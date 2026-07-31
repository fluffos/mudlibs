 inherit ROOM;
void create()
{
        set("short", "老井");
        set("long", @LONG
营地西侧是一个半塌的井架，几个破水桶胡乱地倒扣在地上。向下看去，黑咕隆
咚地不见底，丢下一块石子，半晌听见啪的坠地声在井壁回响，原来已经干枯了不知
多少年。阱栏上拴着一匹没精打采的瘦马。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"banditcamp2",
                        ]));
        set("objects", ([
                __DIR__"npc/horse" : 1,
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
