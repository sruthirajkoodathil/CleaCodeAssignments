#include "paramchecker.h"
#include <gtest/gtest.h>
 
struct param Vitals_3_valid[]={
{100, 50, 100},
{80,40,100},
{80,40,100},
}
struct param Vitals_4_Novalid[]={
{40, 50, 100},
{150,40,100},
{20,40,100},
{101,20,100},
}
TEST(VitalsTest, Vitals_3) { 
    ASSERT_EQ(true, vitalsAreOk(Vitals_3_valid,3));
}
 
TEST(VitalsTest, Vitals_4) {
    ASSERT_EQ(false, vitalsAreOk(Vitals_4_Novalid, 4));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
