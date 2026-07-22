//changan city
// Cracked by 凌惊雪 1-3-2003
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "天机楼");
        set ("long", @LONG
这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，
为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒
的平生绝学屏风大法的介绍。楼的入口处似乎有面挂帘（lian）。

LONG);
        set("exits", ([ 
                "north" : __FILE__,
                "south" : __FILE__,
                "west" :  __FILE__,
                "east" :  __FILE__,
        ]));
        set("item_desc",([
        	"lian" : "一面挂帘，你应该可以拉开它（open）。\n",
        	"挂帘" : "一面挂帘，你应该可以拉开它（open）。\n",
        	"west" : "这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒的平生绝学屏风大法的介绍。\n",
        	"east" : "这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒的平生绝学屏风大法的介绍。\n",
        	"north" : "这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒的平生绝学屏风大法的介绍。\n",
        	"south" : "这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒的平生绝学屏风大法的介绍。\n",
        ]));
  	set("no_fight", 1);
  	set("no_magic", 1);
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
}
void init()
{ 
	add_action("do_open","open");
}

int valid_leave(object who,string dir)
{
	if( !query("exits/"+dir) )
		return ::valid_leave(who,dir);
	this_player()->start_busy(1);	
	if(random(10)==5)
	{
		this_player()->move("/d/luoyang/ge1");
		return 2;
	}
	else if(random(10)==5)
	{
		this_player()->move("/d/luoyang/ge2");
		return 2;
	}
	else if(random(10)==5)
	{
		this_player()->move("/d/luoyang/ge3");
		return 2;
	}
	else if(random(10)==5)
	{
		this_player()->move("/d/luoyang/ge4");
		return 2;
	}
	else	return notify_fail("你沉迷于四壁上的真迹，流连忘返。\n");
}

int do_open(string arg)
{
  	object me=this_player();
  	if( !arg || ( arg!="lian" && arg!="挂帘") )
  		return 0;
  	message_vision("$N伸手拉开挂帘，下了天机楼，回到了书房。\n", me);
  	me->move(__DIR__"shufang");
      	return 1;
}