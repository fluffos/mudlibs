// wu-santong.c 武三通
// by shang 97/6

inherit NPC;

void create()
{
        set_name("武三通", ({ "wu santong", "wu" }) );
	set("gender", "男性" );
        set("age", 45);
	set("long", "这人满头乱发，胡须也是蓬蓬松松如刺猬一般,\n" "须发油光乌黑，照说年纪不大，可是满脸皱纹深陷，却似七八十岁老翁，\n" "身穿蓝布直缀，颈中挂著个婴儿所用的锦缎围涎，围涎上绣著幅花猫扑蝶图，已然陈旧破烂。\n");
	set("attitude", "friendly");
        set("str", 30);
        set("dex", 24);
        set("con", 30);
        set("int", 20);
        set("shen_type", 1);

        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 100);
        set_skill("yiyang-zhi", 130);
        set_skill("finger", 130);
        set_skill("qiantian-yiyang", 130);
        set_skill("tianlong-xiang", 130);

        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("force", "qiantian-yiyang");
        map_skill("finger","yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");

        set("jiali", 60);

        set("combat_exp", 500000);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("eff_jingli", 1500);

        set("inquiry", ([
		"何沅君" : "阿沅，你连义父也不认了？",
		"陆展元" : "死得好，死得好，只可惜我不能亲手取他狗命。",
		"武敦儒" : "他是我大儿子。",
		"武修文" : "他是我二儿子。",
		"武三娘" : "问我老婆干什么？",
	]));
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
