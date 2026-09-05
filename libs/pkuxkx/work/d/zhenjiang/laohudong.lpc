// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山林深处");
        set("long", @LONG
山林深处，这里据说有猛虎出没。
LONG);
        set("no_task",1);
        set("no_die",1);
        set("real_dark",1);
        set("no_sleep_room",1);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                
                "out" : __DIR__"shenshan",
                
]));
     
        
   setup();
}

int valid_leave(object me,string dir)
{
    if (dir=="out")
    {
        me->remove_listen_to_die(this_object());
    }
    return ::valid_leave(me,dir);
}

void init()
{
    object me=this_player();
	me->listen_to_die(this_object());
}

int die_notify(object victim)
{
    int pot,exp;
    exp=random(15000-(victim->query("kar")*victim->query("int")*4));
    if (exp<5000)
    {
        exp=5000;
    }
    pot=exp/2;
    if (victim->query("combat_exp")>150000)
    {
        exp=REWARD_D->add_exp(victim,-exp);
        pot=REWARD_D->add_pot(victim,-pot);
        tell_object(victim,RED+"你在山林深处损失了：\n");
        tell_object(victim,"\t"+chinese_number(-exp)+"点经验；\n");
        tell_object(victim,"\t"+chinese_number(-pot)+"点潜能；\n"NOR);
        return 1;
    }
    tell_object(victim,"虽然死在了山林深处，但你完全没有损失。\n");

    victim->remove_listen_to_die(this_object());
    return 1;
}

int start(object me)
{
            object laohu=new(__DIR__"npc/laohu");
            tell_object(me,HIY+BLINK+"一声虎啸，一只猛虎从山林里冲了出来。\n"+NOR);
   		    laohu->set_temp("seeme",me->query("id"));
            if (me->query("combat_exp")>300000)
            {
                laohu->do_copy(me);
            }
    		laohu->set("uni_target", me);
    		laohu->move(this_object());
    		laohu->kill_ob(me);
    		me->kill_ob(laohu);
            return 1;
}