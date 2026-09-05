// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

string look_gaoshi();
void create()
{
        set("short", CYN"青阳门"NOR);
        set("long", @LONG
这里是镇江府的东城门——青阳门，城墙上贴着几张官府告示(gaoshi)，几个官
兵昼夜在此把守，冷酷的看着来往的每一个人。往东可眺望到江中焦山，再往东便是
苏州。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "north" : __DIR__"tulu3",   
                "south" : __DIR__"tulu4",
                "west" : __DIR__"e2",
                "east" : __DIR__"tulue1",
]));
     set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
     set("objects", ([
		"/d/city/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        ]));      
   setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n镇江知府谕\n";
}
int valid_leave(object me,string dir)
{  
	if (dir=="east")
    {
        if (!userp(me)&&me->query("sinan")=="yes")
        {
            return notify_fail("");
        }
        
    }
    return ::valid_leave(me, dir);
}