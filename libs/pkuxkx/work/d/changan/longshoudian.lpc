
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "龙首殿");
        set("long", @LONG
这是国师居住的宫殿龙首殿，宫殿南面就是碧波荡漾的龙首池，
渠水自长安城东南角的浐水向北蜿蜒流入龙首池，池水向北绕过龙
首山注入大明宫中的太液池。
LONG        );
        
        set("exits", ([
                "north" : __DIR__"dongneiyuan"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}