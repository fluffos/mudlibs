// Room: /d/kunlun/pqf.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "兵器房");
        set("long", @LONG
这里是昆仑派的兵器房，四周放这几个兵器架，上面是昆仑派各弟子平时
练剑用的竹剑。
LONG
        );

        set("objects", ([ 
        "/d/village/obj/zhujian" : 4,
]));

        set("exits", ([
        "west" : __DIR__"bwc",
]));

        setup();
        replace_program(ROOM);
}
