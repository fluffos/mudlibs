inherit ITEM;
void create()
{
        set_name(MAG"鹿茸"NOR, ({ "lu rong","rong"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个鹿茸!\n");
                set("unit", "个"); 
                set("no_get",1);
                set("no_drop",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",100000000);
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
  if(me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");

    
    me->add("combat_exp",5000);  
    
  message_vision(HIY"$N拿起鹿茸吃了下去,感觉经验值最大值增加了5000点。\n"NOR,me);
       destruct(this_object());
       return 1;
}

