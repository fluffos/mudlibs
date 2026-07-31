inherit ITEM; 

void create()
{
     set_name(HIR"血钢"NOR, ({ "xue gang" }) );
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("ty_weapon",1);
   set("no_get",1);
   set("no_drop",1);             
   set("no_put",1);
   set("no_give",1);
   set("bh",5);
   set("damage",150);
   set("long", "这是一个钢级的金属，可以用来合成兵器!(help hecheng)\n");
   
   setup();
  }
