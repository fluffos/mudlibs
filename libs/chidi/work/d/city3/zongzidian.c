// Room:/d/chengdu/zongzidian.c
// oooc 1998/6/28

inherit ROOM;

void create()
{
	set("short", "阿林粽子店");
	set("long", @LONG
这是一家和嘉兴“六芳斋”联营的粽子店。店主人张禽林据说
是湖北邵县的一个书生。因为爱上当地青楼的一个歌妓霍琳琳，所
以弃书从商，发誓要赚钱为爱人赎身。但是他并不是做生意的料，
开店后生意一直不好，因此在他脸上几乎看不到笑容。
LONG
	);

	set("exits", ([
		
                "west" : __DIR__"xiaojie1",
	]));

	set("objects", ([
		__DIR__"npc/zhangqinlin" : 1,
	]));

	setup();
	replace_program(ROOM);
}

