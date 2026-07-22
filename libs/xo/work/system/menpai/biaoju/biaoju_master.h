// 镖局的师傅们教不教武功的凭证

int valid_teach( object you, string skill )
{
    object me;
    string f_name;

    if ( !::valid_teach( you, skill ) )
        return 0;
    me = this_object();
    if ( !BIAOJU_D->is_benmen_wugong( skill ) )
    {
        notify_fail( me->name() + "有些不解：镖局中有人会这门武功吗？\n" );
        return 0; 
    }
    if ( !you->query( "biaoju_dizi" ) )
    {
        command( "? " + you->query( "id" ) );
        notify_fail( me->name() + "说：有谁让你来找我学武功的吗？\n" );
        return 0;
    }
    else
    {
        f_name = you->query( "family/family_name" );
        if ( f_name == "蓬莱派" &&
            f_name != this->query( "family/family_name" ) )
        {
            command( ":)" );
            notify_fail( me->name() + "说道：你既然已是蓬莱派的弟子了，我就不好再传授你我派的武功了。\n" );
            return 0;
        }
    }
    if ( !me->query_jibie( skill ) )
    {
        return notify_fail( me->name() + "不愿意教你这项技能。\n");
    }
    return 1;
}

int win_bihua( object you )
{
    if ( you->query_temp( "fight_master" ) )
    {
        you->delete_temp( "fight_master" );
        command( "say 呵呵，你想混到我这个位置，现在还是不行的！！！" );
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
        command( "say 厉害，你打赢了我，回去报告总镖头吧！" );
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////////
// Internal Function



