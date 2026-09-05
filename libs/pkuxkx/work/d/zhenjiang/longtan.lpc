// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "龙潭");
        set("long", @LONG
这里是湖底，盘踞着一条恶龙，经常夺人性命。
LONG);
        set("no_task",1);
        set("no_die",1);
        set("real_dark",1);
        set("no_sleep_room",1);
        set("exits", ([     
                
                "up" : __DIR__"dahu",
                
]));
     
        
   setup();
}

int valid_leave(object me,string dir)
{
    if (dir=="up")
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
        tell_object(victim,RED+"你在龙潭损失了：\n");
        tell_object(victim,"\t"+chinese_number(-exp)+"点经验；\n");
        tell_object(victim,"\t"+chinese_number(-pot)+"点潜能；\n"NOR);
        return 1;
    }
    tell_object(victim,"虽然死在了龙潭，但你完全没有损失。\n");

    victim->remove_listen_to_die(this_object());
    return 1;
}

int start(object me)
{
            object laohu=new(__DIR__"npc/long");
            tell_object(me,WHT+BLINK+"恶龙猛地游了出来，缠住了你。\n"+NOR);
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