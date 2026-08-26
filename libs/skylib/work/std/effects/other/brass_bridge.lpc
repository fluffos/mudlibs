/**
 * An effect for when you're hung off the brass bridge.
 *  This does damage and causes some items to be dropped.
 * @author Rodion
 */
#include <effect.h>
#include <move_failures.h>

//change this to fiddle with damage:

#define NUM_DICE 4

//The room where dropped inventory goes.
#define DROP_ROOM "/d/am/river/river7"
#define BRIDGE "/d/am/river/bridge"


/** @ignore */
string query_classification() { return "body.hanging"; }

/** @ignore */
void beginning(object player, int time){
   player->submit_ee("hanging", ({10, 30}), EE_CONTINUOUS);
   player->submit_ee("drop_things", ({180, 360}), EE_CONTINUOUS);
   player->submit_ee(0, time, EE_REMOVE);
   player->add_extra_look(this_object());
   
   tell_object(player, "You feel the blood rush to your head.\n");
} /* beginning() */

/**
 * A function to do damage and send messages during the duration of the effect
 */
void hanging(object player, int time){
   int damage, con;
   object corpse;
   
   con = player -> query_con();
   
   damage = roll_MdN(NUM_DICE, con);
   
   if ( (int)player->query_hp() <= damage ){
        player->attack_by( this_object() );
        corpse = player->do_death();
        player->move(DROP_ROOM);
        tell_object(player, "You feel terribly faint, and the world goes "
          "black...\n");
        tell_room( environment(player), (string)player->query_short() 
         +"'s head lolls and "+ player->query_possessive() +" eyes roll "
         "back.  Their corpse immediately falls below.\n",
        player);
        corpse->move(DROP_ROOM, player->query_name() +"'s corpse drops from "
         "above.");
      }
      
    else {
      player->adjust_hp( -damage );
      tell_object(player, "A wave of dizziness washes over you.\n");
      tell_room( environment(player), (string)player->the_short() +
            " looks ill.\n", player );
         }
}/*hanging()*/


/**
 * Function to handle inventory dropping.  This happens only every 3-6
 * minutes for now.
 */
void drop_things(object player, int time){
   int moo;
   mixed bing;
   
   bing = all_inventory(player);
   if(sizeof(bing) != 0){
      moo = random(sizeof(bing));
   }
   else {
      return;
   }
   
   //Bing! Moooo!
   
   if(!(bing[moo]->move(DROP_ROOM))){
      tell_object(player, "You feel your "+ bing[moo]->query_short() 
       +" slip out of your grasp.\n");
      tell_room(environment(player), player->query_short() +"'s "+ 
       bing[moo]->query_short() +" falls from his weak hands.\n", player);
      }
   else
      return;
}/*drop_things*/

//This makes it possible to move() things out of people's inventory.
/** @ignore */
int query_theft_command(){
   return -1;
}

/** @ignore */
int merge_effect(object player, int old_time, int new_time){
   if (old_time > new_time)
      return old_time;
   return new_time;
}/*merge_effect()*/

/** @ignore */
string extra_look(object player){
   return capitalize((string)player->query_pronoun()) +
         " is hanging upside down.  It doesn't look comfortable.\n";
}/*extra_look()*/


/** @ignore */
void reset(object player, int time){
}


/** @ignore */
int survive_death(){return 0;}

/** @ignore */
void end(object player, int amount){
   if ( !(player->query_property("dead"))){
      tell_object(player, "You're suddenly yanked up back onto the bridge by "
         "the same two porters who threw you down there.  Your body slumps to " 
         "the ground, and they walk off.\n");
      tell_object(player, "Your limbs tingle and you feel lightheaded as the "
         "blood rushes from your head back to the rest of your body.\n");
       player->move(DROP_ROOM);
       }
   player->remove_extra_look(this_object());
}/*end()*/

/** @ignore */
string query_death_reason(){ 
   return "being hung out to dry"; 
}

/*A SkankyCode Production, by Rodion*/