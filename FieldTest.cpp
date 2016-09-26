/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
} 

TEST(FieldTest, placeInBigBounds)
{
    Field mf(15);
    mf.placeMine(8, 13);
    ASSERT_NO_THROW(mf.get(8, 13));
}

TEST(FieldTest, safeSpace)
{
    Field mf(15);
    mf.placeMine(8, 13);
    ASSERT_FALSE(mf.isSafe(8, 13));
}

TEST(FieldTest, hidenseek)
{
    Field mf(10);
    mf.placeMine(8, 9);
    ASSERT_EQ(MINE_HIDDEN, mf.get(8, 9));
}

TEST(FieldTest, adjacentDanger)
{
    Field mf(15);
    mf.placeMine(8, 9);
    mf.revealAdjacent(8, 8);
    ASSERT_EQ(MINE_SHOWN, mf.get(8, 9));
}

/**
 * TEST(FieldTest, getOutOfBounds)
 * {
 *      // segault
 *    Field *mf= new Field(5);
 *    ASSERT_ANY_THROW(mf->placeMine(6, 7));
 *      // segault
 *    Field mf(5);
 *    ASSERT_ANY_THROW(mf.placeMine(6, 7));
 * }
 */
