// Created by hacky
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC;
#include "namedata.h"

void create()
{                    
	string name = comm_man_name();
	set_name("陌生人"+name, ({ "mosheng ren" , "ren"  }));
	switch( random(2) ){
	case 0:
		set("long",
		"你以前肯定没见过这个人，他面目陌生，说不定是外地来的游客。\n");
		set("gender", "男性");
		break;
	default:
		set("long",
		"你以前肯定没见过这个人，她面目陌生，说不定是外地来的游客。\n");
		set("gender", "女性");
		break;
	}
	set("age", 12+random(48));
	set("attitude", "peaceful");
	set("combat_exp", random((int)this_object()->query("age")*300));
	set("shen_type",1);set("score",200);set("shen_type",1);set("score",200);set("shen_type",1);set("score",200);setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: random_move :),
        }) );
		
	carry_object(__DIR__"obj/cloth")->wear();
}

