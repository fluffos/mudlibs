
// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("coor",({1900,3900,0}));
	set("short", "场院");
	set("long",
"这里好象是大户人家子弟玩乐的场院,原来建有秋千架的草地，已经成了荆棘丛生的荒草场\n"
"了。再往西是一座凉亭，亭子似乎也快要倒塌了...\n"
);

        set("exits", ([
                "east"          : __DIR__"woodboxy",
	        "west"          : __DIR__"god2" ]) );

//	set("objects", ([
//	]) );


        setup();

}


