// Igor, lacky of the gods
#include <std.h>
inherit MONSTER;

private object owner;
private int silence = 0;

void set_owner(object ob) { owner = ob; }

int claim(string str) {
   if (!str || str == "") return 0;
   if (!wizardp(this_player())) {
      write("%^RED%^Only mad professors and immortals may own a pet Igor!%^RESET%^");
      return 1;
   }
   if (owner)
    if (owner != this_player()) {
      write("%^BOLD%^%^GREEN%^Igor snarls at you.%^RESET%^");
      return 1;
    }
   if (owner == this_player()) {
      present("igor")->force_me("say You arr alrredy mai masstaa.");
      return 1;
   }
   write("%^BOLD%^%^GREEN%^You claim Igor for yourself!%^RESET%^");
   owner = this_player(); 
   return 1;
}

int stfu(string str) {
   if (!str || str == "") return 0;
   if (str != "igor") return 0;
   present("igor")->force_me("say [*] Talking has been turned off -");
   silence = 1;
   return 1;
}

int speak_on(string str) {
   if (str != "igor") return 0;
   present("igor")->force_me("say [*] Talking has been turned on! -");
   silence = 0;
   return 1;
}

void init() {
  ::init();
   add_action("claim", "claim");
   add_action("stfu", "stfu");
   add_action("speak_on", "talk");
}

void create() {
  ::create();
   set_name("Igor");
   set_short("Igor, lacky of the gods");
   set_id( ({"igor", "dork", "lacky", "slave", "servant"}) );
   set_long("%^GREEN%^Igor is the ultimate servant and slave of "
            "the gods. He bends over, due to a rather "
            "large hump in his back. His skin is a pale "
            "green in color, no doubt the result of numerous "
            "poisons and experiments.%^RESET%^");
   set_level(1);
   set_hp(10000000); // 10,000,000 (10 million) hp, sp, and mp
   set_race("goblin");
   set_body_type("human");
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
       present("igor")->force_me("say Whhat wud yu like masta?");
       break;
     case 10:
       present("igor")->force_me("scream in a mad fit");
       break;
     case 20:
       present("igor")->force_me("say Igor be the sexyest goblin in the land!");
       break;
     case 30:
       present("igor")->force_me("say Oi! Oi! Oi!");
       break;
     case 40:
       present("igor")->force_me("snort");
       break;
   }
  }
   if (!owner) return;
   if (environment(owner) != environment(this_object())) {
      message("info", "%^BOLD%^%^GREEN%^Igor leaves to follow his master.%^RESET%^", environment(this_object()));
      this_object()->move(environment(owner));
      message("info", "%^BOLD%^%^GREEN%^Igor stumbles in after his master.%^RESET%^", environment(owner));
   }
}
