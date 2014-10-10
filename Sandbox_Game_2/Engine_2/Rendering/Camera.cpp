#include "Camera.h"

#include <Utilities\Include_GLM_Mat_Transform.h>

namespace Rendering
{
   Camera::Camera()
      : m_position(0.0f),
      m_world_up_vector(0.0f, 1.0f, 0.0f),
      m_view_direction(0.0f, 0.0f, -1.0f),
      m_strafe_direction(0.0f),
      m_prev_mouse_position(0.0f),
      m_camera_move_speed(0.3f)
   {

   }

   glm::mat4 Camera::get_world_to_view_matrix() const
   {
      return glm::lookAt(m_position, m_position + m_view_direction, m_world_up_vector);
   }

   void Camera::mouse_update(const glm::vec2 &new_mouse_position)
   {
      glm::vec2 mouse_delta = new_mouse_position - m_prev_mouse_position;

      // attempt to prevent "camera jump" when the mouse leaves the window and re-enters by only
      // performing this transform if the movement is under a limit
      // Note: Be mindful of whether you are using degrees or radians when you included the GLM matrix transform header.
      if (glm::length(mouse_delta) < 50.0f)
      {
         const float ROTATION_SENSITIVITY = 0.5f;
         const float PI_DEG_CONVERSION = (2.0f * 3.14159f) / 360.0f;
         
         // treat the mouse delta as a change in degrees
         float rotate_angle_rad_x = -mouse_delta.x * PI_DEG_CONVERSION;
         float rotate_angle_rad_y = -mouse_delta.y * PI_DEG_CONVERSION;

         // take the cross product of the current view direction and the world up vector to get the 
         // strafe vector, then rotate around Y, then rotate around the strafe vector
         // ??good candidate for quaternion computation??
         m_strafe_direction = glm::cross(m_view_direction, m_world_up_vector);
         glm::mat4 rotator_mat =
            glm::rotate(rotate_angle_rad_x * ROTATION_SENSITIVITY, m_world_up_vector) *
            glm::rotate(rotate_angle_rad_y * ROTATION_SENSITIVITY, m_strafe_direction);

         // cast the mat4 down to a mat3 rather than casting twice casting the view direction to a 
         // vec4 and back to a vec3
         m_view_direction = glm::mat3(rotator_mat) * m_view_direction;
      }

      m_prev_mouse_position = new_mouse_position;
   }

}