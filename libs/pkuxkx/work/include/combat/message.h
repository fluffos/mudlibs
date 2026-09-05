//combatd.c里面的公共战斗信息显示设定

string *guard_msg = ({
  CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
  CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
  CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
  CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
  CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
  HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
  HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
  HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
  HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
  HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
  HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
  HIW "$N喝道：「$n，看招！」\n" NOR,
});

string *winner_msg = ({
  CYN "\n$N哈哈大笑，说道：「承让了！」\n\n" NOR,
  CYN "\n$N双手一拱，笑著说道：「承让！」\n\n" NOR,
  CYN "\n$n向后一纵，说道：「阁下武艺果然高明，这场算是在下输了！」\n\n" NOR,
  CYN "\n$N胜了这招，向后跃开三尺，笑道：「承让！」\n\n" NOR,
  CYN "\n$N双手一拱，笑着说道：「知道我的利害了吧！」\n\n" NOR,
  CYN "\n$n向后退了几步，说道：「这场比试算我输了，下回看我怎么收拾你！」\n\n" NOR,
  CYN "\n$n向后一纵，恨恨地说道：「君子报仇，十年不晚！」\n\n" NOR,
  CYN "\n$n脸色一寒，说道：「算了算了，就当是我让你吧！」\n\n" NOR,
  CYN "\n$n纵声长笑道：「算你走运！」一面身子向后跳开。\n\n" NOR,
  CYN "\n$n脸色微变，说道：「佩服，佩服！」\n\n" NOR,
  CYN "\n$n向后退了几步，说道：「这场比试算我输了，佩服，佩服！」\n\n" NOR,
  CYN "\n$n向后一纵，躬身做揖说道：「阁下武艺不凡，果然高明！」\n\n" NOR,
});

string *diamond_effect_msg = ({
  HIW "$n的「护体真气」发挥了作用，抵挡住了$N的部分攻击！\n" NOR,
  HIW "只见白光闪过，$N的攻击力似乎有所减弱。\n" NOR,
  HIW "$N的攻击落在$n身上显得软弱无力，无甚威胁！\n" NOR,
});

//造成伤害的信息
string damage_msg(int damage, string type)
{
  string str;
  
  if( damage == 0 ) return "结果没有造成任何伤害。\n";
  
  switch( type )
  {
    case "擦伤":
    case "割伤":
      if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
      else if( damage < 20 ) return "结果在$p$l划出一道细长的血痕。\n";
      else if( damage < 40 ) return "结果「嗤」地一声划出一道伤口！\n";
      else if( damage < 80 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
      else if( damage < 160 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
      else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
      break;
    case "刺伤":
      if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
      else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
      else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
      else if( damage < 80 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
      else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉□糊的血窟窿！\n";
      else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
      break;
    case "瘀伤":
      if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
      else if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
      else if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
      else if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
      else if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
      else if( damage < 160 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
      else if( damage < 240 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
      else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
      break;
    case "砸伤":
      if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
      if( damage < 60 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
      if( damage < 120 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
      if( damage < 240 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
      if( damage < 380 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
      return "只见$w重重地撞击在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
      break;
      
    case "内伤":
      if( damage < 10 ) return "只是把$n打得退了半步，毫发无损。\n";
      else if( damage < 20 ) return "$n痛哼一声，在$p的$l造成一处瘀伤。\n";
      else if( damage < 30 ) return "一击命中，把$n打得痛得弯下腰去！\n";
      else if( damage < 40 ) return "$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
      else if( damage < 60 ) return "$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
      else if( damage < 70 ) return "重重地击中，$n「哇」地一声吐出一口鲜血！\n";
      else if( damage < 80 ) return "「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
      else return "只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
      break;
    case "点穴"://增加点穴伤害pal
      if( damage < 10 ) return "结果只是轻轻的碰到$n的$l根本没有点到穴道。\n";
      else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处淤青。\n";
      else if( damage < 40 ) return "结果一击命中，$w点中了$n$l上的穴道,$n只觉一阵麻木！\n";
      else if( damage < 80 ) return "结果$n闷哼了一声，脸上一阵青一阵白，登时$l麻木！\n";
      else if( damage < 160 ) return "结果$n脸色一下变得惨白，$w点中$n$l的穴道,一阵疼痛遍布整个$l！\n";
      else if( damage < 240 ) return "结果$n一声大叫,$l的穴道被点中,疼痛直入心肺！\n";
      else return "结果只听见$n一声惨叫,一阵剧痛夹杂着麻痒游遍全身,跟着直挺挺的倒了下去.\n";
      break;
    case "抓伤":
      if( damage < 10 ) return "结果只是轻轻地抓到，比抓痒稍微重了点。\n";
      else if( damage < 20 ) return "结果在$p的$l抓出几条血痕。\n";
      else if( damage < 40 ) return "结果一抓命中，$n的$l被抓得鲜血飞溅！\n";
      else if( damage < 80 ) return "结果「嗤」地一声，$l被抓得深可见骨！！\n";
      else if( damage < 120 ) return "结果一抓命中，$n的$l被抓得血肉横飞！！！\n";
      else if( damage < 160 ) return "结果这一下「嗤」地一声抓得$n连晃好几下，差一点摔倒！\n";
      else if( damage < 240 ) return "结果$n哀号一声，$l被抓得筋断骨折！！\n";
      else return "结果只听见$n一声惨嚎，$l被抓出五个血窟窿！鲜血溅得满地！！\n";
      break;
    case "摔伤":
    case "撞伤":
      if( damage < 20 ) return "结果$n脚下不稳，在地上擦破了点儿皮。\n";
      if( damage < 80 ) return "结果「啪」地一声，$n在地上摔了个屁礅。\n";
      if( damage < 160 ) return "结果$n一不小心，被$N重重摔倒在地！\n";
      if( damage < 320 ) return "结果$n被一下摔倒在地，「噗」地一声喷出了一大口鲜血！\n";
      if( damage < 500 ) return "结果被$N这一下摔在地上，骨头「卡嚓」一声断了！\n";
      return "结果只听见$n一声惨嚎，被$N摔得血肉横飞，惨不忍睹！！\n";
    case "反弹伤":
      if( damage < 5 ) return "$N受到$n奋力反震，闷哼一声。\n";
      else if( damage < 10 ) return "$N被$n的胸膛震得气血翻腾，大惊失色。\n";
      else if( damage < 20 ) return "$N被$n的小腹震得站立不稳，摇摇晃晃。\n";
      else if( damage < 40 ) return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
      else if( damage < 80 ) return "$N被$n的小腹反弹回来的力量震得半身发麻。\n";
      else if( damage < 120 ) return "$N被$n的反弹力一震，胸口有如受到一记重击，连退了五六步！\n";
      else if( damage < 160 ) return "$N被$n的内力劲风一震，眼前一黑，身子向後飞出丈许！！\n";
      else return "$N被$n的内力劲风一震，眼前一黑，狂吐鲜血，身子象断了线的风筝向後飞去！！\n";
      break;
    default:
      if( !type ) type = "伤害";
      if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
      else if( damage < 20 ) str = "结果造成轻微的";
      else if( damage < 30 ) str = "结果造成一处";
      else if( damage < 50 ) str = "结果造成一处严重";
      else if( damage < 80 ) str = "结果造成颇为严重的";
      else if( damage < 120 ) str = "结果造成相当严重的";
      else if( damage < 170 ) str = "结果造成十分严重的";
      else if( damage < 230 ) str = "结果造成极其严重的";
      else str =  "结果造成非常可怕的严重";
      return str + type + "！\n";
  }
}

//关于受伤的信息
string eff_status_msg(int ratio)
{
  if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
  if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
  if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
  if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
  if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
  if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
  if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
  if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
  if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
  if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
  return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

//关于气血的信息
string status_msg(int ratio)
{
  if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
  if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
  if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
  if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
  if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
  if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
  if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
  if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
  if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
  return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

  //报告状态的函数，由effective控制消息发给谁
varargs void report_status(object ob,int nouse)
{
    int qipct, efqipct, jingpct, efjingpct;
    int qiratio, jingratio, ratio;
    string msg1, msg2, msg3;

    if (!ob->query_temp("combat/qi_damage") && !ob->query_temp("combat/qi_wound") && 
        !ob->query_temp("combat/jing_damage") && !ob->query_temp("combat/jing_wound"))
        return;

    if ( ob->query("eff_qi")<=0 )
        qipct=0;
    else
        qipct=(int)ob->query("qi")*100/(int)ob->query("eff_qi");
    if ( ob->query("max_qi")<=0 )
        efqipct = 0;
    else
        efqipct = (int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi"); 

    if ( ob->query("eff_jing")<=0 )
        jingpct = 0;
    else
        jingpct=(int)ob->query("jing")*100/(int)ob->query("eff_jing");
    if ( ob->query("max_jing")<=0 )
        efjingpct = 0;
    else
        efjingpct = (int)ob->query("eff_jing") * 100 / (int)ob->query("max_jing"); 

    qiratio = (qipct<efqipct)?qipct:efqipct;
    jingratio = (jingpct<efjingpct)?jingpct:efjingpct;
    ratio = (qiratio<jingratio)?qiratio:jingratio;

    if(ob->query("newbie_village/done") || ob->query("xuetang") || ob->query("combat_exp") >= 2000)
    {
        if( (ob->query_temp("combat/jing_damage")||ob->query_temp("combat/jing_wound"))
           &&(ob->query_temp("combat/qi_damage")||ob->query_temp("combat/qi_wound")) )
        {
            msg1 = ((ob->query_temp("combat/qi_damage")||ob->query_temp("combat/jing_damage"))?"damage:+"+ob->query_temp("combat/qi_damage")+"/+"+ob->query_temp("combat/jing_damage"):"");
            msg2 = ((ob->query_temp("combat/qi_wound")||ob->query_temp("combat/jing_wound"))?" wound:+"+ob->query_temp("combat/qi_wound")+"/+"+ob->query_temp("combat/jing_wound"):"");
            msg3 = " 气血:"+qipct+"%/"+efqipct+"% 精神:"+jingpct+"%/"+efjingpct+"%)"NOR"』\n";
        }
        else if( (!ob->query_temp("combat/jing_damage")&&!ob->query_temp("combat/jing_wound"))
                && (ob->query_temp("combat/qi_damage")||ob->query_temp("combat/qi_wound")) )
        {
            msg1 = ((ob->query_temp("combat/qi_damage"))?"damage:+"+ob->query_temp("combat/qi_damage"):"");
            msg2 = ((ob->query_temp("combat/qi_wound"))?" wound:+"+ob->query_temp("combat/qi_wound"):"");
            msg3 = " 气血:"+qipct+"%/"+efqipct+"%)"NOR"』\n";
        }
        else if( (!ob->query_temp("combat/qi_damage")&&!ob->query_temp("combat/qi_wound"))
                && (ob->query_temp("combat/jing_damage")||ob->query_temp("combat/jing_wound")) )
        {
            msg1 = ((ob->query_temp("combat/jing_damage"))?"damage:+"+ob->query_temp("combat/jing_damage"):"");
            msg2 = ((ob->query_temp("combat/jing_wound"))?" wound:+"+ob->query_temp("combat/jing_wound"):"");
            msg3 = " 精神:"+jingpct+"%/"+efjingpct+"%)"NOR"』\n";
        }

        if (ratio==efqipct || ratio==efjingpct)
        {
            combat_msg( "( $N" + eff_status_msg(ratio) + " )『"+ob->name()+YEL"(" + msg1 + msg2 + msg3, 3, ob);
        }
        else
        {
            combat_msg( "( $N" + status_msg(ratio) + " )『"+ob->name()+YEL"(" + msg1 + msg2 + msg3, 3, ob);
        }
    }
    else
    {    
        if (ratio==efqipct || ratio==efjingpct)
        {
            combat_msg( "( $N" + eff_status_msg(ratio)+ " )\n", 3, ob);
        }
        else
        {
            combat_msg( "( $N" + status_msg(ratio)+ " )\n", 3, ob);
        }
    }
    ob->delete_temp("combat/damage_from");
    ob->delete_temp("combat/qi_damage");
    ob->delete_temp("combat/jing_damage");
    ob->delete_temp("combat/qi_wound");
    ob->delete_temp("combat/jing_wound");
}
  
  // This function is to announce the special events of the combat.
  // This should be moved to another daemon in the future.
  void announce(object ob, string event)
  {
    switch(event) {
    case "dead":
      message_vision("\n$N死了。\n\n", ob);
      break;
    case "unconcious":
      message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
      break;
    case "revive":
      message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
      break;
    }
  }