// Room: /city/kedian.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
                set("short", "贵妃浴场");
        set("long", @LONG
这里是扬州最著名的贵妃浴场的入口，听说在这里洗澡可以恢复人
的体力和精力，因此往来的江湖人物络绎不绝，你来到门口，看见
有位招待正在欢迎你的到来，在入口处立了块价目表(sign)。
LONG
     );

	set("no_fight", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
          "sign" : "每人每次收费为白银三十两。\n"
	]));

	set("objects", ([
                "/d/xinfang/npc/bathgirl" : 1,
	]));

	set("exits", ([
            "east" : __DIR__"bieshuqu",
              "enter" : __DIR__"bathroad",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "enter" )
          return notify_fail("招待拦住你说：对不起，我们这里是要收费的，请先交钱！\n");
         if (this_object()->query("last_guest") == me->query("id") && dir=="enter")
            return notify_fail("招待拦住你说：咦？你不是刚进去过么？老洗澡对身体没好处！\n");
        if ( dir == "enter" )
        this_object()->set("last_guest",me->query("id"));
	return ::valid_leave(me, dir);
}
