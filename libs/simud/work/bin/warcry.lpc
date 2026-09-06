#include <textdraw.h>

int main(string param) {
   string command = "", arg = "";
   string warcry = this_player()->query_env_var("warcry");
   string myName = this_player()->query_cap_name();
   set_actor(this_player());
   set_target(this_player());
   if(!param) {
      if( warcry ) {
         int check;
		 object warcry_ob;
		 // can't already be in combat
		 if( this_player()->query_in_combat() ) {
		    notify_fail("You cannot shout your warcry once battle has been joined!\n");
			return 0;
		 }
		 // can't already have a warcry active
		 if( present_clone("/battle/warcry_object",this_player()) ) {
		    notify_fail("You have already shouted your warcry, hurry up and kill something!\n");
			return 0;
		 }
         // must have endurance
		 if( this_player()->query_endurance() < 10 ) {
            notify_fail("You don't have enough endurance to shout your warcry.\n");
			return 0;
		 }
		 // determine strength of cry
		 check = this_player()->get_skill_roll("combat.tactics");
		 //practice is handled by the object so they don't get free pracs for shouting outside
		 //of combat ;)
		 //this_player()->practice_skill( "combat.tactics", min(1, check / 25) );
		 // debit endurance
		 this_player()->add_endurance( -2 - check/10 );
		 if( this_player()->query_endurance() < 1 ) {
            check += this_player()->query_endurance() * 10;
			this_player()->set_endurance( 1 );
		 }
		 // give them the object
		 warcry_ob = clone_object("/battle/warcry_object");
		 warcry_ob->do_setup( this_player(), check );
		 // issue message
	     warcry = recolor(warcry);
         if(!this_player()->query_toad())
            this_player()->msg_local("~[010~Name ~verbshout ~poss warcry: ~CDEF" + warcry);
      } else {
         msg("You whimper like a puppy. Perhaps you should set a warcry first?");
	  }
   } else {
      if(sscanf(param, "%s %s", command, arg) != 2) {
         command = param;
      }
      switch(command) {
	     case "check":
            if(warcry != 0) {
               msg("Your warcry is: " + warcry);
            } else {
               msg("Sorry, you haven't set a warcry yet.");
            }
            break;
         case "set":
            this_player()->set_env_var("warcry", arg);
            msg("Warcry set to: " + arg);
            break;
         default:
            msg("Please read ~CREFhelp warcry~CDEF for the correct usage of this verb.");
      }
   }
   return 1;
}
