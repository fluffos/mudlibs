// jiushi.c	酒室
// by bing

inherit ROOM;

void create()
{
        set("short", "酒室");
        set("long", @LONG
这是一间宽敞的房间，室中琳琅满目，到处都是酒坛、酒瓶、酒葫芦、酒杯，
屋子里充满了酒香，令人昏昏欲醉。看来此屋主人是个爱酒如命之人。
LONG);

        set("exits", ([ 
	"east" : __DIR__"huilang",
]) );
	set("objects",([
		__DIR__"obj/putaojiu":1,
		__DIR__"obj/fenjiu":1,
		__DIR__"obj/baicaojiu":1,
		__DIR__"obj/zhuyeqing":1,
		]));

	setup();
	replace_program(ROOM);
}
