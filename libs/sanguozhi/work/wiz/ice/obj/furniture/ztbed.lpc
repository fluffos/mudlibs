// created by fire on Jan 19 1998
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit FURNITURE;
inherit M_VALUE;
void setup()
{
  set_id("ztbed", MAG+"紫檀木床"+NOR);
  set_unit("张");
  set_value(4000000);
  set_in_room_desc("一张豪华的"+MAG+"紫檀木床。"+NOR+"(ztbed)");
  set_get_on_msg("");
  set_get_off_msg("$N从床上站起来。\n");
  set_long("这是一张紫檀木床，散发着阵阵清香。\n");
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*3, "on");
}
// Unlike most furniture, you can lie on a bed.  We'll assume you mean sit
// on the bed here, but you can do what you want...
int direct_lie_on_obj()
{
  return 1;
}
int lie()
{
  return sit();
}
int mount_it_already()
{
  string stat;
  if(environment(this_body()) == this_object())
    {
      write("你已经躺在床上了，想睡到床底下吗？\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N脱下衣服，舒舒服服地躺在"+short()+"上。\n");
  foreach (object ob2 in all_inventory(this_body())) 
  {
		
        	stat=ob2-> ob_state() ;
		if(stringp(stat))
		{
			ob2->do_remove();
		}
  }
  return 1;
}
int is_bed()
{
	return 1;
}
