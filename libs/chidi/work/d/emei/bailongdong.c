// Room: /d/emei/bailongdong.c 峨嵋派 白龙洞
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "白龙洞");
	set("long", @LONG
白龙洞据说是《白蛇传》中的白娘子修炼成仙之处。是一个不大的岩洞，
洞内钟乳累累，石笋遍地，再靠左有一条暗河蜿蜒而行，宛若一条游龙伸曲
到洞的尽头。越往洞内走去阵阵扑面的潮湿气息越来越重。这里北上至万年
庵，南下是清音阁。
LONG
	);

	set("exits", ([
                 "southup" : __DIR__"shierpan1",
		"west" : __DIR__"gudelin",
                "northeast" : __DIR__"qingyinge",
	]));


	set("objects",([
	]));
	setup();
}
