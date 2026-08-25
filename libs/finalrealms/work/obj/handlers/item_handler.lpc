mapping mylist = (["fire":1,"cold":1,"magical":1,"electrical":1,"stone":1,
  "poison":1,"air":1,"noguild":1,"nocast":1,
   "acid":1,
  "BLIND":1,
  "sense_life":1,
  "evil":1,"good":1,
  "fear":1,"psionic":1,
  "wolfbane":1,
  "con":2,"dex":2,"str":2,"cha":2,"wis":2,"int":2
]);
/* 
   This stuff just cleans up the code, tidies 6 repeated tests into 1
   Note that the way this is coded, it is unwise to wear "enchanted"
   items for too long, you'll take a temp hit on removal if you do
*/      
protected void stat_adjust(string query_tmp,string query_total,string adj,int j,object user_ob)
{
    int total,temp;
    if(!intp(j)) return;
    if(j < 0) // if removing a stat, be sure we don't kill them :)
    {
        total = call_other(user_ob,query_total);
        if((total + j) < 1)
        {
            j = 1-total;        
        }
        call_other(user_ob,adj,j);
    }
    else // Otherwise don't add to it if it already exists
    {
        temp = call_other(user_ob,query_tmp);
        if(temp <= 0)
            call_other(user_ob,adj,j);                          
    }
}
/* Simillar to above, checks for tags marking guild only properties etc */
int generic_check(string checkfor,string query,object user_ob,object ob)
{
    mixed prop;
    string targ;
    prop = ob->query_property(checkfor);
    if(!prop) return 0;
    targ = call_other(user_ob,query);
    if((stringp(prop) && prop != targ) || (pointerp(prop) && member_array(targ,prop) == -1))
    {
        return 1;
    }
    return 0;
}

int local_in_use(int i,object user_ob,object ob)
{
    string *ks;         
    mixed str;
    string targ;
    int k;
    mixed j;
    mixed rp;
    mapping timed_prop;

    if(!user_ob) return 0;
    timed_prop = (mapping)ob->query_timed_properties(); 

    if(i)
    {
        // Taniwha 1996, guild only checks etc.
        if(generic_check("guild","query_guild_name",user_ob,ob))
        {
            tell_object(user_ob,"The "+(string)ob->query_cap_name()+" requires specialized guild skills to use.\n");
            return 0;
        }       
        // Fits only a race or races    
        if(generic_check("race","query_race",user_ob,ob))
        {
            tell_object(user_ob,"The "+(string)ob->query_cap_name()+" is made for someone with a different body shape from yours. "
              "You just can't use it.\n");
            return 0;            
        }
        // special interest group
        if(generic_check("sig","query_group_name",user_ob,ob))
        {
            tell_object(user_ob,"Sigils flare to life on the "+(string)ob->query_cap_name()+
              " preventing you from using it.\n");
            return 0;            
        }
        // gender (0 = asexual, 1 = male, 2 = female, 3 = bisexual)
        if(generic_check("gender","query_gender_string",user_ob,ob))
        {
            tell_object(user_ob,"Try as you might to wear the"
              " "+(string)ob->query_cap_name()+", you are"
              " clearly of the inappropriate gender.\n");
            return 0;
        }
        // racial group (clan)
        if(generic_check("clan","query_race_group_name",user_ob,ob))
        {
            tell_object(user_ob,"You can't bring yourself to use a "+(string)ob->query_cap_name()+
              " belonging to another clan.\n");    
            return 0;
        } 
        // Deity.
        if(generic_check("deity","query_deity",user_ob,ob))
        {
            tell_object(user_ob,
              "The Gods prevent you from using this item.\n");
            return 0;
        } 
        // class, fighter rogue priest wizard
        if(generic_check("class","query_class_name",user_ob,ob))
        {
            tell_object(user_ob,"You lack the skills to use a "+(string)ob->query_cap_name()+
              ".\n");    
            return 0;
        } 
        // individual player
        if(generic_check("player","query_name",user_ob,ob))
        {
            tell_object(user_ob,"You can't use a "+(string)ob->query_cap_name()+
              " it's been customized to fit someone else.\n");    
            return 0;
        } 
        // quest item, tagged when got
        targ = ob->query_property("property");
        if(stringp(targ) && !user_ob->query_property(targ))
        {
            tell_object(user_ob,"The Gods prevent you using an item you havn't earned.\n");
            return 0;
        }
// added by malik for thingies for commands etc to check for 
        if(rp = ob->query_timed_property("relay_property")){
           user_ob->add_static_property(rp[0],rp[1]);
        }
   /* Taniwha, turning up all over, removed. I didn't QC, neither did Raisa.
        k = ob->query_property("a.c.");
        if(k && !user_ob->query_tmp_a_bon()) user_ob->adjust_tmp_ac_bon(k);
        k=ob->query_property("thac0");
        if(k) user_ob->adjust_thac0(k);
  */
    }
    else  // unwearing
    {
        str = ob->query_property("cursed");
        if(str)
        {
            if(stringp(str)) tell_object(user_ob,str);
            else if(pointerp(str))
            {
                tell_object(user_ob,str[0]);
                if(sizeof(str) >1  && environment(user_ob))
                    tell_room(environment(user_ob),str[1],user_ob);
            }
            tell_object(user_ob,"Oops, it's cursed.\n");
            return 1;
        }
// Malik was here
        rp = ob->query_timed_property("relay_property");
        if(rp){
           user_ob->remove_static_property(rp[0]);
        }
    }
    if(timed_prop && sizeof(ks = keys(timed_prop)) )
    {   
        if(i) // being worn
        {
            // any messages ?   
            str = ob->query_property("messon");
            if(stringp(str)) tell_object(user_ob,str); // single string, tell wearer
            else if(pointerp(str)) // array, wearer + tell_room
            {
                tell_object(user_ob,str[0]);
                if(sizeof(str) > 1 && environment(user_ob))
                {
                    tell_room(environment(user_ob),str[1],user_ob);
                }
            }      
            // Magical effects, stats mods etc
            for(k = 0; k < sizeof(ks); k++)
            {
                j = ob->query_timed_property(ks[k]); // This way it wears off still.
                if(mylist[ks[k]] )
                    switch(ks[k])
                {
                case "con":
                case "str":
                case "dex":
                case "wis":
                case "int":
                case "cha":
                    if(intp(j)) 
                        stat_adjust("query_tmp_"+ks[k],"query_"+ks[k],"adjust_tmp_"+ks[k],j,user_ob);   
                    break;
                default:
                    user_ob->add_static_property(ks[k],j);
                    break;      
                }
            }   
        }                                                     
        else // being unworn
        {
/* Abused, therefore removed. Taniwha 1997
            k = ob->query_property("a.c.");
            if(k && !user_ob->query_tmp_a_bon()) user_ob->adjust_tmp_ac_bon(-k);
            k=ob->query_property("thac0");
            if(k) user_ob->adjust_thac0(-k);
  */
            str = ob->query_property("messoff");
            if(stringp(str)) tell_object(user_ob,str);
            else if(pointerp(str))
            {
                tell_object(user_ob,str[0]);
                if(sizeof(str) > 1 && environment(user_ob))
                {
                    tell_room(environment(user_ob),str[1],user_ob);
                }
            }      
            for(k = 0; k < sizeof(ks); k++)
            {
                j = ob->query_timed_property(ks[k]); // This way it wears off still.
                if(mylist[ks[k]])
                    switch(ks[k])
                {
                case "con":
                case "str":
                case "dex":
                case "wis":
                case "int":
                case "cha":
                    if(intp(j))
                        stat_adjust("query_tmp_"+ks[k],"query_"+ks[k],"adjust_tmp_"+ks[k],-j,user_ob);
                    break;
                default:
                    user_ob->remove_static_property(ks[k]);
                    break;      
                }
            }                                                 
        }
    }           
    return i;
}

