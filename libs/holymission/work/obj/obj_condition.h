#ifndef __OBJ_CONDITION_H__

#define __OBJ_CONDITION_H__

/* condition levels */
#define MAGICAL_CND     7
#define SUPER_CND       6
#define EXCELLENT_CND   5
#define FINE_CND        4
#define AVERAGE_CND     3
#define POOR_CND        2
#define VERY_POOR_CND   1
#define ABISMAL_CND     0

/* condition strings */
#define MAGICAL_MSG     "It is in much better shape than normal weapons.\n"
#define SUPER_MSG       "It is in superb condition.\n"
#define EXCELLENT_MSG   "It is in excellent condition.\n"
#define FINE_MSG        "It is in fine condition.\n"
#define AVERAGE_MSG     "It is in average condition.\n"
#define POOR_MSG        "It is in poor condition.\n"
#define VERY_POOR_MSG   "It is in very poor condition.\n"
#define ABISMAL_MSG     "It is in an abismally poor condition.\n"

#define MAX_CND        1600
#define MAGIC_CND      1000
#define CND_DIV        MAX_CND / 8

#define NO_OF_CONDITIONS  8

#endif // __OBJ_CONDITION_H__
