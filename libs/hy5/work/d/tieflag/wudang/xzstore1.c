 inherit ROOM;
void create()
{
        set("short", "农具店");
        set("long", @LONG
小小的一个农具店，屋里摆著各式各样的农具。左面墙上挂著几
把镰刀，右边墙角放著几把钉钯。中间一个大火炉，炉火正旺，一位
驼背老人望著炉火呆呆的出神。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"xzroad2",
        ]));
        set("objects", ([
                __DIR__"npc/seller1" : 1,
        ]) );
        set("coor/x",90);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
replace_program(ROOM); 
}    
