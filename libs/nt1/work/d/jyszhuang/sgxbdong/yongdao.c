#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", YEL"密洞"NOR);
        set("long", @LONG
这里是上古神兵洞外的密洞，洞中的阴森之气更重，但觉洞内杀机密藏，
稍不留神，立时便有杀生之祸，看来还是小心为妙。    
LONG );
        set("indoors", "city");
        set("exits", ([
                "northeast" : __FILE__,
                "southeast" : __FILE__,
                "southwest" : __FILE__,
                "northwest" : __FILE__,
        ]));
        set("no_fly",1);
        setup();
}

int valid_leave(object me, string dir)
{
        if(present("wei shi",environment(me)))
        return notify_fail(HIY"金甲卫士怒喝到，有我在这里，谁也别想跑！\n"NOR);
        if (random(30) > 14) 
        me->add_temp("mark_yongdao/steps",1);
        if (random(30) < 10)   
        me->add_temp("mark_yongdao/steps",-1); 
        if (me->query_temp("mark_yongdao/steps") <= -6)
        {
        call_out("go_inside",1,me);
        me->delete_temp("mark_yongdao/steps");
        return 1;
        }  
        if (me->query_temp("mark_yongdao/steps") >= 6)
        {
        call_out("go_out",1,me);
        me->delete_temp("mark_yongdao/steps");
        return 1;
        }
        if (random(10) > 7)
        new(__DIR__"npc/killer")->move(environment(me));  
        return ::valid_leave(me, dir);
}
int go_out(object me)
{
        write("忽然你发现眼前一亮，不知不觉你已来到了华山绝顶之上。\n");   
        me->move(__DIR__"wudao");
        return 1;
}

int go_inside(object me)
{
        write("你累得半死，终於走出了密洞。\n");       
        me->move(__DIR__"dongkou");
        return 1;
}

