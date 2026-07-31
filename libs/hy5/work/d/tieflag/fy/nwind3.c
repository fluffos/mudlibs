 inherit ROOM;
void create()
{
        set("short", "北风大街");
        set("long", @LONG
这里显然就不如靠广场那头热闹了，两侧各有一幢小楼，楼上整日飘着白色的
水雾，骄阳下象是青烟缕缕升起。大街的西首是供风云男人们泡澡和桑拿的浸龙堂，
而东首则是当今武林第一美人天天要去，风云城里无人不晓的浣凰堂。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"nwind2",
                "north" : __DIR__"nwind4",
                "east" : __DIR__"hfeng",
                "west" : __DIR__"jlong",
        ]));
        set("objects", ([
                __DIR__"npc/fat" : 1,
                __DIR__"npc/patrol_soldier": 1,
        ]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
