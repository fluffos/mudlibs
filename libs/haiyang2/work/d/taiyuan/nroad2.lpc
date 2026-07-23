// /d/taiyuan/nroad2.c
// Room in 太原
// modify by yang

#include <room.h>
inherit ROOM;
void create()	
{
	set("short", "大官道");
	set("long", @LONG
你走在一条尘土飞扬的大官道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。向北望去，
不远处就是一片大草原了。
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "southeast":__DIR__"nroad1", 
                "north":__DIR__"nroad3", 
                
	]));
       setup();
 	replace_program(ROOM);
}
