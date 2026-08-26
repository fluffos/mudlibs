// Defines for the arg array.
#define ARG_STAGE                  0
#define ARG_TARGETS                1
#define ARG_USING                  2
#define ARG_BONUS                  3
#define ARG_ARGS                   4

// Defines for common usage, further expanded upon in next section.
#define STAGE( x, y )                 x[y-1]
#define SKILL( x, y )                 STAGE(x, y)[0]
#define DIFF( x, y )                  STAGE(x, y)[1]
#define TM_SKILL( x, y )              explode(SKILL(x, y), ".")[sizeof(explode(SKILL(x, y), ".")) - 1]
#define MESSAGES( x, y )              STAGE(x, y)[2][0]
#define FAIL_MESSAGES( x, y )         STAGE(x, y)[2][1]
#define STAGES( x )                   sizeof(x)

// Defines for the ritual mapping, used internally in the spell object.
#define RITUAL_STAGE( x )          STAGE(ritual, x)
#define RITUAL_SKILL( x )          SKILL(ritual, x)
#define RITUAL_DIFF( x )           DIFF(ritual, x)
#define RITUAL_TM_SKILL( x )       TM_SKILL(ritual, x)
#define RITUAL_MESSAGES( x )       MESSAGES(ritual, x)
#define RITUAL_FAIL_MESSAGES( x )  FAIL_MESSAGES(ritual, x)
#define RITUAL_STAGES              STAGES(ritual)

// Defines for END args.
#define END_SUCCEED                -1
#define END_FAIL                   -2
#define END_ABORT                  -3
#define END_FAIL_HANDLED           -4
