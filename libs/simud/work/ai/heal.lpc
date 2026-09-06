// This module is designed for smart mobs with the heal spell, they will find
// a comfortable level at which to restore their hp as battles progress
#include <magic.h>
#include <const.h>
inherit "/ai/module";

string query_module_name() {
   return "heal";
}

// percentage of hp at which to heal
int threshold;
int query_threshold() {
  if (!threshold)
    threshold = 50;
  return threshold;
}
void set_threshold(int x) {
  threshold = min(max(1,x),100);
}
void add_threshold(int x) {
  set_threshold(query_threshold() + x);
}

// true if waiting for spell to finish casting
int healing;
int ohp;		// hp last tick
int query_healing() { return healing; }
void set_healing(int x) {
  healing = (x?1:0);
  // healed to full
  if ( !healing && environment()->query_hp() >= environment()->query_max_hp() )
	add_threshold(-5); // cast much later
}

void on_tick() {
   object ob = environment();
   int hp = ob->query_hp();
   int mhp = ob->query_max_hp();
   int mana = ob->query_mana();
   int mmana = ob->query_max_mana();
   int cost = MAGIC_DAEMON->query_cost("mana", 5);

//   debug("heal: "+hp+"/"+mhp+" t="+threshold+" h="+healing,"ai");

   // if already healing...
   if ( healing ) {
	  if ( ohp < hp ) // took damage while casting, cast sooner
	     add_threshold(1);
	  ohp = hp;
      return;
   }

   // if insufficient mana... (yeah, I know, magic numbers...)
   if ( mana < cost ) {
      add_threshold(-1);   // running out of mana, cast later
      ohp = hp;
	  return;
   }

   // heal if hp is below threshold
   if ( query_threshold() > 100 * hp / mhp ) {
	  if( !ob->query_env_var( "heal_msg" ) )
             say("Ouch! I'm below my threshold of "+threshold+"% hp. Healing.");
          else
             ob->msg_local( ob->query_env_var( "heal_msg" ) );

	  command("cast heal", ob);
	  set_healing(1);
	  call_out("set_healing",10,0);
   }
   ohp = hp;
}
