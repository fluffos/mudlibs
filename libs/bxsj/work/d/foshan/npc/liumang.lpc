//liumang.c  流氓

inherit NPC;

void create()
{
	set_name("流氓", ({ "liu mang", "liu" }));
	set("long", "他是一个成天游手好闲的流氓，看起来一副市井无赖的样子。\n");
	set("gender", "男性");
	set("age", 19);
	set("shen", -2000);

	set("str", 22);
        set("int", 25);
        set("con", 22);
        set("dex", 21);

	set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);

        set("jingli",400);
          set("eff_jingli",400);
        set("jiali", 20);   
	set("combat_exp", 10000);

	set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("strike", 40);
        set_skill("parry", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",10);
}
