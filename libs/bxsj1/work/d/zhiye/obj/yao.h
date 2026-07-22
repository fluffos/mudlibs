// yao.h
// by augx@sj 3/5/2002

nosave mapping DRUGS = ([
"yangjing dan"	: ([	// 养精丹
	"name":		"养精丹",
	"id":		({ "yangjing dan","dan" }),
	"eat_msg":	"$N服下一颗养精丹，顿时觉得精血充足了不少。",
	"long":		"这是一颗用来恢复精血的丹药。",
	"busy":		5,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "bai wei","bai wei","bai wei","he ye","he ye","xiong huang" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"buqi wan"	: ([	// 补气丸
	"name":		"补气丸",
	"id":		({ "buqi wan","wan" }),
	"eat_msg":	"$N服下一颗补气丸，顿时觉得气血充足了不少。",
	"long":		"这是一颗用来恢复气血的丹药。",
	"busy":		5,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "ju geng","ju geng","mu gua","mu gua","xiong huang","xiong huang" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"xujing dan"	: ([	// 续精丹	
	"name":		"续精丹",
	"id":		({ "xujing dan","dan" }),
	"eat_msg":	"$N服下一颗续精丹，顿时觉得精力充沛了不少。",
	"long":		"这是一颗用来恢复精力的丹药。",
	"busy":		5,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "sang ye","sang ye","tian qi","tian qi","zhu ye","zhu ye" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"neixi wan"	: ([	// 内息丸
	"name":		"内息丸",
	"id":		({ "neixi wan","wan" }),
	"eat_msg":	"$N服下一颗内息丸，顿时觉得内力充沛了不少。",
	"long":		"这是一颗用来恢复内力的丹药。",
	"busy":		5,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "bai wei","bai wei","mu gua","mu gua","mu gua","zhu ye" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"bushi dan"	: ([	// 补食丹
	"name":		"补食丹",
	"id":		({ "bushi dan","dan" }),
	"eat_msg":	"$N服下一颗补食丹，再也不感到饥饿。",
	"long":		"这是一颗用来恢复食物的丹药。",
	"busy":		5,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "ju geng","ju geng","sang ye","sang ye","sang ye","xiong huang" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"bushui wan"	: ([	// 补水丸
	"name":		"补水丸",
	"id":		({ "bushui wan","wan" }),
	"eat_msg":	"$N服下一颗补水丸，再也不感到干渴。",
	"long":		"这是一颗用来恢复水分的丹药。",
	"busy":		5,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "he ye","he ye","he ye","ju geng","zhu ye","zhu ye" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"jinchuang yao"	: ([	// 金疮药
	"name":		"金疮药",
	"id":		({ "jinchuang yao","yao" }),
	"eat_msg":	"$N敷上一副金疮药，止住了出血。",
	"long":		"这是一副用来疗伤的金疮药。",
	"busy":		102,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "bai wei","bai wei","mu gua","tian qi","tian qi","tian qi" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
"liaojing dan"	: ([	// 疗精丹
	"name":		"疗精丹",
	"id":		({ "liaojing dan","dan" }),
	"eat_msg":	"$N服下一颗疗精丹，恢复了不少的精血。",
	"long":		"这是一颗用来疗伤的丹药。",
	"busy":		102,
	"worktime":	0,
	"neili":	100,
	"yaocai":	({ "he ye","ju geng","ju geng","tian qi","tian qi","xiong huang" }),
	"need_lvl":	1,
	"gain_lvl":	80,
	"win_lvl":	80,
	"max_lvl":	160,
	"drug_lvl":	6, ]),
			
"zhengqi dan"	: ([	// 正气丹
	"name":		"正气丹",
	"id":		({ "zhengqi dan","dan" }),
	"eat_msg":	"$N服下一颗正气丹，顿时感觉浑身充满正气。",
	"long":		"这是一颗用来增加正气的丹药。",
	"busy":		109,
	"worktime":	0,
	"neili":	300,
	"yaocai":	({ "bai zhi","bai zhi","bai zhi","chai hu","sang ye","sang ye" }),
	"need_lvl":	80,
	"gain_lvl":	160,
	"win_lvl":	160,
	"max_lvl":	220,
	"drug_lvl":	5, ]),
"xieqi wan"	: ([	// 邪气丸
	"name":		"邪气丸",
	"id":		({ "xieqi wan","wan" }),
	"eat_msg":	"$N服下一颗邪气丸，顿时感觉浑身充满邪气。",
	"long":		"这是一颗用来增加邪气的丹药。",
	"busy":		109,
	"worktime":	0,
	"neili":	300,
	"yaocai":	({ "bai zhi","bai zhi","bai zhi","fang feng","sang ye","sang ye" }),
	"need_lvl":	80,
	"gain_lvl":	160,
	"win_lvl":	160,
	"max_lvl":	220,
	"drug_lvl":	5, ]),	
"dali wan"	: ([	// 大力丸
	"name":		"大力丸",
	"id":		({ "dali wan","wan" }),
	"eat_msg":	"$N服下一颗大力丸，顿时感觉浑身充满力量。",
	"long":		"这是一颗用来增加力量的丹药。",
	"busy":		103,
	"worktime":	9,
	"neili":	500,
	"yaocai":	({ "chai hu","chai hu","chai hu","mu gua","mu gua","xiong huang" }),
	"need_lvl":	80,
	"gain_lvl":	160,
	"win_lvl":	160,
	"max_lvl":	220,
	"drug_lvl":	5, ]),	
"lingxi dan"	: ([	// 灵犀丹
	"name":		"灵犀丹",
	"id":		({ "lingxi dan","dan" }),
	"eat_msg":	"$N服下一颗灵犀丹，顿时感觉灵光展现。",
	"long":		"这是一颗用来提升智力的丹药。",
	"busy":		103,
	"worktime":	9,
	"neili":	500,
	"yaocai":	({ "gou qi","gou qi","gou qi","ju geng","ju geng","tian qi" }),
	"need_lvl":	80,
	"gain_lvl":	160,
	"win_lvl":	160,
	"max_lvl":	220,
	"drug_lvl":	5, ]),	
"huangu wan"	: ([	// 换骨丸
	"name":		"换骨丸",
	"id":		({ "huangu wan","wan" }),
	"eat_msg":	"$N服下一颗换骨丸，顿时感觉筋骨强健了不少。",
	"long":		"这是一颗用来提升根骨的丹药。",
	"busy":		103,
	"worktime":	9,
	"neili":	500,
	"yaocai":	({ "fang feng","fang feng","fang feng","mu gua","mu gua","tian qi" }),
	"need_lvl":	80,
	"gain_lvl":	160,
	"win_lvl":	160,
	"max_lvl":	220,
	"drug_lvl":	5, ]),	
"qingshen dan"	: ([	// 轻身丹
	"name":		"轻身丹",
	"id":		({ "qingshen dan","dan" }),
	"eat_msg":	"$N服下一颗轻身丹，顿时感觉身体轻了不少。",
	"long":		"这是一颗用来提升轻功的丹药。",
	"busy":		103,
	"worktime":	9,
	"neili":	500,
	"yaocai":	({ "bai zhi","bai zhi","bai zhi","sang ye","zhu ye","zhu ye" }),
	"need_lvl":	80,
	"gain_lvl":	160,
	"win_lvl":	160,
	"max_lvl":	220,
	"drug_lvl":	5, ]),	

"yannian dan"	: ([	// 延年养精丹
	"name":		CYN"延年养精丹"NOR,
	"id":		({ "yannian dan","dan" }),
	"eat_msg":	CYN"$N服下一颗延年养精丹，顿时感觉精血充足。"NOR,
	"long":		CYN"这是一颗用来大量恢复精血的丹药。"NOR,
	"busy":		12,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "chan tui","chan tui","chan tui","he ye","he ye","xiong huang" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	260,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
"fuling wan"	: ([	// 茯苓补气丸
	"name":		GRN"茯苓补气丸"NOR,
	"id":		({ "fuling wan","wan" }),
	"eat_msg":	GRN"$N服下一颗茯苓补气丸，顿时感觉气血充足。"NOR,
	"long":		GRN"这是一颗用来大量恢复气血的丹药。"NOR,
	"busy":		12,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "fu ling","fu ling","fu ling","mu gua","mu gua","xiong huang" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	260,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
"danggui dan"	: ([	// 当归续精丹
	"name":		HIC"当归续精丹"NOR,
	"id":		({ "danggui dan","danggui" }),
	"eat_msg":	HIC"$N服下一颗当归续精丹，顿时感觉精力充沛。"NOR,
	"long":		HIC"这是一颗用来大量恢复精力的丹药。"NOR,
	"busy":		12,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "dang gui","dang gui","dang gui","tian qi","zhu ye","zhu ye" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	260,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
"chuanbei wan"	: ([	// 川贝内息丸
	"name":		HIG"川贝内息丸"NOR,
	"id":		({ "chuanbei wan","wan" }),
	"eat_msg":	HIG"$N服下一颗川贝内息丸，顿时感觉内力充沛。"NOR,
	"long":		HIG"这是一颗用来大量恢复内力的丹药。"NOR,
	"busy":		12,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "chuan bei","chuan bei","chuan bei","mu gua","mu gua","zhu ye" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	260,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
"chantui yao"	: ([	// 蝉蜕金疮药
	"name":		YEL"蝉蜕金疮药"NOR,
	"id":		({ "chantui yao","yao","chantui" }),
	"eat_msg":	YEL"$N敷上一副蝉蜕金疮药，顿时感觉伤势好了不少。"NOR,
	"long":		YEL"这是一副用来疗伤的神药。"NOR,
	"busy":		102,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "chan tui","chan tui","fang feng","fang feng","gou qi","gou qi" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	260,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
"huoxue dan"	: ([	// 活血疗精丹
	"name":		HIY"活血疗精丹"NOR,
	"id":		({ "huoxue dan","dan" }),
	"eat_msg":	HIY"$N服下一颗活血疗精丹，顿时感觉精血不再流失。"NOR,
	"long":		HIY"这是一颗用来疗伤的丹药。"NOR,
	"busy":		102,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "bai zhi","bai zhi","chai hu","chai hu","chuan bei","chuan bei" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	260,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
"jiedu wan"	: ([	// 解毒丸
	"name":		BLU"解毒丸"NOR,
	"id":		({ "jiedu wan","wan" }),
	"eat_msg":	BLU"$N服下一颗解毒丸，感觉毒性减弱了不少。"NOR,
	"long":		BLU"这是一颗用能减弱大部分毒物的毒性的丹药。"NOR,
	"busy":		103,
	"worktime":	0,
	"neili":	1000,
	"yaocai":	({ "chan tui","chan tui","chan tui","tian qi","tian qi","tian qi" }),
	"need_lvl":	160,
	"gain_lvl":	240,
	"win_lvl":	300,
	"max_lvl":	300,
	"drug_lvl":	4, ]),
	
"huangqi dan"	: ([	// 黄芪内息丹
	"name":		HIG"黄芪内息丹"NOR,
	"id":		({ "huangqi dan","dan" }),
	"eat_msg":	HIG"$N服下一颗黄芪内息丹，顿时感觉内力似乎突破了极限。"NOR,
	"long":		HIG"这是一颗用来增加最大内力的丹药。"NOR,
	"busy":		150,
	"worktime":	0,
	"neili":	2000,
	"yaocai":	({ "dang gui","huang qi","huang qi","huang qi","zhu ye","zhu ye" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	450,
	"max_lvl":	380,
	"drug_lvl":	3, ]),
"jinyin dan"	: ([	// 金银续精丹
	"name":		HIC"金银续精丹"NOR,
	"id":		({ "jinyin dan","dan" }),
	"eat_msg":	HIC"$N服下一颗金银续精丹，顿时感觉精力似乎突破了极限。"NOR,
	"long":		HIC"这是一颗用来增加最大精力的丹药。"NOR,
	"busy":		150,
	"worktime":	0,
	"neili":	2000,
	"yaocai":	({ "chuan bei","jinyin hua","jinyin hua","jinyin hua","xiong huang","xiong huang" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	450,
	"max_lvl":	380,
	"drug_lvl":	3, ]),
"niuhuang wan"	: ([	// 牛黄解毒丸
	"name":		YEL"牛黄解毒丸"NOR,
	"id":		({ "niuhuang wan","wan" }),
	"eat_msg":	YEL"$N服下一颗牛黄解毒丸，顿时感觉体内的毒素大大减少。"NOR,
	"long":		YEL"这是一颗用来解毒的神药。"NOR,
	"busy":		103,
	"worktime":	0,
	"neili":	2000,
	"yaocai":	({ "chan tui","chan tui","niu huang","niu huang","niu huang","tian qi" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	420,
	"max_lvl":	380,
	"drug_lvl":	3, ]),
"shentong dan"	: ([	// 神通丹
	"name":		MAG"神通丹"NOR,
	"id":		({ "shentong dan","dan" }),
	"eat_msg":	MAG"$N服下一颗神通丹，顿时感觉体内的潜能被激发，战斗的能力大大增强了。"NOR,
	"long":		MAG"这是一颗用来提升战斗力的神药。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	2000,
	"yaocai":	({ "fu ling","fu ling","tianhua fen","tianhua fen","tianhua fen","xiong huang" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	420,
	"max_lvl":	380,
	"drug_lvl":	3, ]),
"huti wan"	: ([	// 护体丸
	"name":		HIM"护体丸"NOR,
	"id":		({ "huti wan","wan" }),
	"eat_msg":	HIM"$N服下一颗护体丸，顿时感觉体内的潜能被激发，防御的能力大大增强了。"NOR,
	"long":		HIM"这是一颗用来提升防御力的神药。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	2000,
	"yaocai":	({ "dang gui","dang gui","jinyin hua","jinyin hua","jinyin hua","zhu ye" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	420,
	"max_lvl":	380,
	"drug_lvl":	3, ]),
"tianxin dan"	: ([	// 天心增精丹
	"name":		CYN"天心增精丹"NOR,
	"id":		({ "tianxin dan","dan" }),
	"eat_msg":	CYN"$N服下一颗天心增精丹，顿时感觉精血突破了极限。"NOR,
	"long":		CYN"这是一颗用来提升精血的神药。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	2000,
	"yaocai":	({ "chan tui","chan tui","fang feng","niu huang","niu huang","niu huang" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	420,
	"max_lvl":	380,
	"drug_lvl":	3, ]),
"xiantian wan"	: ([	// 先天养气丸
	"name":		GRN"先天养气丸"NOR,
	"id":		({ "xiantian wan","wan" }),
	"eat_msg":	GRN"$N服下一颗先天养气丸，顿时感觉气血突破了极限。"NOR,
	"long":		GRN"这是一颗用来提升气血的神药。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	2000,
	"yaocai":	({ "chuan bei","chuan bei","huang qi","huang qi","huang qi","tian qi" }),
	"need_lvl":	240,
	"gain_lvl":	320,
	"win_lvl":	420,
	"max_lvl":	380,
	"drug_lvl":	3, ]),

"shenli wan"	: ([	// 龙虎神力丸
	"name":		MAG"龙虎神力丸"NOR,
	"id":		({ "shenli wan","wan" }),
	"eat_msg":	MAG"$N服下一颗龙虎神力丸，顿时感觉全身充满力量。"NOR,
	"long":		MAG"这是一颗用来提升臂力的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	3000,
	"yaocai":	({ "chuan bei","hu gu","hu gu","hu gu","niu huang","niu huang" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"kaitian dan"	: ([	// 首乌开天丹
	"name":		HIW"首乌开天丹"NOR,
	"id":		({ "kaitian wan","wan" }),
	"eat_msg":	HIW"$N服下一颗首乌开天丹，顿时感觉全身充满智慧。"NOR,
	"long":		HIW"这是一颗用来提升智力的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	3000,
	"yaocai":	({ "dang gui","huang qi","huang qi","he shouwu","he shouwu","he shouwu" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"yijing dan"	: ([	// 豹胎易筋丹
	"name":		MAG"豹胎易筋丹"NOR,
	"id":		({ "yijing dan","dan" }),
	"eat_msg":	MAG"$N服下一颗豹胎易筋丹，顿时有一种脱胎换骨的感觉。"NOR,
	"long":		MAG"这是一颗用来提升根骨的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	3000,
	"yaocai":	({ "bao tai","bao tai","bao tai","fu ling","tianhua fen","tianhua fen" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"feisheng dan"	: ([	// 藿香飞升丹
	"name":		HIY"藿香飞升丹"NOR,
	"id":		({ "feisheng dan","dan" }),
	"eat_msg":	HIY"$N服下一颗藿香飞升丹，顿时有一种身轻入雁的感觉。"NOR,
	"long":		HIY"这是一颗用来提升身法的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	3000,
	"yaocai":	({ "chan tui","huo xiang","huo xiang","huo xiang","jinyin hua","jinyin hua" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"fuyun dan"	: ([	// 天仙福运丹
	"name":		HIM"天仙福运丹"NOR,
	"id":		({ "fuyun dan","dan" }),
	"eat_msg":	HIM"$N服下一颗天仙福运丹，顿时有一种幸福的感觉。"NOR,
	"long":		HIM"这是一颗用来提升福运的仙丹。"NOR,
	"busy":		109,
	"worktime":	15,
	"neili":	3000,
	"yaocai":	({ "bai zhi","fu ling","fu ling","huo xiang","huo xiang","huo xiang" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"yuling san"	: ([	// 玉灵补气散
	"name":		GRN"玉灵补气散"NOR,
	"id":		({ "yuling san","san" }),
	"eat_msg":	GRN"$N服下一颗玉灵补气散，顿时感觉气血和内息都恢复到最好的状态。"NOR,
	"long":		GRN"这是一颗用来完全恢复气血和内息的仙丹。"NOR,
	"busy":		103,
	"worktime":	0,
	"neili":	3000,
	"yaocai":	({ "bai zhi","bao tai","bao tai","niu huang","niu huang","niu huang" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"yuzheng dan"	: ([	// 玉真养精丹
	"name":		CYN"玉真养精丹"NOR,
	"id":		({ "yuzheng dan","dan" }),
	"eat_msg":	CYN"$N服下一颗玉真养精丹，顿时感觉精血和精力都恢复到最好的状态。"NOR,
	"long":		CYN"这是一颗用来完全恢复精血和精力的仙丹。"NOR,
	"busy":		103,
	"worktime":	0,
	"neili":	3000,
	"yaocai":	({ "gou qi","hu gu","hu gu","huang qi","huang qi","huang qi" }),
	"need_lvl":	320,
	"gain_lvl":	390,
	"win_lvl":	520,
	"max_lvl":	450,
	"drug_lvl":	2, ]),

"honghua dan"	: ([	// 红花神通丹
	"name":		MAG"红花神通丹"NOR,
	"id":		({ "honghua dan","dan" }),
	"eat_msg":	MAG"$N服下一颗红花神通丹，激发出身体里所有的潜能，攻击力大大提高。"NOR,
	"long":		MAG"这是一颗能够大量提升攻击力的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	4000,
	"yaocai":	({ "gou qi","jinyin hua","jinyin hua","zang honghua","zang honghua","zang honghua" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	600,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"renshen wan"	: ([	// 人参护体丸
	"name":		HIM"人参护体丸"NOR,
	"id":		({ "renshen wan","wan" }),
	"eat_msg":	HIM"$N服下一颗人参护体丸，激发出身体里所有的潜能，防御力大大提高。"NOR,
	"long":		HIM"这是一颗能够大量提升防御力的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	4000,
	"yaocai":	({ "chai hu","ren shen","ren shen","ren shen","tianhua fen","tianhua fen" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	600,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"tijing dan"	: ([	// 红花提精丹
	"name":		RED"红花提精丹"NOR,
	"id":		({ "tijing dan","dan" }),
	"eat_msg":	RED"$N服下一颗红花提精丹，激发出身体里所有的潜能，精血大量提升。"NOR,
	"long":		RED"这是一颗能够大量提升精血的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	4000,
	"yaocai":	({ "chan tui","chan tui","he shouwu","he shouwu","zang honghua","zang honghua" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	600,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"yangqi wan"	: ([	// 人参养气丸
	"name":		YEL"人参养气丸"NOR,
	"id":		({ "yangqi dan","dan" }),
	"eat_msg":	YEL"$N服下一颗红花提精丹，激发出身体里所有的潜能，气血大量提升。"NOR,
	"long":		YEL"这是一颗能够大量提升气血的仙丹。"NOR,
	"busy":		103,
	"worktime":	12,
	"neili":	4000,
	"yaocai":	({ "bai zhi","bai zhi","bao tai","bao tai","ren shen","ren shen" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	600,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"qudu wan"	: ([	// 天心去毒丹
	"name":		HIB"天心去毒丹"NOR,
	"id":		({ "qudu wan","wan" }),
	"eat_msg":	HIB"$N服下一颗天心去毒丹，身体里所有的毒素都被清除了。"NOR,
	"long":		HIB"这是一颗能够去除所有毒素的仙丹。"NOR,
	"busy":		130,
	"worktime":	0,
	"neili":	4000,
	"yaocai":	({ "niu huang","niu huang","hu gu","xiong huang","zang honghua","zang honghua" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	550,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"xuming badan"	: ([	// 续命八丹
	"name":		HIR"续命八丹"NOR,
	"id":		({ "xuming badan","badan" }),
	"eat_msg":	HIR"$N服下一颗续命八丹，把性命掉了回来。"NOR,
	"long":		HIR"这是一颗能够恢复身体最好状态并大大降低毒素的仙丹。"NOR,
	"busy":		150,
	"worktime":	0,
	"neili":	4000,
	"yaocai":	({ "bao tai","he shouwu","huang qi","huo xiang","niu huang","ren shen","xiong huang","zang honghua" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	650,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
"yulu san"	: ([	// 玉露续精散
	"name":		HIC"玉露续精散"NOR,
	"id":		({ "yulu san","san" }),
	"eat_msg":	HIC"$N服下一颗玉露续精散，顿时感觉精力超越了极限。"NOR,
	"long":		HIC"这是一颗大量提升最大精力的仙丹。"NOR,
	"busy":		190,
	"worktime":	0,
	"neili":	4000,
	"yaocai":	({ "jinyin hua","jinyin hua","he shouwu","he shouwu","ren shen","zang honghua" }),
	"need_lvl":	360,
	"gain_lvl":	390,
	"win_lvl":	650,
	"max_lvl":	450,
	"drug_lvl":	2, ]),
	
"shadan san"	: ([	// 鲨胆田七散
	"name":		HIR"鲨胆田七散"NOR,
	"id":		({ "shadan san","san" }),
	"eat_msg":	HIR"$N服下一颗鲨胆田七散，感觉原来的所有烦恼都不复存在了。"NOR,
	"long":		HIR"这是一副能够去除所有毒素，并恢复身体最好状态的仙药。"NOR,
	"busy":		160,
	"worktime":	0,
	"neili":	5000,
	"yaocai":	({ "sha dan","sha dan","sha dan","tian qi","tian qi","zang honghua" }),
	"need_lvl":	390,
	"gain_lvl":	500,
	"win_lvl":	750,
	"max_lvl":	500,
	"drug_lvl":	1, ]),
"puti zi"	: ([	// 菩提雪莲子
	"name":		HIW"菩提雪莲子"NOR,
	"id":		({ "puti zi","zi" }),
	"eat_msg":	HIW"$N服下一颗菩提雪莲子，顿时感觉内力超越了极限。"NOR,
	"long":		HIW"这是一颗能够大量提高最大内力的仙丹。"NOR,
	"busy":		190,
	"worktime":	0,
	"neili":	5000,
	"yaocai":	({ "ju geng","ju geng","xuelian zi","xuelian zi","xuelian zi","zang honghua" }),
	"need_lvl":	390,
	"gain_lvl":	500,
	"win_lvl":	800,
	"max_lvl":	500,
	"drug_lvl":	1, ]),
"wudi dan"	: ([	// 无敌神通丹
	"name":		MAG"无敌神通丹"NOR,
	"id":		({ "wudi dan","dan" }),
	"eat_msg":	MAG"$N服下一颗无敌神通丹，顿时激发出全身超越极限的潜能，攻防都达到一个新的境界。"NOR,
	"long":		MAG"这是一颗能够极大提升攻防的仙丹。"NOR,
	"busy":		103,
	"worktime":	15,
	"neili":	5000,
	"yaocai":	({ "bao tai","bao tai","hu gu","hu gu","sha dan","xuelian zi" }),
	"need_lvl":	390,
	"gain_lvl":	500,
	"win_lvl":	800,
	"max_lvl":	500,
	"drug_lvl":	1, ]),
"huanhun dan"	: ([	// 九转还魂丹
	"name":		BLU"九转还魂丹"NOR,
	"id":		({ "huanhun dan","dan" }),
	"eat_msg":	BLU"$N服下一颗九转还魂丹，顿时有一种灵魂附体的感觉。"NOR,
	"long":		BLU"这是一颗传说中神仙才能炼制的丹药，有回魂转世之功效。"NOR,
	"busy":		640,
	"worktime":	0,
	"neili":	5000,
	"yaocai":	({ "bao tai","he shouwu","hu gu","huo xiang","niu huang","ren shen","sha dan","xuelian zi","zang honghua" }),
	"need_lvl":	390,
	"gain_lvl":	500,
	"win_lvl":	1299,
	"max_lvl":	500,
	"drug_lvl":	1, ]),
]);


void do_recover(object ob)
{
	int i;
	mapping skills, learned;
	string *sk;

	skills = ob->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		ob->improve_skill(sk[0], 1, 1);
		learned = ob->query_learned();
		learned[sk[0]]--;
		foreach (string skill in sk) {
			i = (skills[skill]+1)*(skills[skill]+1);
			if ((learned[skill]+=i/2) > i) {
				skills[skill]++;
				learned[skill] -= i;
			}
		}
	}

	i = ob->query("combat_exp")/199+1;
	if (i > 30000) i = 30000;
	if (i < 150) i = 0;
	ob->add("combat_exp", i);
	ob->add("shen", ob->query("shen")/9);
	i = ob->query("potential");
	i += i/3;
	if (i > ob->query("max_pot")) i = ob->query("max_pot");
		ob->set("potential", i);
}

int do_drug(object me,string yao,int lvl,int lower)
{
	int i;
	mapping mp;
	string * mpk;
	int * mpv;
	
	switch ( yao ) {
		case "yangjing dan":	// 养精丹
			me->add("jing", 600 * lvl/100);
			break;
		case "buqi wan":	// 补气丸
			me->add("qi", 800 * lvl/100);
			break;
		case "xujing dan":	// 续精丹	
			me->add("jingli", 600 * lvl/100);
			break;
		case "neixi wan":	// 内息丸
			me->add("neili", 800 * lvl/100);
			break;
		case "bushi dan":	// 补食丹
			me->add("food", 100 * lvl/100);
			break;
		case "bushui wan":	// 补水丸
			me->add("water", 100 * lvl/100);
			break;
		case "jinchuang yao":	// 金疮药
			me->add("eff_qi", 500 * lvl/100);
			break;
		case "liaojing dan":	// 疗精丹
			me->add("eff_jing", 300 * lvl/100);
			break;
			
		case "zhengqi dan":	// 正气丹
			me->add("shen", 8000 * lvl/100);
			break;
		case "xieqi wan":	// 邪气丸
			me->add("shen", -8000 * lvl/100);
			break;
		case "dali wan":	// 大力丸
			i = 6 * lvl/100;
			me->add_temp("apply/strength",i);
			me->add_temp("drug_apply/strength",i);
			break;
		case "lingxi dan":	// 灵犀丹
			i = 6 * lvl/100;
			me->add_temp("apply/intelligence",i);
			me->add_temp("drug_apply/intelligence",i);
			break;
		case "huangu wan":	// 换骨丸
			i = 6 * lvl/100;
			me->add_temp("apply/constitution",i);
			me->add_temp("drug_apply/constitution",i);
			break;
		case "qingshen dan":	// 轻身丹
			i = 6 * lvl/100;
			me->add_temp("apply/dexerity",i);
			me->add_temp("drug_apply/dexerity",i);
			break;
			
		case "yannian dan":	// 延年养精丹
			me->add("jing", 1800 * lvl/100);
			break;
		case "fuling wan":	// 茯苓补气丸
			me->add("qi", 3000 * lvl/100);
			break;
		case "danggui dan":	// 当归续精丹
			me->add("jingli", 1800 * lvl/100);
			break;
		case "chuanbei wan":	// 川贝内息丸
			me->add("neili", 3000 * lvl/100);
			break;
		case "chantui yao":	// 蝉蜕金疮药
			me->add("eff_qi", 1200 * lvl/100);
			break;
		case "huoxue dan":	// 活血疗精丹
			me->add("eff_jing", 800 * lvl/100);
			break;
		case "jiedu wan": 	// 解毒丸
			mp = me->query_conditions_by_type("poison");
			if(!mapp(mp)) break;
			mpk = keys(mp);
			mpv = values(mp);
			for(i=0;i<sizeof(mp);i++) {
				if( mpk[i] == "xx_poison" ) continue;
				if( mpk[i] == "man_poison" ) continue;
				me->add_condition(mpk[i],-(mpv[i]/5 * lvl/100));
			}
			break;

		case "huangqi dan":	// 黄芪内息丹
			me->add("max_neili", 2 * lvl/100);
			break;
		case "jinyin dan":	// 金银续精丹
			me->add("eff_jingli", 2 * lvl/100);
			break;
		case "niuhuang wan":	// 牛黄解毒丸
			mp = me->query_conditions_by_type("poison");
			if(!mapp(mp)) break;
			mpk = keys(mp);
			mpv = values(mp);
			for(i=0;i<sizeof(mp);i++) {
				if( mpk[i] == "xx_poison" ) continue;
				if( mpk[i] == "man_poison" ) continue;
				me->add_condition(mpk[i],-(mpv[i]/3 * lvl/100));
			}
			break;
		case "shentong dan": 	// 神通丹
			i = me->query_skill("force",1)/4 * lvl/100;
			me->add_temp("apply/attack",i);
			me->add_temp("drug_apply/attack",i);
			break;
		case "huti wan":	// 护体丸
			i = me->query_skill("parry",1)/4 * lvl/100;
			me->add_temp("apply/parry",i);
			me->add_temp("drug_apply/parry",i);
			break;
		case "tianxin dan":	// 天心增精丹
			i = 500 * lvl/100;
			me->add_temp("apply/jing",i);
			me->add_temp("drug_apply/jing",i);
			break;
		case "xiantian wan":	// 先天养气丸
			i = 800 * lvl/100;
			me->add_temp("apply/qi",i);
			me->add_temp("drug_apply/qi",i);
			break;

		case "shenli wan":	// 龙虎神力丸
			if(lower)
				i = 8 * lvl/100;
			else
				i = 30 * lvl/100;
			me->add_temp("apply/strength",i);
			me->add_temp("drug_apply/strength",i);
			break;		
		case "kaitian dan":	// 首乌开天丹
			if(lower)
				i = 8 * lvl/100;
			else
				i = 30 * lvl/100;
			me->add_temp("apply/intelligence",i);
			me->add_temp("drug_apply/intelligence",i);
			break;
		case "yijing dan":	// 豹胎易筋丹
			if(lower)
				i = 8 * lvl/100;
			else
				i = 30 * lvl/100;
			me->add_temp("apply/constitution",i);
			me->add_temp("drug_apply/constitution",i);
			break;
		case "feisheng dan":	// 藿香飞升丹
			if(lower)
				i = 8 * lvl/100;
			else
				i = 30 * lvl/100;
			me->add_temp("apply/dexerity",i);
			me->add_temp("drug_apply/dexerity",i);
			break;
		case "fuyun dan":	// 天仙福运丹
			if(lower)
				i = 5 * lvl/100;
			else
				i = 20 * lvl/100;
			me->add_temp("apply/karma",i);
			me->add_temp("drug_apply/karma",i);
			break;
		case "yuling san":	// 玉灵补气散
			if(lower || lvl<random(80)) {
				me->add("eff_qi", 2000 * lvl/100);
				me->add("qi",3000 * lvl/100);
				if( me->query("neili") < me->query("max_neili") ) {
					me->add("neili",3000 * lvl/100);
					if( me->query("neili") < me->query("max_neili") )
						me->set("neili",me->query("max_neili"));
				}
				break;
			}
			me->add("eff_qi",99999);
			me->add("qi",99999);
			if( me->query("neili") < me->query("max_neili") )
				me->set("neili",me->query("max_neili"));
			break;
		case "yuzheng dan":	// 玉真养精丹
			if(lower || lvl<random(80)) {
				me->add("eff_jing", 1500 * lvl/100);
				me->add("jing",2500 * lvl/100);
				if( me->query("jingli") < me->query("eff_jingli") ) {
					me->add("jingli",2500 * lvl/100);
					if( me->query("jingli") < me->query("eff_jingli") )
						me->set("jingli",me->query("eff_jingli"));
				}
				break;
			}
			me->add("eff_jing",99999);
			me->add("jing",99999);
			if( me->query("jing") < me->query("eff_jingli") )
				me->set("jingli",me->query("eff_jingli"));
			break;

		case "honghua dan":	// 红花神通丹
			if(lower)
				i = me->query_skill("force",1)*2/7 * lvl/100;
			else
				i = me->query_skill("force",1)/2 * lvl/100;
			me->add_temp("apply/attack",i);
			me->add_temp("drug_apply/attack",i);
			break;
		case "renshen wan":	// 人参护体丸
			if(lower)
				i = me->query_skill("parry",1)*2/7 * lvl/100;
			else
				i = me->query_skill("parry",1)/2 * lvl/100;
			me->add_temp("apply/parry",i);
			me->add_temp("drug_apply/parry",i);
			break;
		case "tijing dan":	// 红花提精丹
			if(lower)
				i = 700 * lvl/100;
			else
				i = 2000 * lvl/100;
			me->add_temp("apply/jing",i);
			me->add_temp("drug_apply/jing",i);
			break;
		case "yangqi wan": 	// 人参养气丸
			if(lower)
				i = 1000 * lvl/100;
			else
				i = 3000 * lvl/100;
			me->add_temp("apply/qi",i);
			me->add_temp("drug_apply/qi",i);
			break;
		case "qudu wan":	// 天心去毒丹
			if(lower || lvl<random(80)) {
				mp = me->query_conditions_by_type("poison");
				if(!mapp(mp)) break;
				mpk = keys(mp);
				mpv = values(mp);
				for(i=0;i<sizeof(mp);i++) 
					me->add_condition(mpk[i],-(mpv[i]/2 * lvl/100));
				break;
			}
			mp = me->clear_conditions_by_type("poison");
			break;
		case "xuming badan": 	// 续命八丹
			if(lower || lvl<random(80)) {
				me->add("eff_qi", 2000 * lvl/100);
				me->add("qi",3000 * lvl/100);
				if( me->query("neili") < me->query("max_neili") ) {
					me->add("neili",3000 * lvl/100);
					if( me->query("neili") < me->query("max_neili") )
						me->set("neili",me->query("max_neili"));
				}
				
				me->add("eff_jing", 1800 * lvl/100);
				me->add("jing",2500 * lvl/100);
				if( me->query("jingli") < me->query("eff_jingli") ) {
					me->add("jingli",2500 * lvl/100);
					if( me->query("jingli") < me->query("eff_jingli") )
						me->set("jingli",me->query("eff_jingli"));
				}
				
				mp = me->query_conditions_by_type("poison");
				mpk = keys(mp);
				mpv = values(mp);
				for(i=0;i<sizeof(mp);i++)
					me->add_condition(mpk[i],-(mpv[i]/3 * lvl/100));
				break;
			}
			
			me->add("eff_qi",99999);
			me->add("qi",99999);
			if( me->query("neili") < me->query("max_neili") )
				me->set("neili",me->query("max_neili"));
			me->add("eff_jing",99999);
			me->add("jing",99999);
			if( me->query("jingli") < me->query("eff_jingli") )
				me->set("jingli",me->query("eff_jingli"));
				
			mp = me->query_conditions_by_type("poison");
			if(!mapp(mp)) break;
			mpk = keys(mp);
			mpv = values(mp);
			for(i=0;i<sizeof(mp);i++)
				me->add_condition(mpk[i],-(mpv[i]/2 * lvl/100));
			break;
		case "yulu san":	// 玉露续精散
			if(lower)
				me->add("eff_jingli", 5 * lvl/100);
			else
				me->add("eff_jingli",20 * lvl/100);
			break;
	
		case "shadan san":	// 鲨胆田七散
			if(lower || lvl<random(80)) {
				me->add("eff_qi", 3000 * lvl/100);
				me->add("qi",5000 * lvl/100);
				if( me->query("neili") < me->query("max_neili") )
					me->add("neili",5000 * lvl/100);
				
				me->add("eff_jing", 2500 * lvl/100);
				me->add("jing",3500 * lvl/100);
				if( me->query("jingli") < me->query("eff_jingli") )
					me->add("jingli",3500 * lvl/100);
				
				mp = me->query_conditions_by_type("poison");
				if(!mapp(mp)) break;
				mpk = keys(mp);
				mpv = values(mp);
				for(i=0;i<sizeof(mp);i++)
					me->add_condition(mpk[i],-(mpv[i]/2 * lvl/100));
				break;
			}
			
			me->add("eff_qi",99999);
			me->add("qi",99999);
			me->add("neili",99999);
			me->add("eff_jing",99999);
			me->add("jing",99999);
			me->add("jingli",99999);				
			me->clear_conditions_by_type("poison");
			break;
		case "puti zi":		// 菩提雪莲子
			if(lower)
				me->add("max_neili", 8 * lvl/100);
			else
				me->add("max_neili",30 * lvl/100);
			break;
		case "wudi dan":	// 无敌神通丹
			if(lower)
				i = me->query_skill("force",1)/3 * lvl/100;
			else
				i = me->query_skill("force",1)*2/3 * lvl/100;
			me->add_temp("apply/attack",i);
			me->add_temp("drug_apply/attack",i);
			
			if(lower)
				i = me->query_skill("parry",1)/3 * lvl/100;
			else
				i = me->query_skill("parry",1)*2/3 * lvl/100;
			me->add_temp("apply/parry",i);
			me->add_temp("drug_apply/parry",i);
			break;
		case "huanhun dan": 	// 九转还魂丹
			if(lower || lvl<random(90)) {
				i = me->query("combat_exp")/120+1;
				if (i > 30000) i = 30000;
				if (i < 150) i = 0;
				me->add("combat_exp", i * lvl/100);
				break;
			}
			do_recover(me);
			break;
						
		default:
			return 0;
	}
	
	if( me->query("eff_jing") > me->query("max_jing") )
		me->set("eff_jing",me->query("max_jing"));
	i = me->query("eff_jing") + me->query_temp("apply/jing");
	if( me->query("jing") > i ) me->set("jing",i);
	
	if( me->query("eff_qi") > me->query("max_qi") )
		me->set("eff_qi",me->query("max_qi"));
	i = me->query("eff_qi") + me->query_temp("apply/qi");
	if( me->query("qi") > i ) me->set("qi",i);
	
	if( me->query("jingli") > me->query("eff_jingli")*2 )
		me->set("jingli",me->query("eff_jingli")*2);
	if( me->query("neili") > me->query("max_neili")*2 )
		me->set("neili",me->query("max_neili")*2);
		
	if( me->query("food") > me->max_food_capacity() )
		me->set("food",me->max_food_capacity());
	if( me->query("water") > me->max_water_capacity() )
		me->set("water",me->max_water_capacity());
		
	return 1;
}
