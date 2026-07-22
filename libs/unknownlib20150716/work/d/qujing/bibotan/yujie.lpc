#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "玉阶");
  set ("long", @LONG

一条白玉铺成的玉阶将龙沙台和水晶宫连起。阶的左右立有武士
把守。一些鱼精水怪出出入入，水晶宫中灯火通明，似乎正在举
行大宴，传出阵阵觥酬交错的声音。
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/bie" : 1,
  __DIR__"npc/gui" : 1,
]));
//  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shuijg",
  "south" : __DIR__"longtai1",
]));
//      
        set("water", 1);
//  
  setup();
}

int valid_leave(object me, string dir)
{
	object guai;
        if( wizardp(me)) return ::valid_leave(me, dir);
	if( me->query("family/master_id")=="jiutou fuma") 
		return ::valid_leave(me, dir);
        if (dir == "northup" && !me->is_yinshen() ) 
        {
        	if (objectp(guai=present("xiboer gu", environment(me)))
        	 && !userp(guai) )
        		return notify_fail("西波儿古嚷道：宫中有贵客，闲人免进！\n");
        	if (objectp(guai=present("guboer xi", environment(me)))
        	 && !userp(guai) )
        		return notify_fail("古波儿西嚷道：宫中有贵客，闲人免进！\n");
        }   
        return ::valid_leave(me, dir);
}

