#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",BLU"坟场"NOR);
        set("long", @LONG
这里是慕容氏的坟场, 慕容氏死后都要被安葬这里,世世代代, 
无一例外。每到清明时分, 慕容后裔都要在这里祭祖。场中一座新
坟格外引人住目, 那是慕容复之父慕容博之墓。
LONG);
        set("exits", ([
                "west" : __DIR__"xiaolu4",
        ]));

        

        set("book_count",1);

        
        setup();
        

}

void init()
{
        this_player()->set_temp("ketou_times", 30);
        add_action("do_ketou", "ketou");
}

int do_ketou()
{
        object me, ob;

        me = this_player();
                
        if ( me->query_temp("ketou_times") == 0 )
        {
                message_vision("$N磕头磕得晕了过去。\n", me);
                me->set_temp("ketou_times", random(30));
                me->unconcious();
                return 1;
        }

        me->add_temp("ketou_times", -1);        

        message_vision("$N虔诚地跪下来，在墓碑面前磕头。\n", me);

        if ( random(100) == 37 
        && !present("force book", me)
        && query("book_count") >= 1)
        {
                add("book_count", -1);
 ob=new(__DIR__"obj/neigong-book");
  ob->move(__DIR__"fenmu");
                tell_object(me, "突然你面前，啪地一声掉下一本内功心法！\n");
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

int valid_leave(object me, string dir)
{
        if(me->query_temp("ketou_times") >= 0 ) me->delete_temp("ketou_times");

        return ::valid_leave();
}


