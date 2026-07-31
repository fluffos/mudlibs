// By canoe 2001-06-21
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小  路");
	set("long",@LONG
这里是一条幽静的小路，路旁全部是些奇花异草，但是前面
隐隐约约有片草地。你不由的想去看看！清烟和云雾缭绕着，美丽
极了。地上竖了块牌子(paizi),西边是神农氏炼丹药的地方。
LONG
);
	
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "north":__DIR__"road3",
  "west": __DIR__"datang",
  "east":__DIR__"yejinpu",
        
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
  [1;31m
 	 ＊＊＊＊＊＊
    	 ＊	    ＊
    	 ＊ 神   擅 ＊
   	 ＊ 农   入 ＊
   	 ＊ 药   者 ＊
   	 ＊ 圃   死 ＊
   	 ＊	    ＊
    	 ＊＊＊＊＊＊
[m
"]));
 set("objects", ([
    "/d/liandan/obj/baicaoxian1" : random(2) ,
    "/d/liandan/obj/baicaoxian2" : random(2) ,
    "/d/liandan/obj/xianguan" : random(2) ,
         ]));
 
setup();
}
