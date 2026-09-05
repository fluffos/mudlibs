#ifndef _sys_message_h
#define _sys_message_h

#include "describe.h"
#include "libs.h"

#define M_LAST_ADDED_TOKEN      -540  /* Please update this if you add tokens
                                       * also, if you add tokens, please
                                       * update /lib/message.c  !!   */

#define M_CONTINUED                -100
#define M_APPLY                    -110
#define M_APPLY_WITH_ARGS          -420
#define M_APPLY_FUNCTION           -440
#define M_APPLY_FUNCTION_WITH_ARGS -450
#define M_CALL                     -120
#define M_INDENT                   -130
#define M_RAW                      M_INDENT,0
#define M_CANCEL                   -140
#define M_DESCRIBE_FUNCTION        -150
#define M_CAPITALIZE               -160
#define M_SUBJECT                  -170
#define M_OBJECT                   -180
#define M_ACTIVE_OBJECT            -410
#define M_DESCRIBE_GROUP           -430
#define M_SIMPLE_DESCRIBE          -460
#define M_DESCRIBE_UNOWNED         -500,M_SIMPLE_DESCRIBE
#define M_CLASS                    -470

#define M_ARTICLE                  -220
#define M_THE                      M_ARTICLE,ARTICLE_THE
#define M_NONE                     M_ARTICLE,ARTICLE_NONE
#define M_FULL                     -230
#define M_S                        -240
#define M_DESCRIBE                 -250
#define M_VERB                     -260
#define M_PRONOUN                  -270
#define M_POSSESSIVE               M_PRONOUN,M_S
#define M_OBJECTIVE                M_PRONOUN,M_OBJECT

#define M_ME                       -280
#define M_ME_S                     M_S,M_ME
#define M_ME_DESCRIBE              M_DESCRIBE,M_ME
#define M_ME_VERB                  -290
#define M_ME_PRONOUN               M_PRONOUN,M_ME
#define M_ME_POSSESSIVE            M_PRONOUN,M_S,M_ME
#define M_ME_OBJECTIVE             M_PRONOUN,M_OBJECT,M_ME
#define M_ME_SUBJECT               M_SUBJECT,M_ME

#define M_PL                       -300
#define M_PL_S                     M_S,M_PL
#define M_PL_DESCRIBE              M_DESCRIBE,M_PL
#define M_PL_VERB                  -310
#define M_PL_PRONOUN               M_PRONOUN,M_PL
#define M_PL_POSSESSIVE            M_PRONOUN,M_S,M_PL
#define M_PL_OBJECTIVE             M_PRONOUN,M_OBJECT,M_PL
#define M_PL_SUBJECT               M_SUBJECT,M_PL
#define M_ROOM                     -190
#define M_TARGETS                  -200
#define M_EXCLUDE                  -210
#define M_SUPPRESS_VIEW            -540
#define M_WRITE                    M_TARGETS,M_PL
#define M_SAY                      M_EXCLUDE,M_PL

#define M_ADD                      -320
#define M_PL_ADD                   -330
#define M_ME_ADD                   -340

#define M_SAYS                     -520
#define M_SAYS_TO                  -530
#define M_MONEY                    M_APPLY_FUNCTION, \
                                     ({ LIB_MONEY,"describe_money" })
#define M_ADVERBS                  -480
#define M_SPACE                    -490

#define M_CNTL_SEQ                 -510

/* These are only to be used between two messages in message() but not in
 * send_message() (they will raise an error there)
 */
#define M_DELAY                    -350
#define M_PRESENT                  -360
#define M_ALWAYS                   -370
#define M_DEFAULT                  -380

#define M_ARG                      -390
#define M_PRE                      -400

#define M_ME_THE                   M_THE,M_ME
#define M_ME_NONE                  M_NONE,M_ME
#define M_PL_THE                   M_THE,M_PL
#define M_PL_NONE                  M_NONE,M_PL

/* These macros can be used to eas various descriptions for different
 * light levels (different messages for people who can't see).
 */

#define M_CANNOT_SEE               filter(                        \
                                     all_inventory(               \
                                       get_room(this_object())),  \
                                     (: living($1) && !$1->test_sight(0,1) :))

#define M_CAN_SEE                  filter(                        \
                                     all_inventory(               \
                                       get_room(this_object())),  \
                                     (: living($1) && $1->test_sight(0,1) :))

/* These macros are obsolete and not to be used, use the given macros instead
 */

#define M_PLAYER                   M_PL
#define M_PLAYER_S                 M_PL_S
#define M_OBJECT_S                 M_S
#define M_PLAYER_THE               M_THE,M_PL
#define M_ENUM_OBJECT_S            M_S
#define M_ENUM_VERB                M_VERB
#define M_PL_ENUM_VERB             M_PL_VERB
#define M_ME_ENUM_VERB             M_ME_VERB
#define M_ENUM_ADD                 M_ADD
#define M_LIST                     ""
#define M_LIST_THE                 M_THE
#define M_OBJECTIVE_SELF           M_OBJECTIVE
#define M_PL_OBJECTIVE_SELF        M_PL_OBJECTIVE
#define M_ME_OBJECTIVE_SELF        M_ME_OBJECTIVE
#define M_NAME                     M_PL_DESCRIBE

#endif  /* _sys_message_h */
