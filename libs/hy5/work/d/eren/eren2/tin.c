#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", WHT"锡屋"NOR);
        set("long", @LONG
这间灰白色的屋子里，竟是五光十色，琳琅满目，骤然望去，又仿佛
是另一宝藏。仔细一看，才发觉这“宝藏”不过是许许多多颜色不同、大小
各异的小瓶子，每一个瓶子的形式都诡异得很。
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_t" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
