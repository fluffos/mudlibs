//碎石路
//by male

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"碎石路"NOR);
    set("long", @LONG
从这里你已经可以看到风波亭了,但是自从岳飞父子死后,百姓总是自发聚到风波亭
纪念岳王爷,抨击时政,现在官府已经把风波亭查封了,谁也进不去。
LONG
       );
    set("outdoors", "yuewangmu");

    set("exits", ([
                "west" : __DIR__"xiaodao3",
                "east" : __DIR__"fengboting",
                ]));

    set("objects", ([
                __DIR__ + "npc/daneigaoshou" : 10,
                ]));
    setup();
}
int valid_leave(object me, string dir)
{
    object *ob;
    int i;
    int kill = 0;

    if( dir != "east" )
        return ::valid_leave(me, dir);
    if( !userp(me) && !me->query("is_huoji"))
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++)
    {
        if( living(ob[i]) && ob[i]->query("id") == "danei gaoshou" )
        {
            if (me->query("combat_exp")>3000000)
            ob[i]->kill_ob(me);
            kill = 1;
//            break; //added by iszt@pkuxkx, 2006-11-29
        }
    }
    if ( kill ) return notify_fail("大内高手大叫道:竟敢擅闯风波亭?看我不宰了你!\n");
    return ::valid_leave(me, dir);
}

