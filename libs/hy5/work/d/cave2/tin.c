 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "锡屋");
        set("long", @LONG
这间灰白色的屋子里，竟是五光十色，琳琅满目，骤然望去，又仿
佛是另一宝藏。仔细一看，才发觉这“宝藏”不过是许许多多颜色不
同、大小各异的小瓶子，每一个瓶子的形式都诡异得很。
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
