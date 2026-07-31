#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_DAMAGE;

string inputstr,verb;

int query_autoload()
{ return 1; }
void create()
{
  seteuid(getuid());

set("long",@LONG
    这是一颗神奇的魔法[1;32m星星[2;37;0m，它是由九千九百九十九颗情人的眼泪滴制而成，万分珍贵。

    键入<help star>以获得更多的魔法。

LONG
);

  set("unit","颗");
  set("value", 10000);
  set("material", "ring");
  set("armor_prop/armor", 100);
  set("armor_type", "cape");
  set("light",1);
  set("unequip_msg","$N将[1;32m☆☆[2;37;0m轻轻地摘下来……。\n");
  set("wear_msg", "$N戴上[1;32m☆☆[2;37;0m，睹物思人，不禁流出几滴相思的泪水。\n");
  set("no_give","这么珍贵之物，哪能随便转赠给人？\n");
  set("no_drop","这么珍贵之物，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  setup();
}
void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
    set_name (me->name(1)+ "的[1;32m☆☆[2;37;0m", ({ "my star", "star" }));
  else
    set_name ("☆☆", ({ "my star", "star" }));

   add_action("help","help");
   add_action ("do_wakeup", "wakeup");
   add_action("full","full");
  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="star") return 0;

write(@Help
    
    你可以使用以下的命令:
       
       wakeup <玩家>                    <把昏迷不醒的玩家叫醒>
       full <玩家>                      <全医, 玩家若无输入则内定为自己>
       
          注：这颗星星只可以使用六次，用完六次后他将失去他原有的魔力。

Help

);

  return 1;
}


int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));
    if(me->query("id")!="gigi")
return notify_fail("这样东西你是从哪偷来的？\n");
    if(query("used") >= 6)
          return notify_fail("这只[1;32m星星[2;37;0m已经用过六遍了，变得黯然无色。\n");

  if (!me) return notify_fail ("[star]: full error: 找不到"+str+"\n");
max=me->query("max_sen");
me->set("eff_sen", max);
me->set("sen", max);
max=me->query("max_gin");
me->set("force", me->query("max_force"));
me->set("eff_gin", max);
me->set("mana", me->query("max_mana"));
me->set("atman", me->query("max_atman"));
me->set("gin", max);
max=me->query("max_kee");
me->set("eff_kee", max);
me->set("kee", max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->clear_condition();
  add("used", 1);

  message_vision( "$N滴下了一颗滚烫的[1;36m情人泪[2;37;0m,"+me->query("name")+"的全部精力迅速恢复了。\n",this_player());

  return 1;
}

int do_wakeup (string str)
{
  object me,who;
  me=this_player();
  if (!str) return notify_fail ("[star]: wakeup error, wakeup <someone>\n");
  if(me->query("id")!="gigi")
return notify_fail("这样东西你是从哪偷来的？\n");
  if(query("used") >= 6)
          return notify_fail("这只[1;32m星星[2;37;0m已经用过六遍了，变得黯然无色。。\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, 没有"+str+"\n");
   message_vision( "$N将个一颗[1;36m相思之泪[2;37;0m轻轻的滴落在了$n的脸庞。\n"+
   "$n渐渐恢复了知觉。\n",me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  add("used", 1);

  return 1;
}
