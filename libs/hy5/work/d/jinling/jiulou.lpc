//jinling  jiulou.c
inherit ROOM;

void create()
{
        set("short", "酒楼");
        set("long", @LONG
这里是金陵最大的一坐酒楼了，酒楼坐落在秦淮河岸，两岸迤俪的风光
尽收眼底。和友人傍窗而坐,要三两小菜，清酒一壶，评江湖韵事，论天下
英雄，真是快意非凡。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"dongjie1",

]));
        set("objects", ([
		__DIR__"npc/waiter" : 1,
              __DIR__"npc/obj/songbing" : 1,
              __DIR__"npc/rascal" : 1,
]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}