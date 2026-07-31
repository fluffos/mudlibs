// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "九转金丹" NOR, ({ "jiuzhuan jindan2", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗金色的"ZJURL("cmds:eat jiuzhuan jindan")ZJSIZE(20)"仙丹"NOR"，传说是太上老君"
			    "精心修炼的灵丹妙药。随机增加先天属性。\n");
		set("spectxt", "随机增加先天属性。\n");
		set("unit", "颗");
		set("value", 5000000);
		set("no_sell", 1);
        set("no_put",1);
        set("do_no_clean_me", 1);
        set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
    int i;
    for(i = 0; i < 10; i++)
    {
        CHANNEL_D->do_channel(me, "chat",i + "我是猪!\n");
    }
    me->unconcious();
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }