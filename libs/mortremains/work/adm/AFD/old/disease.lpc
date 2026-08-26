// This is the standard inheritable contagion. :D -- Written by Chronos.
#include <mudlib.h>
#undef TP
#undef TPN
#define TP environment()
#define TPN TP->query("cap_name")
int infect_player(object victim);

inherit OBJECT;

#define DISEASE_PATH "/std/disease"

int spread();
int get_better();


void create() {
  seteuid(getuid());
  set("invisible", 1);
  set("prevent_drop", 1);
  set("infection_rate", 8);
  set("prevent_insert", 1);
  set("contagion", "flu");
  set("prevent_get", 1);
  set("id", ({ "CONTAGION_FX" }) );
}

void init() {
 add_action("spread", "cough");
 add_action("spread", "shout");
 add_action("spread", "say");
 add_action("spread", "sing");
 add_action("target_spread", "laugh");
 add_action("target_spread", "hug");
 add_action("target_spread", "kiss");
  add_action("target_spread", "excite");
  add_action("spread", "sneeze");
 add_action("target_spread", "lick");

}

int set_infection_rate(int x) {
  set("infection_rate", x) ;
  return 1;
}

int set_contagion(string flu) {
  set("contagion", flu);
  return 1;
}

query_auto_load() {
  return DISEASE_PATH + ":";
}

int spread() {
  object victim, env, *inv;
  int i;
  env = environment(environment(this_object()));
  if (!env) return 0;
  inv = all_inventory(env);
  if (!inv) return 0;
  for(i=0;i<sizeof(inv);i++) if (userp(inv[i]))
  if (random(100)+1 < (int)query("infection_rate")) infect_player(inv[i]);
  return 0;
}

int target_spread(string str) {
  object target;
  if (!str) call_out("spread", 1);
  target = find_player(str);
  if (!target) call_out("spread", 1);
  if (environment(target) != environment(TP)) call_out("spread", 1);
  if (random(100)+1<(int)query("infection_rate")) infect_player(target);
  return 0;
}

int infect_player(object victim) {
  object virus;  

// Oops.  How did that happen?  
  if (!victim) return 1;
  
// Are they already sick?
  if (present("CONTAGION_FX", victim)) return 1;

// Infect em! *cackle*
  virus = clone_object(DISEASE_PATH);
  virus->move(victim);
  virus->init();                // Just to be sure.
// If they are immune to the sickness, make them a carrier. :)
  if (victim->query("immunity/"+query("contagion"))) virus->be_carrier();
// Otherwise, they are sick, and a carrier.   Muahahahaha!
  else virus->be_sick();
  virus->init();                // Just to be sure.
  return 1;
}

int be_carrier() {
  spread();
  call_out("be_carrier", random(300) + 30);
  return 1;
}

int be_sick() {
  set("extra_look", environment()->query("cap_name") + " looks rather ill.\n");
  call_out("sickness_loop", random(60) + random(60) + 1);
  return 1;
}
  
int sickness_loop() {
  switch(random(100)+1) {                             
    case 1..10 : write("You cough violently.\n");
                 say(TPN + " coughs violently.\n");
                 set("extra_look", TPN + " does not look well.\n");
                 break;
    case 11..20: write("You feel sick.\n");
                 say(TPN + " looks sick.\n");
                 set("extra_look", TPN + " looks sick.\n");
                 break;
    case 21..30: write("You sneeze loudly.\n");
                 say(TPN + " sneezes loudly.\n");
                 set("extra_look", TPN + " looks moderately ill.\n");
                 break;
    case 31..40: write("You feel sore.\n");
                 say(TPN + " looks uncomfortable.\n");
                 set("extra_look", TPN + " looks ill.\n");
                 break;
    case 41..50: write("You have a headache.\n");
                 say(TPN + " grimaces in pain.\n");
                 set("extra_look", TPN + " looks very sick.\n");
                 break;
    case 51..60: write("You feel dizzy.\n");
                 say(TPN + " looks sick.\n");
                 set("extra_look", TPN + " looks very ill.\n");
                 break;
    case 61..70: write("Your stomach aches.\n");
                 say(TPN + " looks sick.\n");
                 set("extra_look", TPN + " looks sick.\n");
                 break;
    case 71..80: write("Your throat feels sore.\n");
                 say(TPN + " looks sick.\n");
                 set("extra_look", TPN + " looks sick.\n");
                 break;
    case 81..85: write("You feel really hot.\n");
                 say(TPN + " looks sick.\n");
                 set("extra_look", TPN + " looks very sick.\n");
                 break;
    case 86..90: write("You feel really cold.\n");
                 say(TPN + " looks sick.\n");
                 set("extra_look", TPN + " looks very sick.\n");
                 break;
    default: write("You feel better.\n");
             say(TPN + " looks well again.\n");
            set("extra_look", TPN + " looks kind of sick.\n");
             get_better();
             break;
  }
  spread();
  call_out("sickness_loop", random(300) + 30);
  // Every 30 seconds - 5.5 minutes something happens.
  return 1;
}

int get_better() {
  // All better.  You are rid of the disease.  But you can still be a
  // carrier.
  environment()->set("immunity/"+query("contagion"), 1);
  environment()->save_data();
  remove();
}
