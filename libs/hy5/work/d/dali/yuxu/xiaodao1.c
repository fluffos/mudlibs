// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "道旁田野");
	set("long", @LONG
你走在了田间野地上，这里充满田园风光，你不由深深吸了一口这带有泥
土芳香的空气。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"xiaodao2",
	    "northeast" : "/d/dali/jianchuan",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
