// gongzi.c 公子哥

inherit NPC;
void create()
{
        set_name("浪荡公子", ({"gong zi", "gongzi", "zi"}) );
        set("gender", "男性" );
        set("age", 20 + random(8));
        set("long", "这是一个整天游手好闲的公子哥儿。\n");
        set("shen_type", -1);
        set("attitude","heroism");

        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("env/wimpy", 50);

	set("max_qi", 1500);
	set("max_jing", 1100);
	set("neili", 2000);
	set("max_neili", 1500);
	set("jiaji", 20);
        set("combat_exp", 320000);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);

	set_skill("force", 180);
	set_skill("dodge", 185);
	set_skill("unarmed", 180);
	set_skill("sword", 100);
	set_skill("parry", 180);
	set_skill("kunlun-shenfa", 150);
	set_skill("cuff", 100);
	set_skill("wenjia-quan", 100);
	set_skill("huashan-jianfa", 100);
	set_skill("xuantian-wuji", 100);
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shnfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("cuff", "wenjia-quan");
	map_skill("parry", "wenjia-quan");
        prepare_skill("cuff", "wenjia-quan");
        setup();

        carry_object(ARMOR_D("ruanxue"))->wear();
        carry_object(ARMOR_D("changshan"))->wear();
        add_money("silver",20+random(10));
}
