
#include <ansi.h>

inherit ROOM;
void init()
{
        add_action("do_climb", "climb");
}

void create()
{
	set("short", "树林");
	set("long", @LONG
你不知不觉走进了一片树林中，极目青绿，苍松翠柏，高大异常，
更有诸般奇花异树，皆为中土所无。你的面前有一棵大树(tree)，
形状古怪。
LONG
	);

	set("item_desc", ([
               "tree" : "一颗粗壮的大树，闲来无事，不如上去玩玩。\n",
       ]));


	set("exits", ([
                 "east" : __DIR__"shulin7",
		"south" : __DIR__"shulin5",
                 "west" : __DIR__"shulin2",
                "north" : __DIR__"shulin4",
	]));

	set("outdoors", "diaoyudao");
	setup();
}

int do_climb(string arg)
{
        object me = this_player();
	if( !arg || arg!="tree" ) 
	{
	     if ( !arg ) return notify_fail("你要往哪儿爬？\n");
             if ( arg!="tree" )  return notify_fail("你要往哪儿爬？\n"); 
        }
	if (arg=="tree")
	{
	   if((int)me->query_skill("dodge",1)<300)
               return notify_fail("此树极高，等闲轻功不能攀上。\n");     
	   else
             {  message("vision",me->name()+"运起轻功，一眨眼就爬上了大树。\n",environment(me),me);
	 	me->move(__DIR__"shuding");
	 	message("vision",me->name()+"爬上了大树,已是满头大汗。\n",environment(me),({me}));
	 	return 1;
	     }
	}
}





