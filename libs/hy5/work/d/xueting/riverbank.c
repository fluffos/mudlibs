// Room: /d/xueting/riverbank.c
inherit ROOM;
void create()
{
        set("short", "河边空地");
        set("long", @LONG
这里是河边的一处空地，湍急的河流从你的北边往东南边流去，
离这里的河岸往北一丈多远的地方可以看见一个水车，南边则是一
间破旧的大宅院，墙壁上一个大缺口足足可以让人通过。
LONG
        );
        
        set("outdoors", "xueting");
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"ruin2",
]));
        set("objects", ([

                __DIR__"npc/girl" : 1 ])
         );
        setup();
        
        replace_program(ROOM);
}
