// qiu.c 邱山风
// By River 2003.2.26
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("邱山风",({"qiu shanfeng", "qiu", "shanfeng"}));
	set("title", "长乐帮虎猛堂香主");
	set("long", "他就是长乐帮虎猛堂香主邱山风。\n");
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
	set_skill("blade",160);
	set_skill("literate",150);
	set_skill("cuff",160);
	set_skill("kunlun-shenfa", 160);
	set_skill("shenzhao-jing", 160);
	set_skill("lieyan-dao",160);
	set_skill("taizuquan", 160);
	set_skill("parry", 160);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "lieyan-dao");
	map_skill("blade", "lieyan-dao");
	map_skill("cuff", "taizuquan");
	prepare_skill("cuff","taizuquan");

	setup();
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}
