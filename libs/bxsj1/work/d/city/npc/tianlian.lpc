// penglianhu.c 彭连虎

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("彭连虎", ({ "penglian hu", "penglian" }));
	set("nickname", "千手人屠");
	set("long", 
        "他就是杀人不不眨眼的大盗千手人屠彭连虎。\n"
        "一个一脸邪气，并且十分狡猾的家伙。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 40);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2400);
	set("max_jing", 800);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("score", 100000);

    set_skill("force", 120);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 120);

    set_skill("shaolin-shenfa", 120);
    set_skill("hand", 100);
    set_skill("weituo-zhang", 130);
    set_skill("parry", 100);
    set_skill("staff", 120);
    set_skill("qianye-shou", 120);
    set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("hand", "qianye-shou");
  	map_skill("parry", "weituo-zhang");
  	map_skill("staff", "weituo-zhang");
    prepare_skill("strike", "chousui-zhang");

	 
         set("inquiry", ([
                "郭靖" : "嘿嘿, 怎麽你有他的消息吗。",
                "彭连虎" : "就是大爷我。",
                "穆颜萍" : "那可是个美人啊。",
                "沙通天" : "是我的结拜兄弟! ",
                "侯通海" : "也是我的兄弟啊！",
                "钱青健" : "你问这麽多干什麽？",
                
        ]) );
        
        setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
        add_money("gold", 8);
}