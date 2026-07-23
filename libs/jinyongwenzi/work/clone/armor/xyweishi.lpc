// xyweishi

inherit NPC;

void create()
{
	set_name("位士", ({ "wei shi", "wei", "shi" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 30);
	set("dex", 30);
	set("long", "骁勇营负责皇宫的警卫，因此大部分都是正黄旗里精挑细选出来的。\n"
                     "各个身强力壮，一身武艺，眉宇之间显漏着傲气。\n");
	set("combat_exp", 750000);
	set("shen", 1000);
	set("attitude", "peaceful");

	set_skill("unarmed", 140);
	set_skill("force", 140);
	set_skill("sword", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 500);

	set("neili", 1000);
        set("max_qi", 1200); 
        set("max_jing", 800);
        
	set("max_neili",1000);
	set("jiali", 100);
//         create_family("骁勇营","位士");
         set("inquiry", ([
                "rumors" : "当今天子治国有道，四海升平，老百姓都很知足啊！",
                "name" : "大爷我就是骁勇营的位士，嘿嘿。",
        ]) );

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/armor/armor")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
}
