// xiyuan.c 襄阳戏院 
// 星星lywin 2000/6/22 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "襄阳戏院");
        set("long", @LONG
这儿是襄阳最有名的大戏院，在全国各地也有很大的名气，由这个戏
院组织的戏班子常常到各地去进行表演，非常的受好评。你可以在这儿向
管事打听有关工作的事。（ask guan about job）
LONG
        );

        set("exits", ([
                "north" : "/d/xiangyang/jiedao",
        ]));
	set("objects", ([
		__DIR__"guanshi" : 1,
	])); 
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
	replace_program(ROOM);
}
