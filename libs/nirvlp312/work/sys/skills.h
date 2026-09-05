#ifndef _sys_skills_h
#define _sys_skills_h

/* Tuning factor to regulate the rising of a skill
 * <1 means less rising, >1 means more rising
 */
#define COMBAT_SKILL_REWARD_FACTOR      1.0

/* Constant factor to calculate the rewared */
#define COMBAT_SKILL_REWARD             10

/* graduations of influences */
#define INFLUENCE_LOW                   5
#define INFLUENCE_MIDDLE                10
#define INFLUENCE_LARGE                 20

/* for the query_reward() */
#define IMPROVE_ROUTINE                 1
#define IMPROVE_SLIGHTLY                5
#define IMPROVE_SOMEWHAT                20
#define IMPROVE_CONSIDERABLY            80
#define IMPROVE_GREATLY                 200

/* these are only used by basic/living/skill.c */
#define AVERAGE_SKILL_VALUE             20000
#define MAX_SKILL_VALUE                 10000000

/*
 * Convert the experience amount into a skill value, in the range 0-100
 */
#define AVERAGE_EXPERIENCE              5000

#define EXP_TO_PERCENT(exp)\
   (100 - 100 * AVERAGE_EXPERIENCE / (AVERAGE_EXPERIENCE + (exp)))

#define PERCENT_TO_EXP(per)\
   ((per * AVERAGE_EXPERIENCE) / ((100 - per) || 1))

#define AVERAGE_PERCENT                 50

#endif  /* _sys_skills_h  */
