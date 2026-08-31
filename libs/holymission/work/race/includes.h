#define NUMBER_OF_STATS 6
#define SAY(i) tell_room(environment(this_player()),i)

#define NAME       query_name()
#define OBJ        query_objective()
#define POSS       query_possessive()
#define PRON       query_pronoun()
#define GENDER     query_gender_string()
#define CAP        capitalize
#define LC         lower_case
#define REALNAME   query_real_name() 
#define ENV environment

#define SOUL "race/soul"
#define ROOM "race/room"
/* Added by kelly 930526 */
#define RM "race/master"
