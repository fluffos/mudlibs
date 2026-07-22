
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"小石桥"NOR);
	set("long",@long
这是一座小小的白石拱桥。桥下碧绿的湖水正荡着微波。远处的湖面上传
来阵阵歌声，不远处两只鸳鸯在一起戏水，岸边的柳树随着湖面上吹来的微风
时不时地摇摆着。
long);
	set("outdoors","昆仑");

	set("exits", ([
		"north" : __DIR__"jingxiushi",
		"east" : __DIR__"huayuan1",
		"west" : __DIR__"jiuqulang1",
	]));

	set("objects", ([
		CLASS_D("kunlun/suxizhi") : 1,
	]));

	setup();
}
