//Npc from japan
//China:99.11.10

inherit NPC;

void create()
{
        set_name("城卫", ({ "cheng wei", "bing", "wei" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long",
                   "一名正在来回巡视的守城卫士。\n");
     set("title","神户城");
        set("mingwang", 1);
        set("combat_exp", 10000);
	set_skill("blade",60);
	set_skill("parry",60);
	set_skill("unarmed",60);
        set_skill("dodge",60);
        set("max_qi",600);
        set("qi",600);
        set("str", 30);
        set("cor", 20);
        set("con", 2);
        set("int", 2);
        set("attitude", "peaceful");
        setup();
       carry_object("/clone/weapon/tiejia")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver",20);
}
