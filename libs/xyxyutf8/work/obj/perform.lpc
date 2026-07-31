#include <ansi.h>
#include <combat.h>
inherit ITEM;
inherit F_SAVE;

int err_msg(string arg)
{
write(arg);
return 0;
}
        
void create()
{
set_name("自制perform",({"perform"}));
}

varargs int do_perform(object me,string id)
{
string tmp,msg,skill_name,w_name;
object weapon,target;  
mapping data,temp;
string *str;
int v,lvl,ap,dp,t,i,damage;

if ( id )  sscanf(id,"%s %s",tmp,id);
if ( wizardp(me) )  tell_object(me,"id="+id+"\n");
if ( id )  target = present(id,environment(me));
if ( !target || !target->is_fighting(me) )
        target = SSERVER->offensive_target(me);
if ( !target || !target->is_character()
   ||target->is_corpse() || target==me )
        {
        write("你要攻击谁？\n");
        return 0;
        }
if ( query("pfm_level")>20 && !me->query("新任务/昆仑九门") )   return notify_fail("你尚未闯过昆仑九门，无法使用如此高级别的自创外功。\n");
if ( me->query("force")<300 )
        return err_msg("你内力不够。\n");   
if ( me->is_busy() )   return err_msg("你正忙着呢。\n");
weapon = me->query_temp("weapon");
if ( weapon )
        {
        skill_name = weapon->query("skill_type");
        w_name = weapon->name();
        }
else    {
        skill_name = "unarmed";
        w_name = "双掌";
        }
if ( me->query_skill_mapped(skill_name) )
        skill_name = me->query_skill_mapped(skill_name);
                        
if ( me->query("env/brief_message") || target->query("env/brief_message") )
          msg = "$N对$n使用一式从"+to_chinese(skill_name)+"领悟出的"+query("name")+"。\n";
else   {
if ( query("_msg") )  //攻击信息
        msg = query("_msg");
else    msg = "$N对$n使用一式从"+to_chinese(skill_name)+"领悟出的"+query("name")+"。\n";
   }
msg = replace_string(msg,"$w",w_name);
msg = COLOR_D->replace_color(msg,2);
message_vision(msg,me,target);  
me->add("force",-300);
ap = COMBAT_D->skill_power(me,skill_name,SKILL_USAGE_ATTACK);
dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)/2;
dp+= COMBAT_D->skill_power(target,"parry",SKILL_USAGE_DEFENSE)/2;

data = query("perform_type");
if ( !data || !mapp(data) )
        return err_msg("你的自创绝技出错了，联系巫师吧。\n");
v = query("命中附加");
if ( v<=0 )     v = 0;
lvl = query("pfm_level");
if ( lvl<1 ) lvl = 1;
if ( v>=1 )
        ap+= ap/100*v;
ap+= (lvl-1)*500;       

switch(query("perform_type/type"))
        {
        case "busy"     :  //busy技能
                if ( target->is_busy() )
                        return err_msg(target->name()+"已经够忙的了，你使的再漂亮也是枉然。\n");
                if ( random(ap+dp)<dp )
                        {
                        if ( query("_fail_msg") )  //失败信息
                                msg = query("_fail_msg");
                        else    msg = "结果失败了！\n";
                        t = query("perform_type/busy_self");
                        if ( t<1 ) t = 1+random(3);
                        msg = replace_string(msg,"$w",w_name);
                        msg = COLOR_D->replace_color(msg,2);
                        message_vision(msg,me,target);  
                        me->start_busy(t);
                        }
                else    {
                        if ( query("_hit_msg") )  //成功信息    
                                msg = query("_hit_msg");
                        else    msg = "结果一击得手！\n";
                        msg = replace_string(msg,"$w",w_name);
                        msg = COLOR_D->replace_color(msg,2);
                        if ( !me->query("env/brief_message") && !target->query("env/brief_message") )    message_vision(msg,me,target);
                        t = query("perform_type/busy_target");
                        if ( t<1 ) t = random(3);
                        t+= random(lvl);    
                        if ( t>15 ) t = 15;                     
                        target->start_busy(t);
                        }
                break;
        case "hit"      :  //单击延迟型
                if ( !query("perform_type/remove_msg/data") || !query("perform_type/remove_msg/time") )
                        return err_msg("你的自创绝技出错了，联系巫师吧。\n");
                if ( time()<me->query_temp("zzpfm_"+query("ids"))+query("perform_type/remove_msg/time") )
                        return err_msg("绝招用多就不灵了。\n");    
                if ( random(ap+dp)>=dp )
                        {
                        damage = query("perform_type/hit_damage");
                        if ( damage<=0 )
                                damage = me->query_skill(skill_name,1)/60;
                        damage+= (lvl-1)*50;                                                    
                        damage+= me->query_temp("apply/damage");
                        damage-= target->query_temp("apply/armor");
                        if ( damage>0 )
                                {
                                if ( query("_hit_msg") )  //成功信息      
                                        msg = query("_hit_msg")+"\n";
                                else    msg = "结果一击得手！\n";
                                msg = replace_string(msg,"$w",w_name);
                                msg = COLOR_D->replace_color(msg,2);
                                message_vision(msg,me,target);  
                                target->receive_damage("kee",damage,me,"perform");
                                COMBAT_D->report_status(target);
                                if ( me->query("fotce_factor")>0 
                                  && damage/3>0 )
                                        {
                                        target->receive_wound("kee",damage/3,me,"perform");
                                        COMBAT_D->report_status(target,damage/3);
                                        }
                 msg="";
                                }
                        else    msg = HIW"结果对$n"HIW"没造成什么伤害。\n"NOR;
                        msg = replace_string(msg,"$w",w_name);
                        msg = COLOR_D->replace_color(msg,2);
                        message_vision(msg,me,target);  
                        }
                else    {
                        if ( query("_fail_msg") )  //失败信息
                                msg = query("_fail_msg");
                        else    msg = "结果失败了！\n";
                        msg = replace_string(msg,"$w",w_name);
                        msg = COLOR_D->replace_color(msg,2);
                        message_vision(msg,me,target);  
                        }
                me->set_temp("zzpfm_"+query("ids"),time());
                break;
        case "hits"     :   //连击busy型
                temp = query("perform_type/hits");
                if ( !temp || !mapp(temp) )
                        return err_msg("你自创绝技领悟失败，需要重新领悟。\n");
                str = keys(temp);
                for(i=0;i<sizeof(str);i++)
                        {
                        if ( !str[i] || i>6 )
                                continue;
                        if ( !me || !target || !me->is_fighting(target) || !living(target) )
                                continue;       
                        msg = str[i];
                        msg = replace_string(msg,"$w",w_name);
                        msg = COLOR_D->replace_color(msg,2);
                        COMBAT_D->do_attack(me,target,weapon,SKILL_USAGE_ATTACK,msg+"\n"NOR);
                        }
                t = query("perform_type/busy_self");
                if ( t<1 ) t = 1+random(3);
                me->start_busy(t);
                if ( query("perform_type/busy_self")<=0 ) {
                     set("perform_type/busy_self",t);
                     this_object()->save();
                     }
                return 1;
        default :  return err_msg("你的自创绝技领悟失败，需要重新领悟。\n");
        }
return 1;
}

string query_save_file() 
{ 
if ( !query("owner_id") || !stringp(query("owner_id")) ) 
        return 0; 
return sprintf("/c/data/perform/%c/%s/%s", query("owner_id")[0],query("owner_id"),query("ids")); 
}

