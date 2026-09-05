inherit ROOM;
void create()
{
        set("short", "大门");
        set("long",
             "这就是闻名天下的『白驼山庄』的大门。大门梁上雕龙刻凤，美\n"
         "奂美仑，不知凝聚着多少能工巧匠的心血。更显出庄主的富有与显贵。\n"
         "门前左右各蹲着一只威武庄严的石狮子。\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
                "north" : __DIR__"yuanzi",
                "southdown" : __DIR__"shijie",
        ]));
        set("objects",([
                __DIR__"npc/menwei" : 2,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if ( dir != "north" || me->query("shen") < 300 )
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "men wei" )
            return notify_fail("门卫把手一拦：你这种正派人物，老子一看就恶心，快滚！\n");
    }
    return ::valid_leave(me, dir);
}
