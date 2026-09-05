mapping instrument_name=
(["qin":"琴",
	"zheng":"筝",
	"pipa":"琵琶",
	"shaw":"箫",
	"flute":"笛子",
	"drum":"鼓",
	"cymbals":"铜钹"]);

mapping subskill_info=
([
//基准技能
  "music-theory":
  (["name":"基本乐理",  //技能名称
  	"class":2,          //技能分类（分为2，3两级，2级表示为基本技能，3级都是具体的音乐乐谱
  	"level":0]),        //技能级别（分为0-3，表示技能的级别，其中对于2级基本技能，分为0级基础技能，1级基本技能
  	                    //          对于3级音乐乐谱，0-3分别表示乐谱的难易程度）
  	                    //这个级别的含义就是比如对于1级基本技能需要一定等级的0级基础技能等级要求，
  	                    //对于音乐乐谱，高级乐谱不但需要你先学习一定等级的低级乐谱，还需要对应乐器知识等级和基本乐理等级。
  	                    //这里class=2并且level=0的音乐技能只有基本乐理技能。
//基础乐器知识
  "qin":
  (["name":"琴基础",
  	"class":2,
  	"level":1,
  	"require": ({50})]),//require含义要求的前置技能等级，对于class=2 level=1的技能仅仅要求class=2 level=0的基本乐理，
  	                    //对于比如class=3 level=0 则要求对应乐器技能和基本乐理技能，阵列里面第一个元素是要求的基本乐理技能，
  	                    //第二个元素是要求的对应乐器技能，如果是class=3 level=1则第三个元素是要求的level=0的简单乐谱等级
  "pipa":
  (["name":"琵琶基础",
    "class":2,
    "level":1,
    "require":({50})]),
  "zheng":
  (["name":"筝基础",
    "class":2,
    "level":1,
    "require":({50})]),
  "shaw":
  (["name":"箫基础",
    "class":2,
    "level":1,
    "require":({50})]),
  "flute":
  (["name":"横笛基础",
    "class":2,
    "level":1,
    "require":({50})]),
  "drum":
  (["name":"鼓基础",
    "class":2,
    "level":1,
    "require":({50})]),
  "cymbals":
  (["name":"铜钹基础",
    "class":2,
    "level":1,
    "require":({50})]),
//十大名曲中基础乐谱部分（选了其中五首曲子）
  "gaoshan-liushui":
  (["name":"高山流水",
  	"class":3,
  	"level":0,
  	"require":({80,50}),
  	"master":({"qin","zheng"})]),  //主乐器，如果非主乐器想要谱此曲，必须主乐器熟悉该乐器，并且等级超过100
  "meihua-sannong":
  (["name":"梅花三弄",
  	"class":3,
  	"level":0,
  	"require":({80,50}),
  	"master":({"flute","shaw"})]),
  "hangong-qiuyue":
  (["name":"汉宫秋月",
  	"class":3,
  	"level":0,
  	"require":({80,50}),
  	"master":({"pipa","zheng"})]),
  "hujia-pai":
  (["name":"胡笳十八拍",
  	"class":3,
  	"level":0,
  	"require":({80,50}),
  	"master":({"qin"})]),
  "yangchun-baixue":
  (["name":"阳春白雪",
  	"class":3,
  	"level":0,
  	"require":({80,50}),
  	"master":({"qin","pipa"})]),
//十大名曲中稀有乐谱部分（选了其中五首曲子）
  "xiyang-xiaogu":                 //春江花月夜
  (["name":"夕阳箫鼓",
  	"class":3,
  	"level":1,
  	"require":({150,100,80}),
  	"master":({"pipa","zheng"})]),
  "yuqiao-wenwan":
  (["name":"渔樵问答",
  	"class":3,
  	"level":1,
  	"require":({150,100,80}),
  	"master":({"qin","shaw"})]),
  "guangling-san":
  (["name":"广陵散",
  	"class":3,
  	"level":1,
  	"require":({200,150,100}),
  	"master":({"qin"})]),
  "shimian-maifu":
  (["name":"十面埋伏",
  	"class":3,
  	"level":1,
  	"require":({200,150,100}),
  	"master":({"pipa"})]),
  "huanxisha-chunjing":
  (["name":"浣溪沙·春景",
  	"class":3,
  	"level":1,
  	"require":({200,150,100}),
  	"master":({"zheng", "qin"})]),
//高深乐谱-其实也就是门派攻击乐谱部分
  "bihai-chaosheng":
  (["name":"碧海潮生曲",        //桃花岛的主打乐谱，随着本乐谱等级提升附带控制敌人效果逐步加强，并且额外持续扣除对方气血的效果
  	                            //本曲分为浩渺碧海、暗湍绝流、汹涌洪涛、白浪连峰、风啸云飞、群魔弄潮、冰山融水、热海如沸、水若镜平
  	                            //九个段落，每个段落15秒钟，随着段落变化逐步加强效果
  	"class":3,
  	"level":2,
  	"require":({250,250,200,200}),
  	"master":({"flute","shaw"})]),
  "puan-zhou":
  (["name":"普庵咒",            //峨嵋派的主打乐谱，此咒可普安十方、驱除虫蚁、蚊蚋不生、消灾解厄、镇煞安胎、驱邪除秽、逢凶化吉。
  	"class":3,
  	"level":2,
  	"require":({250,250,200,200}),
  	"master":({"qin","pipa"})]),
  "xiaoao-jianghu":
  (["name":"笑傲江湖曲",            //日月神教/华山派的主打乐谱，琴箫合奏曲目，箫曲为buff类效果，琴曲为debuff类效果，合奏的情况下两种效果同时发生作用并且作用级别上调
  	"class":3,
  	"level":2,
  	"require":({250,250,200,200}),
  	"master":({"qin","shaw"})]),
]);