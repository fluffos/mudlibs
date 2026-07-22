// cracked by vikee 2/09/2002   vikee@263.net
inherit ITEM;

void create()
{
  set_name("水晶腰牌", ({ "yao pai" }));
  set_weight(1000);
  set("long", "这是一个水晶制成的腰牌，上刻有“东海龙宫”四个字。
奇怪的是边锋上有些突槽，便如钥匙一般。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("longgong", 1);
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}
void destruct_me(object where, object me)
{
        message_vision("$N手中的$n掉到地下摔碎了。\n",where,me);
        destruct(me);
}

