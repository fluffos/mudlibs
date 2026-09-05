// jingxiu.c 静修阁
// by llin

#include <ansi.h>
inherit ROOM;

int inc(object me);
void init()
{
add_action("do_wudao","wudao");
}

void create()
{
	set("short", "静修阁二楼");
	set("long", 
"这里是武当道派清心静修的地方，凡是武当门下弟子在道\n"
"学上有什么疑难之处，除了向师傅请教外，还可在此处静修悟\n"
"道以提高道学上的修为。屋内一片宁静，四面白壁，唯有正东\n"
"面墙上贴着一条横幅“大道于心”，几名道士正盘腿打坐，闭\n"
"目冥想，似乎已游身世外。\n"
	);

	set("exits", ([
		"down" : __DIR__"jingxiu",
	]));
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);
	setup();
}
int do_wudao()
{	object me=this_player();
	mapping fam;
  int skill = me->query_skill("taoism",1);
  skill = skill/1.5 - me->query("int")*10;
  if (skill <= 0 ) skill = 1;
	
	if (skill*skill/10>me->query("combat_exp")/skill)
	return notify_fail("你受到自身经验和悟性的影响，无法继续悟道了。\n");
	
	if (!(fam=me->query("family")) || fam["family_name"]!="武当派")
	return notify_fail("你又不是牛鼻子老道，在这里凑什么热闹！\n");

	if((int)me->query_skill("taoism",1)<120)
	return notify_fail("你在道学上的修为尚且达不到可以无师自通的地步！\n");

	if((int)me->query("jing")<(int)me->query("max_jing"))
	return notify_fail("你心神无法专一，怎能参悟道学至理？\n");
	
	if((int)me->query("qi")<(int)me->query("max_qi"))
	return notify_fail("你气血亏缺，无法静下心来参悟道学至理！\n");

	if (me->is_busy())
	return notify_fail("你现在无法静下心来悟道！\n");

	if (time()-me->query_temp("wudao") < 10)
	return notify_fail("你刚刚悟道，需要休息一会儿！\n");

	tell_object(me,"你面对墙壁慢慢盘膝坐下，身躯挺直；头，手，足五心朝天；心中默念道家至理\n"
	      WHT"渐渐的你心如止水，开始神游太虚。\n"NOR);
	me->set_temp("wudao",time());
	me->set_temp("duration",6);
//        remove_call_out("inc");
        inc(me);
	return 1;
}

int inc(object me)
{	
	int dur, inc;
	
	if ( !objectp(me) )
		return 1;
		
	dur=me->query_temp("duration");
	inc=(int)me->query_skill("taoism",1)*1*(int)me->query("int")/30;
	
	if (dur==6){
/*	tell_object(me,"你面对墙壁慢慢盘膝坐下，身躯挺直；头，手，足五心朝天；心中默念道家至理\n"
	      WHT"渐渐的你心如止水，开始神游太虚。\n"NOR);*/
	message("vision", 
		me->name() + "走到墙边，盘膝坐下，口中仿佛念念有词。\n",environment(me),me);
	me->add_temp("duration",-1);
	me->start_busy(30);
	call_out("inc",5,me);
	return 1;
	}

	if (dur<6 && dur>0) {
	tell_object(me,HIW"你闭目冥想道学中的真谛，心中的疑惑逐渐释然，对道学的理解也更进了一步。\n"NOR);
	me->improve_skill("taoism",inc);
	me->add_temp("duration",-1);
	me->start_busy(30);
	call_out("inc",5,me);
	return 1;}
	
	if (dur==0){
	message_vision("$N修行完毕，收心定神，满心释然的站了起来。\n",me);
	me->start_busy(0);
	return 1;}
}
