// /guanwai/tianhuo.c

inherit ROOM;
#include "/d/changbai/caishen.h";

void create()
{
	set("short", "天豁峰");
	set("long", @LONG
乘槎河东岸，与龙门峰对峙。峰顶如鹰嘴般的峻峭山峰破石而出，伸向
天池，故又名鹰嘴峰。古书载：“峰起双尖，中辟一线，有豁然开朗、令人
不可思议之趣”，相传为大禹治水所劈，石多赤色，犹如二龙蟠踞，妙趣横
生。据说在这周围的杂草之中就生长着人参，不知道搜索一下能否有所发现。
LONG );
	set("exits", ([
		"east" : __DIR__"huagai",
		"west"  : __DIR__"longmf",
	]));


	set("outdoors", "changbai");

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();

}
