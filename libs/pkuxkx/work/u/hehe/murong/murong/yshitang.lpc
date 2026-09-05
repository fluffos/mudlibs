//yshitang.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

string* names=({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
        }); 

void create()
{
    set("short", "膳房");
    set("long", @LONG
这里提供一般的饮食，弟子们练武累了就到这里吃点东西，
补充体力。
LONG
    );

    set("exits", ([
		"east" : __DIR__"ylianwu1",
    ]));

    set("objects",([
		"/d/shaolin/obj/qingshui-hulu":2,
        names[random(sizeof(names))]:1,
        names[random(sizeof(names))]:1,
	]));

    set("outdoors", "murong");
    setup();
	replace_program(ROOM);

}
