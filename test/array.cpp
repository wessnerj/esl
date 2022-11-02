#include "gtest/gtest.h"

#include "array.h"

#include <cstdint>

namespace {
    TEST(Array, Constructor)
    {
        using namespace esl;

        Array<uint16_t, 16> array;
        EXPECT_EQ(sizeof(array), 16*sizeof(uint16_t));
    }
    TEST(Array, BracketAcces)
    {
        using namespace esl;

        Array<int, 4> array;

        array[0] = 1;
        array[1] = 17;
        array[2] = -7;
        array[3] = 42;

        EXPECT_EQ(array[0], 1);
        EXPECT_EQ(array[1], 17);
        EXPECT_EQ(array[2], -7);
        EXPECT_EQ(array[3], 42);

        const auto& ref = array;
        EXPECT_EQ(ref[0], 1);
        EXPECT_EQ(ref[1], 17);
        EXPECT_EQ(ref[2], -7);
        EXPECT_EQ(ref[3], 42);
    }

    TEST(Array, Empty)
    {
        using namespace esl;

        Array<float, 3> three;
        Array<float, 0> null;

        EXPECT_FALSE(three.empty());
        EXPECT_TRUE(null.empty());
    }

    TEST(Array, Size)
    {
        using namespace esl;

        Array<float, 7> seven;
        Array<float, 0> null;

        EXPECT_EQ(seven.size(), 7u);
        EXPECT_EQ(null.size(), 0u);
    }

    TEST(Array, MaxSize)
    {
        using namespace esl;

        Array<float, 7> seven;
        Array<float, 0> null;

        EXPECT_EQ(seven.max_size(), 7u);
        EXPECT_EQ(null.max_size(), 0u);
    }

    TEST(Array, Fill)
    {
        using namespace esl;

        Array<int, 3> three;
        three[0] = 0;
        three[1] = 1;
        three[2] = 8;

        three.fill(4);

        EXPECT_EQ(three[0], 4);
        EXPECT_EQ(three[1], 4);
        EXPECT_EQ(three[2], 4);
    }

}  // namespace