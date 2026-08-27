/*** Thornfoot Shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"
object my_player;
object my_thorn;

void setup_shadow(object ob, object thorn)
{
  shadow(ob,1);
  my_player = ob;
  my_thorn = thorn;
}

void destruct_thorn()
{
  destruct(this_object());
}
void destruct_shadow()
{
  destruct(this_object());
}

int query_thorn() { return 1; }

int check_duration()
{
  if ( my_thorn )
        return 0;
  else return 1;
}

varargs mixed move_player(string dir, string dest, mixed message, object
                                followee, mixed enter)
{
  int x;

  if ( check_duration() )
  {
        call_out("destruct_shadow",0,0);
        return my_player->move_player(dir,dest,message,followee,enter);
  }

  x = random(2);
  if(x==1)
  {
        tell_object(my_player,
          "You try to move but you as you step down you get an intense "
          "pain in your foot, and notice a thorn lodged there.  Perhaps you "
          "should (painfully) remove it?\n");
        tell_room(environment(my_player), my_player->query_cap_name()+
          " winces in pain, ""as "+my_player->query_pronoun()+
          " tries to move with a thorn in "+my_player->query_possessive()+
          " foot.\n", my_player);
        my_player->adjust_hp(-random(MAX_MOVE_DAM)-1);
        return 1;
  }
  return my_player->move_player(dir,dest,message,followee,enter);
}

