#include "Keyboard_Bindings.h"

// for VK_some_key
#include <Utilities\Include_Helpers\Windows_Lite.h>

#include <Utilities\My_Assert.h>
#include <Input\Action_List.h>

namespace Input
{
   I_Key_Bindings *Keyboard_Bindings::get_instance_ptr()
   {
      static Keyboard_Bindings instance;

      return &instance;
   }

   uint Keyboard_Bindings::get_active_actions() const
   {
      uint active_actions = 0;
      
      // check out the MSDN article on Virtual-Key Codes

      // 'W'
      if (GetAsyncKeyState(0x57))
      {
         active_actions |= ACTION_LIST::FORWARD;
      }

      // 'S'
      if (GetAsyncKeyState(0x53))
      {
         active_actions |= ACTION_LIST::BACK;
      }

      // 'A'
      if (GetAsyncKeyState(0x41))
      {
         active_actions |= ACTION_LIST::STRAFE_LEFT;
      }

      // 'D'
      if (GetAsyncKeyState(0x44))
      {
         active_actions |= ACTION_LIST::STRAFE_RIGHT;
      }

      // 'Q'
      if (GetAsyncKeyState(0x51))
      {
         active_actions |= ACTION_LIST::ROLL_LEFT;
      }

      // 'E'
      if (GetAsyncKeyState(0x45))
      {
         active_actions |= ACTION_LIST::ROLL_RIGHT;
      }

      if (GetAsyncKeyState(VK_SPACE))
      {
         active_actions |= ACTION_LIST::GO_UP;
      }
      
      if (GetAsyncKeyState(VK_SHIFT))
      {
         active_actions |= ACTION_LIST::GO_DOWN;
      }

      if (GetAsyncKeyState(VK_LEFT))
      {
         active_actions |= ACTION_LIST::YAW_LEFT;
      }

      if (GetAsyncKeyState(VK_RIGHT))
      {
         active_actions |= ACTION_LIST::YAW_RIGHT;
      }

      if (GetAsyncKeyState(VK_UP))
      {
         active_actions |= ACTION_LIST::PITCH_FORWARD;
      }

      if (GetAsyncKeyState(VK_DOWN))
      {
         active_actions |= ACTION_LIST::PITCH_BACK;
      }

      return active_actions;
   }
}