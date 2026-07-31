//made by kuku@sjsh
#include <ansi.h>  
inherit ROOM;  
#include <banned.h>  
       
void setup2()  
{  
        int level= random(30)+10;   
              int num= random(5)+1;  
              set("magicroom",1);  
              if (!query("level")) set("level",level); //房间等级涉及怪等级  
              if (!query("npc_num")) set("npc_num",num);//怪的出现数目！  
              set("alternative_die",1);   
              setup(); 
}  

void init() 
{  
        object me=this_player();
        this_object()->init2(); 
        add_action("do_quit",banned_action);  
        add_action("do_cast","cast");
        add_action("do_exert","exert");
        add_action("do_give","give");
        add_action("do_kill","kill");
        add_action("block_cmd","",1);  
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
}  

        
int block_cmd()  
{  
        string verb = query_verb();  
        object me = this_player(); 
        // wizard set hellfire allow all. 
        if (wizardp(me))
                return 0; 
        // 活者可allow all 
        if (!me->query_temp("magic_died")) 
                return 0; 
        if (verb=="tell") return 0;  
        if (verb=="chat") return 0; //allow chat  
        if (verb=="help") return 0;  
        if (verb=="look") return 0;  
        if (verb=="quit") {  
          this_player()->delete_temp("magic_died");  
          this_player()->delete("env/invisibility");  
          this_player()->delete_temp("yaota_passnum");
//                this_player()->set("yaota/fail",1);
          this_player()->move("/d/city/kezhan");  
                      }  
                return 1;  
}  

int do_quit(string arg) 
{  
        write("你不能在这里用这条命令。\n");  
        if (wizardp(this_player())) write("巫师请参阅同一路径内的banned.h文档。\n");  
           return 1;  
}  

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) return 0;
        command("cast transfer");
}

int do_exert(string arg) { 
        if(!arg) return 0;
        if(arg !="recover" && arg != "heal" && arg != "refresh") return 0;
        command("exert "+arg);  
}

int do_give(string arg) 
{ 
        write("你不能在这里用这条命令。\n");  
        return 1;  
}

void do_kill(object me, object obj)
{ 
        if( userp(obj) ){
                write("在这里不能对玩家使用kill命令。\n");  
        }
        return;
}

void alternative_die(object who)  
{  
        object killer,corpse;  
        killer = who->query_temp("last_damage_from");  
   
        if (userp(who)) {  
          message_vision("$N死了。\n",who);  
          who->set("kee",10);        who->set("sen",10);  
         if(who->query("eff_kee")<10) who->set("eff_kee",10);  
         if(who->query("eff_sen")<10) who->set("eff_sen",10);  
         who->set("env/invisibility",1);  
         who->set_temp("magic_died",1);  
         if(!killer) killer=who; 
         if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
             corpse->move(this_object());  
         all_inventory(this_object())->remove_killer(who);  
         who->dismiss_team();  
         who->remove_ride();  
         who->delete_temp("last_fainted_from");  
         }  
        else {  
          if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
               corpse->move(this_object());  
          message_vision("$N死了。\n",who);  
             destruct(who);  
              }  
}
