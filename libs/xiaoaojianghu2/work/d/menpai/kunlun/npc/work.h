// mapping kunlun_task    //记录任务的东东。
//             level      //任务等级
//             point      //忠诚点数
//             time       //给出时间限制。
//             success    //成功次数记录，成功＋1，失败-1。
//                          一个地方到2或-2就完成任务或失败。
//             where      //工作地点
//             done       //是否完成任务。1完成,其它则没有完成



string time_period(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return (time);
}

string give_work(string address,string who)
{
    object me = this_player();
    string words="";
    mapping givework;
//非本门弟子没有活干的。
    if( !kl_dizi(me) ) {
      message_vision( who+"奇怪地笑道：这位"+RANK_D->query_respect(me)+"想要做什么？”\n",me );
      words="这里好象没有什么事情要让你做的了。";
      return (words);
      }
//是否是本地干活的弟子。
    if( kl_mark("query",me,"kunlun_task/where",1,1)!=address ) {
      words="恩，你真勤快，但是现在这里还不用你来帮忙。";
      return (words);
      }
//成功点数是否为2或-2
    if( kl_mark("query",me,"kunlun_task/success",1,1)>=2|| 
        kl_mark("query",me,"kunlun_task/success",1,1)<=-2 ) {
      words="好了，就这样，你先回去向掌门人复命吧。";
      return (words);
      }
//查看是否有事情。如果有则进行检查如下：
    if( kl_mark("query",me,"kunlun_work",1,1) ) { //已经分配了事情。
      if( kl_mark("query",me,"kunlun_task/time",1,1)<time() ){ //超出时间限制
            kl_mark("add",me,"kunlun_task/success",-1,1);
            kl_mark("add",me,"kunlun_task/point",
            0-kl_mark("query",me,"kunlun_work/fail_p",1,1),1);
         if(kl_mark("query",me,"kunlun_task/done",1,1)==1){
            message_vision(kl_mark("query",me,"kunlun_work/delay_msg",1,1),me);
            kl_mark("delete",me,"kunlun_task/done",1,1);
            }
         else message_vision(kl_mark("query",me,"kunlun_work/fail_msg",1,1),me);
       kl_mark("delete",me,"kunlun_work",1,1);
       kl_mark("delete",me,"kunlun_task/time",1,1);
       words=(string)me->query("name")+"真是没用！";
       return(words);
       }

      else { //时间没有到
         if(kl_mark("query",me,"kunlun_task/done",1,1)){ //已经干完了。
            kl_mark("add",me,"kunlun_task/success",1,1);
            kl_mark("add",me,"kunlun_task/point",
                kl_mark("query",me,"kunlun_work/success_p",1,1),1 );
            message_vision(kl_mark("query",me,"kunlun_work/success_msg",1,1),me);
            if(kl_mark("query",me,"kunlun_work/positive_score",1,1)>0)
              write(HIR"正评价"NOR"升高"+chinese_number(
                 kl_mark("query",me,"kunlun_work/positive_score",1,1))+"点。\n");
            if(kl_mark("query",me,"kunlun_work/negative_score",1,1)>0)
              write(HIR"负评价"NOR"升高"+chinese_number(
                 kl_mark("query",me,"kunlun_work/negative_score",1,1))+"点。\n");
            kl_mark("delete",me,"kunlun_work",1,1);
            kl_mark("delete",me,"kunlun_task/done",1,1);
            kl_mark("delete",me,"kunlun_task/time",1,1);
            words=(string)me->query("name")+"真有你的！";
            return (words);
           }
          //还没有干完。
         write("你现在应该去“"+kl_mark("query",me,"kunlun_work/name",1,1)+"”。\n");
         write(sprintf("你现在还有%s时间去干活。\n",
                time_period(kl_mark("query",me,"kunlun_task/time",1,1)-time())) );
         words=(string)me->query("name")+"好好干啊！";
         return (words);
         }
      }
//没有在干活，分配事情如下：
    givework=query_work(kl_mark("query",me,"kunlun_task/level",1,1));
    kl_mark("set",me,"kunlun_work",givework,1 );
    kl_mark("set",me,"kunlun_task/time",time()+givework["time"],1 );
    message_vision(givework["give_msg"],me);
    words=(string)me->query("name")+"抓紧干吧！";
    return (words);
}



int accept_object(object me, object ob)
{
    if(!kl_dizi(me)){
        command("? "+me->query("id"));
        say("这个？我可是不敢当了。");
        return 0;
        }
//是否本地的弟子。
    if( kl_mark("query",me,"kunlun_task/where",1,1)!=environment(me)->query("short") ) {
        command("grin");
        command("say 给我东西？真是不敢当。");
        return 0;
      }
    if( kl_mark("query",me,"kunlun_work",1,1) ) { 
        //已经分配了事情。
        if(kl_mark("query",me,"kunlun_work/object_name",1,1) ) { 
          //如果是找物品的任务。
          if(ob->query("name")!=kl_mark("query",me,"kunlun_work/object_name",1,1) ){
              //所给东西不是需要的东西
              command("shake "+me->query("id"));
              command("say 我可没有要你去找这个东西呢。");
              return 0;
              }
          else{ 
             //所给东西符合
             if( kl_mark("query",me,"kunlun_task/time",1,1)<time() ){ 
                 //超出时间限制
                 kl_mark("add",me,"kunlun_task/success",-1,1 );
                 kl_mark("add",me,"kunlun_task/point",
                     0-kl_mark("query",me,"kunlun_work/fail_p",1,1),1 );
                 message_vision(kl_mark("query",me,"kunlun_work/delay_msg",1,1),me);
                 kl_mark("delete",me,"kunlun_work",1,1);
                 kl_mark("delete",me,"kunlun_task/time",1,1);
                 call_out("nothing",2,ob);
//                 destruct(ob);
                 return 1;
               }
             else{ 
                 //没有超时。
                 kl_mark("add",me,"kunlun_task/success",1,1);
                 kl_mark("add",me,"kunlun_task/point",
                        kl_mark("query",me,"kunlun_work/success_p",1,1),1 );
                 message_vision(kl_mark("query",me,"kunlun_work/success_msg",1,1),me);
                 if(kl_mark("query",me,"kunlun_work/positive_score",1,1)>0)
                   write(HIR"正评价"NOR"升高"+chinese_number(
                     kl_mark("query",me,"kunlun_work/positive_score",1,1))+"点。\n");
                 if(kl_mark("query",me,"kunlun_work/negative_score",1,1)>0)
                   write(HIR"负评价"NOR"升高"+chinese_number(
                     kl_mark("query",me,"kunlun_work/negative_score",1,1))+"点。\n");
                 kl_mark("delete",me,"kunlun_work",1,1);
                 kl_mark("delete",me,"kunlun_task/done",1,1);
                 kl_mark("delete",me,"kunlun_task/time",1,1);
                 call_out("nothing",2,ob);
//                 destruct(ob);
                 return 1;
               }
             }    
        }
    }
    return 0;
}

int nothing(object ob)
{
    return( destruct(ob) );
}
