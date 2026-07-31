// Room: /d/death/inn1.c
 
#include <ansi.h>
inherit ROOM;
 
int do_leave(object ob);
 
void create()
{
        set("short", "蒙古大军账内");
        set("long", @LONG
蒙古大军账内里面有不少蒙古兵,在商量着,如何消灭我大宋,你看
着这帮蒙古人,不由得心里发努,想要干掉他们,但看上去他们武功
似乎不弱,如果你想逃的话,还来的及(leave).
LONG );
 
       set("objects", ([
               "/quest/menpaijob/gumu/guan" : 1,
]) );

//        set("no_clean_up", 0);
        setup();
//	replace_program(ROOM);
}
 
void init()
{
        add_action("do_leave","leave");
}

int do_leave(object ob)
{
        ob = this_player();
        if(ob->query("kill_gumu") == 1)
{
        ob = this_player();
          if (ob->is_busy())
        return notify_fail("你现在正忙着呢。\n");
         if (ob->is_fighting() )
         return notify_fail("你现在逃不了！\n");
        write(HIW"你想了一想,看来力量不足打不过蒙古人,只能撤退了.\n");
        ob->move("/d/xiangyang/southgate2");
        ob->set("kill_gumu", 0);
        ob->apply_condition("menpai_busy",1+random(8));
        write(HIR"你终于逃出了蒙古军大营.\n"NOR);
        return 1;
}
        if(ob->query("kill_gumu") == 0) 
{
        ob = this_player();
          if (ob->is_busy())
        return notify_fail("你现在正忙着呢。\n");
         if (ob->is_fighting() )
         return notify_fail("你现在逃不了！\n");
        write(HIW"你完成了任务,大笑几声,该撤退了.\n");
        ob->move("/d/xiangyang/southgate2");
        write(HIR"你终于逃出了蒙古军大营.\n"NOR);
        return 1;
}
        if(!ob->query("kill_gumu")) 
{
        ob = this_player();
          if (ob->is_busy())
        return notify_fail("你现在正忙着呢。\n");
         if (ob->is_fighting() )
         return notify_fail("你现在逃不了！\n");
        write(HIW"你完成了任务,大笑几声,该撤退了.\n");
        ob->move("/d/xiangyang/southgate2");
        write(HIR"你终于逃出了蒙古军大营.\n"NOR);
        return 1;
}
}
