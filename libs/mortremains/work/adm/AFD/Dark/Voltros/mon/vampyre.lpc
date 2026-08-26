#include "../defs.h"
inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Desmond, Lord of the Undead");
  enable_commands();
  set("long", @ENDLONG
This is a vampyre, ya idjit.
ENDLONG
);
  set_name("desmond");
  set("id", ({
    "vampyre",
    "Desmond",
				"lord",
    "desmond"
}));

		credit(random(5000)+1000);
		set("alignment", -500);
  set("damage", ({ 40, 110 }) );
		clone_object(ARMOR(vampring))->move(TO);
		clone_object(ARMOR(vampcrown))->move(TO);
		clone_object(ARMOR(vamprobes))->move(TO);
		clone_object(ARMOR(vampbrac))->move(TO);
  set_level(50);
		set("size", 10);
		set("undead", 21);
  set("race", "vampyre");
  set("attrib1", "old");  set("attrib2", "gaunt");
  set("gender", "male");
  command("wear all");
  set("weapon_name", "jagged claws");
  set_verbs( ({
    "rakes",
    "slash at",
}));
 set_verbs2( ({
    "rakes",
    "slashes at",
}));

}
void init(){
     if(TPN =="Gendor" || TPN =="Waxer") command("worship "+TPn);
     if(!wizardp(TP)) kill_ob(TP);
}
void heart_beat(){
  object ob;
  ob = query_current_attacker();
  if(ob){
    call_out("move_me", 60+random(20), ob);
}
::heart_beat();
}

int move_me(object ob){
  if(environment(ob) == environment(TO)) return 1;
  TO->move(environment(ob));
  tell_object(environment(ob), "Desmond comes looking for"+ob->query("cap_name")+"!\n");
  set("killer", 0);
  kill_ob(ob);
return 1;
}
