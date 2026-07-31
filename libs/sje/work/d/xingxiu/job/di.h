void init(){
        add_action("mark_success", "sign");
        add_action("set_task", "blow");
        add_action("report_task", "report");
}

int set_task(string arg)
{
   object me, where;
   int now_time, wait_time;   
   mapping astuffs = stuffs[random(sizeof(stuffs))];
   string target = targets[query("di_number")][random(sizeof(targets[query("di_number")]))]; 
   mapping *quest = ({   
     ([ "quest":        target,  
        "type" :        1,
        "exp_bonus":    150+random(200),
        "pot" :         50+random(60),
     ]),              
     ([ "quest":        astuffs["quest"],
        "type" :        2,
        "obj_id":       astuffs["obj_id"], 
        "exp_bonus":    astuffs["exp_bonus"], 
        "pot" :         astuffs["pot"],
     ]), 
   });
   mapping aquest = quest[random(sizeof(quest))];
   me = this_player();      
   now_time = me->query_condition("xx_task"); 
   wait_time = me->query_condition("wait_xx_task"); 
   where = environment(me);

   if(!arg) return 0;
   if(arg == "di" || arg == "duandi"){
     if(this_object()->query("xx_user") != getuid(me)) return notify_fail("拿着只别人的笛子吹？。\n");    
     if(!(where)->query("outdoors")) return notify_fail("你在屋里吹笛子，笛声怎么可能传得远呢？。\n");    
     if( me->query_condition("gb_mission"))
             return notify_fail("老仙最讨厌臭叫化子，先扔掉你的丐帮帮务再说！\n");
     if( me->query_condition("dali_songxin"))
          return notify_fail("你送信还没完，就想到这里来混口饭吃？\n");
     if( me->query_condition("mr_job"))
             return notify_fail("你先把该偷学的武功学到再来为老仙服务吧！\n");
     if(now_time) return notify_fail("你现在正在执行任务中。\n");         
     if(wait_time) return notify_fail("上次搞砸了，这次你就等等吧。\n");      

     tell_room(environment(me),HIY + me->name()+"拿起一只"+this_object()->query("name")+HIY"放到口边，轻轻一吹，发出一股尘锐的哨声。本来笛声清扬激越，
但这根玉笛中发出来的声音却十分凄厉，全非乐调。\n"NOR, ({ me }));
     tell_object(me,HIY"你拿起"+this_object()->query("name")+HIY"放到口边，轻轻吹了起来。\n"NOR);
     if((where)->query("outdoors") != "xingxiuhai") return notify_fail("此地和星宿海相离太远，信鸽恐怕听不到笛声。\n"); 
           
     me->set_temp("xx_target", aquest["quest"]);
     me->set_temp("xx_time", random(30)+25);
     me->set_temp("job_type", aquest["type"]);
     me->set_temp("xx_bonus", aquest["exp_bonus"]);
     me->set_temp("xx_pot", aquest["pot"]);
     me->apply_condition("xx_task", me->query_temp("xx_time"));
     if(me->query_temp("job_type") != aquest["type"]) me->set_temp("job_type", aquest["type"]);
     if(me->query_temp("job_type") == 2) me->set_temp("job_id", aquest["obj_id"]);
     me->start_busy(3);             
     call_out("report", 3, me);            
     return 1;
    }     
}
void report(object me)
{        
   message_vision(HIW"\n只见天空中飞下一只白色信鸽，降在$N的肩头。\n\n"NOR, me);
   write("你将书信从白鸽身上解下，瞟了一眼，信中写道：\n
               老仙最近的意思可能是想要");
   if(me->query_temp("job_type") == 1) write("杀掉「"+me->query_temp("xx_target")+"」。\n\n");
   else if(me->query_temp("job_type") == 2) write("得到「"+me->query_temp("xx_target")+"」。\n\n");
   write("目前情况可以通过查看任务(report)来了解。\n");
   return ;       
}
int report_task()
{
   int now_time, time;
   object me;
   me = this_player();
   now_time = me->query_condition("xx_task"); 
   time = me->query_temp("xx_time");
  
   if (!now_time) return notify_fail("你现在还没有接收到任何任务。\n");
   write("你目前的任务目标是：\n\n");
   if(me->query_temp("job_type") == 1) write("       杀掉「"+me->query_temp("xx_target")+"」。\n\n
并在尸体上留下(sign corpse)我们星宿派的标志。\n");
   else if(me->query_temp("job_type") == 2) write("       找到「"+me->query_temp("xx_target")+"」，献(xian)给老仙。\n\n");
   if(now_time > time/4*3) tell_object(me, "你还有充足的时间去完成任务。\n\n");
   if(now_time > time/2 && now_time < time/4*3) tell_object(me, "你的任务时间已经过了四分之一。\n\n");
   if(now_time > time/4 && now_time < time/2) tell_object(me, "你的任务时间已经过了一半。\n\n");
   if(now_time > time/8 && now_time < time/4) tell_object(me, "你只有四分之一的任务时间了。\n\n");
   if(now_time < time/8 && now_time > 0) tell_object(me, "你的任务时间马上就要过了！\n\n");
   return 1;
}
int mark_success(string arg)
{
   object me, target;
   int now_time;
   mapping fam;  
   me = this_player();     
   fam = (mapping)me->query("family");
   if(!arg) return notify_fail("你要干什么？\n");
   target = present(arg, environment(me));
   now_time = me->query_condition("xx_task");
  
   if(!target) return notify_fail("找不到这个东西。\n");
   if(!me->query_temp("xx_target")) return notify_fail("你还是算了吧，现在还没有接收到任何任务。\n");
   if(!now_time) return notify_fail("算了吧，你现在还没有接收到任何任务。\n");
   if(target->query("id") != "corpse") return notify_fail("看清楚点，那不是尸体。\n");
   if(target->query("victim_name") != me->query_temp("xx_target")) return notify_fail("笨蛋，你杀错人了！\n");
   if(target->query("victim_user")) return notify_fail("哦，这人和NPC同明？算他倒霉！\n");
   if(target->query("kill_by") != me) return notify_fail("糟糕！你来晚一步，目标已经被人给杀了。\n");
   if(fam["family_name"] == "星宿派"){
        me->delete_temp("xx_target");
        message_vision(HIR"$N左手一扬，衣袖中飞出一点"BLU"蓝印印"HIR"的火花，嗤嗤做响，射向$n，着体便燃！\n"NOR, me, target);
        target->set("name", HIB"烧焦的尸体"NOR);
        target->set("long", HIB"一具被炼心弹烧焦的尸体，焦臭四溢，情状可怖。\n"NOR);
        me->delete_temp("job_type");
        call_out("done", 1, me);       
        }
   else{
        me->delete_temp("xx_target");
        message_vision("$N哼了一声，用墨笔在$n的衣袖上写下了“星宿”二字。\n", me, target);
        target->set("long", target->query("long")+"上面有人写了大大的"HIB"星宿"NOR"二字。\n");
        me->delete_temp("job_type");
        call_out("done", 1, me);       
        return 1;
        }
}      
void done(object me)
{
   tell_object(me, "好！任务完成，你马上做了一封飞鸽传书送回星宿海。\n");
   if(me->query_temp("xx_task_fail")){
      me->set_temp("xx_bonus", me->query_temp("xx_bonus")/2);
      me->set_temp("xx_pot", me->query_temp("xx_bonus")/2);
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
   me->clear_condition("xx_task");
   return;
}
