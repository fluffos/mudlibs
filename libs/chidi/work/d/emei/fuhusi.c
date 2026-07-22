// Room: /d/emei/baoguosi.c 峨嵋派 伏虎寺
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "伏虎寺");
	set("long", @LONG
这是一座古朴的佛堂。大殿入口是朱红格扇， 正中一张雪山虎啸图，
地上整整齐齐的排放着数十个黄布蒲团，北首有一个木案，案上放着个竹
制的木鱼。香烟缭绕，氤氲芬芳，室内一片祥和之气。
LONG
	);

	set("exits", ([
		"north" : __DIR__"fuhusi1",
                 "west": __DIR__"chanfang3",
	]));

	set("objects",([
         CLASS_D("emei") + "/jingzhen": 1,
	]));

	setup();
}
