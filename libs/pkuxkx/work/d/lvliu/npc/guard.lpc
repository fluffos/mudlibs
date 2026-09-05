
#include <ansi.h>

inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);
int do_set_skill();

void create()
{
	set_name("劲装武士", ({ "jinzhuang wushi", "wushi" }) );
	set("gender", "男性" );
	set("age", 22+random(10));
	set("long", "这是一个全副武装的劲装武士，看上去杀气腾腾，一副致人死地的模样。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
    set("food", 500);
    set("water", 500);
	set("chat_chance", 25);
	set("max_qi", 20000);
	set("eff_qi", 20000);
	set("qi", 20000);
	set("max_jing", 20000);
	set("eff_jing", 20000);
	set("jing", 20000);
	set("max_jingli", 12000);
	set("jingli", 24000);
	set("max_neili", 12000);
	set("neili", 24000);
	setup();
    carry_object("/clone/armor/jinzhuang")->wear();
    carry_object("/clone/armor/tiejia")->wear();
	do_set_skill();
}

int do_set_skill()
{
	int level;
	int succ_times = 0;
	int addition = 1;
	int life = 0;
	object me = this_object();	
	set("level",to_int(pow(me->query("combat_exp")/400, 0.333)));
	level = pow(me->query("combat_exp")/100, 0.333) * 9;
	family_skill(this_object(), "random", level, 1);
	set("chat_chance_combat", 20);
	wield_weapon();
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

