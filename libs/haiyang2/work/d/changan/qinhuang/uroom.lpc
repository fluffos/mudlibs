inherit ROOM;
int do_xue(string arg);
void create()
{
    set("short", "拳俑");
    set("long", @LONG
这里的陶俑都手无寸铁，摆着各种搏击格斗的姿势，神态各异。
LONG
    );
    set("exits", ([
        "west":__DIR__"shidao2",
    ]));
    setup();
}
void init()
{
    add_action("do_xue", "kan");
}


int do_xue(string arg)
{
    object me;
    me = this_player();
    if ( !arg || ( arg != "俑" ) )
        return notify_fail("什么？\n");
    if ( (int)me->query_skill("literate", 1) < 1)
        return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if ( (int)me->query("jing") < 50)
        return notify_fail("你的精不够！\n");

    if(me->query("qinhuang/hammer")) return notify_fail("你已经学过锤俑了。\n");
    if(me->query("qinhuang/sword")) return notify_fail("你已经学过剑俑了。\n");
    if(me->query("qinhuang/club")) return notify_fail("你已经学过棍俑了。\n");
    if(me->query("qinhuang/blade")) return notify_fail("你已经学过刀俑了。\n");
    if(me->query("qinhuang/whip")) return notify_fail("你已经学过鞭俑了。\n");
    if(me->query("qinhuang/staff")) return notify_fail("你已经学过杖俑了。\n");
    if(me->query("qinhuang/throwing")) return notify_fail("你已经学过箭俑了。\n");
    if(me->query("qinhuang/axe")) return notify_fail("你已经学过斧俑了。\n");
    me->receive_damage("jing", me->query("jing")/10);
    message_vision("$N开始模仿学习这些秦俑的各种动作。\n", me);
    if ( (int)me->query_skill("unarmed", 1) <601)
    {
        me->improve_skill("unarmed", me->query_int());
        me->set("qinhuang/unarmed",1);
        return 1;
    }
    write("你对着秦俑瞧了一回儿，发现已经没有什么好学的了。\n");
    return 1;
}
