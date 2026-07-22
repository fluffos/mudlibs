
inherit ITEM;

void create()
{
  set_name("〖琴曲〗", ({"qin qu", "qinqu", "qu", "book", "shu"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("material", "paper");
    set("value", 0);
  }
}

void init()
{
  if (!wizardp(this_player())) {
  }
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player(),book=this_object();
  int sen_cost, gain,lev,exp;

  if( !book->id(arg) ) return notify_fail("你要读什么？\n");
  if( environment(book)!=me ) return notify_fail("书要拿起来读。\n");
  if(me->is_busy()) return notify_fail("你现在忙着呢，还是等静下心来再读书吧！\n");
  if(me->is_fighting()) return notify_fail("临阵磨枪可来不及啦！\n");
  if( (int)me->query_skill("literate",1)<180 )
    return notify_fail("你拿起书仔细读了半天，但怎么也读不懂。\n");
  if( (int)me->query_skill("qin",1)<280 )
    return notify_fail("你拿起书仔细读了半天，但怎么也读不懂。\n");
  if( (int)me->query_skill("qin",1)>480 )
    return notify_fail("你的琴艺够高，这本秘诀不会让你长进多少。\n");
  exp=(int)me->query("combat_exp");
  lev=(int)me->query_skill("parry", 1);
  if(exp*10 < lev*lev*lev)
    return notify_fail("也许是你的经验不够，再怎么读也没用。\n");
  sen_cost=10+(40-(int)me->query_int())+(35-(int)me->query_kar())+(int)lev/5;
  if( (int)me->query("sen")<sen_cost )
    return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);
  
  gain = (int)me->query_skill("literate",1);
  gain -= random(me->query_int());
  gain +=random(me->query_kar());
  if(gain < 0) gain=0;
  me->improve_skill("qin", gain);

  message_vision("$N正专心地研读"+book->query("name")+"。\n", me);
  tell_object(me, "你研读有关琴艺的技巧，似乎有点心得。\n");
  return 1;
}





