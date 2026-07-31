 inherit ROOM;
void create()
{
        set("short", "藏宝室");
        set("long", @LONG
说是藏宝室，却是空空荡荡什么都没有，几个大开的大箱子堆在角落
里，地上有几粒断了线的珍珠，似乎突然有了什么变故，主人带着所有的
珍宝离开了这里。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"mouseroom3",
                
                        ]));
        set("objects", ([
                __DIR__"npc/rat2" : 3,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
