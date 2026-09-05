// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
#include "checking.h"
inherit NPC;

void create()
{
	set_name("拖雷", ({"tuo lei", "tuo ", "lei"}));
	set("long", 
            HIR"他是铁木真幺子拖雷。\n"NOR);
	set("gender", "男性");
	set("age", 18);
    set("combat_exp", 250000);
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
	
int handshake(object me)
{
	command("handshake "+me->query("id"));
}

int flatter()
{
	CHANNEL_D->do_channel(this_object(), "jh", "爹爹一统大漠，功绩无人能比，应该被尊称“成吉思汗”！");
	CHANNEL_D->do_channel(this_object(), "jh", "众人(every one): 成吉思汗！成吉思汗！成吉思汗……汗……汗……汗……(回音)", -1);
	return 1;
}
