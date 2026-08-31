#include <std.h>
inherit MONSTER;

private object owner;
private int silence = 0;

void set_owner(object ob) { owner = ob; }

int claim(string str) {
   if (!str || str == "") return 0;
   if (!wizardp(this_player())) {
write("%^BOLD%^RED%^Only the Lord of Demons %^BLACK%^Asmodeus%^RED%^ may command Maltheus!%^RESET%^");
      return 1;
   }
   if (owner)
    if (owner != this_player()) {
write("%^BOLD%^%^RED%^Maltheus laughs at you.%^RESET%^");
      return 1;
    }
   if (owner == this_player()) {
present("maltheus")->force_me("say my Lord Asmodeus, I shall always do your bidding.");
      return 1;
   }
write("%^BOLD%^%^RED%^Methulas will now do your bidding!%^RESET%^");
   owner = this_player(); 
   return 1;
}

int stfu(string str) {
   if (!str || str == "") return 0;
if (str != "maltheus") return 0;
present("maltheus")->force_me("say [*] Talking has been turned off -");
   silence = 1;
   return 1;
}

int speak_on(string str) {
if (str != "maltheus") return 0;
present("maltheus")->force_me("say [*] Talking has been turned on! -");
   silence = 0;
   return 1;
}

init() {
  ::init();
   add_action("claim", "claim");
   add_action("stfu", "stfu");
   add_action("speak_on", "talk");
}

create() {
  ::create();
set_name("Maltheus");
set_short("Maltheus, bodyguard to Asmodeus");
set_id( ({"maltheus", "dork", "demon", "demon lord", "servant"}) );
set_long("Maltheus is one of the most powerful entities in existence.  He protects Asmodeus with his eternal soul.");
set_level(250);
   set_hp(10000000); // 10,000,000 (10 million) hp, sp, and mp
set_race("demon");
set_body_type("half-dragon");
   set_gender("male");
   set_mp(10000000);
   set_sp(10000000);
   set("aggressive", 0);

}

void heart_beat() {
   int i;
::heart_beat();
   i=random(40);
  if (silence == 0) {
   switch (i) {
     case 1:
present("maltheus")->force_me("say I await your command my Lord.");
       break;
     case 10:
present("maltheus")->force_me("say I devour the souls of the innocent.");
       break;
     case 20:
present("maltheus")->force_me("wails a demon death call!");
break;
     case 30:
present("maltheus")->force_me("say The armies of Hell will vanquish the pure!");
       break;
     case 40:
present("maltheus")->force_me("say Command me great Warrior!");
       break;
   }
  }
   if (!owner) return;
   if (environment(owner) != environment(this_object())) {
message("info", "%^BOLD%^%^GREEN%^Maltheus dissipates into nothing.%^RESET%^", environment(this_object()));
      this_object()->move(environment(owner));
message("info", "%^BOLD%^%^GREEN%^Maltheus appears in a swirling vortex of dark matter.%^RESET%^", environment(owner));
   }
}
