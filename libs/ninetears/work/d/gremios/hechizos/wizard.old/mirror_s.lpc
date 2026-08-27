#include "tweaks.h"
/*** MIRROR IMAGE SHADOW ***/
/*** Coded By Wonderflug ***/

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

  if ( amount > 0 )
	return my_player->adjust_hp(amount, hitter);

  hit_roll = random( (int)hitter->query_int() );
  check_against = MIRROR_DESTROY_ALL_BASE - (int)hitter->query_level();

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
	  "of your images and it shatters into \nnothingness!\n");
	tell_object(hitter, "You strike at an image of "+
	  my_player->query_cap_name()+", but not the real one, \nand "
	  "it shatters mockingly.\n");
	tell_room(environment(my_player), hitter->query_cap_name()+
	  " shatters one of "+my_player->query_cap_name()+"'s images.\n",
	  ({ my_player, hitter }) );
	ret = my_player->query_hp();
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

int set_hp(int amount, object hitter) 
{
  int ret;

  if ( amount >= (int)my_player->query_hp() )
	return my_player->set_hp(amount, hitter);
  
  if ( random((int)hitter->query_int()) > (MIRROR_DESTROY_ALL_BASE
						-(int)hitter->query_level()) )
  {
        images = 0;
        tell_object(my_player, hitter->query_cap_name()+
          " sees through the images and aims directly at you!\n\n"
          "Your clones vanish as they become useless. \n");
        tell_object(hitter, "You see through "+my_player->query_cap_name()+
          "'s clones, and begin to ignore \nall but the real thing.\n");
        tell_room(environment(my_player), hitter->query_cap_name()+
          " sees through "+my_player->query_cap_name()+"'s images and "
          "\nstrikes directly at "+my_player->query_objective()+"!\n"
          "The rest of the clones vanish as they become useless.\n",
          ({ my_player, hitter }) );
        ret = my_player->set_hp(amount, hitter);
  }
  else
  {
        images -= 1;
        tell_object(my_player, hitter->query_cap_name()+ " strikes one "
          "of your images and it shatters \ninto nothingness!\n");
        tell_object(hitter, "You strike at an image of "+
          my_player->query_cap_name()+", but not the real one, \nand "
          "it shatters mockingly.\n");
        tell_room(environment(my_player), hitter->query_cap_name()+
          " shatters one of "+my_player->query_cap_name()+"'s images.\n",
          ({ my_player, hitter }) );
        ret = my_player->query_hp();
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

