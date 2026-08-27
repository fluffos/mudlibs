/*** MIRROR IMAGE SHADOW ***/
/*** Coded By Wonderflug ***/

#include "tweaks.h"

object my_player;
int images;

void setup_shadow(object ob, int num_images) 
{
  shadow(ob,1);
  my_player = ob;
  images = num_images;
}

void destruct_mirror_image_shadow() 
{
  destruct(this_object());
}

int query_mirror_spell() { return 1; }
int query_armor_spell() { return 1; }

int adjust_hp( int amount, object hitter) 
{
  int ret;
  int hit_roll, check_against;

  if ( !hitter || !living(hitter) || hitter == my_player || images <= 0 )
    return my_player->adjust_hp(amount, hitter);

  if ( amount > 0 )
    return my_player->adjust_hp(amount, hitter);

  hit_roll = random( 20 + (int)hitter->query_cha() );
  check_against = (int)my_player->query_level();
  check_against = check_against>20 ? 20 : check_against;

  if ( hit_roll > check_against )
  {
    images = 0;
    tell_object(my_player, hitter->query_cap_name()+
      " sees through the images and aims directly at you!\n\n"
      "Your clones vanish as they become useless. \n");
    tell_object(hitter, "You see through "+my_player->query_cap_name()+
      "'s clones, and begin to ignore \nall but the real thing.\n");
    tell_room(environment(my_player), hitter->query_cap_name()+
      " sees through "+my_player->query_cap_name()+"'s images and "
      "strikes directly at "+my_player->query_objective()+"!\n"
      "The rest of the clones vanish as they become useless.\n",
      ({ my_player, hitter }) );
    ret = my_player->adjust_hp(amount*2, hitter);
  }
  else
  {
    images -= 1;
    tell_object(my_player, hitter->query_cap_name()+ " strikes one "
      "of your images and it shatters into nothingness!\n");
    tell_object(my_player, "You wince as your link with the image "
      "is broken.\n");
    tell_object(hitter, "You strike at an image of "+
      my_player->query_cap_name()+", but not the real one, and "
      "it shatters mockingly.\n");
    tell_room(environment(my_player), hitter->query_cap_name()+
      " shatters one of "+my_player->query_cap_name()+"'s images.\n",
      ({ my_player, hitter }) );
    ret = my_player->adjust_hp(-2, hitter);
  }

  if ( images <= 0 )
  {
    tell_room(environment(my_player), my_player->query_cap_name()+
      "'s images are all gone!\n", my_player);
    tell_object(my_player, "Your images are all gone!\n");
    my_player->remove_extra_look(this_object());
    call_out("destruct_mirror_image_shadow", 0, 0);
  }
  return ret;
}


void dispell_me()
{
  tell_object(my_player, "Your images vanish as the magic is disrupted.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
    "'s mirror images disperse as the magic is destroyed.\n");
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}

string extra_look()
{
  return "There are "+(images+1)+" duplicates of "+
    my_player->query_objective()+" here.\n";
}

