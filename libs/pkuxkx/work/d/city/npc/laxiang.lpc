// baibian.c

#include <ansi.h>

inherit NPC;

void create()
{
	seteuid(getuid());
	set_name("小白菜", ({ "Slapu"}) );
	set("title", HIY"武学大宗师"NOR" 明教 "YEL"圣使"NOR);
	set("gender", "男性" );
	set("age", 175);
	set("attitude", "heroism");
	
	set("str", 21);
	set("con", 30);
	set("int", 27);
	set("dex", 23);

	set("max_qi", 600);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 30);
	set("shen_type", -1);
	set("env/wimpy", 60);

	set_temp("apply/attack",  10);
	set_temp("apply/defense", 20);

	set("combat_exp", 105097877);

	set_skill("force", 43); 
	set_skill("unarmed", 51);
	set_skill("sword", 37);
	set_skill("dodge", 59);
	set_skill("parry", 40);
	set_skill("taiji-quan", 42); 
	set_skill("taiji-jian", 41); 
	set_skill("taiji-shengong", 40); 
	set_skill("tiyunzong", 53);

	map_skill("force", "taiji-shengong");
	map_skill("unarmed","taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	map_skill("dodge", "tiyunzong");

	

	

	setup();

//      
	add_money("gold", 1);
	call_out("dest",3600);
        
}

int dest()
{
	if (this_object())
	{
		destruct(this_object());
	}
}