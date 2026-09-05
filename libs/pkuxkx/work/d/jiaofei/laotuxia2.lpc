//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void create()
{
			set("short", "老秃峡");
  		set("long", @LONG
走到这里，峡谷宽敞很多，你感觉心里一片亮堂。你往上一看，有突出的崖
石(stone)可以落脚,但如果轻功修为稍低,根本无法攀援。
    前面光线慢慢亮了起来，眼看就要走出峡谷，你心里的烦闷之气也稍稍缓解。
LONG
        );
			set("exits", ([ 
  			"southdown" : __DIR__"laotuxia",
  			"northup" : __DIR__"sshanlu3",	
   		]));
        set("item_desc", ([
        "stone" : "这是一块突出来的崖石，可以jump来登上崖顶。\n",
        ]));
			set("objects",([
//     __DIR__"tufei":1,
        ]));
      set("max_user",1); 
      set("outdoors", "tiezhang");
			setup();

}
void init()
{
  		add_action("do_jump", "jump");
}

int do_jump(string arg)
{
			object me=this_player();
			if(arg !="stone") return 0;
			if(random(me->query_skill("dodge")<300))
				return notify_fail("你这点轻功乱跳会掉进峡谷的！\n");	
			tell_object(me,"你看准峭壁上的踏脚之处，深吸一口气，攀援而上，不一会到了崖顶，"+
			"果然土匪已经备好弓箭，只等众人进入埋伏，万箭齐发。\n"	);
			me->move(__DIR__"syading");
			return 1;
}
