#pragma save_binary
inherit ROOM;
#include <ansi.h>
#include <command.h>
void create()
{
 set("short",WHT"最後乐园"NOR);
	set("long",@LONG	
这里就是传说中的 VOID -- 大神和巫师的最後乐园. 你看到四周一片
白茫茫的, 不一会从虚无中冒出一只企鹅, 递给你一罐「可口可乐」(tm), 
然後站在一旁很邪恶地笑著. 又过了一会, 一只北极熊走了过来, 一掌拍扁
了那只企鹅并从你手上抢走那瓶可乐, 大笑三声後就从你眼前消失了.
你摇摇头, 这种地方还是不要待太久的好.
LONG
);
        set("objects", ([
                __DIR__"bjx" : 1,
              ]));
	setup();
}

void init()
{
        add_action("do_go","jump");
}
int do_go()
{
object me;
object *inv;
int i;
        me = this_player();
                inv = all_inventory(me);
             if(!wizardp(me))
             for(i=0; i<sizeof(inv); i++)
                {
               if (!inv[i]->query("no_drop") && !inv[i]->query("no_get") && !inv[i]->query("no_gave"))
                                                DROP_CMD->do_drop(me, inv[i]);
                                        else
                                                inv[i]->move("/d/changan/job/relax");
                }
        me->start_busy(20);
        me->move("/d/changan/center");
        return 1;
}
