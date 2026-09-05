// Room: /city/underground.c
// becool
inherit ROOM;

void create()
{
	set("short", "丽春院密室");
	set("long", @LONG
这是丽春院的一间密室，没想到一个妓院竟然也有这么一个地方。
角落里一个畏畏缩缩的中年男子拿着把锥子在凿墙，像是在修地道。
LONG);
	set("exits", ([
		"up" : __DIR__"lichunyuan",
	  "eastdown":"d/city/undergrounde1",
	]));
        set("objects", ([
		__DIR__"npc/chongzi" : 1,
                ]));
  set("no_die", 1);
	setup();
}