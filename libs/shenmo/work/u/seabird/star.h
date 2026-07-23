#include <ansi.h>

void unconcious()
{
  die();
}

void powerup()
{
object me = this_object();
message_vision(HIY"方舟给于我力量吧"NOR,me);
me->set("kee",query("max_kee"));
me->set("eff_kee",query("max_kee"));
me->set("sen",query("max_sen"));
me->set("eff_sen",query("max_sen"));
me->set("force",query("max_force"));
me->set("mana",query("max_mana"));
me->clear_condition();
return;
}

void kill_ob(object me)
{
int damage, lvl, r_lvl,skill, i;
object ob=this_object();
    
if ( !me || !present(me,environment()) 
  || me->is_ghost() || !me->is_fighting(ob) )
        {
        powerup();      
        ob->delete_temp("my_killer");
        return;
        }
ob->set_temp("my_killer",me);

switch(random(6))
        {        
        case 0:
                message_vision(HIC"「圣光之雷」$N双手一挥，一团银芒直冲$n而去！\n",ob,me);
                if(random(2))
                        {
                        message_vision(HIC"$N被$n的银芒刺得遍体鳞伤！\n"NOR,me,ob);
                        me->receive_wound("sen",query("max_sen")/50,ob);
                        me->receive_wound("kee",query("max_kee")/50,ob);
                        kill_ob(me);
                        }
                else   message_vision(HIR"$N轻而易举的躲过了$n的攻击！\n"NOR,me,ob);
                break;
        case 1:
                r_lvl = random(5);
                if( r_lvl > 3) lvl = 3;
                if( r_lvl < 1) r_lvl = 1;
                message_vision(HIW"$N大喝一声“刀枪不如！”皮肤变得如钢铁般结识，$n的攻击立刻被反弹回去！\n"NOR,ob,me);
                for(i = 0; i < r_lvl; i++)
                                COMBAT_D->do_attack(me, me, me->query_temp("weapon") );
                break;  
        default:
                message_vision(HIB"$N运起[人间炼狱],幽灵冥气冲向$n \n",ob,me);
                if(random(2))
                        {
                        message_vision(HIB"$N被[人间炼狱]击中,顿时血流如注，顷刻染红了全身！\n"NOR,me);
                        me->receive_wound("kee",query("max_kee")/20,ob);
                        me->receive_wound("sen",query("max_sen")/20,ob);
                        }
                else    message_vision(HIR"$N看准幽灵冥气的方向，纵身跃起，躲过这致命一击！\n"NOR,me);
                break;
        }
if( random(10) == 1 )
        powerup();
remove_call_out("kill_ob");
call_out("kill_ob",4+random(9),me);
}

void fight_ob( object me)
{
kill_ob( me);
}

void die()
{
string str;     
object where ,ob = this_object(),me;
powerup();
where = environment( ob );
me = ob->query_temp("last_damage_from");
if ( !where || !me || !present(me,environment(ob))  
   || me!=ob->query_temp("my_killer") )
        return;

if(  where->query("short")!= "魂魄战场" ) 
   {
    message_vision(HIW"$N化作尘土消失在夜风中！\n"NOR,ob);
    destruct(ob);
    return;
   }
if ( random(20)!=1 && !wizardp(me) )
        {
        say(HIB"\n"+name()+HIB"点了点头：不错不错，再来再来！\n"NOR);
        me->kill_ob(ob);
        ob->kill_ob(me);
        return;
        }

me->remove_killer(ob);
ob->remove_killer(me);

me->start_busy(3);

ob->command("great");
ob->command("say 果真是后浪推前浪。。。\n");

if ( me->query("weapon/make") && me->query("weapon/type/"+ob->query("weapon_type"))<1 )
        {
        me->set("weapon/type/"+ob->query("weapon_type"),1);
//         str = sprintf(HIY"%s"NOR HIY"(%s)：%s"NOR HIY"诚心见鉴日月，终于得到了%s"NOR HIY"！\n"NOR,
                        ob->query("name"),
                        capitalize(ob->query("id")),
                        me->query("name"),
                        ob->query("name"),
                        );
        str = SDS_D->no_color_msg(str);
        str = NOR HIY+str+NOR;
//         message("channel:chat",HIY"【神兵传说】"+str,users());
        }
message_vision("\n$N化作尘土消失在夜风中！\n",ob);
destruct(ob);
return;
}

