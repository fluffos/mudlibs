#ifndef _PLANTCONST_H_
#define _PLANTCONST_H_

// The maximum number of independent variables a plant may have
// attached to itself. This number can be raised without causing
// problems to existing plants -- the code is written to be
// flexible on this.
#define MAX_PLANT_VARS        6

// Must be some multiple of 24 + some number that is not a
// factor of 24 except 1 (valid numbers are 1, 5, 7, 11, 13, 17, 19, 23).
// If you don't use these numbers, then the plant growth rules will be unfairly
// balanced for some plants, because they won't be activated evenly at
// every possible time of day. This delay is in minutes.
//
// If the MUD is overloaded because of plant growth, this number should
// be made larger to slow down the plant growth daemon. If you want
// the plants to grow faster, and you have enough CPU muscle, then
// you should decrease this number.
#define GROWTH_DELAY    53

// The index of plant variables. All variables are 0-254; if you
// need one with a larger range, combine two variables together
// using (var1 * 255) + var2.
#define PLANT_BULK      0
#define PLANT_HEALTH    1
#define FRUIT_COUNT     2
#define STORED_ENERGY   3
#define PLANT_X         4
#define PLANT_Y         5

#define WOOD(x) string query_wood_type() { return x; }
#define FRUIT(x) string query_fruit_type() { return x; }
#define HARVEST(x) string query_harvest_type() { return x; }

#endif
