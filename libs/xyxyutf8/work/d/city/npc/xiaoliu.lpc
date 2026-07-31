#include <ansi.h>
inherit NPC;

nosave string goods_msg="";
nosave mapping goods_list = ([]);
nosave mapping temp_list = ([]);
void init_shop_goods();

void create()
{
	set_name("姚富贵", ({"yao fugui", "yao"}));
       	set("long",
"姚老板是高家集人，后来挣了钱，开了家布店。\n");
       	set("gender", "男性");
        set("title", "布店老板");
        set("combat_exp", 10000);
       	set("age", 36);
       	set("attitude", "friendly");
       	set("shen_type", 1);
       	set_skill("unarmed", 35);
	set_skill("dodge", 30);
	set_skill("parry", 35);
        setup();
       	carry_object(0,"cloth",random(2))->wear();
       	init_shop_goods();
}

void init()
{
	::init();
        add_action("do_list", "list");
}

string goods_msg(object ob)
{
	string arg,*str;
	int i;
	mapping equip_apply_prop,equip_apply_prop2,prop = ob->equip_base(ob);
	if( !prop || !mapp(prop) )
		return 0;
	str = keys(prop);
	if( !str || !arrayp(str) || sizeof(str)<1 )
		return 0;
	equip_apply_prop = ([
		"spells_def"	: "法术防御",
		"spells_damage"	: "法术攻击",
		"combat_def"	: "物理防御",
		"combat_damage"	: "物理攻击",
		"strength"	: "后天体格",
		"courage"	: "后天胆识",
		"intelligence"	: "后天悟性",
		"spirituality"	: "后天灵性",
		"composure"	: "后天定力",
		"personality"	: "后天魅力",
		"constitution"	: "后天根骨",
		"karma"		: "后天福缘",
		"max_kee"	: "气血后限",
		"max_sen"	: "精神后限",	
		"max_force"	: "内力后限",
		"max_mana"	: "法力后限",
		"max_gin"	: "活力后限",
       		"receive_force"	: "内力自动恢复",
       		"receive_mana"	: "法力自动恢复",
       		"receive_kee"	: "气血自动恢复",
       		"receive_sen"	: "精神自动恢复",
       		"reduce_busy"	: "僵直效果减少",
	]);
	equip_apply_prop2 = ([
		"re_spells_effdamage" : "法术损伤反弹百分比",
		"re_combat_effdamage" : "物理损伤反弹百分比",
	       	"attack"	: "攻击命中率",
       		"defense"	: "攻击闪避率",
	       	"spells_succ"	: "法术命中率",
       		"spells_dodge"	: "法术闪避率",
	       	"combat_succ"	: "物理命中率",
       		"combat_dodge"	: "物理闪避率",
	       	"combat_parry"	: "物理招架率",
       		"force_recover" : "吸气效果追加",
	       	"fofce_refresh"	: "凝神效果追加",
       		"receive_heal_kee"	: "气血恢复附加率",
		"receive_heal_sen"	: "精神恢复附加率",
		"receive_curing_kee"	: "气血治疗附加率",
	       	"receive_curing_sen"	: "精神治疗附加率",
       		"receive_exercise"	: "打坐恢复附加率",
		"receive_meditate"	: "冥思恢复附加率",
		"re_spells_damage" : "法术伤害反弹百分比",
		"re_combat_damage" : "物理伤害反弹百分比",
	]);
	arg = "";
	for(i=0;i<sizeof(str);i++)
	{
		if( undefinedp(equip_apply_prop2[str[i]]) 
		 && undefinedp(equip_apply_prop[str[i]]) )
			arg+= str[i];
		else if( !undefinedp(equip_apply_prop2[str[i]]) )
			arg+= equip_apply_prop2[str[i]]+"+"+ob->query("armor_prop/"+str[i])+"% ";
		else	arg+= equip_apply_prop[str[i]]+"+"+ob->query("armor_prop/"+str[i])+" ";
	}			
	return arg;		
}

void init_shop_goods()
{
	int i,k,level,base_value = 500;
	object ob;
	string *files = ({
		"armor","cloth","hand","kui","pifeng","shield",
		"shoes","waist","wrists",
	});
	level = 7;
	for(k=5;k<level;k++)
	{
		reset_eval_cost();
		for(i=0;i<sizeof(files);i++)
		{
			ob = new(sprintf("/d/obj/narmor/%s",files[i]));
			if( !ob )
				continue;
			if( !ob->init_armor(k) )
				continue;
			if( !undefinedp(temp_list[ob->short()]) )
				continue;	
			if( !temp_list || !mapp(temp_list) )
				temp_list = ([ ob->short() : files[i]+" "+k ]);
			else	temp_list[ob->short()] = files[i]+" "+k;	
			if( !goods_list || !mapp(goods_list) )
				goods_list = ([ files[i]+" "+k : ({files[i],k*base_value}),]);
			else	goods_list[files[i]+" "+k] = ({files[i],k*base_value});		
			goods_msg+= sprintf("%30-s  %4-s  %15-s  %s\n",ob->name()+"("+files[i]+" "+k+")",ob->query("level")+"",MONEY_D->money_str(k*base_value,1),goods_msg(ob));
			if( ob )
				destruct(ob);
		}
	}		
}

int do_list()
{
	string str;
	object me = this_player();
	printf("你可以购买下列这些东西：\n");
	printf(REV CYN"       名称                 等级要求    价格              属性         \n"NOR);
	me->start_more(goods_msg); 
	return 1;
}

int buy_object(object who,string str)
{
	string arg;
	object ob;
	int value,v;
	if( !goods_list || !mapp(goods_list) )
	{
		tell_object(who,"现在暂无商品可卖。\n");
		return -1;
	}
	if( undefinedp(goods_list[str]) )
	{
		tell_object(who,"没有此防具可买，请看清ID，比如 buy cloth 1 from xiaoxiao\n");
		return -1;
	}
	sscanf(str,"%s%d",arg,v);
	if( v<1 )
	{
		tell_object(who,"防具等级初始出错，请联系巫师。\n");
		return -1;
	}
	arg = goods_list[str][0];
	value = goods_list[str][1];
	if( value<=0 )
	{
		tell_object(who,"防具价格初始出错，请联系巫师。\n");
		return -1;
	}
	if( !who->check_pay(value) )
	{
		tell_object(who,"你身上的钱不足"+MONEY_D->money_str(value,1)+"。\n");
		return -1;
	}
	ob = new("/d/obj/narmor/"+arg);
	if( !ob )
	{
		tell_object(who,"防具初始出错，请联系巫师。\n");
		return -1;
	}
	if( !ob->init_armor(v) )
	{
		if( ob )  destruct(ob);
		tell_object(who,"防具初始出错，请联系巫师。\n");
		return -1;
	}
	if( !ob->move(who) )
	{
		if( ob )  destruct(ob);
		tell_object(who,"你的背包满了。\n");
		return -1;
	}
	if( !who->money_add(-value) )
	{
		if( ob )  destruct(ob);
		tell_object(who,"购买失败，请联系巫师。\n");
		return -1;
	}
	tell_object(who,HIY"你购买了一"+ob->query("unit")+ob->short()+HIY"。\n"NOR);		
	ob->set("value",1);		 
	return -1;
}
