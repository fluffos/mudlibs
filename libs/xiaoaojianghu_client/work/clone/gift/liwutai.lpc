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
规则如下:每个玩家可以得到500000经验和300000潜能，不足20的先天属性，全部补到20。
不足120级的常用基本武功，全部补足到120级,有自造武器的，增加杀伤力300(最大等级1000)。
有自造甲衣的，增加防御力300(最大等级1500)。转身过（或经验大于5M)的玩家可获得2个魔
戒(随机),4颗宝石(随机)。此外，玩家身上的不良属性将会被清除:神照经,九阴上册，九阴下
册,双手互博,九阴古墓,PK玩家数,叛师数将会被清零。玩家的内力上限也将提高380点。\n
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
  me->set("openliwu",1);
        this_player()->add("combat_exp", 500000);
        this_player()->add("potential",300000);
        message_vision(HIR"$N获得了500000经验和300000潜能!\n"NOR, this_player());
        this_player()->add("max_neili", 380);
        message_vision(HIR"$N获得了380点内力上限!\n"NOR, this_player());
if (this_player()->query("str") <20)
{
this_player()->set("str",20);
message_vision(HIB"$N的先天臂力增加了！\n"NOR, this_player());
}
if (this_player()->query("int") <20)
{
this_player()->set("int",20);
message_vision(HIC"$N的先天悟性增加了！\n"NOR, this_player());
}
if (this_player()->query("con") <20)
{
this_player()->set("con",20);
message_vision(HIY"$N的先天根骨增加了！\n"NOR, this_player());
}
if (this_player()->query("dex") <20)
{
this_player()->set("dex",20);
message_vision(HIG"$N的先天身法增加了！\n"NOR, this_player());
}
if (this_player()->query("kar") <20)
{
this_player()->set("kar",20);
message_vision(HIC"$N的先天臂力增加了！\n"NOR, this_player());
}
if (this_player()->query("per") <20)
{
this_player()->set("per",20);
message_vision(HIB"$N的先天容貌增加了！\n"NOR, this_player());
}
if (me->query_skill("unarmed",1)<120)
{
  me->set_skill("unarmed",120);
message_vision(HIM"$N的基本格斗增加了！\n"NOR, this_player());
}
if (me->query_skill("parry",1)<120)
{
 me->set_skill("parry",120);
message_vision(HIM"$N的基本招架增加了！\n"NOR, this_player());
}
if (me->query_skill("dodge",1)<120)
{
  me->set_skill("dodge",120);
message_vision(HIM"$N的基本轻功增加了！\n"NOR, this_player());

}
if (me->query_skill("force",1)<120)
{
  me->set_skill("force",120);
message_vision(HIM"$N的基本内功增加了！\n"NOR, this_player());
}
if (me->query_skill("literate",1)<120)
{
  me->set_skill("literate",120);
message_vision(HIM"$N的读书写字增加了！\n"NOR, this_player());
}
if (me->query("weapon/lv") &&
me->query("weapon/lv",1)<100)
{
  me->add("weapon/lv",30);
if (me->query("weapon/lv",1)>100)
me->set("weapon/lv",100);
message_vision(HIW"$N的自造武器等级大大的增加了！\n"NOR, this_player());
}
if (me->query("jia/lv")&&
me->query("jia/lv",1)<150)
{
  me->add("jia/lv",30);
if (me->query("jia/lv",1)>150)
me->set("jia/lv",150);
message_vision(HIW"$N的自造甲衣等级大大的增加了！\n"NOR, this_player());
}

me->delete("szj/failed");
message_vision(HIG"$N再次获得破解神照经的机会！\n"NOR, this_player());
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N再次获得解九阴上册的机会！\n"NOR, this_player());
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N再次获得解九阴下册的机会！\n"NOR, this_player());
me->delete("zhou/fail");
message_vision(HIG"$N再次获得解双手互捕的机会！\n"NOR, this_player());
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N再次获得解九阴古墓的机会！\n"NOR, this_player());
me->set("PKS",0);
message_vision(HIG"$N的PK玩家数清零！\n"NOR, this_player());
me->set("betrayer",0);
message_vision(HIG"$N的叛师门数清零！\n"NOR, this_player());
me->delete("last_getzhen");
message_vision(HIG"$N再次获得拿银针的机会！\n"NOR, this_player());
if (me->query("zhuanshen")||
me->query("combat_exp") > 5000000)
{
obj=new("/clone/gem/ring"+random(10));
obj->move(me);
message_vision(HIG"$N获得一个魔戒！\n"NOR, this_player());
obj=new("/clone/gem/ring"+random(10));
obj->move(me);
message_vision(HIG"$N获得一个魔戒！\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N获得一个魔力宝石！\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N获得一个魔力宝石！\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N获得一个魔力宝石！\n"NOR, this_player());
obj=new("clone/gem/gem");
obj->move(me);
message_vision(HIG"$N获得一个魔力宝石！\n"NOR, this_player());
}
message("channel:chat", HIG"【江湖谣言】听说"+me->name() + "拿走了属于自己的礼包!"NOR"。\n", users());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
