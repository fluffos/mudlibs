//code by system_3 
 int valid_leave(object me, string dir)
{
       string nature;
     nature = NATURE_D->room_event_fun();
        if ( dir == "east" && userp(me) )
     {
    if(me->query_temp("paid_money_bing") )
    {
    me->delete_temp("paid_money_bing");
    return ::valid_leave(me, dir);
    }
if((objectp(present("guan bing", environment(me))) || objectp(present("wu jiang", environment(me)))) && (nature=="event_dawn"||nature=="event_night"||nature=="event_midnight"))
{
return notify_fail("守城官军双手一拦说道：城门已经关了，要进城等明天吧。\n");
}
}
 return ::valid_leave(me, dir);
}
