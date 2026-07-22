//pingtai.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "平台");
	set("long", @LONG
这里是大雄宝殿前的一处平台，乃是全寺的中心点，寺中的重大活动多
在此举行。东面是紧那罗王殿，西面是六祖殿。
LONG
	);

	set("exits", ([
		"north" : __DIR__"daxiong",
                "east" : __DIR__"jnlwang",
                "west" : __DIR__"liuzu",
                "southdown" : __DIR__"dxshijie",
        ]));
        
        set("objects",([
        CLASS_D("shaolin") + "/hui-xiu" : 1,
        ]));

        set("valid_startroom",1);
        set("outdoors", "shaolin");
        "/clone/board/bonze_b"->foo();
	set("coor/x",50);
  set("coor/y",290);
   set("coor/z",120);
   setup();
}



