// Room: /d/emei/huayanding.c 峨嵋派 华严顶
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "华严顶");
	set("long", @LONG
这是一个比较宽阔的广场，四周寸草不生，在广场中间有一个丈高的圆
形讲坛，在石坛上有一张石案，两边各有一个石龛，余烟渺渺。在这里每年
峨嵋众弟子都要到这里来听讲经说法，如有机缘峨嵋的掌门也会在这里指点
武功。
LONG
	);

	set("exits", ([
                "southeast" : __DIR__"guanyintang",
                "westdown": __DIR__"shierpan4",
	]));

	set("objects",([
	]));

	setup();
	
}
