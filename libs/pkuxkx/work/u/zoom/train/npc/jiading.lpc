//jiading.c
//by zoom
//2003.3.30

#include <ansi.h>

inherit NPC;

void greeting(object);

void create()
{
	set_name("家丁", ({ "jia ding", "jia" }));
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", 1);
	setup();
}
	

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("hi " + me->query("id"));
		command("say 
         这里有兵器可以用来练习，挑(na|qu)一件吧。
    不管武功高低，拿个兵器总是好的，兵器能加一定的伤害，而穿了甲可以
    提高防御，身上光带着兵器是不行的，要装备起来才成，武器要("+HBRED+HIW"wield xx"NOR+")，
如果想左手拿兵器就用("+HBRED+HIW"wield xx 2"NOR+")，想放下手中的兵器要("+HBRED+HIW"unwield"NOR+")。
同样甲要穿上("+HBRED+HIW"wear"NOR+")才管用,脱下来是("+HBRED+HIW"remove"NOR+")。");

		me->set_temp(this_object()->query("id"), 1);

	}
}

