/*
 * /sys/math.h
 *
 * Some useful math routines
 */

#ifndef MATH_DEF
#define MATH_DEF

#ifndef MATH_FILE
#define MATH_FILE "/sys/global/math"
#endif  MATH_FILE

/*
 * MATH_FIND_EXP will return x in: 2^x = sum
 */
#define MATH_FIND_EXP(sum) (int)call_other(MATH_FILE, "find_exp", (sum))

/*
 * Same as MATH_FIND_EXP, but only for a very limited set of 'sum'.
 */
#define QUICK_FIND_EXP(sum) (int)call_other(MATH_FILE, "quick_find_exp", (sum))

/*
 * SUM_ARRAY returns the sum of an array of values.
 */
#define SUM_ARRAY(arr) reduce( (: $1 + $2 :) , (arr) )

/*
 * INT_MULT_FLOAT_TRUNC - Multiply an int with a float. Returns truncated int.
 * INT_MULT_FLOAT_ROUND - Multiply an int with a float. Returns rounded inc.
 * INT_MULT_FLOAT       - Default to rounding.
 */
#define INT_MULT_FLOAT_ROUND(i, f)	to_int(to_float(i) * (f) + 0.5)
#define INT_MULT_FLOAT_TRUNC(i, f)	to_int(to_float(i) * (f))
#define INT_MULT_FLOAT(i, f)		INT_MULT_FLOAT_ROUND(i, f)

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
    ((int)MATH_FILE->name_to_random((name), (seed), (range)))

/*
 * RANDOM_STRING
 *
 * This will create a random string of 'length' characters using upper
 * and lower case letters and numbers. Example: 8 -> "a8To0PlX"
 */
#define RANDOM_STRING(length) \
    ((string)MATH_FILE->random_string(length))

#endif MATH_DEF
