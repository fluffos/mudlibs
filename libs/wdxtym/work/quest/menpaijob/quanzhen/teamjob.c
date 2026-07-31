#include <ansi.h>
int ckiller=3;
mixed names = ({
        ({
        "试剑岩","教碑","访真桥","遇真宫","观日台",
        "抱子岩","日月岩","老妪岩","黑凤洞","神禾原",
        "全真教大门","草堂寺","半山亭","白马潭","金莲阁",                
        }),
        });

string ask_jianxi()
{
     object guo,ob;
     string where;
	  guo =this_object();
	  ob=this_player();
	  
        if( ob->query("family/family_name") != "全真教")
	  return "你非我派弟子!!";//guo busy time 
	  
	  if (ob->query_condition("qztjob2"))
	  return "现在没有你的任务。";//guo busy time 

//	  if (guo->query_condition("quanzhenjob"))
//	  return "我没有收到任何消息。";//guo busy time 
	  
     if(ob->query("combat_exp")<100000)
      return  "你的功夫太差了。";//too low exp
      if( ob->query_skill("xiantian-qigong",1) < 50)
      return  "你的本门内功太差了。";//too low exp

      
	  where=names[0][random(15)];
//	  guo->apply_condition("quanzhenjob",16);
	  ob->set("qzjob",1);
	  ob->apply_condition("quanzhenjob",60);
          ckiller=3;
ob->set_temp("qztjob",where);ob->apply_condition("qztjob",22);ob->apply_condition("qztjob2",15);
//      call_out("job",80,ob,where,);
	  return    "我刚得到消息，有蒙古护国法王带了一群蒙古兵前来,对我教不利。\n"+
		        "          你赶快去"+where+"设防阻截，\n"+
			    "          务必消灭敌人的护国法王，多加小心。"; 

}

void job(object ob,string where,int maxpot)
{    object obj,gift;
     object guo=this_object();
     int i=0;
if(!ob) return;

if(environment(ob)->query("short")!=where && ob->query_condition("quanzhenjob"))
{
             tell_object(ob, HIY "\n你防守的地方不对吧!蒙古护教法王进了全真教了，你任务失败！\n" NOR); 
}

     guo->apply_condition("quanzhenjob",0);
     if(environment(ob)->query("short")==where&&ob->query_condition("quanzhenjob"))
	 {
	    if (ckiller>0)
	    {if (random(20)>15)
			{ obj=new(__DIR__"mengu3");   
	          obj->do_copy(ob,maxpot,3);
	          obj->set("title",HIY"蒙古兵"NOR);     
              obj->move(environment(ob));
              obj->kill_ob(ob);
			}
		     else 
			{
	  	      obj=new(__DIR__"mengu3"); 
		      obj->do_copy(ob,maxpot,1);
	          obj->set("title",HIG"蒙古兵"NOR);
	          obj->move(environment(ob));
              obj->kill_ob(ob);
	          obj=new(__DIR__"mengu3");
	           obj->set("title",HIW"蒙古兵"NOR);
		      if (random(20)>5)
			  {obj->do_copy(ob,maxpot,2);
	           obj->set("title",HIW"蒙古兵"NOR);
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
			 tell_room(environment(ob),HIC"蒙古兵挥挥手，示意蒙古护教法王先走。\n蒙古护教法王匆匆忙忙的离开了。\n"NOR);
             tell_object(ob, HIY "\n蒙古护教法王进了全真教了，你任务失败！\n" NOR); 
//                                guo->apply_condition("quanzhenjob",0);
			}
 	     else{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIG"蒙古护教法王"NOR);
				obj->move(environment(ob));
                                obj->set_temp("host",ob->query("id"));
				message_vision(HIY"$N狂笑不已：快点接受大汉的封教,不然全部叫你们死光!!\n"NOR, obj);
				obj->kill_ob(ob);
                                guo->apply_condition("quanzhenjob",0);
				}
		}
	 }
}