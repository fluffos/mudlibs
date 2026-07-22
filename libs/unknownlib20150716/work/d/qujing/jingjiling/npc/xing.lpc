inherit NPC;

void create()
{
        set_name("杏仙", ({"xing xian", "xian"}));
        set("long",
"她青姿装翡翠，丹脸赛胭脂，星眼光还彩，蛾眉秀又齐。\n");
        set("age", 20);
	set("attitude", "friendly");
        set("gender", "女性");
	set("class", "yaomo");
	set("nickname", "天台妲姬");
	set_level(90);

	set("eff_dx", -150000);
        set("nkgain", 400);

        set("force_factor", 40);
        set("mana_factor", 30);

        set_skill("unarmed",900);
        set_skill("force",900);
        set_skill("dodge",900);
	set_skill("sword",900);
	set_skill("parry",900);
	set_skill("snowsword",900);
	set_skill("moondance",900);
	set_skill("baihua-zhang",900);
	set_skill("spells",900);
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	map_skill("unarmed", "baihua-zhang");
        setup();

	carry_object("/d/qujing/jingjiling/obj/xingzhi")->wield();
	carry_object("/d/qujing/jingjiling/obj/armor")->wear();
	carry_object("/d/obj/cloth/pinkskirt")->wear();
}

void die()
{
	message_vision("$N身子一瘫，化作一棵杏树。\n",this_object());
	destruct(this_object());
}