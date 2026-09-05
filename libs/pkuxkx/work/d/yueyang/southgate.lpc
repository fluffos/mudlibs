// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南门");
        set("long", "这里是岳阳城的南门，城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "south" : __DIR__"guandaos1",
               "north" : __DIR__"southstreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "yueyang");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n岳阳知府谕\n";
}

int valid_leave(object me,string dir)
{  
	if (dir=="south" && userp(me))
    {
        tell_object(me,HIM+"南面苗岭，林中瘴气漫溢，如果没有准备，当心送命！\n"+NOR+"岳阳知府谕\n");   
    }
	return ::valid_leave(me, dir);
}