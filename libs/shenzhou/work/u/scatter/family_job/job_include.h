//Cracked by Kafei
//inlcude all func.
//wzfeng@xkx 2000 6


string *get_arearoom(string area);
int judge_room(string room_name);
string get_room(string area);
void get_job_palce_msg(object master,object player,string place,string state,string command_mode);
string get_family_master_massage(string command_mode,string menpai,string state);
int job_class_prompt(object player);
int job_start_prompt(object player);
int master_msg(object master,object player,string state,string command_mode);
void assign_job(object master,object player,mapping map);
void finish_job(object player);
void master_tell_player(object player);
void award_job(int exp_lim,int pot_lim,int time1,int time2,
			int luck,int neili,int jingli,int skills_lim,
			object player,object master,string kind);
void job_punish(object player,string job_kind);
void del_job(object player,string kind);
void	oppose_pker(object master,object player,mapping job);
void out_killer(object player,object place);
void job_oppsse_pker_start(object player);
void award_oppose_pker(object player);
object choose_user(string menpai_name);
int do_check_user(object ob,string menpai_name);
int do_check_job_player(object ob,string *list);
int choose_job(object player);
void check_finishjob_place();
void check_askjob_place();
void check_oppose_pker_place();
void check_player_place();
void job_tell_player(object player);
int choose_menpai();
int choose_strategy(string menpai);
int choose_area_power(string menpai);

#define MAPDB "/clone/obj/mapdb"
#define TRAVERSER  "/clone/obj/traverser"
#define JOB_DIR "/clone/obj/job/"



























