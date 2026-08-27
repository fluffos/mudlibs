/*
 * /sys/math.h
 *
 * Some useful math routines
 */

#ifndef MATH_DEF
#define MATH_DEF

#define MATH_FILE "/sys/global/math"

/*
 * MATH_FIND_EXP will return x in: 2^x = sum
 */
#define MATH_FIND_EXP(sum) (int)call_other(MATH_FILE, "find_exp", (sum))

/*
 * Same as MATH_FIND_EXP, but only for a very limited set of 'sum'.
 */
#define QUICK_FIND_EXP(sum) (int)call_other(MATH_FILE, "quick_find_exp", (sum))

/*
 * BIN2DEC
 *
 * This will return the decimal value of a bit array with the most
 * significant bit left. Preceding zeroes will be discarded.
 *
 * Examples: ({ 1, 0, 1, 0 }) -> 10
 *           ({ 0, 1, 1 })    ->  3
 */
#define BIN2DEC(arr) (int)call_other(MATH_FILE, "binary_to_decimal", (arr))

/*
 * DEC2BIN
 *
 * This will return the binary value of a number. The binary value will
 * be an array of 1/0 with the most significant bit first. The most
 * significant bit will always be a 1 (except for num = 0).
 *
 * Examples: 11 -> ({ 1, 0, 1, 1 })
 *            6 ->    ({ 1, 1, 0 })
 */
#define DEC2BIN(num) (int *)call_other(MATH_FILE, "decimal_to_binary", (num))

/*
 * SQUARE_ROOT
 *
 * This will return the square root of a certain number. If the square is
 * negative, the root will be zero.
 */
#define SQUARE_ROOT(i) (int)call_other(MATH_FILE, "square_root", (i))

/*
 * NAME_TO_RANDOM
 *
 * This will return an almost random number within 0 to (range - 1),
 * based on the (lower case) name of a player. This way, for instance for
 * quests or other hints, each combination of name, seed and range will
 * result in the same number and you can use it to generate individual
 * hints for individual players.
 *
 * Arguments: string name  - the lower case name of the player
 *            int    seed  - a large, unique number. You should select a
 *                           number of 7 or 8 digits for each different
 *                           situation you use the macro for.
 *            int    range - the range of the number [ 0 .. (range - 1) ]
 */
#define NAME_TO_RANDOM(name, seed, range) \
    (int)call_other(MATH_FILE, "name_to_random", (name), (seed), (range))

/*
 * FIELD_TO_RADIUS
 *
 * Zwraca promien, jaki mialoby kolo o podanym polu.
 */
#define FIELD_TO_RADIUS(x) \
    ftoi(sqrt(itof(x) / 3.14))

#endif MATH_DEF
