// vote chblk
// Modified by iszt@pkuxkx, 2007-03-11

#include <vote.h> 
#include <ansi.h>

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
        int reason; // vote for what?
        int vv; // valid voter numbers
        int vc; // vote count;
        int df;
        string *juror, my_id;
        object user;
        if (me == victim)
        {
                if(random(2))
                        me->add("vote/abuse", 10);
                return notify_fail("你不是开玩笑吧？当心被剥夺表决权！\n");
        }

        if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_XIUXIAN))
        {
                return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
        }

        if( !victim->query("xiuxian_player") ) 
        {
                return notify_fail(victim->name()+"并不是休闲玩家。\n");
        }

        if (reason <= 0)
        {
                victim->set("vote/reason", (int)V_XIUXIAN); 
        }
        
        my_id = me->query("id");

        // dont allow me to vote twice for the same issue
        juror = victim->query("vote/juror");

        if( !pointerp(juror) )
        {
                victim->set("vote/juror", ({ my_id }) );
        }
        else if( member_array(my_id, juror) == -1 ) 
        {
                victim->set("vote/juror", juror+({ my_id }) );
        }
        else
        {
                me->add("vote/abuse", 10);
                return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
        }
        user=me->query_temp("link_ob");
        vv = 50;  
        if(wizardp(me))
        {
            //不要在代码中加入任何ID判断 -- Jason
            vc = victim->add("vote/count", 5);
        }
        else if (user&&user->query("realuser_verified"))
            vc = victim->add("vote/count", 1);
        else
            vc = victim->query("vote/count");
        
        df = vv - vc;

        if (df>1)
        {
                shout( HIG "【表决】"+me->name()+HIG+"("+me->query("id")+")"
                +"投票关闭" +victim->name()+HIG+"("+victim->query("id")+")"
                +"的休闲玩家资格，还差"+sprintf("%d", df)+"票。\n" NOR);
                victim->apply_condition("vote_clear", 10);
        }
        else 
        {
                shout( HIG "【表决】"+me->name()+HIG+"("+me->query("id")+")"
                +"投票关闭" +victim->name()+HIG+"("+victim->query("id")+")"
                +"的休闲玩家资格。"+victim->name()+HIG+"变为正常玩家，100天内禁止转变成休闲玩家！\n" NOR);
                victim->apply_condition("vote_clear", -10);
                victim->delete("xiuxian_player");
                victim->set("xiuxian_abuse", time()+100*24*3600);
        }

        return 1;
}
