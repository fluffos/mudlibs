#ifndef _COMMAND_H
#define _COMMAND_H

#define COMMAND_ID            0
#define COMMAND_CONTROLLER    1
#define COMMAND_VERBS         2
#define COMMAND_FIELDS        3
#define COMMAND_SYNTAX        4
#define COMMAND_VALIDATION    5
#define COMMAND_MAX_RETRY     6

#define FIELD_ID              0
#define FIELD_TYPE            1
#define FIELD_REQUIRED        2
#define FIELD_PROMPT_SETTING  3
#define FIELD_MAX_RETRY       4
#define FIELD_DEFAULT         5
#define FIELD_ENUM            6
#define FIELD_PROMPT          7
#define FIELD_VALIDATION      8

#define OPTS_OPTS             0
#define OPTS_LONGOPTS         1
#define OPT_OPT               9
#define OPT_PARAM             10
#define OPT_MULTI             11

#define ENUM_ID               0
#define ENUM_MULTI            1
#define ENUM_DELIM            2
#define ENUM_VALUES           3

#define ENUM_VALUE_VALUE      0
#define ENUM_VALUE_LABEL      1
#define ENUM_VALUE_TYPE       2

#define PROMPT_NOECHO         0
#define PROMPT_MSG            1

#define VALIDATE_VALIDATOR    0
#define VALIDATE_FAIL         1
#define VALIDATE_PARAMS       2
#define VALIDATE_NEGATE       3

#define SYNTAX_EXPLODE_ARGS   0
#define SYNTAX_MIN_ARGS       1
#define SYNTAX_MAX_ARGS       2
#define SYNTAX_PATTERN        3
#define SYNTAX_FORMAT         4
#define SYNTAX_ARGS           5
#define SYNTAX_OPTS           6
#define SYNTAX_LONGOPTS       7
#define SYNTAX_VALIDATION     8
#define SYNTAX_SUBCOMMANDS    9

#define TRUE_VALUE            "true"
#define FALSE_VALUE           "false"
#define PROMPT_ALWAYS         "always"
#define PROMPT_SYNTAX         "syntax"
#define PROMPT_VALIDATE       "validate"
#define PROMPT_NEVER          "never"

#define MAX_ARGS              26
#define VALIDATION_PREFIX     "validate_"
#define VALIDATE_SKIP_FIELDS  0x01
#define VALIDATION_PASS       1
#define VALIDATION_FAIL       0
#define VALIDATION_RETRY      -1

#define STEP_FIELD            "step"
#define INITIAL_STEP          0

#endif  // _COMMAND_H
