#include <sys/regexp.h>
#include <saveload.h>
inherit "/ai/module";

object *enemies;

object *query_enemies() { return enemies; }
int query_is_enemy(object who) { return pointerp(enemies) && member(enemies, who) != -1; }

void add_enemy(object who) {
   if( !enemies || !pointerp(enemies) )
      enemies = ({});
   enemies += ({ who });
}

void del_enemy(object who) {
   if ( !enemies || !pointerp(enemies) )
      enemies = ({ });
   enemies -= ({ who });
}

string query_module_name() {
   return "peacekeeper";
}

private int is_humanoid( object who ) {
   switch(who->query_race()) {
   case "human":
   case "orc":
   case "elf":
   case "gnome":
      return 1;
   }

   return 0;
}

void on_fight( object attacker, object target ) {
   object mob;

   mob = environment(this_object());

   if ( attacker == mob || target == mob ) {
      return;
   }

   if (is_humanoid(target)) {
      if (is_humanoid(attacker)) {
         say( "Ok wise guy, you're next!" );
      }
      add_enemy(attacker);
      command( "kill " + attacker->query_name(), environment(this_object()) );
   }
}

void on_sight( object ob, object source ) {
   // don't pick on additional targets if you're already fighting
   if ( environment(this_object())->query_in_combat() ) {
      command( "glower " + ob->query_name() );
      return;
   }
   // otherwise, yar!
   if( ob == environment() )
      return;
   if( query_is_enemy(ob) )
      call_out( "do_aggro", 2+random(4), ob );
   else if( ob->query_is_living() )
      call_out( "do_greet", 2+random(4), ob );
}

void on_death( object who ) {
   if( query_is_enemy(who) ) {
      del_enemy(who);
   }
}

void do_aggro( object who ) {
   object mob = environment(this_object());
   command( "kill " + who->query_name(), mob );
}
