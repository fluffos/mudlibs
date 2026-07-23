// mapping kunlun_work
//      name              //任务名称
//      time              //时间限制
//      give_msg          //给任务信息
//      success_msg       //成功信息
//      fail_msg          //失败信息
//      delay_msg         //耽搁信息
//      success_p         //成功奖励点数
//      fail_p            //失败点数
//      positive_score    //正声望
//      negative_score    //负声望
//      object_name       //所取物品的名字。

mapping *work1=({
([
    "name"        : "浇水",
    "time"        : 200,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“地里缺水了，你去担点水来浇一下吧。”\n",
    "success_msg" : "高老头对$N笑道：“不错，不错。真勤快。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“你真懒啊···”\n",
    "delay_msg"   : "高老头无奈的对$N说道：“你真懒啊···”\n",
    "success_p"   : 3,
    "fail_p"      : 1,
]),
([
    "name"        : "锄草",
    "time"        : 200,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“你去地里面除一下草吧。”\n",
    "success_msg" : "高老头对$N夸道：“不错，不错。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“你怎么这么慢啊？”\n",
    "delay_msg"   : "高老头无奈的对$N说道：“你怎么会事？”\n",
    "success_p"   : 4,
    "fail_p"      : 2,
]),
});

mapping *work2=({
([
    "name"        : "取白菜子",
    "time"        : 600,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“你去弄一点白菜子回来。\n",
    "success_msg" : "高老头对$N夸道：“回来得真快。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“你怎么这么慢呢？”\n",
    "delay_msg"   : "高老头无奈的对$N说道：“你怎么这么慢呢？”\n",
    "success_p"   : 9,
    "fail_p"      : 4,
    "object_name" : "白菜子"
]),
([
    "name"        : "取薄荷子",
    "time"        : 600,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“你去弄一点菜子回来，是薄荷子。\n",
    "success_msg" : "高老头对$N夸道：“你回来得真快啊——。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“你怎么这么慢呢？”\n",
    "delay_msg"   : "高老头无奈的对$N说道：“你怎么这么慢呢？”\n",
    "success_p"   : 9,
    "fail_p"      : 4,
    "object_name" : "薄荷子"
]),
([
    "name"        : "取蒜子",
    "time"        : 600,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“现在应该种蒜了，下山取点菜子回来吧。\n",
    "success_msg" : "高老头对$N夸道：“你回来得真是及时。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“怎么这么慢呢？”\n",
    "delay_msg"   : "高老头无奈的对$N说道：“怎么这么慢呢？”\n",
    "success_p"   : 9,
    "fail_p"      : 4,
    "object_name" : "蒜子"
]),
});

mapping *work3=({
([
    "name"        : "种蒜",
    "time"        : 1000,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“要种点大蒜，你去地里忙一下。\n",
    "success_msg" : "高老头对$N夸道：“不错，是可造之材。”\n",
    "fail_msg"    : "高老头怀疑地对$N说道：“你怎么回事？”\n",
    "delay_msg"   : "高老头无奈地对$N说道：“你怎么这么慢呢？”\n",
    "success_p"   : 15,
    "fail_p"      : 6,
]),
([
    "name"        : "种薄荷",
    "time"        : 1000,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“现在种点薄荷，你去地里忙一下吧。\n",
    "success_msg" : "高老头对$N夸道：“不错，是可造之材。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“你怎么回事？”\n",
    "delay_msg"   : "高老头对$N摇摇头说道：“你辛苦了，下去休息吧。”\n",
    "success_p"   : 15,
    "fail_p"      : 6,
]),
([
    "name"        : "种白菜",
    "time"        : 1000,
    "give_msg"    : "高老头看了看蔬圃，对$N说道：“现在该种白菜了，你去地里忙一下好了。\n",
    "success_msg" : "高老头对$N夸道：“不错，是可造之材。”\n",
    "fail_msg"    : "高老头无奈的对$N说道：“你怎么回事？”\n",
    "delay_msg"   : "高老头无奈的对$N说道：“你怎么这么慢呢？”\n",
    "success_p"   : 15,
    "fail_p"      : 6,
]),
});




mapping query_work(int level)
{
    int i;
    switch(level) {
    case 1:
      i=random(sizeof(work1));
      return( work1[i] );
    case 2:
      i=random(sizeof(work2));
      return( work2[i] );
    case 3:
      i=random(sizeof(work3));
      return( work3[i] );
    default:
      return work1[0];
   }
}
