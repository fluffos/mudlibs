#include <swamp.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("unicorn");
set_short("A majestic unicorn");
set_long("A white coat unicorn with a beautiful %^RED%^r%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^MAGENTA%^w%^RESET%^ colored horn.  You can't help but wonder why it chooses to wander the swampland.");

set("aggressive",  0);
set_id(({"unicorn", "majestic unicorn", "horse"}));
set_skill("attack", 300);
set_skill("magic attack", 300);
set_skill("faith", 300);
set_moving(1);
set_speed(10);
set_class("fighter");
set_subclass("warrior");
set_alignment(0);
set_skill("projectile", 200);
set_stats("intelligence", 90);
set_stats("wisdom", 60);
set_race("unicorn");
set_body_type("hrnquadrupe");
if(random(5) > 2) set_gender("male"); else set_gender("female");
set_spell_chance(45);
set_skill("charging", 700);
set_spells(({"rush"}));
set_level(60);

set_skill("faith", 250);
}
void heart_beat() {
 object env, ob;
 ::heart_beat();
  if (!this_object()) return;
   if (!this_object()->query_current_attacker()) return;
   if (random(3000) > 600) return;
   ob = this_object()->query_current_attacker();
   env = environment(ob);
   switch (random(2)) {
     case 1:  // gore
       tell_object(env, "%^YELLOW%^BOLD%^The unicorns horn %^WHITE%^FLASHES %^YELLOW%^brightly as it gores into its opponent!");
       ob->damage(750);
       break;
     default: // heal
       tell_object(env, "%^ORANGE%^The unicorn heals itself!");
     this_object()->damage(-1000);
   }
}
