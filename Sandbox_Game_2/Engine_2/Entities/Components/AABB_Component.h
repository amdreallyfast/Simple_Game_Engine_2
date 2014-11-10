#ifndef ENGINE_COLLISION_DETECTION_AABB_H
#define ENGINE_COLLISION_DETECTION_AABB_H


#include <glm\vec3.hpp>
#include <Entities\Game_Component.h>
#include <Utilities\Typedefs.h>

namespace Shapes
{
   class Geometry;
}

namespace Entities
{
   // class for an Axis-aligned Bounding Box
   class __declspec(dllexport) AABB_Component : public Game_Component
   {
   public:
      // for ensuring that pointers and array data get set to 0
      AABB_Component();

      void set_geometry(const Shapes::Geometry *box_this);

      bool initialize();
      // default shutdown
      void update();

      // figures out where the two are coliding and returns the point of collision
      // Note: If there is no collision, it returns 0 on all axes.
      glm::vec3 is_colliding_with_AABB(const AABB_Component &other_box);

   private:
      // keep this pointer around in case you need to re-calculate something from the geometry
      const Shapes::Geometry *m_geometry_data_ptr;

      // a box has six faces, so just magically declare them
      enum BOX_FACES
      {
         TOP_CENTER = 0,   // max Y
         BOTTOM_CENTER,    // min Y
         LEFT_CENTER,      // min X
         RIGHT_CENTER,     // max X
         FRONT_CENTER,     // min Z
         BACK_CENTER,      // MAX Z
         NUM_FACES
      };

      // use vec3s for the default face centers and floats for the current extremities of the box
      // Note: I chose this strategy because min/max values on each axis are easy to compute and
      // compare, but I can only translate vectors, so I create the default face vectors as vec3s
      // that can be easily translated with the entity's latest position and orientation on every
      // frame (the update() method).
      glm::vec3 m_default_face_centers[BOX_FACES::NUM_FACES];
      float m_curr_min_x;
      float m_curr_max_x;
      float m_curr_min_y;
      float m_curr_max_y;
      float m_curr_min_z;
      float m_curr_max_z;

      // a helper function that needs access to private data members
      // Note: The vector data source may refer to closely packed vec3s like this class'
      // "default face centers" member, or it may refer to geometry data in a My_Vertex 
      // structure in which the next position vec3 is 3 vectors ahead, or maybe other
      // data sources in the future.  The loop and the conditions in it though are the
      // same, so I introduced the "index stride" variable (NOT a byte offset!) to account
      // for these different vector storages.
      void recalculate_all_min_max_values(const glm::vec3 *vec_data_source_ptr, const uint max_vectors, const uint index_stride);
   };
}

#endif