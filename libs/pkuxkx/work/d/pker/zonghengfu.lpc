//Made by goodtaste
//hongyutang.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"纵横神府"NOR);
        set("long", @LONG
经为纵，只凭我独来独往;纬作横，何妨我任意西东
据说杀手帮主楚云飞一生未败，纵横天下，率意直行，晚年开
创杀手帮，建此纵横神府，以显示自己的威名
LONG
        );
        
        set("exits", ([
                "south" : __DIR__"heyuntang",
                
                ]));
         

          set("objects", ([
         
                   __DIR__"npc/chu" : 1,
                   __DIR__"npc/dizi" : 3,
                   __DIR__"npc/puren":2,
           ]));
		set("no_task",1);
         setup();
       // replace_program(ROOM);
}


int valid_leave(object me, string dir)

{


        if(me->query_temp("right"))
          me->delete_temp("right");
	return ::valid_leave(me, dir);
}



