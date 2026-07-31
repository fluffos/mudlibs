inherit ITEM;

void create()
{
	set_name("钓杆", ({ "diaoyu gan" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一把钓杆,你可以往上装(zhuang)鱼饵。\n");
                set("yuer",1);
		set("unit", "把");
		set("value", 100);
	}
}
void init()
{
   add_action("do_open","zhuang");
}
int do_open(string arg)
{
    object me=this_player(),ob;
ob=this_object();
        if( ob->query("yuer"))
                        return notify_fail("不是已经装好了吗！\n");

        if( me->is_busy() )
                        return notify_fail("你正忙着呢！\n");

        if (me->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");

    tell_object(me,"你从地上挖了一点蚯蚓，装在鱼杆上。\n");
me->start_busy(8);
ob->set("yuer",1);
        return 1;
}