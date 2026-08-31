/* prison.h 910622 Herp --- header file for prison defines */
 
#define OWNER "herp"
#define HOME "players/"+OWNER
#define PRISON HOME+"/prison"
#define PCURSE HOME+"/pcurse"
#define PCURSE_ID "pcurse"
#define PNAME this_player()->query_name()
#define is_wiz (this_player()->query_wizard())
#define is_arch_wiz (this_player()->query_level()>49)
#define is_owner (this_player()->query_real_name()==OWNER)
#define is_allowed (is_arch_wiz || is_owner)
