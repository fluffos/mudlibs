// File         : killer.c
// Created By   : whuan@pkuxkx, 2007-07-02
#include <ansi.h>
inherit FAMILY_NPC;
#include <random_name.h>
void do_leave()
{
        if(!this_object())
                return;
        message_vision("$N看了看天色，自言自语道：“天色不早了，得去干活了。”\n", this_object());
        destruct(this_object());
}
int leave()
{
	command("hehe");
	do_leave();
}
void create()
{
        set_name(get_rndname(), ({get_rndid(), }));
        set("gender", "男性" );
        set("age", 22+random(22));
        set("combat_exp", 10000000);
        set("attitude", "heroism");
        add("inquiry", ([
                "name" : "大爷我有要事在身，别烦我！",
                "here" : "大爷我有要事在身，别烦我！",
        ]));
        set("chat_chance", 40);
        set("uni_target", 1);
        set("jiali", 50);
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        call_out("do_leave", 1800);
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
int do_copy(object me)  
{                       
		int exp;
		int skill, str;
		int index;
		int factor;
		string my_family=me->query("family/family_name"),title="隐世";
		mapping family=(["神龙教":"shenlongjiao","少林派":"shaolin","武当派":"wudang", "峨嵋派":"emei", "丐帮":"gaibang",
	"天龙寺":"tianlong", "天地会":"tiandihui", "华山派":"huashan1", "全真派":"quanzhen","雪山派":"xueshan","星宿派":"xingxiu", 
			"白驼山":"baituo", "日月神教":"riyuejiao","大轮寺":"dalunsi","桃花岛":"taohua", "古墓派":"gumu", "灵鹫宫":"lingjiu", 
			"姑苏慕容":"murong", "明教":"mingjiao" , "朝廷":"chaoting",]);
		if(!objectp(me)) return 0;
		if (stringp(my_family))
		my_family=family[my_family];
		else
		my_family="random";
		if (me->query("family/family_name"))
		title=me->query("family/family_name");
		title+="高手";
		set("title",HBWHT+HIR+title+NOR);
		exp=me->query("combat_exp");
		index=me->query("shenlong_zhanglao/times")/250;
		//family_skill会set npc的chat_chance_combat为100，这个变态！
		//必须把family_skill放在最前面！ 
		skill=pow(exp/100.0,1.0/3)*10;
		family_skill(this_object(), my_family, skill, 1);
		set("chat_chance_combat", 40);
		set("combat_exp",exp);    
		set("level",me->query("level")+1+random(5));
		str=me->query_str();
		if ( str > 150 ) 
		str=150;
		if ( me->query("shenlong_zhanglao/times") < 1000 )
		{
			set("max_qi", str * 200);
			set("eff_qi", str * 200);
		}
		else if ( me->query("shenlong_zhanglao/times") < 5000 )
		{
			set("max_qi", str * 250);
			set("eff_qi", str * 250);
		}
		else if ( me->query("shenlong_zhanglao/times")<= 12500 )
		{
			set("max_qi", str * 300 );
			set("eff_qi", str * 300 );
		}
		else 
		{
			set("max_qi", str * 325 );
			set("eff_qi", str * 325 );
		}
		set("qi", query("eff_qi"));
		set("max_jing", me->query("max_jing"));
        set("eff_jing", me->query("max_jing"));
        set("jing", me->query("max_jing"));
        set("max_neili", me->query("max_neili"));
        set("neili", me->query("max_neili"));
        set("max_jingli", me->query("max_jingli"));
        set("jingli", me->query("max_jingli"));
        set("jiali",150);
		set("gender",me->query("gender"));
        wield_weapon();
}

void die()
{
	object me = query("uni_target"),mykiller; 
	if( !objectp(mykiller = get_damage_origin_object()) || mykiller->query("id")!= me->query("id"))
	{
		message_vision(HIC"$N说道：“你...”，话没说完，两眼翻白，腿儿蹬了几下，脑袋一歪，死了。\n",this_object());
		::die();
		return;
	}
	me->set("drilled",1);
	message_vision(HIC"$N不自量力，被$n干掉了。\n",this_object(),me);
	me->tell_owner();
	destruct(this_object());
	return;
}