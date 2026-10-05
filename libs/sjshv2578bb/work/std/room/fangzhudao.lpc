//放逐岛房间继承文件 kuku@sjsh 2003.8.25

#include <ansi.h>  
inherit ROOM;  
#include <banned.h>  
       
void setup2()  
{  
        set("fangzhuroom",1);         
        set("alternative_die",1);   
        setup(); 
}  

void init() 
{  
        object me=this_player();        
        this_object()->init2(); 
        
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        add_action("block_cmd","",1);  
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
}  

int block_cmd()  
{  
        string verb = query_verb();  
        object me = this_player(); 
        // wizard set fangzhudao allow all. 
        if (wizardp(me))
                return 0; 
        // 活者可allow all 
        if (!me->query_temp("fangzhudao_died")) 
                return 0; 
        if (verb=="tell") return 0;  
        if (verb=="say") return 0; //allow say  
        if (verb=="help") return 0;  
        if (verb=="look") return 0;  
        return 1;  
}  

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) write("你不能在这里用这条命令。\n");   
        command("cast transfer");
        return 1;
}

int do_exert(string arg) { 
        if(!arg) return 0;
        if(arg !="recover" && arg != "heal" && arg != "refresh") return 0;
        command("exert "+arg);  
}

void alternative_die(object who)  
{  
        object killer,corpse;  
        killer = who->query_temp("last_damage_from");  
   
        if (userp(who)) {  
                message_vision("$N死了。\n",who);  
                who->set("kee",10);        
                who->set("sen",10);  
                if(who->query("eff_kee")<10) 
                        who->set("eff_kee",10);  
                if(who->query("eff_sen")<10) 
                        who->set("eff_sen",10);                 
                if(!killer) 
                        killer=who; 
//              if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
//                      corpse->move(this_object());  
                all_inventory(this_object())->remove_killer(who);  
                who->dismiss_team();  
                who->remove_ride();  
                who->delete_temp("last_fainted_from");                  
                who->delete("env/invisibility");  
                who->move("/d/quest/fangzhudao/kezhan");  
        }  
        else {  
                if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
                        corpse->move(this_object());  
                message_vision("$N死了。\n",who);               
                destruct(who);  
        }  
}
