/* function for std_bow   */

weapon_hit(attacker){
object quiver; 
 if (present("quiver_of_arrows",this_player()))
  { 
	write("You shoot an arrow agains your enemy.\n");
	say(this_player()->query_name()+" shoots an arrow against "+this_player()->query_possessive()+
             "enemy.\n");
	quiver=present("quiver_of_arrows",this_player());
	quiver->dec_arrows(1);
        return dama;
  }

 }
 
