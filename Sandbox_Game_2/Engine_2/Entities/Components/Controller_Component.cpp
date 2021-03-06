#include "Controller_Component.h"

// for setting a particular key binding
#include <Input\Supported_Bindings.h>
#include <Input\Key_Bindings\Keyboard_Bindings.h>

// for getting at the physics component
#include <Entities\Entity.h>
#include <Entities\Components\Physics_Component.h>

// for figuring out which actions are active
#include <Input\Action_List.h>

#include <Utilities\Typedefs.h>
#include <glm\vec3.hpp>
#include <Utilities\Include_Helpers\Default_Vectors.h>
#include <Utilities\Include_Helpers\GLM_Mat_Transform.h>
#include <Utilities\Quaternion_Helper.h>
#include <Utilities\Include_Helpers\GLM_Quaternion.h>
#include <Utilities\Include_Helpers\GLM_Dual_Quaternion.h>
#include <Utilities\Printer_Helper.h>

#include <Utilities\My_Assert.h>

#include <iostream>
using std::cout;
using std::endl;

namespace Entities
{
   bool Controller_Component::initialize()
   {
      m_easy_physics_ptr = m_parent_entity_ptr->get_component_ptr<Physics_Component>();
      return (m_easy_physics_ptr != 0);
   }

   void Controller_Component::update()
   {
      //using Input::ACTION_LIST;
      //MY_ASSERT(m_key_binder_ptr != 0);
      ////MY_ASSERT(m_easy_physics_ptr != 0);

      //static const float LINEAR_SPEED = 0.3f;
      //static const float ROTATION_SPEED = 0.02f;

      //// define these to avoid lots of repetious dereferencing
      ////glm::vec3 new_position = m_parent_entity_ptr->m_position;
      //glm::vec3 new_position;
      //
      //
      ////glm::vec3 forward_vector = glm::normalize(m_parent_entity_ptr->m_base_orientation);
      ////glm::vec3 forward_vector = glm::mat3(glm::mat4_cast(m_parent_entity_ptr->m_base_orientation_quat)) * Utilities::Default_Vectors::WORLD_FORWARD;
      ////glm::vec3 strafe_vector = glm::cross(Utilities::Default_Vectors::WORLD_UP_VECTOR, forward_vector);
      ////glm::vec3 relative_up_vector = glm::cross(forward_vector, strafe_vector);

      ////Utilities::Printer_Helper::print_vec("up:", relative_up_vector);

      ////glm::fquat new_orientation = m_parent_entity_ptr->m_base_orientation_quat;
      ////Utilities::Printer_Helper::print_quat("orientation:", new_orientation);
      //glm::fquat new_orientation;

      //glm::fquat current_orientation_conjugate = glm::conjugate(new_orientation);
      //glm::vec3 forward_vector = current_orientation_conjugate * Utilities::Default_Vectors::WORLD_FORWARD_VECTOR;
      //glm::vec3 left_vector = current_orientation_conjugate * Utilities::Default_Vectors::WORLD_LEFT_VECTOR;
      //glm::vec3 relative_up = current_orientation_conjugate * Utilities::Default_Vectors::WORLD_UP_VECTOR;

      //   // get the list of actions that are active right now
      //uint active_actions = m_key_binder_ptr->get_active_actions();

      //if (active_actions & ACTION_LIST::FORWARD)
      //{
      //   //cout << "accellerating";
      //   new_position += forward_vector * LINEAR_SPEED;
      //}

      //if (active_actions & ACTION_LIST::BACK)
      //{
      //   //cout << ", back";
      //   new_position -= forward_vector * LINEAR_SPEED;
      //}

      //if (active_actions & ACTION_LIST::STRAFE_LEFT)
      //{
      //   //cout << ", strafing left";
      //   new_position += left_vector * LINEAR_SPEED;
      //}

      //if (active_actions & ACTION_LIST::STRAFE_RIGHT)
      //{
      //   //cout << ", strafing right";
      //   new_position -= left_vector * LINEAR_SPEED;
      //}

      //if (active_actions & ACTION_LIST::GO_UP)
      //{
      //   //cout << ", going up";
      //   new_position += Utilities::Default_Vectors::WORLD_UP_VECTOR * LINEAR_SPEED;
      //}

      //if (active_actions & ACTION_LIST::GO_DOWN)
      //{
      //   //cout << ", going up";
      //   new_position -= Utilities::Default_Vectors::WORLD_UP_VECTOR * LINEAR_SPEED;
      //}

      //if (active_actions & ACTION_LIST::YAW_LEFT)
      //{
      //   //cout << ", rotating left";
      //   //forward_vector = glm::mat3(glm::rotate((+1.0f) * ROTATION_SPEED, relative_up_vector)) * forward_vector;
      //   //Utilities::Quaternion_Helper::orientation_offset(glm::vec3(0.0f, 1.0f, 0.0f), +ROTATION_SPEED, new_orientation);
      //   new_orientation = glm::angleAxis(-ROTATION_SPEED, Utilities::Default_Vectors::WORLD_UP_VECTOR) * new_orientation;
      //}

      //if (active_actions & ACTION_LIST::YAW_RIGHT)
      //{
      //   //cout << ", rotating right";
      //   //forward_vector = glm::mat3(glm::rotate((-1.0f) * ROTATION_SPEED, relative_up_vector)) * forward_vector;
      //   //Utilities::Quaternion_Helper::orientation_offset(glm::vec3(0.0f, 1.0f, 0.0f), -ROTATION_SPEED, new_orientation);
      //   new_orientation = glm::angleAxis(+ROTATION_SPEED, Utilities::Default_Vectors::WORLD_UP_VECTOR) * new_orientation;
      //}

      //if (active_actions & ACTION_LIST::PITCH_FORWARD)
      //{
      //   //cout << ", tilting forward";
      //   //forward_vector = glm::mat3(glm::rotate((+1.0f) * ROTATION_SPEED, strafe_vector)) * forward_vector;
      //   //Utilities::Quaternion_Helper::orientation_offset(glm::vec3(1.0f, 0.0f, 0.0f), -ROTATION_SPEED, new_orientation);
      //   new_orientation = glm::angleAxis(+ROTATION_SPEED, Utilities::Default_Vectors::WORLD_LEFT_VECTOR) * new_orientation;
      //}

      //if (active_actions & ACTION_LIST::PITCH_BACK)
      //{
      //   //cout << ", tilting back";
      //   //forward_vector = glm::mat3(glm::rotate((-1.0f) * ROTATION_SPEED, strafe_vector)) * forward_vector;
      //   //Utilities::Quaternion_Helper::orientation_offset(glm::vec3(1.0f, 0.0f, 0.0f), +ROTATION_SPEED, new_orientation);
      //   new_orientation = glm::angleAxis(-ROTATION_SPEED, Utilities::Default_Vectors::WORLD_LEFT_VECTOR) * new_orientation;
      //}

      //if (active_actions & ACTION_LIST::ROLL_LEFT)
      //{
      //   //cout << ", tilt left";
      //   //Utilities::Quaternion_Helper::orientation_offset(glm::vec3(0.0f, 0.0f, -1.0f), +ROTATION_SPEED, new_orientation);
      //   new_orientation = glm::angleAxis(+ROTATION_SPEED, Utilities::Default_Vectors::WORLD_FORWARD_VECTOR) * new_orientation;
      //}

      //if (active_actions & ACTION_LIST::ROLL_RIGHT)
      //{
      //   //cout << ", tilt right";
      //   //Utilities::Quaternion_Helper::orientation_offset(glm::vec3(0.0f, 0.0f, -1.0f), -ROTATION_SPEED, new_orientation);
      //   new_orientation = glm::angleAxis(-ROTATION_SPEED, Utilities::Default_Vectors::WORLD_FORWARD_VECTOR) * new_orientation;
      //}

      //if (active_actions != 0)
      //{
      //   //cout << endl;
      //}

      //// replaced with dual quaternion
      ////m_parent_entity_ptr->m_position = new_position;

      ////m_parent_entity_ptr->m_base_orientation = forward_vector;

      //// replaced with dual quat
      ////m_parent_entity_ptr->m_base_orientation_quat = glm::normalize(new_orientation);

      //glm::fdualquat new_state = glm::normalize(Utilities::Quaternion_Helper::make_dual_quat(new_orientation, new_position));
      //
      //// right or left multiply the entity's dual quat as needed
      //// Note: Right multiply to make the rotation happen relative to the world origin.  
      //// Note: Left multiply to make the rotation happen relative to the object's origin.
      //// I'll need to think to understand why this is happening.  Or I may just call it a 
      //// magic black box and move on.
      //m_parent_entity_ptr->m_where_and_which_way = new_state * m_parent_entity_ptr->m_where_and_which_way;
   }

   bool Controller_Component::set_key_binding(const Input::SUPPORTED_BINDINGS binding)
   {
      using Input::SUPPORTED_BINDINGS;

      switch (binding)
      {
      case SUPPORTED_BINDINGS::KEYBOARD:
      {
         m_key_binder_ptr = Input::Keyboard_Bindings::get_instance_ptr();
         break;
      }
      default:
      {
         // unknown binding
         return false;
      }
      }

      return true;
   }
}