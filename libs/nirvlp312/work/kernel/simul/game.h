void shout(string s);
int query_is_wizard(object player);
varargs status is_wizard(mixed who,int mode);
/*
void wizlist(mixed arg);
*/
void update_actions();
object present_clone(mixed file, mixed ob);
object present_property(mixed prop, mixed ob);
#ifndef NEW_LIGHT
int query_light(object ob);
#endif
varargs mixed with_player(object player,closure code,mixed args);
varargs status accessible(object ob,object to,string container_id,int flags);
varargs int notify_fail(mixed message,varargs mixed prio);
nomask string query_verb();
nomask void set_verb(string v);
nomask varargs int command(string comm, object who, status without_alias);
varargs int message_command(mixed mess, object who, mapping args);
nomask void set_living_name(string name);
object find_exact_living(string name);
mixed find_all_livings(string name);
object find_living(string name);
object find_player(string name);
/*
void start_simul_efun();
*/
int get_encumbrance(object o);
int get_mass(object o);
int get_area_size(object o);
string castle_file(mixed creator_or_object);
object get_room(object o);

