#include <ansi.h>;
mixed names = ({
        ({
        "少林广场","王府路","华藏庵","有所不为轩","紫霄宫大门",
        "天微堂","日月坪","赵王府","六和塔","全真教大门", 
        "居庸关","赵王府","缥缈峰山脚","金马枋","星宿海", 
        "雪山寺山门","一品堂大院","星云湖畔","五指堂","五指堂", 
        "凌霄内门","凌霄殿","灵州南门","近日古楼","龙门峰",
        "嘉峪关","丝绸之路","荆州西门","黑风口","龙门峰",
        "南城","土窑馆","萧然居","蒙古草原","漠北",
        "蒙古草原","回族部落","小溪流","鳌拜府","王府井大街",
        "塘沽口","汝州城","丝绸之路","荆州东门","草莓地",
        "长安乐坊","十字街头","长安城西门","锦城驿","全真教大门",
        "蜀都酒楼","金牛武馆","锦城驿","南诏德化碑","剑川镇",
        "玉虚观","星云湖畔","鲁望镇","喜州城","太和街口",
        "福威镖局","榕城驿","保淑塔","终南山主峰","寒水潭",
        "太湖","南浔镇","净慈寺","胡庆余堂","保淑塔",
        "风雷堂","圣姑堂","青龙堂大厅","成德殿","平定州",
        "山海关","大字岭","悬空寺","衡阳西街","刘府大院",
        "玄坛庙","打谷场","群仙观","莲花峰","莎萝坪",
        "朱雀外门","鲁望镇","白虎外门","荆州中心","天安门",
        "扬州武馆","福威镖局","玄妙观","灵隐寺","泉州南门",
        "灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",                
        "蛇骨塔","长安乐坊","衡阳西街","喜州城","葛鲁城", 
        "伊犁","山海关","老龙头","葛鲁城","天山脚下",
        "丽春院","涌泉寺","听雨轩","五老峰","紫金城",
        "松风观","终南山脚","抱子岩","白马潭","升仙坊",                
        "嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
        }),
        ({
         "宋兵","流氓","偏将","裨将","佐将","男孩",
                 "小孩","铁匠",

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
         me->add("combat_exp",-100+random(20));
         me->apply_condition("zzz_busy",4+random(4));
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
          
  if (interactive(ob) && (int)ob->query_condition("zzz_busy"))  
       return "你办事不力，先等会吧。";

  if (interactive(ob) && (int)ob->query_condition("guojob2_busy"))  
       return "现在我可没有给你的任务，等会再来吧。\n";

       if ((int)ob->query_condition("menpai_busy"))  
       return "护送是件危险工作，我看"+ob->query("name")+"需要休息一会！\n";
//        if (ob->query_condition("husong_busy"))
//        return "我现在没有给你的任务。";//husong busy time 
          
  if (interactive(ob) && ob->query_temp("hu_song")
      && (int)ob->query_condition("husong_busy"))  
       return "你上一次的任务还没完成!";
          if(ob->query("combat_exp")<500000)
      return  "你的功夫太差了。";//too low exp
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
          ob->apply_condition("husong_busy",30);
          for(i=0;i<count;i++)
          {if(team[i]!=0)
           team[i]->apply_condition("husong_busy",30);
           team[i]->set_temp("hu_song",1);
          }
          for(i=100;i*i*i/10<=maxexp;i++);
      where=names[0][random(120)];
          call_out("make_npc",0,i,ob,where,count);
          message_vision(HIY"\n$N挥挥手，一位公子从内室慢慢走了过来。\n"NOR,this_object());
          command("say 你帮我把这位公子护送到"+where+"。");
          ob->set_temp("hu_song",1);
          ob->start_busy(2);
          return "速去速回，一路上多加小心。";   
}

void make_npc(int maxpot,object player,string where,int count)
{   object obj;
//        player->start_busy(3);
//      player->set("hu_song",1);
        player->set_temp("hu_song",1);
        obj = new(__DIR__"gongzi");
    obj->move(environment(player));
        obj->set_temp("target",where);
        obj->set_temp("maxpot",maxpot);
    obj->set_temp("count",count);
        obj->set_temp("host",player->query("id"));
        obj->set_leader(player);
        message_vision("$N决定跟随$n一起行动。\n",obj,player);
        obj->apply_condition("hu_song",200);
        return;

}    

