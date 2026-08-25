// created by fire on Jan 19 1998
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit FURNITURE;
inherit M_VALUE;
void setup()
{
  set_id("mbed", "%^RED%^双人床%^RESET%^");
  set_unit("张");
  set_value(3000000);
  set_in_room_desc("一张舒适的%^RED%^双人床%^RESET%^(mbed)");
  set_get_on_msg("");
  set_get_off_msg("$N恋恋不舍地从%^RED%^双人床%^RESET%^上站起来，却依然在回味刚才的美梦\n");
  set_long("这是一张%^H_RED%^貉燃雪%^RESET%^和%^H_GREEN%^我心依然%^RESET%^的结婚喜床。\n");
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*2, "on");
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
      write("你已经躺在床上了\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N懒洋洋地躺在了%^RED%^双人床%^RESET%^上，满心地希望情人在梦中出现。\n");
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
