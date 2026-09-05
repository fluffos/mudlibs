// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", HIG"定波门"NOR);
        set("long", @LONG
这里是镇江府的北城门——定波门，城墙上贴着几张官府告示(gaoshi)，几个官
兵昼夜在此把守，冷酷的看着来往的每一个人。往北便可望到滚滚东流的长江，江中
沙洲蜿蜒，白鹭丛飞，江面渔舟熙攘，百舸争流，一派繁荣盛景。江面对岸便是扬州。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "west" : __DIR__"tulu12",   
                "east" : __DIR__"tulu1",
                "south" : __DIR__"n2",
                "northup" : __DIR__"beimian",
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