// 总坛弟子

inherit NPC;
void create()
{
        set_name("总坛弟子", ({ "shenlong dizi","dizi" }));
	set("long", "他是一个神龙教总坛的弟子。\n");
        set("gender", "男性");
	set("title", "神龙教第三代弟子");	
        set("age", 20);       
	set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 23);
        set("combat_exp", 60000);
        set("shen", -10000);
        set("attitude", "peaceful");
	set("max_qi",500);
        set("max_jing",350);
        set("neili",500);
        set("max_neili",500);
        set("jingli",200);
        set("eff_jingli",200);
	set("jiali",20);
	set("score", 10000);

	set_skill("force", 60);
	set_skill("dodge", 60);
      set_skill("parry",60);
	set_skill("strike",60);
	set_skill("huagu-mianzhang", 80);
      set_skill("youlong-shenfa",60);
      set_skill("dulong-dafa",60);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
        map_skill("strike", "huagu-mianzhang");
        map_skill("parry","huagu-mianzhang");
      prepare_skill("strike","huagu-mianzhang");
      
      create_family("神龙教",3, "弟子");
      setup();
      carry_object(__DIR__"obj/scloth")->wear();
}
