// junquest_song
// Updated by Lonely

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{      
        object room, jiang;  
        string temp;
        int liangcao;
        mapping jiangjun;

        room = environment(me);
 
        if (duration < 1) return 0;

        if (me != WAR_D->query_king())
        {
                me->apply_condition("junquest_song", 0);
                return 0;
        }

        if ((time() - me->query_temp("jun_quest/last_jiang")) > 600)
        {
                jiangjun = me->query_temp("jun_quest/jiang");

                temp = read_file("/quest/quest_jun/song/liangcao", 1, 1);
                liangcao = atoi(temp);
                if (! jiangjun || sizeof(jiangjun) < me->query("degree_jungong") * 2)         
                if (liangcao > 300 && objectp(room)
                && file_name(room) == "/quest/quest_jun/sying1")
                {
                        me->set_temp("jun_quest/last_jiang", time());
                        tell_object(me,
                                    HIR "新征一批的宋军到了，赶快加紧训练吧！！！\n" NOR); 
                        liangcao = liangcao - 50;
                        temp = sprintf("%d", liangcao);
                        write_file("/quest/quest_jun/song/liangcao", temp, 1);
                        jiang = new("/quest/quest_jun/song/songb");
                        jiang->move(room);
                        jiang->change_ob();
                }
        }

        if (duration == 1)  
        {
                WAR_D->remove_enemy();     
                tell_object(me, HIR "蒙古大军久攻不下，终于撤军了！！！\n" NOR);
                tell_object(me, HIR "恭喜你胜利完成此次出征任务，击败来犯蒙军实乃我朝之栋梁啊！！！\n" NOR);    
                WAR_D->give_bouns();
        }
        me->apply_condition("junquest_song", duration - 1); 

        return CND_CONTINUE;      
}


