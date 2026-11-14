#ifndef MONSTER_H
#define MONSTER_H
  
void reset(status arg);

object set_heart_ob(object ob);
object set_dead_ob(object ob);
object set_init_ob(object ob);

int set_random_pick(int r);

status set_move_at_reset(status i);
status set_aggressive(status a);

string set_name(string n);
 
/*** set level will automatically set monster to bare minimum requirements ***/ 
  
void set_level(int l);  

void set_wander(int chance, int time);
  
/************************************/
/* old way for spells */
 
int set_chance(int c);
int set_spell_dam(int d);
  
string set_spell_mess1(string m);
string set_spell_mess2(string m);
string set_spell_type(string t);
 
string set_spell_skill_type(string str);
 
/**************************************/
/* new way */

void set_spell(mixed *arr);

/* can call player spells */

void load_spells(int c, string *s);

/***********************************************************************/
/* heart beat */

protected status filter_players(object ob);

void heart_beat();
  
/**************************************************************************/  
 
status init_command(string cmd);


/***************************************************************************/ 

/***   Load Chats and Attack chats.   ***/  
 
void load_chat(int chance, string *strs);
  
void load_a_chat(int chance, string *strs);
  
/***   Load language chat - Zilanthius ***/  
  
void load_l_chat(int chance, string lang, string *strs);
  
/****************************************************************************/
  
status second_life();

/****************************************************************************/
  
void pick_any_obj ();
  
/************************************************************************/


void init();
  
/*** stealing from a monster, call "steal" if something is stolen... ***/ 
 
void steal();

/************************************************************************/ 
/* load function added by Crombie, Sept 8, 1993 */

void load_monster(mixed name, int lev, string race);
int add_weapon(string wfile);

int set_steal_chance(int i);
int query_steal_chance();
void steal_from_player(object who, mixed item);

#endif
