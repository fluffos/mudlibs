//changan city
// Cracked by 凌惊雪 1-3-2003
inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "红阁");
        set ("long", @LONG
这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，
为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒
的平生绝学屏风大法的介绍。

LONG);

        set("exits", ([ 
                "south" : __FILE__,
        ]));
  	set("no_fight", 1);
  	set("no_magic", 1);
	set("no_clean_up", 0);
        set("item_desc",([
        	"south" : "这里是神侯府的天机楼。这里和其他周围的几个小阁连为一体，错落有致，为古黄玉石的建筑。楼内四壁镂有水舞寒的手迹，气势磅礴。其间很多是水舞寒的平生绝学屏风大法的介绍。\n",
        ]));
	
        setup();
}

int valid_leave(object who,string dir)
{
	if( !query("exits/"+dir) )
		return ::valid_leave(who,dir);
	who->start_busy(1);	
	if(random(4)==1)
	{
		who->move(__DIR__"tianji");
		return 2;
	}
	else	return notify_fail("你沉迷于四壁上的真迹，流连忘返。\n");
}