#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "Avenger");
  set("long", @ENDLONG
The blade of avenger glows with a magical auburn
light, fine drawings are encrusted within the blade.
ENDLONG
 );
  set("id", ({
    "avenger",
    "sword",
    "weapon",
  }));
  set("size", 5);
  set("name", "Avenger");
  set("bulk", 30);
  set("mass", 21);
  set("nosecond", 1);
  set_value(1500);
  set("weapon", 15);
  set("damage", ({ 15,40 }));
  set_type("cutting");
  set_verbs( ({
    "lunge at",
    "attempt to maim",
    "slice repeatedly at",
    "gouge at",
    "attempt to lancinate",
}));
  set("post_wield_func", "special_on");
	set("pre_wield_func", "req_func");
}

int req_func(){
   if(TP->query_level() <19) {
        write("You are not of high enough level to use that weapon.\n");
 return 1;
}  
}
int special_on() {
  write(@ENDLONG
Avenger tells you: "May we slay countless opponents master."
ENDLONG
);
return 1;
}

int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = 10 + random(50);
  victim = environment()->query_current_attacker();
  if (random(100) < 20) {
  message("combat",
        victim->query("cap_name") + " is overcome by the sheer power of Avenger!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You are cut to pieces as Avenger strikes you repeatedly!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "Avenger slices repeatedly into its opponent!\n");
    return 0;
  }
}