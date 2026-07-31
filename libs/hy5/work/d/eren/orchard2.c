 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "果园");
        set("long", @LONG
果园里的树枝上挂满了各种果实。红的苹果象牙球一样的发光。有些树木早巳
披上晚秋灿烂的装束，那是如火如茶的颜色，果实的颜色，熟透的甜瓜的颜色，橘
子与柠檬的颜色，珍馐美馔的颜色。林中到处亮出红红的光彩，
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"orchard1",
        ]));
        set("objects", ([ 
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
