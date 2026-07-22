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
    "name"        : "取蒜",
    "time"        : 240,
    "give_msg"    : "药师点了点头，对$N说道：“大蒜能却火，你去弄一点来。”\n",
    "success_msg" : "药师对$N称赞道：“你真的很快啊！”\n",
    "fail_msg"    : "药师叹了口气：“这么长时间才回来？”\n",
    "delay_msg"   : "药师叹了口气：“这么长时间才回来？”\n",
    "success_p"   : 3,
    "fail_p"      : 2,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "蒜",
]),
([
    "name"        : "取菊花",
    "time"        : 240,
    "give_msg"    : "药师点了点头，对$N说道：“菊花能清新明目，你去弄一点来。”\n",
    "success_msg" : "药师对$N称赞道：“真是一个有前途的弟子！”\n",
    "fail_msg"    : "药师叹了口气：“怎么这么长时间才回来？”\n",
    "delay_msg"   : "药师叹了口气：“怎么这么长时间才回来？”\n",
    "success_p"   : 3,
    "fail_p"      : 2,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "菊花",
]),
([
    "name"        : "取薄荷",
    "time"        : 240,
    "give_msg"    : "药师点了点头，对$N说道：“现在缺一点薄荷，你去弄一点来。”\n",
    "success_msg" : "药师对$N称赞道：“不错！不错。 ”\n",
    "fail_msg"    : "药师叹了口气，对$N说道：“你是怎么了？”\n",
    "delay_msg"   : "药师叹了口气，对$N说道：“太慢了，制药是需要赶时间的。”\n",
    "success_p"   : 3,
    "fail_p"      : 2,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "薄荷",
]),
});

mapping *work2=({
([
    "name"        : "取虫草",
    "time"        : 600,
    "give_msg"    : "药师想了想，对$N说：“前几天在古籍里面发现一种草药：虫草。\n"
                    "听说常长在草势茂密之地，你去给我弄一株来怎么样？”\n",
    "success_msg" : "药师对$N称赞道：“不错！这虫草就是奇妙。”\n",
    "fail_msg"    : "药师叹了口气，对$N说道：“真是没有用，你下去吧。”\n",
    "delay_msg"   : "药师叹了口气，对$N说道：“真是没有用，你下去吧。”\n",
    "success_p"   : 8,
    "fail_p"      : 4,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "虫草",
]),/*
([
    "name"        : "取白花蛇",
    "time"        : 600,
    "give_msg"    : "药师想了想，对$N说：“前几天在古籍里面发现一种奇特的动物：白花蛇。\n"
                    "据说前面那片竹林里有人见到过，你去给我弄一条来怎么样？”\n",
    "success_msg" : "药师对$N称赞道：“不错，辛苦你了！”\n",
    "fail_msg"    : "药师叹了口气，对$N说道：“真是没有用，你下去吧。”\n",
    "delay_msg"   : "药师叹了口气，对$N说道：“真是没有用，你下去吧。”\n",
    "success_p"   : 10,
    "fail_p"      : 5,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": "白花蛇",
]),*/
});

mapping *work3=({
([
    "name"        : "取"RED"红"NOR"蘑菇",
    "time"        : 600,
    "give_msg"    : "药师对$N说道：“听说有人在后山丛林里面发现了一种"RED"红"NOR"蘑菇。\n"
                    "               你去取点来，我想研究研究。\n",
    "success_msg" : "药师对$N称赞道：“不错！下去休息一会儿吧。”\n",
    "fail_msg"    : "药师叹了口气，对$N哼道：“真是没有用，光吃饭不办事。”\n",
    "delay_msg"   : "药师叹了口气，对$N哼道：“真是没有用，光吃饭不办事。”\n",
    "success_p"   : 15,
    "fail_p"      : 6,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": RED"红"NOR"蘑菇",
]),
([
    "name"        : "取"CYN"青"NOR"蘑菇",
    "time"        : 600,
    "give_msg"    : "药师对$N说道：“听说有人在后山丛林里面发现了一种"CYN"青"NOR"蘑菇。\n"
                    "               你去取一朵来，我想研究研究。\n",
    "success_msg" : "药师对$N称赞道：“不错！去了一趟山上，很累了吧。”\n",
    "fail_msg"    : "药师叹了口气，对$N哼道：“真是没有用，光吃饭不办事。”\n",
    "delay_msg"   : "药师叹了口气，对$N哼道：“真是没有用，光吃饭不办事。”\n",
    "success_p"   : 15,
    "fail_p"      : 6,
    "positive_score": 0,
    "negative_score": 0,
    "object_name": CYN"青"NOR"蘑菇",
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
