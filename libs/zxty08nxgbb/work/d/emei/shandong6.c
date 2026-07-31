// Room: /d/emei/shandong2.c 山洞2
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "山洞");
	set("long", @LONG
你走在一条漆黑山洞里，朦胧中，不时感到头顶一阵刺痛，只觉得洞
内十分狭窄和低矮。摸着洞内岩壁缓慢前行，从墙壁上散发出的阴冷潮湿
气息，使你不由自主的打了寒噤，浑身有说不出的难受。
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong7",
           "west":  __DIR__"shandong"+(random(6)+5),
           "south": __DIR__"shandong"+(random(6)+5),
           "north": __DIR__"shandong"+(random(6)+5), 
	]));
	setup();
}
