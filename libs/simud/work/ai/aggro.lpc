#include <sys/regexp.h>
inherit "/ai/module";

int aggro_level;

void set_aggro_level(int x) { aggro_level = x; }
int query_aggro_level() { return aggro_level; }

string query_module_name() {
   return "aggro";
}

void on_sight( object ob, object source ) {
   //say( "saw "+ob->query_name() );
   // only aggro against players ;)
   if ( !ob->query_is_player() ) {
      //say( "not attacking mob");
      return;
   }
/*   // charisma has chance of preventing aggression
   if ( ob->stat_check("cha", aggro_level) ) {
	  //say( "not attacking charming player (level="+aggro_level+")" );
      return;
   }
*/
   // don't pick on additional targets if you're already fighting
   if ( environment(this_object())->query_in_combat() ) {
      //say( "not attacking since i'm already fighting" );
      return;
   }
   // otherwise, yar!
   call_out( "do_aggro", 2+random(4), ob );
}

void do_aggro( object who ) {
   object mob = environment(this_object());
   command( "kill " + who->query_name(), mob );
}
