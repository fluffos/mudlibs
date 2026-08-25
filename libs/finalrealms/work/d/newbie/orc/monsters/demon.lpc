#include "path.h"

inherit "/obj/monster";

void setup() {
    set_name("demon");
    add_alias("demon");
    set_level(16);
    set_wimpy(0);
    set_random_stats(13,18);
    set_str(17);
    set_dex(17);
    set_con(16);
    set_gender (0);
    set_al (300);
    set_short("Demon");
    set_main_plural("Demons");
    add_plural("demons");
    set_long("  The creature stands some nine feet tall with several eyes "
      "each staring at you!! It has four huge arms and six legs. "
      " Its skin is made of black and green scales and has a reddish "
      "barb at the end of its tail.\n");
    set_aggressive (4);
    adjust_money(6+random(4),"silver");
    this_object()->init_equip();
    add_move_zone("CAVE");
    set_move_after(5,60);
}
//#define AN this_object()->query_cap_name()
//#define DN this_player()->query_cap_name()
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack () {

    int two,three,four,five;
    two=random(2);
    three=random(3);
    four=random(4);
    five=random(5);

    return ([
      "punch"   :({ AN+" "+({"rips","mauls",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"rips","mauls",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
      "kick"    :({ AN+" "+({"slashes","chews",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"slashes","chews",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
      "knee"    :({ AN+" "+({"gnaws","slashes",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"gnaws","bites",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
      "headbutt":({ AN+" "+({"hits","paws",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"hits","bites",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
    ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c

int num = 3;    // number of added attacks

int do_added_attack(object him, object me)
{
    monster::unarmed_attack(him, me);
}
int unarmed_attack(object him, object me)
{
    object *att = me->query_attacker_list();
    int i,j;
    for(i=0; i<sizeof(att); i++)
    {
	for(j=0; j<num+1; j++)
	    do_added_attack(att[i],me);
    }
}
void do_death(object att){
    // check for att!!!!   - Radix
    if(att) 
    {
	tell_object(att,"With one mighty stroke you cut off the Demon's head!\n");
	tell_room(environment(att), att->query_cap_name()+" takes one"
	  " mighty slice at the Demon's head and cuts it off.\n",att);
    }
    clone_object("/d/newbie/orc/items/misc/dhead")->move(environment(this_object()));
    ::do_death(att);
}
