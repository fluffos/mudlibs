// rank 江湖同道给rank_info,chat里的尊称，大家评选比自吹自擂要合适多了。
#include <ansi.h>
inherit F_CLEAN_UP;

int valid_voters(object me);

string de_color(string rank)
{
    rank=replace_string(rank,"$GRN$",GRN);
    rank=replace_string(rank,"$RED$",RED);
    rank=replace_string(rank,"$YEL$",YEL);
    rank=replace_string(rank,"$BLU$",BLU);
    rank=replace_string(rank,"$CYN$",CYN);
    rank=replace_string(rank,"$MAG$",MAG);
    rank=replace_string(rank,"$WHT$",WHT);
    rank=replace_string(rank,"$HIG$",HIG);
    rank=replace_string(rank,"$HIR$",HIR);
    rank=replace_string(rank,"$HIY$",HIY);
    rank=replace_string(rank,"$HIB$",HIB);
    rank=replace_string(rank,"$HIC$",HIC);
    rank=replace_string(rank,"$HIM$",HIM);
    rank=replace_string(rank,"$HIW$",HIW);
    rank+=NOR;
    return rank;
}

int main(object me, string arg)
{
    string id,rank;
    string *voters;
    object pl;
    int votes;

    voters=STATISTIC_D->query("rank_vote/voters");
    if (voters)
    {
        if (member_array(me->query("id"),voters)!=-1)
        return notify_fail("你已经投过一票了！\n");
    }
    else
    {
        voters=({});
    }
    if ((int)me->query("combat_exp")-(int)me->query("vote_rank_exp")<(int)me->query("combat_exp")/100&&(int)me->query("combat_exp")-(int)me->query("vote_rank_exp")<100000)
    {
        return notify_fail("你不是一个合法的投票者！\n");
    }
    if (!arg)
    {
        return notify_fail("投票选出某人的rank，指令是rank <某人> <某rank>，如果此人正被江湖同道投票rank，直接附议rank <某人>。\n");
    }
    else if (sscanf(arg, "%s %s", id, rank)==2)
    {
        if (!pl=find_player(id))
        {
            return notify_fail("你只能投票选出在线玩家的rank。\n");
        }
        if (pl==me)
        {
            return notify_fail("哪有给自己自吹自擂的道理啊。\n");
        }
        if(!me->visible(pl)) 
        {
            return notify_fail("你只能投票选出在线玩家的rank。\n");
        }
        if (STATISTIC_D->query("rank_vote/be_vote")&&pl->query("id")!=STATISTIC_D->query("rank_vote/be_vote"))
        {
            return notify_fail("现在正在给"+STATISTIC_D->query("rank_vote/be_vote")+"封衔。\n");
        }
        if (time()-(int)pl->query("be_ranked")<604800)//至少7天重新取
        {
            return notify_fail(pl->query("name")+"刚被选出rank不久，稍迟再给新的rank吧。\n");
        }
        if (pl->query_temp("being_ranked"))
        {
            if (rank!="-a")
            {
                return notify_fail("现在"+pl->query("name")+"正被江湖同道商议加衔"+pl->query_temp("being_ranked")+"，你要么附议，要么等之后再提出新的rank。\n");
            }
            else
            {
                votes=valid_voters(me);
                votes=votes/3;
                pl->add_temp("rank_vote",-1);
                me->set("vote_rank_exp",me->query("combat_exp"));
                voters+=({me->query("id")});
                STATISTIC_D->set("rank_vote/voters",voters);
                CHANNEL_D->do_channel(this_object(), "jh", HIW + pl->query("name")+HIW+"被提议，尊称“"+pl->query_temp("being_ranked")+HIW+"”，"+me->query("name")+HIR+"反对"+HIW+"。", -1);
                CHANNEL_D->do_channel(this_object(), "jh", HIW + "尚需"+chinese_number(votes-(int)pl->query_temp("rank_vote"))+"人附议。(附议请输入：rank "+pl->query("id")+"\t反对请输入：rank "+pl->query("id")+" -a)", -1);
                if ((int)pl->query_temp("rank_vote")<-5)//提议取消
                {
                    CHANNEL_D->do_channel(this_object(), "jh", HIW + pl->query("name")+HIW+"被提议，尊称“"+pl->query_temp("being_ranked")+HIW+"”，因众人反对，提议取消。", -1);
                    pl->delete_temp("rank_vote");
                    pl->delete_temp("being_ranked");
                    STATISTIC_D->clear_vote(1);
                }
                return 1;
            }
        }
        else
        {
            if (rank=="-a")
            {
                return notify_fail("-a参数是rank的反对指令，必须有人首倡rank之后，才可以使用-a反对。\n");
            }
            if (strwidth(rank)>24)
            {
                return notify_fail("太长了，哪有人有这么长的尊称？\n");
            }
            rank=de_color(rank);
            pl->set_temp("being_ranked",rank);
            pl->add_temp("rank_vote",1);
            me->set("vote_rank_exp",me->query("combat_exp"));
            voters+=({me->query("id")});
            STATISTIC_D->set("rank_vote/first_advisor",me->query("id"));
            STATISTIC_D->set("rank_vote/voters",voters);
            STATISTIC_D->set("rank_vote/be_vote",pl->query("id"));
			STATISTIC_D->set("rank_vote/vote_expire",time()+1800);
            CHANNEL_D->do_channel(this_object(), "jh", HIW + pl->query("name")+HIW+"在江湖中声望日重，"+me->query("name")+HIW+"提议，江湖中人称其一声“"+rank+HIW+"”，如果附议，请rank "+pl->query("id")+"。", -1);
            return 1;
        }
    }
    else if (sscanf(arg, "%s", id)==1)
    {
        if (!pl=find_player(id))
        {
            return notify_fail("你只能投票选出在线玩家的rank。\n");
        }
        if (pl==me)
        {
            return notify_fail("哪有给自己自吹自擂的道理啊。\n");
        }
        if(!me->visible(pl)) 
        {
            return notify_fail("你只能投票选出在线玩家的rank。\n");
        }
        if (!pl->query_temp("being_ranked"))
        {
            return notify_fail("附议？当前并无对"+pl->query("name")+"的rank要求。\n");
        }
        if (STATISTIC_D->query("rank_vote/be_vote")&&pl->query("id")!=STATISTIC_D->query("rank_vote/be_vote"))
        {
            return notify_fail("现在正在给"+STATISTIC_D->query("rank_vote/be_vote")+"封衔。\n");
        }
        pl->add_temp("rank_vote",1);
        me->set("vote_rank_exp",me->query("combat_exp"));
        voters+=({me->query("id")});
        STATISTIC_D->set("rank_vote/voters",voters);
        CHANNEL_D->do_channel(this_object(), "jh", HIW + pl->query("name")+HIW+"被提议，尊称“"+pl->query_temp("being_ranked")+HIW+"”，"+me->query("name")+HIW+"附议。", -1);
        votes=valid_voters(me);
        votes=votes/3;
        if ((int)pl->query_temp("rank_vote")>=votes)
        {
            CHANNEL_D->do_channel(this_object(), "jh", HIW + "大家一致认为，" + pl->query("name")+HIW+"应该被尊称一声“"+pl->query_temp("being_ranked")+HIW+"”，从此江湖中人都这样称呼其。", -1);
            pl->set("rank_giver",STATISTIC_D->query("rank_vote/first_advisor"));
			STATISTIC_D->clear_vote(1);
            pl->set("rank_info/respect",pl->query_temp("being_ranked"));
            pl->delete_temp("being_ranked");
            pl->delete_temp("rank_vote");
            pl->set("be_ranked",time());
            tell_object(pl,HIG+"你从此在江湖中被人尊称"+pl->query("rank_info/respect")+HIG+"。\n"+NOR);
        }
        else
        {
            CHANNEL_D->do_channel(this_object(), "jh", HIW + "尚需"+chinese_number(votes-(int)pl->query_temp("rank_vote"))+"人附议。(附议请输入：rank "+pl->query("id")+"\t反对请输入：rank "+pl->query("id")+" -a)", -1);
        }
        return 1;
    }
    else
    {
        return notify_fail("投票选出某人的rank，指令是rank <某人> <某rank>，如果此人正被江湖同道投票rank，直接附议rank <某人>。\n");
    }
}

int valid_voters(object me)
{
        object *list;
        int d = 0;
        int j;

        list = users();
        j = sizeof(list);
        while( j-- )
        {
                // Skip those users in login limbo.
                if (list[j]->query("combat_exp")-list[j]->query("vote_rank_exp")<100000) continue;
                if (list[j]->query("combat_exp")-list[j]->query("vote_rank_exp")<list[j]->query("combat_exp")/100) continue;
                if( !environment(list[j]) ) continue;
                if( !me->visible(list[j]) ) continue;
                if ((int)list[j]->query("antirobot/deactivity") > 3) continue;//不fullme玩家不计入，这样就不会出现挂机太多，没人投票的情况。
                d++;
        }
        return d;
}

int help(object me)
{
	write(@HELP
用这个指令可以推举江湖中某人的尊称。如果你是首倡者，命令是
rank <玩家id> <rank名>，比如 rank abc 大黄牛，支持颜色控制
符，可用颜色同nick。如果是跟投，只用rank abc即可。如某人提
议的rank超过你的接受程度，可使用rank abc -a反对。

HELP
);
        return 1;
}