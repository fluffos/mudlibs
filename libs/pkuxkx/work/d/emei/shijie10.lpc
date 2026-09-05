// Room: /d/emei/shijie10.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "石阶");
set("outdoors","emei");
	set("long", @LONG
这里是通往峨嵋山的石阶，一条长长的石阶向西延伸，
就向没有尽头似的，虔诚的进香客来来往往。沿途很是热
闹，不是有小贩沿路叫买，还有峨眉的女尼和俗家弟子来
来往往。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            //"southeast" : "/d/wudang/wdroad8",
            "west" : __DIR__"shijie11",
            //"northwest" : "/d/dalunsi/tulu1",  
            "northdown" : "/d/chengdu/guandaos3",
]));
	
	setup();
}

