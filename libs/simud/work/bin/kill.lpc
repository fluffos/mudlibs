#include <const/battconst.h>

/**
 * Added as a quick fix to prevent victims from being locked in combat by
 * stupid aggro npc's who start fights from across unwalkable barriers.
 * - al [jan 30, '05]
 */
void attack_target(object ob) {
   object *targets = this_player()->query_targets();
   if( !pointerp(targets) )
      this_player()->set_targets( ({ ob }) );
   else if( member(targets, ob) == -1 )
      this_player()->set_targets( targets + ({ ob }) );
   this_player()->cpr();
}

void notify_fight(object who,object victim) {
	object ob;
	debug("notify_fight: "+who->query_name()+", "+victim->query_name(),"combat");
	foreach( ob : all_inventory(environment(who)) ) {
		if( !ob->query_is_living() )
			continue;
		debug("notify_fight: telling "+ob->query_name(),"combat");
		ob->on_fight(who,victim);
	}
}

int main(string str) {
   object ob;

/**
   if (this_player()->query_level() != 1000) {
      msg("Death is forbidden! Yell at Al.");
      return 1;
   }
**/

   if( this_player()->query_dead() ) {
      notify_fail( "Alas, it is for the living to avenge the dead. Try haunting.\n" );
      return 0;
   }

   if( !str ) {
      notify_fail("Kill what?\n");
      return 0;
   }
   if (this_player()->query_stance() & ST_SITTING | ST_LYING)
     if (!this_player()->change_stance(ST_STANDING)) {
       notify_fail("You really should stand up before picking a fight.");
       return 0;
     }

   ob = single_present(str, environment(this_player()), (: $1->query_is_living() :));
   if( !ob ) ob = single_present(str, environment(this_player()) );
   if( !ob ) {
     notify_fail("I don't know what you mean by '"+str+"'.\n");
     return 0;
   }
   else if(ob == this_player()) {
     notify_fail("You, know therapy and mind altering drugs are really a better solution.\n");
     return 0;
   } else if ( !ob->query_is_living() ) {
     notify_fail("Attacking inanimate objects is pointless. Yay, you win.\n");
     return 0;
   } else {
     // this_player()->start_combat(ob, 1);
     attack_target(ob);
     set_target(ob);
     this_player()->msg_local("~CACT~Name ~verbattack ~targ!~CDEF");
     // notify everyone
     notify_fight( this_player(), ob );
   }
   return 1;
}
