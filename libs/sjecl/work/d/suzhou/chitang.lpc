#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"池塘"NOR);
	set("long", @LONG
一池池水映入你的眼帘，小蓬莱翼然水中，曲折的石桥上架着紫藤花棚。
池东你可以看到曲溪楼、西楼、清风池等小筑，掩映于花木山石之间。池西的
山腰间，桂树丛生。秋日，置身于“闻木樨香轩”，阵阵桂香，沁人心脾。轩
下，水涧两岸叠石重重，你不禁为此景而赞叹不已。
LONG	);
	set("exits", ([ 
		"northeast" : __DIR__"gumujiaohe",
	]));
	set("outdoors", "苏州" );
	set("no_clean_up", 0);
	set("incity",1);
	setup();
}
