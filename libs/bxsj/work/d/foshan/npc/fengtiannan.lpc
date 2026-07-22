// fengtiannan.c

inherit NPC;

void create()
{
        set_name("凤天南", ({ "feng tiannan", "feng" }));
        set("long", "这人正是五虎门掌门人南霸天凤天南。
只见他上唇留着两撇花白小髭，约莫五十来岁年纪，右腕戴一只汉玉镯，
左手拿着一个翡翠鼻烟壶，俨然是个养尊处优的大乡绅模样，实不似个
坐地分赃的武林恶霸，只是脚步凝稳，双目有威，多半武功高强。
\n");
        set("gender", "男性" );
	set("attitude", "peaceful");
        set("age", 55);
        set("no_get", "凤天南对你而言太重了。\n");
        set("unique", 1);
	set("shen", -10000);

	set("str", 30);
        set("int", 20);
        set("con", 10);
        set("dex", 20);

	set("max_qi",2500);
        set("max_jing",2500);
        set("neili",3500);
        set("max_neili",3500);

        set("jingli",2200);
        set("eff_jingli",2200);
        set("jiali",100);   
	set("combat_exp", 800000);
       
       set_skill("staff", 160);
       set_skill("cuff", 160);
       set_skill("force",160);
       set_skill("dodge",160);
       set_skill("parry",160);
       set_skill("wushang-dali",180);
       set_skill("qingmang-jian", 180);
      
       map_skill("staff", "wushang-dali");
       map_skill("parry", "wushang-dali");
       map_skill("dodge", "qingmang-jian");

       setup();
       carry_object(ARMOR_D("cloth"))->wear();
       carry_object(BINGQI_D("gangzhang"))->wield();
       carry_object("/d/foshan/obj/yaoshi");
}

void init()
{	
	object ob; 
	ob = this_player();
	::init();
	if( interactive(ob)){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);		
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
          this_object()->kill_ob(ob);        
}
