 inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
这儿已不能说是道路，只是一条又湿又滑的地道，洞顶很低，需弯腰
才能通过。两侧有许多岩洞，黑咕隆咚地不知深浅，没有一盏灯，没有一
点声响，脚下悉悉簌簌不断有小动物窜过，偶尔踩到，便是吱的一声尖叫。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad2",
                "northwest" : __DIR__"jailroad4",
                "west" : __DIR__"guardroom",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
