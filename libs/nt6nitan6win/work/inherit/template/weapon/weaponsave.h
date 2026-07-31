#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

string query_autoload()
{   
        if (! query("autoload"))
                return 0;
        if(!query("long")) set("long",this_object()->short());
        return query("strong")+" "+
               query("max_strong")+" "+
               query("weapon_prop/damage")+" "+
               query("name")+" "+
               query("org_name")+" "+
               query("user")+" "+
               query("user_skill")+" "+
               query("temp_skill")+" "+
               query("flag")+" "+
               query("poison_flag")+" "+
               query("long")+" "+
               query("wield_msg")+" "+
               query("unequip_msg")+" "+
               query("unwield_msg")+" "+
               query("weapon_prop/str")+" "+
               query("weapon_prop/dodge")+" "+
               query("weapon_prop/armor")+" "+
               query("weapon_prop/int")+" "+
               query("weapon_prop/per")+" "+
               query("weapon_prop/con")+" "+
               query("weapon_prop/kar")+" "+
               
               query("weapon_prop/dodgeaction")+" "+
               query("weapon_prop/min_damage")+" "+
               query("weapon_prop/enhance_min_damage")+" "+
               
               query("wield_str")+" "+
               query("wield_con")+" "+
               query("wield_int")+" "+
               query("wield_dex")+" "+
               query("wield_force")+" "+
               query("wield_maxforce");
               
               
}

void autoload(string pa)
{   
    string name,org_name,user,wlong,
           wield_msg,unequip_msg,unwield_msg;
           
    int str,max_str,damage,user_skill,tskill,flag,p_flag,
        w_str,w_dodge,w_armor,w_int,w_per,w_con,w_kar;
    
    int w_dodge_action,w_min_damage,w_enhance_min_damage;
    int wield_str,wield_con,wield_int,wield_dex,wield_force,wield_maxforce;
    
    if(sscanf(pa,"%d %d %d %s %s %s %d %d %d %d %s %s %s %s %d %d %d %d %d %d %d "+
                 "%d %d %d %d %d %d %d %d %d",
       str,max_str,damage,name,org_name,user,user_skill,tskill,flag,p_flag,wlong,
       wield_msg,unequip_msg,unwield_msg,
       w_str,w_dodge,w_armor,w_int,w_per,w_con,w_kar,
       w_dodge_action,w_min_damage,w_enhance_min_damage,
       wield_str,wield_con,wield_int,wield_dex,wield_force,wield_maxforce)==30)
        {   
            set("strong",str);
            set("max_strong",max_str);
            set("weapon_prop/damage",damage);
            set("user_skill",user_skill);
            set("temp_skill",tskill);
            set("flag",flag);
            set("poison_flag",p_flag);
            
            set("weapon_prop/str",w_str);
            set("weapon_prop/dodge",w_dodge);
            set("weapon_prop/armor",w_armor);
            set("weapon_prop/int",w_int);
            set("weapon_prop/per",w_per);
            set("weapon_prop/con",w_con);
            set("weapon_prop/kar",w_kar);
            
            set("weapon_prop/dodgeaction",w_dodge_action);
            set("weapon_prop/min_damage",w_min_damage);
            set("weapon_prop/enhance_min_damage",w_enhance_min_damage);
            
            set("wield_str",wield_str);
            set("wield_con",wield_con);
            set("wield_int",wield_int);
            set("wield_dex",wield_dex);
            set("wield_force",wield_force);
            set("wield_maxforce",wield_maxforce);
            
            set("user",user);
            set("org_name",org_name);
            set("name",name);
            set("long",wlong);
            set("wield_msg",wield_msg);
            set("unequip_msg",unequip_msg);
            set("unwield_msg",unwield_msg);
            
            set("save_flag",1);
        }
        return;
}
void improve(int i)
{
    add("temp_skill",i);
        if(query("temp_skill")>=5*query("user_skill")*query("user_skill")){
                add("user_skill",1);
                set("temp_skill",0);
        }
        return;
}

int is_dazao()
{
        if(query("save_flag"))
                return 1;
        else
                return 0;
}