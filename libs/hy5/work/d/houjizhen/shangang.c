// shangang.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山冈");
	set("long", @LONG
这是这里郊外的一个坟场，说是坟场，其实是一个乱葬冈，当年武林一场
浩劫死了不少的人，死尸都扔在这里，没有人去理会！后来人们才纷纷在这建
了些坟，让死去的亲友们得以安息。可能由于杀气太重，这里常年都是乌云满
天的，凄厉的寒风扑面吹来，更显得阴森可怖。平时都没人敢到这来，只有树
上的乌鸦‘呀，呀’凄惨地叫着。
LONG
	);
	set("exits", ([
	"northwest" : __DIR__"tomb",
	"east" : __DIR__"shulin3",
	]));
	setup();
//	replace_program(ROOM);
}



