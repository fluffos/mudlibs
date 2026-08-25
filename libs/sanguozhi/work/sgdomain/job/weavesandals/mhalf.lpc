//mhalf.c 草鞋掌 by row
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
set_unit("块");
set_id("caoxie zhang", YEL+"草鞋掌"+NOR,);
add_id("zhang");
set_in_room_desc(YEL+"草鞋掌"+NOR+"(caoxie zhang)");
set_long("这粗看上去是一块用草绳编成的椭圆形的片片，\n不过若将两块拼在一起，就有点象人脚底的形状。");
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
	ob=present("zhang",usr);
	if(!objectp(ob))
	{
	write("你身上没有这样东西。\n");
	return 1;
	}
	if(this_body()->query_job(JOBID,"beg_time")==0)
	{
	this_body()->simple_action(
	"$N一阵手忙脚乱，手中的"+YEL+"草鞋掌"+NOR+"都散了架了。\n");
	destruct(ob);
	return 1;
	}
	if (m_hp<10)
	{write("你太累了，休息一会儿吧。\n");
	return 1;
	}
	if(ob->query_count()<2)
	{
	write("至少需要两块"+YEL+"草鞋掌"+NOR+"才能拼得起来。\n");
	return 1;
	}
	m_hp-=10;
	this_body()->set_cur_hp(m_hp);
	usr->simple_action(
	"$N将仔细将两块"+YEL+"草鞋掌"+NOR+"前后拼接起来。\n");
	usr->start_busy(10,"你正忙着拼鞋底呢。\n");
	call_out("done",10);
}
void done(object ob)
{
	object mhalf;
	int num;
	all_inventory(this_body());
	mhalf=present("zhang",this_body());
	num=mhalf->query_count();
	if(num==2)
	{
	write("成功了！你得到一只"+YEL+"草鞋底"+NOR+"。\n");
	ob=new(__DIR__+"strawsandals");
	ob->move(this_body());
	destruct(mhalf);
	return;
	}
	write("成功了！你得到一只"+YEL+"草鞋底"+NOR+"。\n");
	ob=new(__DIR__+"strawsandals");
	ob->move(this_body());
	mhalf->set_count(num-2);
	mhalf->set_look();
	return;
}