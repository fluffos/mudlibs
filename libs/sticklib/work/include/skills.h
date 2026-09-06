/* /include/skills.h */

#define NEWSKILL(x) ({ (x), time() })

/*
 * Default values are quite bad; guild object can override them.
 *
 */
#define DEF_SK_PAUSE   360
#define DEF_SK_FORGET 7200

/* Array defines:
 * SK_SCORE : 0..100000
 * SK_TIME  : time() value of last change, used to prevent too fast
 *            advancement and to forget certain skills slowly
 */
#define SK_SCORE  0
#define SK_TIME   1

#define SK_ARRAY_SIZE 2
