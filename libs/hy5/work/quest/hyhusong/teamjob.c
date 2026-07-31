#include <ansi.h>;
string *npc_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","柳","风","刘","林", }); 
mixed names = ({
        ({
        "巴陵广场","九龙壁","天安门","长安戏院","大雁塔",
        "山海关城楼","岳麓书院","望江阁","杜甫草堂","陆羽茶馆",
        "王府路","双鹤桥","定襄广场","万年庵","报国寺",
        "南岭山口","福威镖局","山神庙","太湖","断桥",
        "胡庆余堂","钱塘江畔","灵隐寺","合肥广场","猩猩滩",
        "平定州","赤帝峰","祝融殿","悬空寺南楼","二仙祠",
        "人字瀑","镇岳宫","平心石","开元观","烟雨楼",
        "牛家村口","趵突泉","大明湖","关圣庙","萧湘书院",
        "秦淮河","雨花台","逍遥津","庐山","开封府",
        "野猪林","昆仑派山门","碧鸡枋","天风川","一品堂大门",
        "白马寺","洛神庙","马邑城中心","四雅清风","铁木真营帐",
        "天微堂","佛心井","武侯祠","阿育王寺","祁连山",
        "驻鹤庄","试剑岩","施琅将军府","汝州城","少林广场",
        "白塔宝刹","天中阁","藏珠阁","寒山寺","岱庙",
        "晋祠","崇圣宝殿","芦苇荡","三清殿","普光寺",
        "富家大门","崇安寺","武夷宫","玄武外门","青草坪",
        "缥缈峰山脚","火焰山","圣湖","芙蓉客栈","南浔镇",
        "小乔墓","点将台","龙门镖局","中州贡院","西夏古碑",
        "九江广场","全聚德酒楼","吐鲁番","剑川镇","长安乐坊",
        "胡庆余堂","宁远","山海关","老龙头","丽春院",
        }),
        });
string ask_fangqi()
{
         object me;
object obj;
         me = this_player();
         if(me->query_condition("husong_busy")<=1)
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->clear_condition("husong_busy");
         if (me->query("combat_exp",1) > 300) me->add("combat_exp",-200+random(20));
         me->apply_condition("zzz_busy",18);
         me->apply_condition("menpai_busy",18);
         me->apply_condition("hu_song",0);
         me->clear_condition("hu_song");
         me->delete_temp("hu_song");
if (obj=present("gong zi",environment(me)))
{
if(obj->query_temp("host")==me->query("id"))
{
destruct(obj);
}
}
         return "没关系,下次继续努力 。";
}

string ask_job()
{     object wang,ob;
      object *team;
          int i=0,count=0,minexp,maxexp;
      string where;
          wang =this_object();
          ob=this_player();
          
  if (!wizardp(ob) && interactive(ob) && (int)ob->query_condition("zzz_busy"))  
       return ob->query("name")+"你办事不力，先等会吧。";

  if (!wizardp(ob) && interactive(ob) && (int)ob->query_condition("guojob2_busy"))  
       return ob->query("name")+"现在我可没有给你的任务，等会再来吧。\n";

       if (!wizardp(ob) && (int)ob->query_condition("menpai_busy"))  
       return "护送是件危险工作，我看"+ob->query("name")+"需要休息一会！\n";
//        if (ob->query_condition("husong_busy"))
//        return "我现在没有给你的任务。";//husong busy time 
          
  if (!wizardp(ob) && interactive(ob) && ob->query_temp("hu_song")
      && (int)ob->query_condition("husong_busy"))  
       return ob->query("name")+"你上一次的任务还没完成!";
          if(ob->query("combat_exp")<5000000 && ob->query("jobtime")!=6)
      return  ob->query("name")+"你的功夫太差了。";//too low exp

          if(ob->query_skill("force",1)<100)
      return  ob->query("name")+"你的功夫太差了。";//too low exp

      team=ob->query_team();
      count=sizeof(team);
      if(count>=5)
          return "此事不宜张扬。"; //too many people
          minexp=ob->query("combat_exp");
          maxexp=minexp;
      
          for(i=1;i<count;i++)
      { if(team[i]!=0)
          {
                if(team[i]->query("combat_exp")<minexp)
            minexp=team[i]->query("combat_exp");
                if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
          }
          }
          if ((maxexp-minexp)>800000)
      return "你们的武功相差太悬殊。";//exp too far
     //check ok
     // ob->set_temp("team_count",count);
          ob->apply_condition("husong_busy",60);
          for(i=0;i<count;i++)
          {if(team[i]!=0)
           team[i]->apply_condition("husong_busy",60);
           team[i]->set_temp("hu_song",1);
          }
         // for(i=100;i*i*i/10<=maxexp;i++);
         i=ob->query_skill("force",1);
      where=names[0][random(sizeof(names[0]))];
          call_out("make_npc",0,i,ob,where,count);
          message_vision(HIY"\n$N挥挥手，一位公子从内室慢慢走了过来。\n"NOR,this_object());
          command("say "+ob->query("name")+"你帮我把这位公子护送到"+where+"。");
          ob->set_temp("hu_song",1);
          ob->apply_condition("menpai_busy",8);
          ob->start_busy(2);
          return ob->query("name")+"速去速回，一路上多加小心。";   
}

void make_npc(int maxpot,object player,string where,int count)
{   object obj;
//        player->start_busy(3);
//      player->set("hu_song",1);
        player->set_temp("hu_song",1);
        obj = new(__DIR__"gongzi");
    obj->move(environment(player));
    player->set_temp("hstarget",where);
        obj->set_temp("target",where);
        obj->set_temp("maxpot",maxpot);
    obj->set_temp("count",count);
     obj->set_name(player->query("name")+"护送的"+npc_name[random(sizeof(npc_name))]+"公子", ({player->query("id")+" gz","gong zi"}));
        obj->set_temp("host",player->query("id"));
        obj->set_leader(player);
        message_vision("$N决定跟随$n一起行动。\n",obj,player);
        player->apply_condition("hu_song",100);
        return;

}    

