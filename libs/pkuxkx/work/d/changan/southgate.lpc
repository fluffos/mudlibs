//明德门 /d/jinyang/mingdemen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"
#define TITLE_LV1 "/quest/changan/title_lv1"
string look_gaoshi();

void create()
{
        set("short", HIW"明德门"NOR );
        set("long", @LONG
这里是长安正南的明德门。城墙上贴着告示(gaoshi)。
南面正是终南山。
LONG        );
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
                "north" : __DIR__"southstreet3",
                "westup" : __DIR__"citywall8",
                "eastup" : __DIR__"citywall6",
                "south" : __DIR__"guandaos1",
                
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-2": 1,
		      __DIR__"npc/jinwu-3": 1,
          __DIR__"npc/jinwu-1": 4,
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        set("outdoors", "changan");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer_ext("cakiller") + "\n\n"+TITLE_LV1->show_quest()+"\n长安知府谕\n";
}

int valid_leave(object me,string dir)
{
  object jw; 
  
	jw=present("jin wu", environment(me));
	
	if ( check_obj_enter(me, dir) )
	{
    if (dir=="north" && me->query_condition("cakiller") && objectp(jw))
      return notify_fail("你已被全城通缉，快去避避风头！\n");
    else
		  return ::valid_leave(me, dir);
	}
	else
	  return notify_fail("城防禁地，闲人免入！\n");
}