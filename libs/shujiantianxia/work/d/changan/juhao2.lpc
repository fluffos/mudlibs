// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/juhao2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "酒楼二楼");
	set("long", @LONG
这里是聚豪酒楼的二楼，大堂内宽敞明亮，墙上挂满了文人学士的字画。
聚豪酒楼生意红火，平时便高朋满座，一到节日更要提前来定下酒席。站在楼
上眺望，只觉得心旷神怡。
LONG
        );
	set("no_get",1);
	set("no_drop",1);
	set("no_fight",1);
	set("exits", ([
		"down" : __DIR__"juhao",
	]));

	set("incity",1);
	setup();
}

void init()
{       
	object ob=this_object();
	object me=this_player();
	object obj;

	if (me->query_temp("see_zhubanren",1)<1 && ob->query("doing",1)>0) {
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("caiyao"));
		obj->move(me);
		obj=new(FOOD_D("jiutan"));
		obj->move(me);
		obj=new(FOOD_D("jinbei"));
		obj->move(me);
		write("你走上楼来，小二急忙安排你找一空位坐下。桌上琳琅满目的美酒佳肴使你垂涎欲滴！\n");
		me->set_temp("see_zhubanren",1);
	}
	add_action("do_start", "start");
	add_action("do_theend", "theend");
	add_action("do_quit","quit");
	add_action("do_kickout","kickout");
}

int do_start()
{
	object me=this_player();
	object ob=this_object();
        
	if(me->query_temp("zhubanren") != 1) return notify_fail("你又不是主办人，瞎嚷嚷什么？\n");
	if(ob->query("doing")>0) return notify_fail("宴席不是已经开始了吗？\n");
	ob->set("doing",1);
	message("shout", HIC"\n【闲聊】酒楼掌柜(Zhanggui)：" + me->short(1) +HIC" \n\t\t现在在长安聚豪酒楼举行“"HIR""+me->query_temp("宴席")+""HIC"”敬请各路英雄豪杰。\n\n" NOR, users());
        message_vision(""BLINK+HIR"$N的"+ me->query_temp("宴席",1) +"开始了！"NOR"\n",me); 
        write("你可以用“"HIW"theend"NOR"”来结束这次宴席。\n还可以用“"HIW"kickout"NOR"”赶走你不喜欢的客人，他们将不能再参加您的酒宴！\n");
        call_out("time_theend", 3600);
        return 1;
}

int do_theend(string arg)
{
	object me=this_player();
	object ob=this_object();
	object obj;
        mixed *ob_list;
        int max,i;
        
        if (me->query_temp("zhubanren",1)<1) return notify_fail("你又不是主办人，瞎嚷嚷什么？\n");
        if (ob->query("doing",1)<1) return notify_fail("这里没有举行酒宴！\n");
       	message("shout", HIC"\n【闲聊】酒楼掌柜(Zhanggui)：" +me->short(1) +HIC" 的“"HIR""+me->query_temp("宴席")+""HIC"”结束了。\n\n" NOR, users());
        message_vision(""BLINK+HIR"$N的"+ me->query_temp("宴席",1) +"结束了！"NOR"\n",me); 
        me->delete_temp("zhubanren",1);
        me->delete_temp("宴席",1);
        ob->delete("doing",1);

	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);
	for(i=0;i<max;i++) {
		obj = ob_list[i];
		obj->delete_temp("see_zhubanren");
		obj->delete_temp("getout");
	}
	return 1;
}

int do_quit()
{
	object me=this_player();
	if (me->query_temp("zhubanren")) {
		write("你的宴席还没有结束，主人怎么能离开？\n");
		return 1;
	}
	else return 0;
}

int do_kickout(string arg)
{
	object me=this_player();
	object him;

        if (me->query_temp("zhubanren",1)<1) return notify_fail("你以为你是谁？\n");
	if (!arg) return notify_fail("你要请谁离开你的宴席？\n");

	him=find_player(arg);
	if(!him) return notify_fail("这个人没在你的宴席中！\n"); 
	if(him!=present(him,environment(me))) return notify_fail ("这个人没在你的宴席中！\n"); 

        message_vision("$N叫来酒楼掌柜，将"+ (string)him->query("name") +"("+ (string)him->query("id") +")赶出了宴席！\n", me); 
        him->set_temp("getout",1);
        him->move(__DIR__"juhao");
        tell_object(him,"你被掌柜带回了楼下，看来，他们是不欢迎你再进去了！\n");
        
        return 1;
}

int time_theend(string arg)
{
	object ob=this_object();
	object obj;
        mixed *ob_list;
        int max,i;
        
        if (ob->query("doing")<1) return 1;
       	message("shout", HIW"\n酒楼掌柜：长安聚豪酒楼举行的宴席结束了。\n\n" NOR, users());
        ob->delete("doing",1);
        
        ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
        max=sizeof(ob_list);
        for(i=0;i<max;i++) {
		obj = ob_list[i];
		obj->delete_temp("zhubanren");
		obj->delete_temp("宴席");
		obj->delete_temp("see_zhubanren");
		obj->delete_temp("getout");
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	object ob=this_object();
	if( dir=="down" && me->query_temp("zhubanren",1)>0 && ob->query("doing",1)>0 )
		return notify_fail("你的宴席还没有结束，主人怎么能离开？\n");
	return ::valid_leave(me,dir);
}
