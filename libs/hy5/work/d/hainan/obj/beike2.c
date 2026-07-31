// beike2.c

inherit ITEM;

void create()
{
	set_name("五彩贝壳", ({ "wucai beike","beike" }) );
	set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "个");
		set("value", 1000);
		set("long", 
"这是个漂亮的五彩贝壳，应该可以卖不少钱！\n");
	}
	setup();
}
