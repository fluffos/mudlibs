mapping city_area=([
/*
 "扬州城" : ({"/d/city/","beidajie1","beidajie2","beimen","guangchang",
              "nandajie1","nandajie2","nanmen","qianzhuang","shuyuan",
              "xidajie1","xidajie2","ximen",
            }),
*/
 "泉州城" : ({"/d/quanzhou/","beimen","haigang","jiaxing","jxnanmen",
              "nanhu","nanhu1","nanmen","qzroad1","qzroad2","qzroad3",
              "qzroad4","qzroad5","tieqiang","yanyu","zahuopu","zhongxin",
            }),
 "灵鹫宫" : ({"/d/lingjiu/","dating","damen","changl15","changl7","changl6",
              "changl5","changl1","changl9","changl12","changl8","changl4",
              "changl3","changl2","changl10","huayuan","xiaodao1","xiaodao2",
            }),
 "白驼山" : ({"/d/baituo/","chaifang","changlang","chufang","damen","datiepu",
              "dating","dongjie","guangchang","houmen","houyuan","huayuan",
              "jiudian","menlang","tuyuan","xijie","ximen","yaofang","yuanzi",
            }),
 "北京城" : ({"/d/city2/","chaoyan1","chaoyan2","chaoyang","di_an1","di_an2",
              "di_an3","di_an4","di_anmen","dongcha1","dongcha2","dongchangdamen",
              "dongmen","nandaj1","nandaj2","tian_anm","wangfu1","wangfu2",
              "wangfu3","xichang1","xichang2","xidan","xidan1","ximen",
            }),
         ]);

string *city_name=({"扬州城","泉州城","灵鹫宫","白驼山","北京城"});
string site_name=city_name[random(sizeof(city_name))];
int haojie_times;

int place_killer(string site,object ob)
{
     string *location, site_file;
     int size;

     location=city_area[site];
     size=sizeof(location);

     site_file=location[0]+location[random(size-1)+1];
     ob->set("area",site);
     ob->set("place_name",site_file);
     ob->move(site_file);
     return 1;
}

void haojie_begin(int num)
{
     object killer;
     int n;

     if( haojie_times < 1 )
     {
        remove_call_out("haojie_begin");
        return;
     }

     if( haojie_times >= 4  )
     {
        remove_call_out("haojie_begin");
        remove_call_out("haojie_new");
        call_out("haojie_new",600,num);
        return;
     }

     haojie_times++;

     message("channel:rumor", HIR"【浩劫】"HIW"江湖英雄令"
            +HIR"重现江湖，号召各路豪杰齐赴"+HIY+site_name+HIR"抵御"
            +HIB"杀手帮"+HIR"之入侵！\n"NOR,users());
     for(n=0;n<num;n++)
     {
          killer=new("/quest/chousha/killer");
       killer->start_escape(500);
          place_killer(site_name,killer);
     }

 remove_call_out("haojie_begin");
  call_out("haojie_begin",30,num);
     return;
}
              
void haojie_new(int num) 
{
     if( haojie_times >= 4 )
     {
        haojie_times=2;
       message("channel:rumor", HIR"【浩劫】经过一段时间的殊死"
        +HIR"搏斗，双方皆有伤亡，进入了短暂的休整！\n"NOR,users()); 

          remove_call_out("haojie_begin");
       call_out("haojie_close",5,num);
     }  

     remove_call_out("haojie_new");
     return;
}

void haojie_close()
{
   string temp;
   int killer_rate,chousha_count;
   object *ulist;
   int k;

   ulist=users();
   k=sizeof(ulist);
   while (k--)
   {
      if( !environment(ulist[k]) || !ulist[k]->query_temp("haojie")) continue;
      ulist[k]->delete_temp("haojie");
      ulist[k]->delete_temp("apply/short");
   }

   message("channel:rumor", HIR"【浩劫】经过各路武林豪杰的殊死抗争，"
   +HIY"杀手帮"+HIR"称霸武林的阴谋终于暂时宣告破灭，\n江湖中又似乎恢复"
   +"了以往的片刻安平！\n"NOR,users());

   haojie_times=0;
   killer_rate=6;
   temp=sprintf("%d",killer_rate);
   write_file("/quest/chousha/killer_rate",temp,1);
   chousha_count=0;
   temp=sprintf("%d",chousha_count);
write_file("/quest/chousha/chousha_count",temp,1);

   remove_call_out("haojie_begin");
   remove_call_out("haojie_close");
   return;
}

