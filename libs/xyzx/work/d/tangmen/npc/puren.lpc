inherit NPC;
string ask_me(int i);
void create()
{
	set_name("仆人", ({ "pu ren","ren"}) );
	set("gender", "男性" );
	set("age", 21);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 1100);
	set("max_jing", 1100);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 10);
	set("shen",300);
	set("combat_exp", 8000);
	set("score", 1000);
        set_skill("force", 60);
        set_skill("biyun-xinfa", 60);
        set_skill("dodge", 70);
        set_skill("qiulinshiye", 50);
        set_skill("strike", 60);
        set_skill("biye-wu", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("wuzhan-mei", 40);
        

        map_skill("force", "biyun-xinfa");
        map_skill("dodge", "qiulinshiye");
        map_skill("strike", "biye-wu");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");
        set("class", "tangmen");
        setup();
        carry_object("/d/tangmen/obj/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
