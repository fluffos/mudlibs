// /d/taiyuan/nroad1.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "大官道");
	set("long", @LONG
你走在一条尘土飞扬的大官道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。往北走是
去马邑的路。南面就是太原了。
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "northwest":__DIR__"nroad2", 
                "south":__DIR__"beimen", 
                
	]));
       setup();
	replace_program(ROOM);
}
