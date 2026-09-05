#pragma save_binary
// sen-bean.c

inherit COMBINED_ITEM;

void create()
{
        set_name("仙豆", ({ "sen-bean"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long", "这是一粒暗红色有点奇怪的豆子，闻了闻有一种上等药材的味道。\n");
                set("unit", "粒");
                set("value", 50000);
                set("base_value", 50000); 
                set("base_unit", "粒");
                set("base_weiht",50);
        }
        set_amount(1);
}

void init()
{
	add_action("eat_sen","eat");
}


int eat_sen(string arg)  
{
       object me;
       int inss;
     
       if( !this_object()->id(arg) ) return 0;
       me = this_player();

       if( (inss = me->query("max_gin") - me->query("gin")) > 0 )
       {
        	if( inss > 50 ) me->add("gin", 50);
              else me->add("gin", inss);
	}
       if( (inss = me->query("max_kee") - me->query("kee")) > 0 )
       {
        	if( (inss = me->query("max_kee") - me->query("kee")) > 50 ) me->add("kee", 50);
              else me->add("kee", inss);
	}
       if( (inss = me->query("max_sen") - me->query("sen")) > 0 )
       {
        	if( inss > 50) me->add("sen", 50);
              else me->add("sen", inss);
	}
	add_amount(-1);	
	message_vision("$N拿出一粒小丸子，一口给吞了下去。\n", me);
       message_vision("只见$N脸上泛起一阵红晕，整个人看起来好多了！\n", me);

       return 1;
}
