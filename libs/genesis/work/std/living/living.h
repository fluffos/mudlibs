 /*
  * Prototypes
  */
void create_living();
void reset_living();
int query_base_stat(int stat);
nosave void update_acc_exp(int stat_exp, int guild_exp);
string query_real_name();
mixed query_learn_pref(int stat);
int query_stat(int stat);
public void update_stat(int stat);
void attack_object(object ob);
void start_heart();
varargs string query_Art_name(object pobj);
void stop_fight(mixed elist);
string query_nonmet_name();
void move_all_to(object dest);
object *query_team();
int stat_to_exp(int stat);
int query_tell_active();
string query_align_text();
public mixed query_weapon(int which);
