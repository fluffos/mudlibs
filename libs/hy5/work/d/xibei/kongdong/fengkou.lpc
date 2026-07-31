//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","峰口");
	set("long",@LONG
崆峒山一名空同山，乃唐时杜光庭《洞天福地岳渎名山记》所列七十二福地
之一，眼前便是崆峒山主峰--马鬃山，峰高千仞，三面临渊，松遮云绕，向峰顶
望去，隐约可见一排排精致奇巧的古建筑，上接云天，下临深谷，红楼碧瓦，犹
如天宫一般。传说崆峒最早为道家所崇奉的仙人广成子修炼得道之所，被道教奉
为远祖的噌登崆峒问道于广成子，故此山有“道家第一名山”之称。
LONG);
	set("exits",
	([
	"south" : "/d/xibei/kongdong_shan",
          "northup" : __DIR__"shijie1",
	]));

        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
