string *guard_msg = ({
  CYN "$N注视着$n的行动，企图寻找机会出手。\n" NOR,
  CYN "$N正盯着$n的一举一动，随时准备发动攻势。\n" NOR,
  CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
  CYN "$N目不转睛地盯着$n的动作，寻找进攻的最佳时机。\n" NOR,
  CYN "$N慢慢地移动着脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
  HIW "$N和$n仇人相见份外眼红，立刻打了起来！\n" NOR,
  HIW "$N对着$n大喝：「可恶，又是你！」\n" NOR,
  HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
  HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
  HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
  HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
  HIW "$N喝道：「$n，看招！」\n" NOR, });

string *winner_msg = ({
  CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
  CYN "\n$N双手一拱，笑着说道：承让！\n\n" NOR,
  CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
  CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
  CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
  CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});
string damage_msg(int damage, string type) {
  string str;

  //      return "造成 " + damage + " 点" + type + "。\n";

  if (damage <= 0) return "结果对$n没有造成任何伤害。\n";

  switch (type) {
    case "擦伤":
    case "抓伤":
    case "割伤":
      if (damage < 10) return "结果只是轻轻地划破$p的皮肉。\n";
      else if (damage < 20) return "结果在$p$l划出一道细长的血痕。\n";
      else if (damage < 40) return "结果「嗤」地一声划出一道伤口！\n";
      else if (damage < 80) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
      else if (damage < 160) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
      else return "结果只听见$n一声惨嚎，$p的$l被划出一道深及见骨的可怕伤口！\n";
      break;
    case "砍伤":
    case "劈伤":
      if (damage < 10) return "结果只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n";
      else if (damage < 20) return "结果在$n$l砍出一道细长的血痕。\n";
      else if (damage < 40) return "结果「噗嗤」一声劈出一道血淋淋的伤口！\n";
      else if (damage < 80) return "结果只听「噗」地一声，$n的$l被劈得血如泉涌，痛得$p咬牙切齿！\n";
      else if (damage < 160) return "结果「噗」地一声砍出一道又长又深的伤口，溅得$N满脸鲜血！\n";
      else return "结果只听见$n一声惨嚎，$p的$l被劈开一道深及见骨的可怕伤口！\n";
      break;
    case "枪伤":
    case "刺伤":
      if (damage < 10) return "结果只是轻轻地刺破$p的皮肉。\n";
      else if (damage < 20) return "结果在$p$l刺出一个创口。\n";
      else if (damage < 40) return "结果「噗」地一声刺入了$n$l寸许！\n";
      else if (damage < 80) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了步！\n";
      else if (damage < 160) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
      else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！\n";
      break;
    case "筑伤":
      if (damage < 10) return "结果只是轻轻地一触，在$n的皮肤上留下一点白痕。\n";
      else if (damage < 20) return "结果在$p的$l留下几道血痕。\n";
      else if (damage < 40) return "结果一下子筑中，$n的$l顿时出现几个血孔！\n";
      else if (damage < 80) return "结果一下子筑中，$n立刻血流如注！\n";
      else if (damage < 120) return "结果「哧」地一声，$n顿时鲜血飞溅！\n";
      else if (damage < 160) return "结果这一下「哧」地一声，$n被筑得浑身是血！\n";
      else return "结果「哧」重重地砸中，$n被筑得千疮白孔，血肉四处横飞！\n";
      break;
    case "掌伤":
    case "拳伤":
    case "瘀伤":
      if (damage < 10) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
      else if (damage < 20) return "结果在$p的$l造成一处瘀青。\n";
      else if (damage < 40) return "结果一击命中，$n的$l登时肿了一块老高！\n";
      else if (damage < 80) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
      else if (damage < 120) return "结果「砰」地一声，$n退了两步！\n";
      else if (damage < 160) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
      else if (damage < 240) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
      else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！\n";
      break;
    case "撞伤":
    case "砸伤":
      if (damage < 10) return "结果只是轻轻地碰到，等于给$n搔了一下痒。\n";
      else if (damage < 20) return "结果在$p的$l砸出一个小臌包。\n";
      else if (damage < 40) return "结果砸个正着，$n的$l登时肿了一块老高！\n";
      else if (damage < 80) return "结果砸个正着，$n闷哼一声显然吃了不小的亏！\n";
      else if (damage < 120) return "结果「砰」地一声，$n疼得连腰都弯了！\n";
      else if (damage < 160) return "结果这一下「轰」地一声砸得$n眼冒金星，差一点摔倒！\n";
      else if (damage < 240) return "结果重重地砸中，$n眼前一黑，「哇」地一声吐出一口鲜血！\n";
      else return "结果只听见「轰」地一声巨响，$n被砸得血肉模糊，惨不忍睹！\n";
      break;
    case "震伤":
    case "内伤":
      if (damage < 20) return "结果在$n身上一触即逝，等于给$n搔了一下痒。\n";
      else if (damage < 40) return "结果$n晃了一晃，吃了点小亏。\n";
      else if (damage < 80) return "结果$n气息一窒，显然有点呼吸不畅！\n";
      else if (damage < 120) return "结果$n体内一阵剧痛，看起来内伤不轻！\n";
      else if (damage < 160) return "结果「嗡」地一声$n只觉得眼前一黑，双耳轰鸣不止！\n";
      else return "结果只听见「嗡」地一声巨响，$n「哇」地一声吐出一口鲜血，五脏六腑都错了位！\n";
      break;
    case "鞭伤":
    case "抽伤":
      if (damage < 10) return "结果只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n";
      else if (damage < 20) return "结果在$n$l抽出一道轻微的紫痕。\n";
      else if (damage < 40) return "结果「啪」地一声在$n$l抽出一道长长的血痕！\n";
      else if (damage < 80) return "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！\n";
      else if (damage < 160) return "结果「啪」地一声爆响！这一下好厉害，只抽得$n皮开肉绽，血花飞溅！\n";
      else return "结果只听见$n一声惨嚎，$w重重地抽上了$p的$l，$n顿时血肉横飞，十命断了九条！\n";
      break;
    default:
      if (!type) type = "伤害";
      if (damage < 10) str = "结果只是勉强造成一处轻微";
      else if (damage < 20) str = "结果造成轻微的";
      else if (damage < 30) str = "结果造成一处";
      else if (damage < 50) str = "结果造成一处严重";
      else if (damage < 80) str = "结果造成颇为严重的";
      else if (damage < 120) str = "结果造成相当严重的";
      else if (damage < 170) str = "结果造成十分严重的";
      else if (damage < 230) str = "结果造成极其严重的";
      else str = "结果造成非常可怕的严重";
      return str + type + "！\n";
  }
}

string eff_status_msg(int ratio) {
  if (ratio == 100) return HIG "看起来气血充盈，并没有受伤。" NOR;
  if (ratio > 95) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
  if (ratio > 90) return HIY "看起来可能受了点轻伤。" NOR;
  if (ratio > 80) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
  if (ratio > 60) return HIY "受伤不轻，看起来状况并不太好。" NOR;
  if (ratio > 40) return HIR "气息粗重，动作开始散乱，看来所受的伤着实不轻。" NOR;
  if (ratio > 30) return HIR "已经伤痕累累，正在勉力支撑着不倒下去。" NOR;
  if (ratio > 20) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
  if (ratio > 10) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
  if (ratio > 5) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
  return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio) {
  if (ratio == 100) return HIG "看起来充满活力，一点也不累。" NOR;
  if (ratio > 95) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
  if (ratio > 90) return HIY "看起来可能有些累了。" NOR;
  if (ratio > 80) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
  if (ratio > 60) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
  if (ratio > 40) return HIR "似乎非常疲惫，看来需要好好休息了。" NOR;
  if (ratio > 30) return HIR "已经一副头重脚轻的模样，正在勉力支撑着不倒下去。" NOR;
  if (ratio > 20) return HIR "看起来已经力不从心,马上要支持不住了。" NOR;
  if (ratio > 10) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
  return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

//report_shen messages
string sen_status_msg(int ratio) {
  if (ratio == 100) return HIG "看起来头脑清醒，一点也不迷糊。" NOR;
  if (ratio > 90) return HIG "拍了拍自己的脑袋，似乎有点不太得劲。" NOR;
  if (ratio > 80) return HIY "看起来有些迷糊了。" NOR;
  if (ratio > 60) return HIY "的确有点迷糊了，但还辨得出东西南北。" NOR;
  if (ratio > 40) return HIR "两眼发直，口角流涎，神智开始混乱。" NOR;
  if (ratio > 20) return HIR "迷迷糊糊，摇摇晃晃，已经辨不出东西南北了。" NOR;
  if (ratio > 10) return RED "神智已经处在极度混乱中,再也支持不住了。" NOR;
  return RED "心智已经完全迷失，随时都有可能背过气去。" NOR;
}
