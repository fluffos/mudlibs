//Cracked by zoom
//daoyou.c 新手学堂导游
//2004.3.30

#include <ansi.h>

inherit NPC;

int ask_help();
void greeting(object);

void create()
{
	set_name("叮当", ({ "dao you", "guider"}));
	set("long", "他张的极俊俏，笑嘻嘻地和蔼可亲。\n");
	set("nickname", "导游");
	set("gender", "男性");
	set("age", random(5) + 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 500);
	set("eff_jing", 500);
	set("jing", 500);
	set("max_neili", 500);
	set("eff_neili", 500);
	set("neili", 500);
	set("max_jingli", 500);
	set("eff_jingli", 500);
	set("jingli", 500);
	set("combat_exp", 30000 + random(5) * 10000);
	set("score", 1000);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("strike", 50);
	set_skill("sword", 50);
//	set_skill("taiji-shengong", 50);
//	map_skill("force", "taiji-shengong");
//	prepare_skill("strike", "wuyu-zhangfa");

	set("inquiry", ([
			"help"   : 	(: ask_help :),
			"帮助"   : 	(: ask_help :),
			"庄主"   : 	"庄主在书房\n",
		]));

	setup();
//	carry_object("/clone/weapon/changjian")->wield();
//	carry_object(__DIR__"obj/yellowrobe")->wear();

}
void init()
{
        object me = this_player();
		::init();
        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	object room;
	if (me->query_temp(this_object()->query("id")) == 0 )
		{	command("hi " + me->query("id"));
			command("say 
          是新来的吧，新手学堂可以帮你学到一些基本的操作，熟悉
    环境。你不妨四处看看(look)。地上有什麽东西你都可以捡起来
    (get)收着。你可以先查查(i or inventory)看你现在身上有些什
    麽。你要不时地查查(hp)你的身体状态，要是饿了或渴了就去找
    些吃的喝的吧。你要是有什麽问题可以问我。
    "+HBRED+HIW"(ask guider about help)"NOR);
		}
}

int ask_help()
{
	command("say 
          这里是新手学堂，你可以在这里学到一些基本的操作，可以熟悉
    一下环境。");
//可以自己出去走走，你身上的新手精灵会指点你一些常识的
//    东西。有什么不懂的也可以问他。这里还有其他客人，失陪勿怪。");
   return 1;
}

