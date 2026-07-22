// /d/xiangyang/obj/ouxiepu.c
// By Jpei

inherit ITEM;

void create()
{
        set_name("呕血谱", ({ "ou xie pu", "go chart", "chart", "qipu", "pu" }) );
	set("long", "这是前人笔记中曾提到过的刘仲甫和骊山仙姥的对局，据说刘仲甫为此而呕血数升，本以为只是传说，没想到竟真有棋谱流传下来。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("no_get", "那是无价之宝，对方连睡觉都揣在怀里的！\n");
                set("no_drop", "这可是无价之宝，你这么老大一个人，居然如此不识货？！\n");
		set("value", 1000000);
	        set_weight(12);
//		set("treasure", 1);
        }
        setup();
}

