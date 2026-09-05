// jiuyin-zhenjing1.c
#include <ansi.h>
inherit ITEM;
int do_zuanyan(string arj);

void create()
{
     set_name(MAG "马屁宝典" NOR, ({ "mapi baodian", "baodian","book" }));
        set_weight(200);
        set("unit", "本");
        set("long", "《马屁宝典》    ----韦小宝  口述  双儿  笔录.\n");
        set("value", 20000);
	//set("no_drop",1);
	set("material", "paper");
        set("skill", ([
                        "name": "flatter",      	// name of the skill
                        "exp_required": 100,  	// minimum combat experience required
                        "jing_cost": 10+random(10),	// jing cost every time study this skill
                        "difficulty":   10,     	// the base int to learn this skill
                        "max_skill":    100      // the maximum level you can learn
        ]) );
setup();
}

