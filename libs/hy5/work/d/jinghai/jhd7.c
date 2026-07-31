// Room: /d/jinghai/jhd7.c

inherit ROOM;

void create()
{
	set("short", "衫树林");
	set("long", @LONG
你走在繁密的衫树林中，便似来到传说中的巨人国一般，巨
大的衫树已不知生长了几百年了每一棵都有数十丈高，你不禁心
中赞叹上天斧圭之神奇。偶而一声清脆的鸟鸣划破四周的静谧，
似乎更为这里添加了一种神秘的气氛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"westup" : __DIR__"jhd8",
	"east" : __DIR__"jhd3",
	"enter" : __DIR__"mi1",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
