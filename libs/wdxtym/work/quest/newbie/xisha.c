//[lsg 1999//11/25]
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "洗沙");
        set("long", @LONG
  这是杨州野外一处洗沙场，听说老板是外地来的，长得胖胖的，
挺逗人发笑。你可以在这里(xi sha)挣些修为和白银。
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
        "north" : "/d/city/jiaowai9",

]));
	set("item_desc",([
		"【洗沙】" : ZJOBACTS2"洗沙:xi sha\n",
	]));
        setup();
}

void init()
{
        add_action("do_xi","xi");
        add_action("do_ban","dazuo");
        add_action("do_ban","du");
        add_action("do_ban","study");

}

int do_ban()
{
        write ("别打扰人家洗沙啦！\n");
        return 1;
}
int do_xi(string arg)
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;

        if((int)(me->query("combat_exp")) > 500000)
              return notify_fail("乖乖，你的修为太高了，去另谋生路吧。\n");
        if (!arg)
              return notify_fail("你要洗什么？\n");
        if (arg != "sha")
              return notify_fail("这里只能洗沙啦 ，笨蛋。\n");
if (me->is_busy())
return notify_fail("你正忙着呢!\n");
        if( (int)me->query_temp("sha") )
              return notify_fail("你已经在开始洗了。\n");
        if ((int)(me->query("qi")) < 26)
              return notify_fail(RED"气太低，再洗当心把小命送掉，你还是休息一下吧。\n");
        if ((int)(me->query("jing")) < 26)
              return notify_fail(RED"精太低，再洗当心把小命送掉，你还是休息一下吧。\n");
        message_vision("
$N把双手伸进冒着白泡的水中，开始洗沙。\n\n",me);
        me->set_temp("sha",1);
        me->add("qi",-10);
me->start_busy(8);
        call_out("del_sha", 8, me, mon, bonus, exp, pot);
        return 1;
}

void del_sha(object me, object mon, int bonus, int exp, int pot)
{
if (!me) return;
        me->delete_temp("sha");
        if (random (10) < 3)
{
       message_vision(HIR"
$N埋下头来，仔细的洗着金沙，直累得满头大汗，面色苍白,\n
一不小心“咚”的一声掉到洗沙池里，得白干了，老板没要你陪沙就算好的了。\n"NOR,me);
            me->start_busy(5);
        return ;
}
        else
{
        exp = 200 + random(80);
        pot = 100 + random(40);
        message_vision(HIC"
   $N埋头来，仔细的洗着金沙，丝毫不敢大意。\n
半晌之后终于洗好了" + chinese_number(exp) + "斤金沙。\n\n"NOR
  HIB"老板走了过来，对你点点头，顺手给$N一锭银子，说到：“嗯，好。。再接再励”。\n"NOR,me);
        bonus = (int) me->query("combat_exp");
        bonus += exp;
        me->set("combat_exp", bonus);
        bonus = (int) me->query("potential");
        bonus += exp;
        me->set("potential", bonus);
        me->receive_damage ("qi",8 + random(10));
        me->receive_damage ("jing",8 + random(10));
        me->receive_wound ("qi",1);
        me->receive_wound ("jing",1);
        mon = new("/clone/money/silver");
        mon->set_amount(exp/50);
        mon->move(me);
        me->start_busy(5);
        return;
}
}
