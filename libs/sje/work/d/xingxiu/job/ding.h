string ask_job()
{
       object me, ob;
       mapping fam;
       int shen, exp, j;
       me = this_player();
       fam = (mapping)me->query("family");
       shen = me->query("shen");
       exp=me->query("combat_exp",1); 
 
       if (!fam || fam["family_name"] != "星宿派") 
         return "看你对老仙态度恭敬，何不加入我星宿派呢？";
       if( exp < 100000) 
         return "哈哈哈，你再加把力练功，很快就可以为老仙我分忧了。";
       if (exp > 1000000)
         return "老仙我现在可没什么东西感兴趣了。";
       if(shen>0)
         return "哼！你是来卧底的吧？";
           if(exp>200000)
           if(-(shen) < exp/2) 
         return "徒儿，看来你的心肠还不够黑啊，有些事你不问也罢。";
       if(interactive(me) && me->query_temp("xx_job")) 
         return "你说要替老仙分忧，怎么还在这里发呆？";
       if(interactive(me) && me->query_condition("wait_xx_task")) 
         return "老仙现在心情还好，不用你来为我分忧。";

//     if(exp>=1250000) j=10;
//     else if(exp>=1000000) j=8;
       if(exp >=750000) j=6;
       else if(exp>=500000) j=4;
       else if(exp>=250000) j=2;
       else j=0;
       ob = new("/d/xingxiu/job/di_" + j);
       ob->move(me);
       ob->set("xx_user", getuid(me));
       me->set_temp("xx_job", 1);
       message_vision("$N拿出一只玉制短笛，交给$n。\n\n", this_object(), me);
       return "老仙我最近心情不佳，徒儿你要多多为我分忧才是！\n";    
}

int do_xian(string arg)
{
    object who, me, ob;
    who = this_player();
    me = this_object();

    if(!arg) return notify_fail("你要献给老仙什么东西？\n");
    if(!objectp(ob = present(arg, who))) return notify_fail("你身上没有这样东西。\n");
    if(!who->query_temp("xx_job")) return notify_fail("连老仙现在的心情还没摸清楚就乱献东西？\n"); 
    if(!who->query_temp("job_type")) return notify_fail("老仙还没让你去找新的东西来献呢！\n");
           
    message_vision(HIY"\n$n毕恭毕敬地将"+ob->query("name")+HIY"拿出，双手捧上，想要献给$N。\n\n"NOR, me, who);
    ob->move(me);    
    if(who->query_temp("job_type") != 2){
         command("say 你拿个"+ob->query("name")+"给我干嘛？");
         message_vision("说完$N随手一扔，将"+ob->query("name")+"扔了出去。\n\n", me);
         remove_call_out("throw");
         call_out("throw",0,ob);
         return notify_fail("老仙不要你献上的东西。\n");
         }
    if(userp(ob)){
         command("stare " + who->query("id"));
         command("say 竟敢用假货来欺骗本老仙，给我滚出去！");
         message_vision("\n说完$N长袖一挥，一股内劲拂出，就将$n扫出洞外！\n\n", me, who);
         remove_call_out("kicking");
         call_out("kicking",0,who);
         return notify_fail("糟糕，穿邦了！\n");
         }
    if(ob->query("name") != who->query_temp("xx_target")){
      if(ob->query("id") != who->query_temp("job_id")) {
         command("hmm " + who->query("id"));
         command("say 你拿个"+ob->query("name")+"给老仙我有什么用？");
         message_vision("说完$N随手一扔，将"+ob->query("name")+"扔了出去。\n\n", me);
         remove_call_out("throw");
         call_out("throw",0,ob);
         return notify_fail("好象是你献错东西了。\n");
         }
      else{
         who->delete_temp("job_type");
         call_out("destroying", 1, ob, me);
         call_out("done", 3, who);       
         return 1;
         }
         }
        who->delete_temp("job_type");
        call_out("destroying", 1, ob, me);
        call_out("done", 3, who);       
        return 1;
}

void throw(object ob)
{
      if (!ob) return;
       ob->move("/d/xingxiu/ryd1");
       message("vision","只听“呼”地一声，从日月洞里直飞了出来一"+ob->query("unit")+ob->query("name")+"掉在地上。\n", environment(ob), ob);
}

void kicking(object who)
{
      if(!who || environment(who) != environment())  return;
       who->move("/d/xingxiu/ryd1");
       message("vision","只听“呼”地一声，紧接着"+who->query("name")+"从日月洞里直飞了出来，摔了个四脚朝天！\n", environment(who), who);
       who->receive_wound("jing", 200);
       who->receive_wound("qi", 250);
       who->add("neili", -600);
       who->add("jingli", -500);
       who->start_busy(5);
}

void done(object me)
{
        int hgdf, poison;
      mapping fam;
      hgdf = me->query_skill("huagong-dafa",1);
      poison = me->query_skill("poison",1);
      fam = (mapping)me->query("family");

      if(!me) return;
       command("pat " + me->query("id"));       
       command("say 不错不错，既然你找到了老仙我想要的东西，我就指点指点你吧。");
      if(fam["family_name"] == "星宿派") {
      if(hgdf < 180) me->improve_skill("huagong-dafa", me->query("xx_points")*random(3));
      if(poison < 180) me->improve_skill("poison", me->query("xx_points")*random(3));
       me->add("xx_points", 1);
       me->set_temp("xx_bonus", me->query_temp("xx_bonus")+((hgdf+poison)/10));
       me->set_temp("xx_pot", me->query_temp("xx_pot")+((hgdf+poison)/20));
       call_out("ok", 0, me);
       return;             
       }
      call_out("ok", 0, me);                    
}       

void destroying(object obj, object me)
{
        message_vision("$N拿起$n仔细地端详了一会儿，满意地点了点头，脸上露出了笑容。\n", me, obj);
        destruct(obj);
}

void ok(object me)
{
       tell_object(me, "你听了老仙的指点，功夫进步了不少！\n"); 
       if(me->query_temp("xx_task_fail")){
         me->set_temp("xx_bonus", me->query_temp("xx_bonus")/4);
         me->set_temp("xx_pot", me->query_temp("xx_bonus")/4);
         me->delete_temp("xx_task_fail");
         }
         me->add("combat_exp", me->query_temp("xx_bonus"));
         me->add("potential", me->query_temp("xx_pot"));
       if(me->query("potential") > me->query("max_pot")) 
         me->set("potential", me->query("max_pot"));
         me->add("shen", -(me->query_temp("xx_bonud")*10));
         me->delete_temp("xx_bonus");
         me->delete_temp("xx_time");
         me->delete_temp("xx_pot");
         me->delete_temp("job_id");
         me->clear_condition("xx_task");
         me->delete_temp("xx_target");        
         return;
}

