inherit ITEM;
void create()
{
        set_name(HIG"年龄丸"NOR, ({ "age wan","wan"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {       
           set("unit", "颗"); 
                set("no_get",1);
                set("no_s",1);             
                set("no_put",1);
                set("no_give",1);
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
    
  me->set("mud_age",0);
  me->set("zjb_dj/dj",1);
  me->set_skill("dodge",1);
  me->set_skill("force",1);
  me->set_skill("pixie-jian",1);
  me->set_skill("sword",1);
  me->set_skill("unarmed",1);
  me->set_skill("shaolin-shenfa",1);
  me->set_skill("piaomiao-shenfa",1);
  me->set_skill("parry",1);
  me->set_skill("jiuyang-shengong",1);
message_vision(HIB"$N拿起年龄丸吃了下去,飙的一下就成熟了不少。\n"NOR,me);
       destruct(this_object());
       return 1;
}

