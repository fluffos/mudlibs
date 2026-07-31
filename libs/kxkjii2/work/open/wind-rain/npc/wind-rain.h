#define C_OBJ "/open/wind-rain/obj"
#define C_NPC "/open/wind-rain/npc"
#define C_ROOM "/open/wind-rain"


void greeting(object who)
{
  object me=this_object();

    if(me->query("id")=="liu-un"){    
  if((who->query("family/family_name") == "魔刀门") )
    {
       
       command("say "+who->query("name")+"你是魔刀门的人!!灭族之仇不共戴天,纳命来!!");
       me->kill_ob(who);
    }
                                 }
                                 
    if( (who->query("id") == "taifar") )
    {
       command("say 欢迎总楼主!");
       command("bow "+who->query("name"));
    }
    else if( (who->query("id") == "roger") )
    {
       command("say 欢迎李楼主!");
       command("bow "+who->query("name"));
    }
//xxxx==未来武林盟主的玩家id
     else if( (who->query("id") == "juliet") )
    {
       command("say 武林盟主驾到!");
       command("bow "+who->query("name"));
    }
    else
    {
     command("say 不见风雨，治世有明 ;请问下一句是什么？");
    }
//xxx==未来对某派的格杀令
     if( (who->query("family/family_name") == "xxxx"))
    {
       
     command("say 楼主有令！对"+who->query("family/family_name")+"的人格杀勿论！ ");
     me->kill_ob(who);
    }
return;
}
