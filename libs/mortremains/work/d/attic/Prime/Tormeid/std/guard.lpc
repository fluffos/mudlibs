// The standard guard for the castle.  All the guards have some basic training
// before they are allowed to protect the castle! :D
// Written by Chronos a long long time ago.
// (04-10-98) Minor modifications made by Chronos.
#include "../defs.h"

inherit MONSTER ;

create(){
  ::create() ;
  set("pursuing", 1) ;
  set("short", "a guard");
  set("long", @ENDLONG
A member of the castle guard.
ENDLONG
  );
  set("id", ({ "guard", "castle guard" }) );
  set("gender", "male");
  set("race", "human");
  set_name("guard");
 set_level(30) ;
  set_alignment("ln") ;
  enable_commands() ;
  set("natt", 2) ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  set("chat_chance", 4);
  set("chat_output", ({
  "The guard looks at you suspiciously.\n",
  "The guard eyes you carefully.\n",
  "The guard keeps a look out with a watchful eye.\n",
  "The guard shifts uncomfortably from foot to foot.\n",
  "The guard sighs loudly.\n",
  "The guard stares at you.\n",
  "The guard polishes his weapon.\n",
  }) );
  set("att_chat_output", ({
   "The guard calls for other guards to raise the alarm!\n",
  "The guard calls for reinforcements!\n",
  }) );
}

void init() {
  add_action("kill", "kill" ) ;
  add_action("bash", "steal") ;
  add_action("cast", "cast") ;
  add_action("bash", "bash") ;
}

int cast(string str) {
  call_out("check_him", 4+random(4), TP) ;
  return 0;
}

int kill(string str) {
  call_out("check_him", 1, TP ) ;
  return 0;
}

int check_him(object him) {
  if (!him) return 0;
  if (!present(him, environment())) return 0;
  if (him->query_guard()) return 0 ;
  if (him->query_king()) return 0 ;
  if (him->query_attackers()) {
    message("combat",
   "Guard says: No fighting in the castle!\n", environment(TO)) ;
   kill_ob(him);
   return 1;
  }
  return 0;
}

void relay_message(string Class, string str) {
  string attacker, victim ;
  object fellow ;

  if (str) {
      if (sscanf(str, "%s attacks %s", attacker, victim)==2 ||
          sscanf(str, "%s swings at %s", attacker, victim)==2 ) {
    if (sizeof(this_object()->query_attackers())==0) {
      fellow = find_living(lower_case(attacker)) ;
      if (fellow) {
   if (check_him(fellow)) {
  this_object()->kill_ob(fellow) ;
     tell_object(fellow, "The guard attacks you!\n");
        say ("The guard attacks "+fellow->query("cap_name")+
             "!\n") ;
  }
     tell_object(environment(TO), "Guard says: No fighting in the castle!\n");
      }
    }
  }
  }
  ::relay_message(Class, str) ;
}
 

int query_guard() { return 1; }

int bash(string str) {
  if (!str) return 0 ;
  if (TP->query("invisible")) return 0 ;
  write("Guard says [to you]: Don't you be thinking about getting rowdy in here.\n") ;
  message("bullshit", iwrap("Guard says [to "+TPN+
   "]: Don't you be thinking about getting rowdy in here.\n"),
   environment(TO), ({ TP }) ) ;
  return 1;
}



