// created by fire on Jan 19 1998
#include <sanguo.h>
#include <mudlib.h>
#include <ansi.h>
inherit FURNITURE;
inherit M_VALUE;

private int p_status;  // 1 for on, 0 for off

int turn_onoff( string par_str )
{
   if ( par_str == "on" )
   {
        write( "你打开开关。" );
        
        p_status = 1;
    
   }
   else if ( par_str == "off" )
   {
        write( "你关上开关。" );
        
        p_status = 0;
   }
   else
   {
        write( "turn on 或者 turn off\n" );    
   }
    
   return p_status;
    
}

int turn( string par_str )
{
   if ( par_str == "on" )
   {
        write( "你打开开关。" );
        
        p_status = 1;
    
   }
   else if ( par_str == "off" )
   {
        write( "你关上开关。" );
        
        p_status = 0;
   }
   else
   {
        write( "turn on 或者 turn off\n" );    
   }
    
   return p_status;
}

void setup()
{
  set_id("sofa", HIY+"沙发"+NOR);
  set_unit("张");
  set_in_room_desc("一张舒服的"+HIY+"沙发"+NOR+"。(sofa)");
  set_value(5000000);
  set_get_on_msg("");
  set_get_off_msg("$N费劲地从沙发上站了起来。\n");
  set_long("这是一张意大利进口的真皮沙发，要坐上去请用 sit on sofa。\n");
  set_preposition("on");
  set_relations("on","under");
  set_max_capacity(VERY_LARGE*5, "on");
//  add_action( "turn" );
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
      write("你已经坐在沙发上面了，白痴。\n");
      return 1;
    }
  this_body()->move(this_object());
  this_body()->simple_action("$N舒舒服服地横在了"+short()+"上，看也不看旁边的人一眼。\n");
  return 1;
}

void do_wish_for_str( string str )
{
    write( "是你希望的吗\n" );
}

