string query_attacker();
status query_wielded(string weapon_side);
status query_sell_destruct();
int weapon_class();
int query_wc();
object query_hit_func();
string query_type();
string weapon_type();
int query_length();
string query_object_type();
string *query_attack_msg();

/***************************************************************************/
/*  sets */

int set_class(int wc);
int set_wc(int wc);
void set_hit_func(object ob);
void set_right_wielded(object ob);
string set_type(string t);
int set_length(int l);
string *set_attack_msg(string *msg);



void dewield();
void un_wield();
int hit(object attacker);
status check_class_no_allow();
void load_weapon(mixed *str);


/***************************************************************************/
/*  actions */

status wield(string wielding);

