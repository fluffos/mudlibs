// 无量东宗可以做为 master 的 NPC 使用的包含文件

int valid_teach( object you, string skill )
{
    object me;

    if ( !::valid_teach( you, skill ) )
        return 0;
    me = this_object();
    if ( !WULIANG_D->is_benmen_wugong( skill ) )
    {
        notify_fail( me->name() + "有些发怒：这是别派武功，你要学它作甚！\n" );
        return 0; 
    }
    if ( you->query( "master" ) != me->query( "id" ) )
    {
        command( "? " + you->query( "id" ) );
        notify_fail( me->name() + "说：有谁让你来找我学武功的吗？\n" );
        return 0;
    }
    if ( !me->query_jibie( skill ) )
    {
        notify_fail( me->name() + "不愿意教你这项技能。\n");
    }
    return 1;
}

int win_bihua( object you )
{
    if ( you->query_temp( "fight_master" ) )
    {
        you->delete_temp( "fight_master" );
        command( "say 你才会这几下子就想不跟我学了，没门！！！" );
    }
    else
        command( "say 你还需多加努力才是！" );
    return 1;
}

int lose_bihua( object you )
{
    if ( you->query_temp( "fight_master" ) )
    {
        you->set( "defeat_master", 1 );
        you->save();
        command( "chat* admire " + you->query( "id" ) );
        if ( query( "id" ) != "zuo zimu" )
            command( "say 厉害，你打赢了我，回去报告掌门人吧！" );
        else
        {
            you->set( "掌门/permit", 1 );
            command( "say 你武功已至如此境界，看来足以领悟悟剑居中本派的武学精华。\n" );
        }
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////////
// Internal Function



