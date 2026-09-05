//金肃门 /d/jinyang/jinsumen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "金肃门");
        set("long", 
"这里是晋阳的西门，出了城就快到吕梁山了。往东是一条小街。城墙上贴着\n告示(gaoshi)。\n"

        );

        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	    ]));
        set("exits", ([
                
                "east" : __DIR__"weststreet",
                "north" : __DIR__"citywall19",
                "south" : __DIR__"citywall20",
                "southwest" : __DIR__"guandaow1",
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "jinyang");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n晋阳知府谕\n";
}

int valid_leave(object me,string dir)
{  
	if (dir=="southwest")
    {
        if (me->query("id")=="xun bu")
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
    if (dir=="east" && me->query_condition("killer"))
    {
        return notify_fail("你已被全城通缉，快去避避风头！\n");
    }
	return ::valid_leave(me, dir);
}