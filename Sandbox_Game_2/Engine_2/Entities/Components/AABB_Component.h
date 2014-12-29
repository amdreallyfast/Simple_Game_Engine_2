#ifndef ENGINE_COLLISION_DETECTION_AABB_H
#define ENGINE_COLLISION_DETECTION_AABB_H


#include <glm\vec3.hpp>
#include <Entities\Game_Component.h>
#include <Utilities\Typedefs.h>

// forward declaration of friend classes
namespace Shapes
{
   class Geometry;
}

namespace Collision_Detection
{
   class Collision_Handler;
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

      // figures out if/where the two are colliding and returns the overlap on all axes
      // Note: Two boxes will only collide if they have overlapped on all axes, but the
      // time and location of collision can only be calculated with the physics
      // Note: If there is no collision, it returns 0 on all axes.
      glm::vec3 is_colliding_with_AABB(const AABB_Component &other_box) const;

   private:
      // the collision handler class will need access to the entity's mass and velocity to calculate
      // the point of impact and the force exerted at that point, and then this physics class will 
      // react to the applied force
      friend class Collision_Detection::Collision_Handler;
      
      // keep this pointer around in case you need to re-calculate something from the geometry
      const Shapes::Geometry *m_geometry_data_ptr;

      // a box has six faces, so just magically declare them
      enum BOX_CORNERS
      {
         RIGHT_UPPER_FRONT,
         RIGHT_UPPER_BACK,
         LEFT_UPPER_FRONT,
         LEFT_UPPER_BACK,
         RIGHT_LOWER_FRONT,
         RIGHT_LOWER_BACK,
         LEFT_LOWER_FRONT,
         LEFT_LOWER_BACK,
         NUM_CORNERS
      };

      // use vec3s for the default face centers and floats for the current extremities of the box
      // Note: I chose this strategy because min/max values on each axis are easy to compute and
      // compare, but I can only translate vectors, so I create the default face vectors as vec3s
      // that can be easily translated with the entity's latest position and orientation on every
      // frame (the update() method).
      glm::vec3 m_default_box_corners[BOX_CORNERS::NUM_CORNERS];
      float m_curr_min_x;
      float m_curr_max_x;
      float m_curr_min_y;
      float m_curr_max_y;
      float m_curr_min_z;
      float m_curr_max_z;

      // a helper function that needs access to private data members
      void recalculate_all_min_max_values(const glm::vec3 *curr_box_corners_arr, const int max_vectors);
   };
}

#endif
