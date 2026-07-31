inherit ITEM; 

void create()
{
     set_name(HIG"绿铜"NOR, ({ "lv tong" }) );
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("ty_weapon",1);
   set("no_get",1);
   set("no_put",1);
   set("value",100000);
   set("con",2);
   set("long", "这是一个铜级的金属，可以用来合成兵器!(help hecheng)\n");
   
   setup();
  }
