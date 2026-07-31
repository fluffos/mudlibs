// Room: /open/stst/sazai/men.c

inherit ROOM;

void create()
{
        set("short", "野羊寨大门");
        set("long", @LONG
    这里就是江湖上提起就变色的野羊寨，是强盗和土匪就地分赃的地
方。保镖的到了这里，保准是有去无回，从这里向北走就是野羊寨的练武场
了。

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu1",
  "south":__DIR__"huanglu",
]));
	set("objects",([
		__DIR__"npc/zaiding":2,
]));

        setup();
        replace_program(ROOM);
}

