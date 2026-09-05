#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
	set_name(BLK"土匪"NOR, ({ "tu fei", "fei" }));
	set("long", 
		"他就是他是在黑松岭上占山为王的土匪。\n"
           );
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);
	set("combat_exp", 20000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("dodge", 60);
        set_skill("strike", 50);
	set_skill("parry", 50);
	set_skill("blade", 70);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	setup();
  	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        object ob;  
        ob=this_object();
        ::init();       
        command("kill " + this_player()->query("id"));
}

