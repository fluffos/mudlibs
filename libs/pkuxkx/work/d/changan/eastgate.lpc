//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "city_level.h"
#define TITLE_LV1 "/quest/changan/title_lv1"
string look_gaoshi();

void create()
{
        set("short", HIG"春明门"NOR);
        set("long", @LONG
这里是长安正东的春明门。城墙上贴着告示(gaoshi)。
东面正是西岳华山。
LONG);
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
                "west" : __DIR__"eaststreet-3",
                "northup" : __DIR__"citywall1",
                "southup" : __DIR__"citywall2",
                "east" : __DIR__"guandaoe1",
                
        ]));
        set("objects", ([
		      __DIR__"npc/jinwu-2": 1,
          __DIR__"npc/jinwu-1": 4,
        ]));
        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
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
    if (dir=="west" && me->query_condition("cakiller") && objectp(jw))
      return notify_fail("你已被全城通缉，快去避避风头！\n");
    else
		  return ::valid_leave(me, dir);
	}
	else
	  return notify_fail("城防禁地，闲人免入！\n");
}