// D:\xkx\d\liuxiu-shanzhuang\chemahang.c车马行
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_gu();

void create()
{
    set("short", "车马行");
    set("long", "这里是一家马车行，挂着一个招牌"+YEL"(paizi)"NOR+"，店里的马车停得满满当当的。\n");

    set("outdoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "paizi":"竭诚为新玩家提供方便。\n你可以雇车"+HBBLU"(gu或hire)"NOR+"去扬州。\n",
        ]));

    set("exits", ([
        "north" : __DIR__"xingzilin",
        ])
     );

    setup();
}

void init()
{
	add_action("show_quest", "quest");
    add_action("do_gu","gu");
    add_action("do_gu","hire");    
}

int do_gu()
{
    object who,mache,*inv;
    who=this_player();
    inv=all_inventory(who);
	for (int i=0;i<sizeof(inv);i++)
	if (userp(inv[i]))
	{
		tell_object(who,"你不能带人离开这里。\n");
		return 1;
	}
    if (1==check_questindex(who,"到南面的车马行坐马车去扬州"))
    {
        if (!objectp(mache=who->query_temp("newbie/mache_room")))
        {
            mache=new(__DIR__"mache");
            if (mache) who->set_temp("newbie/xingzilin_room",mache);
            who->move(mache);
        }
        else
        {
            who->move(mache);
        }
        message_vision("$N走上了一辆马车。\n",who);
    }
    else
    {
        tell_object(who,"你还不能离开这里。\n");
    }
    
    return 1;    
}

int valid_leave(object who,string dir)
{
   /* if (("north"==dir) && (1==check_questindex(who,"到南面的车马行坐马车去扬州")))
    {
        return notify_fail("你去意已决，就不必再回去了吧。\n");
    }*/

    return ::valid_leave(who,dir);
}

