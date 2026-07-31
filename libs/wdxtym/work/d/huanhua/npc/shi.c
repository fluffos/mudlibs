
inherit NPC;
inherit F_MASTER;
void create()
{
	int jibie;
	jibie = 100;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("浣花剑派第四代弟子", ({ "dizi", "dizi" }));
	set("long", 
                "一名普普通通的浣花剑派弟子\n"
		"他好像二十岁了！\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 21);
	set("int", 22);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 280);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 20000);
	set_skill("force", 45);
	set_skill("dodge", 45);
	set_skill("unarmed", 40);
	set_skill("parry",50);
	set_skill("sword",50);


	setup();
carry_object("/clone/cloth/cloth")->wear();
}
