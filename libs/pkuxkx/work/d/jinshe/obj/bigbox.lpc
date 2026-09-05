// bigbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("大铁盒", ({"big box", "box"}));
        set("long",
"这盒子高约一尺，然而入手轻飘飘地，似乎盒里并没藏着甚么
东西。打开盒盖，那盒子竟浅得出奇，离底仅只一寸，一只尺
来高的盒子，怎地盒里却这般浅？料得必有夹层。\n");
        set("unit", "只");
        set("open_count", 1);
        set_weight( 2000);
        set("no_get", 1);
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        if ( arg=="box" || arg=="big box" )
        {
        	if (query("open_count") > 0)
        	{
                add("open_count", -1);
                message_vision(HIR "$N伸手打开铁盒，只见眼前黑影骤起，原来盒里是毒箭！\n" NOR, this_player());
                this_player()->receive_damage("qi", 0, "被大铁盒里的毒箭射中");
                this_player()->die();
                return 1;
        	}
        	else
        	{
                write("铁盒已经被别人打开过了。\n");
                return 1;
        	}
	}
	else 
		return notify_fail("你要打开什么？\n");
}

