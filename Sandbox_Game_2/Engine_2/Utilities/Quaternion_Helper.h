#ifndef ENGINE_QUATERNION_HELPER_H
#define ENGINE_QUATERNION_HELPER_H

#include <glm\vec3.hpp>
#include <glm\gtx\quaternion.hpp>

namespace Utilities
{
   namespace Quaternion_Helper
   {
      // this function is an adaption of OrientationOffset(...) from ArcSynthesis Tutorial 0.3.8, tutorial 8, QuaternionYPR.cpp
      void orientation_offset(const glm::vec3 &rotation_axis, const float rotation_angle_rad, glm::fquat &offset_this);
   }
}

#endif