 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "白云山庄");
        set("long", @LONG
袁家本是这里的首户，提起袁家的白云山庄来，在这周围八百里的人有谁不知道
的呢？更何况今天不同寻常，是袁家大少爷袁青枫与万马堂千金马芳铃结亲的大喜之
日。门前车水马龙，都是前来贺喜的人群。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"yuanvillage2",
                "south": __DIR__"road1e",
        ]));
        set("objects", ([
                
        ]) );
set("coor/x",-1090);
        set("coor/y",180);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
