// huanong.c


#include <command.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("花农", ({ "hua nong", "nong" }));
	set("nickname","老实人"); 

	set("gender", "男性");
	set("long",
		"为了解决下岗工人问题，〖武林〗巫师组特别请了这个"
		"老实人在这里当小花园的花农。\n");
	set("str", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 800000);
	set("attitude", "friendly");

	set("vendor_goods", ([
		__DIR__"obj/zhongzhi": 20,
	]));

	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"花农十分诚恳地说：微笑真是好啊，给了我这份工作。\n",
		"花农叹了口气说：这工作看起容易，做起来难，但我喜欢这个工作。\n",
	}));

	carry_object("/clone/cloth/cloth")->wear();
	set_max_encumbrance(100000000);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
