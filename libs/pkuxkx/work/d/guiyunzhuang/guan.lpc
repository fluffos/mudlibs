#include <room.h>  
inherit ROOM;
void create()
{
  set("short","归云馆");
  set("long",@LONG
这里是归云庄岛的留客之所。这里窗明几净，
很显然有人经常打扫。屋角一张大床，被褥铺的整整齐齐。屋子正中小桌上放着一把
茶壶.
LONG
  );
  	set("exits/west",__DIR__"zoulang3");
	set("exits/east",__DIR__"houhuayuan");
    set("objects", ([
	__DIR__"obj/table":1,
    ]) ); 
    set("resource/water",1);
    set("liquid/name","茶水");
    set("liquid/type", "water");
    set("liquid/drunk_apply",6);
  
	setup();
}
                  
