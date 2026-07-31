// /d/xiangyang/obj/guanglingsan.c
// By Jpei

inherit ITEM;

void create()
{
        set_name("广陵散", ({ "guang ling san", "san", "qinpu", "pu" }) );
	set("long", "这就是著名的广陵散琴谱了。本以为自嵇康后就失传了，没想到却能在蔡邕的墓中发现。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("no_get", "那是无价之宝，对方连睡觉都揣在怀里的！\n");
                set("no_drop", "这可是无价之宝，你这么老大一个人，居然如此不识货？！\n");
		set("value", 1000000);
	        set_weight(85);
//		set("treasure", 1);
        }
        setup();
}

