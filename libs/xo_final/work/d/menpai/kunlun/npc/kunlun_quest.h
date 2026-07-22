// mapping quest
//   "quest"     : 任务名字
//   "time"      : 时间限制
//   "bonus"     : 奖励点数
//   "quest_msg" : QUEST信息
//   "reward_msg": 奖励信息
//   "fail_msg"  : 失败信息
//   "delay_msg" : 耽误信息
//   "positive_score":正声望
//   "negative_score":负声望

void do_destruct();
mapping *quest_name=({
([
    "quest" : "取清风宝剑",
    "time"  : 1200,
    "bonus" : 20,
    "quest_msg" : "白鹿子叹了口气道：前几日一柄清风宝剑不知道哪儿去了，你帮我查一下。\n",
    "reward_msg": "白鹿子很高兴的对你笑笑，说：好样的！真不愧是昆仑弟子。\n",
    "fail_msg"  : "白鹿子叹了口气，说道：下去呆着吧，真是没用。\n",
    "delay_msg" : "白鹿子很生气，说道：怎么这时候才回来？\n",
]),
([
    "quest" : "取馕",
    "time"  : 900,
    "bonus" : 6,
    "quest_msg" : "白鹿子吩咐你：厨房需要招待几个客人，你下山去买点馕吧，\n",
    "reward_msg": "白鹿子很高兴的对你笑笑：常跑跑腿，也是一种锻炼啊！\n",
    "fail_msg"  : "白鹿子叹了口气，说道：下去呆着吧，真是没有用。\n",
    "delay_msg" : "白鹿子很气愤，怎么这时候才回来？\n",
]),
([
    "quest" : "取百合",
    "time"  : 1000,
    "bonus" : 14,
    "quest_msg" : "白鹿子吩咐你：厨房需要百合，你去哪儿弄一包来。\n",
    "reward_msg": "白鹿子很高兴的对你笑笑：常跑跑腿，也是一种锻炼啊！\n",
    "fail_msg"  : "白鹿子叹了口气，说道：下去呆着吧，真是没有用。\n",
    "delay_msg" : "白鹿子很气愤，怎么这时候才回来？\n",
]),
([
    "quest" : "取"MAG"葡萄"NOR,
    "time"  : 1200,
    "bonus" : 8,
    "quest_msg" : "白鹿子说道：听说山下的葡萄熟了，你弄点葡萄回来。\n",
    "reward_msg": "白鹿子很高兴笑道：这葡萄真不错！！\n",
    "fail_msg"  : "白鹿子叹了口气，说道：下去呆着吧，真是没有用。\n",
    "delay_msg" : "白鹿子很生气地道：怎么这么慢啊？\n",
]),
([
    "quest" : "取貂裘",
    "time"  : 1500,
    "bonus" : 20,
    "quest_msg" : "白鹿子对你点点头说道：昆仑处在寒冷地方，避寒之物不可少啊！\n"
                  "                      你去弄一件貂裘来。\n", 
    "reward_msg": "白鹿子很高兴的对你说：你真能干啊。\n",
    "fail_msg"  : "白鹿子哼哼道：不知道平日都吃饭做什么去了！\n",
    "delay_msg" : "白鹿子很气愤，说道：你怎么这么慢！！！\n",
]),
([
    "quest" : "取指南针",
    "time"  : 1000,
    "bonus" : 6,
    "quest_msg" : "白鹿子对你说道：“沙漠一直是去往中原的一道障碍，听说\n"
                  "  有指南针的话要好一些，你去到哪儿买一个指南针回来！\n",
    "reward_msg": "白鹿子很高兴的对你说：这个指南针，确实是有些奇妙啊！\n",
    "fail_msg"  : "白鹿子安慰你说：我知道你是尽力了。\n",
    "delay_msg" : "白鹿子点了点头，叹了一口气，说道：你下去休息休息吧。\n",
]),
([
    "quest" : "取印度蛇药",
    "time"  : 800,
    "bonus" : 15,
    "quest_msg" : "白鹿子对你说：山里有蛇，但是没有好的蛇药，听说有\n"
                  "一种印度蛇药，疗效不错，你去为大伙买一点来好了。\n",
    "reward_msg": "白鹿子很高兴的对你说：你真能干啊。\n",
    "fail_msg"  : "白鹿子哼哼道：不知道平日都吃饭做什么去了！\n",
    "delay_msg" : "白鹿子很气愤，说道：你怎么这么慢！！！\n",
]),
([
    "quest" : "取梵文书籍",
    "time"  : 1000,
    "bonus" : 8,
    "quest_msg" : "白鹿子对你说：近来常有一些印度人从山下经过，语言不通。\n"
                  "    听书山下有梵文书籍卖，你下山去买本梵文书籍回来吧。\n",
    "reward_msg": "白鹿子很高兴的说：这书连我也看不懂，得仔细研究研究。\n",
    "fail_msg"  : "白鹿子道：连这点小事也做不好了！\n",
    "delay_msg" : "白鹿子很气愤，说道：你太慢了！！！\n",
]),
([
    "quest" : "取马头琴",
    "time"  : 1200,
    "bonus" : 12,
    "quest_msg" : "白鹿子对你说：有个客人很喜欢音乐，我准备送一个好的乐器给他。\n"
                  "              你下山去买一把马头琴回来吧！\n",
    "reward_msg": "白鹿子很高兴的说：这马头琴样子真不错。\n",
    "fail_msg"  : "白鹿子道：连这样的事情都不能完成？！\n",
    "delay_msg" : "白鹿子很气愤，说道：你速度太慢了！！！\n",
]),

([
    "quest" : "取"YEL"丝绸"NOR,
    "time"  : 1000,
    "bonus" : 15,
    "quest_msg" : "白鹿子对你说：小姐要做衣服，需要"YEL"丝绸"NOR"，你去弄一匹来。\n",
    "reward_msg": "白鹿子很高兴的对你说：你办事效率很高嘛！\n",
    "fail_msg"  : "白鹿子哼哼道：不知道平日都吃饭做什么去了！\n",
    "delay_msg" : "白鹿子很气愤，说道：怎么搞的？！！！\n",
]),
});

string *refuse_msg=({
    "白鹿子对$N笑道：你还是下去先多练练功夫再说。\n",
    "白鹿子想了想，对$N说道：现在没有什么事情想让你做的。\n",
    "白鹿子沉吟半晌，对$N抱歉的说道：你先下去休息休息再说吧。\n",
});

int time_period(int timep, object me)
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

    tell_object(me,HIW "你有" + time + "的时间\n去完成你师傅给的任务。\n"NOR);
    return 1;
}

mapping query_quest()
{
    return quest_name[random(sizeof(quest_name))];
}

int accept_object(object who, object ob)
{
//    string test;
	mapping quest;
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,this_object()->name()+"笑道：“你给我东西干什么？”\n");
	return 0;
	}
        if( "取"+ob->name(1) != quest["quest"] || ob->is_character())
        {
        tell_object(who,this_object()->name()+"皱眉说：“我当初可不是让你去找这个呀！”\n");
        return 0;
        }
        if ( who->query("quest/task_time") && (int) who->query("quest/task_time") < time() )
        {
        tell_object(who,quest["delay_msg"]);
        who->delete("quest");
        kl_mark("add",who,"kunlun_task/level",-1,1);
        call_out("do_destruct",1,this_object());
        return 1;
        }
        else
        {
                    tell_object(who,quest["reward_msg"]);
                    who->add("class_score/昆仑派",quest["bonus"]);
                    printf(HIR"->师门忠诚度升高 %s 点\n"NOR
                        ,chinese_number(quest["bonus"]) );
                    if( quest["positive_score"])
                    {
                        who->add("positive_score",quest["positive_score"]);
                        printf(HIG"->正评价升高 %s 点\n"NOR
                        , chinese_number(quest["positive_score"]) );
                    }
                    if( quest["negative_score"])
                    {
                        who->add("negative_score",quest["negative_score"]);
                        printf(HIC"->负评价升高 %s 点\n"NOR
                        ,chinese_number(quest["negative_score"]) );
                    }
                    who->delete("quest");
                    kl_mark("add",who,"canyue/level4",2,1);
                    call_out("do_destruct",1,this_object());
                    return -1;
        }
}

int give_quest()
{
    mapping quest ;
    object me = this_player(); // ob = this_object();
    int class_score, timep;

    if ( quest = me->query("quest") )
    {
         if( me->query("quest/status") == quest["quest"] )
         {
                tell_object(me,quest["reward_msg"]);
                me->add("class_score/昆仑派",quest["bonus"]);
                printf(HIR"->师门忠诚度升高 %s 点\n"NOR
                    ,chinese_number(quest["bonus"]) );
                if( quest["positive_score"])
                {
                    me->add("positive_score",quest["positive_score"]);
                    printf(HIG"->正评价升高 %s 点\n"NOR
                    , chinese_number(quest["positive_score"]) );
                }
                if( quest["negative_score"])
                {
                    me->add("negative_score",quest["negative_score"]);
                    printf(HIC"->负评价升高 %s 点\n"NOR
                    ,chinese_number(quest["negative_score"]) );
                }
                me->delete("quest/status");
                me->delete("quest");
                kl_mark("add",me,"canyue/level4",2,1);
                return 1;
          }

          else 
          {
            if( ((int) me->query("quest/task_time")) >  time() && quest["time"])
                  return 0;
              else
              {
	      tell_object(me,quest["fail_msg"]);
                  me->add("class_score/昆仑派",-quest["bonus"]/3);
                  if(quest["bonus"]/3)
                  printf(HIY"->师门忠诚度下降 %s 点\n"NOR
                    ,chinese_number(quest["bonus"]/3) ); 
	      me->delete("quest");
                  kl_mark("add",me,"kunlun_task/level",-1,1);
                  return 1;
              }
           }
     }

     if((int)me->query("quest/task_time")&&
            (int)me->query("quest/task_time") > time()) 
     {                     
            message_vision(refuse_msg[random(sizeof(refuse_msg))],me);
            return 1;
     }
    class_score = (int)me->query("class_score/昆仑派");
    quest = query_quest();
    tell_object(me,quest["quest_msg"]);
   	me->set("quest", quest);
    me->delete("quest/task_time");
    if( timep = quest["time"] )
    {
        time_period( timep, me);
        me->set("quest/task_time", (int) time()+(int) quest["time"]);
    }
    return 1;
}

void do_destruct()
{
    object *obj=all_inventory(this_object());    
    int i;
    for(i=0;i<sizeof(obj);i++){
      if(obj[i]->query("name")!="长剑"&&obj[i]->query("name")!="紫绸长衫")
         destruct(obj[i]);
      }
    return;
}
