// yunjiyuan.c 云集园

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "云集园");
        set("long", @LONG
这里是云集园，又名小蓬莱，园中亭台轩榭，假山错落，鸟语花香，
十分幽静。全真七子常在这品酒论剑，也不时指点门下第子。往北是八
卦亭，往南是内园。
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
                "northwest" : __DIR__"baguating",
                "east" : __DIR__"xiaolu3",
                "southeast" : __DIR__"neiyuan",
        ]));
        
        
        setup();
        
}
int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "southeast")
        {
                if( mapp(fam = me->query("family")) 
                &&  fam["family_name"] == "全真教" 
                &&  fam["generation"] == 3  ) 
                        return ::valid_leave(me, dir);
                
                if( me->query("guilty") == 0 
                &&  !wizardp(me) )
                {
                        return notify_fail("你资格不够，不能进内园。\n");
                }
        }
        return ::valid_leave(me, dir);
}

