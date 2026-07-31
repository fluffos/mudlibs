#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"机会丸"NOR, ({ "jihuiwan" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 88);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_beg", 1);
            set("no_pawn", 1);
            set("value", 88);
            set("treasure",1);
            set("unit", "颗");
            set("material", "paper");
            set("long", "神珠之一。作用就是后悔药！！\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");
if (random(8)==1)
{
me->delete("szj/failed");
message_vision(HIG"$N再次获得破解神照经的机会！\n"NOR, this_player());
}
else if (random(8)==2)
{
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N再次获得解九阴上册的机会！\n"NOR, this_player());
}
else if (random(8)==3)
{
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N再次获得解九阴下册的机会！\n"NOR, this_player());
}
else if (random(8)==4)
{
me->delete("zhou/jieyi");
me->delete("zhou/fail");
me->delete("zhou/failed");
message_vision(HIG"$N再次获得解双手互捕的机会！\n"NOR, this_player());
}
else if (random(8)==5)
{
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N再次获得解九阴古墓的机会！\n"NOR, this_player());
        message_vision(HIG "$N吃把珠吃了下去，只觉得全身舒服了不少!\n" NOR, me);
}	
else 
{
me->set("betrayer",0);
message_vision(HIG"$N的叛师门数清零！\n"NOR, this_player());
}
	destruct(this_object());
	return 1;
}