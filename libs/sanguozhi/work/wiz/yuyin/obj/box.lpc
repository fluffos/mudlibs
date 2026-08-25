//朱红匣子 by benben
#include <mudlib.h>
#include <setbit.h>
#include <sanguo.h>
inherit COMPLEX_CONTAINER;
inherit M_GETTABLE;
inherit M_LOCKABLE;
inherit M_OPENABLE;
void setup(){   
  object ob1,ob2;
  set_in_room_desc("一个小巧的糖盒(box)。");
  set_adj( "小巧的" );
  set_id( "box","糖盒", );
  set_long("一个小巧的糖盒，上面写着：天天吃糖，牙齿健康。\n");
  set_relations("in");
  set_max_capacity(SMALL*2);
  ob1=new(FOBJPATH+"candy");
  ob1->move(this_object());
  ob2=new(FOBJPATH+"candy");
  ob2->move(this_object());
}
