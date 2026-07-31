 inherit ROOM;
void create()
{
        object          con, item; 
        set("short", "石屋");
        set("long", @LONG
曲折蜿蜒的小路尽头，是一栋形式古老的石屋，里面的陈设也同
样古朴，甚至带着种阴森森的感觉。正面靠墙是一个黄幔低垂的神龛，
其他什么东西都没有。
LONG
        );
        set("exits", ([
                "south" : __DIR__"groad6",
        ]));
        set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/yexue" : 1,
        ]));
        set("coor/x",-1100);
        set("coor/y",-90);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}     
