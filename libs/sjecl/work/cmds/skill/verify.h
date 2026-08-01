//      Tbh 具体制作
//      HBRED   HBGRN   HBYEL   HBBLU   HBMAG   HBCYN   HBWHT

#include <ansi.h>

mapping exert_names = ([
  //  八荒六合功
  "bahuang-liuhe/bahuang": HBRED + HIW "〖八荒六合〗" NOR,
  "bahuang-liuhe/chuanyin": RED "传音大法" NOR,
  "bahuang-liuhe/duzun": HIG "★" HIR "唯我独尊" HIG "★" NOR,

  //  北冥神功
  "beiming-shengong/beiming": BLU "北冥大法" NOR,
  "beiming-shengong/huti": HBCYN + HIG "北冥护体" NOR,
  "beiming-shengong/jiedu": HIG "解毒大法" NOR,
  "beiming-shengong/shengsifu": HIR "生" BLU " 死 " WHT "符" NOR,
  "beiming-shengong/shougong": BLU "收功大法" NOR,

  //  碧海潮声功        
  "bihai-chaosheng/cuidu": HIW "催    毒" NOR,
  "bihai-chaosheng/zhanbu": HIG "占 卜 术" NOR,
  "bihai-chaosheng/lifeheal": HIW "他人疗伤" NOR,
  "bihai-chaosheng/maze": HIY "奇门迷魂阵" NOR,
  "bihai-chaosheng/play": HIM "吹    箫" NOR,
  "bihai-chaosheng/qimen": HIW "奇门八卦" NOR,

  //  毒龙大法        
  "dulong-dafa/jiedu": HIW "解    毒" NOR,
  "dulong-dafa/shougong": CYN "收    功" NOR,
  "dulong-dafa/wudi": RED "无敌大法" NOR,
  "dulong-dafa/shexin": HIR "摄    心" NOR,

  //  娥眉九阳神功        
  //        "emei-jiuyang/heal":HIW"真气疗伤"NOR,
  //        "emei-jiuyang/lifeheal":HIW"他人疗伤"NOR,
  //        "emei-jiuyang/powerup":HIY"峨嵋九阳功"NOR,

  //  归元吐纳法        
  "guiyuan-tunafa/focus": HBBLU "聚    力" NOR,
  //        "guiyuan-tunafa/lifeheal":HIY"他人疗伤"NOR,

  //  寒冰真气        
  "hanbing-zhenqi/hanbing": HIW "寒 冰 诀" NOR,
  "hanbing-zhenqi/juhan": HIW "聚    寒" NOR,
  "hanbing-zhenqi/liaodu": HIW "疗    毒" NOR,

  //  化功大法
  "huagong-dafa/duwu": HIB "毒    雾" NOR,
  "huagong-dafa/huadu": BLU "化    毒" NOR,
  "huagong-dafa/huagong": BLU "化    功" NOR,
  "huagong-dafa/huajing": HIB "化    精" NOR,
  "huagong-dafa/judu": BLU "聚毒护身" NOR,
  "huagong-dafa/liaodu": HIB "疗    毒" NOR,

  // 混元一气
  "hunyuan-yiqi/heal": HIW "真气疗伤" NOR,
  "hunyuan-yiqi/lifeheal": HIW "他人疗伤" NOR,
  "hunyuan-yiqi/roar": HIY "狮 子 吼" NOR,

  /*        "hunyuan-gong/jianmang":                MAG"剑　　芒"NOR,
        "hunyuan-gong/ningshen":                MAG"凝　　神"NOR,
        "hunyuan-gong/lifeforce":               MAG"治疗内伤"NOR,
        "hunyuan-gong/lifeheal":                MAG"疗　　伤"NOR,
        "hunyuan-gong/zixia":                   MAG"紫　　霞"NOR, */

  //  混天气功        
  "huntian-qigong/huntian": HIR "混    天" NOR,
  "huntian-qigong/shentong": HIW "神    通" NOR,
  "huntian-qigong/powerup": HIR "混天气功" NOR,
  "huntian-qigong/shougong": GRN "收    功" NOR,

  /*        "huagong-dafa/heal":                    RED"真气疗伤"NOR,
        "huagong-dafa/huadu":                   RED"化　　毒"NOR,
        "huagong-dafa/huagong":                 RED"化　　功"NOR,
        "huagong-dafa/judu":                    RED"聚　　毒"NOR,
        "huagong-dafa/liaodu":                  RED"疗　　毒"NOR, */

  //  蛤蟆功        
  "hamagong/hama": HIB "蛤 蟆 功" NOR,
  "hamagong/nizhuan": HIW "逆    转" NOR,
  "hamagong/qudu": HIW "驱    毒" NOR,

  // 冷泉神功
  "lengquan-shengong/lengquan": HIB "冷    泉" NOR,
  "lengquan-shengong/yinyang": HIY "阴阳无常" NOR,

  //  临济十二庄        
  "linji-zhuang/fengyun": MAG "风    云" NOR,
  "linji-zhuang/riyue": MAG "日    月" NOR,
  "linji-zhuang/tiandi": HIW "天    地" NOR,
  "linji-zhuang/wuwo": HIW "无    我" NOR,
  "linji-zhuang/yinyang": HBBLU "阴    阳" NOR,
  "linji-zhuang/zhixin": MAG "之    心" NOR,
  "linji-zhuang/youming": HIW "幽    冥" NOR,

  //  龙象般若功
  "longxiang-boruo/fenchang": BLU "凝神梵唱" NOR,
  "longxiang-boruo/longxiang": MAG "龙象之力" NOR,
  "longxiang-boruo/shield": CYN "真气护体" NOR,
  "longxiang-boruo/guiyuan": HIY "搜魄归元" NOR,
  "longxiang-boruo/juxue": HIW "疗    伤" NOR,
  "longxiang-boruo/shenyou": HIW "神    游" NOR,

  //  九阳神功
  "jiuyang-shengong/chuangong": HIR "传　　功" NOR,
  "jiuyang-shengong/jiuyang": HIR "九阳神功" NOR,
  "jiuyang-shengong/tougu": HIW "透 骨 针" NOR,
  "jiuyang-shengong/yinfeng": HIW "阴 风 刀" NOR,
  "jiuyang-shengong/xinmo": HIR "心　　魔" NOR,

  //  九阴真功        
  "jiuyin-zhengong/huanxue": HIB "移经换穴" NOR,
  "jiuyin-zhengong/liaojing": HIW "真气疗精" NOR,
  "jiuyin-zhengong/heyi": HIR "万变合一" NOR,
  "jiuyin-zhengong/jiuyin": WHT "九阴真气" NOR,
  "jiuyin-zhengong/shehun": HIW "摄魂大法" NOR,
  "jiuyin-zhengong/yihun": HIW "移魂大法" NOR,
  "jiuyin-zhengong/zongjue": HIY "九阴总诀" NOR,

  //  枯荣禅功       
  "kurong-changong/kong": HIG "空    明" NOR,
  "kurong-changong/ku": GRN "枯字大法" NOR,
  "kurong-changong/liao": HIY "真气疗伤" NOR,
  "kurong-changong/roar": HIY "狮 子 吼" NOR,
  "kurong-changong/rong": HIR "荣字大法" NOR,
  "kurong-changong/xinjing": GRN "静心潜修" NOR,

  //  乾天一阳功
  "qiantian-yiyang/kong": HIG "空    明" NOR,
  "qiantian-yiyang/liao": HIY "真气疗伤" NOR,
  "qiantian-yiyang/xinjing": GRN "静心潜修" NOR,

  //  圣火神功
  "shenghuo-shengong/chuangong": HIR "传　　功" NOR,
  "shenghuo-shengong/tougu": HIW "透 骨 针" NOR,
  "shenghuo-shengong/yinfeng": HIW "阴 风 刀" NOR,
  "shenghuo-shengong/xinmo": HIR "心　　魔" NOR,

  //  神元功        
  //        "shenyuan-gong/heal":HIW"真气疗伤"NOR,
  //        "shenyuan-gong/lifeheal":HIW"他人疗伤"NOR,
  "shenyuan-gong/shenyuan": HIY "神 元 功" NOR,


  //        "songshan-qigong/jianqi":GRN"运 剑 气"NOR,

  /*        "tiangang-zhengqi/heal":HIW"真气疗伤"NOR,
        "tiangang-zhengqi/lifeheal":HIW"他人疗伤"NOR,
        "tiangang-zhengqi/powerup":HIR"运 天 罡"NOR, */

  //  小无相神功
  "xiaowuxiang-gong/liaojing": HIC "疗精" NOR,
  "xiaowuxiang-gong/wuxiang": HBCYN + HIC "无根无相" NOR,

  //  玄天无极功
  "xuantian-wuji/taxue": MAG "踏雪无痕" NOR,
  "xuantian-wuji/light": HIW "运功于剑" NOR,

  /*        
        "xixing-dafa/heal":HIW"真气疗伤"NOR,
        "xixing-dafa/lifeheal":HIW"他人疗伤"NOR,
        "xixing-dafa/powerup":HIR"吸心大法"NOR,
        "xixing-dafa/roar":HIR"长空狂吼"NOR,
        "xixing-dafa/xijing":HIR"吸    精"NOR,
        "xixing-dafa/xineili":HIR"吸 内 力"NOR,
        "xixing-dafa/xiqi":HIR"吸    气"NOR,  
*/

  //  易筋经        
  "yijin-jing/jingang": HIR "金刚不坏体神功" NOR,
  "yijin-jing/roar": HIY "狮 子 吼" NOR,

  //  氤氲紫气        
  "yinyun-ziqi/qudu": HIY "纯阳无极功" NOR,
  "yinyun-ziqi/lifesave": HIW "鹤嘴劲点龙跃窍" NOR,
  "yinyun-ziqi/taiji": CYN "太 极 功" NOR,
  "yinyun-ziqi/yinyun": MAG "氤氲内聚" NOR,

  //  玉女心经
  "yunu-xinjing/hebi": HIY "合    壁" NOR,
  "yunu-xinjing/xinjing": HIY "心    经" NOR,

  //  紫霞神功        
  "zixia-gong/jianyi": HIM "紫霞剑意" NOR,
  "zixia-gong/zixia": MAG "紫    霞" NOR,
  "zixia-gong/jianqi": MAG "紫霞剑气" NOR,
  "zixia-gong/lifeforce": MAG "混元无极功" NOR,

  //神照经
  "shenzhao-jing/shenzhao": HIW "神    照" NOR,

]);

mapping perform_names = ([
  //  黯然销魂掌
  "anran-zhang/anran": HIY "黯然销魂" NOR,
  "anran-zhang/xiaohun": HIW "销魂" NOR,
  "anran-zhang/jishi": HIY "嫉世愤俗" NOR,

  //  暗影浮香
  "anying-fuxiang/huashen": HBYEL "诸天化身步" NOR,

  "banruo-zhang/yipai": RED "一拍两散" NOR,

  //  
  "canglang-goufa/beauty": MAG "美人三招" NOR,
  "canglang-goufa/hero": HIR "英雄三招" NOR,

  //  参合指
  "canhe-zhi/ci": HIC "刺 字 诀" NOR,

  //  慈行鞭
  "cihang-bian/cibei": RED "慈悲字诀" NOR,

  //  冲灵剑法
  "chongling-jian/hebi": HIY "双剑合璧" NOR,

  //  抽髓掌
  "chousui-zhang/biyan": HIC "碧　　焰" NOR,
  "chousui-zhang/chousui": BLU "三阴抽髓" NOR,
  "chousui-zhang/huoqiang": BLU "火　　墙" NOR,
  "chousui-zhang/huoqiu": HIR "火　　球" NOR,
  "chousui-zhang/yinhuo": YEL "银　　火" NOR,
  "chousui-zhang/fushidu": BLU "腐尸攻击" NOR,
  //  穿云腿
  "chuanyun-tui/chuanyun": HIG "穿    云" NOR,


  //  春兰剑法
  "chunlan-jianfa/lianji": HIC "兰剑连击" NOR,

  //  催心掌
  "cuixin-zhang/cuixin": HIR "催心断肠" NOR,
  "cuixin-zhang/yinyang": HIG "阴阳双掌" NOR,

  //  大伏魔拳
  "dafumo-quan/fumo": HIY "伏   魔" NOR,
  "dafumo-quan/xiangmo": HIG "降   魔" NOR,
  "dafumo-quan/posha": HIY "破   煞" NOR,
  "dafumo-quan/qiankun": HIY "乾坤一击" NOR,

  //  打狗棒
  "dagou-bang/chan": HBGRN "缠 字 诀" NOR,
  "dagou-bang/zhuan": HBYEL "转 字 诀" NOR,
  "dagou-bang/shuangjue": HIW "棒掌双绝" NOR,
  "dagou-bang/chuo": HBWHT "戳 字 诀" NOR,
  "dagou-bang/tiao": HBMAG "挑 字 诀" NOR,
  "dagou-bang/wugou": HIY "天下无狗" NOR,
  "dagou-bang/pi": HBRED "劈 字 诀" NOR,
  "dagou-bang/ban": HBBLU "绊 字 诀" NOR,
  "dagou-bang/yin": HBCYN "引 字 诀" NOR,

  //  达摩剑
  "damo-jian/sanjue": RED "达摩三绝" NOR,

  //  密宗大手印
  "dashou-yin/tianyin": HIY "阿修罗天印" NOR,

  //  冬梅剑法
  "dongmei-jianfa/wumei": HIM "舞梅弄影" NOR,

  //  斗转星移
  "douzhuan-xingyi/xingyi": HIY "星移斗转" NOR,
  "douzhuan-xingyi/bishen": HIG "以彼之道还施彼身" NOR,

  //  段家剑法
  "duanjia-jianfa/fenglei": BLU "风雷四击" NOR,

  //  独孤九剑
  "dugu-jiujian/kuangfeng": HIC "狂风卷地" NOR,
  "dugu-jiujian/poqi": HIC "破 气 式" NOR,
  "dugu-jiujian/pobian": HIW "破 鞭 式" NOR,
  "dugu-jiujian/podao": HIW "破 刀 式" NOR,
  "dugu-jiujian/pozhang": HIW "破 掌 式" NOR,
  "dugu-jiujian/pojian": HIW "破 剑 式" NOR,
  "dugu-jiujian/pojianshi": HIW "破 箭 式" NOR,
  "dugu-jiujian/poqiang": HIW "破 枪 式" NOR,
  "dugu-jiujian/posuo": HIW "破 索 式" NOR,
  "dugu-jiujian/zongjue": HIW "总 诀 式" NOR,

  //  夺命金花
  "duoming-jinhua/huayu": HIW "满天花雨" NOR,

  //  反两仪刀
  "fanliangyi-dao/hebi": HIY "合　　璧" NOR,
  "fanliangyi-dao/sanshenfeng": HIC "华岳三神峰" NOR,

  "fengmo-zhang/feizhang": HIR "飞    杖" NOR,

  //  寒冰绵掌
  "hanbing-mianzhang/xixue": HIC "吸血青蝠" NOR,

  //  寒冰神掌
  "hanbing-shenzhang/hanbing": BLU "寒冰真气" NOR,

  "hansha-sheying/xiangyin": HIY "心心相印" NOR,

  //  化骨绵掌
  "huagu-mianzhang/bujue": HIC "绵绵不绝" NOR,
  "huagu-mianzhang/huagu": HIY "化    骨" NOR,
  "huagu-mianzhang/puhuo": RED "飞蛾扑火" NOR,

  //  华山剑法
  //        "huashan-jianfa/jianzhang":HIR"剑掌五连环"NOR,
  "huashan-jianfa/feijian": HIC "飞    剑" NOR,
  "huashan-jianfa/lianhuan": MAG "夺命连环三仙剑" NOR,
  "huashan-jianfa/wushuang": HIR "无双无对" NOR,
  "huashan-jianfa/xiyi": HIC "希夷剑法" NOR,
  "huashan-jianfa/sanqingfeng": HIR "太岳三青峰" NOR,
  "huashan-jianfa/yangwu": MAG "养吾剑法" NOR,
  "huashan-jianfa/shunv": HIC "淑女剑法" NOR,
  "huashan-jianfa/junzi": HIC "君子剑法" NOR,
  "huashan-jianfa/shijiushi": HIC "玉女十九式" NOR,
  "huashan-jianfa/kuaijian": HIG "狂风快剑" NOR,

  //  回风鞭法
  "huifeng-bian/huixuan": HIY "回旋十三式" NOR,

  //  回风拂柳剑
  "huifeng-jian/jue": HIW "绝    剑" NOR,
  "huifeng-jian/liaoyuan": HIW "燎原百击" NOR,
  "huifeng-jian/mie": HIW "灭    剑" NOR,
  "huifeng-jian/miejue": HIW "灭绝心法" NOR,

  // 胡家刀法
  "hujia-daofa/feidao": HIC "飞 刀 诀" NOR,
  "hujia-daofa/luandao": HIR "乱 刀 诀" NOR,
  "hujia-daofa/roudao": HIG "柔 刀 诀" NOR,

  //  混元掌
  "hunyuan-zhang/wuji": HIR "混元无极" NOR,

  //  火焰刀
  "huoyan-dao/daoqi": HIY "火焰刀气" NOR,
  "huoyan-dao/fen": HIR "焚 字 诀" NOR,
  "huoyan-dao/ran": HIR "燃 字 诀" NOR,

  //  枯荣禅功
  "kurong-changong/jiuchong": BLU "九 重 天" NOR,

  //  兰花拂穴手
  "lanhua-shou/fuxue": HIC "兰花拂穴" NOR,

  //  两仪剑法
  //        "liangyi-jian/sanqiu":CYN"一日三秋"NOR,
  "liangyi-jian/hebi": MAG "双剑合璧" NOR,
  "liangyi-jian/hundun": HIG "混沌剑气" NOR,
  "liangyi-jian/jianqin": HIB "琴剑双绝" NOR,

  "lietian-fu/lihun": RED "离 魂 斩" NOR,

  //  烈焰刀法
  "lieyan-dao/shenghuo": HIR "圣火光明" NOR,

  //  凌波微步
  "lingbo-weibu/luoshen": HIG "洛    神" NOR,

  //  灵蛇鞭法
  "lingshe-bianfa/chan": HIY "金蛇缠丝" NOR,
  "lingshe-bianfa/sandou": HIY "灵蛇三抖" NOR,

  //  六合刀法
  "liuhe-daofa/sancai": CYN "奇门三才刀" NOR,

  //  六脉神剑
  "liumai-shenjian/ciqu": MAG "此去彼来" NOR,

  //  天山六阳掌
  "liuyang-zhang/duanzhang": WHT "段掌神威" NOR,
  "liuyang-zhang/liuyang": HBCYN + HIC "六阳诀" NOR,

  //  柳叶刀法
  "liuye-daofa/daozhang": BLU "一刀夹双掌" NOR,

  "longzhua-gong/canyun": RED "风卷残云" NOR,

  //  落英神剑掌
  "luoying-zhang/bading": HIW "拔附骨钉" NOR,
  "luoying-zhang/fugu": HIR "附 骨 钉" NOR,
  "luoying-zhang/pikong": HIB "劈 空 掌" NOR,
  "luoying-zhang/shenjian": HIM "桃花影里飞神剑" NOR,

  //  截手九式
  "jieshou-jiushi/foguang": MAG "佛光普照" NOR,

  "jingang-quan/fumo": HIR "金刚伏魔" NOR,

  //  金蛇剑法
  "jinshe-jianfa/kuangwu": HIR "金蛇狂舞" NOR,

  // 金蛇游身掌
  "jinshe-zhangfa/chanshen": HIY "金蛇缠身" NOR,

  // 金蛇锥法
  "jinshe-zhuifa/sheying": HIR "蛇影万道" NOR,

  // 九阴白骨爪
  "jiuyin-baiguzhua/jiuyin": RED "九阴三绝爪" NOR,
  "jiuyin-baiguzhua/duzhua": HIB "九阴毒爪" NOR,
  "jiuyin-baiguzhua/zhuagou": HIB "九阴爪钩" NOR,
  "jiuyin-shenzhang/shenzhang": HIR "神掌夺魄" NOR,
  "jiuyin-shenzhang/yinyang": HIG "阴阳双掌" NOR,
  "jiuyin-shenzhua/sanjue": RED "九阴三绝抓" NOR,
  "jiuyin-shenfa/huanyinbu": HIW "幻阴步" NOR,
  "juehu-shou/juehu": BLU "绝　　户" NOR,
  "kongming-quan/luanwu": RED "群魔乱舞" NOR,
  "kongmingquan/chan": CYN "缠 字 诀" NOR,
  "kongmingquan/kongqianjiuhou": CYN "空前绝后" NOR,
  "kunlun-zhang/diezhang": HIG "昆仑叠掌" NOR,

  //  美女拳法
  "meinu-quanfa/shexin": HIY "摄    心" NOR,

  //  苗家剑法
  "miaojia-jianfa/duoming": HIW "连环夺命诀" NOR,
  "miaojia-jianfa/ci": HBBLU + HIW "绝  命  刺" NOR,

  //  慕容刀法
  "murong-daofa/daoying": HIR "刀 影 掌" NOR,

  //  慕容剑法
  "murong-jianfa/lianhuan": HIC "七剑连环指" NOR,
  "murong-jianfa/sanhua": HIG "天女散花" NOR,
  //        "murong-jianfa/qixingplus":HIB"七剑转七星"NOR,


  "nianhua-zhi/fuxue": HIY "拂穴绝技" NOR,

  // 凝血神爪
  "ningxue-shenzhua/ningxue": HIR "凝血诀" NOR,
  "ningxue-shenzhua/liao": HIY "疗字诀" NOR,

  "pangen-cuojie/pifeng": HIR "乱 披 风" NOR,
  "pixie-jian/cimu": RED "飞针刺目" NOR,
  "pixie-jian/feiying": MAG "葵花飞影术" NOR,
  "pixie-jian/jue": MAG "绝 命 针" NOR,

  //  劈石破玉拳
  "poyu-quan/leidong": MAG "雷动九天" NOR,

  //  乾坤大挪移
  "qiankun-danuoyi/hua": HIW "化 字 诀" NOR,
  "qiankun-danuoyi/yi": BLU "移 字 诀" NOR,
  "qiankun-danuoyi/xu": HIY "蓄 字 诀" NOR,
  "qiankun-danuoyi/yin": HIG "引 字 诀" NOR,

  //  如来千叶手
  "qianye-shou/qianshou": HIY "千手如来" NOR,

  //  秋菊剑法        
  "qiuju-jianfa/chan": HBRED "菊香缠人" NOR,

  "qingxu-bian/fei": HIB "龙凤双飞" NOR,

  //        "qingyan-zhang/liaorao":HIY"烟雾缭绕"NOR,

  //  七伤拳
  "qishang-quan/duanhun": HIR "断魂夺魄" NOR,
  "qishang-quan/qishang": HIR "七伤总诀" NOR,

  //  全真剑法
  "quanzhen-jianfa/qixing": HIW "七星绝命剑" NOR,
  "quanzhen-jianfa/sanqing": HIW "一剑化三清" NOR,

  "ranmu-daofa/fentian": HIR "举火焚天" NOR,
  "ranmu-daofa/fenwo": HIR "焚    我" NOR,
  "ranmu-daofa/fenxin": HIR "焚 心 决" NOR,
  "riyue-bian/chanrao": HIY "缠 绕 诀" NOR,
  "riyue-bian/fumoquan": HIY "金刚伏魔圈" NOR,
  "riyue-bian/riyue": HIC "日月神鞭" NOR,
  "ruying-suixingtui": YEL "如影随形" NOR,
  "sanhua-zhang/sanhua": HIW "四季散花" NOR,

  //  三阴蜈蚣抓
  "sanyin-zhua/sanyin": HBBLU "三阴毒蛭抓" NOR,

  //  圣火令法    
  "shenghuo-lingfa/duo": BCYN "夺 字 诀" NOR,
  "shenghuo-lingfa/ji": HIY "击 字 诀" NOR,
  "shenghuo-lingfa/tisha": HIM "踢　　沙" NOR,
  "shenghuo-lingfa/xinmo": HIR "心　　魔" NOR,

  //  神龙追命腿
  "shenlong-tuifa/zhuiming": HIY "神龙追命腿" NOR,

  //  水上漂
  "shuishangpiao/piao": HIC "漂" NOR,

  //  四花舞影剑
  "sihua-wuying/chan": HBRED "菊香缠人" NOR,
  "sihua-wuying/lianji": HIC "兰剑连击" NOR,
  "sihua-wuying/wuqing": HIR "竹剑无情" NOR,
  "sihua-wuying/wumei": HIM "舞梅弄影" NOR,
  "sihua-wuying/tongqi": HIG "同气连枝" NOR,


  //  嵩山剑法
  "songshan-jian/feiwu": BLU "飞    舞" NOR,
  "songshan-jian/leiting": YEL "雷霆万钧" NOR,
  "songshan-jian/longfeng": HIR "龙吟凤翔" NOR,
  "songshan-jian/songyang": HIW "嵩 阳 诀" NOR,

  //  大嵩阳神掌
  "songyang-zhang/junji": CYN "峻极神掌" NOR,

  //  大嵩阳手
  "songyang-shou/junji": CYN "峻极神掌" NOR,
  "songyang-shou/yinyang": HIY "大阴阳手" NOR,

  // 嵩阳鞭
  "songyang-bian/luan": BLU "乱 鞭 诀" NOR,


  "suibo-zhuliu/wuzhuan": HIW "奇门五转" NOR,
  "suishangpiao/piao": HIC "   飘  " NOR,

  //  太极剑
  "taiji-jian/chan": HIW "天缠地绕诀" NOR,
  "taiji-jian/lian": CYN "连 字 诀" NOR,
  "taiji-jian/lianhuan": HIC "连 环 诀" NOR,
  "taiji-jian/sanhuan": HIG "三环套月" NOR,
  "taiji-jian/tongshou": HIC "天地同寿" NOR,
  "taiji-jian/raozhi": HIR "绕指柔剑" NOR,

  //  太极拳
  "taiji-quan/ji": RED "挤 字 诀" NOR,
  "taiji-quan/luanhuan": HIC "乱 环 诀" NOR,
  "taiji-quan/zhen": RED "震 字 诀" NOR,
  "taiji-quan/an": HIB "按 字 诀" NOR,
  "taiji-quan/dongjing": MAG "动 静 诀" NOR,
  "taiji-quan/gangrou": HIB "刚 柔 诀" NOR,
  "taiji-quan/yinyang": GRN "阴 阳 诀" NOR,
  "taiji-quan/zhannian": CYN "粘 粘 诀" NOR,
  "taiji-quan/taiji": WHT "太    极" NOR,

  //  弹指神通
  "tanzhi-shentong/huayu": CYN "漫天花雨" NOR,
  "tanzhi-shentong/qiankun": HIG "乾坤一指" NOR,
  "tanzhi-shentong/shentong": HIW "弹指神通" NOR,
  "tanzhi-shentong/tan": HIG "弹 字 诀" NOR,
  "tanzhi-shentong/xinghe": HIW "星河千帆舞" NOR,


  //  腾龙匕法
  "tenglong-bifa/diqing": HIY "狄青降龙" NOR,
  "tenglong-bifa/feiyan": HIR "飞燕回翔" NOR,
  "tenglong-bifa/guifei": HIR "贵妃回眸" NOR,
  "tenglong-bifa/luda": HIY "鲁达拔柳" NOR,
  "tenglong-bifa/xiaolian": HIR "小怜横陈" NOR,
  "tenglong-bifa/zixu": HIY "子胥举鼎" NOR,

  "tiangang-jian/qixinggongyue": YEL "七星拱月" NOR,
  "tiangang-zhang/tiangang": HIG "天    罡" NOR,

  //  天山杖法
  "tianshan-zhang/feizhi": BLU "飞掷" NOR,

  //        "tianyu-qijian/san":HIR"天女散花"NOR,

  //  铁掌掌法
  "tiezhang-zhangfa/tianlei": HIY "天 雷 气" NOR,
  "tiezhang-zhangfa/duoming": HBBLU "夺命铁爪" NOR,
  "tiezhang-zhangfa/heisha": HBBLU "黑 砂 掌" NOR,
  "tiezhang-zhangfa/heyi": HIW "阴阳合一" NOR,
  "tiezhang-zhangfa/honglei": HBBLU "轰雷双掌" NOR,
  "tiezhang-zhangfa/judu": HIB "聚    毒" NOR,
  "tiezhang-zhangfa/pangen": HBBLU "枯树盘根" NOR,
  "tiezhang-zhangfa/pushan": HIW "铁蒲扇掌" NOR,
  "tiezhang-zhangfa/qinna": HBBLU "铁掌擒拿" NOR,
  "tiezhang-zhangfa/rubairen": HBBLU "入 白 刃" NOR,
  "tiezhang-zhangfa/tiezhang": HBBLU "铁    掌" NOR,
  "tiezhang-zhangfa/xuanfeng": HBBLU "旋风快掌" NOR,
  "tiezhang-zhangfa/zhangdao": HIW "铁掌掌刀" NOR,

  //  梯云纵
  "tiyunzong/zong": HIY "纵字诀" NOR,

  //  五虎段门刀
  "wuhu-duanmendao/duan": HIY "断字诀" NOR,

  //  金刚降伏轮
  "xiangfu-lun/dazhuan": HIY "五轮大转" NOR,
  "xiangfu-lun/wushuai": HIY "天人五衰" NOR,

  //  降龙十八掌
  "xianglong-zhang/kanglong": HIC "亢龙有悔" NOR,
  "xianglong-zhang/paiyun": WHT "排云双掌" NOR,
  "xianglong-zhang/xiao": YEL "降 龙 啸" NOR,

  //  夏竹剑法
  "xiazhu-jianfa/wuqing": HIR "竹剑无情" NOR,


  //  星移掌
  "xingyi-zhang/riyue": CYN "日月同辉" NOR,
  //        "xingyi-zhang/xingdian":HIW"星光点点"NOR,

  //  旋风扫叶腿
  "xuanfeng-tui/kuangfeng": HIG "狂风绝技" NOR,

  //  玄铁剑法
  "xuantie-jianfa/haichao": HIB "海潮汹涌" NOR,
  "xuantie-jianfa/wujian": HIB "无剑胜有剑" NOR,

  //  玄虚刀法
  "xuanxu-daofa/luanhuanjue": HIY "乱 环 诀" NOR,

  //  玄阴剑法
  "xuanyin-jian/xuanyin": HIB "玄 阴 诀" NOR,
  "xuanyin-jian/zhan": HIB "斩 字 诀" NOR,
  "xuanyin-jian/jiulianji": HIR "玄阴九连击" NOR,


  //  血刀经
  "xuedao-jing/jixue": HIR "祭血神刀" NOR,
  "xuedao-jing/shendao": HIR "神刀穿心" NOR,

  //  雁行刀法
  "yanxing-daofa/feiyan": HIY "飞雁随风刃" NOR,
  "yanxing-daofa/chuanliu": HIY "雁行穿柳刀" NOR,
  "yanxing-daofa/hebi": MAG "双刀合璧" NOR,
  "yanxing-daofa/huanying": HIY "无形幻影" NOR,

  //  九阴银龙鞭
  "yinlong-bian/chanrao": HIG "缠绕诀" NOR,
  "yinlong-bian/feilong": HIG "飞龙诀" NOR,
  "yinlong-bian/chou": HIB "抽字诀" NOR,

  "yingou-bifa/caoshu": HIM "草    书" NOR,
  "yingou-bifa/kaishu": HIC "楷    书" NOR,
  "yingou-bifa/shigu": HIY "石 鼓 文" NOR,

  //  银索金铃
  "yinsuo-jinling/sanwu": HIW "三无三不手" NOR,
  "yinsuo-jinling/yueyin": HIW "乐音绝技" NOR,
  //        "yinsuo-jinling/feng":HIC"封    穴"NOR,
  "yinsuo-jinling/yufeng": HIW "玉 蜂 针" NOR,

  //  一阳指
  "yiyang-zhi/ciqu": HIG "此去彼来" NOR,
  "yiyang-zhi/yizhisanmai": HIR "一指点三脉" NOR,
  "yiyang-zhi/liumai": HIW "六脉神剑" NOR,
  "yiyang-zhi/sandie": HIY "阳关三叠" NOR,
  "yiyang-zhi/qianlong": WHT "潜龙勿用" NOR,

  //  一指禅
  "yizhi-chan/wofo": HIW "皈依我佛" NOR,

  //  游龙身法
  "youlong-shenfa/baibian": HIY "神行百变" NOR,

  "youming-zhao/youming": HIR "呼唤鬼魂" NOR,
  "yubi-jianfa/san": HIM "天女散花" NOR,
  "yubi-jianfa/shuangzhao": HIG "璧影双照" NOR,

  //  玉女素心剑
  "yunu-jianfa/hebi": HIY "双剑合壁" NOR,
  "yunu-jianfa/suxin": HIW "玉女素心" NOR,
  "yuxiao-jian/feiying": HIW "飞    影" NOR,
  "yuxiao-jian/qimen": HIG "奇门玉箫" NOR,
  //        "yuxiao-jian/yuxiao":CYN"碧海潮生按玉箫"NOR,

  //  天山折梅手
  "zhemei-shou/luanmei": MAG "乱梅飞舞" NOR,
  "zhemei-shou/zhe": HIY "折字诀" NOR,
  "zhemei-shou/duo": CYN "空手夺刃" NOR,
  "zhemei-shou/hanmei": HIM "寒梅暖阳" NOR,
  "zhemei-shou/jue": HIY "折梅手心诀" NOR,
  "zhemei-shou/poyun": CYN "神鹫破云式" NOR,
  "zhemei-shou/tanmei": HIY "弹梅·落雪·散花香" NOR,

  //  震山绵掌
  "zhenshan-mianzhang/bingdi": HIC "花开并蒂" NOR,

  "zhuihun-gou/luanpifeng": HIB "乱 披 风" NOR,
  "zui-gun/zuida": HIY "八仙醉打" NOR,
  "zuibaxian/zuijiu": GRN "八仙醉酒" NOR,

  //千蛛万毒手
  "qianzhu-wandushou/qianzhu": HIR "千" HIG "蛛" HIW "万" HIB "毒" NOR,

  //空明拳
  "kongming-quan/kong": HIW "空 字 诀" NOR,
  "kongming-quan/ming": HIW "明 字 诀" NOR,

]);
