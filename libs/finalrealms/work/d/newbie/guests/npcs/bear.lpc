inherit "/obj/monster";
#define AN attacker->query_cap_name()
 
 
#define DN defender->query_cap_name()
#define MAXDAMAGE 60
 
 
void setup() {
 
set_level(8);
set_al(-60);
//set_kill_xp(750);
        set_wimpy(0);
         set_name("bear");
         add_alias("Bear");
set_short("Bear");
set_long("Strips of matted fur hang off this malformed creature's "
         "back as he stares listlessly off at the distance.  Its eyes "
         "are coated with a thin green haze that glows from years of "
         "immersion in this black forest.  Its muscles outlined under the "
         "shag of his fur tremble for a season of hibernation that has "
         "never arrived.\n");
        set_guild("monster");
     set_aggressive(0);
 
   load_chat(25,
   ({
     1, ":licks crystallized bits of honey off its claws.",
     1, ":shudders incessantly.",
     1, ":never takes its glowing eyes off you.",
     1, ":lumbers about.",
     1,":has no one to bear hug.",
     1,":scratches the trunk of a tree with its curved claws.",
     1,":clamors atop a tree stump.",
     1,":swats halfheartedly at a flying locust."
        }));
   load_a_chat(20,
   ({
     1,":stretches and seperates his claws.",
     1,":moves quickly towards you!",
     1,":rises upon its hind legs.",
     1,"An angry bear could be dangerous to your health.",
     1,":paces around you, trying to corner you for its attack.",
     1,":darts at you with a deadly claw."
 
     }));
}
 
valid_attack() {
 
int two, three, four, five;
 
two = random(2);
three=random(3);
four=random(4);
five=random(5);
 
  return ([
"punch"   :({ AN+" "+({"tears", "claws",})[two]+" "+DN+" on the "+({"thigh","ear","chest","shoulder",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"tears", "claws",})[two]+" you on the "+({"thigh","ear","chest","shoulder",})[four]+".\n"}),
 
"kick"    :({ AN+" "+({"tears", "claws",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"tears", "claws",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
"knee"    :({ AN+" "+({"bats", "boxes",})[two]+" "+DN+" on the "+({"thigh","ear","chest","shoulder",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"bats", "boxes",})[two]+" you on the "+({"thigh","ear","chest","shoulder",})[four]+".\n"}),
 
"headbutt":({ AN+" "+({"bats", "boxes",})[two]+" on the "+({"arm","hand","leg","neck",})[four]+" of "+DN+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"bats", "boxes",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),  ]);}

