// Room: /d/dali/xishuang.c
// bbb 1997/06/10 
// update cool 98.2.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "西双版纳");
	set("long", @LONG
西双版纳是大理边疆一块美丽富饶的土地，澜沧江及其支流小黑江、普文
河、流沙河、罗梭江、南腊河等河流，横贯全境。东部为无量山山地，西侧为
怒山山地余脉，最高峰为孔明山，有允景洪、勐遮、勐罕、勐海、勐腊普文等
坝子。在一望无际的原始森林里还繁殖着野象、虎、豹、犀牛、金丝猴、孔雀、
犀鸟等珍禽异兽。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
             "northeast" : __DIR__"xiushan",
             "east" : __DIR__"jiangnan",
	]));

	set("coor/x",-310);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/xishuang",1);
      }
}

int valid_leave(object me, string dir)
{
        if ( me->query_temp("xuncheng")
         && dir == "east")
           return notify_fail("你还在巡城呢，仔细完成你的任务吧。\n");
           return ::valid_leave(me, dir);
}

