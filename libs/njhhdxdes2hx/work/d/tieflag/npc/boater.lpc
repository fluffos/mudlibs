// boater.c

inherit NPC;

void create()
{
    set_name("老婆子",({"old boater","boater"}));
    set("long","她面容被岁月侵蚀，风雨吹打，划出了千百条皱纹，显得那么衰老
但一双眼睛，却仍亮如闪电，似是只要一眼瞧过去，任何人的秘密，却再也休想瞒过她。\n");
    set("gender","女性");
    set("age",62);
    set("no_arrest",1);
    set("int",22);
    set("cor",20);
    set("per",10);
    set("con",20);
    set("cps",20);
    set("agi",20);
    set("gin",1000);
    set("max_gin",1000);
    set("eff_gin",1000);
    set("max_sen",1000);    
    set("sen",1000);
    set("eff_sen",1000);
    set("combat_exp",111110);  
    set_skill("force",100);
    set_skill("nine-moon-force",150);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",20);
    map_skill("force","nine-moon-force");
    set("attitude", "friendly");
	set("chat_chance",2);
	set("chat_msg",({
		"老婆子咿呀咿呀摇着橹。\n",
    }) );
    setup();
    carry_object("obj/cloth")->wear(); 
    add_money("silver",30);
}
