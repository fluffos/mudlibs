#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
       set("short", HIY "新闻" NOR);
	set("long", @LONG
这里是江湖的新闻发布中心，有什么新闻都可以在这里发布(post)，
然后系统自动随机通知所有在线玩家。
LONG );
	set("exits", ([
     "east" : __DIR__"wizard_room",
	]));
	set("objects",([
		__DIR__"newer":1,
	//"d/wizard/npc/chaiyao":1,
	]));
	set("no_clean_up", 1);
	setup();
	call_other("/d/board/news_b", "???");
	replace_program(ROOM);
}
