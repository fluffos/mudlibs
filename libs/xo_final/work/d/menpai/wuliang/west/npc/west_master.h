// 无量西宗可以做为 master 的 NPC 使用的包含文件
int can_apprentice( object me )
{
    if ( me->query("west/master") == this_object()->query("id") )
    {
        return 1;
    }

    return 0;
}

int win_bihua( object you )
{
    if ( you->query_temp( "west/fight_master" ) )
    {
        you->delete_temp( "west/fight_master" );
        command( "say 你才会这几下子就想不跟我学了，没门！！！" );
    }
    else
    {
        command( "say 你还需多加努力才是！" );
    }

    return 1;
}

int lose_bihua( object you )
{
    if ( you->query_temp( "west/fight_master" ) == query("id") )
    {
        you->set( "west/defeat_master", query("id") );
        you->save();
        command( "chat* admire " + you->query( "id" ) );
        command( "say 厉害，你打赢了我，回去报告掌门人吧！" );
    }
    return 1;
}

int family_quest(object me)
{ 
    return OLD_QUEST_D->give_oldquest(me, this_object());
}

int have_family_quest(object me)
{
    return OLD_QUEST_D->have_oldquest(me, this_object());
}

void done_family_quest(object me)
{
    OLD_QUEST_D->done_oldquest(me, this_object());
}

void cancel_family_quest(object me)
{
    return OLD_QUEST_D->cancel_oldquest(me, this_object());
}

