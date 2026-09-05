//trainer.c
//by zoom
//2003.3.30

#include <ansi.h>

inherit NPC;

void greeting(object);

void create()
{
        set_name("教头", ({ "trainer"}) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "这是个和蔼可亲的教头。\n");
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
	{	command("hi " + me->query("id"));
		command("say 
         这位" + RANK_D->query_respect(me) + 
	          "来练功了，真是好样的。
    练功累吧？没关系，苦尽甜来嘛！
    行走江湖，不会武功是要吃大亏的。
    我来教你练功的方法吧：
    功夫可以跟师傅学习("+HBRED+HIW"learn|xue"NOR+")，也可以自己练习("+HBRED+HIW"pratice|lian"NOR +")，
要是机缘好，能找到秘籍什么的就更好了，可以通过读书("+HBRED+HIW"study|du|read"NOR+")来提高武学技能。
要是不介意的话，不才可以教阁下一些皮毛。");

		me->set_temp(this_object()->query("id"), 1);

	}
}

int recognize_apprentice(object ob)
{
	return 1;
}