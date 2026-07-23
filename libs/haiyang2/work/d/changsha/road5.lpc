// /d/zhuojun/road1.c
// Room in 涿郡
// modify by yang

inherit ROOM;

void create()
{
	set("short", "麓山寺");
	set("long", @LONG
麓山寺坐落在岳麓山的古树丛中，左临清风峡，右饮白鹤泉前瞰
赫曦丹枫、长岛湘流，后倚禹碑风云、深壑林海，为晋代法崇禅师首
建，有"汉魏最初名胜，湖湘第一道场"之誉，殿内千手观音庄严慈祥
。寺院内保留两株六朝古松，成为麓山寺悠久历史的活见证。
LONG);

	set("exits", ([
		"north": __DIR__"nanmen",
		"south": __DIR__"road6",
		
	]));

       set("objects",([
                __DIR__"npc/shang" : 2,
        "/d/shaolin/npc/xiao-bei" : 2,
        ]));
 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



