// herbalist.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("许灵仁", ({"xu lingren","seller"}));
	set("title","药铺掌柜");
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 70);
	set_skill("literate", 70);
	
	set("combat_exp",10000);
     	set("age", 44);
	set("long",
		"药铺掌柜的是位中年汉子，看起来有四五十岁，他\n"
		"红光满面，精神焕发，可见对自己的身体保养的很\n"
		"好，你可以用 list 问他店里有哪些药。\n");
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));

	set("inquiry", ([
		"治疗": "这里有各种药卖，你只管买些回去吃了，包你很快就好！\n",
		"疗伤": "这里有各种药卖，你只管买些回去吃了，包你很快就好！\n",
		"看病": "这里有各种药卖，你只管买些回去吃了，包你很快就好！\n",
	]) );


	setup();
	carry_object(__DIR__"obj/silk-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


