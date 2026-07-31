 inherit ROOM;
void create()
{
        set("short", "马贼营地");
        set("long", @LONG
废墟后转了几圈，面前是一块空地，空地上升了几堆篝火，烤肉的香味扑鼻
而来。几个满脸横肉的汉子懒懒散散地靠在篝火边，手里提着各式兵器。后面是
三两个帐篷，破旧不堪，旷野的风吹过，猎猎作响。
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"deserted",
                "north" : __DIR__"camp",
                "northwest": __DIR__"banditcamp2",
                        ]));
        set("objects", ([
                __DIR__"npc/bandit1" : 1,
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
