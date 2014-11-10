#include "AABB_Component.h"

#include <Entities\Entity.h>
#include <Shapes\Geometry.h>
#include <Shapes\My_Vertex.h>
#include <Utilities\Quaternion_Helper.h>
#include <memory.h>
#include <Utilities\My_Assert.h>

#include <Utilities\Printer_Helper.h>

#include <Utilities\Include_Helpers\GLM_Mat_Transform.h>

#include <iostream>
using std::cout;
using std::endl;


// a helper namespace for non-class helper things
namespace
{
   inline float avg(float min, float max)
   {
      return (max + min) / 2.0f;
   }

   inline float half_distance(float min, float max)
   {
      return (max - min) / 2.0f;
   }

}

namespace Entities
{
   AABB_Component::AABB_Component()
      : m_geometry_data_ptr(0)
   {
   }

   void AABB_Component::set_geometry(const Shapes::Geometry *box_this)
   {
      m_geometry_data_ptr = box_this;
   }

   bool AABB_Component::initialize()
   {
      // can't initialize without any geometry
      MY_ASSERT(m_geometry_data_ptr != 0);

      recalculate_all_min_max_values(
         &(m_geometry_data_ptr->m_shape_data.m_verts->position), 
         m_geometry_data_ptr->m_shape_data.m_num_verts,
         sizeof(Shapes::My_Vertex) / sizeof(glm::vec3));

      // set the default vectors so that they can be transformed on the next update
      m_default_face_centers[BOX_FACES::LEFT_CENTER] = glm::vec3(m_curr_min_x, 0.0f, 0.0f);
      m_default_face_centers[BOX_FACES::RIGHT_CENTER] = glm::vec3(m_curr_max_x, 0.0f, 0.0f);
      m_default_face_centers[BOX_FACES::TOP_CENTER] = glm::vec3(0.0f, m_curr_max_y, 0.0f);
      m_default_face_centers[BOX_FACES::BOTTOM_CENTER] = glm::vec3(0.0f, m_curr_min_y, 0.0f);
      m_default_face_centers[BOX_FACES::FRONT_CENTER] = glm::vec3(0.0f, 0.0f, m_curr_min_z);
      m_default_face_centers[BOX_FACES::BACK_CENTER] = glm::vec3(0.0f, 0.0f, m_curr_max_z);


      return true;
   }

   void AABB_Component::update()
   {
      //static uint update_count = 0;

      //if (update_count > 10)
      //{
      //   glm::normalize(m_parent_entity_ptr->m_where_and_which_way);
      //}
      //update_count++;

      glm::vec3 curr_face_centers[BOX_FACES::NUM_FACES];

      // transform the face center points
      glm::fdualquat &transform = m_parent_entity_ptr->m_where_and_which_way;
      glm::fdualquat transform_conjugate = Utilities::Quaternion_Helper::dual_quat_conjugate(transform);
      //glm::mat4 mat = Utilities::Quaternion_Helper::dual_quat_to_mat4(transform);
      for (uint face_index = 0; face_index < BOX_FACES::NUM_FACES; face_index++)
      {
         curr_face_centers[face_index] = Utilities::Quaternion_Helper::dual_quat_translate_point(
            m_default_face_centers[face_index],
            transform,
            transform_conjugate);
         //glm::vec4 v = glm::vec4(m_default_face_centers[face_index], 1.0f);
         //glm::vec3 v2 = glm::vec3(mat * v);
         //curr_face_centers[face_index] = v2;
      }

      // data is closely packed, so index_stride is 1
      recalculate_all_min_max_values(curr_face_centers, BOX_FACES::NUM_FACES, 1);
   }


   glm::vec3 AABB_Component::is_colliding_with_AABB(const AABB_Component &other_box)
   {
      // this overlap section does not make sense without imagining the boundaries of two cubes 
      // infringing on each other on a given axis, but it works
      bool X_overlap = (m_curr_min_x < other_box.m_curr_max_x) && (m_curr_max_x > other_box.m_curr_min_x);   // "left" is negative X
      bool Y_overlap = (m_curr_max_y > other_box.m_curr_min_y) && (m_curr_min_y < other_box.m_curr_max_y);   // "up" is positive Y
      bool Z_overlap = (m_curr_min_z < other_box.m_curr_max_z) && (m_curr_max_z > other_box.m_curr_min_z);   // "forward" is negative Z

      if (X_overlap)
      {
         cout << " - X overlap";
      }
      
      if (Y_overlap)
      {
         cout << " - Y overlap";
      }

      if (Z_overlap)
      {
         cout << " - Z overlap";
      }

      if (X_overlap || Y_overlap || Z_overlap)
      {
         cout << endl;
      }


      return glm::vec3();
   }


   void AABB_Component::recalculate_all_min_max_values(const glm::vec3 *vec_data_source, const uint max_vectors, const uint index_stride)
   {
      // give the min/max values initial data that is within the boundaries of the data
      const glm::vec3 &initial_vert = *vec_data_source;
      m_curr_min_x = initial_vert.x;
      m_curr_max_x = initial_vert.x;
      m_curr_min_y = initial_vert.y;
      m_curr_max_y = initial_vert.y;
      m_curr_min_z = initial_vert.z;
      m_curr_max_z = initial_vert.z;

      // go through all the vectors and find the min and max in all axes
      for (uint vec_counter = 0; vec_counter < max_vectors; vec_counter++)
      {
         // calculate the index location of the vector data
         // Ex: In My_Vertex, there are position, normal, and color vec3s, so the
         // first position index (in vec3 land, not in My_Vertex land) is [0], the
         // next is [3], the next is [6], etc.
         // Ex: In m_default_face_centers, the vectors are closely packed, so the
         // first position is at index [0], the next at [1], the next at [2], etc.
         uint vec_index = vec_counter * index_stride;

         const glm::vec3 &vec_ref = vec_data_source[vec_index];

         if (vec_ref.x < m_curr_min_x) { m_curr_min_x = vec_ref.x; }
         else if (vec_ref.x > m_curr_max_x) { m_curr_max_x = vec_ref.x; }

         if (vec_ref.y < m_curr_min_y) { m_curr_min_y = vec_ref.y; }
         else if (vec_ref.y > m_curr_max_y) { m_curr_max_y = vec_ref.y; }

         if (vec_ref.z < m_curr_min_z) { m_curr_min_z = vec_ref.z; }
         else if (vec_ref.z > m_curr_max_z) { m_curr_max_z = vec_ref.z; }
      }
   }
}