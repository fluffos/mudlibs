#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
 set("short", MAG "阜城门" NOR);
        set("long", @LONG
 这是京城的阜城门,城门上的牌子写着三个大字－－阜城门。高耸坚固的城墙
透出一股威严。城墙上贴着几张告示（gaoshi).因为是京畿重镇，所以官兵们
戒备森严，动不动就截住行人盘问。西边是通往保定的驿道,东边是城里。
LONG
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

	set("exits", ([
 "east" :__DIR__"xchjie2",
	"west" : "/d/road/rcatolz0",
        ]));
        set("objects", ([
__DIR__"npc/xmenzg" : 1,
__DIR__"npc/bing" : 5,
        ]));
        setup();
}

string look_gaoshi()
{
  return FINGER_D->get_killer() + "\n\n\t\t九门提督\n\n\t\t    南宫灭\n";
}
