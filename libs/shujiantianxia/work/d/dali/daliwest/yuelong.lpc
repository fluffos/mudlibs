// Room: /d/dali/yuelong.c
// bbb 1997/06/10 
//cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "玉龙雪山");
	set("long", @LONG
全山十三峰，峰峰终年披云戴雪，似一排玉柱立地擎天，并肩耸立在金沙
江东岸；如一条矫健的玉龙。从碧空蜿蜒而来，腾跃于锦绣大地之上。它气势
磅礴，洋溢着一种雄奇、壮丽的美。 
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
             "northdown" : __DIR__"ninglang",
	]));

	set("coor/x",-380);
  set("coor/y",-450);
   set("coor/z",0);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/yuelong",1);
      }
}
