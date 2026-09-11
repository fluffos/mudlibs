// by row
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
void my_drop();
void add_hook(string s,function f);
void setup() {
    set_id("mai zhong", ""+HIY+"麦种"+NOR+"","seeds");
    set_unit("包");
   set_size(VERY_SMALL);
    set_in_room_desc(""+HIY+"麦种"+NOR+"(mai zhong)。\n");
    set_long("这是一小包作为种子的麦粒，颗颗金黄饱满。\n");
   add_hook("move",(:my_drop:));
}
void my_drop()
{
   object env=environment();
   object soil;
   soil=present("tu di",env);
   if(objectp(soil))
   {
      tell_environment(this_object(),"I got it hehehehe\n");
   this_object()->remove();
   }
}
