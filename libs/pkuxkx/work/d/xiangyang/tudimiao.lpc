#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"土地庙"NOR);
	set("long", 
	HIY"这里是一座小小的庙宇,逢年过节,有一些善男信女来此进香
  庙里供奉这几尊神像,神像前的供桌上还摆着一些贡品.一个青铜香炉里
  积满了香灰,空气中弥漫着一股熏香的气味.\n"NOR
	);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
    set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/obj/gongpin" : 4,
                __DIR__"npc/jxke" : 2,
         "/d/riyuejiao/npc/ry-welcomer" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"xysouth3",
                
	]));
   	setup();
	
}

/*void init()
{
    object me=this_player();
	me->set("startroom", base_name(this_object()));

}*/