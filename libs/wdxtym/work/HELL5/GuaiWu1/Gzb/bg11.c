// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_WAIST;


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
	w_name=HIC "怪物之腰" NOR;
        }
        if (!me->query("jiajia/id"))
        {
	w_id="guaiwu8";
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

        set("material", "fur");
	set_name(w_name, ({w_id}));
	set("unit", "件");
		set("long", HIC"【怪物限定】"NOR"怪物系列								
"HIG"《套装加成：基础刀法等级+50，攻击力500》"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 50);
	set("armor_prop/unarmed_damage", 50+lv1+lv2+lv3);
	set("armor_prop/damage", 50+lv1+lv2+lv3);	
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
	set("material", "fur");

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
	set("armor_type","waist");
		set("material", "fur");
				 set("suit",HIR"怪物"NOR);  //套装名称
		set("suit_lvl",8);	     //套装等级
		set("suit_count",9);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","怪物甲");
		set("suit_mod/finger","怪物戒");
//		set("suit_mod/hands","怪物手");
		set("suit_mod/head","怪物盔");
		set("suit_mod/neck","怪物链");
		set("suit_mod/pants","怪物腿");
		set("suit_mod/boots","怪物靴");
		set("suit_mod/cloth","怪物衣");
//		set("suit_mod/surcoat","怪物披");
//		set("suit_mod/shield","怪物盾");
		set("suit_mod/waist","怪物腰");
		set("suit_mod/wrists","怪物腕");
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性第三，臂力第四
		set("suit_eff/constitution",50);      //3件
		set("suit_eff/spirituality",50);      // 5件
		set("suit_eff/intelligence",50);      //7件
		set("suit_eff/strength",50);      //9件
	       //套装全部附加技能效果，一整套
		set("suit_eff_skill/force",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/dodge",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/parry",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/unarmed",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/cuff",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/strike",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/finger",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/hand",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/claw",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/sword",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/blade",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/staff",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/hammer",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/club",50+me->query("taozhuang/lv"));
        set("suit_eff_skill/whip",50+me->query("taozhuang/lv"));
	setup();
}



