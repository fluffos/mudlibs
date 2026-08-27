/*** Thorn in one's Foot ***/
/*** By Wonderflug ***/
/* Based on Fengarance's broken leg */
/* But horribly hacked to bits now. */

#include "tweaks.h"

inherit "/std/object";
 
void setup()
{
  set_name("espina");
  add_alias("espina");
  set_short("");
  set_long("Parece que estas rodeado por espinas cerca de tus pies. "
    "Sera bastante complicado moverse por aqui, hazlo con cuidado.\n");
  set_weight(0);
  set_value(0);
}
 
void init()
{
  ::init();
  add_action("do_remove", "quitar");
  if ( !this_player() )
    return ;

  if ( !this_player()->query_thorn() )
    clone_object(THORN_SHADOW)->setup_shadow(this_player(), this_object());
}
 
int do_remove( string str )
{
  object ob;
  int check;

  ob = this_player();
  check = (int)ob->query_str() + (int)ob->query_wis() + 
    (int)ob->query_dex() + (int)ob->query_int();

  if ( str != "espina" && str != "espinas" && str != "espina del pie" )
    return 0;

  if ( check < random(80) )
  {
    write("Intentas sacarte las espinas que se te han clavado en los pies "
      "Pero .. ohhhhhh que dolor!\n");
    tell_room(environment(ob), ob->query_cap_name()+" intenta quitarse "
               "una espina del pie pero grita de dolor.\n",ob); 
    ob->adjust_hp(-random(MAX_REMOVE_DAM)-1);
    return 1;
  }
  write("Estas muy dolorido para sacarte la espina del pie.\n");
  tell_room(environment(ob), ob->query_cap_name()+" comienza a chillar "+
    "de dolor al ver que no puede quitarse la espina de su pie.\n",ob); 
  ob->adjust_hp(-random(MAX_REMOVE_DAM)-1);
  this_player()->destruct_thorn_shadow();
  this_object()->dest_me();
  return 1;
}
