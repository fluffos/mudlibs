#include <ansi.h>;
 inherit "/quest2/npcskill";
#include <command.h>;
#include "/quest2/name.h";

object me=this_object(),questob,killertemp;
string username;
string guaiobname,*guaikeysa,*guaikeysb,*guaiobid;
int s1,s2;
string *first_name = ({ "郑","王","张","陈","金","姑苏","钱","孙","李","周","吴",
        "刘","林","钱","木","元","破","喜" });
string *name_words = ({ "志","天","良","志","忠","大","老","良","勇","元","华","宏",
        "孝","雄","龙","明","文","武","斌","来","胜","进","铭","彬","东","伟" });

void create()
{  
         string name, id;
        name = first_name[random(sizeof(first_name))];
//   int level,chooseguai;

/*

*/
//重新写了新的分配名字
            if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
     id = this_player()->query("id");

          set_name(name, ({ id+" killer", "killer" }) );

   set("gender","男性");
   set("env/wimpy", 40);
   set("per",10);
   set("age",60);
   set("attitude", "friendly");
   set("no_dun",1);
   set("yguai",1);
   add_temp("apply/armor",600);
   add_temp("apply/damage",50);
   add_temp("apply/weapon",200);
   set("chat_chance",70);

   set("chat_chance_combat",random(90));
   setup();
 carry_object("/clone/misc/sleepbag");   //如果没有睡袋的话就屏蔽掉
}
int setguaiskill(int chooseguai,int level,object guai)
{  
   guai=this_object();
   set_std_skills(level,guai);
   switch (chooseguai)
    {
      case 1:set_shaolin_guai(level,guai);carry_shaolin_weapon();break;
      case 2:set_wudang_guai(level,guai);carry_wudang_weapon();break;
      case 3:set_dali_guai(level,guai);carry_dali_weapon();break;
      case 4:set_emei_guai(level,guai);carry_emei_weapon();break;
      case 5:set_xueshan_guai(level,guai);carry_xueshan_weapon();break;
      case 6:set_murong_guai(level,guai);carry_murong_weapon();break;
      case 7:set_gaibang_guai(level,guai);carry_gaibang_weapon();break;
      case 8:set_taohua_guai(level,guai);carry_taohua_weapon();break;
      case 9:set_mingjiao_guai(level,guai);carry_mingjiao_weapon();break;
      case 10:set_gumu_guai(level,guai);carry_gumu_weapon();break;
      case 11:set_xiaoyao_guai(level,guai);carry_xiaoyao_weapon();break;
      case 12:set_riyue_guai(level,guai);carry_riyue_weapon();break;
      case 13:set_quanzhen_guai(level,guai);carry_quanzhen_weapon();break;
      default:set_master_guai(level,guai);carry_master_weapon();break;
    }
}
//怪怎么也会疗伤?
void heart_beat()
{
   
   int qi,effqi,maxqi,neili,max_neili;
   maxqi=(int)this_object()->query_temp("maxqi");   
   effqi=(int)this_object()->query("eff_qi");
   qi=query("qi");
   if (effqi<maxqi) command("exert heal");
   if (qi<(int)(effqi*2/3)) command("exert recover");
   maxqi=(int)this_object()->query_temp("maxjing");   
   effqi=(int)this_object()->query("eff_jing");
   qi=query("jing");
   if (qi<(int)(effqi*2/3)) command("exert regenerate");
   neili=(int)this_object()->query("neili");
   max_neili=(int)this_object()->query("max_neili");
   if(neili<(max_neili/2))
   set("neili",max_neili/2);
   ::heart_beat();
}

 int check_time(object ob)
{

   if (!query_temp("appear")) 
     {
       set_temp("appear",1);
 call_out("check_time",900,ob);
       return 1;
     }
   if (me->is_fighting()) 
     {
 call_out("check_time",600,ob);
       return 1;
     }
   remove_call_out("check_time");
if(objectp(ob))
 message_vision(MAG"$N眼见情况不妙，大叫一声，溜了。\n"NOR,ob);
   destruct (this_object());
}


void die ()
{
      int pot,exp,qn;
    object killerob,me,jinyong;
    mixed questob;
    me=this_object();
    killerob=me->query_temp("last_damage_from");
                    
    questob=(object)me->query_temp("player"); 
    questob->set_temp("kill",0); 
    if (!killerob) 
    {   
        message_vision("$N惨叫一声，死了。\n",this_object());
         tell_object(questob,"你得到了零点经验和零点潜能！\n"NOR);
        destruct(me);
        return;    
    }
    else if (killertemp)
     {
        if (killertemp!=killerob)
          {
             message_vision("$N惨叫一声，死了。\n",this_object());
             tell_object(questob,"你得到了零点经验和零点潜能！\n"NOR);
             destruct(me);
             return;    
          }
     } 
    if (killerob->query("id")!=questob->query("id"))
    {  
       message_vision("$N惨叫一声，死了。\n",this_object());
        tell_object(questob,"你得到了零点经验和零点潜能！\n"NOR);
       destruct(me);
       return; 
    }
    message_vision("$N惨叫一声，死了。\n",this_object());
exp = (questob->query_int()*5) + (questob->query("kar")*20) + random(1000);
  if (exp > 10200) exp = 9809+random(200);
pot = (exp/10);
   if (pot > 3100) pot = 2888+random(200);
    questob->add("combat_exp",exp);
    questob->add("score",exp/5);
       questob->add("potential",exp/(random(5)+2));
/*
  jinyong=load_object("/jyquest/jinyong");
CHANNEL_D->do_channel(jinyong,"chat",questob->name(1)+"杀死了"+this_object()->name()+",得到"
  +chinese_number(exp)+"点经验,"+chinese_number(qn)+"点潜能！");
*/
    tell_object(questob,"你得到了\n"+HIW+
 chinese_number(exp)+NOR"点经验和"+HIW+chinese_number(qn)+NOR"点潜能以及"HIW+chinese_number(exp/5)+"点江湖阅历!\n");
    destruct(me);
   
}
//不能让别人帮忙打晕怪   
void unconcious()
{
  killertemp=query_temp("last_damage_from");
  ::unconcious();
}
void init()
{
    if (is_busy()) return;
    add_action("do_drive","drive");
    username=query_temp("killername");
    if ((int)environment(me)->query("no_fight")) return; 
    if (this_player()->query("id")==username)
     { 
       if (query_temp("firstsee")==0||!query_temp("firstsee"))
         {  if(random(40)>20){     
         message_vision(HIR"$N恶狠狠地盯着$n，大叫一声，竟然找上门来了，今天不是你死就是我亡！\n"NOR
         ,this_object(),this_player());
//          this_object()->kill_ob(this_player());
          command("follow "+this_player()->query("id"));}
         else this_object()->command("? "+this_player()->query("id"));
          set_temp("firstsee",1);

          
          }
         set_heart_beat(1);
//         if(random(40)<20) this_object()->kill_ob(this_player());
       
        
         
     }   
}

int do_drive(string arg)
{
    mapping exits;
    string *dirs;
    int size;
    if (arg==(string)this_object()->query("id"))
      {
        if (environment()->query("no_fight"))
         {
           exits=environment()->query("exits");      
           dirs=keys(exits);
           size=sizeof(dirs);
           if (size>0)
             { 
              this_player()->command("follow "+this_object()->query("id"));
              command("go "+dirs[random(size)]);
              return 1;
             }
          }
       }
     return 0;
}
