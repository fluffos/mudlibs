// Room: /d/emei/dadian.c 峨嵋派 大殿
// create by host dec,15 1997
inherit ROOM;


void create()
{
	set("short", "大殿");
	set("long", @LONG
这里是卧云庵的正殿。正中供奉着一尊巨大的普贤菩萨，披发跣足，
衣纹飘动。铜象左右各侍立金童玉女。在左右两边各挂了一幅诘语“法力
无边”，“普济群英”。殿内正中摆放了一张香案，案上香烟缭绕。靠墙
放着几张太师椅，地上放着几个蒲团。
LONG
	);

	set("exits", ([
               "north":__DIR__"guangchang",
	]));

	set("objects",([
               CLASS_D("emei") + "/jingxuan" : 1,
	]));

	setup();

}
