// /d/zhuojun/road6.c
// Room in 涿郡
// modify by yang

inherit ROOM;


void create()
{
	set("short", "密印寺");
	set("long", @LONG
密印寺位于宁乡沩山的毗峰下，为唐代高僧灵祐所建，
唐宰相裴休捐田千亩,召各寺名僧汇聚沩山盛极一时。寺宇
高大巍峨，山门刻联语：“法雨来衡岳，宗风启仰山”。万
佛殿壁上嵌有佛像12218尊，为世界之最。该寺为禅宗五家
宗派之一的仰宗的祖庭，现已恢复成庄严雄伟的禅家道场。
LONG );
	set("exits", ([
		"west" : __DIR__"road7",
		"east" : __DIR__"road3",
	]));
	       set("objects",([
        "/d/shaolin/npc/xiao-bei" : 2,
        ]));
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



