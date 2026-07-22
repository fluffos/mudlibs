// /u/dubei/miaojiang/mjqj

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY+"苗疆奇境"+NOR);
        set("long", @LONG
这里是山顶的边缘，但风光更为秀美。峭壁上盘蜒着古树，地上已经没有
人的足迹了，许多不知名的小动物从树丛里蹿来蹿去。
LONG                           
        );
        set("wu_count",3);

	set("outdoors", "苗疆");

        set("exits", ([
                 "southwest" : __DIR__"mjqj",
        ]));

        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));
}
 
int do_wa(string arg)
{ 
	int i;
        object wu, me, *inv;

        me = this_player();
        inv = deep_inventory(me);

        i = sizeof(inv);

        if (!( present("xiao tiechan", this_player())))
		return notify_fail("你在地上刨了刨 ，惊起许多小动物！\n");

        if ( !arg || arg != "he shouwu" )
		return notify_fail("你想做什麽？\n");       

        if ((int)me->query("jingli")<200) 
		return notify_fail ("你太累了！\n");

        if(objectp(present("heshou wu", me)))        
		return notify_fail("你已经得到何首乌了，怎么这么贪心？\n");

        if(random(15)!=3) {
		me->add("jingli",-120);
		return notify_fail("你挖了半天，只看到一些野草。\n"); 
        }

        while (i--)
        if( inv[i]->query("drug"))
		return notify_fail("你挖了半天，只看到一些野草。\n");  
 
        if (query("wu_count") > 0){
		message_vision("$N忽然看到一株何首乌，赶快捡了起来。\n",me);
		add("wu_count", -1);
		wu=new("/clone/medicine/neili/shouwu");
		wu->set("owner", me->query("id"));
		wu->move(me);
		log_file("quest/neili",sprintf("%-18s在苗疆得到%s。\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",wu->name()), me);
		me->add("jingli", -200);      
        }
	else
		message_vision("$N挖了半天，一无所获。\n", me);
	return 1;
}
