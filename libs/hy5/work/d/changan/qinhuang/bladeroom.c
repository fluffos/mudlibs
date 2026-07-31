inherit ROOM;
int do_xue(string arg);
void create()
{
    set("short", "刀俑");
    set("long", @LONG
自己站在长长的白玉石阶之底，石阶直通向上方那六丈来高、十里
来宽的巨大平台。仰头望去，广阔的黑色顶穹缀满了千万颗宝石、明珠，
光彩夺目，璀璨似星河，浩瀚如夜空，将四周照得一片皎皎明亮。在那
瑰丽的顶穹下方，赫然竟是一座拔地而起、连天入穹的雄伟宫城。那巍
峨壮丽的城楼殿宇，钩心斗角的流檐飞瓦，绵延雄矗于白玉石台上，如
泰山压顶，竟比长安城楼还要气势磅礴、雄奇瑰丽！石阶两边的广场上，
密密麻麻竟全是列成方阵的兵俑。铜人、陶俑、石雕……交相陈杂，少
说也有几万之众，军姿雄壮，威风凛凛。广场上，一条条银带蜿蜒交错，
闪耀着炫目的光泽，就像是江河汇集，一齐朝东面一个白光闪闪的水池
流去。
这里的陶俑手里都拿着刀，摆着各种姿势，神态各异。
LONG
    );
    set("exits", ([
           "east":__DIR__"shidao3",
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

    if ( me->is_busy())
        return notify_fail("你正在忙！\n");

    me->receive_damage("jing", me->query("jing")/10);
    message_vision("$N开始模仿学习这些秦俑的各种动作。\n", me);
    me->start_busy(2);
    if ( (int)me->query_skill("blade", 1) < 601)
    {
        me->improve_skill("qinhuang/blade", me->query_int());
        //me->set("blade",1);
        return 1;
    }
    write("你对着秦俑瞧了一回儿，发现已经没有什么好学的了。\n");
    return 1;
}
