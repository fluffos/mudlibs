// Room: /d/city/dongxiangfang.c

#define CAR_ROOM "/d/city/lv-che"

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"东厢房"NOR);
	set("long", @LONG
这是丽春院的东厢房。这儿比起外面院子里安静了一些, 床上躺着一位汉
子, 看样子伤得很厉害。
LONG
	);

	set("exits", ([
                "west" : __DIR__"lichunyuan",
	]));

        set("objects", ([
                __DIR__"npc/mao" : 1,
        ]));

	set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

void init()
{
//      object me = this_player();

//      if (!me->query_temp("mao18/passed1")) return;
        add_action("do_no",({"no"}));
        add_action("do_yes",({"yes"}));
}

int do_yes()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed1"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("茅十八都早走了！！\n");
        me->delete_temp("mao18/passed1");
        me->set_temp("mao18/passed2",1);
        tell_object(me,HIR"
    你立马说道：“干么不去？好朋友有福同享，有难同当。”

    那人哈哈大笑，说道：“这两句话说得好。老子在江湖上听人说过了几千遍，有福共

享的家伙见得多了，有难同当的人却碰不到几个。咱们走罢！”\n"NOR);
        call_out("do_go", 1, me, ob);
        return 1;
}

int do_no()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed1"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("茅十八都早走了！！\n");
        tell_object(me,HIB"
    你战抖的答道：“小人家中。。。家中还有些事，请大爷您就放过小的我吧！”

    那人哈哈大笑，说道：“看你这小家伙也没什么骨气，赶快滚吧！”\n"NOR);
        me->delete_temp("mao18/passed1");
        return 1;
}

int do_go(object me, object ob)
{
	if (!me->query_temp("mao18/passed2"))
		return 1;
	tell_object(me,HIR"
    你二人走出丽春院数丈远，迎面赶来一辆驴车。那人喝到：“雇车，到城西，得胜山！”
    
    那赶车的当即停车，放下踏板，待得你二人上车后，驴车便向前奔出。\n"NOR);
	ob->move(CAR_ROOM);
	me->move(CAR_ROOM);
	call_out("do_going", 5, me, ob);
        return 1;
}

int do_going(object me, object ob)
{
	if (!me->query_temp("mao18/passed2"))
		return 1;
	tell_object(me,CYN"
    只见茅十八从怀中摸出一锭十两重的黄金，交给你，说道：“小朋友，这锭金子给你。”
    
    你见到这锭金子，不禁咽了口唾沫，心中犹豫不定究竟是收还是不收("RED"yes"CYN"|"RED"no"CYN")。\n"NOR);
	me->delete_temp("mao18/passed2");
    me->set_temp("mao18/passed3",1);
	return 1;
}    	
