//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","仙人桥");
	set("long",@LONG
这里是两座孤崖之间唯一的通道－－“仙人桥”，前人在石面光滑如削的绝
壁上凿出仅一脚一手深的石窝或浅窄的石级，一直通向崖壁的几个石洞，洞旁有
“罗立诸峰”，“明星玉女”等引人注目的题刻，古时真人就是在这里修行，可
谓绝世脱俗。再往上就是“疑无路”了。
LONG);
	set("exits",
	([
          "east" : __DIR__"lianhua_tai",
          "up" : __DIR__"yiwu_lu",
          	]));
        set("outdoors","kongdong");
        setup();
        //place_program(ROOM);
}
