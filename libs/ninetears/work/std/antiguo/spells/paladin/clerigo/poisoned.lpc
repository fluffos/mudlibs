/* Poison object, actually a "dead" invisible NPC 
 * Effects based on con, once cast this isn't a spell
 * but a festering wound
 */ 
#include "tweaks.h"
inherit "/std/object";

int strength;
int hb;
int query_spell() { return 1; }

int dispell_me()
{
  this_object()->dest_me();
  return 1;
}

void init()
{
  ::init();
  set_heart_beat(1);
}

void set_spell(object ob,int damage)
{
  strength = damage;
}

void setup()
{
  set_name("poisoned wound");
  set_short("festering poisoned wound");
  add_alias("wound");
  set_long("\n A disgusting looking wound that is weeping greenish "
    "puss and making you feel quite ill.\n");
  set_get();
  reset_drop();
  strength = random(20);
}

void heart_beat()
{
  object ob;
  int i;

  hb++;
  ob = environment(this_object());
  if( !ob || !living(ob) || ob->query_dead() || 
      !ob->query_timed_property("poisoned") )
  {
    dispell_me();
    return ;
  } 

  if( hb > ob->query_con() )
  {
    hb = 0;
    ob->adjust_hp(-random(strength),this_object());
    tell_object(ob,"Your poisoned wound weakens you.\n");
    tell_room(environment(ob),(string)ob->query_cap_name()+
      " suddenly looks ill.\n",({ ob }) );
  }
  set_heart_beat(1);
}     
