// Room: Lv-Che.c
// Creator : Numa@Sj 00-6-3

#include <ansi.h>
inherit ROOM;

#define OUT "/d/city/xidajie2"
#define FROOM "/d/city/winmo"

void create()
{
        set("short", HIC"车厢内"NOR);
        set("long", @LONG
这是驴车的车厢内，里面干干净净，车厢不住的上下颠簸，想是车走的急
了些。
LONG
	);
	set("no_fight",1);
        setup();
}

void init()
{
        object me = this_player();
        object ob;

        if (!(ob = present("mao shiba",environment(me)))) {
                tell_object(me,HIR"
    突然，外面一阵闪动，茅十八立时跳出车去，你也随即跳了出去。\n"NOR);
                me->move(OUT);
                tell_room(environment(me),"只见"+me->name(1)+"从驴车中跳了出来。\n",({me}));
                tell_object(me,HIB"
    但是，你却怎么也找不见茅十八，只有失望的离开了！\n"NOR);
    		me->delete_temp("mao18");
    		return;
    	}
        call_out("do_arrive", 20, me, ob);
//      if (!me->query_temp("mao18/passed1")) return;
        add_action("do_no",({"no"}));
        add_action("do_yes",({"yes"}));
}

int do_arrive(object me, object ob)
{
	if (!me) return 1;
	if (!me->query_temp("mao18/passed4")) {
                tell_object(me,HIR"
    突然，外面一阵闪动，茅十八立时跳出车去，你也随即跳了出去。\n"NOR);
                me->move(OUT);
                tell_room(environment(me),"只见"+me->name(1)+"从驴车中跳了出来。\n",({me}));
                tell_object(me,HIB"
    但是，你却怎么也找不见茅十八，只有失望的离开了！\n"NOR);
    		me->delete_temp("mao18");
            return 1;
    	}
    	tell_object(me,HIY"
    车子不一会就到了得胜山，你和茅十八跳下车来，却见那山只有七八丈高，不过是个

小丘。\n"NOR);
	me->move(FROOM);
	ob->move(FROOM);
	return 1;
}

int do_no()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed3"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("茅十八都早走了！！\n");
        me->delete_temp("mao18/passed3");
        me->set_temp("mao18/passed4",1);
        tell_object(me,HIR"
    你大声道：“咱们只讲义气，不讲钱财。你送元宝给我，便是瞧我不起。你身上有伤，

我还可以帮忙照料你。”

    茅十八一怔，仰天狂笑，说道：“好极！好极！有点意思！”将元宝收入怀中。\n"NOR);
        return 1;
}

int do_yes()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed3"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("茅十八都早走了！！\n");
        tell_object(me,HIB"
    你窃笑了几声答道：“多谢大爷您赏小人的黄金，小人现在就走！”

    那人哈哈大笑，说道：“看你这小家伙也没什么骨气，赶快滚吧！”\n"NOR);
    	me->move(OUT);
        me->delete_temp("mao18/passed3");
        remove_call_out("do_arrive");
        ob->return_home();
        return 1;
}
