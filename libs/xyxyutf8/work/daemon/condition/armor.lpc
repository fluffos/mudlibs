//armor 新盔甲的治疗功能
//不想使用Call_out以免资源狂耗，所以就使用此设定
//snowtu 2007
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

mapping tt = ([
        "kee"           : "气血增加",
        "sen"           : "精神增加",
        "eff_kee"       : "气血治疗",
        "eff_sen"       : "精神治疗",
        "force"         : "内力恢复",
        "mana"          : "法力恢复",
]);     

int update_condition(object me, int dur)
{
object *inv,armor,armor2;
mapping data;
string *datas,type,needarmor;
int i,v,k,tmp,j,flag=0,flag2=0;
if ( !me )
        return 0;
inv = all_inventory(me);        
data = me->query_entire_temp_dbase();
data = data["apply"];
datas = keys(data);
for(i=0;i<sizeof(datas);i++)
        {
        if ( sscanf(datas[i],"ad_%s",type)==1 )
                {
                if ( type!="kee" && type!="sen"
                  && type!="eff_kee" && type!="eff_sen" 
                  && type!="mana" && type!="force" ) 
                        continue;
                v = data["ad_"+type];   
                for(k=0;k<sizeof(inv);k++)
                        {
                        if ( (tmp=inv[k]->query("armor_prop/ad_"+type))>0 )
                                {
                                armor = inv[k]; 
                                if ( armor->query("equipped")!="worn" )
                                        continue;
                                if ( stringp(needarmor=armor->query("need_obj/ad_"+type)) )
                                        {
                                        for(j=0;j<sizeof(inv);j++)
                                                {
                                                if ( inv[j]->short()==needarmor 
                                                  && inv[j]->is_zhaohuan()
                                                  && inv[j]!=armor 
                                                  && inv[j]->query("equipped")=="worn" )
                                                        armor2 = inv[j];
                                                }
                                        if ( !armor2 || !objectp(armor2) )
                                                v-= tmp;
                                        }
                                }
                        }
                flag+= v;                       
                if ( v>0 )
                        {
                        v*= 10;
                        v = v/3+random(v/2);                         if ( type=="force" )
                                {
                                if ( me->query("force")<me->query("max_force")*2 )
                                        {
                                        flag2++;        
                                        me->add("force",v);
                                        if ( me->query("force")>me->query("max_force")*2 )
                                                me->set("force",me->query("max_force")*2);
                                        }
                                }
                        else if ( type=="mana" )
                                {
                                if ( me->query("mana")<me->query("max_mana")*2 )
                                        {
                                        flag2++;
                                        me->add("mana",v);
                                        if ( me->query("mana")>me->query("max_mana")*2 )
                                                me->set("mana",me->query("max_mana")*2);
                                        }
                                }
                        else if ( sscanf(type,"eff_%s",type)==1 )
                                {
                                if ( me->query("eff_"+type)<me->query("max_"+type) )
                                        {
                                        flag2++;                
                                        me->receive_curing(type,v);     
                                        }
                                }
                        else    {
                                if ( me->query(type)<me->query("eff_"+type) )
                                        {
                                        flag2++;        
                                        me->receive_heal(type,v);
                                        }
                                }
                        if ( flag && me->query("env/test") )
                                tell_object(me,HIY"你的"+tt[type]+"了"HIR+v+HIY"点。\n"NOR);
                        }
                }
        continue;
        }
if ( flag<=0 )
        return 0;
me->apply_condition("armor",dur);
return CND_CONTINUE;
}

