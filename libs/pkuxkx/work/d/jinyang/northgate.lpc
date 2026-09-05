//怀德门 /d/jinyang/northgate
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "怀德门");
        set("long",  "这里是晋阳的北门怀德门，往北是著名的雁门关。城墙上贴着告示(gaoshi)。\n"

        );
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	    ]));
        set("exits", ([
                
               
                "south" : __DIR__"northstreet",
                "west" : __DIR__"citywall11",
                "east" : __DIR__"citywall9",
                "north" : __DIR__"guandaon1",
                
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
	if (dir=="north")
    {
        if (me->query("id")=="xun bu")
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
    if (dir=="south" && me->query_condition("killer"))
    {
        return notify_fail("你已被全城通缉，快去避避风头！\n");
    }
	return ::valid_leave(me, dir);
}