int ob_hit(object ob, object me, int damage)
{
   int neili,a;
   int n,sharpness;
object weapon;
string msg1;
sharpness=query("sharpness");
msg1="";
//message_vision(HIW"杀伤值:"+damage+HIW"！\n"NOR, me,ob);
if (!sharpness) sharpness=0;
if (random(sharpness) > 1 && random(8)==0)
{

damage=damage-(sharpness*20);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", sharpness* 10);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", sharpness * 10);
if (damage <0) damage=0;
message_vision(CYN"$N身上的"+query("name")+CYN"一颤，漾起层层金光，顿时将$n" CYN "的攻击减弱了很多！\n"NOR, me,ob);
 return damage;
}
else if (random(2)==0)
{
        switch (random(18) )
        {
        case 0:
                if (query("wtypeA") >0)
{
if(me->is_busy()) me->start_busy(1);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
{
me->add("eff_qi", query("wtypeA") * 20);
}
message_vision(HIY"$N身上的"+query("name")+HIY"金光一闪，$N" HIY "被阻塞的穴道一贯而通！\n"NOR, me,ob);
 return damage;
}
        case 1:
                if (query("wtypeB") >0)
{
if(!ob->is_busy()) ob->start_busy(query("wtypeB")+2);
message_vision(CYN"$N身上的"+query("name")+CYN"绿光一闪，$n" CYN "被附近的树木发出的共鸣一惊，行动一顿！\n"NOR, me,ob);
 return damage;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeC") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeC") * 50);
message_vision(GRN"$N身上的"+query("name")+GRN"水光一闪，$N" GRN "的体力得到了恢得！\n"NOR, me,ob);
 return damage;
}
        case 3:
                if (query("wtypeD") >0)
{
                ob->receive_damage("qi", query("wtypeD") * 50);
                ob->receive_wound("qi", query("wtypeD") * 50);
message_vision(RED"$N身上的"+query("name")+RED"火光一闪，$n" RED "大叫一声 不好$n浑上烧着了！\n"NOR, me,ob);
 return damage;
}
        case 4:
                if (query("wtypeE") >0)
{
                ob->add("neili",-(query("wtypeE")*80));
                if(!ob->is_busy()) ob->start_busy(2);
message_vision(YEL"$N身上的"+query("name")+YEL"土光一闪，$n" RED "大叫一声 浑身提不起力了。\n"NOR, me,ob);
 return damage;
}
        case 5:
                if (query("wtypeF") >0)
{
damage=damage/query("wtypeF");
if (damage <0) damage=0;
me->add("neili",(query("wtypeF")*50));
message_vision(HIM"$N身上的"+query("name")+HIM"招来一阵风，$N" HIM "被无数圈风保护起来。\n"NOR, me,ob);
 return damage;
}

        case 6:
                if (query("wtypeG") >0)
{
if (ob->query_temp("apply/dodge",1) >= 0)
		ob->add_temp("apply/dodge", -(8 * query("wtypeG")));
if (ob->query_temp("apply/defense",1) >= 0)
		ob->add_temp("apply/defense", -(8 * query("wtypeG")));

//if (ob->query_temp("apply/dodge",1) < 0) ob->set_temp("apply/dodge",0);
//if (ob->query_temp("apply/defense",1) < 0) ob->set_temp("apply/defense",0);
		
		ob->start_busy(random(query("wtypeG")) + 2);
message_vision(HIW"$N身上的"+query("name")+HIW"雷光一闪，$n" HIW "只觉得身形一涩！\n"NOR, me,ob);
 return damage;
}
        case 7:
                if (query("wtypeH") >0)
{
if (me->query_temp("apply/dodge",1) <= (query("wtypeH")*6))
		me->add_temp("apply/dodge", (6 * query("wtypeH")));
if (me->query_temp("apply/defense",1) <= (query("wtypeH")*6))
		me->add_temp("apply/defense", (6 * query("wtypeH")));
message_vision(HIB"$N身上的"+query("name")+HIB"电光一现，$N" HIB "的防御速度快了很多！\n"NOR, me,ob);
 return damage;
}

        case 8:
                if (query("wtypeI") >0)
{
if (me->query_temp("apply/attack",1) <= (query("wtypeI")*6))
		me->add_temp("apply/attack", (6 * query("wtypeI")));
if (me->query_temp("apply/damage",1) <= (query("wtypeI")*6))
		me->add_temp("apply/damage", (6 * query("wtypeI")));
message_vision(WHT"$N身上的"+query("name")+WHT"闪过天空的光泽，$N" WHT "的攻击速度快了很多！\n"NOR, me,ob);
 return damage;
}


        case 9:
                if (query("wtypeJ") >0)
{
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
message_vision(YEL"$N身上的"+query("name")+YEL"闪过大地的光泽，发出一阵黄色的烟雾，$n" YEL "只觉气血一阵逆流！\n"NOR, me,ob);
 return damage;
}
        case 10:
                 if (query("wtypeK") >0)
{

//if( (int)ob->query("neili") >0  )
//               ob->add("neili", -query("wtypeK") * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )
                me->add("neili", query("wtypeK") * 60);
message_vision(HIC"$N身上的"+query("name")+HIC"闪过人类的王者之气。内力得到了恢复！\n"NOR, me,ob);
 return damage;
}

        case 11:
                if (query("wtypeL") >0)
{

//if( (int)ob->query("eff_qi") >0  )
//                ob->add("eff_qi", -query("wtypeL") * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeL") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeL") * 50);


//if( (int)ob->query("eff_jing") >0  )
                //ob->add("eff_jing", -query("wtypeL") * 30);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeL") * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeL") * 30);                
message_vision(HIR"$N身上的"+query("name")+HIR"魔光一现，体力精力得到了恢复！！\n"NOR, me,ob);
 return damage;
                                                                                                                         
}


      case 12:
                if (query("wtypeA") >0 && (query("armor_prop/intelligence") >0 && query("armor_prop/karey") >0))
{
if (random(3)==0)
{
	me->add("combat_exp", random(query("wtypeA",1))+1);
msg1=query("name") + HIG"灵光一闪！"+me->query("name")+"的实战经验得到了增加 "NOR;
}
if (query("wtypeC") >0 && ((int)ob->query("combat_exp",1) >= (int)me->query("combat_exp",1)))
{
//ob->start_busy(query("wtypeC") + 2);
//ob->apply_condition(du[random(sizeof(du))], query("wtypeC")*3);
//msg1=msg1+ob->query("name")+HIY"身上闪出一道迷乱的黄色厌恶！"NOR;
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )  me->add("neili", query("wtypeC") * 80);
msg1=msg1+me->query("name")+HIY"身上闪出一道水色的光芒！"NOR;
}         
message_vision(query("name")+ HIY "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}


      case 13:
                if (query("wtypeB") >0 && (query("armor_prop/karey") >0 && query("armor_prop/percao") >0))
{
if (random(3)==0)
{
me->add("potential", random(query("wtypeB",1))+1);
msg1=query("name") + HIG"灵光一闪！"+me->query("name")+"的潜能得到了增加 "NOR;
}
if (query("wtypeD") >0 && ((int)ob->query("combat_exp",1) <= (int)me->query("combat_exp",1)))
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeD") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeD") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeD") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeD") * 50);         
msg1=msg1+me->query("name")+RED"身上闪出一道火红色的重生的光芒！"NOR;


//ob->start_busy(query("wtypeD") + 2);
//ob->apply_condition(du[random(sizeof(du))], query("wtypeD")*3);
//msg1=msg1+ob->query("name")+RED"身上闪出一道迷乱的火红色厌恶！"NOR;

}         
message_vision(query("name")+ CYN "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

      case 14:

                if (query("wtypeE") >0 && (query("armor_prop/defense") >0 && query("armor_prop/neili") >0)  && (int)me->query("shen") > 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeE") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeE") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeE") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeE") * 50);         
msg1=msg1+me->query("name")+YEL"身上闪出一道大地的重生的光芒！"NOR;
if (query("wtypeI") >0  && (int)ob->query("shen") < 0)
{
ob->start_busy(query("wtypeI") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeI")*3);
msg1=msg1+ob->query("name")+WHT"身上闪出一道天属性烟雾！"NOR;

}         
message_vision(query("name")+ YEL "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

      case 15:
                if (query("wtypeF") >0 && (query("armor_prop/jing") >0 && query("armor_prop/damage") >0)  && (int)me->query("shen") < 0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeF") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeF") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeF") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeF") * 50);         
msg1=msg1+me->query("name")+HIM"身上闪出一道清爽的微风！"NOR;

if (query("wtypeJ") >0  && (int)ob->query("shen") > 0)
{
ob->start_busy(query("wtypeJ") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
msg1=msg1+ob->query("name")+HIY"身上闪出一道地属性烟雾！"NOR;

}         
message_vision(query("name")+ HIM "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR, me,ob);
return damage;
}

      case 16:
                if (query("wtypeG") >0 && (query("armor_prop/damage") >0 && query("armor_prop/jingli") >0) && (string)me->query("gender") != "女性")
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeG") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeG") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeG") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeG") * 50);         
msg1=msg1+me->query("name")+HIW"身上闪出一道天雷的光芒！"NOR;
if (query("wtypeK") >0 && (string)ob->query("gender") != "男性")
{
ob->start_busy(query("wtypeK") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeK")*3);
msg1=msg1+ob->query("name")+RED"身上闪出一道人属性烟雾！"NOR;

}         
message_vision(query("name")+ HIC "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

      case 17:
                if (query("wtypeH") >0 && (query("armor_prop/armor") >0 && query("armor_prop/defense") >0) && (string)me->query("gender") != "男性")
{

if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2  )
                me->add("eff_qi", query("wtypeH") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*2  )
                me->add("qi", query("wtypeH") * 50);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2  )
                me->add("eff_jing", query("wtypeH") * 50);
if( (int)me->query("jing") < (int)me->query("max_jing")*2  )
                me->add("jing", query("wtypeH") * 50);   
msg1=msg1+me->query("name")+HIB"身上闪出一道闪电的光芒！"NOR;
if (query("wtypeL") >0  && (string)ob->query("gender") != "女性")
{
ob->start_busy(query("wtypeL") + 2);
ob->apply_condition(du[random(sizeof(du))], query("wtypeL")*3);
msg1=msg1+ob->query("name")+HIR"身上闪出一道魔属性烟雾！"NOR;

}         
message_vision(query("name")+ HIB "通体一阵闪亮，闪出五色光芒！！结果:\n"+msg1+"\n"+NOR, me,ob);

return damage;
}

       }
}

  return damage;
}