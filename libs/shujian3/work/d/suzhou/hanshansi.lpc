inherit ROOM;

void create()
{
        set("short", "寒山寺门");
        set("long",@long
相传在唐元和年间，有寒山子曾来此居住，后来高僧希迁禅师在此重建寺
院时，更名为寒山寺。具载，唐开元年间，诗人张继赴京应试落第，返途舟船
停靠枫桥，赋诗一首：“月落乌啼霜满天，江枫渔火对愁眠，姑苏城外寒山寺，
夜半歌声到客船”。从此，诗韵钟声，脍炙人口，寺因诗而名扬天下。
long);
	set("exits",([
 		"enter" : __DIR__"zhengdian",
		"southeast" : __DIR__"qsgdao5",
	]));
	set("objects", ([
		NPC_D("youke") : 1,
	]));
	setup();
}
