
// duchang2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "赌场");
	set("long", @LONG
这里是赌场的二楼，很多人在围着几张桌子高声叫嚷，煞是热闹。
    靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
        );
        set("exits", ([
                "north"          : __DIR__"eroad1", 
		"up"		 : __DIR__"duchang2",
	 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：赌(bet)：赢一两纹银，输五十文。\n";
}

