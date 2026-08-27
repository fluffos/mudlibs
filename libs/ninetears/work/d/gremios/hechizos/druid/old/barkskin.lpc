/*** Barkskin Shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"
object my_player;

void setup_shadow(object ob, int amount)
{
  shadow(ob,1);
  my_player = ob;
}

void destruct_shadow()
{
  tell_object(my_player, "Your skin reverts to normal as the Barkskin "
        "wears off.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+"'s skin "
	"reverts to normal.\n", my_player);
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

int check_duration()
{
  if ( my_player->query_timed_property("barkskin_on") )
        return 0;
  else return 1;
}

int query_skin_spell() { return 1; }
/* Barkskin counts as both of these. */
int query_mirror_spell() { return 1; }
int query_armor_spell() { return 1; }

int adjust_hp( int amount, object hitter)
{
  int ret;

  if ( amount > 0 )
        return my_player->adjust_hp(amount, hitter);

  if ( hitter )
  tell_object(hitter, "Your attack glances off of "+my_player->query_cap_name()+
        "'s tough, bark-like skin.\n");
  tell_object(my_player, "The attack glances off your Barkskin.\n");
  tell_room(environment(my_player), "The attack "
        "glances off of "+my_player->query_cap_name()+"'s tough, bark-like "
        "skin.\n",
        ({ hitter, my_player }) );

  ret = amount*BARKSKIN_FRACTION;

  if ( check_duration() )
        call_out("destruct_shadow",0,0);
  return my_player->adjust_hp( ret, hitter );
}

int set_hp(int amount, object hitter)
{
  if ( amount >= (int)my_player->query_hp() )
        return my_player->set_hp(amount, hitter);

  if ( hitter )
  tell_object(hitter, "Your attack glances off of "+my_player->query_cap_name()+
        "'s bark-like skin.\n");
  tell_object(my_player, "The attack glances off your Barkskin.\n");
  tell_room(environment(my_player), "The attack "
        "glances off of "+my_player->query_cap_name()+"'s bark-like "
        "skin.\n",
        ({ hitter, my_player }) );

  if ( check_duration() )
        call_out("destruct_shadow",0,0);
  return my_player->adjust_hp(
                ((int)my_player->query_hp()-amount)*BARKSKIN_FRACTION );
}

string extra_look()
{
  return  "Has strange skin that looks like tree bark.\n";
}

void dispell_me()
{
  my_player->remove_timed_property("barkskin_on");
  tell_object(my_player, "Your skin reverts to normal as the magic is "
        "destroyed.\n");
  tell_object(environment(my_player), my_player->query_cap_name()+
        "'s skin reverts to normal as the magic is destroyed.\n",
        my_player );
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

