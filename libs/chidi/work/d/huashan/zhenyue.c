// zhenyue.c
inherit ROOM;
void create()
{
    set("short", "镇岳宫");
    set("long", @LONG
这里地势略为平坦，上、下山的游客多在此稍作休息再继续前行。附
近有几间简陋的旅社，欲登东峰观日出者，大都于头晚歇息于此。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
        "westup" : __DIR__"canglong",
        "southwest" : __DIR__"chaoyang",
        "eastup" : __DIR__"yunu",
        "northdown" : __DIR__"husun",
    ]));
    set("objects", ([ 
        __DIR__"npc/gao" : 1,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    setup();
}
 
int valid_leave(object me, string dir)
{
    object ob;
    ob=present("gao genming", environment(me));
    if (dir != "northdown" && objectp(ob) && living(ob) )
        if(mapp(me->query("family")) && me->query("family/family_name") !="华山派")
        if(me->query("combat_exp") >= 1000)
        if( !wizardp(me) )
        return notify_fail("高根明喝道：后面是本派重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
    return ::valid_leave(me, dir);
}
