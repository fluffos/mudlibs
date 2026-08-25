/*  File upgrade by Grimbrand 2-11-96                                   */

inherit "/obj/monster";

void setup() {
   set_level(8);
   set_wimpy(0);
   set_name("hellhound");
   add_alias("hound");
   add_alias("hell hound");
   set_main_plural("hellhounds");
   add_plural("hounds");
   add_plural("hell hounds");
   set_short("Hell Hound");
   set_long("   Before you stands a dusty red and skinless looking dog. " 
            "At one time this creature skin was covered in flame, and was "
            "considered a fierce foe.  Now the creature looks as if it "
            "needs to return to the hell that it came from.  The long "
            "stay in the material plane has obviously drained its power."
            "\n\n");
   set_kill_xp(431);
   set_max_hp(34);
   set_guild("fighter");
   adjust_money(4,"gold");
}


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
#define MAXDAMAGE 6

mapping valid_attack() {

int two, three, four, five;

two = random(2);
three=random(3);
four=random(4);
five=random(5);

  return ([
   "punch"   :({ AN+" "+({"bites", "tears",})[two]+" "+DN+" on the "+
              ({"arm","hand","leg","neck",})[four]+".\n",
              "You hit "+DN+".\n", AN+" "+({"bites", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

   "kick"    :({ AN+" "+({"bites", "tears",})[two]+" "+DN+" on the "+
              ({"arm","hand","leg","neck",})[four]+".\n",
              "You hit "+DN+".\n", AN+" "+({"bites", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

   "knee"    :({ AN+" "+({"tears", "bites",})[two]+" "+DN+" on the "+
              ({"arm","hand","leg","neck",})[four]+".\n",
              "You hit "+DN+".\n", AN+" "+({"tears", "bites",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

   "headbutt":({ AN+" "+({"bites", "tears",})[two]+" on the "+
              ({"arm","hand","leg","neck",})[four]+" of "+DN+".\n",
              "You hit "+DN+".\n", AN+" "+({"bites", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),  
]);
}
