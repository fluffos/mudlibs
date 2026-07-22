// 织布房
// zhibufang1.c
// augx@sj 19/9/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIY"织布坊"NOR);
	set("long",
"这是间到处飞满棉絮的房间，纺织女工们正紧张的在里屋忙碌着。终日
都可以听到编织机运作的声音，纺织女们以纤细的手指捏着纺梭在编织机上
忙碌的身影也甚是优美。你可以在这里买卖布匹，和编织自己的布匹。
"); 

	set("objects",([
		__DIR__"npc/fangzhi-nu" : 1,
		//__DIR__"obj/zhibuji" : 1,
	]));
	
	set("exits",([
		"west" : "/d/changan/northjie2",
	]));
	
	set("indoors", "长安城");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
