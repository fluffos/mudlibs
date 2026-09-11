// train.h by fire on Dec 1998
#define TRAIN_BEG 0
#define TRAIN_PROCESS 1
#define TRAIN_END 2
#define AFTER_TRAIN 4
// questions in the train
#define NO_QUESTION 0
#define QUESTION_SUCCESS 1
#define QUESTION_FAIL -1
#define QUESTION_OVER_DUE -2
#define QUESTION_PROCESS 2
////////////// the maximum times of train topics /////////////
#define MAXTIMES_MOVEME 1
#define MAXTIMES_MOVEOTHER 1
#define MAXTIMES_MOVEALL 1
#define MAXTIMES_FOLLOWME 1
#define MAXTIMES_STAY 1
#define MAXTIMES_GUARD 1
#define MAXTIMES_QUESTION 3
#define MAXTIMES_DEFENCE 1
#define MAXTIMES_ATTACK 1
////////////// busy time in war //////////////////////////////
#define MOV_BUSY_TIME 1
#define ATTACK_BUSY_TIME 3
#define ARRAY_BUSY_TIME 3
#define HORSE_BUSY_TIME 3
#define SIEGE_BUSY_TIME 3

////////////// the functions /////////////////////////////////
void train_arrange(int p_id);
void train_collect(int p_id);
int check_question(int p_id);
void question_overdue(int p_id);
void question_fail(int p_id);
void question_success(int p_id);
void question_wrong(int p_id);
mixed new_question(int p_id);
void question_new(int p_id,string question);
void train_over(int p_id);
void announce_task(int task_id);
mixed get_train_question();
void train_arrange_attack(int task_id);
void train_arrange_defence(int task_id);
void show_question(string p_leader,int task_id);
void quit_question(int task_id);
/////////////////// the function for war ////////////////////////////////
int can_have_new_att_troop(int task_id);
string get_valid_att(int task_id);
string get_att_val_str(int task_id);
string att_prompt(int task_id);
mixed check_att_answer(int task_id,string str);
int input_arrange_att(int task_id,string str);
void man_input(string p_id,int t_id,string p_side);
string att_get_position(string p_area,string p_dir);

int can_have_new_att_troop(int task_id);
string get_valid_att(int task_id);
string get_att_val_str(int task_id);
string att_prompt(int task_id);
mixed check_att_answer(int task_id,string str);
int input_arrange_att(int task_id,string str);
void troop_busy(int t_id,int p_time,string msg) ;
