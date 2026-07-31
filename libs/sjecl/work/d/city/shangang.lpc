// shangang.c 山冈(扬州郊外)

#include <ansi.h>
inherit ROOM;

void create()
{

	set("short","山冈");
	set("long", @LONG
这是扬州郊外的一个坟场，说是坟场，其实是一个乱葬冈。当年扬州十日
屠时，城里的死尸都扔在这里，后来人们才纷纷在这建了些坟，让死去的亲友
们得以安息。可能由于杀气太重，这里常年都是乌云满天的，凄厉的寒风扑面
吹来，更显得阴森可怖。平时都没人敢到这来，只有树上的乌鸦‘呀，呀’凄
惨地叫着。
LONG
	);
	set("outdoors","扬州");

	set("exits", ([
		"north" : __DIR__"tomb",
		"southeast" : __DIR__"hsroad1",
	]));

	setup();
}

