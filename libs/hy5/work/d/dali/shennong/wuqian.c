// 小屋前 /d/menpai/shennong/wuqian.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{
    set("short",    "小屋前");
    set("long", @LONG
你来到一个不大的小屋前。屋子是茅草做成的，很有风一吹就会倒的感觉。
屋前乱七八糟的放着些杂物，似乎是好久没人来过了。小路继续向上延伸，绕
过小屋，一直通向山顶。
LONG
    );
    set("exits",    ([  /*sizeof()==3*/
        "eastup"    :   __DIR__"dong_shanao",
        "enter"     :   __DIR__"xiaowu",
        "westdown"  :   __DIR__"shanxi",
    ]) );
    set("objects",  ([
        __DIR__"npc/bangzhong"  :   2,
    ]) );
    set("outdoors", "wuliang");
    setup();
}

int valid_leave(object ppl, string dir)
{
    object npc, here = this_object();

    if( !npc = present( "bang zhong", here ) )
        return ::valid_leave(ppl, dir);
    if( living(npc) 
     && dir != "westdown" )
    {
        if( ppl->query("family/family_name") == "神农帮" )
        {
            message_vision( "$N对$n招呼道：“回来啦，辛苦～～”\n", 
                npc, ppl );
            return ::valid_leave(ppl, dir);
        }
        if( !ppl->query("family/family_name") )
        {
            message_vision( "$N斜眼看了看$n：“嗬，又来个拜帮主为师的～～”\n", 
                npc, ppl );
            return ::valid_leave(ppl, dir);
        }
        return notify_fail( "神农帮帮众伸手一拦，喝道：“什么人？来干什么？”\n" );
    }
    if( living(npc) 
     && !ppl->query("family/family_name") 
     && !ppl->query_temp("CanPass") )
        return notify_fail( "神农帮帮众冷笑一声：“怎么的？来了不拜师还想走？！”\n" );
    return ::valid_leave(ppl, dir);
}    
