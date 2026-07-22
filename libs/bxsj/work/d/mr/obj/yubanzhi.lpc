// yubanzhi.c 斑指

#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
        set_name(HIG "玉斑指" NOR, ({ "yu banzhi", "banzhi",}));
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", HIG"这玉斑指绿得出奇，通体碧绿，晶莹可爱，你忍不住想摸(mo)它。\n" NOR);
                set("value", 50000);
                set("no_get", 1);
                set("no_drop", 1);
                set("material", "jade");
                set("armor_type", "cloth");       
                set("armor_prop/armor", 5);
        }
        setup();
}

void init()
{                     
        object ob, me;
        ob = this_object();
        me = this_player();
        add_action("task", "mo");
        call_out("do_check", 2, ob);
}

int task(string arg)
{
        object me = this_player();
        int i;
        i = (int)me->query_temp("skill_lvl", 1);
        if( !me->query_temp("mr_job", 1) && !me->query_temp("mr_job_done"))
                return notify_fail("现在你没有任何任务。\n"); 
        write("你轻轻地摸了摸玉斑指，突然看见有一行小字显现出来：\n\n");
        write("\t\t偷学"HIR"[touxue]"NOR"武功「"+HIY+me->query_temp("skill_target")+NOR"」"+to_chinese(i)+"级，然后展示"HIC"[show]"NOR"给慕容复。\n\n");
        return 1;
}

void do_check()
{
        object ob = this_object();
        object me = this_player();
        string skill;
        
        if( !interactive(me)) 
        {
                if(stringp( skill = me->query("doing_job") ))
                {
                        me->delete_skill(skill);
                 }                                          
         call_out("do_check", 2, ob);
         }
         else    call_out("do_check", 2, ob);
         return;
}       
         
