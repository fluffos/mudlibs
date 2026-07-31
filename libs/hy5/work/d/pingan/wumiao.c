// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "平安武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭
毕敬地上香礼拜。旁边似乎有一道侧门。
LONG );
	set("no_fight", "1");
	set("no_dazuo", "1");
         set("pingan",1);
	set("no_steal", "1");
	set("no_sleep_room", "1");

        set("valid_startroom","1");

	set("exits", ([
		"east" : __DIR__"bei2",
	]));
        set("objects", ([
  __DIR__"npc/sighmoon" : 1,
	]));
	setup();
        "/clone/board/wiz2_b"->foo();
}

void init()
{
	object me;
	me=this_player();
	me->set("startroom",base_name(environment(me)));
	return;
}
