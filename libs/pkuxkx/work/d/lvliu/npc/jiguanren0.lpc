
inherit NPC;

#include <ansi.h>

void create()
{
        set_name("零号机关人"NOR, ({ "jiguan ren", "ren", "robot", }));
		set("long", "一个绿柳山庄的机关人，主要用于测试技能，制作精巧，如同真人一般。\n"NOR);
        set("race", "机关人");
		set("age", 100);
        set("max_qi", 1000000);
        set("max_jing", 1000000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 0);
        set("combat_exp", 1000000);
		set("no_get", 1);		
        setup();
}


void unconcious()
{
    die();
}

void die()
{
	object ob = this_object();
	message_vision("$N头顶上的一个圆环转动了几圈，又恢复如初了。\n", ob);
    set("max_qi", 1000000);
    set("max_jing", 1000000);
    set("eff_qi", 1000000);
    set("eff_jing", 1000000);
    set("qi", 1000000);
    set("jing", 1000000);
    set("neili", 1000);
	set("max_neili", 1000);
	set("jingli", 1000);
	set("max_jingli", 1000);
	clear_condition();
}
