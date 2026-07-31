
// ben1.h for job
// xueer


string ask_sao()
{
         object me = this_player();
         object ob,ob1;
         mapping fam;
         int m,n,i,j;        

         if (!(fam = this_player()->query("family")) || fam["family_name"] != "大理段家")
         return RANK_D->query_respect(this_player()) +
                "与本寺毫无瓜葛，何谈工作？";
        if (me->query_temp("marks/sao") == 0)  
           {   
            m = 1+random(5);
            me->set_temp("marks/sao",m); 
            me->set_temp("marks/数量",m);       
            me->set_temp("marks/工具",1);    
            ob=new("/d/tianlongsi/obj/saozhou");
            ob->move(me);

            for(i=0;i<m;i++)
              {
               n = random(5);
               if (n==0) 
                   ob1=new("/d/tianlongsi/laji/shuye");
               if (n==1)   
                   ob1=new("/d/tianlongsi/laji/feizhi");
               if (n==2)   
                   ob1=new("/d/tianlongsi/laji/poyi");
               if (n==3)   
                   ob1=new("/d/tianlongsi/laji/pojian");
               if (n==4)   
                   ob1=new("/d/tianlongsi/laji/xshizi");
               if (n==5)   
                   ob1=new("/d/tianlongsi/laji/xmuban");

               j = random(20);
               if (j==0)
                 ob1->move("/d/tianlongsi/damen");
               if (j==1)
                 ob1->move("/d/tianlongsi/talin");
               if (j==2)
                 ob1->move("/d/tianlongsi/ta3");
               if (j==3)
                 ob1->move("/d/tianlongsi/ta2");
               if (j==4)
                 ob1->move("/d/tianlongsi/ta1");
               if (j==5)
                 ob1->move("/d/tianlongsi/wujingge");
               if (j==6)
                 ob1->move("/d/tianlongsi/wuwoge");
               if (j==7)
                 ob1->move("/d/tianlongsi/baodian");
               if (j==8)
                 ob1->move("/d/tianlongsi/xianghemen");
               if (j==9)
                 ob1->move("/d/tianlongsi/wulege");
               if (j==10)
                 ob1->move("/d/tianlongsi/huangtianmen");
               if (j==11)
                 ob1->move("/d/tianlongsi/wuchangge");
               if (j==12)
                 ob1->move("/d/tianlongsi/ruihemen");
               if (j==13)
                 ob1->move("/d/tianlongsi/yaotai");
               if (j==14)
                 ob1->move("/d/tianlongsi/wuwujing");
               if (j==15)
                 ob1->move("/d/tianlongsi/cibeiyuan");
               if (j==16)
                 ob1->move("/d/tianlongsi/sanwugong");
               if (j==17)
                 ob1->move("/d/tianlongsi/doushuai");
               if (j==18)
                 ob1->move("/d/tianlongsi/doumugong");
               if (j==19)
                 ob1->move("/d/tianlongsi/yuhuayuan");
               if (j==20)
                 ob1->move("/d/tianlongsi/banruotai");
              }

            return RANK_D->query_respect(this_player()) +
                "你既然有这个诚意,那么寺内有"+ chinese_number(m) +"处杂物就麻烦你清理了。";
           }             

         else return RANK_D->query_respect(this_player()) +
                   "你的工作都没有完成怎么有来了。";
               
}

string ask_over()
{
        object me=this_player();
        object who;
        int combat_exp,potential,exp,pot,exp1,pot1,m1;

        if (me->query_temp("marks/工具") == 0)  
        if (me->query_temp("marks/sao") == 0) 
        if (me->query_temp("marks/over")==1) 
           {
                exp = (int)me->query("combat_exp");
                pot = (int)me->query("potential");

                me->set_temp("marks/over",0);
                m1 = me->query_temp("marks/数量");
                me->set_temp("marks/数量",0);

                this_player()->add("combat_exp", 50+random(25)+25*m1);
                this_player()->add("potential", 10+random(10)+10*m1);
                this_player()->receive_damage("jing",random(10));
                this_player()->receive_damage("qi",random(10));
                exp1 = (int)me->query("combat_exp");
                pot1 = (int)me->query("potential");

                combat_exp = exp1 - exp;
                potential = pot1 - pot;
                tell_object(me,"本因对你说：好，这是给你的奖励。\n");
                tell_object(me,HIR"终于把任务完成了。\n"NOR);
                tell_object(me,HIW"你被奖励了：" +
                chinese_number(combat_exp) + "点实战经验，"+
                chinese_number(potential) + "点潜能。\n" NOR);
                return("谢谢你的帮助! \n");

           }
           else return("你的任务都没有完成怎么就回来了。\n");
           else return("你的任务都没有完成怎么就回来了。\n");
           else return("你的扫帚都没有还给我怎么算完成任务。\n");

}


int accept_object(object who, object ob)
{	
        object me;
	me=this_player();
        if (me->query_temp("marks/sao") == 0) 
        if (me->query_temp("marks/工具") == 1)
        if ((string)ob->query("id")=="sao zhou") 
           {
               me->set_temp("marks/工具",0);
               me->set_temp("marks/over",1);
               this_player()->set_temp("wang/鱼",0);
               message_vision("本因对你说：好，如果你打扫完了就(ask yin about over)吧。\n",who);
               call_out("destroy", 1, ob);
	       return 1;
           }
         else message_vision("你交的东西我不需要。\n",who);
         else message_vision("你的工具都交了, 怎么又来交工具。\n",who);
         else message_vision("你的地都没有打扫完,怎么就来交工具。\n",who);


        if (  (string)ob->query("id") == "jin he")
	{
		message_vision("本因大喜道：“多谢施主！施主若是有缘人，请到牟尼堂取本寺之宝。\n", who);
		who->set_temp("marks/find_temp",1);
		who->move("/d/tianlongsi/banruotai");
		return 1;
	}
	return 0;
}

