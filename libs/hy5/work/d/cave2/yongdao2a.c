 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "小石洞");
        set("long",  @LONG
说是石洞，其实只是石壁上一块凹进的地方，洞里黑咕隆咚地伸手不
见五指。顶壁上不停地有水珠渗出，滴在颈中透心地凉。脚下踩到几块硬
硬的东西，顺着摸下去，竟似是一具骷颅，偶尔会有几只蝙蝠扑闪着翅膀
飞过，漆黑，压抑，使人忍不住地想大声呼叫。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"yongdao2",
        ]));
        set("objects", ([
                __DIR__"obj/woodbarrel" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
