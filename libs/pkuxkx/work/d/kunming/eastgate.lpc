// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "东城门");
        set("long", "这里是昆明城的东门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "east" : __DIR__"guandaoe1",
               "west" : __DIR__"eaststreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "kunming");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n昆明知府谕\n";
}

int valid_leave(object me,string dir)
{  
	if (dir=="east" && userp(me))
    {
        tell_object(me,BLINK+HIM+"东面苗岭，林中瘴气漫溢，如果没有准备，当心送命！\n"+NOR+"昆明知府谕\n");   
    }
	return ::valid_leave(me, dir);
}