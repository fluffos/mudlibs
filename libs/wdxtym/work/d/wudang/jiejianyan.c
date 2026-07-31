//Room: jiejianyan.c 解剑岩
//Date: Sep 22 1997

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","解剑岩");
      set("long",@LONG
这是武林中极负盛名的武当解剑岩，岩下解剑池水明澈照人。武林
人士经此都自觉解剑，以示对武当派的尊敬。千百年来，概无例外。
LONG);
      set("objects", ([
	   CLASS_D("wudang") +"/shan": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
	  "eastdown"  : __DIR__"slxl2",
	  "westup"    : __DIR__"slxl3",
	  "north"    : __DIR__"jingji/enter",
      ]));
      setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	me = this_player();
	if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	     && dir == "westup"
	     && objectp(present("zhang cuishan", environment(me))))
	{
	    message_vision(CYN"张翠山道：“各色人等，到解剑岩都需解剑，千百年来概无例外！”$N慑于武当山规，不敢硬争，只得退了一步。\n\n"NOR"\n",me);
	    return notify_fail(RED"请不要装备武器。"NOR"\n");
	 }
	 return ::valid_leave(me, dir);
}

