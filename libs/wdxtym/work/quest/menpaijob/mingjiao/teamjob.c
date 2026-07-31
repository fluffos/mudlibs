#include <ansi.h>
int ckiller=3;
mixed names = ({
        ({
        "明教前殿","明教西侧殿","明教东侧殿","明教大殿","明教大殿",
        "天微堂","紫微堂","天市堂","烈火旗后门","烈火旗大厅",
        "烈火旗大门","烈火旗牌坊","巨木旗大门","锐金旗大厅","明教山门",                
//"明教山门",
        }),
        });

string ask_jianxi()
{
     object guo,ob;
     string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "明教")
	  return "你非我派弟子!!";//guo busy time 
	  
	  if (ob->query_condition("mjtjob2"))
	  return "现在没有你的任务!";//guo busy time 

//	  if (guo->query_condition("mingjiaojob"))
//	  return "我没有收到任何消息。";//guo busy time 
	  
     if(ob->query("combat_exp")<100000)
      return  "你的功夫太差了。";//too low exp

      if( ob->query_skill("jiuyang-shengong",1) < 50)
      return  "你的本门内功太差了。";//too low exp      
	  where=names[0][random(15)];
//	  guo->apply_condition("mingjiaojob",16);
	  ob->set("mjjob",1);
	  ob->apply_condition("mingjiaojob",60);
          ckiller=3;
ob->set_temp("mjtjob",where);ob->apply_condition("mjtjob",24);ob->apply_condition("mjtjob2",16);
//      call_out("job",80,ob,where,);
	  return    "我刚得到消息，有一名五大门派的首领带了弟子前来攻我圣教。\n"+
		        "          你赶快去"+where+"设防阻截，\n"+
			    "          务必消灭敌人的首领，多加小心。"; 

}

void job(object ob,string where,int maxpot)
{    object obj,gift;
      object guo=this_object();     
     int i=0;
if(!ob) return;
if(environment(ob)->query("short")!=where && ob->query_condition("mingjiaojob"))
{
             tell_object(ob, HIY "\n你防守的地方不对吧!五派首领杀进了明教，你任务失败！\n" NOR); 
}
     guo->apply_condition("mingjiaojob",0);
     if(environment(ob)->query("short")==where&&ob->query_condition("mingjiaojob"))
	 {
	    if (ckiller>0)
	    {if (random(20)>15)
			{ obj=new(__DIR__"wudang");   
	          obj->do_copy(ob,maxpot,3);
	          obj->set("title",HIY"武当派弟子"NOR);     
              obj->move(environment(ob));
              obj->kill_ob(ob);
			}
		     else 
			{
	  	      obj=new(__DIR__"emei"); 
		      obj->do_copy(ob,maxpot,1);
	          obj->set("title",HIG"峨嵋派弟子"NOR);
	          obj->move(environment(ob));
              obj->kill_ob(ob);
	          obj=new(__DIR__"shaolin");
	           obj->set("title",HIW"少林派弟子"NOR);
		      if (random(20)>5)
			  {obj->do_copy(ob,maxpot,2);
	           obj->set("title",HIW"少林派弟子"NOR);
			  }
			   else 
               obj->do_copy(ob,maxpot,1);
		       obj->move(environment(ob));
               obj->kill_ob(ob);
			 }  
                  ckiller=ckiller-1;
	  	  call_out("job",60,ob,where,maxpot,ckiller-1);
	    }
	    else 
		 {if (present("menggu",environment(ob)))
			{//present menggu dahan,then mission failed
			 tell_room(environment(ob),HIC"蒙古兵挥挥手，五派首领先走。\n五派首领匆匆忙忙的离开了。\n"NOR);
             tell_object(ob, HIY "\n五派首领杀进了明教，你任务失败！\n" NOR); 
			}
 	     else{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIG"五派首领"NOR);
                                obj->set_temp("hostmj",ob->query("id"));
				obj->move(environment(ob));
				message_vision(HIY"$N狂笑不已：就凭你们几个也想挡住我的去路?\n"NOR, obj);
				obj->kill_ob(ob);
     guo->apply_condition("mingjiaojob",0);
//				gift=new(__DIR__"mijian");
//			田	gift->set_temp("host",ob->query("id"));
//				gift->move(obj);
				}
		}
	 }
}