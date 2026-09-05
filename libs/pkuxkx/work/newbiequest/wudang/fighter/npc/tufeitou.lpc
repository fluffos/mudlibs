//tufei.c 土匪
//seagate@pkuxkx 2010/11/06

#include <ansi.h>
inherit FAMILY_NPC;
varargs void wield_weapon(string);

void create()
{
  set_name("土匪头", ({ "tufei tou", "robber" }));
  set("long", "他是武当山脚下的土匪，长得一脸横肉。\n");
  set("age", 20+random(20));
  set("attitude", "heroism");
  set("combat_exp", 500000);
  set("food",500);
  set("water",500);
  set("chat_chance_combat", 15);
  set("can_kun",1);
  setup();
  carry_object("/clone/armor/bianfuxuejia")->wear();
  call_out("destroying",1800,this_object());
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
	level=(level/50)*50;
	if(level<50)
		level=50;
	else if(level>1000)
		level=1000;
	
	set("combat_exp", (me->query("combat_exp")/100)*120);
	family_skill(this_object(), "xie", level, 1);

  set("max_qi", level*40);
  set("eff_qi", level*40);
  set("qi", level*40);
  set("max_jing", level*40);
  set("eff_jing", level*40);
  set("jing", level*40);
  set("max_jingli", level*10);
  set("jingli", level*10);
  set("max_neili", level*10);
  set("neili", level*10);

  set("uni_target",me);
  set_face("special",me->query("name")+"的土匪头",({me->query("id")+"'s tufeitou","tufei tou","robber"}),1000);

  wield_weapon();
}

//土匪死了送杀死土匪的玩家道德和声望。
void die()
{
	object me;
	
	me=query("uni_target");
	if ( objectp(me) )
	{
	  message_vision(HIY"$N消灭了武当山周围无恶不作的土匪，附近地村民都非常感激！\n"NOR, me);
	  me->add("shen",5000+random(5)*1000);
	  me->add("repute",200+random(5)*100);
  }
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

void destroying(object ob) {
	destruct(ob);
}
