string my_zuzhi()
{
    return "longmen";
}

int accept_apprentice( object player )
{
    return 0;
}

int accept_betray( object player )
{
    return 0;
}

int accept_chushi( object player )
{
    return 0;
}

int accept_teach( object you, string skill )
{
    object me;

    me = this_object();

    if ( !SKILL_D( skill )->valid_learn( you ) )
    {
        return 0;
    }

    if ( !me->IsMemberOf(my_zuzhi()) )
    {
        command( "? " + you->query( "id" ) );
        tell_object(you, me->name() + "说：有谁让你来找我学武功的吗？\n" );
        return 0;
    }

    if ( !me->query_jibie( skill ) )
    {
        tell_object(you, me->name() + "不愿意教你这项技能。\n");
        return 0;
    }

    if ( me->ZuzhiTouxianJibie(my_zuzhi()) > you->ZuzhiTouxianJibie(my_zuzhi()) + 1 )
    {
        command( "? " + you->query( "id" ) );
        tell_object(you, me->name() + "说：有谁让你来找我学武功的吗？\n" );
        return 0;
    }

    return 1;
}

int win_bihua( object you )
{
    if ( you->query_temp( "qintianbiao/fight_master" ) == this_object()->ZuzhiTouxianJibie(my_zuzhi()) )
    {
        you->delete_temp( "qintianbiao/fight_master" );
        command( "say 呵呵，你想混到我这个位置，现在还是不行的！！！" );
    }

    command( "say 你还需多加努力才是！" );
    return 1;
}

int lose_bihua( object you )
{
    if ( you->query_temp( "qintianbiao/fight_master" ) == this_object()->ZuzhiTouxianJibie(my_zuzhi()) )
    {
        you->set_temp( "qintianbiao/defeat_master", this_object()->query("name") );
        command( "chat* admire " + you->query( "id" ) );
        command( "say 厉害，你打赢了我，回去报告总镖头吧！" );
    }

    return 1;
}

int zhongcheng( object me, string skill )
{
    object master = this_object();
    int dengji, jibie, score;

    if ( skill == "literate" )
    {
        return 1;
    }

    if ( master->query("can_teach") )
    {
        return 1;
    }

    dengji = SKILL_D( skill )->query_dengji();
    if ( !dengji )
    {
        dengji = 1;
    }

    jibie = me->query_jibie( skill );

    score = me->ZuzhiScore(my_zuzhi());

    if ( !jibie && score < dengji )
    {
        return 0;
    }

    if ( score < jibie * dengji )
    {
        return 0;
    }

    return 1;
}

