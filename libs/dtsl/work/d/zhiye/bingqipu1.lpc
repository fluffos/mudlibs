// 兵器铺
// bingqipu1.c
// augx@sj 9/5/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIY"兵器铺"NOR);
	set("long",
"这是一家富丽堂皇的兵器铺，墙上挂满长剑，大刀、铁锤、铁棍、匕首等
等兵器。屋角还摆着一个火炉，炉火把四周照得一片通红。柜台后面站着一位
神态严肃的铸剑师，他不但手艺好，信誉也不错，所以大家都愿意来这里买卖
兵器。
");

	set("objects",([
		__DIR__"npc/zhujian-shi" : 1,
		__DIR__"npc/hantiejiang" : 1,
		__DIR__"obj/zhujianlu" : 1,
	]));

	set("exits",([
		"north" : "/d/city/dongdajie0",
	]));

	set("indoors", "扬州城");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
