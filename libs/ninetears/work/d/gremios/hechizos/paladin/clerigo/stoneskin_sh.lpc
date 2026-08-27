/*** Stoneskin Shadow ***/
/*** By Wonderflug ***/

#include "tweaks.h"
object my_player;


void setup_shadow(object ob)
{
  shadow(ob,1);
  my_player = ob;
}

void destruct_stoneskin_shadow()
{
  tell_object(my_player, "Your skin reverts to normal as the stoneskin "
        "wears off.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+"'s skin "
	"reverts to normal.\n", my_player);
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

int check_duration()
{
  if ( my_player->query_timed_property("stoneskin_on") )
        return 0;
  else return 1;
}

int query_stoneskin_spell() { return 1; }
/* Stoneskin counts as both of these. */
int query_mirror_spell() { return 1; }
int query_armor_spell() { return 1; }

int adjust_hp( int amount, object hitter)
{
  int ret;
  int hit_roll, check_against;

  if ( amount > 0 )
        return my_player->adjust_hp(amount, hitter);

  tell_object(hitter, "Your attack glances off of "+my_player->query_cap_name()+
        "'s stone-like skin.\n");
  tell_object(my_player, hitter->query_cap_name()+"'s attack glances off "
        "your Stoneskin.\n");
  tell_room(environment(my_player), hitter->query_cap_name()+"'s attack "
        "glances off of "+my_player->query_cap_name()+"'s stone-like "
        "skin.\n",
        ({ hitter, my_player }) );

  if ( check_duration() )
        call_out("destruct_stoneskin_shadow",0,0);
  return my_player->adjust_hp( amount*STONESKIN_FRACTION, hitter );
}

int set_hp(int amount, object hitter)
{
  int ret;

  if ( amount >= (int)my_player->query_hp() )
        return my_player->set_hp(amount, hitter);

  tell_object(hitter, "Your attack glances off of "+my_player->query_cap_name()+
        "'s stone-like skin.\n");
  tell_object(my_player, hitter->query_cap_name()+"'s attack glances off "
        "your Stoneskin.\n");
  tell_room(environment(my_player), hitter->query_cap_name()+"'s attack "
        "glances off of "+my_player->query_cap_name()+"'s stone-like "
        "skin.\n",
        ({ hitter, my_player }) );

  if ( check_duration() )
        call_out("destruct_stoneskin_shadow",0,0);
  return my_player->adjust_hp(
                ((int)my_player->query_hp()-amount)*STONESKIN_FRACTION );
}

string extra_look()
{
  return  "Has skin that looks as hard as stone.\n";
}

/* These two for dispel magic, and stone to flesh, respectively */
void dispell_me()
{
  my_player->remove_timed_property("stoneskin_on");
  tell_object(my_player, "Your skin reverts to normal as the magic is "
        "destroyed.\n");
  tell_object(environment(my_player), my_player->query_cap_name()+
        "'s skin reverts to normal as the magic is destroyed.\n",
        my_player );
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

void dispel_stoneskin()
{
  dispell_me();
}

