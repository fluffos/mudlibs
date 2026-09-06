#include <battle.h>
#include <race.h>

BATTLE_ACTION( 1000, "animal" )

string query_action_name() {
   return "Grab";
}

void on_action( object victim ) {
   mixed result;
   mapping wc, grappling;
   int damage, x, *hands = ({}), hand;
   string buf = "", bp;

   this_player()->add_readiness(-500);
   if( !BATTLE_DAEMON->check_legal_melee(victim, "grab") )
      return;

   // get list of hands had by the attacker
   foreach( x : m_indices(this_player()->query_race_object()->query_bp_map()) ) {
      if ( x & (BP_HANDS | BP_HANDS2 ) )
         hands += ({ x });
   }

   // make sure they are able to grab
   if (!sizeof(hands)) {
      debug("Grab attempt made by something w/o hands :)","combat");
      msg("~CWRNYou can't grab anything, you've got no hands!~CDEF");
      return;
   }
   // see if they're already grappling
   grappling = this_player()->query_env_var("grappling");
   if (mappingp(grappling)) {
      foreach ( x : m_indices(grappling) ) {
         if ( grappling[x] != victim )
            grappling -= ([x]);
         else
            hand = x;
      }
   }
   // not holding current enemy, grab anew
   if (!hand) {
      hand = hands[random(sizeof(hands))];
      if ( this_player()->skill_check("combat.grappling", victim->get_skill_roll("combat.grappling")) ) {
         object ob = clone_object("/battle/grapple_object");
		 ob->do_setup(hand,this_player(),victim);
		 buf = "~[090~Name ~verbgrab onto ~targ with ~poss "+ob->query_limb_name()+".";
         this_player()->add_endurance(-2);
      } else {
         buf = "~[130~Name ~verbmiss a wild grab at ~targ.";
         this_player()->add_endurance(-5);
      }
   }
   // already grabbing, squeeze ;)
   else {
      // find the correct grappling object
      object ob;
      foreach( ob : all_present("grapple_ob", victim) ) {
         if ( ob->query_holder() == this_player() )
            break;
      }
      if ( !ob || ob->query_holder() != this_player() ) {
         set_target(victim);
         msg("~CWRNYou aren't able to grapple with ~targ.~CDEF");
         return;
      }
      wc = copy(this_player()->query_wc());
      if (!mappingp(wc))
        wc = (["blunt":3]);
      wc["blunt"] += this_player()->query_str_wc();
      // already holding, guaranteed damage
      damage = victim->take_damage_percent(wc);
      this_player()->add_endurance(-2);
      victim->add_endurance(-5);
      if ( damage >= 100 ) {
         buf = "~[090~Name ~verbcrush the life out of ~targ.";
		 ob->do_release();
	  } else if( damage >= 40 )
         buf = "~[090~Name ~verbcrush ~targ in ~poss grip.";
      else if( damage >= 10 )
         buf = "~[090~Name ~verbsqueeze ~targ.";
      else if( damage > 0 )
         buf = "~[090~Name ~verbreadjust ~poss grip on ~targ.";
      else {
         buf = "~[130~Name ~verblose ~poss grip on ~targ.";
         ob->do_release();
      }
   }

   this_player()->msg_local(buf+"~CDEF");
}
