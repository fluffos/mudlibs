/*  File upgrade by Grimbrand 2-11-96                                   */

inherit "/obj/monster";

nosave int i = 0;
object cloak;
 
void setup() {
   set_name("hook horror");
   add_alias("hook");
   set_short("Decrepid Hook Horror");
   set_long("   Before you stands what is left of a hook horror.  At one "
            "time this creature stood at least three times a duergar's "
            "height, but now it can barely stand erect.  Its exoskeleton "
            "of hard armor plates appear to have gotten weak over the years "
            "and it is even missing one of its claws.  This is a truely "
            "poor example of an extremely dangerous race."
            "\n\n");
   set_main_plural("hook horrors");
   set_gender(1);
   adjust_gp(4);
   set_random_stats(6,18);
   set_str(12);
   set_level(8);
   set_max_hp(34);
   set_al(100+random(50));
   set_wimpy(0);        
   set_kill_xp(431);
   adjust_money(5,"gold");

} /* setup() */

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
#define MAXDAMAGE 5
mapping valid_attack () {

  int GP,two,three,four,five;
  two=random(2);
  three=random(3);
  four=random(4);
  five=random(5);

   if(random(15))
     {
      GP = attacker->query_gp();
   
      if(GP>9)
        {
         if (i<2)
            say(AN+" swings a claw.\n");
            i = i +1;
         if(i>2)
           {
            i = 0;
            say(AN+" smashes "+DN+" withs its claw!!!\n");
            defender->adjust_hp(-(random(MAXDAMAGE)), this_object());
           }
        }
     }
   return ([
   "punch"   :({ AN+" "+({"claws", "tears",})[two]+" "+DN+" on the "+
              ({"arm","hand","leg","neck",})[four]+".\n",
              "You hit "+DN+".\n", AN+" "+({"claws", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
   
   "kick"    :({ AN+" "+({"claws", "tears",})[two]+" "+DN+" on the "+
              ({"arm","hand","leg","neck",})[four]+".\n",
              "You hit "+DN+".\n", AN+" "+({"claws", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

   "knee"    :({ AN+" "+({"claws", "tears",})[two]+" "+DN+" on the "+
              ({"arm","hand","leg","neck",})[four]+".\n",
              "You hit "+DN+".\n", AN+" "+({"claws", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

   "headbutt":({ AN+" "+({"claws", "tears",})[two]+" on the "+
              ({"arm","hand","leg","neck",})[four]+" of "+DN+".\n",
              "You hit "+DN+".\n", AN+" "+({"claws", "tears",})[two]+
              " you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),  
]);
}
