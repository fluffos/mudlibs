// This action brought up to spec and into alignment with the natural order
// of the unverse by Allaryin on Oct 14, 2003.
//
// Combined shield/shoulder bash action, incredibly expensive in terms of
// readiness and endurance, but it has the added bonus of being impossible
// to parry and of stunning your enemy. Later enhancements will probably
// include the ability to knock people to the ground with very successful
// bashes.
#include <battle.h>

BATTLE_ACTION( 1000, ({"bludgeon","axe","brawl"}) )

string query_action_name() {
   return "Bash";
}

void on_action( object victim ) {
   mixed result;
   mapping wc;
   int damage;
   object shield;
   string buf = "";

   this_player()->add_readiness(-1000);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "bash") )
      return;

   if (this_player()->query_endurance())
      this_player()->add_endurance(-2);
   else {
      msg("~CWRNYou are too tired to fight any more!~CDEF");
      this_player()->add_readiness(-1000);
      return;
   }

   // find a held shield
   foreach ( shield : all_inventory(this_player()) )
      if (shield->query_shield() && shield->query_held())
         break;

   // set wc of attack if using a shield
   if (shield && shield->query_shield() && shield->query_held()) {
      wc = copy(shield->query_wc());
      if (!mappingp(wc))
        wc = ([]);
      if (!wc)
         wc = (["blunt":shield->query_ac()]);

      debug("shield = " + shield->query_name(),"combat");
   }
   // set wc of attack if using shoulder
   else {
      wc = (["blunt":this_player()->query_wc("blunt")]);
      debug("shield = shoulder ;)","combat");
      shield = 0;
   }

   wc["blunt"] += this_player()->query_str_wc();

   result = BATTLE_DAEMON->execute_melee(shield, wc, victim, 2, ATT_NO_PARRY);
   damage = result[RESULT_MOD];

   switch (result[RESULT_TYPE]) {
     case "miss":
       buf = "~[130~Name ~verbfly past ~targ as ~pron ~verbtry to ram ~objt with ~poss "+
               (shield ? "shield" : "shoulder") + "!";
       this_player()->add_readiness(-200);
       this_player()->add_busy( random((20-this_player()->query_dexterity())/2) );
       break;

     default:
	   // sound
	   AUDIO_DAEMON->sfx_room(environment(victim),"hithard.wav");

       if (damage)
         victim->add_readiness(-damage*5);

       if (damage >= 10) {
         buf = "~[090~Name ~verbslam into ~targ with ~poss "+
               (shield ? "shield" : "shoulder") + "!";
         victim->add_busy(3);
       } else if (damage > 0) {
         buf = "~[090~Name ~verbrun into ~targ with ~poss "+
               (shield ? "shield" : "shoulder") + ".";
         victim->add_busy(1);
       } else
         buf = "~[130~Targ ~vertdon't flinch as ~name ~verbbump ~objt with ~poss "+
               (shield ? "shield" : "shoulder") + ".";
       break;
   }
   if (result[RESULT_MSG])
     buf += "~[060 "+result[RESULT_MSG];

   this_player()->msg_local(buf+"~CDEF");
}
