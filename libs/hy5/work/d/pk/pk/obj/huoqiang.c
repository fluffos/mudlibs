// huoqiang.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;
void init()
{
        add_action("do_shoot","shoot");
}
void create()
{
	set_name("荷兰火枪", ({"helan huoqiang", "huoqiang"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "一支荷兰火枪。可惜只能放一枪。\n");
		set("no_put", 1);
		set("no_pawn", 1);
		set("value", 0);
		set("material", "bamboo");
		set("wield_msg", "$N抽出一支乌油的木柄火枪握在手中。\n");
		set("unwield_msg", "$N把手中的火枪背回背上。\n");
	}
	init_staff(30);
	setup();
}
int do_shoot(string arg)
{
       object me, obj;

       me = this_player();
      if (!arg)
      return notify_fail("你要打谁！\n");
if (me->is_busy())
return notify_fail("你正忙着呢！\n");
        if( !environment(me)->query("bwdhpk"))
{
       message_vision(HIR "\n$N此枪为比赛专用，枪被没收了！\n\n" NOR,
                       me, obj);
	destruct(this_object());   
       return 1;       
}


       if( !objectp(obj = present(arg, environment(me)) ))
               return notify_fail("你要射击的对象这里没有。\n");
if (obj==me)
   return notify_fail("自己打自己!\n");
      if (!userp(obj))
               return notify_fail("此枪只能打玩家!\n");
       message_vision(HIR "\n$N对准$n抬手就是一枪：砰！枪口一团火焰喷出。$n被打死了！\n\n" NOR,
                       me, obj);

me->start_busy(3);
obj->set_temp("last_damage_from",me);
       obj->die();
me->add_temp("bwdhpk",1);
message("channel:chat", HIC"【屠人战况】"HIR + " "+obj->query("name")+"被"+me->query("name")+"用火枪打死了！\n"NOR,users() );
	destruct(this_object());   
       return 1;
}