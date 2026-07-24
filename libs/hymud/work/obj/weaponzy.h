mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n,sharpness,damage;
object weapon;
string msg1,msg2,msg3;
sharpness=query("sharpness");
if (!sharpness) sharpness=0;
msg1="";
if (random(sharpness) > 1 && random(8)==0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", (sharpness*2) * 10);
//sharpness=sharpness*2;
                victim->receive_damage("qi", (sharpness*3) * 10,me);
                victim->receive_wound("qi", (sharpness*3) * 10,me);
                return RED "$N" HIY "手中"+query("name")+RED"一颤，漾起层层金光，顿时将$n"
                       RED "划伤！鲜血顺着$n身上直往下流！\n" NOR;
}
else if (random(2)==0)
{
        switch (random(18) )
        {

        case 0:
                if (query("wtypeA") >0)
{
                if (! victim->is_busy())
                victim->receive_wound("qi", (query("wtypeA")*3) * 20,me);
                victim->start_busy(query("wtypeA") + 2);
                return query("name")+HIY"金光一闪，闪过了$n的双眼！"
                       "$n" HIY "只觉头晕目眩，几欲昏厥！\n" NOR;
}
        case 1:
                if (query("wtypeB") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", (query("wtypeB")*5) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", (query("wtypeB")*5) * 50);
                return query("name")+ CYN "绿光一闪，$N" CYN "身边树木的生命活力"
                       "使$N" CYN "的身体得到了恢复！\n" NOR;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", (query("wtypeC")*5) * 30);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", (query("wtypeC")*5) * 30);
                victim->start_busy(3);
                return query("name")+ GRN "水光一闪，$N" GRN "的气色好一些"
                       "$n感到一阵冰凉，不能动弹了！\n" NOR;
}
        case 3:
                 if (query("wtypeD") >0)
{

                victim->receive_damage("qi", (query("wtypeD")*7) * 50,me);
                victim->receive_wound("qi", (query("wtypeD")*7) * 50,me);
                return query("name")+ RED "火光一闪，$n" RED "大叫一声 不好"
                       "$n浑上烧着了！\n" NOR;
}
        case 4:
                if (query("wtypeE") >0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )
                me->add("neili", (query("wtypeE")*5) * 60);
                return query("name")+ GRN "土光一闪，$N" GRN "丹田一暖，的元气恢得了不少。\n" NOR;                                           
 }
        case 5:
                if (query("wtypeF") >0)
{
damage = 15 * (query("wtypeF")*6) ;
if (victim->query_temp("apply/dodge",1) >= 0)
		victim->add_temp("apply/dodge", -(8 * query("wtypeF")));
if (victim->query_temp("apply/defense",1) >= 0)
		victim->add_temp("apply/defense", -(8 * query("wtypeF")));
//if (victim->query_temp("apply/dodge",1) < 0) victim->set_temp("apply/dodge",0);
//if (victim->query_temp("apply/defense",1) < 0) victim->set_temp("apply/defense",0);

victim->start_busy(random(query("wtypeF")) + 1);
		if ((int)victim->query("qi")+10 > damage)
		victim->receive_wound("qi", damage,me);
                
                return query("name")+ HIM "招来一阵风，飞舞在空中的无形之利刃包围着$n，$n" HIM "只觉寸步难行！\n" NOR;
}
        case 6:
                if (query("wtypeG") >0)
{

			damage = 30 * (query("wtypeG")*5) ;
if ((int)victim->query("neili")+10 > (damage*30))
		victim->add("neili", -damage*30);
if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage,me);
                return query("name")+ HIW "招来一道雷，一闪而过击中了$n，$n" HIW "只觉得全身又痛又麻！\n" NOR;
}
        case 7:
                if (query("wtypeH") >0)
{
damage = 10 * (query("wtypeH")*5) ;
if (victim->query_temp("apply/attack",1) >= 0)
		victim->add_temp("apply/attack", -(8 * query("wtypeH")));
if (victim->query_temp("apply/parry",1) >= 0)
		victim->add_temp("apply/parry", -(8 * query("wtypeH")));
//if (victim->query_temp("apply/attack",1) < 0) victim->set_temp("apply/attack",0);
//if (victim->query_temp("apply/parry",1) < 0) victim->set_temp("apply/parry",0);

victim->receive_wound("qi", (query("wtypeH")) * 10,me);
victim->start_busy(random(query("wtypeH")) + 1);
		if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage,me);
                return query("name")+ HIB "招来一阵电，电光一闪击中了$n，$n" HIB "只觉混身麻痹！\n" NOR;

}
        case 8:
                if (query("wtypeI") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", (query("wtypeI")*5) * 20);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", (query("wtypeI")*5) * 20);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")  )
                me->add("eff_jing", (query("wtypeI")*5) * 20);
if( (int)me->query("jing") < (int)me->query("max_jing")  )
                me->add("jing", (query("wtypeI")*5) * 20);
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", (query("wtypeI")*5) * 30);
                return query("name")+ WHT "闪过天空的光泽，$N" WHT "全身气色发身了变化\n" NOR;

}
        case 9:
                if (query("wtypeJ") >0)
{
victim->receive_wound("qi", (query("wtypeJ")*3) * 20,me);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*4);
victim->receive_wound("qi", (query("wtypeJ")) * 10,me);
                return query("name")+ YEL "闪过大地的光泽，黄色的烟雾从地上出现包围了$n，$n" YEL "只觉气血一阵逆流！\n" NOR;
}
        case 10:
                if (query("wtypeK") >0)
{

		if (objectp(weapon = victim->query_temp("weapon"))) {
			if (random(query("weapon_prop/damage")) > weapon->query("weapon_prop/damage") / 2
			&& random(me->query("str")) > victim->query("str") / 2
			&& random(6)==0) {
				victim->start_busy(random(query("wtypeK")) + 3);
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{

					message_vision(HIW"只听见「哐」地一声轻响，$N手中的" + weapon->query("name") + HIW"已经被" + query("name") + HIW"削为两截！\n"NOR, victim);
					weapon->unequip();
					weapon->move(environment(victim));
					weapon->set("name", "断掉的" + weapon->query("name"));
					weapon->set("value", 0);
					weapon->set("weapon_prop", 0);
					victim->reset_action();
}
else
{
victim->receive_wound("qi", (query("wtypeK")*3) * 20,me);	
}	

}
victim->receive_wound("qi", (query("wtypeK")*3) * 20,me);
}

if( (int)victim->query("neili") >0  )
                victim->add("neili", -(query("wtypeK")*5) * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*4  )
                me->add("neili", (query("wtypeK")*5) * 60);

                return query("name")+ HIC "闪过人类的王者之气。$n" HIC "双眼一花，觉和全身的内力给王者之气吸走了！\n" NOR;
}
        case 11:
                if (query("wtypeL") >0)
{

if( (int)victim->query("eff_qi") >0  )
                victim->add("eff_qi", -(query("wtypeL")*5) * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*5  )
                me->add("eff_qi", (query("wtypeL")*5) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*5  )
                me->add("qi", (query("wtypeL")*5) * 50);


if( (int)victim->query("eff_jing") >0  )
	victim->receive_wound("jing", -(query("wtypeL")*5) * 30,me);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*5  )
                me->add("eff_jing", (query("wtypeL")*5) * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*5  )
                me->add("jing", (query("wtypeL")*5) * 30);                
victim->receive_wound("qi", (query("wtypeL")) * 12,me);
return query("name")+ HIR "魔光一现，$n" HIR "只觉鬼哭狼嚎声不绝于耳，三魂六魄都给吸了出去！！\n" NOR;                                                                                                                                        
}


      case 12:
                if (query("wtypeC") >0 && (query("weapon_prop/strength") >0 && query("weapon_prop/neili") >0))
{
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )  me->add("neili", (query("wtypeC")*2) * 150);

msg1=query("name") + HIG"灵光一闪！恢复了"+me->query("name")+"的内力 ";

if( (int)victim->query("eff_qi") >0  )
victim->receive_wound("jing", -(query("wtypeC")*6) * 280,me);
msg1=msg1+victim->query("name")+HIR"身上闪出一道死亡的光华！"NOR;

if (query("wtypeA") >0 && ((int)victim->query("neili",1) <= (int)me->query("neili",1)))
{

if (victim->query_temp("apply/attack",1) >= 0)
		victim->add_temp("apply/attack", -(20 * query("wtypeA")));
if (victim->query_temp("apply/parry",1) >= 0)
		victim->add_temp("apply/parry", -(20 * query("wtypeA")));
if (victim->query_temp("apply/dodge",1) >= 0)
		victim->add_temp("apply/dodge", -(20 * query("wtypeA")));
if (victim->query_temp("apply/defense",1) >= 0)
		victim->add_temp("apply/defense", -(20 * query("wtypeA")));
//if (victim->query_temp("apply/attack",1) < 0) victim->set_temp("apply/attack",0);
//if (victim->query_temp("apply/parry",1) < 0) victim->set_temp("apply/parry",0);
//if (victim->query_temp("apply/dodge",1) < 0) victim->set_temp("apply/dodge",0);
//if (victim->query_temp("apply/defense",1) < 0) victim->set_temp("apply/defense",0);
	victim->receive_wound("qi", (query("wtypeA")) * 100,me);
	
msg1=msg1+ victim->query("name") + HIY"突然身形一泄！"NOR;
}
         
return query("name")+ HIG "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                        
}


      case 13:
                if (query("wtypeD") >0 && (query("weapon_prop/jing") >0 && query("weapon_prop/jingli") >0))
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*5  )
                me->add("eff_qi", (query("wtypeD")*5) * 150);
if( (int)me->query("qi") < (int)me->query("max_qi")*5  )
                me->add("qi", (query("wtypeD")*5) * 150);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*5  )
                me->add("eff_jing", (query("wtypeD")*5) * 130);
if( (int)me->query("jing") < (int)me->query("max_jing")*5  )
                me->add("jing", (query("wtypeD")*5) * 130);         
msg1=query("name") + HIG"灵光一闪！恢复了"+me->query("name")+"的休力 ";

if (random(10)==0 && !me->query_condition("killer") &&  !me->query_condition("psgc") && (int)victim->query("combat_exp",1) >= (int)me->query("combat_exp",1))
{	
if (!me->query_condition("huaiyun") && !me->query_condition("wudang_guard") && !me->query_condition("mptjob") && !me->query_condition("mjtjob") && !me->query_condition("mp2_kill") && !me->query_condition("guanfu_task") && !me->query_condition("wudu_xunshan")  && !me->query_condition("hu_song")  && !me->query_condition("xhquest")  && !me->query_condition("qztjob")  && !me->query_condition("xsjob")  && !me->query_condition("menggusong")  && !me->query_condition("shaolin_song")  && !me->query_condition("lingjiu_song")  && !me->query_condition("lyjob")  && !me->query_condition("killme")  && !me->query_condition("riyue_guard"))
{
me->clear_condition("anqi_poison");
me->clear_condition("baituo_poison");
me->clear_condition("bat");
me->clear_condition("bing_poison");
me->clear_condition("binghuo");
me->clear_condition("black_poison");
me->clear_condition("broken_arm");
me->clear_condition("canxia");
me->clear_condition("chanchu_poison");
me->clear_condition("chilian_poison");
me->clear_condition("cold_poison");
me->clear_condition("corpse_poison");
me->clear_condition("cuixin_zhang");
me->clear_condition("dashouyin");
me->clear_condition("dragon_poison");
me->clear_condition("emerald_poison");
me->clear_condition("fire_poison");
me->clear_condition("flower_poison");
me->clear_condition("green_blood");
me->clear_condition("hehe");
me->clear_condition("hot_poison");
me->clear_condition("huanyin_poison");
me->clear_condition("ice_poison");
me->clear_condition("iceshock");
me->clear_condition("ill_dongshang");
me->clear_condition("ill_fashao");
me->clear_condition("ill_keshou");
me->clear_condition("ill_kesou");
me->clear_condition("ill_shanghan");
me->clear_condition("ill_zhongshu");
me->clear_condition("insect_poison");
me->clear_condition("juehu_hurt");
me->clear_condition("jy-poison");
me->clear_condition("jy_poison");
me->clear_condition("libie");
me->clear_condition("new_poison1");
me->clear_condition("new_poison2");
me->clear_condition("new_poison3");
me->clear_condition("new_poison4");
me->clear_condition("new_poison5");
me->clear_condition("new_poison6");
me->clear_condition("new_poison7");
me->clear_condition("new_poison8");
me->clear_condition("no_shadow");
me->clear_condition("nx_poison");
me->clear_condition("poison");
me->clear_condition("poison_sandu");
me->clear_condition("qiankun_wound");
me->clear_condition("qiankunyibang");
me->clear_condition("qinghua_poison");
me->clear_condition("qishang_poison");
me->clear_condition("qx_snake_poison");
me->clear_condition("rose_poison");
me->clear_condition("sanpoison");
me->clear_condition("sanxiao_poison");
me->clear_condition("scorpion_poison");
me->clear_condition("shenlong_poison");
me->clear_condition("shenzhao");
me->clear_condition("sl_poison");
me->clear_condition("snake_poison");
me->clear_condition("ss_poison");
me->clear_condition("tiezhang_yang");
me->clear_condition("tiezhang_yin");
me->clear_condition("tmpili_poison");
me->clear_condition("tmqidu_poison");
me->clear_condition("tmzhuihun_poison");
me->clear_condition("unknown");
me->clear_condition("wudoumi-fanshi");
me->clear_condition("wugong_poison");
me->clear_condition("wuhudu_poison");
me->clear_condition("wuxing_poison");
me->clear_condition("x2_poison");
me->clear_condition("x2_sandu");
me->clear_condition("xiezi_poison");
me->clear_condition("xscold_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuantian_han");
me->clear_condition("xx_condition");
me->clear_condition("xx_liandu");
me->clear_condition("xx_poison");
me->clear_condition("xx_sandu");
me->clear_condition("yf_poison");
me->clear_condition("yufeng_poison");
me->clear_condition("yyz_damage");
me->clear_condition("zhizhu_poison");
me->clear_condition("zhua_poison");
me->clear_condition("zimu-zhen");
me->clear_condition("zm_poison");
me->clear_condition("zmqidu_poison");

msg1=msg1+me->query("name")+HIR"身上的毒素,被逼出体外！"NOR;
}
}

if (query("wtypeB") >0 && ((int)victim->query("combat_exp",1) <= (int)me->query("combat_exp",1)))
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*4);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*4);
msg1=msg1+ victim->query("name") + HIY"突然口吐黑色血液！\n"NOR;
victim->receive_wound("qi", (query("wtypeB")*2) * 100,me);
}         
return query("name")+ RED "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                        
}

      case 14:
                if (query("wtypeI") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/percao") >0) && (string)victim->query("gender") != "女性")
{
if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeI")*6) * 280,me);
msg1=msg1+victim->query("name")+HIR"身上闪出一道粉色的死亡光华！"NOR;
victim->receive_wound("qi", (query("wtypeI")) * 100,me);
if (query("wtypeE") >0 && ((string)me->query("gender") == "女性"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeE")*5) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeE")*5) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeE")*5) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeE")*5) * 50);         
msg1=msg1+query("name") + HIG"粉色的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ WHT "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                              
}


      case 15:
                if (query("wtypeJ") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/constitution") >0)  && (string)victim->query("gender") != "男性")
{
if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeJ")*6) * 280,me);
msg1=msg1+victim->query("name")+HIR"身上闪出一道红色的死亡光华！"NOR;

victim->receive_wound("qi", (query("wtypeJ")) * 100,me);
if (query("wtypeF") >0 && ((string)me->query("gender") == "男性"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeF")*5) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeF")*5) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeF")*5) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeF")*5) * 50);         
msg1=msg1+query("name") + HIG"红色的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ HIB "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                               
}


      case 16:
                if (query("wtypeK") >0 && (query("weapon_prop/dodge") >0 && query("weapon_prop/parry") >0)   && (int)victim->query("shen") < 0)
{

if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeK")*6) * 200,me);
msg1=msg1+victim->query("name")+HIR"身上闪出一道正气的死亡光华！"NOR;
victim->receive_wound("qi", (query("wtypeK")) * 100,me);
if (query("wtypeG") >0 &&  (int)me->query("shen") > 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeG")*5) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeG")*5) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeG")*5) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeG")*5) * 50);         
msg1=msg1+query("name") + HIG"正气的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ HIC "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                             
}

      case 17:
                if (query("wtypeL") >0 && (query("weapon_prop/attack") >0 && query("weapon_prop/armor") >0)   && (int)victim->query("shen") > 0)
{
if( (int)victim->query("eff_qi") >0  )
	victim->receive_wound("jing", -(query("wtypeL")*6) * 200,me);
msg1=msg1+victim->query("name")+HIR"身上闪出一道邪气的死亡光华！"NOR;

victim->receive_wound("qi", (query("wtypeL")) * 100,me);

if (query("wtypeH") >0  &&  (int)me->query("shen") < 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", (query("wtypeH")*5) * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", (query("wtypeH")*5) * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", (query("wtypeH")*5) * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", (query("wtypeH")*5) * 50);         
msg1=msg1+query("name") + HIG"邪气的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ HIG "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                            
}


        }
        
}        
        return damage_bonus;
}
