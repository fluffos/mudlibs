// m_shenbing.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
inherit S_WEAPON;

int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
	add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
}


void create()
{
	object me;
	string w_name,w_id,w_or,p_name,name;
	int w_lv,dj,color;
	me = this_player();
//读入数据
	w_name=me->query("shenbing/name");
	w_id = "my "+me->query("shenbing/id");
	w_or = me->query("shenbing/or");
	w_lv = me->query("shenbing/lv");
	p_name = HIY"无上神品"NOR;
	dj = me->query("shenbing/dj");
        color = w_lv / 2;

	if (me->query("shenbing/pin"))
	{
		p_name = me->query("shenbing/pin");
	}
        switch(color){
                case 1:
                        name = WHT + p_name + w_name + NOR;
                        break;
                case 2:
                        name = HIR + p_name + w_name + NOR;
                        break;
                case 3:
                case 4:
                        name = HIB + p_name + w_name + NOR;
                        break;
                case 5:
                        name = HIY + p_name + w_name + NOR;
                        break;
                case 6:
                        name = HIM + p_name + w_name + NOR;
                        break;
                case 7:
                        name = MAG + p_name + w_name + NOR;
                        break;
                case 8:
                        name = HIW + p_name + w_name + NOR;
                        break;
                case 9:
                        name = HIC + p_name + w_name + NOR;
                        break;
                default:
                        name = HIG + p_name + w_name + NOR;
                        break;
        }
	if (!me->query("shenbing/name"))
	{
		w_name="自制的神兵";
	}
	if (!me->query("shenbing/id"))
	{
		w_id="shenbing";
	}
	if (!me->query("shenbing/or"))
	{
		w_or="千年神木";
	}
	if (!me->query("shenbing/lv"))
	{
		w_lv=5;
	}
	if (!me->query("shenbing/dj"))
	{
		dj=1;
	}
	/*if (me->query("weapon/lv",1) > 150)
	{
		w_lv=150;
	}*/

	set_name(name, ({w_id}));
	set("unit", "口");
	set("weapon_prop/baoji", w_lv * 2);
	set("weapon_prop/shenbing", me->query("shenbing/weapon"));
	set("pin",me->query("shenbing/pin"));
	set("value",1000);
	set("ownmake",1);
	set("no_sell",1);
	set("no_give",1);
	set("no_put",1);
    set("shenbing/s1",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "千年神木" :
			set_weight(500);
			set("material", "iron");
			break;
		case "海底金母" :
			set_weight(1000);
			set("material", "steel");
			break;
		case "寒丝羽竹" :
			set_weight(30);
			set("material", "bamboo");
			break;
		default :
		}
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	else
		set("wield_msg", "$N往腰中一带，抽出了一口"+name+"握在手中。\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
	else
		set("unwield_msg", "$N手中"+name+"迎风一抖，眨眼间已然不见影踪。\n");
	if (!me->query("shenbing/pin"))
		init_dagger(w_lv * 10 *dj);
	else if (me->query("shenbing/pin") == "后天神品")
		init_dagger(w_lv * 15 *dj);
	else if (me->query("shenbing/pin") == "先天神品")
		init_dagger(w_lv * 18 *dj);
	else if (me->query("shenbing/pin") == "太上仙品")
		init_dagger(w_lv * 21 *dj);
	else if (me->query("shenbing/pin") == "仙君一品")
		init_dagger(w_lv * 22 *dj);
	else if (me->query("shenbing/pin") == "仙君二品")
		init_dagger(w_lv * 23 *dj);	
	else if (me->query("shenbing/pin") == "仙君三品")
		init_dagger(w_lv * 24 *dj);
	else if (me->query("shenbing/pin") == "仙君四品")
		init_dagger(w_lv * 25 *dj);
	else if (me->query("shenbing/pin") == "仙君五品")
		init_dagger(w_lv * 26 *dj);
	else if (me->query("shenbing/pin") == "仙君六品")
		init_dagger(w_lv * 27 *dj);
	else if (me->query("shenbing/pin") == "仙君七品")
		init_dagger(w_lv * 28 *dj);		
	else if (me->query("shenbing/pin") == "仙君八品")
		init_dagger(w_lv * 29 *dj);		
	else if (me->query("shenbing/pin") == "仙君九品")
		init_dagger(w_lv * 30 *dj);		
	else if (me->query("shenbing/pin") == "仙君十品")
		init_dagger(w_lv * 31 *dj);		
	else if (me->query("shenbing/pin") == "仙君十一品")
		init_dagger(w_lv * 32 *dj);		
	else if (me->query("shenbing/pin") == "仙君十二品")
		init_dagger(w_lv * 33 *dj);		
	else if (me->query("shenbing/pin") == "仙君十三品")
		init_dagger(w_lv * 34 *dj);			
	else if (me->query("shenbing/pin") == "仙君十四品")
		init_dagger(w_lv * 35 *dj);		
	else if (me->query("shenbing/pin") == "仙君十五品")
		init_dagger(w_lv * 36 *dj);		
	else if (me->query("shenbing/pin") == "仙君十六品")
		init_dagger(w_lv * 37 *dj);		
	else if (me->query("shenbing/pin") == "仙君十七品")
		init_dagger(w_lv * 38 *dj);		
	else if (me->query("shenbing/pin") == "仙君十八品")
		init_dagger(w_lv * 39 *dj);		
	else if (me->query("shenbing/pin") == "仙君十九品")
		init_dagger(w_lv * 40 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十品")
		init_dagger(w_lv * 41 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十一品")
		init_dagger(w_lv * 42 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十二品")
		init_dagger(w_lv * 43 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十三品")
		init_dagger(w_lv * 44 *dj);			
	else if (me->query("shenbing/pin") == "仙君二十四品")
		init_dagger(w_lv * 45 *dj);			
	else if (me->query("shenbing/pin") == "仙君二十五品")
		init_dagger(w_lv * 46 *dj);			
	else if (me->query("shenbing/pin") == "仙君二十六品")
		init_dagger(w_lv * 47 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十七品")
		init_dagger(w_lv * 48 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十八品")
		init_dagger(w_lv * 49 *dj);		
	else if (me->query("shenbing/pin") == "仙君二十九品")
		init_dagger(w_lv * 50 *dj);			
	else if (me->query("shenbing/pin") == "仙君三十品")
		init_dagger(w_lv * 51 *dj);			
	else if (me->query("shenbing/pin") == "仙君三十一品")
		init_dagger(w_lv * 52 *dj);			
	else if (me->query("shenbing/pin") == "仙君三十二品")
		init_dagger(w_lv * 53 *dj);			
	else if (me->query("shenbing/pin") == "仙君三十三品")
		init_dagger(w_lv * 54 *dj);				
	else if (me->query("shenbing/pin") == "仙君三十四品")
		init_dagger(w_lv * 55 *dj);				
	else if (me->query("shenbing/pin") == "仙君三十五品")
		init_dagger(w_lv * 56 *dj);				
	else if (me->query("shenbing/pin") == "仙君三十六品")
		init_dagger(w_lv * 57 *dj);				
	else if (me->query("shenbing/pin") == "仙君三十七品")
		init_dagger(w_lv * 58 *dj);				
	else if (me->query("shenbing/pin") == "仙君三十八品")
		init_dagger(w_lv * 59 *dj);				
	else if (me->query("shenbing/pin") == "仙君三十九品")
		init_dagger(w_lv * 60 *dj);				
	else if (me->query("shenbing/pin") == "仙君四十品")
		init_dagger(w_lv * 61 *dj);				
	else if (me->query("shenbing/pin") == "仙君四十一品")
		init_dagger(w_lv * 62 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十二品")
		init_dagger(w_lv * 63 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十三品")
		init_dagger(w_lv * 64 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十四品")
		init_dagger(w_lv * 65 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十五品")
		init_dagger(w_lv * 66 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十六品")
		init_dagger(w_lv * 67 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十七品")
		init_dagger(w_lv * 68 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十八品")
		init_dagger(w_lv * 69 *dj);			
	else if (me->query("shenbing/pin") == "仙君四十九品")
		init_dagger(w_lv * 70 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十品")
		init_dagger(w_lv * 71 *dj);					
	else if (me->query("shenbing/pin") == "仙君五十一品")
		init_dagger(w_lv * 72 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十二品")
		init_dagger(w_lv * 73 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十三品")
		init_dagger(w_lv * 74 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十四品")
		init_dagger(w_lv * 75 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十五品")
		init_dagger(w_lv * 76 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十六品")
		init_dagger(w_lv * 77 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十七品")
		init_dagger(w_lv * 78 *dj);			
	 if (me->query("shenbing/pin") == "仙君五十八品")
		init_dagger(w_lv * 79 *dj);			
	else if (me->query("shenbing/pin") == "仙君五十九品")
		init_dagger(w_lv * 80 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十品")
		init_dagger(w_lv * 81 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十一品")
		init_dagger(w_lv * 82 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十二品")
		init_dagger(w_lv * 83 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十三品")
		init_dagger(w_lv * 84 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十四品")
		init_dagger(w_lv * 85 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十五品")
		init_dagger(w_lv * 86 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十六品")
		init_dagger(w_lv * 87 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十七品")
		init_dagger(w_lv * 88 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十八品")
		init_dagger(w_lv * 89 *dj);			
	else if (me->query("shenbing/pin") == "仙君六十九品")
		init_dagger(w_lv * 90 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十品")
		init_dagger(w_lv * 91 *dj);				
	else if (me->query("shenbing/pin") == "仙君七十一品")
		init_dagger(w_lv * 92 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十二品")
		init_dagger(w_lv * 93 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十三品")
		init_dagger(w_lv * 94 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十四品")
		init_dagger(w_lv * 95 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十五品")
		init_dagger(w_lv * 96 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十六品")
		init_dagger(w_lv * 97 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十七品")
		init_dagger(w_lv * 98 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十八品")
		init_dagger(w_lv * 99 *dj);			
	else if (me->query("shenbing/pin") == "仙君七十九品")
		init_dagger(w_lv * 100 *dj);			
	else if (me->query("shenbing/pin") == "仙君八十品")
		init_dagger(w_lv * 101 *dj);					
	else if (me->query("shenbing/pin") == "仙君八十一品")
		init_dagger(w_lv * 102 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十二品")
		init_dagger(w_lv * 103 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十三品")
		init_dagger(w_lv * 104 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十四品")
		init_dagger(w_lv * 105 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十五品")
		init_dagger(w_lv * 106 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十六品")
		init_dagger(w_lv * 107 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十七品")
		init_dagger(w_lv * 108 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十八品")
		init_dagger(w_lv * 109 *dj);				
	else if (me->query("shenbing/pin") == "仙君八十九品")
		init_dagger(w_lv * 110 *dj);				
	else if (me->query("shenbing/pin") == "仙君九十品")
		init_dagger(w_lv * 111 *dj);							
	
	
	
	setup();
}



int do_duanlian(object weapon,object me)
{
	object obj;
	int w_zhi, w_level;
	string w_or;
	string arg;
		me=this_player();

obj=present("xueye", me);//渡渡加入锻造兵器系统

	if( !weapon )
		return notify_fail("你要锻炼什么?\n");

	if (me->is_fighting())
		return notify_fail("你打着呢?\n");

	if (me->is_busy())
		return notify_fail("你忙着呢?\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("你的内力不够，无法锻炼剑气！\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不够，无法锻炼兵器！\n");

	if (userp(me) && !me->query_skill_mapped("force"))
		return notify_fail("你没有内功，在使用中啊!\n");
		
	if(!present("xueye", me))
		return notify_fail("你的身上没有树精之血或者数量不足不足5！\n");
		
	if(!present("xueye", me)&& obj->query_amount()<5)
		return notify_fail("你的身上没有树精之血或者数量不足5！\n");
		
	if ( obj->query_amount()<5)
		return notify_fail("你的身上没有树精之血或者数量不足5！\n");
		
	if( me->query_skill("shenzhao-jing", 1) > 100
            && (int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力不够，无法锻炼兵器！\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的气不够，无法锻炼剑气！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你现在的体力太弱，无法锻炼剑气！\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("你现在的精力无法集中，不能锻炼剑气！\n");


	message_vision(HIR "$N左手直指剑脊，右手手握树精血液将其一丝丝的传了进去。\n" NOR, me);

	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("weapon_max",5);
	me->add("weapon/lv",5);
		obj->add_amount(-5);

		message_vision(HIY "剑身忽的一亮，一道金光隐入$N的剑体，不见了！\n" NOR,me);
		message_vision(HIG "$N的剑的等级提高了！\n" NOR, me);
	message_vision(HIC "$N的剑气提升了!\n" NOR, me);
		message("vision",ZJCHANNEL+ HIC"炼"HIM"器"HIW"："HIC""+me->query("name")+"("+me->query("id")+")将树精之血导入武器之中，武器等级得到提升！\n" NOR, users());		

	return 1;
}


int do_hui(object weapon)
{
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("你要摧毁什么?\n");
	message_vision(HIR "$N大喝一声，一掌擎剑，一掌猛力击下。结果轰隆一声巨响"
			+w_name+HIR"断为两截!\n" NOR,me);
	me->set("weapon/make",0);
	destruct( this_object() );
	me->delete("weapon");

	me->save();

	return 1;
}
/*void owner_is_killed()
{
        write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
        this_object()->unequip();
        this_object()->reset_action();
        this_object()->set("name", query("name") + "的碎片");
        this_object()->set("value", 0);
        this_object()->set("weapon_prop", 0);
}*/
