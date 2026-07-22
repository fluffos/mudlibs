// Modify By River@SJ 2003.8.26

// 答案字节不得大于 30 个，汉字 15 个。
// 答案个数不超过 6 个（含正确答案在内）。
// 全部为选择题，答案最少需要 2 个。

mapping *question_list = ({
([
	"question":	"阿朱、阿紫、阿碧血缘上讲是姐妹？",
	"answer":	"否",
	"choose":	({"是"}),
]),
([
	"question":	"『九阴真经』和『九阳真经』作者是同一个人？",
	"answer":	"否",
	"choose":	({"是"}),
]),
([
	"question":	"辟邪剑法源自『葵花宝典』？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"小郡主沐剑屏是其父唯一的孩子？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"ALIAS是指MUD里的别名，用简单的几个字母代替较为复杂的一些指令，\n"+
			"从而使输入迅速？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"人物有悟性、根骨、身法、膂力四项基本天赋？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"人物有福缘、纯朴、容貌、精神四项隐藏天赋？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"玩家死亡后可以复活，但是损失所有的钱财，各种技能降半级，经验减\n"+
			"少 0.5% ？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"气是一个人的力气大小的标准，也分为最大值，有效值和当前值？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"精是一个人的精神状况的标准，分为最大值，有效值和当前值。最大值？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"玩家可以通过提高特殊内功的等级来提高后天根骨？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"玩家可以通过提高基本内功的等级来提高后天根骨？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"玩家可以通过提高读书写字的等级来提高后天悟性？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"玩家可以通过提高基本轻功的等级来提高后天身法？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"玩家可以通过提高特殊轻功的等级来提高后天身法？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"正气或戾气是衡量一个人物正直或是邪恶的标尺？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"当精、气、精力、内力的任何一种小于零的时候人都会昏迷，在昏迷时\n"+
			"又受到攻击则死亡？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"如果一个游戏者的最高工匠技能级别高于他本身的最高武学技能，且工\n"+
			"匠技能大于一百级，则此游戏者将被认为是工匠？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"工匠所拥有的所有武学技能都不能超过二百级？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"工匠技能以四百级为极限，并且受经验限制？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"如果有玩家企图杀害一个工匠，且此工匠不是通缉犯，此工匠可以随时\n"+
			"随地呼唤巡捕（yell guard），来寻求巡捕的保护？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"工匠在钱庄中可以比武士存更多的钱，但相对而言取钱的手续费比武士\n"+
			"要高？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"经验大于 5,000,000 的玩家就能建立自己的帮派？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"帮派系统中帮主可以用解散(gdismiss)命令来解散帮派，也可以使用禅\n"+
			"让把帮主位置传给帮派中符合条件的玩家？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"帮派系统中帮派的首领可以在自己的帮派里命令等级比自己低的帮派成\n"+
			"员执行某些动作，命令为 gforce",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"帮派系统中每个帮派都有自己的实力值和名望值，实力值由帮派的成员\n"+
			"的实力总和而得，名望值的增减则由帮派间争斗得结果决定？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"在聊天系统中，用 say  命令说出来的话，只能被同一个场景内的玩家\n"+
			"听到？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"如果在短时间内发大量信息到公聊频道的玩家，将会被系统强制关闭他\n"+
			"的聊天频道？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"算命得知：「看……五官挪位，印堂发暗，……。」可知其容貌小于 15 ？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"算命得知：「……，不过你前生一定行了善事，一生大富大贵，子孙多\n"+
			"多。」可知其福缘小于 20 ？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"加力(jiali) 的多少直接影响攻击力。但应注意加力的大小，加力后增\n"+
			"加杀伤力但同时消耗大量内力？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"读书时，每一次读书都要消耗一些精血，悟性高的人消耗的精血较少，\n"+
			"悟性低的人消耗的精血较多？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"在三十岁前精的最大值会逐年增长，四十岁后则会逐年减少，七十岁后\n"+
			"不再变化？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"内力可以运用于恢复，包括恢复精(yun regenerate)、气(yun recover)、\n"+
			"精力(yun refresh)这三种？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"潜能的上限与受经验限制的武功级别有关？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"武功的有效等级等于基本武功跟特殊武功之和？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"讨价还价(trade) 是你做买卖讲价的水平，级别越高则在买卖中的亏损\n"+
			"越少？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"帮派争斗中攻击对方的物品或房间时，同一房间的所有和攻击者同一帮\n"+
			"派或同一联盟的玩家的攻击力和防御力会有一定的下降？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"在帮派争斗期间，争斗双方及其各自结盟帮派的成员在争斗双方的帮派\n"+
			"区域里叫杀没有BUSY，但杀死对方后会被通缉？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"帮派系统中帮派成员分为帮主、副帮主、堂主、帮众四个等级？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"工匠可以去扬州东门附近的龙门镖局雇佣保镖来保护自己，一个工匠所\n"+
			"能雇佣的保镖最高等级取决于该工匠的战斗经验的高低？",
	"answer":	"否",
	"choose":	({ "是" }),
]),
([
	"question":	"在任何地方都可以对通缉犯叫杀(kill)，而且没有忙碌状态？",
	"answer":	"是",
	"choose":	({ "否" }),
]),
([
	"question":	"练习技能一次得到的点数约等于该项基本武功的级别的：",
	"answer":	"1/5",
	"choose":	({ "1/2", "1/3", "1/4" }),
]),
([
	"question":	"领悟一次得到的点数取决于：",
	"answer":	"读书写字",
	"choose":	({ "先天悟性", "后天悟性", "精" }),
]),
([
	"question":	"吐呐需要你的气的当前值大于最大气的：",
	"answer":	"70%",
	"choose":	({ "50%", "60%", "80%" }),
]),
([
	"question":	"打坐需要你的精的当前值大于最大精的：",
	"answer":	"80%",
	"choose":	({ "50%", "60%", "70%" }),
]),
([
	"question":	"用「一苇渡江」渡过汉水,需要轻功有效等级大于等于：",
	"answer":	"80",
	"choose":	({ "60", "100", "120" }),
]),
([
	"question":	"飞身渡黄河需要轻功有效等级大于等于：",
	"answer":	"250",
	"choose":	({ "200", "300", "350" }),
]),
([
	"question":	"飞身渡长江需要最大内力大于等于：",
	"answer":	"3500",
	"choose":	({ "2000", "2500", "3000" }),
]),
([
	"question":	"温家五老中，愿意把五行阵传授给外人的是：",
	"answer":	"温方山",
	"choose":	({ "温方达", "温方义", "温方悟", "温方施" }),
]),
([
	"question":	"下列行为中，不会被通缉的是：",
	"answer":	"杀官兵",
	"choose":	({ "杀侯君集", "杀史青山", "杀顾炎武" }),
]),
([
	"question":	"下面那一项不是昆仑三圣何足道的绰号？",
	"answer":	"赌圣",
	"choose":	({ "棋圣", "剑圣", "琴圣" }),
]),
([
	"question":	"屠龙刀中藏的是：",
	"answer":	"武穆遗书",
	"choose":	({ "九阴真经", "九阳真经", "葵花宝典" }),
]),
([
	"question":	"下面哪个不是看守谢逊的三大神僧？",
	"answer":	"空见",
	"choose":	({ "渡厄", "渡劫", "渡难" }),
]),
([
	"question":	"「那少年约莫十五六岁年纪，头上歪戴著一顶黑黝黝的破石帽，.....\n"+
			"露出两排晶晶发亮的雪白细牙...眼珠漆黑，甚是灵动」说的是：",
	"answer":	"黄蓉",
	"choose":	({ "韦小宝", "木婉清", "杨过" }),
]),
([
	"question":	"下面这些人不曾断指的是：",
	"answer":	"赵志敬",
	"choose":	({ "尹志平", "范遥", "郑克爽" }),
]),
([
	"question":	"恢复精血的指令是：",
	"answer":	"yun jing",
	"choose":	({ "yun jingli", "yun qi", "yun heal" }),
]),
([
	"question":	"恢复精力的指令是：",
	"answer":	"yun jingli",
	"choose":	({ "yun jing", "yun qi", "yun heal" }),
]),
([
	"question":	"恢复气血的指令是：",
	"answer":	"yun qi",
	"choose":	({ "yun jing", "yun jingli", "dazuo" }),
]),
([
	"question":	"使内力增加的最常用途径是：",
	"answer":	"dazuo",
	"choose":	({ "yun jing", "yun jingli", "yun qi" }),
]),
([
	"question":	"学习技能将会消耗的是：",
	"answer":	"精血",
	"choose":	({ "精力", "内力", "气血" }),
]),
([
	"question":	"在河边或者江边叫船的指令是：",
	"answer":	"yell boat",
	"choose":	({ "look boat", "yell", "find boat" }),
]),
([
	"question":	"下面哪种频道解释是错误的？",
	"answer":	"party 帮派频道",
	"choose":	({ "chat 闲聊频道", "rumor 谣言频道", "tell 私聊频道" }),
]),
([
	"question":	"如果你到了一个出售商品的NPC面前，看商品目录的指令是？",
	"answer":	"list",
	"choose":	({ "look", "place", "help" }),
]),
([
	"question":	"如果你在游戏中想跟随某个玩家或者NPC一起行动,则应输入指令：",
	"answer":	"follow",
	"choose":	({ "gen", "follow none", "lead" }),
]),
([
	"question":	"如果你想解除跟随某个玩家或NPC的指令，则应输入：",
	"answer":	"follow none",
	"choose":	({ "follow", "no follow", "follow me" }),
]),
([
	"question":	"在游戏中，查看自己有何武功的指令是？",
	"answer":	"skills(cha)",
	"choose":	({ "score", "inventory(i)", "hp" }),
]),
([
	"question":	"在游戏中，查看自己身上有何物品的指令是？",
	"answer":	"inventory(i)",
	"choose":	({ "look", "skills", "hp" }),
]),
([
	"question":	"离开游戏的正确指令是？",
	"answer":	"quit",
	"choose":	({ "断线", "关闭zMUD窗口", "关机" }),
]),
([
	"question":	"下面不属于私人聊天的指令是：",
	"answer":	"rumor",
	"choose":	({ "tell", "reply", "whisper" }),
]),
([
	"question":	"不受根骨影响的是：",
	"answer":	"饭量的大小",
	"choose":	({ "气的恢复速度", "受攻击时所受的伤害", "每岁精、气的增长" }),
]),
([
	"question":	"不影响膂力大小的是：",
	"answer":	"基本招架",
	"choose":	({ "基本拳脚", "基本指法", "基本腿法" }),
]),
([
	"question":	"不决定铸造兵器基本威力的是：",
	"answer":	"铸造时间",
	"choose":	({ "兵器的等级", "制造兵器的原材料", "制造者的锻造技能" }),
]),
([
	"question":	"不属于药师应该拥有的技能是：",
	"answer":	"种植术",
	"choose":	({ "采药术", "提炼术", "炼丹术" }),
]),
([
	"question":	"不属于铸剑师应该拥有的技能是：",
	"answer":	"修理术",
	"choose":	({ "采矿术", "打铁术", "锻造术" }),
]),
([
	"question":	"不属于织造师应该拥有的技能是：",
	"answer":	"修补术",
	"choose":	({ "采集术", "编织术", "裁剪术" }),
]),
([
	"question":	"当你想要了解某一区域（比如大理）的地图的时候，指令是：",
	"answer":	"help map dali",
	"choose":	({ "help", "help map here", "look dali" }),
]),
([
	"question":	"当你想要了解某一门派（比如明教）的说明时，指令是：",
	"answer":	"help party mingjiao",
	"choose":	({ "help", "help party", "party help" }),
]),
([
	"question":	"在帮派系统中,如果要对一个帮派开战，那么宣战的指令是？",
	"answer":	"declare",
	"choose":	({ "delate", "grant", "destory" }),
]),
([
	"question":	"在帮派系统中，结盟的指令是？",
	"answer":	"ally",
	"choose":	({ "attack", "gwar", "abdicate" }),
]),
([
	"question":	"如果要销毁自己帮派里的物品或房间，使用的命令是：",
	"answer":	"destory",
	"choose":	({ "attack", "gwar", "build" }),
]),
([
	"question":	"请问怎样可以将你的好友「friend」加入你的好友列表中？",
	"answer":	"finger -a friend",
	"choose":	({ "finger friend", "finger -d friend" }),
]),
([
	"question":	"请问如何给自己起一个「nickname」的外号？",
	"answer":	"nick nickname",
	"choose":	({ "nick none", "nick add nickname"}),
]),
([
	"question":	"为了角色安全需要时常修改登陆密码，请问通过什么指令修改？",
	"answer":	"passwd",
	"choose":	({ "password", "passwd -c", "passwd -send" }),
]),
([
	"question":	"请问如何查看角色的本次连线时间？",
	"answer":	"time",
	"choose":	({ "uptime", "onlinetime"}),
]),
([
	"question":	"请问如何设定当自己气血不足 30% 的时候自动逃离战场？",
	"answer":	"set wimpy 30",
	"choose":	({ "set brief 30", "set no_accept 30", "set block 30" }),
]),
([
	"question":	"玩家「char」在公开频道中发布不适当言论，你希望发布一个投票关闭\n"+
			"他的频道该如何进行？",
	"answer":	"vote chblk char",
	"choose":	({ "vote unchblk char", "chblk char", "unchblk char"}),
]),
([
	"question":	"你希望在自己的角色上增加一些个性的描述说明，该通过哪个指令添加？",
	"answer":	"describe",
	"choose":	({ "nick", "color", "score" }),
]),
([
	"question":	"请问如何把玄铁剑法(xuantie-jianfa)指定为你使用的基本剑法种类？",
	"answer":	"jifa sword xuantie-jianfa",
	"choose":	({ "jifa xuantie-jianfa", "bei xuantie-jianfa", "bei sword xuantie-jianfa" }),
]),
([
	"question":	"如何查看书剑的预设表情动作列表？",
	"answer":	"semote",
	"choose":	({ "emote", "help emote" }),
]),
([
	"question":	"如果你不希望看到闲聊频道的说话，通过什么指令关闭？",
	"answer":	"tune chat",
	"choose":	({ "tune party", "tune rumor", "tune sj" }),
]),
([
	"question":	"使用什么指令可以让你从战斗中安全脱离出来？",
	"answer":	"halt",
	"choose":	({ "go", "leave" }),
]),
([
	"question":	"使用什么指令可以让在游戏中的所有人肯定可以看到你所说的话？",
	"answer":	"shout",
	"choose":	({ "chat", "rumor", "sj" }),
]),
([
	"question":	"使用什么指令可以解散一个你已经建立的队伍？",
	"answer":	"team dismiss",
	"choose":	({ "team with", "team", "team talk" }),
]),
([
	"question":	"如果你不想与玩家「char」私聊，应当如何进行？",
	"answer":	"set block char",
	"choose":	({ "set tell char", "finger -a char", "finger -d char" }),
]),
([
	"question":	"当地上有黄金「gold」，你想捡起来，应输入的指令是",
	"answer":	"get gold",
	"choose":	({ "drop gold", "give gold", "steal gold" }),
]),
([
	"question":	"如果你想装备剑「sword」，则应输入？",
	"answer":	"wield sword",
	"choose":	({ "unwield sword", "wear sword", "remove sword" }),
]),
([
	"question":	"当你想从玩家「char」身上偷取黄金「gold」时，正确的指令是？",
	"answer":	"steal gold from char",
	"choose":	({ "give char gold", "give gold to char", "get gold from char" }),
]),
([
	"question":	"当你想把身上的衣服「cloth」穿上时，应该输入的指令是？",
	"answer":	"wear cloth",
	"choose":	({ "remove cloth", "wield cloth", "unwield cloth" }),
]),
([
	"question":	"当你想脱掉身上的衣服(cloth)时，应该输入的指令是？",
	"answer":	"remove cloth",
	"choose":	({ "wear cloth", "wield cloth", "unwield cloth" }),
]),
([
	"question":	"当你想把身上的衣服「cloth」丢弃的时候，应输入的指令是？",
	"answer":	"drop cloth",
	"choose":	({ "get cloth", "give cloth", "put cloth" }),
]),
([
	"question":	"当你想把手中的剑「sword」放下时，应该输入的指令是？",
	"answer":	"unwield sword",
	"choose":	({ "wield sword", "wear sword", "remove sword" }),
]),
([
	"question":	"用内力给自己疗伤的指令是？",
	"answer":	"yun heal",
	"choose":	({ "yun jingli", "yun qi", "yun jing" }),
]),
([
	"question":	"如果你想给玩家「char」疗伤，应该输入的指令是？",
	"answer":	"yun lifeheal char",
	"choose":	({ "yun heal char", "yun lifesave char", "yun qi char" }),
]),
([
	"question":	"神雕侠侣中小龙女传给杨过抓麻雀的手法是什么？",
	"answer":	"tianluo-diwang",
	"choose":	({ "yunu-shenfa", "yunu-xinjing", "yinsuo-jinling" }),
]),
([
	"question":	"鹿鼎记中韦小宝使用的轻功是什么？",
	"answer":	"shenxing-baibian",
	"choose":	({ "hansha-sheying", "lingbo-weibu", "tianlong-xiang" }),
]),
([
	"question":	"笑傲江湖中风清阳传给令狐冲的剑法是什么？",
	"answer":	"dugu-jiujian",
	"choose":	({ "huashan-jianfa", "taiji-jian", "xuantie-jianfa" }),
]),
([
	"question":	"射雕英雄传里梅超风传给杨康的爪法是什么？",
	"answer":	"jiuyin-baiguzhua",
	"choose":	({ "jiuyin-shenzhua", "ningxue-shenzhua", "youming-shenzhua" }),
]),
([
	"question":	"当你身处茶馆，想要买花生「huasheng」，指令是？",
	"answer":	"buy huasheng",
	"choose":	({ "sell huasheng", "get huasheng", "qu huasheng" }),
]),
([
	"question":	"自己建立帮派的命令是？",
	"answer":	"gcreate",
	"choose":	({ "glist", "build", "grant" }),
]),
([
	"question":	"如果你想布五行阵「wuxing-zhen」,该使用的命令是？",
	"answer":	"lineup form wuxing-zhen",
	"choose":	({ "lineup", "lineup wuxing-zhen", "lineup with wuxing-zhen" }),
]),
([
	"question":	"在游戏中建立聊天室的命令是？",
	"answer":	"irc /create",
	"choose":	({ "irc /join", "irc /setroom", "irc /invite" }),
]),
([
	"question":	"如果你想跟玩家「char」组队，应该使用的命令是？",
	"answer":	"team with char",
	"choose":	({ "team dismiss", "team talk", "team kill" }),
]),
([
	"question":	"学习一次得到的点数约等于后天悟性的：",
	"answer":	"1/2",
	"choose":	({"1/3", "1/4", "1/5"}),
]),
([
	"question":	"读书一次得到的点数约等于读书写字级别的：",
	"answer":	"1/5",
	"choose":	({"1/2", "1/3", "1/4"}),
]),
([
	"question":	"当你的气血上限不是 100% 时，哪种原因是错误的？",
	"answer":	"食物吃得太多",
	"choose":	({ "最大气血增加后再次连线进入游戏", "战斗受伤", "中毒" }),
]),
});
