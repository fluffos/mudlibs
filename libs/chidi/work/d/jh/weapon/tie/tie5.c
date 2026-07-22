
inherit ITEM; 

void create()
{
     set_name(MAG"紫铁"NOR, ({ "zi tie" }) );
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("ty_weapon",1);
   set("no_get",1);
         set("zhongji_hc",1);
           set("value",1);

   set("no_put",1);
        
   set("damage",50+random (50));
   set("long", "这是一个铁级的金属，可以用来镶嵌兵器(xiangqian)和合成装备！\n");
   
   setup();
  }
