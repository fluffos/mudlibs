// lilishi.c 李力世

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("李力世", ({ "li lishi", "li" }));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个身材矮小，满连胡须的中年人，身上的\n"+
"衣服又脏又破，脸上满是皱纹，看上去饱经风霜。\n");
	set("combat_exp", 85000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("hand", 50);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("yunlong-shou", 60);
	set_skill("wuhu-duanmendao", 90);
	set_skill("yunlong-shenfa", 60);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("dodge", "yunlong-shenfa");

	prepare_skill("hand", "yunlong-shou");

	set("neili", 150);
	set("max_neili", 150);
	set("jiali", 10);

	create_family("天地会", 4, "弟子");

	set("chat_chance", 2);
	set("chat_msg", ({
        "李力世突然说：初进洪门结义兄，对天明誓表真心。\n",
	}));
        set("inquiry", ([
		"陈近南" :  "\n为人不识陈近南，便称英雄也枉然。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
                "反清复明" : "去棺材店和天桥仔细瞧瞧吧！\n",
                "暗号" : "敲三下！\n",
                "切口" : "敲三下！\n",

       ]) );
	setup();
	carry_object("/d/beijing/npc/obj/tudao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}
