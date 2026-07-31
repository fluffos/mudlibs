// nigu1.c

inherit NPC;

void create()
{
	set_name("尼姑",({ "nigu" }) );
        set("gender", "女性" ); 
        set("class","bonze");
        set("age", 20);
        set("long", "这是个已出家的但还没有入门的尼姑。\n");
        set("str", 17);
        set("dex", 19);
        set("con", 20);
        set("int", 17);
	set("shen_type", 1);         
        set("max_qi",300);
        set("qi",300);             
        set("combat_exp", 800);     
        set_skill("unarmed",12);
        set_skill("dodge",12);
        set("attitude", "peaceful");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

