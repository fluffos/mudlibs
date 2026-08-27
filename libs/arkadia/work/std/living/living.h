 /*
  * Prototypes
  */
void create_living();
void reset_living();
int query_base_stat(int stat);
void update_acc_exp();
varargs string query_real_name(int przyp);
public string query_Imie(mixed pobj, int przyp);
public string query_met_name(int przyp);
mixed query_learn_pref(int stat);
int query_stat(int stat);
void attack_object(object ob);
void start_heart();
varargs string query_Art_name(mixed pobj, int przyp);
void stop_fight(mixed elist);
varargs string query_nonmet_name(int przyp);
void move_all_to(object dest);
object *query_team();
int stat_to_exp(int stat);
int query_tell_active();
string query_align_text();
void set_gender(int g);
int query_gender();
void add_gender_names();
int query_living_rodzaj();