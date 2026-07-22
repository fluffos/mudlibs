inherit ITEM; 

void create()
{
     set_name(HIR"赤血铁"NOR, ({ "chixue tie" }) );
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("ty_weapon",1);
   set("no_get",1);
   set("no_put",1);
           set("value",1);

   //set("no_give",1);
   set("zhongji_hc",1);
   set("bh",4);
   set("con",35+random (120));
   set("damage",100+random (500));
   set("long", "这是一个高级的金属，可以用来镶嵌兵器(xiangqian)和合成装备！\n");
   
   setup();
  }
