inherit ITEM;
void create()
{
        set_name(HIY"千年雪莲"NOR, ({ "qiannian xuelian","xuelian"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗雪莲!\n");
                set("unit", "颗"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",50000);
                set("zhuyao",23);
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

  if(me->query("id")!=query("zhuren"))
  return notify_fail("这棵雪莲不是你挖的,你吃个什么劲。\n");
    
if (me->query("max_neili")>me->query_skill("force",1)*50)
{
 me->add("max_neili",random(30));   
} else {
me->add("max_neili",20+random(40));}
    
  message_vision(HIY"$N拿起雪莲吃了下去,感觉内力最大值增加了几点。\n"NOR,me);
       destruct(this_object());
       return 1;
}
