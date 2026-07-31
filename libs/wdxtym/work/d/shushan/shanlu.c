//【蜀山派】mhxy-yushu 2001/2
//modified by hanchat@txwx2005
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","山麓");
  set ("long", @LONG

曲折的小路尽头豁然开朗,东南方向就是著名的卧眉峰了。由于很久没
人走动，路边的小草(grass)都有人那么高了,不知道草里面有没有什么
东西。
LONG);

//  set("outdoors", 2);
  	
  set("exits", ([      
// "southeast" : __DIR__"womeifeng",
 "northeast" : __DIR__"road0",
 "southwest" : __DIR__"shanlu1",

 ]));


     set("item_desc", ([
         "grass" : HIR"\t\t\这草看起来好像跟其它的不太一样, 要不要挖掘(wacao)看看。\n"NOR
      ]));

 setup();
}

void init()
{
  add_action("do_wajue", "wacao");
}
int do_wajue(string arg)
{
object yaocai,weapon, me=this_player();
if ((arg != "草" && arg != "grass") || !arg)
	return notify_fail("你要挖什么？\n");

if(!query("havewajue"))
	return notify_fail("你来得太晚了，这草已经给挖走了。\n");

weapon=me->query_temp("weapon");
if (!weapon)
    return notify_fail("你不会想要空手挖吧？\n");

if (weapon->query("skill_type")=="dagger")
{
	message_vision("$N用手中的"+weapon->name()+"开始挖掘地上的草。\n",me);
	message_vision("$N挖掘到一株稀有的药材。\n",me); 
	yaocai=new("/d/shushan/obj/yaocai");
	yaocai->move(me);
	set("havewajue", 0);
	return 1;
}

	message_vision("$N用手中的"+weapon->name()+"开始挖掘地上的草。\n",me);
	message_vision("$N使用的工具不对,看来挖不出来。\n",me); 
return 1;
}

void reset()
{
	::reset();
	set("havewajue", 1);
}
