
mixed query_autoload()
{   
        
        if (! query("autoload"))
                return 0;
        
        if (!query("long")) set("long",this_object()->short()+"\n");
        return 
               query("name")+" "+
               query("long")+" "+
               query("armor_prop/armor")+" "+
               query("armor_prop/parry")+" "+
               query("armor_prop/dodge")+" "+
               query("armor_prop/damage")+" "+
               
               query("armor_prop/str")+" "+
               query("armor_prop/int")+" "+
               query("armor_prop/con")+" "+
               query("armor_prop/dodgeaction")+" "+
               
               query("armor_prop/per")+" "+
               query("armor_prop/kar")+" "+
               
               query("wear_str")+" "+
               query("wear_con")+" "+
               query("wear_int")+" "+
               query("wear_dex")+" "+
               query("wear_force")+" "+
               query("wear_maxforce")+" "+
               
               query("no_need_force")+" "+
               query("no_need_maxforce")+" "+
               query("no_need_sx")+" "+
               query("reduce_force")+" "+
               query("reduce_maxforce")+" "+
               query("reduce_sx")+" "+
                             
               query("armor_prop/enhance_min_damage")+" "+
               query("armor_prop/enhance_max_damage")+" "+
               query("armor_prop/double_damage");               
               
              
}

void autoload(string pa)
{   
    string name,longs;
    int armor,parry,dodge,damage;
    int str,intl,con,dex;
    int per,kar;
    int w_str,w_con,w_int,w_dex,w_force,w_maxforce;
    int no_need_force,no_need_maxforce,no_need_sx,reduce_force,
        reduce_maxforce,reduce_sx;
    int enhance_min_damage,enhance_max_damage,double_damage;  
    
    if(sscanf(pa,"%s %s "+
                 "%d %d %d %d "+
                 "%d %d %d %d "+
                 "%d %d "+
                 "%d %d %d %d %d %d "+
                 "%d %d %d %d %d %d "+
                 "%d %d %d",
       name,longs,
       armor,parry,dodge,damage,
       str,intl,con,dex,
       per,kar,
       w_str,w_con,w_int,w_dex,w_force,w_maxforce,
       no_need_force,no_need_maxforce,no_need_sx,reduce_force,
       reduce_maxforce,reduce_sx,      
       enhance_min_damage,enhance_max_damage,double_damage)==27)
        {               
            set("name",name);
            set("long",longs);
            
            set("armor_prop/armor",armor);
            set("armor_prop/parry",parry);
            set("armor_prop/dodge",dodge);
            set("armor_prop/damage",damage);
            
            set("armor_prop/str",str);
            set("armor_prop/int",intl);
            set("armor_prop/con",con);
            set("armor_prop/dodgeaction",dex);
            
            set("armor_prop/per",per);
            set("armor_prop/kar",kar);
            
            set("wear_str",w_str);
            set("wear_con",w_con);
            set("wear_int",w_int);
            set("wear_dex",w_dex);
            set("wear_force",w_force);
            set("wear_maxforce",w_maxforce);
            
            set("no_need_force",no_need_force);
            set("no_need_maxforce",no_need_maxforce);
            set("no_need_sx",no_need_sx);
            set("reduce_force",reduce_force);
            set("reduce_maxforce",reduce_maxforce);
            set("reduce_sx",reduce_sx);
            
            set("armor_prop/enhance_min_damage",enhance_min_damage);
            set("armor_prop/enhance_max_damage",enhance_max_damage);
            set("armor_prop/double_damage",double_damage);
            
            set("save_flag",1);
        }
        return;
}
