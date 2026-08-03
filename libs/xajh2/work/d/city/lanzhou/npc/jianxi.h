// 一品堂在兰州的奸细   /d/city/npc/jianxi.h
// 包括：
//     妓女 春儿、马倌 梅老三、帐房先生 朱算

void init()
{
    int fshen;
    object ppl = this_player();
    object npc = this_object();
    fshen = ppl->query("negative_score") - ppl->query("positive_score");
    if ( !npc->can_act()
     || npc->is_fighting() )
        return;
    if ( !interactive( ppl ) )
        return;
    if ( ppl->query( "yipin/refuse_join" ) )
        return;
    if ( ppl->IsMemberOf( "yipin" ) )
        return;
    if( fshen < 5000 )
        return;
    if ( ppl->query_xiuwei_by_type( "sword" ) +
        ppl->query_xiuwei_by_type( "blade" ) +
        ppl->query_xiuwei_by_type( "unarmed" ) +
        ppl->query_xiuwei_by_type( "dodge" ) +
        ppl->query_xiuwei_by_type( "short" ) +
        ppl->query_xiuwei_by_type( "long" ) +
        ppl->query_xiuwei_by_type( "whip" ) +
        ppl->query_xiuwei_by_type( "zonggang" ) <= 5000 )
        return;
    remove_call_out( "Fazhan" );
    call_out( "Fazhan", 2, ppl, npc );
    return;
}

void Fazhan( object ppl, object npc )
{
    object obj;
    string name;
    if ( !ppl
     || environment( ppl ) != environment() )
    return;
    switch( name = npc->query( "name" ) )
    {
        case "梅老三"   :
            message_vision( "$N说：“什么时候我也能发笔财就好了！”\n", npc );
            command( "whisper " + ppl->query( "id" ) + " \n"
                + "“嘿嘿，你想不想发财？我这有块帕子，是小巷里面\n"
                + "那家大户人家的。据说如果有个武功高强的人能把\n"
                + "这张帕子送回去，就有大财可发。嘿嘿，我功夫太\n"
                + "差，人家根本就不让我进。怎么样，你跑一趟吧？”\n" );
            ppl->set_temp( "yipin/fazhan_ren", "梅老三" );
            message_vision( "$N给$n一块帕子。\n", npc, ppl );
            break;
        case "朱算"     :
            message_vision( "$N把算盘拨得“哗哗”响，嘴里不住念叨着什么。\n",
                npc );
            message_vision2( "$N突然停下打算盘，说道：“这位$F，帮我个忙好不好"
                + "？把这块帕子送到小巷深处的那户人家去。多谢了！”", npc );
            ppl->set_temp( "yipin/fazhan_ren", "朱算" );
            message_vision( "$N给$n一块帕子。\n", npc, ppl );
            break;
    }
    obj = new( __DIR__"obj/pazi" );
    obj->move( ppl );
    return;
}
