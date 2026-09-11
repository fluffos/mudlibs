//mcao.c 茅草 by row
#include <sanguo.h>
#include <ansi.h>
#include <mudlib.h>
#define JOBID "weavesandals"
inherit OBJ;
inherit M_MERGEABLE;
inherit M_GETTABLE;
inherit "/std/modules/m_weaveable";
void setup()
{
merge_setup();
set_unit("把");
set_id("mao cao", YEL+"茅草"+NOR,);
add_id("cao");
set_in_room_desc(YEL+"茅草"+NOR+"(mao cao)");
set_long("刚从路边拔下来的茅草，又长又结实，寻常的农家常用它来编些东西。");
set_gettable(1);
set_is_keeping(1);
set_size(SMALL);
set_ori_size(SMALL);
}
mixed weave()
{
	int m_hp;
	object usr;
	object ob;
	m_hp=this_body()->query_cur_hp();
	usr=this_body();
	all_inventory(usr);
	ob=present("cao",usr);
	if(!objectp(ob))
	{
	write("你身上没有这样东西。\n");
	return 1;
	}
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	this_body()->simple_action(
	"突然一阵大风，将$N手中的"+YEL+"茅草"+NOR+"刮得不知去向。\n");
	destruct(ob);
	return 1;
	}
	if (m_hp<10)
	{write("你太累了，休息一会儿吧。\n");
	return 1;
	}
	if(ob->query_count()<2)
	{
	write("至少需要两把"+YEL+"茅草"+NOR+"来编织。\n");
	return 1;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	usr->simple_action(
	"$N小心地将两把"+YEL+"茅草"+NOR+"慢慢搓在一起。\n");
	usr->start_busy(10,"你正忙着编草绳呢。\n");
	call_out("done",10);
}
void done(object ob)
{
	object mcao;
	int num;
	all_inventory(this_body());
	mcao=present("cao",this_body());
	num=mcao->query_count();
	if(num==2)
	{
	write("成功了！你得到一段"+YEL+"茅草绳"+NOR+"。\n");
	ob=new(__DIR__+"mrope");
	ob->move(this_body());
	destruct(mcao);
	return;
	}
	write("成功了！你得到一段"+YEL+"茅草绳"+NOR+"。\n");
	ob=new(__DIR__+"mrope");
	ob->move(this_body());
	mcao->set_count(num-2);
	mcao->set_look();
	return;
}