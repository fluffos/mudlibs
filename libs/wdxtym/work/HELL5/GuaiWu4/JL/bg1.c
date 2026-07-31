// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_ARMOR;


int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_duanlian","lianjia");
	add_action("do_hui","huijia");
	add_action("do_levelup","jijia");
}


void create()
{
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	int lv1,lv2,lv3;
	
	me = this_player();
//读入数据
	w_name=me->query("jiajia/name");
	w_id = "my "+me->query("jiajia/id");
	w_or = me->query("jiajia/or");
	w_lv = me->query("jiajia/lv");
	lv1=me->query("jinjie/s1")*500;
	lv2=me->query("guizhen")*1000+me->query("zhengdao/s1")*100000+me->query("feisheng/s1")*50000000;
	
	lv3=(me->query("jinjie/s2"));		
        if (!me->query("jiajia/name"))
        {
	w_name=HIC "山君·护甲" NOR;
        }
        if (!me->query("jiajia/id"))
        {
	w_id="Shan Jun1";
        }
        if (!me->query("jiajia/or"))
        {
	w_or="千年神木";
        }
        if (!me->query("jiajia/lv"))
        {
	w_lv=1;
        }
        if (me->query("jiajia/lv",1) > 200)
        {
	w_lv=200;
        }

		set("material", "armor");
				 set("material", "crimson gold");  //原料

	set_name(w_name, ({w_id}));
	set("unit", "件");
		set("long", HIC"【山君限定】"NOR"山君系列								
"HIG"《套装加成：基础拳法等级+65，攻击力650》"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 65);
	set("armor_prop/unarmed_damage", 65+lv1+lv2+lv3);
	set("armor_prop/damage", 65+lv1+lv2+lv3);	

	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("armor_prop/baoji", w_lv * 2);
					set("no_drop", 1);
				set("no_sell", 1);
				set("no_steal", 1);
        set("no_put", 1);
        set("no_give", 1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("material", "armor");

	switch(w_or)
		{
		case "千年神木" :
			set_weight(500);
			set("material", "fur");
			break;
		case "海底金母" :
			set_weight(1000);
			set("material", "fur");
			break;
		case "寒丝羽竹" :
			set_weight(30);
			set("material", "fur");
			break;
		default :
		}
	set("unit", "件");
	if( me->query("jia/wear_msg"))
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N穿上"+w_name+"在身上。\n");
	if( me->query("jia/unequip_msg"))
		set("unequip_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("unequip_msg", "$N身上的"+w_name+"脱了下来，眨眼间已然不见影踪。\n");
	set("armor_type","armor");
		set("material", "armor");
				 set("suit",HIR"山君套装"NOR);  //套装名称
		set("suit_lvl",6);	     //套装等级
		set("suit_count",9);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","山君·护甲");
		set("suit_mod/finger","山君·戒指");
//		set("suit_mod/hands","山君·手套");
		set("suit_mod/head","山君·头饰");
		set("suit_mod/neck","山君·项链");
		set("suit_mod/pants","山君·护腿");
		set("suit_mod/boots","山君·护靴");
		set("suit_mod/cloth","山君·衣服");
//		set("suit_mod/surcoat","山君·披风");
//		set("suit_mod/shield","山君·护盾");
		set("suit_mod/waist","山君·腰带");
		set("suit_mod/wrists","山君·护腕");
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/constitution",4);      //3件
		set("suit_eff/spirituality",4);      // 5件
		set("suit_eff/intelligence",4);      //7件
		set("suit_eff/strength",4);      //9件
	       //套装全部附加技能效果，一整套
        set("suit_eff_skill/cuff",65+me->query("taozhuang/lv"));
	setup();
}



