//trainer2.c
//by zoom
//2003.3.30

#include <ansi.h>

inherit NPC;

void greeting(object);

void create()
{
        set_name("武师", ({ "wu shi","shi"}) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "这是个和蔼可亲的武师。\n");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 22);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 30000);
        set("score", 20000);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("sword", 20);
        set_skill("blade", 20);

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
{//	if (me->query_temp(this_object()->query("id")) == 0 )
	{
		command("say 
         学了武功要会用才成，老朽自不量力，就来说说：
    学会了功夫，用会用才成，先看看自己都学了什么("+HBRED+HIW"skills"NOR+")，
    所学的功夫要激发("+HBRED+HIW"enable|jifa"NOR+")，空手功夫还要备("+HBRED+HIW"bei"NOR +")，
如果你所学的功夫支持互备就更好了，你可以同时备两种功夫，
和人打架的时候对手出一招，你就可以出两招， 兵器功夫没这
么麻烦，只要拿对了兵器就能用出来了，不同的是互备用的是("+HBRED+HIW"wbei"NOR+")。
如果你所学的功夫有特殊攻击的话，你可以用可以发招("+HBRED+HIW"perform"NOR+")，
这个可以通过查看("+HBRED+HIW"verify"NOR+")，你的对应技能得到详细情况。");

		me->set_temp(this_object()->query("id"), 1);

	}
}
