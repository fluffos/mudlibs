
inherit NPC;
#include <ansi.h>


void create()
{
	set_name("莽汉", ({ "mang han", "han"}));
	set("long", HIY"他体格也算十分魁梧，只是眼神有些呆滞、似乎总是在寻找什么。\n"NOR);
	set("long_base", HIY"他体格也算十分魁梧，只是眼神有些呆滞、似乎总是在寻找什么。\n"NOR);
	set("gender", "男性");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 5500);
	set("max_jing", 5500);
	set("eff_jingli",5400);
	set("neili", 5100);
	set("max_neili", 5100);
	set("jiali", 20);
	set("combat_exp", 58000+random(500));

	set_skill("force", 170);
	set_skill("dodge", 180);
	set_skill("unarmed", 170);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("cuff", 180);
	set("chat_chance", 3);
	set("chat_msg", ({
		"莽汉贼头贼脑地看了看周围没人，晃着脑袋流里流气地哼哼着：路边的野花，你不要采啊...不采白不采呀！\n",
			"莽汉满脸痴呆地傻笑着：花，我要花花。。。\n",
			"莽汉用上嘴唇亲了亲下嘴唇。\n",
		"莽汉看了看别人的嘴唇，吞了口唾液。\n",
		"莽汉摇摇头，叹口气道：“疯了，都疯了...”\n",
	}));
	set("inquiry", ([
		"比武招亲" : "看那小妞多俊俏，要不是我身手不成，也想上去试试……\n",
		"招亲" : "看那小妞多俊俏，要不是我身手不成，也想上去试试……\n",
	]));
	setup();
	//carry_object("/clone/armor/caoxie")->wear();
	carry_object("/clone/misc/cloth")->wear();
}
