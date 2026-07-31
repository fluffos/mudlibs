// yaopu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "济世堂");
	set("long", @LONG
这里是镇中唯一的药铺，由于这里靠近天山，所以，在这里你可以买到
许多珍贵药材。济世堂的老板是一位老头子，留着长长的胡须，虽然他的脸
上写满了岁月的沧桑，但是他那一双眼睛看起来炯炯有神。
LONG
	);

	set("exits", ([
		"south" : __DIR__"shilu5",
	]));

        set("objects",([
		__DIR__"npc/yaoboss" : 1,
	]));
        
	setup();
	replace_program(ROOM);
}
