// 红包

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"礼物台"NOR, ({"liwu tai"}));
	set_weight(100000000);
    set("no_give","每个人只有一个，你都这么大方！\n");
    set("value", 0);
    set("no_steal",1);
    set("no_beg",1);
    set("no_put",1);
    set("no_get","这个东西拿不走的！\n");
    set("no_drop","这个东西扔不掉的！！\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一个上面放着很多东西的"+HIY"礼物台，"NOR+"似乎可以拿走(openliwu)自己的一份。
每个新手，都能换得自己的一份礼物。
\n
\n");
		set("unit", "个");
	}
}
  void init()
{
  add_action("do_liwu","openliwu");
}
int do_liwu()
{
object ob,obj;
object me=this_player();
ob=this_object();

        this_player()->start_busy(10);
  if(me->query("openliwu")>0)
  {
message_vision("属于$N的那份礼物已经给拿走了!\n", this_player());
   return 1;
  }
  if ( me->query("zhuanshen"))
  {
message_vision("$N不是新手!\n", this_player());
   return 1;
  }
  if ( me->query("combat_exp")> 2000000)
  {
message_vision("$N不是新手!\n", this_player());
   return 1;
  }

  me->set("openliwu",1);
        this_player()->add("combat_exp", 300000);
        this_player()->add("potential",80000);
        message_vision(HIR"$N获得了300000经验和80000潜能!\n"NOR, this_player());
        this_player()->add("max_neili", 300);
        message_vision(HIR"$N获得了300点内力上限!\n"NOR, this_player());

if (this_player()->query("str") <15)
{
this_player()->set("str",15);
message_vision(HIB"$N的先天臂力增加了！\n"NOR, this_player());
}
if (this_player()->query("int") <15)
{
this_player()->set("int",15);
message_vision(HIC"$N的先天悟性增加了！\n"NOR, this_player());
}
if (this_player()->query("con") <15)
{
this_player()->set("con",15);
message_vision(HIY"$N的先天根骨增加了！\n"NOR, this_player());
}
if (this_player()->query("dex") <15)
{
this_player()->set("dex",15);
message_vision(HIG"$N的先天身法增加了！\n"NOR, this_player());
}
if (this_player()->query("kar") <20)
{
this_player()->set("kar",20);
message_vision(HIC"$N的先天福缘增加了！\n"NOR, this_player());
}
if (this_player()->query("per") <20)
{
this_player()->set("per",20);
message_vision(HIB"$N的先天容貌增加了！\n"NOR, this_player());
}
if (me->query_skill("unarmed",1)<100)
{
  me->set_skill("unarmed",100);
message_vision(HIM"$N的基本格斗增加了！\n"NOR, this_player());
}
if (me->query_skill("parry",1)<100)
{
 me->set_skill("parry",100);
message_vision(HIM"$N的基本招架增加了！\n"NOR, this_player());
}
if (me->query_skill("dodge",1)<100)
{
  me->set_skill("dodge",100);
message_vision(HIM"$N的基本轻功增加了！\n"NOR, this_player());

}
if (me->query_skill("force",1)<100)
{
  me->set_skill("force",100);
message_vision(HIM"$N的基本内功增加了！\n"NOR, this_player());
}
if (me->query_skill("literate",1)<100)
{
  me->set_skill("literate",100);
message_vision(HIM"$N的读书写字增加了！\n"NOR, this_player());
}
return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
