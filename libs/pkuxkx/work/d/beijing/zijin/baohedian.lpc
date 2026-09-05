// Room: /d/beijing/zijin/baohedian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"保和殿"NOR);
	set("long",
HIC"又称谨身殿，建极殿。皇帝立后、立太子时，在此着装，再到太
和殿受贺。每当除夕，这里是宴请王公大臣的地方。著名的殿试亦在
此举行。
一座单檐鎏金攒尖顶，覆蓝色琉璃瓦的圆殿，穹窿圆顶式天花藻井，层
层收缩，不用横梁，只用柱子支撑和斗拱承托。殿内中央有4 根鎏金雕
龙的龙井柱。四周天花板上布满飞金走彩的各种圆形图案，十分雍容华
丽。在殿的后面，有一座巨大的云龙石雕，上面刻着九龙戏珠于海涛云
雾之间。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"zhonghedian",
  	"north" : __DIR__"xiaohuayuan",
]));

	setup();
	replace_program(ROOM);
}
