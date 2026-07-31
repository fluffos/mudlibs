// Room: /u/aplio/ltsh/shiwai.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "龙腾山");
	set("long", @LONG
飞流瀑布，直泻三千。深山耸立，云深不知处。一条弯曲小路依山环绕。
别说是普通人，就连身怀绝顶轻功高手也望而生畏。依稀望见一栋气势磅礴的
大殿，正是令江湖人物闻风丧胆的龙腾四海总坛所在。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"jyt",
]));
	set("outdoors", "龙腾山影");

	setup();
	replace_program(ROOM);
}
