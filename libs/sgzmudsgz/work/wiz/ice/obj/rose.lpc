//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_VALUE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("枝");
set_value(9999);
set_id("rose", HIR+"玫瑰"+NOR);
set_long("一枝娇艳的"+HIR+"玫瑰"+NOR+"(rose)");
set_in_room_desc("一枝"+HIR+"红玫瑰"+NOR+"(rose)");
set_gettable(1);
set_slot(BREST);
//set_wearmsg("$N在胸前别上一枝"+HIR+"红玫瑰"+NOR+"，显得更加娇艳动人。\n");
set_removemsg("$N小心翼翼地将"+HIR+"红玫瑰"+NOR+"从胸前取下来。\n");
}
int smell() {
  object who;
  who = environment(this_object());
  this_body()->set_cur_hp(0);
  write("这朵玫瑰熟悉的香味使你不由得想起了一个人．．．\n");
  write("你只觉一阵心痛，差点晕了过去．\n");
  return 1;
}

void do_wear() {
  object who;
  who=owner(this_object());
  foreach (object ob2 in all_inventory(who)) 
  {
        
  	if ((ob2->ob_state()==BREST))
        {
                write("你已经穿戴了同类装备了。\n");
                return;
        }
  }   
  who->simple_action("$N在胸前别上一枝"+HIR+"红玫瑰"+NOR+"没想到玫瑰深深的扎入了$N的心窝！\n");
  who->set_cur_hp(0);
}
