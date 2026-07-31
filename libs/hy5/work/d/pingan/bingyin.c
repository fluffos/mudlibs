// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，
有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色
地寻视着四周。听说这二天有毛贼出没。正在招集兵勇巡城.
LONG );
	set("item_desc", ([
		"men" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"east" : __DIR__"bei1",
	]));
	set("objects", ([
		__DIR__"npc/wujian" : 1,
		__DIR__"npc/bing" : 3,
	]));
	
	set("roomif","$botten#巡城任务:ask wang about job$#");
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
}
