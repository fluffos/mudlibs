//shangyuetai.c	赏月台
//by bing
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","赏月台");
	set("long",@LONG 
这里是黑木崖后山的一块平地。俯瞰群山环绕，仰望浩瀚
苍穹，令人心胸大为开阔。教主常在这里深夜赏月，沉思武功
奥秘。
LONG
	);
	set("exits", ([
		"west" : __DIR__"dongce",
	]));
	set("outdoors", "riyuejiao");
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);
        set("no_task",1);
	setup();
}

void init()
{
    add_action("do_chensi","chensi");
}

int inc(object me)
{	
	int dur=me->query_temp("duration");
	int inc=(int)me->query_skill("daguangming-xinfa",1)*1*(int)me->query("int")/30;
	
	if (dur==6){
	tell_object(me,"你看着当空的明月，往日武学中难解之处一一在心中扫过。\n"+HIM+"渐渐进入天人合一的境界。\n"NOR);
	message("vision", 
		me->name() + "对着明月竟似看得痴了。\n",environment(me),me);
	me->add_temp("duration",-1);
	me->start_busy(10);
	call_out("inc",5,me);
	return 1;
	}

	if (dur<6 && dur>0) {
	tell_object(me,HIM"你凝神思索，对武学的理解也更进了一步。\n"NOR);
	me->improve_skill("daguangming-xinfa",inc);
	me->add_temp("duration",-1);
	me->start_busy(5);
	call_out("inc",5,me);
	return 1;}
	
	if (dur==0){
	message_vision("$N想通了某处关节，一法通，百法通，境界大进。\n",me);
	me->delete_temp("busy");
	return 1;}
}


int do_chensi()
{	object me=this_player();
	mapping fam;
    int skill = me->query_skill("daguangming-xinfa",1);
    skill = skill/1.5 - me->query("int")*10;
    if (skill <= 0 ) skill = 1;
	if (me->query_skill("taoism",1)>10)
    return notify_fail("道学心法和大光明心法完全相冲，强行领悟极易走火入魔。\n");
    if (me->query_skill("buddhism",1)>10)
    return notify_fail("佛家心法和大光明心法完全相冲，强行领悟极易走火入魔。\n");
    if (me->query_skill("jiuyang-shengong",1)>10)
    return notify_fail("九阳神功和大光明心法完全相冲，强行领悟极易走火入魔。\n");
	if (skill*skill/10>me->query("combat_exp")/skill)
	return notify_fail("你受到自身经验和悟性的影响，沉思也没有什么效果了。\n");
	
	if (!(fam=me->query("family")) || fam["family_name"]!="日月神教")
	return notify_fail("你不是神教弟子，速速离开吧！\n");
    if (me->query("exp/rynewbiejob")<10000)
    return notify_fail("教主有令，必须完成一定程度的入门任务才能在这里沉思。\n");
	if((int)me->query_skill("daguangming-xinfa",1)<150)
	return notify_fail("你还是去找师父学学或者找本书来读吧！\n");

	if((int)me->query("jing")<(int)me->query("max_jing"))
	return notify_fail("你心神不宁，无法静思武学的奥秘。\n");
	
	if((int)me->query("qi")<(int)me->query("max_qi"))
	return notify_fail("你气血亏缺，无法静思武学的至理。\n");

	if (me->is_busy())
	return notify_fail("你现在正忙着呢！\n");

	me->set_temp("duration",6);
//        remove_call_out("inc");
        inc(me);
	return 1;
}

