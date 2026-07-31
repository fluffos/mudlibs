// wuchou-5.c 五丑
// by iceland

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("五丑", ({"wu chou","wuchou","chou","wu"}));
	set("long",
"他是藏边五丑中的老五，功夫不高，坏事做了不少。\n"
"他是大轮寺达尔巴的弟子。\n"
	);

        set("title", HIY "大轮寺第十四代弟子" NOR);
	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "huanxi");

	set("age", 26);
	set("shen_type", -1);
	set("str", 20);
	set("int", 15);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("eff_jing", 200);
	set("max_jing",200);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);
	set("combat_exp", 10000);
	set("score", 4000);
	set("unique", 1);

	set_skill("force", 25);
	set_skill("longxiang-boruo", 25);
	set_skill("dodge", 25);
	set_skill("yuxue-dunxing", 25);
	set_skill("staff", 25);
	set_skill("wushang-dali", 25);
	set_skill("parry", 25);
	set_skill("huanxi-chan", 25);
	set_skill("literate", 20);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("staff", "wushang-dali");
	map_skill("parry", "wushang-dali");

	create_family("大轮寺", 14, "弟子");
        set("chat_chance", 2);
        set("chat_msg", ({
"五丑兴奋的道：“我听大哥的，还等什么，我们快去吧。”\n",
        }) );

	setup();

        carry_object(ARMOR_D("pijia"))->wear();
        carry_object(BINGQI_D("jingangzuan"))->wield();

        add_money("silver",10); 
}