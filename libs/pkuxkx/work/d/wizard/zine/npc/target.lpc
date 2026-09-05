//铜雀台陪练npc ZINE2012

#include <ansi.h>

inherit FAMILY_NPC;

varargs void wield_weapon(string weapon);
void die();
void create()
{
	int i=random(2);
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", i?"男性":"女性");
	set("title",HIY"铜雀台弟子"NOR);
	set("age", 22);
	set("long", "这是一名铜雀台的弟子。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("food",500);
    set("water",500);
	setup();
    carry_object("/d/wizard/zine/obj/cloth")->wear();
}

int do_copy(object me,int lv)
{
	int level,exp;
	exp=me->query("combat_exp")/10*(10+lv-1);
	level=to_int(pow(exp/100,0.333)*10);
	set("combat_exp",exp);
    family_skill(this_object(), "random", level, 1);
    set("chat_chance_combat", 150);
	set("max_qi", level * 10);
	set("eff_qi", level * 10);
	set("qi", level * 10);
	set("max_jing", level * 10);
	set("eff_jing", level * 10);
	set("jing", level * 10);
	set("max_jingli", level * 10);
	set("jingli", level * 10);
	set("max_neili", level * 15);
	set("neili", level * 30);
	set("level",lv+1);
	set("owner",me);
	wield_weapon();
}

void unconcious()
{
	object ob=this_object();
	object me = query("owner");
	if (ob->query("test_npc"))
	{
		environment(ob)->ResetTest(ob);
	}
	if(!me || !objectp(me))
	{

		message_vision(HIY"$N见不是你的对手，微一拱手，退了下去。\n"NOR,ob);
		destruct(ob);
		return;
	}
	if(!objectp(get_damage_origin_object()) || get_damage_origin_object() != me)
	{
		message_vision(HIY"$N见不是你的对手，微一拱手，退了下去。\n"NOR,ob);
		destruct(ob);
		return;
	}
	me->set_temp("tqt/liangong2/lv",query("level"));
	message_vision(HIY"$N见不是你的对手，微一拱手，退了下去。\n"NOR,ob);
	destruct(ob);
	return;
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
