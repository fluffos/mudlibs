//hubian1.c
//by hehe
//2003.3.20

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "太湖边");
    set("long", @LONG
你走到湖边,前面豁然一个大湖泊(hu),水面光滑如镜,湖上停着艘小船(boat)，
船头坐着一位钓鱼老翁。湖边则杏花夹径,绿柳倒垂。暖洋洋的春风吹在身上,当真
是熏熏欲醉。
LONG
    );

    set("exits", ([
        "southeast" : __DIR__"qzroad1",
        "northwest" : __DIR__"taihu2"
    ]));
	set("objects",([
		__DIR__"npc/th_yufu" : 1,
        ]));
    set("couldfish",1);
	  set("item_desc", ([
		  "hu" :
"    湖面宽阔无比，一眼无边。远远望去，湖中种满了红菱白藕，
微风吹过，绿叶轻摇，煞是动人。藕菱之间，是一条条曲曲的水路，
不知道通向何处。
",
      "boat" : "这是钓鱼老翁的钓鱼船，在湖中慢慢漂流着。\n"
                     ]));

    set("outdoors", "quanzhou");
    setup();
}