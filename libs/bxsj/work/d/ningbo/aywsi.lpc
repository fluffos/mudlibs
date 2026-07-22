// Room: /u/beyond/ningbo/tianfengta.c 阿育王寺
// Beyond make 1997.6.8

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"阿育王寺"NOR);
	set("long", @LONG
阿育王寺殿顶都复以黄色琉璃瓦，舍利殿中设七级舍利塔，非金非石。光
芒四射。相传人们能从塔空中窥视舍利子，石塔后有释迦牟尼像。寺内环境十
分幽静，是及好的禅修之所。
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"tianyige",
		"west" : __DIR__"tianfengta",
		"southeast" : __DIR__"ningbo",
		"east" : __DIR__"xikou",
	]));
	set("outdoors", "宁波");
	setup();
}
