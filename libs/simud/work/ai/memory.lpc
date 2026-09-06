#include <sys/regexp.h>
#include <saveload.h>
inherit "/ai/module";

string *enemies;
object *attackers;

string *query_enemies() { return enemies; }
int query_is_enemy(string name) { return pointerp(enemies) && member(enemies, name) != -1; }

void add_enemy(string name) {
   if( !enemies || !pointerp(enemies) )
      enemies = ({});
   enemies += ({ name });
}

void del_enemy(string name) {
   if ( !enemies || !pointerp(enemies) )
      enemies = ({ });
   enemies -= ({ name });
}

void set_enemies(string *names) { enemies = names; }

string query_module_name() {
   return "memory";
}

void on_hit( object ob, int damage ) {
   string name = ob->query_name();
   object mob = environment(this_object());
   if( !query_is_enemy(name) ) {
      add_enemy(name);
      command( "say Oh, now you're on my list.", mob );
   } else {
      if( damage > 20 )
      command( "ouch", mob );
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
   if( query_is_enemy(ob->query_name()) )
      call_out( "do_aggro", 2+random(4), ob );
   else if( ob->query_is_living() )
      call_out( "do_greet", 2+random(4), ob );
}

void on_death( object who ) {
}

void do_aggro( object who ) {
   object mob = environment(this_object());
   command( "kill " + who->query_name(), mob );
}

void do_greet( object who ) {
   object mob = environment(this_object());
   if( mob->query_recognize(who->query_name()) )
      command( "say " + who->query_name() + ": Hello there!", mob );
   else
      command( "wave " + who->query_name(), mob );
}

