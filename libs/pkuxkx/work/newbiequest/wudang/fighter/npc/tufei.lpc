//tufei.c 土匪
//seagate@pkuxkx 2010/11/06

#include <ansi.h>
inherit FAMILY_NPC;
varargs void wield_weapon(string);

void create()
{
  set_name("土匪", ({ "tu fei", "robber" }));
  set("long", "他是武当山脚下的土匪，长得一脸横肉。\n");
  set("age", 20+random(20));
  set("attitude", "heroism");
  set("combat_exp", 500000);
  set("food",500);
  set("water",500);
  set("chat_chance_combat", 10);
  set("can_kun",1);
  setup();
  carry_object("/clone/armor/bianfuxuejia")->wear();
  call_out("destroying",900,this_object());
}

void init()
{
	add_action("do_kaowen","kaowen");
}

//土匪拷贝的技能等级从50级开始一直到1000级结束，每50级50级跳跃。
//技能拷贝已玩家等级上限的80%来拷贝，并且小于这个等级取最接近被50整除的那个级别
//这样子对新手来说相对比较合适。
void reset_stat(object me)
{
	int level;
	if(!objectp(me))
		return;
	
	level=pow(me->query("combat_exp")/100,0.3333)*10;
	level=level*80/100;
	level=level/50;
	if ( level > 2 )
		level=level*2/3;
	if ( level > 2 )
		level=level-1;
	level=level*50;
	if(level<50)
		level=50;
	else if(level>500)
		level=500;
	
	set("combat_exp", (me->query("combat_exp")/100)*60);
	family_skill(this_object(), "xie", level, 1);
        
  set("max_qi", level*10);
  set("eff_qi", level*10);
  set("qi", level*10);
  set("max_jing", level*10);
  set("eff_jing", level*10);
  set("jing", level*10);
  set("max_jingli", level*10);
  set("jingli", level*10);
  set("max_neili", level*3);
  set("neili", level*3);

  set("uni_target",me);

  wield_weapon();
}

//土匪死了送杀死土匪的玩家道德和声望。
void die()
{
	object me;
	int exp;
	
	me=query("uni_target");
	if ( !objectp(me) )
	{
		::die();
		return;
	}
	exp=me->query("combat_exp")/10000000;
	if ( exp>9 )
		exp=9;
	exp=(exp+1)*10000000;
	if ( me->query("shen")< exp )
	{
	  message_vision(HIY"$N消灭了武当山周围无恶不作的土匪，附近地村民都非常感激！\n"NOR, me);
	  me->add("shen",1000+random(3)*500);
	  me->add("repute",100+random(3)*100);
	}
	else
		message_vision(HIC"大侠$N又消灭了武当山周围无恶不作的土匪。\n"NOR, me);
	::die();
}

varargs void wield_weapon(string weapon)
{
  if(!weapon && query("use_weapon1"))
    wield_weapon(query("use_weapon1"));
  if(!weapon && query("use_weapon2"))
    wield_weapon(query("use_weapon2"));
  if(!weapon)
    return;
  
  switch(weapon)
  {
  case "sword":
    carry_object("/clone/weapon/changjian")->wield();
    break;
  case "blade":
    carry_object("/clone/weapon/gangdao")->wield();
    break;
  case "staff":
    carry_object("/clone/weapon/gangzhang")->wield();
    break;
  case "whip":
    carry_object("/clone/weapon/changbian")->wield();
    break;
  case "zhen":
    set("gender", "无性");
    carry_object("/d/city/obj/flower_shoe")->wear();
    carry_object("/d/city/obj/pink_cloth")->wear();
    carry_object("/d/city/obj/goldring")->wear();
    carry_object("/d/city/obj/necklace")->wear();
    carry_object("/d/quanzhou/obj/xiuhua")->wield();
    carry_object("/d/riyuejiao/obj/xiuhuajia");
    break;
  case "dagger":
    carry_object("/clone/weapon/bishou")->wield();
    break;
  case "xiao":
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/obj/shizi");
    carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
    break;
  case "ling":
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/npc/obj/jinhua");
    carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
    break;
  case "hammer":
    carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
    break;
  default:
  }
  return;
}

int do_kaowen()
{
	object me;
	
	me=this_player();
	if(!query("in_kun"))
		return notify_fail("土匪不屑得瞅了瞅你，想从我这里得到消息，还是打赢我再说吧！\n");
	else if(query("in_kaowen"))
		return notify_fail("你正在拷问土匪！\n");
	else if(!me->query_temp("quest_fighter/name"))
		return notify_fail("你不知道想从土匪哪里获得什么消息，也无从拷问！\n");
	
	set("in_kaowen",1);
	if(random(100)<10) {
		tell_object(me,"土匪向你求饶道：好汉别打了！我这就领你从小路进到山寨里面去。\n");
		tell_object(me,"你解开了捆绑在土匪上的绳子，让土匪在前面引路。\n");
		remove_call_out("in_kun");
		this_object()->move("/newbiequest/wudang/fighter/xiaolu");
		me->move("/newbiequest/wudang/fighter/xiaolu");
		call_out("move_next",5,me);
	}
	else {
		tell_object(me, "你正在使劲地拷问土匪关于"+me->query_temp("quest_fighter/name")+"的下落，但是土匪什么也不说。\n");
		call_out("in_kaowen",5,me,0);
	}
	return 1;
}

//拷问的时候成功几率随着时间逐步增加
void in_kaowen(object me,int times)
{
	if(random(100)<10+5*times) {
		tell_object(me,"土匪向你求饶道：好汉别打了！我这就领你从小路进到山寨里面去。\n");
		tell_object(me,"你解开了捆绑在土匪上的绳子，让土匪在前面引路。\n");
		set("in_kun",-1);
		this_object()->move("/newbiequest/wudang/fighter/xiaolu");
		me->move("/newbiequest/wudang/fighter/xiaolu");
		call_out("move_next",5,me);
	}
	else {
		tell_object(me, "你正在使劲地拷问土匪关于"+me->query_temp("quest_fighter/name")+"的下落，但是土匪什么也不说。\n");
		call_out("in_kaowen",5,me,times+1);
	}
}

int move_next(object me)
{
	tell_object(me, "土匪说到：前面不远就是我们山寨，我只能送你到这里了。\n");
	me->move("/d/wudang/tufeicun");
	call_out("destroying",1,this_object());
}

void destroying(object ob) {
	destruct(ob);
}