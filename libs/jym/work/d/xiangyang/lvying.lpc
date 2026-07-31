//Cracked by Roath
// Room: /d/xiangyang/lvyingbi.c

inherit ROOM;

void create()
{
	set("short", "[1;32m绿影壁[2;37;0m");
	set("long", @LONG
眼前一堵巨大的照壁面北而立，全壁用青绿色石料刻砌而成。壁分三堵，中
堵最高，由三十一块大型绿砚石镶嵌而成，上雕二龙戏珠於云水之间；左右两堵
各刻蛟龙(dragon)飞舞，直奔中堵，大有夺珠之势。四周用白砚石镶边，精雕小
龙数十条，状态各异，栩栩如生。座底和壁顶亦由巨石镶嵌，上雕各种花草、彩
云图案，花纹细腻，技巧独特。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "dragon" : "你仔细数了一下，整堵石壁雕龙九十九条，布局浑然一体，气势恢宏磅礴。
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huating",
]));

	setup();
	replace_program(ROOM);
}
