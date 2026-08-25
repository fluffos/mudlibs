// by fire on Jan 9 1998 barrel.c
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
int isfill;
string short();
void setup() {
    set_adj("小巧的");
    set_id("shui hu", "水壶","bottle");
    set_unit("个");
    set_in_room_desc("一只浇花用的水壶(shui hu)。");
    isfill=0;
}
string long()
{
    if(isfill)
    {
       return "一只浇花用的水壶(shui hu)。\n"+
        "里面装满了水。\n";
    }
    return "一只浇花用的水壶(shui hu)。\n";
}
mixed direct_fill_obj()
{
   return 1;
}
void fill_with(object with)
{
   string s_obj;
   if(isfill)
   {
      printf("%s已经满了。\n",short());
      return;
   }
   isfill=1;
   this_body()->simple_action("$N将"+short()+"装满了水。\n");
}
int can_turn()
{
        return 1;
}
int set_water(int water)
{
	if( water == 0 )return isfill;
	else {
		isfill = 0;
		return isfill;
	}
}
