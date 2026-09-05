// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
#include "checking.h"
inherit NPC;

void create()
{
	set_name("博尔术", ({"bo ershu","bo","ershu"}));
	set("long", 
            HIR"他就是铁木真的大将博尔术。\n"NOR);
	set("gender", "男性");
	set("age", 30);
    set("combat_exp", 150000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth4")->wear();
	
    
    call_out("check",2);
}
	
