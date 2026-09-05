#include <ansi.h>
inherit ITEM;
void create()
{

        set_name(HIY"手表"NOR, ({ "shou biao", "biao", "watch" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        HIG"这是一块特别特别牛逼的手表。\n" );
                set("unit","块");
                set("value",100000);
        }
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me;
	      int time = time();
        tell_object(this_player(),HIG"现在时间是" + ctime(time) + "（" + time + "）\n"NOR);
        return 1;
}

