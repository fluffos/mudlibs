//sanban, 无敌三神锤
//created 6-10-97 pickle
 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg,targetrude;
        object weapon;
        int success,hurt,diff,damage;
        int myexp=(int)me->query("combat_exp")/5000;
        int mylev=(int)me->query_skill("hammer");
        int mystr=(int)me->query("str")+(int)(me->query_skill("unarmed")/10-2);
        int mykar=(int)me->query_kar();
        int targetlev, targetstr,targetkar,targetexp,targeteffkee;
        int myskill;
                object *inv, obj, obj1;
        int mypot,tapot;
        string str;
        int i, temp_dodge,temp_spells;
        
        string *hitone = ({
        "$n试图侧身避开，但为时已晚。大锤劈在肩上，留下一道深可见骨的伤口！\n",
        "$n高举手中兵刃试图架开，但挡不住$N的来势，被震得吐出一口鲜血！\n",
        "$n以攻为守，但去势不够凌厉。虽逼得$N回锤自护，但还是在$n肩膀带出一道伤口。\n",
        });
        string *missone = ({
        "$n轻轻一闪，大锤带着一阵劲风从身边斩下，但没伤到$n分毫。\n",
        "$n高举手中兵刃奋力一架，只听「当」的一声巨响，$N巨锤已被弹开！\n",
        "$n不顾大锤来势，反而向$N疾攻，逼得$N不得不回锤自保，这一势「开瓜」就此落空。\n",
        });
        string *hittwo = ({
        "$n似乎没有觉出危险，顺手一挡。待到发觉来势之疾，为时已晚。脸上已多了一条数寸长的伤口！\n",
        "$n没想道$N攻势如此之快，急忙低头闪避，但无法躲开，被刀刃划得皮开肉绽！\n",
        "$n攻势已然发出，来不及回防，脸上被割掉一片皮，显然伤得不轻！\n",
        });
        string *misstwo = ({
        "$n脑袋微微一侧，避过了$N的攻势。\n",
        "$n似乎早已料到这一招，顺势在锤杆上一推，避了开去。\n",
        "眼看这招要把$n脑袋戳个对穿，突然间$n使个铁板桥，护手刀落了个空。\n",
        });
        string *hitthree = ({
        "$n似乎已被这三锤连环的威势吓破了胆，懒懒散散地一歪，被大锤横劈在肩头。\n",
        "$n看准来势，以手中兵器架去，但已力不从心，被锤头震得虎口出血，显然内伤不轻！\n",
        "$n眼见来势凌厉，企图低头避过，但不料大锤随着下劈，从$n背上割下一大片皮肉！\n",
        });
        string *missthree = ({
        "$n似乎早已熟知大锤来路，锤未到，人已先轻飘飘地避开了。\n",
        "$n眼见躲不过来招，急忙在地上一滚。虽然避得狼狈，但丝毫没有受伤。\n",
        "$n不顾自身危险，中宫直进，向$N攻去，果然将来招化解了。\n",
        });
        string *hit=({
        RED"$N道：也叫你尝尝这无敌三神锤的厉害！\n"NOR,
        RED"这无敌三神锤一气呵成，$n被攻了个措手不及，伤势甚为可怕！\n"NOR,
        RED"$N狂笑道：就凭你这点本事，也来跟我斗？\n"NOR,
        });
        string *miss;
  
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("无敌三神锤不是练着好看的，只能对战斗对手施用。\n");
        targetrude=RANK_D->query_self_rude(target);
        targetexp=(int)target->query("combat_exp")/5000;
        targetlev=(int)target->query_skill("parry");
        targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
        targetkar=(int)target->query_kar();
        myskill=(int)me->query_skill("frht-hammer",1);
        
        miss=({
        BLU"$n哈哈大笑道："+targetrude+"听说这无敌三神锤有多少威力，现在一看，也不过如此嘛！\n"NOR,
        BLU"$n长笑一声，对$N不屑地说道：就这点本事，"+targetrude+"还没放在眼里！\n"NOR,
        BLU"$n仰天大笑道：还有什么本事，尽管拿出来吧！\n"NOR,
        });

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "qingming-xuangong")
                return notify_fail("请使用青冥玄功!\n");

        if((int)me->query_skill("qingming-xuangong",1) < 200)
                return notify_fail("你的青冥玄功还不够。。。\n"); 

       if(me->query("jing")<500)
                return notify_fail("你的精力不足，难以随意挥动一柄大锤。\n");


        if(me->query_skill("frht-hammer",1)<100)
                return notify_fail("你的这门武功不够熟悉，无法一气呵成地使出！\n");
        if(me->query("max_neili") < 1000 || me->query("neili")<500)
                return notify_fail("你的内力不足，难以随意挥动一柄大锤。\n");
        msg = CYN "$N一声暴喝：开瓜！剔牙！掏耳朵！三招一气呵成！\n\n只见一道青影划过，大锤直劈$n顶门！\n" NOR;
        if( random(mylev+targetlev+mystr*3+targetstr*3) > (targetlev+targetstr*3))
        {
                msg += hitone[random(sizeof(hitone))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage=15+random(mykar/3);
        }
        else msg+=missone[random(sizeof(missone))];
        msg+=CYN"\n$N大锤已经带过，顺势以锤尾护手尖刀疾挑$n面门！\n"NOR;
        if( random(myexp+targetexp+mylev+targetlev) > (targetexp+targetlev))
        {
                msg += hittwo[random(sizeof(hittwo))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage+=15+random(mykar/3);
        }
        else msg+=misstwo[random(sizeof(misstwo))];
        msg+=CYN"\n$N迅疾无伦地翻转锤头，大锤向$n脑袋横劈过去！\n"NOR;
        if(random(myexp+targetexp+mykar*10+targetkar*10)>(targetexp+targetkar))
        {
                msg+=hitthree[random(sizeof(hitthree))];
                success+=1;
                if(random(mykar+targetkar)>targetkar) hurt+=1;
                damage+=15+random(mykar/3);
        }
        else msg+=missthree[random(sizeof(missthree))];
        diff=3-success;
        if (diff<0) diff = 0;
        if (success) hurt=damage*hurt/success;
        else hurt=0;
        me->add("neili", -(50*success));
        targeteffkee=(int)target->query("eff_qi",1);
        if (targeteffkee> 38000) targeteffkee=38000;
        
        target->receive_wound("qi", targeteffkee*hurt/100,me);
        target->receive_damage("qi", targeteffkee*(damage-hurt)/100,me);
        if(success)
        {
                //me->start_busy(2);
                msg+=hit[random(sizeof(hit))];
        }       
        else
        {
                //me->start_busy(3);
                msg+=miss[random(sizeof(miss))];
        }
        message_vision(msg, me, target);
        if(success && me->query_temp("jjftop") && living(target))
        {
                target->receive_damage("qi", targeteffkee*(damage-hurt)/40,me);
                msg=HIG"$N感到劲力有余，手中板锤顺势回扳，一锤砍到$n。\n$n立时被劈的血肉模糊，晕死在地上！\n";
                message_vision(msg, me, target);
        }
 
 if (myskill> 500 || !userp(me))
{
    message_vision(HIC"\n$N运足精神，大喝一声，对着$n发出了全力一击！\n"NOR, me, target);

        mypot=(int)me->query_skill("hammer",1);
        mypot=mypot*mypot*mypot/2 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry",1);
        tapot=tapot+(int)target->query_skill("dodge",1)/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

//      write("mypot " + mypot + ", tapot " +tapot+ "\n");

        if( random( mypot+tapot )/1000 > tapot/1000 ) 
        {

                inv = all_inventory(target);
                i = sizeof(inv);

                if ( i < 1 ) 
                {
                        message_vision(HIR"$N躲闪不及，被打个正着！\n"NOR, target);
                        damage = 100+(int)me->query("jiali")
                        + (int)me->query_skill("hammer",1) + (int)me->query_skill("frht-hammer",1);
                        target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage,me);

                        COMBAT_D->report_status(target);
                } 
                else 
                {
                        if(target->query_temp("armor")||target->query_temp("weapon")) 
                        {
                                if( target->query_temp("armor") ) 
                                {
                                        for (i=1; i < sizeof(inv); i++ ) 
                                        {
                                                obj = inv[i];
if (!obj->query("systemmake") && !obj->query("ownmake"))
{
                                                if( obj->query("equipped") != "worn" ) continue;
                                                obj->delete("equipped");
                                                obj->set("value", 0);
                                                //obj->set("No_Wear", 1);
                                                message_vision(HIY"$N身上的$n被打的粉碎！\n"NOR, target,obj);
                                                temp_dodge=(int)obj->query("armor_prop/dodge",1);
                                                temp_spells=(int)obj->query("armor_prop/armor",1);
                                                if (temp_dodge)
                                                target->add_temp("apply/dodge",-temp_dodge);
                                                if (temp_spells)
                                                target->add_temp("apply/armor",-temp_spells);
                                                                                                
                                                obj->set("name", "破碎的"+obj->query("name"));
}
                                        }
                                }
                                if (target->query_temp("weapon")) 
                                {
                                	
                                        obj=target->query_temp("weapon");
if (!obj->query("systemmake") && !obj->query("ownmake"))
{
                                        obj->unequip();
                                        obj->set("value", 0);
                                        message_vision(HIW "只听见「啪」地一声，$N手中的" + obj->name()+ "已经断为两截！\n" NOR, target);
                                        obj->set("name", "断掉的" + obj->query("name"));
                                        obj->set("weapon_prop", 0);
                                        obj->set("armor_prop", 0);                                                              
                                        //obj->move(environment(target));
                                       // call_out("remove_broken_cloth",random(300)+60,obj);
}
                                target->receive_damage("qi",(int)me->query_skill("frht-hammer",1),me); 
                                target->receive_wound("qi",(int)me->query_skill("frht-hammer",1),me); 
                                }
//                        target->delete_temp("armor");
//                        target->delete_temp("apply");
                        } 
                        else 
                        {
                                message_vision(HIR"$N躲闪不及，被打个正着！\n"NOR, target);
                           
                        damage = (int)me->query("jiali") 
                        + (int)me->query_skill("hammer",1) + (int)me->query_skill("frht-hammer",1);
                                target->receive_damage("qi",damage,me); 
                                target->receive_wound("qi",damage,me); 
                               
                                COMBAT_D->report_status(target); 
                        }
                }
        } 
        else 
        {
                message_vision(HIC"却被$N躲开了！\n"NOR, target);
        }

        me->add("neili", -50);
        me->receive_damage("jing", 50);
 
} 


if (myskill> 800)
{
	     message_vision(HIY"\n$N手指$n愤恨道：“对我不仁尔等小命休以”，一语说罢，$N气运丹田，力灌掌心，使出「翻天覆地」。\n\n"NOR,me,target);
                
        mypot=(int)me->query_skill("frht-hamer");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot || !living(target) ) 
{       
        
         message_vision(HIR"只见$n硬生生的接住$N这技绝招，顿感喉头一甜，[噗]的一声吐出一口鲜血。\n\n"NOR,me, target);  
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("qi",(random(me->query_skill("hammer")*3/2)+ (int)me->query_skill("frht-hammer",1)),me);
         COMBAT_D->report_status(target);
                
         if (target->query("eff_qi")< -100 || !living(target))  
 {str=target->name()+"被"+me->name()+"的「翻天覆地」震死，魂魄都无处寻觅。";
         CHANNEL_D->do_channel(me, "rumor",str);
         me->delete_temp("last_channel_msg");}
        else {if ( random(2)==0 )
              message_vision(HIR"$N见到$n受伤不轻，乘胜追击，又出一技“翻云覆雨”，$n的七魂六魄早已少了一半。\n"NOR,me,target);
         COMBAT_D->do_attack_damage(me, target);
         target->receive_wound("qi",(random(me->query_skill("parry")*3/2)+ (int)me->query_skill("frht-hammer",1)),me);
         COMBAT_D->report_status(target);
              target->start_busy(2);
             }
          
}        
     
         else  {message_vision(HIC"$N识破此招，气运丹田，以力抗力硬接此绝招！\n"NOR, target);
                me->start_busy(2);
               }
               
        me->add("neili", -50);
        me->receive_damage("jing", 50);
	
	
}		
	


        me->start_busy(3);
        
        return 1;
}

