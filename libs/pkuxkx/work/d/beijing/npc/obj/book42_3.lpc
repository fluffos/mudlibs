#include <ansi.h>
inherit ITEM;
int do_tear(string arg);
void init()
{
        add_action("do_tear", "tear");
}
void create()
{
        set_name(BLU"四十二章经"NOR, ({"sishierzhang jing", "jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一本镶蓝旗的经书,封皮(binding)是蓝绸所制，镶以红绸边，显得十分精致。\n");
                set("unit", "本");
                set("value", 1000);
                set("material", "paper");
        }
        setup();
}
int do_tear(string arg)
{
	object me, ob;
	me = this_player();

        if( !arg || arg != "binding" ) return notify_fail("你要撕什么？\n");

	message_vision("$N将" + query("name") +"的封皮撕开，只见几块碎羊皮掉了下来。\n", this_player());
	ob = new(__DIR__"yangpi_3");
	ob->move(environment(me));
	destruct(this_object());
	return 1;
}
