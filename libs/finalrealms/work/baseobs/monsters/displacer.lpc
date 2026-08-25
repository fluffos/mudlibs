inherit "/obj/monster";


void setup() {

        set_level(5);
        set_wimpy(0);
        set_name("displacer");
        add_alias("beast");
        add_alias("displacer");
       set_main_plural("beasts");
        set_short("displacer beast");
        set_long("It is a vaguely puma-like creature with bluish black skin "
                 ", and dead black tentacles. Its eyes are a hellish "
                 "glowing green.\n");
        set_kill_xp(550);
        set_guild("fighter");
       set_aggressive(1);
       add_move_zone("lowtun");
       set_move_after(5, 30);
}

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack() {

int two, three, four, five;

two = random(2);
three=random(3);
four=random(4);
five=random(5);

  return ([
"punch"   :({ AN+" "+({"claws", "rips",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"claws", "rips",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

"kick"    :({ AN+" "+({"bites", "claws",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"bites", "claws",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

"knee"    :({ AN+" "+({"chomps", "slashes",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"chomps", "slashes",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),

"headbutt":({ AN+" "+({"rips", "tears a new hole",})[two]+" on the "+({"arm","hand","leg","neck",})[four]+" of "+DN+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"rips", "tears a new hole for",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),  ]);}

