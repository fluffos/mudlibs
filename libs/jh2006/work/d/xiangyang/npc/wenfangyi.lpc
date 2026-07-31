// /d/city/npc/wenfangyi

inherit NPC;
 
void create()
{
	set_name("温方义", ({ "wen fangyi", "wen" }));
	set("nickname", "温家五老");
	set("long", 
        "他就是温家五老的老二温方义。\n"
        "一个五十来岁的老者，一双眼睛透出精光。\n");
	set("gender", "男性");
	set("age", 56);
	set("attitude", "friendly");
	set("shen", -9000);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2000);
	set("max_jing", 1800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 900000);
	 

    set_skill("force", 140);
    set_skill("yijin-jing", 140);
    set_skill("dodge", 150);

    set_skill("shaolin-shenfa", 140);
    set_skill("cuff", 150);
    set_skill("wenjia-daofa", 130);
    set_skill("parry", 150);
    set_skill("blade", 120);
    set_skill("wenjia-quan", 150);
    set_skill("literate", 110);

	map_skill("force", "yijin-jing");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-quan");
  	map_skill("blade", "wenjia-daofa");
       prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	 
     
}