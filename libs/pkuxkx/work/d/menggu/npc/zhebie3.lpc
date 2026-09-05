// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("哲别", ({"zhe bie", "zhe", "bie"}));
	set("title", WHT"神箭手"NOR);
	set("long", 
            HIR"他是草原上的第一神箭手哲别。\n"NOR);
	set("gender", "男性");
	set("age", 40);
    set("combat_exp", 150000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth3")->wear();
	
}
	
int pat(object me)
{
	CHANNEL_D->do_channel(this_object(), "bd", "pat "+me->query("id"), 1);
	return 1;
}
