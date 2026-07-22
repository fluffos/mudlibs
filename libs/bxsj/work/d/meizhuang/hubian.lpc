// /d/meizhuang/hubian.c 西湖边
// By Lklv

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", GRN"西湖边"NOR);
	set("long", @LONG
这是西湖孤山的一个所在，一边倚着小山，和外边湖水相隔一条长堤，更
是幽静。湖边有几株垂柳，倒影映在碧绿的湖水里，微风吹过，倒垂下来的柳
条拂过水面，带出一层层的涟漪。东边是一条蜿蜒曲折的石级，不知道通向哪
里。
LONG
);
	set("objects",([
		"/d/hz/npc/you" : 2,
	]));
	set("outdoors","杭州");
	set("exits", ([
		"west" : "/d/hz/gushan",
		"east" : __DIR__"shiji",
	]));
	setup();
}
