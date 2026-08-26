
#define TASKER "/handlers/taskmaster"

/**
 * This class contains taskmaster result data.
 * @member result the result of the skill check
 * @member degree the degree of success or failure
 */
class task_class_result {
  int result;
  int degree;
}

/* These are the defines for perform_task() results. */
#define BARF      -1
#define FAIL       0
#define SUCCEED    1
#define AWARD      2

/* These are the defines for compare_skills() results. */
#define OFFAWARD  -2
#define OFFWIN    -1
#define DRAW       0
#define DEFWIN     1
#define DEFAWARD   2

/** This is a define for a fixed skill test. */
#define TM_FIXED 1
/** This is a define for a free skill test in a room or similar. */
#define TM_FREE 2
/** This is a define for a continuous task. */
#define TM_CONTINUOUS 3
/** This is a define for a command. */
#define TM_COMMAND 4
/** This is a define for a ritual. */
#define TM_RITUAL 5
/** This is a define for a spell. */
#define TM_SPELL 6
/** This is a define for just a skill check without a tm chance. */
#define TM_NONE 7
