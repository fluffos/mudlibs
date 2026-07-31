// /u/beyond/mr/fenmu.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIB"坟场"NOR);
        set("long", @LONG
这里是慕容氏的坟场, 慕容氏死后都要被安葬这里,世世代代, 
无一例外。每到清明时分, 慕容后裔都要在这里祭祖。场中一座新
坟格外引人住目, 那是慕容复之父慕容博之墓。
LONG);
        set("exits", ([
                "west" : __DIR__"xiaojing1-4",
        ]));

        set("book_count",1);
        
        setup();
}

void init()
{
	if (!this_player()->query_temp("ketou_times"))
	        this_player()->set_temp("ketou_times",
			1+random(this_player()->query_skill("force", 1)));
        add_action("do_ketou", "ketou");
}

int do_ketou()
{
        object me, ob;

        me = this_player();
                
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

        if ( me->query_temp("ketou_times") == 0 )
        {
                message_vision("$N磕头磕得晕了过去。\n", me);
                me->set_temp("ketou_times",
			1+random(me->query_skill("force", 1)));
                me->unconcious();
                return 1;
        }

        me->add_temp("ketou_times", -1);        

        message_vision("$N虔诚地跪下来，在墓碑面前磕头。\n", me);

 if ( random (30) == 10 
        && !present("force book", me)
        && query("book_count") >= 1)
        {
                add("book_count", -1);
 ob=new(__DIR__"obj/neigong-book");
  ob->move(this_object());
                tell_object(me, "突然你面前，啪地一声掉下一本内功心法！\n");
        }

        if ( (int)me->query("jing")<0) {
                 write("你太累了，歇会再磕头吧！\n");              
       		 return 1;
	}
        if ((int)me->query_skill("force", 1) >= 30 
        && (int)me->query_skill("force", 1) <= 100 
        && present("force book", me) )
        {        
                me->receive_damage("jing", 20);
                me->improve_skill("force", me->query("int"));
                if ( random(5) == 0 )
tell_object(me, "冥冥之中，你似乎觉得解决了你在内功方面的疑难。\n");
        }

        return 1;
}
