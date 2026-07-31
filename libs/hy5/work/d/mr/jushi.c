// /u/beyond/mr/jushi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"局室"NOR);
         set ("long",@long
这是大家平时休闲起居的地方, 里面放着一具古筝, 一张棋桌, 上面的
棋错综复杂, 令人百思不得其解。局室的东面是大厅，西面是一条长廊，南
面是一间厢房。
long);                                                           
         set("item_desc",([
         "qiju" : "一盘杀的难解难纷的棋，不知你是否想研究一下？\n",
         ]));
         set("exits",([
             "east" : __DIR__"dating",
             "west" : __DIR__"cl6-0",
             "south" : __DIR__"xiangfang3",
]));

	setup();
}



int do_yanjiu(string arg)
{
	object me;

	me = this_player();
        if ( !living(this_player()) || arg != "qiju" )
                 return 0;
	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
         if ( (int)me->query("jing")<30) {
 me->receive_damage("jing", 10);
                 write("你太累了，已经没有力气来研读棋局了！\n");  
                 return 1;
}
me->receive_damage("jing", 10);

	message_vision("$N正专心研究桌上的「棋局」。\n", me);

	if ( (int)me->query_skill("parry", 1) < 31)
	{
		me->improve_skill("parry", me->query("int"));
		write("你对着桌子上的「棋局」琢磨了一回儿，似乎对基本招架略有心得。\n");
		return 1;
	}

	write("你对着棋局研究了一会，但是你已经研究透彻，对你来说已毫无意义了。\n");

	return 1;
}


