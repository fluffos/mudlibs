// 超级大礼包 /ADDED BY KEINXIN

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"贰零零叁新年大礼包"NOR, ({"dalibao", "bao", "libao"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
    set("no_bug", 1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "一个用纯金制作成的"+HIY"贰零零叁新年大礼包"NOR+"代表了海洋贰巫师组对大家的真诚祝福，请打开看看(opengift)。\n");
		set("unit", "个");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
	int exp,pot;
	object me = this_player();
object ob;
object gem;
        exp = 6100+random(8000);
        pot = exp/3;
  if(me->query("liwuopen/1")>0)
  {
message_vision("属于$N的那份礼物已经给拿走了!\n", this_player());
	destruct(this_object());
   return 1;
  }
	me->set("liwuopen/1",1);
	this_player()->add("combat_exp",exp);
	this_player()->add("potential",pot);
        this_player()->add("max_neili", 380);
	this_player()->start_busy(50);
	message_vision("$N打开了新年大礼包，小人物，绯雨剑心，刮风，YQH，YAODM，笑莫问带着金光出现了！\n", this_player());
	                                                                       
tell_object(me,HIW"       @@        @@                                                        \n"NOR);
tell_object(me,HIW"     @@@@     @@                                  @                        \n"NOR);
tell_object(me,HIW"        @     @@                   @@@@       @@@@@                        \n"NOR);
tell_object(me,HIW"       @@    @@        @@@@@@@@      @@@@@@@     @ @@@@    @      @@       \n"NOR); 
tell_object(me,HIW"     @@@@@@@@@@@@     @@     @@      @@@  @@@   @@@  @@@@  @@     @        \n"NOR);
tell_object(me,HIW"       @@   @@       @@     @@     @@@     @@   @@     @@   @@   @@        \n"NOR);
tell_object(me,HIW"       @    @@       @@   @@@@    @@@@     @@   @@     @@   @@   @         \n"NOR);
tell_object(me,HIW"      @@    @@@      @@  @  @@@@@@ @@     @@   @@     @      @@ @          \n"NOR);
tell_object(me,HIW"      @      @@@@    @@@@    @@@   @@@   @     @@@  @@        @@           \n"NOR);
tell_object(me,HIW"     @@                            @@         @@             @             \n"NOR);
tell_object(me,HIW"                                   @@         @@            @              \n"NOR);
tell_object(me,HIW"                                  @@          @@       @@@@                \n"NOR);
tell_object(me,HIW"                                  @@          @@                           \n"NOR);
tell_object(me,HIW"                                                                           \n"NOR);
tell_object(me,HIW"                                                                           \n"NOR);
tell_object(me,HIW"         @@@          @@@          @@@         @@@@                        \n"NOR);
tell_object(me,HIW"       @@@@@@@      @@   @@      @@  @@@          @@                       \n"NOR);
tell_object(me,HIW"      @     @@    @@      @@   @@      @@         @@                       \n"NOR);
tell_object(me,HIW"           @@     @       @@  @@       @@         @                        \n"NOR);
tell_object(me,HIW"          @      @@       @@  @@       @@    @@@@@                         \n"NOR);
tell_object(me,HIW"         @       @@       @   @@       @         @@                        \n"NOR);
tell_object(me,HIW"       @         @@      @    @@     @@           @                        \n"NOR);
tell_object(me,HIW"     @@@@@@@@     @     @     @@     @           @@                        \n"NOR);
tell_object(me,HIW"    @@       @     @@@@         @@@         @@@@                           \n"NOR);
tell_object(me,HIW" 	                                                                      \n"NOR);
tell_object(me,HIW" 	                                                                      \n"NOR);
tell_object(me,HIW" 	                                                                      \n"NOR);
tell_object(me,HIY"你小心翼翼的打开礼包，随着灿烂的火花，小人物，绯雨剑心，刮风，YQH，YAODM，笑莫问带着金光出现了。\n"NOR);
        tell_object(me,HIY"                                                           \n"NOR);
	tell_object(me,HIR"他们个个穿着特制的节日礼服，显得神采奕奕。和你一起庆祝新的一年的到来。\n");
	tell_object(me,"                                                           \n");
	tell_object(me,BLINK"海洋贰巫师组感谢您在新年陪伴我们，感谢您陪同我们走过贰零零贰，希望您在新的一年中继续支持海洋贰。\n"+
	                    "祝您在新年里一帆风顺，百事可乐，万事如意！\n"NOR);                    
	tell_object(me,HIY"                                                                                      \n");
	tell_object(me,HBBLU"                                                                         海洋贰巫师组\n");
	tell_object(me,HBBLU"                                                           http://haiyang2.6to23.com\n"NOR);  
	tell_object(me,HIY"                                                           \n"NOR);
	tell_object(me,HIW"你被奖励了：很多很东东啊，而且没有人来抢!! ^0^ \n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n"NOR);
        message_vision(HIW"$N获得了380点内力上限!\n"NOR, this_player());

if (me->query("weapon/lv") &&
(int)me->query("weapon/lv",1)<100)
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
message_vision(HIW"$N再次获得破解神照经的机会！\n"NOR, this_player());
me->delete("jiuyin/shang-failed");
message_vision(HIW"$N再次获得解九阴上册的机会！\n"NOR, this_player());
me->delete("jiuyin/xia-failed");
message_vision(HIW"$N再次获得解九阴下册的机会！\n"NOR, this_player());
me->delete("zhou/fail");
message_vision(HIW"$N再次获得解双手互捕的机会！\n"NOR, this_player());
me->delete("jiuyin/gumu-failed");
message_vision(HIW"$N再次获得解九阴古墓的机会！\n"NOR, this_player());
me->set("PKS",0);
message_vision(HIW"$N的PK玩家数清零！\n"NOR, this_player());
me->set("betrayer",0);
message_vision(HIW"$N的叛师门数清零！\n"NOR, this_player());
me->delete("last_getzhen");
message_vision(HIW"$N再次获得拿银针的机会！\n"NOR, this_player());
if (this_player()->query("kar") <22)
{
this_player()->set("kar",22);
message_vision(HIW"$N的先天臂力增加了！\n"NOR, this_player());
}
if (this_player()->query("per") <25)
{
this_player()->set("per",25);
message_vision(HIW"$N的先天容貌增加了！\n"NOR, this_player());
}
if (me->query_skill("unarmed",1)<120)
{
  me->set_skill("unarmed",120);
message_vision(HIW"$N的基本格斗增加了！\n"NOR, this_player());
}
if (me->query_skill("parry",1)<120)
{
 me->set_skill("parry",120);
message_vision(HIW"$N的基本招架增加了！\n"NOR, this_player());
}
if (me->query_skill("dodge",1)<120)
{
  me->set_skill("dodge",120);
message_vision(HIW"$N的基本轻功增加了！\n"NOR, this_player());

}
if (me->query_skill("force",1)<120)
{
  me->set_skill("force",120);
message_vision(HIW"$N的基本内功增加了！\n"NOR, this_player());
}
if (me->query_skill("literate",1)<120)
{
  me->set_skill("literate",120);
message_vision(HIW"$N的读书写字增加了！\n"NOR, this_player());
}

//        message_vision(HIG"$N另外获得了一个魔力宝石！\n"NOR, this_player());     
	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}