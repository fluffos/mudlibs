//mrope.c 茅草绳 by row
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
set_unit("段");
set_id("maocao sheng", YEL+"茅草绳"+NOR,);
add_id("sheng","mrope");
set_in_room_desc(YEL+"茅草绳"+NOR+"(maocao sheng)");
set_long("这是段用几股茅草编成的绳子，看上去相当结实。");
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
	ob=present("sheng",usr);
	if(!objectp(ob))
	{
	write("你身上没有这样东西。\n");
	return 1;
	}
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	this_body()->simple_action(
	"不知从哪里窜出一只小狗，将$N手中的"+YEL+"茅草绳"+NOR+"叼了就跑。\n");
	destruct(ob);
	return 1;
	}
	if (m_hp<10)
	{write("你太累了，休息一会儿吧。\n");
	return 1;
	}
	if(ob->query_count()<4)
	{
	write("至少需要四段"+YEL+"茅草绳"+NOR+"来编织。\n");
	return 1;
	}
	m_hp-=5;
	this_body()->set_cur_hp(m_hp);
	usr->simple_action(
	"$N将四段"+YEL+"茅草绳"+NOR+"左右摆齐，然后左绕右，右穿左，\n来来回回，一心一意地编织起来。\n");
	usr->start_busy(10,"你正忙着编鞋掌呢。\n");
	call_out("done",10);
}
void done(object ob)
{
	object mrope;
	int num;
	all_inventory(this_body());
	mrope=present("sheng",this_body());
	num=mrope->query_count();
	if(num==4)
	{
	write("成功了！你得到一块"+YEL+"草鞋掌"+NOR+"。\n");
	ob=new(__DIR__+"mhalf");
	ob->move(this_body());
	destruct(mrope);
	return;
	}
	write("成功了！你得到一块"+YEL+"草鞋掌"+NOR+"。\n");
	ob=new(__DIR__+"mhalf");
	ob->move(this_body());
	mrope->set_count(num-4);
	mrope->set_look();
	return;
}