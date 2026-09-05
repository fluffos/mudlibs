// cjgreward.h 藏经阁任务奖励文件
// seagate@pkuxkx by 2011.02.17

//技能兑奖列表中默认的三个值
int *minlevel=({300, 800, 1200});
int *maxlevel=({800, 1200, 1600});
int *point=({20, 25,30});

//最低级别(minlevel)默认为300，800，1200，最高级别（maxlevel）默认为800，1200，1600
//积分（point）消耗默认是20，25，30
//武功类技能 对应 武功秘籍库房
mapping kungfu_skill=
(["taiji-jian" : 
	([ "family" : "武当派",
		 "name" : "太极剑法",
		 "preskill" : "taiji-quan"]),
  "taiji-quan" : 
	([ "family" : "武当派",
		 "name" : "太极拳"]),
  "taiji-zhao" : 
	([ "family" : "武当派",
		 "name" : "太极爪",
		 "preskill" : "taiji-quan"]),
  "taiji-dao" : 
	([ "family" : "武当派",
		 "name" : "太极刀法",
		 "preskill" : "taiji-quan"]),
  "taiji-shengong" : 
	([ "family" : "武当派",
		 "name" : "太极神功",
		 "point" : ({200, 300, 400})]),
  "yizhi-chan" : 
	([ "family" : "少林派",
		 "name" : "一指禅" ]),
  "luohan-quan" : 
	([ "family" : "少林派",
		 "name" : "罗汉拳" ]),
  "zui-gun" : 
	([ "family" : "少林派",
		 "name" : "少林醉棍" ]),
  "daweituo-chu" : 
	([ "family" : "少林派",
		 "name" : "大韦陀杵",
		 "mutexskill" : ({"riyue-bian", "ranmu-daofa"}) ]),
  "riyue-bian" : 
	([ "family" : "少林派",
		 "name" : "日月鞭法",
		 "mutexskill" : ({"daweituo-chu", "ranmu-daofa"}) ]),
  "ranmu-daofa" : 
	([ "family" : "少林派",
		 "name" : "燃木刀法",
		 "mutexskill" : ({"daweituo-chu", "riyue-bian"}) ]),
  "hunyuan-yiqi" : 
	([ "family" : "少林派",
		 "name" : "混元一气功",
		 "point" : ({200, 300, 400}) ]),
  "yijin-jing" : 
	([ "family" : "少林派",
		 "name" : "易筋经神功",
		 "point" : ({200, 300, 400}) ]),
  "jingang-buhuai" : 
	([ "family" : "少林派",
		 "name" : "金刚不坏神功",
		 "point" : ({150, 300, 450}) ]),
  "tiangang-zhi" : 
	([ "family" : "峨嵋派",
		 "name" : "天罡指" ]),
  "jieshou-jiushi" : 
	([ "family" : "峨嵋派",
		 "name" : "截手九式" ]),
  "fuliu-jian" : 
	([ "family" : "峨嵋派",
		 "name" : "回风拂柳剑" ]),
  "yanxing-dao" : 
	([ "family" : "峨嵋派",
		 "name" : "雁行刀" ]),
  "pili-dan" : 
	([ "family" : "峨嵋派",
		 "name" : "霹雳弹" ]),
  "linji-zhuang" : 
	([ "family" : "峨嵋派",
		 "name" : "临济十二庄",
		 "point" : ({200, 300, 400}) ]),
  "xianglong-zhang" : 
	([ "family" : "丐帮",
		 "name" : "降龙十八掌" ]),
  "dagou-bang" : 
	([ "family" : "丐帮",
		 "name" : "打狗棒法" ]),
  "huntian-qigong" : 
	([ "family" : "丐帮",
		 "name" : "混天气功",
		 "point" : ({200, 300, 400}) ]),
  "huashan-jianfa" : 
	([ "family" : "华山派",
		 "name" : "华山剑法" ]),
  "dugu-jiujian" : 
	([ "family" : "华山派",
		 "name" : "独孤九剑" ]),
  "fanliangyi-dao" : 
	([ "family" : "华山派",
		 "name" : "反两仪刀法" ]),
  "hunyuan-zhang" : 
	([ "family" : "华山派",
		 "name" : "混元掌" ]),
  "huashan-neigong" : 
	([ "family" : "华山派",
		 "name" : "华山内功",
		 "point" : ({200, 300, 400}) ]),
  "zixia-shengong" : 
	([ "family" : "华山派",
		 "name" : "紫霞神功",
		 "point" : ({200, 300, 400}) ]),
  "xueshan-jianfa" : 
	([ "family" : "雪山派",
		 "name" : "雪山剑法",
		 "preskill" : "xueshan-neigong" ]),
  "jinwu-daofa" : 
	([ "family" : "雪山派",
		 "name" : "金乌刀法",
		 "preskill" : "xueshan-neigong" ]),
  "lingxiao-quan" : 
	([ "family" : "雪山派",
		 "name" : "凌霄拳法",
		 "preskill" : "xueshan-neigong" ]),
  "xueshan-neigong" : 
	([ "family" : "雪山派",
		 "name" : "雪山内功",
		 "point" : ({200, 300, 400}) ]),
  "quanzhen-jian" : 
	([ "family" : ({"全真派","古墓派"}),
		 "name" : "全真剑法" ]),
  "tonggui-jian" : 
	([ "family" : "全真派",
		 "name" : "同归剑法" ]),
  "kongming-quan" : 
	([ "family" : "全真派",
		 "name" : "空明拳",
		 "preskill" : "xiantian-gong" ]),
  "yiyang-zhi" : 
	([ "family" : ({"全真派","天龙寺"}),
		 "name" : "一阳指" ]),
  "qixing-array" : 
	([ "family" : "全真派",
		 "name" : "北斗七星阵",
		 "minlevel" : ({ 100, 600, 1200 }),
		 "maxlevel" : ({ 600, 1200, 1800 }),
		 "point" : ({250, 400, 550}),
		 "preskill" : "xiantian-gong" ]),
  "tiangang-beidou" : 
	([ "family" : "全真派",
		 "name" : "天罡北斗阵",
		 "minlevel" : ({ 100, 600, 1200 }),
		 "maxlevel" : ({ 600, 1200, 1800 }),
		 "point" : ({250, 400, 550}),
		 "preskill" : "xiantian-gong" ]),
  "xiantian-gong" : 
	([ "family" : "全真派",
		 "name" : "先天功",
		 "point" : ({200, 300, 400}) ]),
  "jiulong-bian" : 
	([ "family" : "天地会",
		 "name" : "九龙鞭" ]),
  "danxin-jian" : 
	([ "family" : "天地会",
		 "name" : "碧血丹心剑" ]),
  "fulong-shou" : 
	([ "family" : "天地会",
		 "name" : "乾坤伏龙手" ]),
  "yunlong-zhua" : 
	([ "family" : "天地会",
		 "name" : "云龙爪" ]),
  "cangming-gong" : 
	([ "family" : "天地会",
		 "name" : "浩气苍冥功",
		 "point" : ({200, 300, 400}) ]),
  "lingbo-weibu" : 
	([ "family" : "天龙寺",
		 "name" : "凌波微步" ]),
  "liumai-shenjian" : 
	([ "family" : "天龙寺",
		 "name" : "六脉神剑" ]),
  "feihua-zhuyue" : 
	([ "family" : "天龙寺",
		 "name" : "飞花逐月" ]),
  "beiming-shengong" : 
	([ "family" : "天龙寺",
		 "name" : "北冥神功",
		 "point" : ({200, 300, 400}) ]),
  "hamagong" : 
	([ "family" : "白驼山",
		 "name" : "蛤蟆功",
		 "point" : ({200, 300, 400}) ]),
  "lingshe-zhangfa" : 
	([ "family" : "白驼山",
		 "name" : "灵蛇杖法" ]),
  "shexing-diaoshou" : 
	([ "family" : "白驼山",
		 "name" : "蛇形刁手" ]),
  "shentuo-zhang" : 
	([ "family" : "白驼山",
		 "name" : "神驼雪山掌" ]),
  "xuedao-jing" : 
	([ "family" : "大轮寺",
		 "name" : "血刀经" ]),
  "huoyan-dao" : 
	([ "family" : "大轮寺",
		 "name" : "火焰刀" ]),
  "xiangfu-lun" : 
	([ "family" : "大轮寺",
		 "name" : "降伏轮" ]),
  "dashou-yin" : 
	([ "family" : "大轮寺",
		 "name" : "大手印" ]),
  "longxiang-boruo" : 
	([ "family" : "大轮寺",
		 "name" : "龙象般若功",
		 "point" : ({200, 300, 400}) ]),
  "riyue-jian" : 
	([ "family" : "日月神教",
		 "name" : "日月剑法" ]),
  "riyue-dao" : 
	([ "family" : "日月神教",
		 "name" : "日月刀法" ]),
  "pixie-jian" : 
	([ "family" : "日月神教",
		 "name" : "辟邪剑法",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "preskill" : "kuihua-shengong" ]),
  "riyue-shengong" : 
	([ "family" : "日月神教",
		 "name" : "日月神功",
		 "point" : ({200, 300, 400}) ]),
  "kuihua-shengong" : 
	([ "family" : "日月神教",
		 "name" : "葵花神功",
		 "point" : ({200, 300, 400}) ]),
  "shenlong-xinfa" : 
	([ "family" : "神龙教",
		 "name" : "神龙心法",
		 "point" : ({200, 300, 400}) ]),
  "shenlong-bian" : 
	([ "family" : "神龙教",
		 "name" : "神龙鞭法" ]),
  "dulong-bi" : 
	([ "family" : "神龙教",
		 "name" : "毒龙匕法" ]),
  "huagu-mianzhang" : 
	([ "family" : "神龙教",
		 "name" : "化骨绵掌" ]),
  "zhaixing-shou" : 
	([ "family" : "星宿派",
		 "name" : "摘星手" ]),
  "xingxiu-duzhang" : 
	([ "family" : "星宿派",
		 "name" : "星宿毒掌" ]),
  "tianshan-zhang" : 
	([ "family" : "星宿派",
		 "name" : "天山杖法" ]),
  "huagong-dafa" : 
	([ "family" : "星宿派",
		 "name" : "化功大法",
		 "point" : ({200, 300, 400}) ]),
  "bixue-xinfa" : 
	([ "family" : "朝廷",
		 "name" : "碧血心法",
		 "point" : ({200, 300, 400}) ]),
  "huzhua-shou" : 
	([ "family" : "朝廷",
		 "name" : "虎爪手" ]),
  "kuihua-zhua" : 
	([ "family" : "朝廷",
		 "name" : "葵花爪" ]),
  "kuangfeng-dao" : 
	([ "family" : "朝廷",
		 "name" : "狂风刀法" ]),
  "kuangfeng-jian" : 
	([ "family" : "朝廷",
		 "name" : "狂风剑法" ]),
  "lujia-ji" : 
	([ "family" : "朝廷",
		 "name" : "吕家戟" ]),
  "bainiao-qiangfa" : 
	([ "family" : "朝廷",
		 "name" : "百鸟朝凰枪" ]),
  "juemen-gun" : 
	([ "family" : "朝廷",
		 "name" : "绝门棍" ]),
  "duanyun-bian" : 
	([ "family" : "朝廷",
		 "name" : "断云鞭" ]),
  "leiting-axe" : 
	([ "family" : "朝廷",
		 "name" : "雷霆斧" ]),
  "xiaohun-zhang" : 
	([ "family" : "古墓派",
		 "name" : "黯然销魂掌" ]),
  "meinu-quan" : 
	([ "family" : "古墓派",
		 "name" : "美女拳" ]),
  "jiuyin-baiguzhao" : 
	([ "family" : ({"古墓派","桃花岛"}),
		 "name" : "九阴白骨爪" ]),
  "yunu-jianfa" : 
	([ "family" : "古墓派",
		 "name" : "玉女剑法" ]),
  "xuantie-jian" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1800 }),
		 "point" : ({200, 300, 400}),
		 "name" : "玄铁剑法" ]),
  "changhen-bian" : 
	([ "family" : "古墓派",
		 "name" : "长恨鞭法" ]),
  "qianmie-shou" : 
	([ "family" : "古墓派",
		 "name" : "千灭银针手" ]),
  "jiuyin-shengong" : 
	([ "family" : "公共武学",
		 "name" : "九阴神功",
		 "point" : ({200, 300, 400}) ]),
  "yunu-xinfa" : 
	([ "family" : "古墓派",
		 "name" : "玉女心法",
		 "point" : ({200, 300, 400}) ]),
  "bahuang-gong" : 
	([ "family" : "灵鹫宫",
		 "name" : "八荒六合唯我独尊功",
		 "point" : ({200, 300, 400}) ]),
  "tianyu-qijian" : 
	([ "family" : "灵鹫宫",
		 "name" : "天羽奇剑" ]),
  "liuyang-zhang" : 
	([ "family" : "灵鹫宫",
		 "name" : "天山六阳掌" ]),
  "zhemei-shou" : 
	([ "family" : "灵鹫宫",
		 "name" : "天山折梅手" ]),
  "shenghuo-lingfa" : 
	([ "family" : "明教",
		 "name" : "圣火令法" ]),
  "lieyan-dao" : 
	([ "family" : "明教",
		 "name" : "烈焰刀" ]),
  "datengnuo-bufa" : 
	([ "family" : "明教",
		 "name" : "大腾挪步法" ]),
  "feihua-shou" : 
	([ "family" : "明教",
		 "name" : "飞花摘叶手" ]),
  "hanbing-zhang" : 
	([ "family" : "明教",
		 "name" : "寒冰绵掌" ]),
  "qiankun-danuoyi" : 
	([ "family" : "明教",
		 "minlevel" : ({ 400, 700, 1000 }),
		 "maxlevel" : ({ 700, 1000, 1400 }),
		 "point" : ({250, 400, 550}),
		 "name" : "乾坤大挪移" ]),
  "guangming-shenghuogong" : 
	([ "family" : "明教",
		 "point" : ({200, 300, 400}),
		 "name" : "光明圣火功" ]),
  "shenyuan-gong" : 
	([ "family" : "姑苏慕容",
		 "point" : ({200, 300, 400}),
		 "name" : "神元功" ]),
  "douzhuan-xingyi" : 
	([ "family" : "姑苏慕容",
		 "minlevel" : ({ 250, 600, 1000 }),
		 "maxlevel" : ({ 600, 1000, 1600 }),
		 "point" : ({150, 300, 450}),
		 "name" : "斗转星移" ]),
  "murong-jianfa" : 
	([ "family" : "姑苏慕容",
		 "name" : "慕容剑法" ]),
  "murong-daofa" : 
	([ "family" : "姑苏慕容",
		 "name" : "慕容刀法" ]),
  "canhe-zhi" : 
	([ "family" : "姑苏慕容",
		 "name" : "参合指" ]),
  "xingyi-zhang" : 
	([ "family" : "姑苏慕容",
		 "name" : "星移掌" ]),
  "yuxiao-jian" : 
	([ "family" : "桃花岛",
		 "name" : "玉萧剑法" ]),
  "luoying-zhang" : 
	([ "family" : "桃花岛",
		 "name" : "落英神剑掌" ]),
  "tanzhi-shengong" : 
	([ "family" : "桃花岛",
		 "name" : "弹指神功" ]),
  "fuxue-shou" : 
	([ "family" : "桃花岛",
		 "name" : "兰花拂穴手" ]),
  "bihai-shengong" : 
	([ "family" : "桃花岛",
		 "point" : ({200, 300, 400}),
		 "name" : "碧海神功" ]),
  "taiyi-shengong" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 400, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({200, 300, 400}),
		 "name" : "太乙神功" ]),
  "taiyi-jian" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({100, 150, 200}),
		 "name" : "太乙神剑",
		 "preskill" : "taiyi-shengong" ]),
  "taiyi-you" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({100, 150, 200}),
		 "name" : "太乙神游",
		 "preskill" : "taiyi-shengong" ]),
  "taiyi-zhang" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({100, 150, 200}),
		 "name" : "太乙神掌",
		 "preskill" : "taiyi-shengong" ]),
  "chuforce" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 250, 700, 1100 }),
		 "maxlevel" : ({ 700, 1100, 1600 }),
		 "point" : ({200, 300, 400}),
		 "name" : "楚家内功" ]),
  "xixing-dafa" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 200, 600, 1200 }),
		 "maxlevel" : ({ 600, 1200, 1600 }),
		 "point" : ({250, 350, 500}),
		 "name" : "吸星大法" ]),
  "jinshe-zhang" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({100, 150, 200}),
		 "name" : "金蛇游身掌" ]),
  "jinshe-jian" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({100, 150, 200}),
		 "name" : "金蛇剑法" ]),
  "jinshe-zhui" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1600 }),
		 "point" : ({100, 150, 200}),
		 "name" : "金蛇锥法" ]),
  "yuejia-qiangfa" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 500, 1000, 1300 }),
		 "maxlevel" : ({ 1000, 1300, 1800 }),
		 "point" : ({150, 250, 350}),
		 "name" : "岳家枪法" ]),
  "zui-quan" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 300, 600, 1000 }),
		 "maxlevel" : ({ 600, 1000, 1500 }),
		 "point" : ({250, 400, 600}),
		 "name" : "醉拳" ]),
  "qishang-quan" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 400, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1800 }),
		 "point" : ({100, 150, 200}),
		 "name" : "七伤拳" ]),
  "shenxing-baibian" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 400, 800, 1200 }),
		 "maxlevel" : ({ 800, 1200, 1800 }),
		 "point" : ({50, 80, 120}),
		 "name" : "神行百变" ]) ]);

//知识类技能 对应 奇闻轶事库房
mapping knowledge_skill=
(["begging" : 
	([ "family" : "丐帮",
		 "minlevel" : ({ 250, 350, 450 }),
		 "maxlevel" : ({ 350, 450, 600 }),
		 "point" : ({300, 400, 600}),
		 "name" : "叫化绝活"]),
  "checking" : 
	([ "family" : "丐帮",
		 "minlevel" : ({ 300, 400, 500 }),
		 "maxlevel" : ({ 400, 500, 600 }),
		 "point" : ({300, 400, 600}),
		 "name" : "道听途说"]),
  "stealing" : 
	([ "family" : "丐帮",
		 "minlevel" : ({ 150, 250, 400 }),
		 "maxlevel" : ({ 250, 400, 500 }),
		 "point" : ({300, 400, 600}),
		 "name" : "妙手空空"]),
  "daoxue-xinfa" : 
	([ "family" : "全真派",
		 "point" : ({150, 200, 300}),
		 "name" : "道学心法"]),
  "taoism" : 
	([ "family" : "武当派",
		 "minlevel" : ({ 300, 1000, 2000 }),
		 "maxlevel" : ({ 1000, 2000, 3000 }),
		 "point" : ({300, 500, 700}),
		 "name" : "道学心法"]),
  "daguangming-xinfa" : 
	([ "family" : "日月神教",
		 "minlevel" : ({ 300, 1000, 1800 }),
		 "maxlevel" : ({ 1000, 1800, 2500 }),
		 "point" : ({300, 500, 700}),
		 "name" : "大光明心法"]),
  "poison" : 
	([ "family" : ({"白驼山","星宿派"}),
		 "minlevel" : ({ 400, 600, 800 }),
		 "maxlevel" : ({ 600, 800, 1000 }),
		 "point" : ({300, 400, 600}),
		 "name" : "基本毒技"]),
  "training" : 
	([ "family" : "白驼山",
		 "minlevel" : ({ 400, 600, 800 }),
		 "maxlevel" : ({ 600, 800, 1000 }),
		 "point" : ({300, 400, 600}),
		 "name" : "驭兽术"]),
  "yangsheshu" : 
	([ "family" : "神龙教",
		 "minlevel" : ({ 300, 500, 700 }),
		 "maxlevel" : ({ 500, 700, 900 }),
		 "point" : ({300, 400, 600}),
		 "name" : "养蛇之技"]),
  "zhaosheshu" : 
	([ "family" : "神龙教",
		 "minlevel" : ({ 300, 500, 700 }),
		 "maxlevel" : ({ 500, 700, 900 }),
		 "point" : ({300, 400, 600}),
		 "name" : "招蛇之术"]),
  "stradgy" : 
	([ "family" : "朝廷",
		 "minlevel" : ({ 200, 300, 400 }),
		 "maxlevel" : ({ 300, 400, 500 }),
		 "point" : ({300, 500, 700}),
		 "name" : "兵法战策"]),
  "leadership" : 
	([ "family" : "朝廷",
		 "minlevel" : ({ 200, 300, 400 }),
		 "maxlevel" : ({ 300, 400, 500 }),
		 "point" : ({300, 500, 700}),
		 "name" : "为官之道"]),
  "qimen-bagua" : 
	([ "family" : "桃花岛",
		 "minlevel" : ({ 400, 600, 800 }),
		 "maxlevel" : ({ 600, 800, 1000 }),
		 "point" : ({200, 300, 400}),
		 "name" : "奇门八卦"]),
/*  "music" : 
	([ "family" : "桃花岛",
		 "minlevel" : ({ 400, 600, 800 }),
		 "maxlevel" : ({ 600, 800, 1000 }),
		 "point" : ({200, 300, 400}),
		 "name" : "音律"]),*/
  "business" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 15, 100, 200 }),
		 "maxlevel" : ({ 100, 200, 400 }),
		 "point" : ({2000, 3000, 4000}),
		 "name" : "经商之道"]),
  "anti-disguise" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 50, 300, 600 }),
		 "maxlevel" : ({ 300, 600, 900 }),
		 "point" : ({25, 50, 75}),
		 "name" : "火眼金睛"]),
  "disguise" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 50, 300, 600 }),
		 "maxlevel" : ({ 300, 600, 900 }),
		 "point" : ({50, 80, 120}),
		 "name" : "易容术",
		 "preskill" : "anti-disguise" ]),
  /*"forging" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 200, 300, 400 }),
		 "maxlevel" : ({ 300, 400, 500 }),
		 "point" : ({2000, 3000, 4000}),
		 "name" : "锻造术"]),*/ //forging和新锻造系统容易引起误会，取消了。query_skill(forging)改成query(forging)
  "identification" : 
	([ "family" : "公共武学",
		 "minlevel" : ({ 100, 300, 600 }),
		 "maxlevel" : ({ 300, 600, 900 }),
		 "point" : ({200, 300, 400}),
		 "name" : "鉴定之术"]) ]);

//佛法类技能 对应 佛经库房
mapping buddhism_skill=
(["buddhism" : 
	([ "family" : "少林派",
		 "minlevel" : ({ 300, 1000, 2000 }),
		 "maxlevel" : ({ 1000, 2000, 3000 }),
		 "point" : ({300, 500, 700}),
		 "name" : "禅宗心法"]),
  "mahayana" : 
	([ "family" : "峨嵋派",
		 "minlevel" : ({ 300, 1000, 2000 }),
		 "maxlevel" : ({ 1000, 2000, 3000 }),
		 "point" : ({300, 500, 700}),
		 "name" : "大乘涅磐功"]),
  "huanxi-chan" : 
	([ "family" : "大轮寺",
		 "minlevel" : ({ 300, 1000, 2000 }),
		 "maxlevel" : ({ 1000, 2000, 3000 }),
		 "point" : ({300, 500, 700}),
		 "name" : "欢喜禅"]) ]);

// 装备类物品列表 对应 器械库房
mapping equip_item=
(["sword":
	(["file" : ({ "std_weapon", "std_weapon", "std_weapon" }),
		"key"  : ({ "level1_sword", "level2_sword", "level3_sword" }),
		"name" : ({ HIG"尚贤剑"NOR, HIB"非命剑"NOR, HIY"天志剑"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：二孔、伤害+230、臂力+10、攻击+50\n",
		          "属性：三孔、伤害+190、臂力+15、攻击+60\n",
		          "属性：三孔、伤害+210、臂力+20、攻击+80\n"}) ]),
  "blade":
	(["file" : ({ "std_weapon", "std_weapon", "std_weapon" }),
		"key"  : ({ "level1_blade", "level2_blade", "level3_blade" }),
		"name" : ({ HIG"悯农刀"NOR, HIB"循名刀"NOR, HIY"韩非子刀"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：二孔、伤害+230、臂力+15、攻击+30\n",
		          "属性：三孔、伤害+190、臂力+20、攻击+40\n",
		          "属性：三孔、伤害+210、臂力+25、攻击+50\n"}) ]),
  "staff":
	(["file" : ({ "std_weapon", "std_weapon", "std_weapon" }),
		"key"  : ({ "level1_staff", "level2_staff", "level3_staff" }),
		"name" : ({ HIG"耕桑棍"NOR, HIB"灵枢棍"NOR, HIY"阴阳棍"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：二孔、伤害+230、臂力+20、身法-10\n",
		          "属性：三孔、伤害+190、臂力+30、身法-10\n",
		          "属性：三孔、伤害+210、臂力+40、身法-10\n"}) ]),
  "whip":
	(["file" : ({ "std_whip", "std_whip", "std_whip" }),
		"key"  : ({ "level1_whip", "level2_whip", "level3_whip" }),
		"name" : ({ HIG"梦云鞭"NOR, HIB"瑞霞鞭"NOR, HIY"行道鞭"NOR }),
		"point" : ({ 45000, 60000, 75000 }),
		"msg" : ({"属性：二孔、伤害+230、身法-10、一定概率缠住最多三个敌人【概率较低】\n",
		          "属性：三孔、伤害+190、臂力+5、身法-5、一定概率缠住最多四个敌人【概率一般】\n",
		          "属性：三孔、伤害+210、臂力+10、身法-5、一定概率缠住最多五个敌人【概率较高】\n"}) ]),
  "hammer":
	(["file" : ({ "std_hammer", "std_hammer", "std_hammer" }),
		"key"  : ({ "level1_hammer", "level2_hammer", "level3_hammer" }),
		"name" : ({ HIG"棱威锤"NOR, HIB"裂胆锤"NOR, HIY"刑天锤"NOR }),
		"point" : ({ 45000, 60000, 75000 }),
		"msg" : ({"属性：二孔、伤害+230、身法-10、一定概率范围攻击最多二个其他敌人【概率较低，伤害较低】\n",
		          "属性：三孔、伤害+190、身法-5、一定概率范围攻击最多三个其他敌人【概率一般，伤害一般】\n",
		          "属性：三孔、伤害+210、身法+5、一定概率范围攻击最多四个其他敌人【概率较高，伤害较高】\n"}) ]),
  "spear":
	(["file" : ({ "std_spear", "std_spear", "std_spear" }),
		"key"  : ({ "level1_spear", "level2_spear", "level3_spear" }),
		"name" : ({ HIG"五德枪"NOR, HIB"六亲枪"NOR, HIY"羲和枪"NOR }),
		"point" : ({ 45000, 60000, 75000 }),
		"msg" : ({"属性：二孔、伤害+230、身法-10、一定概率范围攻击最多四个其他敌人【概率较低，伤害较低】\n",
		          "属性：三孔、伤害+190、身法-10、一定概率范围攻击最多五个其他敌人【概率一般，伤害一般】\n",
		          "属性：三孔、伤害+210、身法-5、一定概率范围攻击最多六个其他敌人【概率较高，伤害较高】\n"}) ]),
  "dagger":
	(["file" : ({ "std_weapon", "std_weapon", "std_weapon" }),
		"key"  : ({ "level1_dagger", "level2_dagger", "level3_dagger" }),
		"name" : ({ HIG"百辟灵宝匕"NOR, HIB"百辟含章匕"NOR, HIY"百辟龙鳞匕"NOR }),
		"point" : ({ 50000, 70000, 90000 }),
		"msg" : ({"属性：二孔、伤害+210、基础攻速1.1、身法+15\n",
		          "属性：三孔、伤害+180、基础攻速1.15、身法+25\n",
		          "属性：三孔、伤害+200、基础攻速1.2、身法+40\n"}) ]),
  "shield":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_shield", "level2_shield", "level3_shield" }),
		"name" : ({ HIG"金翎盾"NOR, HIB"雕磐盾"NOR, HIY"震夙盾"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：三孔、防御+500、魔法值+5、反击能力【相当于雷★炎晶效果】\n",
		          "属性：三孔、防御+550、魔法值+5、反击能力【相当于泽★炎晶效果】\n",
		          "属性：三孔、防御+600、魔法值+5、反击能力【略高于天★炎晶效果】\n"}) ]),
  "head":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_head", "level2_head", "level3_head" }),
		"name" : ({ HIG"金翎冠"NOR, HIB"雕磐巾"NOR, HIY"震夙发结"NOR }),
		"point" : ({ 20000, 25000, 30000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5\n",
		          "属性：三孔、防御+120、魔法值+10\n",
		          "属性：三孔、防御+150、魔法值+15\n"}) ]),
  "cloth":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_cloth", "level2_cloth", "level3_cloth" }),
		"name" : ({ HIG"金翎袍"NOR, HIB"雕磐服"NOR, HIY"震夙衣"NOR }),
		"point" : ({ 20000, 25000, 30000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5\n",
		          "属性：三孔、防御+120、魔法值+10\n",
		          "属性：三孔、防御+150、魔法值+15\n"}) ]),
  "armor":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_armor", "level2_armor", "level3_armor" }),
		"name" : ({ HIG"金翎甲"NOR, HIB"雕磐甲"NOR, HIY"震夙甲"NOR }),
		"point" : ({ 20000, 25000, 30000 }),
		"msg" : ({"属性：三孔、防御+500、魔法值+5\n",
		          "属性：三孔、防御+550、魔法值+10\n",
		          "属性：三孔、防御+600、魔法值+15\n"}) ]),
  "surcoat":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_surcoat", "level2_surcoat", "level3_surcoat" }),
		"name" : ({ HIG"金翎披风"NOR, HIB"雕磐披风"NOR, HIY"震夙披风"NOR }),
		"point" : ({ 20000, 25000, 30000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5\n",
		          "属性：三孔、防御+120、魔法值+10\n",
		          "属性：三孔、防御+150、魔法值+15\n"}) ]),
  "waist":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_waist", "level2_waist", "level3_waist" }),
		"name" : ({ HIG"金翎腰带"NOR, HIB"雕磐腰带"NOR, HIY"震夙腰带"NOR }),
		"point" : ({ 20000, 25000, 30000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5\n",
		          "属性：三孔、防御+120、魔法值+10\n",
		          "属性：三孔、防御+150、魔法值+15\n"}) ]),
  "wrists":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_wrists", "level2_wrists", "level3_wrists" }),
		"name" : ({ HIG"金翎护腕"NOR, HIB"雕磐护腕"NOR, HIY"震夙护腕"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5、招架+20\n",
		          "属性：三孔、防御+120、魔法值+5、招架+30\n",
		          "属性：三孔、防御+150、魔法值+5、招架+50\n"}) ]),
  "hands":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_hands", "level2_hands", "level3_hands" }),
		"name" : ({ HIG"金翎护手"NOR, HIB"雕磐护手"NOR, HIY"震夙护手"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5、拳脚功夫+20\n",
		          "属性：三孔、防御+120、魔法值+5、拳脚功夫+30\n",
		          "属性：三孔、防御+150、魔法值+5、拳脚功夫+50\n"}) ]),
  "boots":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_boots", "level2_boots", "level3_boots" }),
		"name" : ({ HIG"金翎靴"NOR, HIB"雕磐靴"NOR, HIY"震夙靴"NOR }),
		"point" : ({ 30000, 35000, 40000 }),
		"msg" : ({"属性：三孔、防御+100、魔法值+5、轻功+20\n",
		          "属性：三孔、防御+120、魔法值+5、轻功+30\n",
		          "属性：三孔、防御+150、魔法值+5、轻功+50\n"}) ]),
  "ring":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_finger", "level2_finger", "level3_finger" }),
		"name" : ({ HIG"金翎戒"NOR, HIB"雕磐戒"NOR, HIY"震夙戒"NOR }),
		"point" : ({ 25000, 30000, 35000 }),
		"msg" : ({"属性：二孔、防御+50、魔法值+5\n",
		          "属性：二孔、防御+60、魔法值+10\n",
		          "属性：二孔、防御+80、魔法值+15\n"}) ]),
  "necklace":
	(["file" : ({ "std_armor", "std_armor", "std_armor" }),
		"key"  : ({ "level1_neck", "level2_neck", "level3_neck" }),
		"name" : ({ HIG"金翎项链"NOR, HIB"雕磐项链"NOR, HIY"震夙项链"NOR }),
		"point" : ({ 25000, 30000, 35000 }),
		"msg" : ({"属性：二孔、防御+50、魔法值+5\n",
		          "属性：二孔、防御+60、魔法值+10\n",
		          "属性：二孔、防御+80、魔法值+15\n"}) ]),
	"throwing":
	(["file" : ({ "ruyi-zhu", "liuye-dao", "sanleng-ci" }),
		"name" : ({ WHT"如意珠"NOR, HIW"柳叶刀"NOR, RED"三棱刺"NOR }),
		"point" : ({ 1, 1, 1 }),
		"msg" : ({"属性：伤害+100\n",
		          "属性：伤害+130\n",
		          "属性：伤害+160\n"}) ]),
  "modaoshi" :
	(["point" : ({ 500, 450, 400 }),
		"file" : ({"modaoshi", "modaoshi", "modaoshi", }),
		"name" : ({CYN"磨刀石"NOR, CYN"磨刀石"NOR, CYN"磨刀石"NOR}),
		"msg" : ({"仅支持藏经阁兵器，一次修复最大值1点。\n",
			        "仅支持藏经阁兵器，一次修复最大值1点。\n",
			      "仅支持藏经阁兵器，一次修复最大值1点。\n"}) ]) ]);

// 普通丹药类物品列表 对应 普通丹药库房
// 默认amount（数量）为10单位（对于普通丹药）。
//     高级丹药默认数量是1单位
mapping drug_item=
(["xingjun-san" :
	(["point" : ({ 20, 17, 14 }),
		"name" : "行军散" ]),
  "xingshen-dan" :
	(["point" : ({ 20, 17, 14 }),
		"name" : "醒神丹" ]),
  "mzjinchuang" :
	(["point" : ({ 5, 4, 3 }),
		"name" : HIC"少林寺秘制金创药"NOR ]),
  "mzyangjing" :
	(["point" : ({ 5, 4, 3 }),
		"name" : HIC"少林寺秘制养精丹"NOR ]),
  "baicaodan" :
	(["point" : ({ 50, 45, 40 }),
		"name" : HIG"少林秘制百草丹"NOR ]),
  "xingxiu-wan" :
	(["point" : ({ 3, 2, 1 }),
		"name" : YEL"秘制"GRN"祛毒散"NOR ]),
  "shedu-wan" :
	(["point" : ({ 3, 2, 1 }),
		"name" : YEL"秘制"GRN"五毒散"NOR ]) ]);

// 高级丹药类物品列表 对应 高级丹药库房
// 高级丹药默认数量是1单位
mapping hdrug_item=
(["expdan":
	(["point" : ({ 100, 90, 80 }),
		"name" : "经验丹" ]),
  "potdan":
	(["point" : ({ 60, 45, 40 }),
		"name" : "潜能丹" ]),
  "repdan":
	(["point" : ({ 90, 72, 69 }),
		"name" : "声望丹" ]),
  "scoredan":
	(["point" : ({ 200, 160, 140 }),
		"name" : "门忠丹" ]),
  "library-card1":
	(["point" : ({ 1000, 900, 800 }),
		"name" : HIG"阅览证"NOR ]),
  "library-card2":
	(["point" : ({ 1100, 1000, 900 }),
		"name" : HIB"阅览证"NOR ]),
  "kurong-miji1":
	(["point" : ({ 1, 1, 1 }),
		"name" : GRN"枯荣神功秘籍"NOR ]),
  "kurong-miji2":
	(["point" : ({ 2000, 2000, 2000 }),
		"name" : HIG"枯荣神功秘籍"NOR ]),
  "qianniandan" :
	(["point" : ({ 120, 100, 80 }),
		"file" : "/d/ludingshan/obj/special/dan3", 
		"name" : HIR"千年火龙丹"NOR ]),
  "randomgem" :
	(["point" : ({ 26, 21, 18 }),
		"file" : "/obj/gem/gem", 
		"name" : "随机宝石" ]),
  "money" :
	(["point" : ({ 1000, 900, 800 }),
		"file" : "/clone/money/hundred-thousand-cash", 
		"name" : "十万两银票" ]) ]);