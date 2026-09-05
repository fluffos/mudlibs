//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", WHT"广场"NOR);
        set("long", 
"张家口是南北通道，塞外皮毛集散之地，人烟稠密，市肆繁盛。\n"

        );
        
        set("exits", ([
                "west" : __DIR__"weststreet",
                "east" : __DIR__"eaststreet",
                "north" : __DIR__"northstreet",
                "south" : __DIR__"southstreet",
                
        ]));
        /*set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));*/
        set("outdoors", "saiwai");
        setup();
   
}


