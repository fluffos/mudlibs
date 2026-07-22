inherit ITEM;
void create()
{
        set_name(HIG"疾风丹"NOR, ({ "jifeng dan","dan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
       else {   
                set("unit", "颗"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);
				set("buy_sell", 1);
        }
    setup();
}
void init()
{
    if (environment()==this_player())
        add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me = this_player();
  int maxneili,neili;
    neili = me->query("neili");
    maxneili = me->query("max_neili");
    
  if(!id(arg)) return 0;

  if(me->query("id")==query("value"))
  return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");
    
me->add("combat_exp",random(5000));
me->start_busy(0);
  message_vision(HIG"$N拿起疾风丹,身如疾风,一转身脱离了busy!!!!!\n"NOR,me);
       destruct(this_object());
       return 1;
}

