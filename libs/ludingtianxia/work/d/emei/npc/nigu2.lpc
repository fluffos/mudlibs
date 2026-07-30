// nigu2.c

inherit NPC;

void create()
{
	set_name("尼姑",({ "nigu" }) );
        set("gender", "女性" ); 
        set("class","bonze");
        set("age", 20);
        set("long", "这是个已出家的尼姑，看上去就是会武功的样子。\n");
        set("str", 18);
        set("dex", 20);
        set("con", 20);
        set("int", 17);
	set("shen_type", 1);         
        set("max_qi",300);
        set("qi",300);     
        set("combat_exp", 2000);     
        set_skill("unarmed",30);
        set_skill("dodge",30);  
        set("attitude", "peaceful");
        create_family("峨嵋派",7,"弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

