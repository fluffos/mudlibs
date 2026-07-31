//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "妃丽湖畔");
	set("long", @LONG
你站在妃丽湖的北岸，北边不远就是喜州城。此湖不大，但湖水
清澈，鱼鳖皆有，不少台夷村民划着竹筏在湖上捕鱼。湖之南和东边
半山上都有台夷村镇，有道路绕湖东而过通向南边。
LONG
);

	set("exits", ([
		"north" : __DIR__"minov61",
		"east"  : __DIR__"minov76",
		"southeast" : __DIR__"minov65",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
