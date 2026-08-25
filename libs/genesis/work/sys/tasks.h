#ifndef TASK_H
#define TASK_H

/*
 * These constants are defined for use with resolve_task(), as the
 * difficulty argument.
 */

#define TASK_SIMPLE      200  /*(91.96%) */
#define TASK_EASY        350
#define TASK_ROUTINE     500  /*(50.00%) */
#define TASK_HARD        650
#define TASK_DIFFICULT   800  /*( 8.04%) */
#define TASK_EXACTING    950
#define TASK_FORMIDABLE 1100  /*(Need skills to even have a chance) */
#define TASK_IMPOSSIBLE 1400  /*(Need even more skills to have a chance) */

/*
 * These constants are for use in skill lists for the task system.
 * They are negative to avoid any possible conflicts with the skills
 */

#define SKILL_MIN    -100
#define SKILL_MAX    -200
#define SKILL_AVG    -300
#define SKILL_WEIGHT -400
#define SKILL_END    -500
#define SKILL_VALUE  -600

/*
 * These constants are provided to deal with stats in tasks
 */

#define TS_STR    -1
#define TS_DEX    -2
#define TS_CON    -3
#define TS_INT    -4
#define TS_WIS    -5
#define TS_DIS    -6
#define TS_RACE   -7
#define TS_LAYMAN -9
#define TS_OCC    -8
#define TS_CRAFT  -10

#endif
