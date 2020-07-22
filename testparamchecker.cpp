#include "paramchecker.h"
#include <gtest/gtest.h>

/*struct Param Vitals_1_valid[1]={
{60, 50, 100}
};

struct Param Vitals_1_Notvalid[1]={
{101, 50, 100}
};

struct Param Vitals_3_valid[3]={
{100, 50, 100},
{80,40,100},
{80,40,100}
};
struct Param Vitals_4_Notvalid[4]={
{40, 50, 100},
{150,40,100},
{20,40,100},
{101,20,100}
};
*/
struct Param Vitals_5_valid[5]={
{50, 50, 100},
{60,40,100},
{70,60,150},
{100,20,100},
{20,20,100}
};

/*TEST(VitalsTest, Vitals_1Valid) { 
    ASSERT_EQ(true, vitalsAreOk(Vitals_1_valid,1));
}
TEST(VitalsTest, Vitals_1Notvalid) { 
    ASSERT_EQ(false, vitalsAreOk(Vitals_1_Notvalid,1));
}
TEST(VitalsTest, Vitals_3) { 
    ASSERT_EQ(true, vitalsAreOk(Vitals_3_valid,3));
}
 
TEST(VitalsTest, Vitals_4) {
    ASSERT_EQ(false, vitalsAreOk(Vitals_4_Notvalid, 4));
}*/

TEST(VitalsTest, Vitals_5Valid) { 
    ASSERT_EQ(true, vitalsAreOk(Vitals_5_valid,5));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

