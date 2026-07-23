#include <ansi.h>
void full_me(object me);
void check2();
void check();
void destroying(object me)
{        
destruct(me);        
return;
}
int checking(object me, object ob)
{        
if((int)me->query("kee")* 100 / (int)me->query("max_kee") <= 20)
{                
if (!living(me)) 
return 1;                 
else 
{                  
message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR,me);                  
destruct(this_object());                  
return 1;                 
}        
}        
if (me->is_fighting())         
{                
call_out("checking",1, me, ob);                
return 1;        
}        
if ( !present(ob->query("id"), environment()) && present("huo che",environment()) )           
{                  
command("laugh");                
command("jie huo che");                
message_vision("$N推着货车呼啸而去。\n", me);                
call_out("destroying",1,me);                
return 1;        
}        
if (!present(ob->query("id"), environment()))          
{              
message_vision("$N悻悻的说：“算你跑的快！”\n",me);              
command("sigh");              
message_vision("$N身行几起几纵消失在暗处\n",me);              
call_out("destroying",1,me);              
return 1;          
}             
}

/*
void kill_ob(object ob)
{
  set_temp("my_killer",ob);
  remove_call_out("check");
  call_out("check",1);
  remove_call_out("check3");
  call_out("check3",1);
  remove_call_out("check2");
  call_out("check2",1);
  ::kill_ob(ob);
}
*/
void init()
{
    add_action("do_kill","kill"); 
    add_action("do_kill","fight");  
}

int do_kill(string arg) 
{
object who = this_player(); 
object me = this_object();

if(!arg || present(arg,environment(me))!=me) return 0; 
if (me->query("jiebiao")!=who) 
        {
        tell_object(who,CYN"你也是道上的朋友吧？还是不要多管闲事为好！\n"NOR);  
        return 1;
        }
me->set("zhuanshi_cnt",who->query("zhuanshi")-1);
return 0; 
}

//check3()是防止别人去帮忙杀
void check3()
{
     object me=this_object();
if (me->query_temp("last_damage_from")&&me->query_temp("my_killer"))
{
    if(me->query_temp("last_damage_from")!=me->query_temp("my_killer"))
{
     message_vision("你们想以多取胜，我可要发彪了！\n",me);
     full_me(me);
}
}
 remove_call_out("check3");
 call_out("check3",1);
}
void check2()
{
        object me = this_object();
        int i;
        object *emery=me->query_emery();

        if( sizeof(emery)==0 )
        {
        remove_call_out("check2");
        full_me(me);
        return ;
        }

        if( !me->is_fighting() )
        {
        full_me(me);
        remove_call_out("check2");
        return ;
        }


        for(i=0;i<sizeof(emery);i++)
        {
                if(!interactive(emery[i]) )
                full_me(me);
        }

        remove_call_out("check2");
        call_out("check2",1);
        return;
}

void full_me(object me)
{
        me = this_object();
        me->command("say 老子天下无敌！");
        me->command("say 想杀我，看你的本事了！");
        me->revive();
        me->set("kee",query("max_kee"));
        me->set("eff_kee",query("max_kee"));
        me->set("sen",query("max_sen"));
        me->set("eff_sen",query("max_sen"));
        me->set("force",query("max_force")*2);
        me->set("mana",query("max_mana")*2);
        me->clean_condition();
        return;
}

void copy_change(object ob) 
{
 object me = this_object();
 me->add_temp("apply/armor",ob->query_temp("apply/armor")); 
 me->add_temp("apply/damage",ob->query_temp("apply/damage")/2); 
}
