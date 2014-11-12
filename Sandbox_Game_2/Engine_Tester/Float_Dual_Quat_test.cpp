// for the Google Test frame
#include <gtest\gtest.h>

#include <Engine_2\Math\F_Dual_Quat.h>
using Math::F_Dual_Quat;

#include <Engine_2\Math\F_Quat.h>
using Math::F_Quat;

#include <iostream>
using std::cout;
using std::endl;

// this file contains some useful constants to save time and keep magic numbers constant during testing
#include "Math_Helper.h"


TEST(Float_Dual_Quat, Default_Constructor)
{
   //F_Dual_Quat dq;

   //EXPECT_FLOAT_EQ(0.0f, dq.m_real.m_scalar);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_real.m_vector.x);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_real.m_vector.y);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_real.m_vector.z);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_dual.m_scalar);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_dual.m_vector.x);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_dual.m_vector.y);
   //EXPECT_FLOAT_EQ(0.0f, dq.m_dual.m_vector.z);
}

TEST(Float_Dual_Quat, Explicit_Constructor)
{
   //F_Quat q1(1.0f, glm::vec3(+1.1f, +2.2f, +3.3f));
   //F_Quat q2(2.0f, glm::vec3(-3.3f, -2.2f, -1.1f));
   //F_Dual_Quat dq(q1, q2);

   //EXPECT_FLOAT_EQ(1.0f, dq.m_real.m_scalar);
   //EXPECT_FLOAT_EQ(+1.1f, dq.m_real.m_vector.x);
   //EXPECT_FLOAT_EQ(+2.2f, dq.m_real.m_vector.y);
   //EXPECT_FLOAT_EQ(+3.3f, dq.m_real.m_vector.z);
   //EXPECT_FLOAT_EQ(2.0f, dq.m_dual.m_scalar);
   //EXPECT_FLOAT_EQ(-3.3f, dq.m_dual.m_vector.x);
   //EXPECT_FLOAT_EQ(-2.2f, dq.m_dual.m_vector.y);
   //EXPECT_FLOAT_EQ(-1.1f, dq.m_dual.m_vector.z);
}

TEST(Float_Dual_Quat, Convenience_Constructor)
{
   //static const float ROTATE_X = 1.1f;
   //static const float ROTATE_Y = 2.2f;
   //static const float ROTATE_Z = 3.3f;
   //glm::vec3 rotation_axis(ROTATE_X, ROTATE_Y, ROTATE_Z);

   //static const float ROT_ANGLE = 1.0f;

   //static const float TRANSLATE_X = -3.3f;
   //static const float TRANSLATE_Y = -2.2f;
   //static const float TRANSLATE_Z = -1.1f;
   //glm::vec3 translation(TRANSLATE_X, TRANSLATE_Y, TRANSLATE_Z);

   //F_Dual_Quat dq(rotation_axis, ROT_ANGLE, translation);
   //F_Quat expected_real = F_Quat::generate_rotator(rotation_axis, ROT_ANGLE);
   //F_Quat expected_dual = F_Quat::generate_pure_quat(translation);
}

TEST(Float_Dual_Quat, Translate)
{

}

TEST(Float_Dual_Quat, Orientation)
{

}

TEST(Float_Dual_Quat, Magnitude)
{

}

TEST(Float_Dual_Quat, Normalize)
{

}

TEST(Float_Dual_Quat, Conjugate)
{

}

TEST(Float_Dual_Quat, Multiply)
{
   //F_Quat real_1(1.0f, glm::vec3(1.1f, 2.2f, 3.3f));
   //F_Quat dual_1(0.0f, glm::vec3(4.4f, 5.5f, 6.6f));
   //F_Dual_Quat dq1(real_1, dual_1);

   //F_Quat real_2(1.0f, glm::vec3(-3.3f, -2.2f, -1.1f));
   //F_Quat dual_2(0.0f, glm::vec3(-6.6f, -5.5f, -4.4f));
   //F_Dual_Quat dq2(real_2, dual_2);

   //// put in its own block to avoid "result_X" mixups
   //{
   //   F_Dual_Quat result_1 = dq1 * dq2;
   //   EXPECT_FLOAT_EQ(+13.1f, result_1.m_real.m_scalar);
   //   EXPECT_FLOAT_EQ(+2.64f, result_1.m_real.m_vector.x);
   //   EXPECT_FLOAT_EQ(-9.68f, result_1.m_real.m_vector.y);
   //   EXPECT_FLOAT_EQ(+7.04f, result_1.m_real.m_vector.z);
   //   EXPECT_FLOAT_EQ(+67.76f, result_1.m_dual.m_scalar);
   //   EXPECT_FLOAT_EQ(+14.74f, result_1.m_dual.m_vector.x);
   //   EXPECT_FLOAT_EQ(-33.88f, result_1.m_dual.m_vector.y);
   //   EXPECT_FLOAT_EQ(+19.14f, result_1.m_dual.m_vector.z);
   //}

   //{
   //   dq1 *= dq2;
   //   F_Dual_Quat result_2 = dq1;
   //   EXPECT_FLOAT_EQ(+13.1f,  result_2.m_real.m_scalar);
   //   EXPECT_FLOAT_EQ(+2.64f,  result_2.m_real.m_vector.x);
   //   EXPECT_FLOAT_EQ(-9.68f,  result_2.m_real.m_vector.y);
   //   EXPECT_FLOAT_EQ(+7.04f,  result_2.m_real.m_vector.z);
   //   EXPECT_FLOAT_EQ(+67.76f, result_2.m_dual.m_scalar);
   //   EXPECT_FLOAT_EQ(+14.74f, result_2.m_dual.m_vector.x);
   //   EXPECT_FLOAT_EQ(-33.88f, result_2.m_dual.m_vector.y);
   //   EXPECT_FLOAT_EQ(+19.14f, result_2.m_dual.m_vector.z);
   //}

   cout << "hello" << endl;
}
