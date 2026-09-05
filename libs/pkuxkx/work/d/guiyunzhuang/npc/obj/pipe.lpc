// pipe.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"铜哨"NOR,({ "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "brass");
                set("long", "一根约两寸多长的铜哨。\n");
        }
}

void init()
{
        add_action("do_blow", "blow");
}

int do_blow(string arg)
{
    if ( arg != "pipe" ) return 0;
	if ( file_name(environment(this_player()))=="/d/guiyunzhuang/houhuayuan")
	{
		if( present("a xiang",environment(this_player()))
		&& living(present("a xiang",environment(this_player()))))
				return notify_fail("你正准备吹哨子，可是阿香瞟了你一眼，你的气又咽了回去。\n");
		else 
		{
			message_vision("$N拿起"+this_object()->name()+"吹了一下铜哨，壮了壮胆就闯了进去。\n",this_player(),environment());
			this_player()->move("/d/guiyunzhuang/taolin");
			return 1;
		}
	}
	else
	{
	    message_vision("$N拿起一个"+ this_object()->name()+"吹了一声.可是似乎没有多大作用。\n",this_player());
	    return 1;
	}
}
