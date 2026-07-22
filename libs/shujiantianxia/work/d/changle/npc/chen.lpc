// chen.c 陈冲之
// By River 2003.2.26
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("陈冲之",({"chen chongzhi", "chen", "chongzhi"}));
	set("title", "长乐帮狮威堂香主");
	set("long", "他就是长乐帮狮威堂香主陈冲之。\n");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen", -1000);
	set("str", 26);
	set("int", 29);
	set("con", 27);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 2200);
	set("eff_jingli", 2500);
	set("jiali", 80);
	set("combat_exp", 1300000); 
	set("unique", 1);

	set_skill("dodge",160);
	set_skill("force", 160);
	set_skill("literate",150);
	set_skill("cuff",160);
	set_skill("kunlun-shenfa", 160);
	set_skill("shenzhao-jing", 160);
	set_skill("taizuquan", 160);
	set_skill("parry", 160);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "taizuquan");
	map_skill("cuff", "taizuquan");
	prepare_skill("cuff","taizuquan");

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}
