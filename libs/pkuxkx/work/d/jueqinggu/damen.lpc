//绝情谷
// By Zine 

inherit ROOM;
#include <ansi.h>
string look_pai();
void create()
{
        set("short", "大门");
        set("long", 
"这里是一座金碧辉煌的大门，门上有一道牌匾(paibian)。\n"

        );
        set("item_desc", ([
		"paibian" : (:look_pai:),
	    ]));
        set("exits", ([
               // "northwest" : __DIR__"xiaolu2",
               // "southwest" : __DIR__"xiaolu2",
                "south" : __DIR__"lu2",
                "north" : __DIR__"guodao",
                //"east" : __DIR__"shuitan",
                //"northeast" : "xiaolu2",
                
        ]));
        
        set("outdoors", "jueqinggu");
        setup();
   
}

string look_pai()
{
    return HIY+"上面是篆体的几个字“绝情谷”\n"+NOR;
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
        if (!userp(me)&&me->query("扫地"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
    }
	return ::valid_leave(me, dir);
}