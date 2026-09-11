// char.h by fire on July 5, 1998
#define TYPE_NPC  0 // means this char is a npc
#define TYPE_PLAYER 1 // means this is a player used for type in chars
#define STATUS_NOTFINISHED 0 // means this npc can't be used yet
#define STATUS_SLEEPING 1 // means this npc or player not active
#define STATUS_ACTIVE 2 // means this npc or (not online player)is active 
#define STATUS_ONLINE 3 // just for players when he is on line
// LD means loyalty down
#define LD_NOPAY 20 // because of no pay the loyalty down
// RD means loyalty down
#define RD_NOPAY 20 // because of no money to pay the officer
// PC means put a char in some place
#define PC_SUCCESSFUL 1
#define PC_NOSUCHCHAR -1
#define PC_NOSUCHROOM -2
#define PC_FAIL -100
#define TASK_NONE 0
#define TASK_MEETING 1
#define TASK_WAR 2
#define TASK_TRAIN 3
#define TASK_UNKNOW 10
// functions
string* check_char(string para_name,mixed para_value);
mixed get_char(string p_id,string para_name);
string set_char(string p_id,string para_name,mixed para_value);
string remove_char(string p_id) ;
int char_exist(string p_id);
void set_char_modified();
string* check_char_area(string para_name,mixed para_value,string p_area);
mixed list_chars();
