inherit F_CLEAN_UP;

int score_cost;

//return 1 if me is allowed to use this command
int check_valid(object me)
{
    return GUIDER_D->check_valid(me,score_cost);
}

int finish(object me)
{
    return GUIDER_D->finish(me,score_cost);
}

int main(object me, string arg)
{
    score_cost = this_object()->get_cost(me);
    if(check_valid(me))
    {
        if(this_object()->exec_cmd(me,arg))
        {
            return finish(me);
        }
		return 1;
    }
    else
    {
        return notify_fail(sprintf("你的新手导师信誉度不足以使用这次命令。需要：%d,拥有：%d\n",score_cost,GUIDER_D->guider_score(me->query("id"))));
    }
    return 0;
}

int check_apprentice(object me,object app)
{
    return GUIDER_D->check_apprentice(me,app);
}