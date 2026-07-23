// 镖局的师傅们教不教武功的凭证

int valid_teach( object you, string skill )
{
    object me;

    me = this_object();
    if ( !SKILL_D( skill )->valid_learn( you ) )
        return 0;

    if ( you->query( "family/family_name" ) != "龙门镖局" )
    {
        command( "? " + you->query( "id" ) );
        notify_fail( me->name() + "说：有谁让你来找我学武功的吗？\n" );
        return 0;
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


int zhongcheng( object me, string skill )
{
    int dengji, jibie, zhongchen;
    dengji = SKILL_D( skill )->query_dengji();
    if( !dengji ) dengji = 1;
    jibie = me->query_jibie( skill );
    if ( SKILL_D( skill )->query_level() )
        dengji = SKILL_D( skill )->query_level();
    switch ( dengji )
    {
        case 1 : zhongchen = jibie * 10 / 6;        break;
        case 2 : zhongchen = 100 + jibie * 10 / 6;  break;
        case 3 : zhongchen = 200 + jibie * 10 / 6;  break;
        case 4 : zhongchen = 300 + jibie * 20 / 6;  break;
        case 5 : zhongchen = 500 + jibie * 30 / 6;  break;
        case 6 : zhongchen = 800 + jibie * 50 / 6;  break;
        case 7 : zhongchen = 1300 + jibie * 80 / 6; break;
        case 8 : zhongchen = 2100 + jibie * 130 / 6; break;
        case 9 : zhongchen = 3400 + jibie * 210 / 6; break;
        case 10 : zhongchen = 5500 + jibie * 340 / 6; break;
        default : zhongchen = jibie * 20 / 6; break;
    }
    if ( zhongchen <= me->query( "class_score/" + me->query( "family/family_name" ) ) )
        return 1; 
    else
        return 0;
}



