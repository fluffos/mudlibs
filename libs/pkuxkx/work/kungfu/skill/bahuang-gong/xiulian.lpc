//xiulian.c     八荒六合唯我独尊功的修炼 
#include <ansi.h>
#include <skill.h>
void end_xiulian(object me);
int exert(object me, string arg)
{
        object where;
        seteuid(getuid());
        where = environment(me);
        if (where->query("pigging")) 
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())   
                return notify_fail("你现在正忙着呢。\n");
        if( me->is_fighting() )  
                return notify_fail("战斗中进行修炼，好象只有神仙才能做到。\n");
        if ((string)me->query("family/family_name") != "灵鹫宫" )  
                return notify_fail("你现在不是灵鹫宫弟子，不能使用八荒六合唯我独尊功进行修炼！\n");
        if (!me->query("lingjiu/xiulian"))  
                return notify_fail("你没有返老还童，不需要进行修炼！\n");
        if (time()-me->query("lingjiu/last_xiulian_time")<240)
                return notify_fail("八荒六合唯我独尊功每日只能修炼一次，距上次修炼的时间还不足1天！\n");
        me->start_busy(60);
        write("你盘膝而坐，一手指天，一手指地，开始修炼“八荒六合唯我独尊功”....\n");
        me->set("lingjiu/last_xiulian_time",time());
        call_out("end_xiulian",10, me);
        return 1;
}
void end_xiulian( object me )
{
        if ( me->is_busy() ){
                tell_object( me, "你鼻中喷出白烟，缭绕在脑袋四周。......\n");
                call_out("end_xiulian",10,me);
        }
        else{
                int xiulian_times; //完全恢复需要的次数
                string *sname;    //恢复的功夫名称
                int *svalue;
                mapping skill_status;    //灵鹫宫返老还童用

                write("不知过了多久，你的八荒六合唯我独尊功修炼完毕。\n");
                write("你直起腰，深深地吸了一口气，觉得四肢百骸都非常舒服，功力也恢复了一些。\n");
                //恢复功力
                if (me->query("lingjiu/huantong3"))
                        xiulian_times=90;
                else if (me->query("lingjiu/huantong2"))
                        xiulian_times=60;
                else    xiulian_times=30;
                me->add("lingjiu/need_xiulian",-1);
                skill_status=me->query("lingjiu/skill_status");

                sname=keys(skill_status);
                svalue=values(skill_status);
                if (me->query("lingjiu/need_xiulian")<=0) {
                        for(int i=0; i<sizeof(skill_status); i++)
                                me->set_skill(sname[i],svalue[i]+5);
                        me->set("qi",me->query("lingjiu/qi"));
                        me->set("max_qi",me->query("lingjiu/max_qi"));
                        me->set("eff_qi",me->query("max_qi"));
                        me->set("jing",me->query("lingjiu/jing"));
                        me->set("max_jing",me->query("lingjiu/max_jing"));
                        me->set("eff_jing",me->query("max_jing"));
                        me->set("jingli",me->query("lingjiu/jingli"));
                        me->set("max_jingli",me->query("lingjiu/max_jingli"));
                        me->set("neili",me->query("lingjiu/neili"));
                        me->set("max_neili",me->query("lingjiu/max_neili"));
                        me->set("combat_exp",me->query("lingjiu/combat_exp"));
                        //删除不再用的属性
                        me->delete("lingjiu/skill_status");
                        me->delete("lingjiu/qi");
                        me->delete("lingjiu/eff_qi");
                        me->delete("lingjiu/max_qi");
                        me->delete("lingjiu/jing");
                        me->delete("lingjiu/eff_jing");
                        me->delete("lingjiu/max_jing");
                        me->delete("lingjiu/jingli");
                        me->delete("lingjiu/neili");
                        me->delete("lingjiu/max_jingli");
                        me->delete("lingjiu/max_neili");
                        me->delete("lingjiu/combat_exp");
                        me->delete("lingjiu/need_xiulian");
                        me->delete("lingjiu/mud_age");
                        me->delete("lingjiu/xiulian");
                        me->delete("lingjiu/last_xiulian_time");
                }
                else {
                        for(int i=0; i<sizeof(skill_status); i++) 
                                if( sname[i] != "literate") me->set_skill(sname[i], me->query_skill(sname[i],1)+svalue[i]/xiulian_times);
                        me->add("qi",me->query("lingjiu/qi")/xiulian_times);
                        me->add("max_qi",me->query("lingjiu/max_qi")/xiulian_times);
                        me->set("eff_qi",me->query("max_qi"));
                        me->add("jing",me->query("lingjiu/jing")/xiulian_times);
                        me->add("max_jing",me->query("lingjiu/max_jing")/xiulian_times);
                        me->set("eff_jing",me->query("max_jing"));
                        me->add("jingli",me->query("lingjiu/jingli")/xiulian_times);
                        me->add("max_jingli",me->query("lingjiu/max_jingli")/xiulian_times);
                        me->add("neili",me->query("lingjiu/neili")/xiulian_times);
                        me->add("max_neili",me->query("lingjiu/max_neili")/xiulian_times);
                        me->add("combat_exp",me->query("lingjiu/combat_exp")/xiulian_times);
                }
                me->add("mud_age",me->query("lingjiu/mud_age")/xiulian_times);
                me->set("age",14+me->query("mud_age")/3600/24);
        }
        return;
}
