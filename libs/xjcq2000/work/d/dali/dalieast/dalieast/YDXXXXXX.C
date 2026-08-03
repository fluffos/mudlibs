// Room: /d/dali/ydxxxxxx.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "燕子窝");
	set("long", @LONG
洞上边的悬岩侧壁上，无数石穴密如蛛网，成千上万的岩燕，结巢其上每
当春夏之间，千万只燕子进入洞内，生儿育女，繁衍后代。每年，人们都要从
这些绝壁上采集为数可观的燕窝，作为滋补佳品。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
		"west" : __DIR__"ydxxxxx",
	]));

	setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/ydxxxxxx",1);
      }
}
