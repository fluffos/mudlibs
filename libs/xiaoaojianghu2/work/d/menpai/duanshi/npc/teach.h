//teach.h 用来不允许ppl在本门派中随便的请教

int valid_teach( object you, string skill )
{
    object me=this_object();

    if ( !::valid_teach( you, skill ) )
        return 0;

    if ( (!you->query("family/master_id")) || (you->query("family/master_id")!=me->query("id")) )
    {
        command( "? " + you->query( "id" ) );
    	command( "say “你怎么不去找自己师傅请教功夫啊？本府上最忌讳自己偷学武功。”");
        return 0;
    }        

    if ( you->query("class_score/镇南王府") < me->query("class_score/镇南王府") )
    {
        command( "angry " + you->query( "id" ) );
        command( "say “你最近是不是对府里交代的事情很不上心啊？看看你这个样子！”");
        return 0;
    }
                        
    return 1;
}

 