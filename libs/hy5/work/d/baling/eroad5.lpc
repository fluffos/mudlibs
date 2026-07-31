

inherit ROOM;


void create()
{
	set("short", "官路");
	set("long", @LONG
这是一条官路。人来人往。挑担子的行商，赶着大车的马夫，熙熙
攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃
。向西是巴陵通向山海关的大道，向东则是通往涪陵县的官道。
LONG
	);
	
	set("exits", ([
                "west" : __DIR__"eroad4",
                "southeast" : __DIR__"edao4",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
