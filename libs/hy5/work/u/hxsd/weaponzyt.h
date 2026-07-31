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
                me->add("neili", sharpness * 10);

                victim->receive_damage("qi", sharpness * 10);
                victim->receive_wound("qi", sharpness * 10);
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
                victim->start_busy(query("wtypeA") + 2);
                return query("name")+HIY"金光一闪，闪过了$n的双眼！"
                       "$n" HIY "只觉头晕目眩，几欲昏厥！\n" NOR;
}
        case 1:
                if (query("wtypeB") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeB") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeB") * 50);
                return query("name")+ CYN "绿光一闪，$N" CYN "身边树木的生命活力"
                       "使$N" CYN "的身体得到了恢复！\n" NOR;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeC") * 30);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeC") * 30);
                victim->start_busy(3);
                return query("name")+ GRN "水光一闪，$N" GRN "的气色好一些"
                       "$n感到一阵冰凉，不能动弹了！\n" NOR;
}
        case 3:
                 if (query("wtypeD") >0)
{

                victim->receive_damage("qi", query("wtypeD") * 50);
                victim->receive_wound("qi", query("wtypeD") * 50);
                return query("name")+ RED "火光一闪，$n" RED "大叫一声 不好"
                       "$n浑上烧着了！\n" NOR;
}
        case 4:
                if (query("wtypeE") >0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )
                me->add("neili", query("wtypeE") * 60);
                return query("name")+ GRN "土光一闪，$N" GRN "丹田一暖，的元气恢得了不少。\n" NOR;                                           
 }
        case 5:
                if (query("wtypeF") >0)
{
damage = 15 * query("wtypeF") ;
if (victim->query_temp("apply/dodge",1) >= 0)
		victim->add_temp("apply/dodge", -(8 * query("wtypeF")));
if (victim->query_temp("apply/defense",1) >= 0)
		victim->add_temp("apply/defense", -(8 * query("wtypeF")));
//if (victim->query_temp("apply/dodge",1) < 0) victim->set_temp("apply/dodge",0);
//if (victim->query_temp("apply/defense",1) < 0) victim->set_temp("apply/defense",0);

victim->start_busy(random(query("wtypeF")) + 1);
		if ((int)victim->query("qi")+10 > damage)
		victim->receive_wound("qi", damage);
                
                return query("name")+ HIM "招来一阵风，飞舞在空中的无形之利刃包围着$n，$n" HIM "只觉寸步难行！\n" NOR;
}
        case 6:
                if (query("wtypeG") >0)
{

			damage = 30 * query("wtypeG") ;
if ((int)victim->query("neili")+10 > (damage*30))
		victim->add("neili", -damage*30);
if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage);
                return query("name")+ HIW "招来一道雷，一闪而过击中了$n，$n" HIW "只觉得全身又痛又麻！\n" NOR;
}
        case 7:
                if (query("wtypeH") >0)
{
damage = 10 * query("wtypeH") ;
if (victim->query_temp("apply/attack",1) >= 0)
		victim->add_temp("apply/attack", -(8 * query("wtypeH")));
if (victim->query_temp("apply/parry",1) >= 0)
		victim->add_temp("apply/parry", -(8 * query("wtypeH")));
//if (victim->query_temp("apply/attack",1) < 0) victim->set_temp("apply/attack",0);
//if (victim->query_temp("apply/parry",1) < 0) victim->set_temp("apply/parry",0);

victim->start_busy(random(query("wtypeH")) + 1);
		if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage);
                return query("name")+ HIB "招来一阵电，电光一闪击中了$n，$n" HIB "只觉混身麻痹！\n" NOR;

}
        case 8:
                if (query("wtypeI") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeI") * 20);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeI") * 20);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")  )
                me->add("eff_jing", query("wtypeI") * 20);
if( (int)me->query("jing") < (int)me->query("max_jing")  )
                me->add("jing", query("wtypeI") * 20);
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", query("wtypeI") * 30);
                return query("name")+ WHT "闪过天空的光泽，$N" WHT "全身气色发身了变化\n" NOR;

}
        case 9:
                if (query("wtypeJ") >0)
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
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
					message_vision(HIW"只听见「哐」地一声轻响，$N手中的" + weapon->query("name") + HIW"已经被" + query("name") + HIW"削为两截！\n"NOR, victim);
					weapon->unequip();
					weapon->move(environment(victim));
					weapon->set("name", "断掉的" + weapon->query("name"));
					weapon->set("value", 0);
					weapon->set("weapon_prop", 0);
					victim->reset_action();
}
}

if( (int)victim->query("neili") >0  )
                victim->add("neili", -query("wtypeK") * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )
                me->add("neili", query("wtypeK") * 60);

                return query("name")+ HIC "闪过人类的王者之气。$n" HIC "双眼一花，觉和全身的内力给王者之气吸走了！\n" NOR;
}
        case 11:
                if (query("wtypeL") >0)
{

if( (int)victim->query("eff_qi") >0  )
                victim->add("eff_qi", -query("wtypeL") * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeL") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeL") * 50);


if( (int)victim->query("eff_jing") >0  )
                victim->add("eff_jing", -query("wtypeL") * 30);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeL") * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeL") * 30);                
return query("name")+ HIR "魔光一现，$n" HIR "只觉鬼哭狼嚎声不绝于耳，三魂六魄都给吸了出去！！\n" NOR;                                                                                                                                        
}


      case 12:
                if (query("wtypeC") >0 && (query("weapon_prop/strength") >0 && query("weapon_prop/neili") >0))
{
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )  me->add("neili", query("wtypeC") * 150);

msg1=query("name") + HIG"灵光一闪！恢复了"+me->query("name")+"的内力 ";

if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeC") * 200);
msg1=msg1+victim->query("name")+HIR"身上闪出一道死亡的光华！"NOR;

if (query("wtypeA") >0 && ((int)victim->query("neili") <= (int)me->query("neili")))
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
	
	
msg1=msg1+ victim->query("name") + HIY"突然身形一泄！"NOR;
}
         
return query("name")+ HIG "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                        
}


      case 13:
                if (query("wtypeD") >0 && (query("weapon_prop/jing") >0 && query("weapon_prop/jingli") >0))
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeD") * 150);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeD") * 150);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeD") * 130);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeD") * 130);         
msg1=query("name") + HIG"灵光一闪！恢复了"+me->query("name")+"的休力 ";

if (random(10)==0 && !me->query_condition("killer") &&  !me->query_condition("psgc") && (int)victim->query("combat_exp",1) >= (int)me->query("combat_exp",1))
{	
me->clear_condition();
msg1=msg1+me->query("name")+HIR"身上的毒素,被逼出体外！"NOR;
}

if (query("wtypeB") >0 && ((int)victim->query("combat_exp",1) <= (int)me->query("combat_exp",1)))
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeB")*3);
msg1=msg1+ victim->query("name") + HIY"突然口吐黑色血液！\n"NOR;
}         
return query("name")+ RED "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                        
}

      case 14:
                if (query("wtypeI") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/percao") >0) && (string)victim->query("gender") != "女性")
{
if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeI") * 200);
msg1=msg1+victim->query("name")+HIR"身上闪出一道粉色的死亡光华！"NOR;

if (query("wtypeE") >0 && ((string)me->query("gender") == "女性"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeE") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeE") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeE") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeE") * 50);         
msg1=msg1+query("name") + HIG"粉色的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ WHT "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                              
}


      case 15:
                if (query("wtypeJ") >0 && (query("weapon_prop/dexerity") >0 && query("weapon_prop/constitution") >0)  && (string)victim->query("gender") != "男性")
{
if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeJ") * 200);
msg1=msg1+victim->query("name")+HIR"身上闪出一道红色的死亡光华！"NOR;


if (query("wtypeF") >0 && ((string)me->query("gender") == "男性"))
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeF") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeF") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeF") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeF") * 50);         
msg1=msg1+query("name") + HIG"红色的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ HIB "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                               
}


      case 16:
                if (query("wtypeK") >0 && (query("weapon_prop/dodge") >0 && query("weapon_prop/parry") >0)   && (int)victim->query("shen") < 0)
{

if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypek") * 200);
msg1=msg1+victim->query("name")+HIR"身上闪出一道正气的死亡光华！"NOR;

if (query("wtypeG") >0 &&  (int)me->query("shen") > 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeG") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeG") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeG") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeG") * 50);         
msg1=msg1+query("name") + HIG"正气的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ HIC "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                             
}

      case 17:
                if (query("wtypeL") >0 && (query("weapon_prop/attack") >0 && query("weapon_prop/armor") >0)   && (int)victim->query("shen") > 0)
{
if( (int)victim->query("eff_qi") >0  )
victim->add("eff_qi", -query("wtypeL") * 200);
msg1=msg1+victim->query("name")+HIR"身上闪出一道邪气的死亡光华！"NOR;



if (query("wtypeH") >0  &&  (int)me->query("shen") < 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeH") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeH") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeH") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeH") * 50);         
msg1=msg1+query("name") + HIG"邪气的灵光一闪！恢复了"+me->query("name")+"的休力 ";

}         
return query("name")+ HIG "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR;                                                                                                                                                            
}


        }
        
}        
        return damage_bonus;
}
