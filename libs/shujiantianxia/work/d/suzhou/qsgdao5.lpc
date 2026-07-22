inherit ROOM;

void create()
{
	set("short", "枫桥镇");
	set("long",@long
出苏州城西门向西行约三十里，就到了这枫桥镇。具史书所载，唐朝开元
年间，诗人张继赴京应试落第，返途舟船停靠枫桥，赋诗一首：“月落乌啼霜
满天，江枫渔火对愁眠，姑苏城外寒山寺，夜半歌声到客船”。从此，诗韵钟
声，脍炙人口，寺因诗而名扬天下，枫桥镇也成了游览胜地。
long);
	set("outdoors", "苏州");
	set("exits",([
		"east" : __DIR__"qsgdao4",
		"northwest" : __DIR__"hanshansi",
		"south" : __DIR__"tulu1",
	]));
	set("objects", ([
		NPC_D("youke") : 2,
	]));
	setup();
}
