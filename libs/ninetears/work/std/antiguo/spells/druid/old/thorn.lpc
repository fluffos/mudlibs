/*** Thorn in one's Foot ***/
/*** By Wonderflug ***/
/* Based on Fengarance's broken leg */
/* But horribly hacked to bits now. */

#include "tweaks.h"

inherit "/std/object";
 
void setup()
{
  set_name("thorn_foot");
  add_alias("thorn foot");
  add_alias("foot");
  add_alias("thorn");
  set_short("");
  set_long("It appears that you have gotten a huge thorn stuck "
        "in your foot.  It'll be hard to move with that thing.\n");
  set_weight(0);
  set_value(0);
}
 
void init()
{
  ::init();
  add_action("do_remove", "remove");
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

  if ( str != "thorn" && str != "thorn foot" && str != "thorn in foot" )
        return 0;

  if ( check < random(80) )
  {
        write("You try to pull the thorn out but it doesn't want to seem "
          "to come out.  But ohhhhhh did that hurt!\n");
        tell_room(environment(ob), ob->query_cap_name()+" tries to remove "
          "a thorn from "+ob->query_possessive()+" foot, and howls in "
          "pain.\n", ob); 
        ob->adjust_hp(-random(MAX_REMOVE_DAM)-1);
        return 1;
  }
  write("You very painfully pull out the thorn.\n");
  tell_room(environment(ob), ob->query_cap_name()+" winces in pain as "+
        ob->query_pronoun()+" removes a thorn from "+ob->query_possessive()+
        "foot.\n", ob);
  ob->adjust_hp(-random(MAX_REMOVE_DAM)-1);
  this_player()->destruct_thorn();
  this_object()->dest_me();
  return 1;
}

