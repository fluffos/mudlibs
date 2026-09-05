// unwield.c
// addoil unwield all by whuan
inherit F_CLEAN_UP;

int do_unwield(object me,object ob);
int main(object me, string arg)
{
	object ob,ob2,ob3,*inv;
	string str;
	int i;

	if( !arg ) return notify_fail("你要脱掉什么？\n");
  ob = me->query_temp("weapon");//右手兵器
  ob2 = me->query_temp("secondary_weapon");//左手兵器

  
  if (arg=="all" && !objectp(ob) && !objectp(ob2))
      return notify_fail("你两手空空，并没有拿任何兵器呀。\n");  
	if (arg == "right" && !objectp(ob))
			return notify_fail("你右手没拿武器。\n");
	if (arg == "left" && !objectp(ob2))
			return notify_fail("你左手没拿武器。\n");
	if (arg=="all")
		{
      if(objectp(ob))
         do_unwield(me,ob);
      if(objectp(ob2))
         do_unwield(me,ob2);
      return 1;
    }
  if (arg=="left")
  	{
      if(objectp(ob2))
         do_unwield(me,ob2);
      return 1;
    }
  if (arg=="right")
  	{
      if(objectp(ob))
         do_unwield(me,ob);    	
      return 1;
	  }
	if ((arg != "left") && (arg != "right") && (arg != "all"))
		  ob3 = present(arg, me);//其他兵器
	if( !objectp(ob3) )
		return notify_fail("你身上没有这样东西。\n");
  if(objectp(ob3))
	if( (string)ob3->query("equipped")!="wielded" )
		return notify_fail("你并没有装备这样东西作为武器。\n");
    do_unwield(me,ob3);
		return 1;
}
int do_unwield(object me,object ob)
{
	string str;
	if( ob->unequip() ) 
		{
		if( !stringp(str = ob->query("unwield_msg")) )
			{
				str = "$N放下手中的$n。\n";
				if (me->query_temp("yinyang-daoluan/daoluan") || me->query_temp("kuihua.guiming"))
				{
					me->delete_temp("apply/attack_speed", me->query_temp("yinyang-daoluan/daoluan"));
					me->delete_temp("yiyang-daoluan/daoluan");
					me->delete_temp("active_buffer/yinyang-daoluan.daoluan");
					message_vision("你赤手空拳，攻势缓了下来。\n", me);
				}
			}
		message_vision(str, me, ob,"wield");
		return 1;
	 } 
	else
		return 0;	
}

int help(object me)
{
  write(@HELP
指令格式 : unwield <物品名> 或left(左手兵器),right(右手兵器),all(两手兵器)
 
这个指令让你放下手中的武器。
 
HELP
    );
    return 1;
}
 

