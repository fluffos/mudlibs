// by aiai
 
inherit ROOM;
#include <room.h>

void create ()
{
	set ("short", "青石崖");
	set ("long", @LONG

   岛上风光秀丽，当真是好去处！高崖上视野开阔，远望四周，
把蓬莱景色看的清清楚楚。远处大海如明镜般平整。山崖上长有
无数异草，飘着淡淡香气。远处你隐隐觉得地上好像有一个什么
洞(hole),你不妨走过去看看(kan)。
LONG);
	set("exits", ([ /* sizeof() == 3 */
	
]));
	set("objects",([
      //            "/kungfu/class/xiakedao/xianzhi":1,
        __DIR__"npc/baihe":1,
	]));
	set("no_clean_up",1);
	set("outdoors", "xiakedao");
	setup();
}
void init()
{
	add_action("do_down", "d");
        add_action("do_down", "down");
        add_action("do_jump", "jump");
add_action("do_lookin","lookin");
       add_action("do_look", "kan");
	
}
int do_jump(string arg)
{
object me;
object room;
me=this_player();
if(me->query("enterhole")==1)
{
tell_object(me,"你纵身一跃，跳入了洞中......\n");
       room = load_object(__DIR__"yueertai");
if(room) me->move(room);
}
else
{
tell_object(me,"你感到精神振奋，在崖上蹦蹦跳跳的做起了运动！\n");
}
return 1;
}
int do_look(string arg)
{
object me;
me=this_player();
if(arg=="hole")
{
message_vision("$N朝洞里看了看，觉得里面传来有几阵风声\n你感到莫名的兴奋，下面该不会有什么宝藏吧？可以(lookin)看清楚些\n",me);
}
return 1;
}

int do_lookin(string arg)
{
object me;
object room;
me=this_player();
if(!arg||arg!="hole") return notify_fail("你要看什么？");
if(me->query("enterhole")==1) 
{
tell_object(me,"你又来到上次掉下去的地方，往下看了看，心想，也许自己还能跳(jump)下去学功夫呢！\n");
return 1;
}
if(((int)me->query_skill("dodge")<80)&&((int)me->query("eff_qi")<(int)me->query("max_qi")))
{
tell_object(me,"\n你把头伸到洞里往下看，结果脚一滑，你整个身子就摔了下去......\n");
me->set("enterhole",1);
       room = load_object(__DIR__"yueertai");
if(room) me->move(room);
me->unconcious();
  write("过了良久，你终于醒来，你发现你居然落到了洞底，这里居然又是别有洞天！\n");
}
else
{
 message_vision("你把头伸到洞里往下看,脚突然一滑，不过还好，幸亏你轻功好，体力又足，才反应快，没有掉下去，\n结果吓了一身冷汗\n",me);
}

return 1;
}
int do_down(string arg)
{
	object me;
	object room;
	me = this_player();
        message_vision("$N从山窟跳了下去。\n", me);

	me->move(__DIR__"yaxia");
	
	return 1;
}
