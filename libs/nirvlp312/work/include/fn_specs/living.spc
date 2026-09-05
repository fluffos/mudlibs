/* log */

void log(string file,mixed old, mixed new);

/* sets */

int set_level(int i);

string set_msgin(string s);
string set_msgout(string s);
string set_mmsgin(string s);
string set_mmsgout(string s);

string *set_languages_known(string *arr);

status set_speak_language(string str);

string *set_weapon_prof(string *arr);
string *set_classes(string *arr);

status set_ghost(status i);
status set_dead(status i);

status set_no_wimpy(status i);
int set_wimpy(int i);
string set_custom(string s);
  
int set_hp(int i);
int set_max_hp(int i);

int set_exp(int i);

int set_money(int i);
int set_age(int i);
int set_alignment(int i);
int set_gender(int i);

string *set_spell_immune(string *arr);
mixed *set_loaded_spell(mixed *arr);

int set_magic_resist(int i);

status set_npc(status i);
int set_invis(int i);

int set_ac(int i);
int set_armor_class(int i);

int set_ac_bonus(int i);
object *set_armor_worn(object *arr);

int set_right_wc(int i);
object set_right_weapon(object ob);
string set_right_weapon_type(string s);
int set_right_weapon_bonus(int i);
 
int set_left_wc(int i);
object set_left_weapon(object ob);
string set_left_weapon_type(string s);
int set_left_weapon_bonus(int i);
 
object set_primary_attack(object ob);

object *set_secondary_attacks(object *arr);
string *set_classes(string *arr);
  
/*** Primary skills ***/ 
 
int set_combat(int i);
int set_dexterity(int i);
int set_intelligence(int i);
int set_wisdom(int i);
int set_charisma(int i);
int set_constitution(int i);
int set_strength(int i);

/**************************************************************************/
/* query */

string query_current_room();

string query_real_name();
string query_cap_name();
string query_invis_name();

int query_level();
int query_level_drained();
 
string query_msgin();
string query_msgout();
string query_mmsgin();
string query_mmsgout();

string *query_languages_known();
string *query_weapon_prof();
string *query_classes();

status query_ghost();
status query_dead();

status query_no_wimpy();
int query_wimpy();
string query_custom();
  
int query_hp();
int query_max_hp();

int query_exp();
int query_money();
int query_age();
int query_alignment();
  
string *query__all_spell_immune();
mixed *query_loaded_spell();
int query_magic_resist();
status query_spell_immune(string str);

string query_speak_language();
status query_npc();
int query_invis();

int query_ac();
int query_armor_class();
object *query_armor_worn();
int query_ac_bonus();

int query_right_wc();
object query_right_weapon();
string query_right_weapon_type();

int query_left_wc();
object query_left_weapon();
string query_left_weapon_type();

string query_attacker(); 
object query_attack();
object query_primary_attack();

object *query_secondary_attacks();
object *query_alt_attackers();


/*** Primary skills ***/ 
 
int query_combat();
int query_dexterity();
int query_intelligence();
int query_wisdom();
int query_charisma();
int query_constitution();
int query_strength();


string *query_classes();


/* gender stuff */

int query_gender();

status query_neuter();
status query_male();
status query_female();
  
string query_gender_string ();
    
string query_pronoun ();
  
string query_possessive ();
  
string query_objective ();


/**************************************************************************/
/* adj */

int adj_level(int i);
int adj_level_drained(int i);
 
int adj_wimpy(int i);
  
int adj_hp(int i);
int adj_max_hp(int i);

int adj_exp(int i);
int adj_money(int i);

int adj_age(int i);

int adj_alignment(int i);
int adj_magic_resist(int i);

int adj_ac(int i);
int adj_armor_class(int i);
int adj_ac_bonus(int i);

int adj_right_wc(int i);
int adj_right_weapon_bonus(int i);
 
int adj_left_wc(int i);
int adj_left_weapon_bonus(int i);
  
/*** Primary skills ***/ 
 
int adj_combat(int i);
int adj_dexterity(int i);
int adj_intelligence(int i);
int adj_wisdom(int i);
int adj_charisma(int i);
int adj_constitution(int i);
int adj_strength(int i);

/****************************************************************************/
/* adds */  

status add_weight(int wt);
int add_exp(int i);
int add_money(int i);
  
/****************************************************************************/
/* show age in clock time */  

string show_age(status arg);


/***************************************************************************/
/* level draining stuff */
  
void restore_level();
  
void drain_level();
  
/***********************************************************************/
/* spell_immune array stuff */
  
status query_spell_immunity(string str);
  
void add_spell_immunity(string str);
  
void remove_spell_immunity(string str);


/**********************************************************************/
/* languages_known array stuff */
  
status query_language(string str);
  
void add_language(string str);
  
void remove_language(string str);

/**************************************************************************/
/* weapon_prof array stuff */

status query_weapon_proficiency(string str);

void add_weapon_proficiency(string str);
  
void remove_weapon_proficiency(string str);

/**********************************************************************/
/* classes array stuff */

status query_class(string str);
  
void add_class(string str);
  
void remove_class(string str);

/************************************************************************/ 
/* secondary_attacks array stuff */

status query_secondary_attacker(object ob);

status add_secondary_attacker(object ob);
  
void remove_secondary_attacker(object ob);

/************************************************************************/ 
/* armor_worn array stuff */

status query_armor(object ob);

static status filter_armor_type(object ob, string type);

object query_armor_type(object ob);

void add_armor_worn(object ob);
  

/**************************************************************************/
/* initialise stuff */

void reset(status arg);

/***************************************************************************/
/* move_player */

varargs status move_player(string dir_dest,mixed optional_dest_ob,status safe);
 
  
/************************************************************************/  
/* insta-kill */
  
void death();

/***********************************************************************/
/* hit player */

int hit_player(int dam);
  
/**************************************************************************/
/* stop fight */


varargs void stop_fight(object arg);

/**************************************************************************/  
/* attack */  

  
void attack();

/**************************************************************************/
/* spell attacks */
 
do_spell_object
(ob, msg_me, msg_you, msg_room, sp_cost, hp_dam, immune, my_skill);


status load_spell(mixed *arr);


void cast_spell_at_target();
 

/* thus in process_msg(), this_object() == target, this_player() == caster */

int spell_hit(int spell_dam,
          string caster_msg,
          string target_msg,
            string room_msg,
                object prev,
               string fname,
               string immune,
              mixed type,
              status passive);


/****************************************************************************/
/* wimpy */
  
void run_away();
  
/****************************************************************************/
/* Externally Configurable bonuses */

int carry_bonus();

int right_wc_bonus();

int left_wc_bonus();

int ac_bonus();


/***************************************************************************/
/* carry, ac, wc calculators - these should fix problems */

void recalc_carry();

void recalc_wc();

void recalc_ac();

/**************************************************************************/
  
status communicate(string str);

static status speak(object who, string str);

/*************************************************************************/

void attack_msg(int dam, string type, object who, string side);
void unload_spell();

