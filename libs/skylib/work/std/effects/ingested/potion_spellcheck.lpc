/*******************************************************************
 *    The spellcheck potion for witches uses three files:          *
 *       1) This effect, which is placed on the player             *
 *          when she drinks the potion.  The argument              *
 *          is the amount drunk (modified by the brewer's          *
 *          bonus.                                                 *
 *                                                                 *
 *       2) The command object.  This is cloned and placed         *
 *          in the player's inventory.  This object contains       *
 *          the code for the focus -command, which the             *
 *          player uses to choose which spell she concentrates     *
 *          on.  It uses magic.spells.special, and includes        *
 *          a taskmaster check for it.                             *
 *                                                                 *
 *       3) The witch spellcheck effect.  This is really the       *
 *          meat of the potion.  It is placed at the end           *
 *          of this effect, and before destroying the command      *
 *          object, it calls query_spell_focused() on it,          *
 *          which returns the spell (if any) the player            *
 *          is focusing on.  The command object is destroyed       *
 *          almost immediately afterwards.                         *
 *                                                                 *
 *          The arguments for this effect are a three element      *
 *          mixed array, but only the first element, the           *
 *          spell's filename, is passed to it.  The effect         *
 *          takes care of the last two, which are consecutively,   *
 *          the current stage and the last stage.                  *
 *                                                                 *
 *    --Tape 98/02/03                                              *
 *******************************************************************/
 
#include <player.h>
#include <effect.h>

#define EFFECT "/std/effects/magic/witch_spellcheck"
#define COMMANDOB "/obj/magic/spellcheck_potion_command"

#define COST 30
#define SKILL "magic.spells.special"

object command_object;

string query_classification() { return "magic.spellcheck.potion"; }


object find_right_object( object plr ) {

   string name;
   object ob, *obs;
   
   name = plr->query_name();
   
   obs = children( COMMANDOB );
   
   if( !sizeof( obs ) ) {
      tell_creator( plr, "(No cloned command objects in memory -- "
         "whoops!\n" );
      return 0;
   }
   
   foreach( ob in obs ) {
      if( ob->query_property( "owned by" ) == name ) {
         return ob;
      }
   }

   tell_creator( plr, "(find_right_object() couldn't find a match -- "
      "whoops!)\n" );
   return 0;

} /* find_right_object() */


void beginning( object player, int args ) {

   tell_object( player, "Your stomach starts to emit funny noises "
      "as you begin to feel woozy.\n" );

   tell_room( environment( player ), player->the_short() +
      " looks a bit disoriented.\n", player );
   
   player->submit_ee( "message", 15, EE_ONCE );

   player->submit_ee( 0, 50, EE_REMOVE );

} /* beginning() */


void message( object player, int args, int ) {
   tell_object( player, "You feel slightly more stable "
      "now, but by the look of your surroundings you "
      "still feel as if you're on a carousel.\n" );

   tell_room( environment( player ), player->the_short() +
      " sways slightly.\n", player );

   command_object = clone_object( COMMANDOB );

   if( !command_object ) {
      player->tell_object( player, "A voice whispers, "
         "almost beyond hearing:  Oops.\n" );
      player->submit_ee( 0, 0, EE_REMOVE );
      return;
   }
   
   command_object->add_property( "owned by", player->query_name() );
   
   tell_creator( player, "Bing: %O\n", command_object->query_property( "owned by" ) );
   
   command_object->move( player );

   tell_object( player, "It seems that your mind has weakened "
      "somewhat.  You might be able to take advantage of this "
      "and \"focus\" on one of the spells in your mind to see "
      "if you can pin it down for closer examination.\n" );

} /* message() */


int merge_effect( object player, int old_args, int new_args ) {

   if( new_args ) {
      old_args += new_args;
      tell_object( player, "You feel even woozier.\n" );
   }
   
   return old_args;

} /* merge_effect() */


void restart( object player, mixed *args, int ) {
} /* restart() */


void end( object player, int args, int ) {

   object cmdob;
   
   if( !cmdob = find_right_object( player ) ) {
      tell_creator( player, "(Couldn't find right command object.)\n" );
      tell_object( player, "It seems that the dizziness attack has "
         "passed.\n" );
      player->new_parser( "burp" );
      return;
   }
   
   if( cmdob->query_spell_focused() ) {

      tell_object( player, "The spell thrashes around "
         "in your mind, attempting to release itself from "
         "your grip.  You hold on firmly, and after a while "
         "everything seems to dim, and finally fade to "
         "black.\n" );

      tell_room( environment( player ), player->the_short() +
         " promptly passes out.\n", player );
   
      player->set_position( "lying" );
      
      player->add_effect( EFFECT, ({
         cmdob->query_spell_focused(), 0, 0 }) );
   }      
   else {
      tell_creator( player, "(You didn't focus on a spell.)\n" );
      tell_object( player, "It seems that the dizziness attack has "
         "passed.\n" );
      player->new_parser( "burp" );
   }

   if( cmdob ) {
      cmdob->safety_check();
   }

} /* end() */

