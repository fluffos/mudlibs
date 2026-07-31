// npc: /d/xingxiu/npc/afanti.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("阿凡提", ({ "afanti" }) );
	set("gender", "男性" );
	set("age", 48);
	set("long", 
	    "他头上包着头巾，长着向上翘的八字胡，最喜欢捉弄巴依、帮助穷人。他常给别人出谜语。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("dodge", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set("combat_exp", 2500);

	set("attitude", "peaceful");
	set("inquiry", ([
	    "name" : "我就是纳苏尔的阿凡提。",
	    "纳苏尔" : "是我出生的地方。",
	    "巴依" : "他把我关在这里，有吃有喝，我就不走了。巴依是个坏蛋，愿胡大惩罚他。",
	    "小毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
	    "胡大" : "就是真主。又名安拉或阿拉。",
	    "真主" : "真主至大，万物非主，唯有真主。穆罕默德是真主的使者。",
       ]) );

	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
	     "阿凡提叹了口气：嗨，可惜我的驴。\n",
	}) );
	carry_object("/clone/cloth/wcloth")->wear();
	carry_object("/d/xingxiu/obj/dongbula");
}

int accept_object(object who, object ob)
{
     	if ((string)ob->query("id") != "mao lv")
		return 0;

	write("阿凡提笑得嘴都合不上了，说：多谢这位" + RANK_D->query_respect(who) + "的帮助。\n");

	if (who->query("score") < 100)
	{
		who->add("score", 5 + random(5));
		tell_object(who, HIG "你的江湖阅历提高了。"NOR"\n");
	}

	destruct(ob);
	return 1;
}

