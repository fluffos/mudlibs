// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", WHT"南水门"NOR);
        set("long", @LONG
这里是镇江府的南城门——南水门，城墙上贴着几张官府告示(gaoshi)，几个官
兵昼夜在此把守，冷酷的看着来往的每一个人。往南走便是崇山峻岭，峰峦叠翠，沿
山间小路可通往建康府。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "west" : __DIR__"tulu7",   
                "east" : __DIR__"tulu6",
                "north" : __DIR__"s",
				"south" : __DIR__"shanlus1",
]));
     set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
     set("objects", ([
		__DIR__"npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        ]));    
	set("entry_direction","south");
		set("migong","/d/zhenjiang/jilong");
		set("migong_posi","north");
		set("look_refuse_msg","鸡笼山被官府征用，此刻平民禁入。\n");
		set("enter_refuse_msg","鸡笼山被官府征用，此刻平民禁入。\n");
   setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n镇江知府谕\n";
}