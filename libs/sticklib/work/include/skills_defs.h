#ifndef SKILL_DEFS_H
#define SKILL_DEFS_H

#define SKILL_POS_VAL	0
#define SKILL_POS_LEV	1
#define SKILL_POS_HOOK	2

#define SKILL_EXISTS	-1
#define SKILL_NO_EXIST	-2
#define SKILL_ADDED	0
#define SKILLS_FULL	1
#define SKILL_NO_PREREQ	2

#define SKILL_LIMIT 12

#define SKILL_TRAIN_RATE	0.05

#define HOOK_RESOLVED_NT	-4
#define HOOK_RESOLVED		-3
#define HOOK_NOT_IN_USE		0
#define ALREADY_HOOKED		1
#define HOOKED			2
#define HOOK_REMOVED		3
#define NOT_HOOKED		4

#define SK_TRAIN_STD	1.0
#define SK_TRAIN_EASY	2.0
#define SK_TRAIN_HARD	0.5
#define SK_TRAIN_X_HARD	0.25

#define COST_FOR_ASKILL	1

#define SK_RANKS ({\
"unknown", \
"a neophyte", \
"learning", \
"an amateur", \
"untested", \
"accomplished", \
"talented", \
"well known", \
"professional", \
"highly regarded", \
"celebrated", \
"a leading authority", \
"world renowned", \
"a guru",\
})

#define TOP_RANK	13

#endif /* SKILL_DEFS_H */
