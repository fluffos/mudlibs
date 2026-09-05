// caishen.h  采参
//Modified by Vast@Pkuxkx

#include <ansi.h>

void init()
{
//        this_player()->delete_temp("cbshen");
        add_action("do_search", "tan");
        add_action("do_search", "search");
        add_action("do_dig", "wa");
//        add_action("do_dig", "dig");
}

int do_search(string arg)
{
        object me, ob;

        if( !arg || !(arg == "参" || arg == "人参") )
				{
                write("你要搜索什么？\n");
								return 1;
				}

        me = this_player();

        if( me->is_fighting() || me->is_busy() )
                {write("你现在正忙着呢。\n");;return 1;}

        if( me->query_temp("cbshen/参1") )
                {write("你不是已经找到人参了吗？\n");;return 1;}

       if( !objectp(ob = present("suobo gun", me)) || !ob->query("equipped"))
                {write("你没有装备索拨棍，无法拨开灌木山草寻找人参！\n");;return 1;}

        if( (int)me->query("jingli") < 80 )
                {write("你太累了，先歇息一会儿吧。\n");;return 1;}

        me->add_temp("cbshen/times", 1);
        if(random(me->query_temp("cbshen/times")) > 20) me->set_temp("cbshen/times", 0);
        me->add("jingli", - 10);
        me->start_busy(4);

	message_vision("$N用索拨棍拨打着四周的灌木杂草，希望能从中发现人参的踪迹！\n", me);

	call_out("result", 3, me);

        return 1;
}

int do_dig(string arg)
{
        object me, ob;

        if( !arg || !(arg == "参" || arg == "人参") )
                {write("你要挖什么？\n");;return 1;}

        me = this_player();

        if( me->is_fighting() || me->is_busy() )
                {write("你现在正忙着呢。\n");;return 1;}

        if( !objectp(ob = present("lugu qianzi", me)) || !ob->query("equipped"))
		{write("你没有装备鹿骨钎子，无法将人参从土中起出！\n");;return 1;}

        if( (int)me->query("jingli") < 80 )
                {write("你太累了，先歇息一会儿吧。\n");;return 1;}

        me->add("jingli", - 10);
        me->start_busy(2);

        if( !me->query_temp("cbshen/参1") )
        {
        	me->add_temp("cbshen/wa", 1);
        	if(me->query_temp("cbshen/wa") > 5)
        	{
                	message_vision("$N拿着鹿骨钎子使劲的挖着土，忽听嘎巴一声，钎子断为两截！\n", me);
                	ob->unequip();
                	destruct(ob);
                	me->set_temp("cbshen/wa", 0);
                }
                else
                message_vision("$N拿着鹿骨钎子使劲的挖着土，不知道在找什么宝贝。\n", me);
                return 1;
        }

        add("count", -1);

        message_vision(HIY"$N从怀中掏出一把鹿骨钎子，小心翼翼的把植被从土中起出！\n"NOR, me);
        me->delete_temp("cbshen/参1");

        switch(random(3))
        {
        	case 0:
        	ob = new(__DIR__"obj/sanqi");
        	tell_object(me, "你大失所望：原来这只不过是一颗" + ob->name() + "。\n");
        	break;
        	case 1:
        	ob = new(__DIR__"obj/yinyang-cao");
        	tell_object(me, "你大失所望：原来这只不过是一颗" + ob->name() + "。\n");
        	break;
        	case 2:
        	ob = new(__DIR__"obj/cb_renshen");
        	tell_object(me, "你兴高采烈：原来这正是一颗" + ob->name() + "。\n");
        	message_vision("$N不禁高兴的跳了起来，高声喊道：棒——槌——！" +
                       "声音远远传了开去，在大山中回荡，久久不散！\n", me);
        	break;
        }
	ob->move(me);

        return 1;
}

int result(object me)
{
	object ob;
	int power;
	string *beast = ({__DIR__"npc/cb_fox",
			  __DIR__"npc/cb_xiong",
			  __DIR__"npc/cb_laohu"});

        if( query("count") < 1 && (int)me->query_temp("cbshen/times") > 20 )
        {
		tell_object(me, "\n你用索拨棍拨打着四周的灌木杂草，可是没发现有人参的踪迹！\n不过你觉得继续努力也许会有新的发现！\n");
		return 1;
	}

        power = (int)me->query_temp("cbshen/times") * (int)me->query("kar");
        power *= query("count");

        if( random(power) > 100 ) {
                me->set_temp("cbshen/参1", 1);
                message_vision(HIG"\n$N用棍子不断的拨打着四周的山草，忽然发现杂草之中有一株植物！\n"NOR, me);
                write("直觉告诉你这也许就是一株人参哦，赶快挖(wa)呀！\n");
                return 1;
	}

	if(query("beast") > 0 && random(me->query("kar")) < 5 )
	{
		ob = new(beast[random(sizeof(beast))]);
		message_vision(HIY"\n结果$N却惊出了一头正在休息的" + ob->name() + "！\n"NOR, me);
		ob->move(this_object());
		ob->kill_ob(me);
		add("beast", -1);
		return 1;
	}

	if(query("count") < 1)
	{
		add("count", -1);
		if(query("count") < -20) set("count", random(5) + 1);
	}

	tell_object(me, "\n你用索拨棍拨打着四周的灌木杂草，可是没发现有人参的踪迹！\n不过你觉得继续努力也许会有新的发现！\n");

	return 1;
}