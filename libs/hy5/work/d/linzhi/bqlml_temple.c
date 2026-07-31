// Room: /d/linzhi/bqlml_temple.c

inherit ROOM;

void create()
{
	set("short", "布久喇嘛林寺");
	set("long", @LONG
布久喇嘛林寺位于尼洋河下游左岸的三级阶地上，三面环山
，面对尼洋河口三角洲，属红教寺院。整座寺庙为土木结构，飞
檐画栋，金璧辉煌，融合藏汉民族不同建筑艺术风格。寺院周围
的环境清幽，绿树成荫，寺院外清溪长流。置身此间，既可观赏
漫山林海，又可远眺波光潋滟的尼洋河三角洲。布久喇嘛林寺依
山傍水，佛殿庭院掩映绿荫之中，院内藏獒成群。整个寺院形状
内呈正四角，外底层屋檐共有二十角，第二到第三层屋檐为八角
，佛殿高20余米，内径10余米，上覆金顶，呈塔形，四面墙体分
以白蓝红绿四色涂之，非常漂亮。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lin46",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/monk1" : 2,
 __DIR__"npc/biglama" : 1,
  __DIR__"npc/lama" : 1,
__DIR__"npc/xintu" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
