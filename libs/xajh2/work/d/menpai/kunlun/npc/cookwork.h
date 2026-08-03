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
    "name"        : "挑水",
    "time"        : 180,
    "give_msg"    : "大厨师对$N点了点头说：“现在正要做饭，你去担点水来倒在缸里吧。”\n",
    "success_msg" : "大厨师对$N笑道：“累了吧，快歇息去吧。”\n",
    "fail_msg"    : "大厨师对$N皱了皱眉：“连担水都不会？”\n",
    "delay_msg"   : "大厨师叹了口气：“这么长时间才回来？”\n",
    "success_p"   : 3,
    "fail_p"      : 2,
    "positive_score": 0,
    "negative_score": 0,
]),
([
    "name"        : "取白菜",
    "time"        : 240,
    "give_msg"    : "大厨师想了想，对$N点了点头说：“你去弄一棵白菜回来吧。”\n",
    "success_msg" : "大厨师对$N点了点头笑道：“这就回来了。”\n",
    "fail_msg"    : "大厨师对$N气愤的说道：“你真是没有用。”\n",
    "delay_msg"   : "大厨师对$N气愤的说道：“你真没用。”\n",
    "success_p"   : 4,
    "fail_p"      : 2,
    "positive_score": 0,
    "negative_score": 0,
    "object_name"   : "白菜",
]),
([
    "name"        : "取豆角",
    "time"        : 240,
    "give_msg"    : "大厨师对$N点了点头说：“你去找一些豆角来，怎么样？”\n",
    "success_msg" : "大厨师对$N不住的夸道：“不错，不错。真是及时。”\n",
    "fail_msg"    : "大厨师对$N叹了口气：“真是靠不住。”\n",
    "delay_msg"   : "大厨师对$N叹了口气：“今天这个菜是没有办法了。”\n",
    "success_p"   : 4,
    "fail_p"      : 3,
    "positive_score": 0,
    "negative_score": 0,
    "object_name"   : "豆角",
]),
([
    "name"        : "取茄子",
    "time"        : 240,
    "give_msg"    : "大厨师对$N说：“听说现在茄子熟了，你去弄一些来。”\n",
    "success_msg" : "大厨师对$N赞赏的说：“不错，不错。真有你的。”\n",
    "fail_msg"    : "大厨师对$N叹了口气：“我知道你尽力了。”\n",
    "delay_msg"   : "大厨师对$N叹了口气：“下去歇息吧。”\n",
    "success_p"   : 4,
    "fail_p"      : 3,
    "positive_score": 0,
    "negative_score": 0,
    "object_name"   : "茄子",
]),
([
    "name"        : "取萝卜",
    "time"        : 240,
    "give_msg"    : "大厨师对$N说：“萝卜熟了，你去弄一点来怎么样？”\n",
    "success_msg" : "大厨师对$N赞赏的说：“不错，不错。”\n",
    "fail_msg"    : "大厨师对$N叹了口气：“连这点东西也弄不来？”\n",
    "delay_msg"   : "大厨师对$N叹了口气：“耽误了这么长的时间了。”\n",
    "success_p"   : 4,
    "fail_p"      : 3,
    "positive_score": 0,
    "negative_score": 0,
    "object_name"   : "萝卜",
]),
});
mapping *work2=({
([
    "name"        : "砍柴",
    "time"        : 300,
    "give_msg"    : "大厨师对$N点了点头说：“现在厨房缺柴火，你去砍一点回来吧。”\n",
    "success_msg" : "大厨师对$N笑道：“不错，不错。去了一趟山上，感觉怎么样？”\n",
    "fail_msg"    : "大厨师对$N皱了皱眉，冷哼了一声：“连把柴火都弄不回来？真没办法。”\n",
    "delay_msg"   : "大厨师叹了口气：“这么长时间才回来？火都快熄了。”\n",
    "success_p"   : 6,
    "fail_p"      : 3,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "烧柴",
]),/*
([
    "name"        : "取竹笋",
    "time"        : 480,
    "give_msg"    : "大厨师对$N说道：咱们前面竹林里面的竹笋很不错，你去弄棵来吧。”\n",
    "success_msg" : "大厨师对$N点了点头：“你今天可真是立了一大功劳啊！”\n",
    "fail_msg"    : "大厨师对$N皱了皱眉，冷哼了一声：“真是没用 。”\n",
    "delay_msg"   : "大厨师对$N皱了皱眉，冷哼了一声：“真是没用 。”\n",
    "success_p"   : 8,
    "fail_p"      : 4,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "竹笋",
])*/

});

mapping *work3=({
([
    "name"        : "取木炭",
    "time"        : 600,
    "give_msg"    : "大厨师对$N点了点头说：“现在想烤点东西，需要用木炭，你想想办法吧。”\n",
    "success_msg" : "大厨师伸出一只油腻腻的手，拍拍$N的肩膀笑道：“真有你的。”\n",
    "fail_msg"    : "大厨师对$N叹了口气，说道：“相信你也尽力了。”",
    "delay_msg"   : "大厨师对$N叹了口气，说道：“相信你也尽了力了。”",
    "success_p"   : 10,
    "fail_p"      : 4,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "木炭",
]),
([
    "name"        : "取木耳",
    "time"        : 600,
    "give_msg"    : "大厨师对$N很高兴地说：“山上树林里面有木耳，你去找点来吧。”\n",
    "success_msg" : "大厨师伸出一只油腻腻的手，看见$N皱了皱眉，没有拍，笑道：“恩，不错！”\n",
    "fail_msg"    : "大厨师对$N叹了口气，说道：“算了······”",
    "delay_msg"   : "大厨师对$N叹了口气，说道：“算了······”",
    "success_p"   : 14,
    "fail_p"      : 5,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "木耳",
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
