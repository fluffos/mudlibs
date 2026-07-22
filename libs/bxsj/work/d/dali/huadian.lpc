// Room: /dali/huadian.c
// bbb 1997/06/11
// Modify By River 98/12/	  
inherit ROOM;

void create()
{
	set("short", "花店");
	set("long", @LONG
你一到这里，立即被一阵花香陶醉，只见从房顶到地面，全是花的世界标
签上写着:「红妆素裹」,「十八学士」,「眼儿媚」,「风尘三侠」之类，大部
分都是大理的国花：茶花，卖花的姑娘见你走了进来，忙迎了上来。
LONG
	);
	set("exits", ([
           "west" : __DIR__"dongjie7",
        ]));

	set("objects", ([
	       __DIR__"npc/maihua": 1,
	       __DIR__"npc/yatou": 1,
        ]) );
	set("coor/x",-280);
  set("coor/y",-450);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/huadian",1);
      }
}
