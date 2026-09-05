// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", HIC"登云门"NOR);
        set("long", @LONG
这里是镇江府的东城门——登云门，城墙上贴着几张官府告示(gaoshi)，几个官
兵昼夜在此把守，冷酷的看着来往的每一个人。往前便是镇江府的西津渡，远处金山
寺隐约可见。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "north" : __DIR__"tulu10",   
                "south" : __DIR__"tulu9",
                "east" : __DIR__"w2",
                "west" : __DIR__"tuluw1",
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
	if (dir=="west")
    {
        if (!userp(me)&&me->query("sinan")=="yes")
        {
            return notify_fail("");
        }
        
    }
    return ::valid_leave(me, dir);
}