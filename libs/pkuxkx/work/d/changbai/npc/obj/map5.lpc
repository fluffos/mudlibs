#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG"宝藏地图残片"NOR , ({"map piece5", "map"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "片");
    set("value", 10000);
    set("long","这是一片残片地图，横七竖八的标注了很多地点。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
  }
  setup();
}
void init()
{
   add_action("do_hebing","hebing");
   add_action("do_hebing","he");
   add_action("do_hebing","combine");
}

int do_hebing()
{
	object me=this_player();
	object map5=this_object();
	object newmap;
	object map1,map2,map3,map4;
	map1 = present("map piece1", me);
	map2 = present("map piece2", me);
	map3 = present("map piece3", me);
	map4 = present("map piece4", me);
	if(!objectp(map1) || !objectp(map2) || !objectp(map3) || !objectp(map4) )
           return notify_fail("你合来合去，发现总是合不全，可能是缺了一些地图残片！\n");
	if(map1->query("owner") != me->query("id")) 
	         return notify_fail("好像有张地图不是你的吧？\n");; //不是自己找到的地图不让合并
	if(map2->query("owner") != me->query("id")) 
	         return notify_fail("好像有张地图不是你的吧？\n");; //不是自己找到的地图不让合并
	if(map3->query("owner") != me->query("id")) 
	         return notify_fail("好像有张地图不是你的吧？\n");; //不是自己找到的地图不让合并
	if(map4->query("owner") != me->query("id")) 
	         return notify_fail("好像有张地图不是你的吧？\n");; //不是自己找到的地图不让合并
	if(map5->query("owner") != me->query("id")) 
	         return notify_fail("好像有张地图不是你的吧？\n");; //不是自己找到的地图不让合并
        message_vision(HIR"\n$N将手中的五块地图残片拼在一起，合成了一张藏宝图！\n"NOR, me);
      destruct(map1);
      destruct(map2);
      destruct(map3);
      destruct(map4);
  newmap=new("/d/changbai/npc/obj/map");
  newmap->set("owner",me->query("id"));
  newmap->move(me);
  destruct(map5);
  return 1;  
}
