// autosaved.c
// file:                Autosave daemon
// creator:     ken
// date:                98-2-23

// for autosave players data file.
#include <ansi.h>

inherit F_DBASE;
string  zuji(string str);
void zujinpc(object me,object obj);
void zujinpc2(object me,object obj);
void give_gift();
int give_gift3(int rd,object npc,object me);
mapping citynpc = ([
"/d/baling/beidajie1.c":  "xiao jie",
"/d/baling/beimen.c":  "wu jiang",
"/d/baling/bingqipu.c":  "tie jiang",
"/d/baling/dangpu.c":  "meng laoban",
"/d/baling/dongmen.c":  "wu jiang",
"/d/baling/guangchang.c":  "shang lv",
"/d/baling/kedian.c":  "xiao er",
"/d/baling/nanmen.c":  "wu jiang",
"/d/baling/qianzhuang.c":  "qian laoban",
"/d/baling/shuyuan.c":  "zhu xiansheng",
"/d/baling/ximen.c":  "wu jiang",
"/d/baling/xunhuange.c":  "tao hong",
"/d/baling/yanju.c":  "wu jiang",
"/d/baling/yaopu.c":  "wang yaoshi",
"/d/beijing/andao1.c":  "xuan zhen",
"/d/beijing/anding.c":  "guan bing",
"/d/beijing/anding.c":  "wu jiang",
"/d/beijing/aobai3.c":  "qin bing",
"/d/beijing/aobai4.c":  "guan jia",
"/d/beijing/aobai4.c":  "jia ding",
"/d/beijing/aobai5.c":  "chu shi",
"/d/beijing/chaguan.c":  "guan anji",
"/d/beijing/chaoyang.c":  "guan bing",
"/d/beijing/chaoyang.c":  "wu jiang",
"/d/beijing/dangpu.c":  "jia laoliu",
"/d/beijing/datiepu.c":  "tiejiang",
"/d/beijing/dating.c":  "chen jinnan",
"/d/beijing/di_an2.c":  "flower girl",
"/d/beijing/di_an3.c":  "liu mang",
"/d/beijing/di_an3.c":  "liumang tou",
"/d/beijing/dongmen.c":  "guan bing",
"/d/beijing/dongmen.c":  "wu jiang",
"/d/beijing/duchang.c":  "shou toutuo",
"/d/beijing/duchang.c":  "wu liuqi",
"/d/beijing/fuweibiaoju.c":  "yi biaotou",
"/d/beijing/guancai1.c":  "gao yanchao",
"/d/beijing/hai_dating.c":  "zheng keshuang",
"/d/beijing/hai_dayuan.c":  "shi wei",
"/d/beijing/haigang.c":  "flower girl",
"/d/beijing/houtai.c":  "xi zi",
"/d/beijing/huichunt.c":  "xu tianchuan",
"/d/beijing/huichunt.c":  "yaopu huoji",
"/d/beijing/jail.c":  "yu zu",
"/d/beijing/kang3.c":  "jia ding",
"/d/beijing/kedian.c":  "xiao er",
"/d/beijing/kedian4.c":  "kedian huoji",
"/d/beijing/mianguan.c":  "jianghu haoke",
"/d/cangzhou/bank.c":  "jiang tiaohou",
"/d/cangzhou/beimen.c":  "guan bing",
"/d/cangzhou/beimen.c":  "wu jiang",
"/d/cangzhou/dangpu.c":  "huang laoban",
"/d/cangzhou/dongmen.c":  "guan bing",
"/d/cangzhou/dongmen.c":  "wu jiang",
"/d/cangzhou/eroad4.c":  "jiangbei dadao",
"/d/cangzhou/fuya.c":  "ya yi",
"/d/cangzhou/kezhan.c":  "miao ruolan",
"/d/cangzhou/kezhan.c":  "xiao er",
"/d/cangzhou/mihang.c":  "wang dami",
"/d/cangzhou/mingju.c":  "ping si",
"/d/cangzhou/wroad4.c":  "ke shang",
"/d/changan/ca.c":  "xiao fan",
"/d/changan/ca10.c":  "shensuan zi",
"/d/changan/ca11.c":  "wei bing",
"/d/changan/ca14.c":  "yaopu huoji",
"/d/changan/ca15.c":  "yue girl",
"/d/changan/ca17.c":  "xiao fan",
"/d/changan/ca2.c":  "xiao er",
"/d/changan/dongmen.c":  "guan bing",
"/d/changan/dongmen.c":  "wu jiang",
"/d/changan/garments.c":  "zeng rou",
"/d/changan/shuyuan.c":  "li bai",
"/d/changsha/beidajie2.c":  "qi gai",
"/d/changsha/dongdajie2.c":  "shu sheng",
"/d/changsha/eroad2.c":  "xiao shami",
"/d/changsha/jinlou.c":  "li laoban",
"/d/changsha/nandajie2.c":  "liu mang",
"/d/changsha/nanmen.c":  "wu jiang",
"/d/changsha/qianzhuang.c":  "qian laoban",
"/d/changsha/road2.c":  "shang lv",
"/d/changsha/road4.c":  "xiao shami",
"/d/changsha/road5.c":  "shang lv",
"/d/changsha/road5.c":  "xiao shami",
"/d/changsha/tianwaitian.c":  "xiao er",
"/d/changsha/tiejiangpu.c":  "tie jiang",
"/d/changsha/xiaochidian.c":  "xiao er",
"/d/changsha/xiaoxiang.c":  "xian sheng",
"/d/changsha/xiaoxiang.c":  "xue tong",
"/d/changsha/ximen.c":  "wu jiang",
"/d/changsha/yaopu.c":  "song daifu",
"/d/changsha/zhahuopu.c":  "li laoban",
"/d/chengdu/beijie.c":  "jianghu haoke",
"/d/chengdu/biaoju.c":  "biao tou",
"/d/chengdu/chaguan.c":  "lao ban",
"/d/chengdu/chaguan3.c":  "cha boshi",
"/d/chengdu/chenmapo.c":  "chen mapo",
"/d/chengdu/chufang.c":  "da shifu",
"/d/chengdu/chunxilu.c":  "wei bing",
"/d/chengdu/chunxilu3.c":  "wei bing",
"/d/chengdu/dangpu.c":  "yan liu",
"/d/chengdu/dongjie2.c":  "seng ren",
"/d/chengdu/liangting.c":  "xiao fan",
"/d/chengdu/lingmu.c":  "saomu ren",
"/d/chengdu/mujiangpu.c":  "zhang mujiang",
"/d/chengdu/niangjiuwu.c":  "wang erniang",
"/d/chengdu/niangjiuwu.c":  "xiao huozi",
"/d/chengdu/northgate.c":  "guan bing",
"/d/chengdu/northgate.c":  "wu jiang",
"/d/chengdu/qianzhuang.c":  "ma youcai",
"/d/chengdu/qingyang.c":  "dao shi",
"/d/chengdu/shimiao.c":  "xiao heshang",
"/d/chengdu/shimiao.c":  "zhike seng",
"/d/chengdu/shuoshuyuan.c":  "shen jinyin",
"/d/chengdu/shuoshuyuan.c":  "wang cheng",
"/d/chengdu/southgate.c":  "guan bing",
"/d/chengdu/southgate.c":  "wu jiang",
"/d/chengdu/tidufu.c":  "qin bing",
"/d/chengdu/tidufu.c":  "shi cong",
"/d/chengdu/tidufu.c":  "wu tiande",
"/d/chengdu/tidugate.c":  "qin bing",
"/d/chengdu/tidujie.c":  "guan bing",
"/d/chengdu/westgate.c":  "guan bing",
"/d/chengdu/westgate.c":  "wu jiang",
"/d/chengdu/xijie2.c":  "flower girl",
"/d/chengdu/yaopu.c":  "yaodian huoji",
"/d/chengdu/zahuopu.c":  "wang yongkan",
"/d/chengdu/zhubaodian.c":  "xie yunyan",
"/d/city/baiyipu.c":  "shen wanfu",
"/d/city/bank2.c":  "tie suanpan",
"/d/city/beiliuxiang.c":  "po pi",
"/d/city/beimen.c":  "ma chaoxing",
"/d/city/beimen.c":  "wu jiang",
"/d/city/beimen.c":  "guan bing",
"/d/city/beimendajie.c":  "ge ji",
"/d/city/biaoju.c":  "biao tou",
"/d/city/bingyin.c":  "wu jiang",
"/d/city/bingyin.c":  "wang huaishui",
"/d/city/bingyin.c":  "shi qingshan",
"/d/city/bingyin.c":  "guan bing",
"/d/city/bingyindamen.c":  "guan bing",
"/d/city/caibopu.c":  "gu bancheng",
"/d/city/caiyijiekou.c":  "ge ji",
"/d/city/caohebeijie.c":  "qiu xingxing",
"/d/city/caohebeijie.c":  "yang leishi",
"/d/city/caohecexiang.c":  "tang fan",
"/d/city/caohexiaojie.c":  "you ke",
"/d/city/chaguan.c":  "aqing sao",
"/d/city/chanzhisi.c":  "kanmen seng",
"/d/city/chanzhixf.c":  "huogong seng",
"/d/city/chuanlang.c":  "ya huan",
"/d/city/dangpu.c":  "xun bu",
"/d/city/dangpu.c":  "tang nan",
"/d/city/dangpu2.c":  "xun bu",
"/d/city/dangpu2.c":  "xiangling",
"/d/city/datiepu.c":  "tiejiang",
"/d/city/dayuan.c":  "guan jia",
"/d/city/dayuan.c":  "jia ding",
"/d/city/dongmen.c":  "wu jiang",
"/d/city/dongmen.c":  "guan bing",
"/d/city/dongmenqiao.c":  "boy",
"/d/city/dongxiang.c":  "hong niang",
"/d/city/duchang.c":  "pang toutuo",
"/d/city/fengreiroom.c":  "zhao junrong",
"/d/city/ganquanjie.c":  "ouyang ke",
"/d/city/garments.c":  "zeng rou",
"/d/city/gbandao.c":  "jian zhanglao",
"/d/city/guangchang.c":  "xun bu",
"/d/city/guangchang.c":  "liu mang",
"/d/city/guangchang.c":  "da che",
"/d/city/guangchang.c":  "liumang tou",
"/d/city/heyuanhouyuan.c":  "he yuanwai",
"/d/city/hongqiao.c":  "girl",
"/d/city/houyuan.c":  "cui yuanwai",
"/d/city/huadian.c":  "a ke",
"/d/city/huadian2.c":  "ying lian",
"/d/city/jiaowai10.c":  "jiang shangyou",
"/d/city/jiaowai13.c":  "mo bushou",
"/d/city/jiaowai2.c":  "qiu wanjia",
"/d/city/jiaowai4.c":  "zhao gouer",
"/d/city/jiaowai6.c":  "kuai huosan",
"/d/city/kedian.c":  "xiao er",
"/d/city/lichunyuan.c":  "mao shiba",
"/d/city/lichunyuan.c":  "kong kong",
"/d/city/lichunyuan.c":  "wei chunfang",
"/d/city/lichunyuan.c":  "guinu",
"/d/city/majiu.c":  "ma fu",
"/d/city/matou.c":  "jian gong",
"/d/city/meichuanxuan.c":  "yang wanxiao",
"/d/city/meixiangyuan.c":  "chang xiang",
"/d/city/menting.c":  "jia ding",
"/d/city/nandajie1.c":  "xiao hunhun",
"/d/city/nandajie2.c":  "tuobo seng",
"/d/city/nandajie2.c":  "duan yu",
"/d/city/nanmen.c":  "shi song",
"/d/city/nanmen.c":  "wu jiang",
"/d/city/nanmen.c":  "guan bing",
"/d/city/neizhai.c":  "cheng yuhuan",
"/d/city/pomiao.c":  "peng youjing",
"/d/city/pomiao.c":  "lu youjiao",
"/d/city/qianzhuang.c":  "qian yankai",
"/d/city/qionghuajie.c":  "ge ji",
"/d/city/qiqifang.c":  "jiang qianli",
"/d/city/shuyuan.c":  "zhu xi",
"/d/city/sixiepu.c":  "li bailv",
"/d/city/taipingqiao.c":  "ge ji",
"/d/city/tangwu1.c":  "qiu haoshi",
"/d/city/tangwu2.c":  "wu guxian",
"/d/city/tianningshuju.c":  "xin youqing",
"/d/city/tongsijie.c":  "xun bu",
"/d/city/tongsiqiao.c":  "liu yan",
"/d/city/toujinpu.c":  "kong jinjin",
"/d/city/waifang.c":  "lu lixian",
"/d/city/wuguan.c":  "chen youde",
"/d/city/wumiao.c":  "nan xian",
"/d/city/xiangfenpu.c":  "dai chunlin",
"/d/city/xianguopu.c":  "peng baoxian",
"/d/city/xiaobaozhai.c":  "wei xiaobao",
"/d/city/xidajie2.c":  "youfang daoren",
"/d/city/ximen.c":  "wu jiang",
"/d/city/ximen.c":  "feng gongying",
"/d/city/ximen.c":  "guan bing",
"/d/city/xixiang.c":  "cui yingying",
"/d/city/yamen.c":  "xun bu",
"/d/city/yamen.c":  "ya yi",
"/d/city/yaopu.c":  "ping yizhi",
"/d/city/yaopu.c":  "yaopu huoji",
"/d/city/ymzhengting.c":  "tan youji",
"/d/city/ymzhengting.c":  "cheng yaofa",
"/d/city/youju.c":  "foxmail",
"/d/city/yudian.c":  "leng yuran",
"/d/city/zahuopu.c":  "yang yongfu",
"/d/city/zhuqidian.c":  "liu sanshun",
"/d/city/zizheng.c":  "li xiaoqi",
"/d/city/zizheng.c":  "gu yueer",
"/d/city/zizheng.c":  "kong xiaotian",
"/d/city/zuixianlou.c":  "xiao er",
"/d/city/zuixianlou2.c":  "wang wu",
"/d/dali/atoubu.c":  "lie ren",
"/d/dali/banshan.c":  "kanzhu ren",
"/d/dali/biluoshan.c":  "nong fu",
"/d/dali/bingying.c":  "shi bing",
"/d/dali/bingying.c":  "wei shi",
"/d/dali/buxiongbu.c":  "shang fan",
"/d/dali/cangshanlu1.c":  "lie ren",
"/d/dali/caopo.c":  "muyang nu",
"/d/dali/caopo.c":  "muyang ren",
"/d/dali/center.c":  "jianghu yiren",
"/d/dali/changlang.c":  "duan wuwei",
"/d/dali/guibingshi2.c":  "daizu shouling",
"/d/dali/hebian.c":  "shang fan",
"/d/dali/hexi.c":  "shang fan",
"/d/dali/hualang.c":  "gong nu",
"/d/dali/jianchuan.c":  "lie ren",
"/d/dali/jianchuan.c":  "pihuo shang",
"/d/dali/jianchuankou.c":  "shi bing",
"/d/dali/jianchuankou.c":  "wu jiang",
"/d/dali/jinzhihe.c":  "seng ren",
"/d/dali/jisidawu1.c":  "lao jisi",
"/d/dali/kedian.c":  "xiao er",
"/d/dali/kefang.c":  "pei cong",
"/d/dali/langan3.c":  "yangcan nu",
"/d/dali/langan4.c":  "fangsha nu",
"/d/dali/longkou.c":  "shi bing",
"/d/datong/hongchanglu1.c":  "city guard",
"/d/datong/hongchanglu1.c":  "qiaoshou meimei",
"/d/datong/jiangjunfu.c":  "guan bing",
"/d/datong/jiangjunfu.c":  "wu jiang",
"/d/datong/jiangjunfu.c":  "ya yi",
"/d/datong/jinyangjie6.c":  "shoubian laoren",
"/d/datong/renyili.c":  "ren yili",
"/d/datong/shuiguodian.c":  "fruit seller",
"/d/datong/sizhai2.c":  "zhuge wu",
"/d/datong/wanhualou.c":  "gui gong",
"/d/datong/yuanwaifu.c":  "liang yuanwai",
"/d/datong/zahuopu.c":  "hu mai",
"/d/foshan/dangpu.c":  "lao chaofeng",
"/d/foshan/eastgate.c":  "changbian",
"/d/foshan/huiguan.c":  "feng yiming",
"/d/foshan/road8.c":  "zhang chaotang",
"/d/foshan/road8.c":  "zhang kang",
"/d/foshan/street1.c":  "jia ding",
"/d/foshan/street2.c":  "liu mang",
"/d/foshan/street3.c":  "liumang tou",
"/d/foshan/yingxionglou.c":  "feng qi",
"/d/foshan/yingxionglou2.c":  "pang shangren",
"/d/foshan/yingxionglou2.c":  "shou shangren",
"/d/fuzhou/biaoju.c":  "bai er",
"/d/fuzhou/biaoju.c":  "changbian",
"/d/fuzhou/biaoju.c":  "chen qi",
"/d/fuzhou/biaojudy.c":  "shi biaotou",
"/d/fuzhou/biaojuhy.c":  "zheng biaotou",
"/d/fuzhou/biaojunz.c":  "wang furen",
"/d/fuzhou/biaojuzt.c":  "lin zhennan",
"/d/fuzhou/fzroad10.c":  "yu renyan",
"/d/fuzhou/fzroad5.c":  "fang renzhi",
"/d/fuzhou/fzroad6.c":  "yu renhao",
"/d/guizhou/chaguan.c":  "xiao er",
"/d/guizhou/chengmen.c":  "wu jiang",
"/d/guizhou/dangpu.c":  "qiu laoban",
"/d/guizhou/dongdajie.c":  "xiao jie",
"/d/guizhou/dongmen.c":  "wu jiang",
"/d/guizhou/ncenter.c":  "wu jiang",
"/d/guizhou/qianzhuang.c":  "qian yan",
"/d/guizhou/tiejiangpu.c":  "tie jiang",
"/d/guizhou/ximen.c":  "wu jiang",
"/d/hangzhou/dalu1.c":  "hong hua",
"/d/hangzhou/dalu1.c":  "tiao fu",
"/d/hangzhou/duanqiao.c":  "poor man",
"/d/hangzhou/fajingsi.c":  "jinxiang ke",
"/d/hangzhou/fajingsi.c":  "xiao shami",
"/d/hangzhou/jiulou.c":  "xiao er",
"/d/hangzhou/jujingyuan.c":  "hong hua",
"/d/hangzhou/jujingyuan.c":  "jian ke",
"/d/hangzhou/kedian.c":  "xiao er",
"/d/hangzhou/lingyinsi.c":  "lao heshang",
"/d/hangzhou/lingyin3.c":  "kumu chanshi",
"/d/hangzhou/liuzhuang.c":  "jia ding",
"/d/hangzhou/maojiabu.c":  "old woman",
"/d/hangzhou/marryroom.c":  "hong niang",
"/d/hangzhou/qiantang.c":  "jian ke",
"/d/hangzhou/road12.c":  "li kexiu",
"/d/hangzhou/road12.c":  "qing bing",
"/d/hangzhou/road13.c":  "zhang zhaozhong",
"/d/hangzhou/road14.c":  "luo bing",
"/d/hangzhou/suti7.c":  "shu sheng",
"/d/hefei/beidajie1.c":  "wu shi",
"/d/hefei/bingqipu.c":  "tie jiang",
"/d/hefei/caifengdian.c":  "zhang zhanggui",
"/d/hefei/center.c":  "yi ren",
"/d/hefei/dongdajie1.c":  "di zi",
"/d/hefei/dongdajie2.c":  "qi gai",
"/d/hefei/dongdajie3.c":  "gu niang",
"/d/hefei/huayuan.c":  "xiao jie",
"/d/hefei/liangting.c":  "gongzi ge",
"/d/hefei/nandajie2.c":  "dao ke",
"/d/hefei/nandajie3.c":  "xiao hunhun",
"/d/hefei/qianzhuang.c":  "chang laoban",
"/d/hefei/shanlu1.c":  "tu fei",
"/d/hefei/xiaochidian.c":  "xiao er",
"/d/hefei/xidajie1.c":  "shang bing",
"/d/hefei/xidajie2.c":  "xiao jie",
"/d/hefei/xiyuan.c":  "xi you",
"/d/hefei/yanju.c":  "wu jiang",
"/d/hefei/yaopu.c":  "ding zhanggui",
"/d/jiangling/beimen.c":  "dao ke",
"/d/jiangling/beimen.c":  "jianghu haoke",
"/d/jiangling/caidi.c":  "di yun",
"/d/jiangling/chaguan.c":  "chongyi jushi",
"/d/jiangling/citang.c":  "tao hong",
"/d/jiangling/datang.c":  "he wenbao",
"/d/jiangling/datang.c":  "ling tuisi",
"/d/jiangling/juhuahui.c":  "ling shuanghua",
"/d/jiangling/kedian.c":  "xiao er",
"/d/jiangling/laofang.c":  "ding dian",
"/d/jiangling/laotc.c":  "laoban niang",
"/d/jiangling/maxipu.c":  "qi changfa",
"/d/jiangling/nanlou.c":  "bo yuan",
"/d/jiangling/nanlou.c":  "feng tan",
"/d/jiangling/nanlou.c":  "shen cheng",
"/d/jiangling/nanlou.c":  "sun jun",
"/d/jiangling/nanmen.c":  "jian ke",
"/d/jiangling/nanmen.c":  "jianghu haoke",
"/d/jinan/govern.c":  "yayi",
"/d/jinan/lake.c":  "su rongrong",
"/d/jinan/mjgate":  "xiao yi",
"/d/jinan/road1.c":  "duanchang ren",
"/d/jingzhou/jzximen.c":  "guan bing",
"/d/jingzhou/jzyamen.c":  "ya yi",
"/d/jingzhou/kedian.c":  "xiao er",
"/d/jingzhou/qianzhuang.c":  "qian defa",
"/d/jingzhou/shuyuan.c":  "xiao xiangzi",
"/d/jingzhou/yaopu.c":  "huatuo",
"/d/jingzhou/yaopu.c":  "yaopu huoji",
"/d/jingzhou/ymzhengting.c":  "ling situi",
"/d/jinling/yuhuatai.c":  "wang qier",
"/d/jinling/zhongxin.c":  "qiu yi",
"/d/jinling/zhongyaopu.c":  "xu lingren",
"/d/jiujiang/beidajie2.c":  "su su",
"/d/jiujiang/bingqidian.c":  "tie jiang",
"/d/jiujiang/center.c":  "fei yan",
"/d/jiujiang/chaguan.c":  "cha ke",
"/d/jiujiang/chaguan.c":  "chaguan laoban",
"/d/jiujiang/chaguan.c":  "mi tan",
"/d/jiujiang/chunzailou.c":  "jian ke",
"/d/jiujiang/chunzailou.c":  "jiu ke",
"/d/jiujiang/chunzailou.c":  "xiang yushan",
"/d/jiujiang/chunzailou.c":  "xiao he",
"/d/jiujiang/chunzailou.c":  "zhang gui",
"/d/jiujiang/fanzhuang.c":  "xiao er",
"/d/jiujiang/xidajie1.c":  "shang ren",
"/d/kaifeng/cangjing1.c":  "zhifa zhanglao",
"/d/kaifeng/chufang.c":  "kong guanren",
"/d/kaifeng/chufang.c":  "liu caizhu",
"/d/kaifeng/chufang2.c":  "shaohuo seng",
"/d/kaifeng/chufang2.c":  "suzhai shifu",
"/d/kaifeng/daoxiang1.c":  "xiao er",
"/d/kaifeng/daoxiang2.c":  "gao yanei",
"/d/kaifeng/daoxiang2.c":  "lu yuhou",
"/d/kaifeng/wroad2.c":  "qi gai",
"/d/kaifeng/xiangguosi.c":  "zhike seng",
"/d/kaifeng/xilou.c":  "xiao sheng",
"/d/kaifeng/xuandemen.c":  "guan bing",
"/d/kaifeng/yanqing.c":  "qi gai",
"/d/kaifeng/yaqi.c":  "liu zhanggui",
"/d/kaifeng/zhuque.c":  "guan bing",
"/d/kaifeng/zhuque.c":  "qi gai",
"/d/kunming/chapu.c":  "xiao er",
"/d/kunming/dangpu.c":  "liu tong",
"/d/kunming/kedian.c":  "yuan cai",
"/d/kunming/qiao.c":  "qiang dao",
"/d/kunming/shufan.c":  "wu sangui",
"/d/kunming/wangfu2.c":  "qin bing",
"/d/kunming/xizoulang1.c":  "feng xifan",
"/d/luoyang/dianpu.c":  "dian zhu",
"/d/luoyang/eastgate.c":  "guan bing",
"/d/luoyang/eastroad.c":  "wang jiaju",
"/d/luoyang/huadian.c":  "laoban niang",
"/d/luoyang/hulaoguan.c":  "guan bing",
"/d/luoyang/lvzhuxiaoyuan.c":  "luzhu weng",
"/d/luoyang/lvzuan.c":  "fei bing",
"/d/suzhou/dangpu.c":  "wang heji",
"/d/suzhou/datiepu.c":  "tiejiang",
"/d/suzhou/dayuan1.c":  "guan jia",
"/d/suzhou/dayuan1.c":  "jia ding",
"/d/suzhou/dongmen.c":  "guan bing",
"/d/suzhou/dongmen.c":  "wu jiang",
"/d/suzhou/dongxiang.c":  "ling qiuhua",
"/d/suzhou/houyuan.c":  "ling tuizi",
"/d/suzhou/hutong3.c":  "liu mang",
"/d/suzhou/jiudian.c":  "xiao er",
"/d/suzhou/jubaozhai.c":  "sun baopi",
"/d/suzhou/kedian.c":  "xiao er",
"/d/suzhou/nanmen.c":  "wu jiang",
"/d/suzhou/shijianshi.c":  "jian ke",
"/d/suzhou/shuyuan.c":  "lao fuzi",
"/d/suzhou/tielingguan.c":  "guan bing",
"/d/suzhou/zijinan.c":  "ni gu",
"/d/taiyuan/huichuntang.c":  "leng xiansheng",
"/d/taiyuan/jinci.c":  "gu niang",
"/d/taiyuan/jiuguan.c":  "xiao er",
"/d/taiyuan/nandajie2.c":  "che fu",
"/d/taiyuan/nanmen.c":  "wu jiang",
"/d/taiyuan/shuyuan.c":  "zhao xueshi",
"/d/taiyuan/wanjinzhai.c":  "huo ji",
"/d/taiyuan/ximen.c":  "wu jiang",
"/d/taiyuan/xinggong.c":  "min gong",
"/d/taiyuan/xiyuan.c":  "xi you",
"/d/taiyuan/yansi.c":  "wu jiang",
"/d/xiangyang/biaoju.c":  "biao tou",
"/d/xiangyang/biaoju.c":  "guo xu",
"/d/xiangyang/eastgate2.c":  "song bing",
"/d/xiangyang/eastjie1.c":  "shi bowei",
"/d/xiangyang/guofugate.c":  "jia ding",
"/d/xiangyang/jiangjuntang.c":  "ya jiang",
"/d/xiangyang/jiangjuntang.c":  "zuo jiang",
"/d/xiangyang/jiedao.c":  "poor man",
"/d/xiangyang/juyichufang.c":  "shaofan shifu",
"/d/xiangyang/juyihuayuan.c":  "guo fu",
"/d/xiangyang/northgate2.c":  "pi jiang",
"/d/xiangyang/northgate2.c":  "song bing",
"/d/xiangyang/northjie.c":  "jian jie",
"/d/xiangyang/northroad2.c":  "shi mengjie",
"/d/xiangyang/qianzhuang.c":  "huang zhen",
"/d/xiangyang/shudian.c":  "shudian laoban",
"/d/xiangyang/westroad2.c":  "shi zhongmeng",
"/d/xiangyang/xinluofang.c":  "gaoli shang",
"/d/xiangyang/xuetang.c":  "lao xiansheng",
"/d/xiangyang/yaopu.c":  "yaopu huoji",
"/d/zhongzhou/bank.c":  "yao dezhong",
"/d/zhongzhou/beimen.c":  "guan bing",
"/d/zhongzhou/canchang.c":  "cai fan",
"/d/zhongzhou/canchang.c":  "liumang tou",
"/d/zhongzhou/chenglou.c":  "guan bing",
"/d/zhongzhou/congwu.c":  "du dajin",
"/d/zhongzhou/dangpu.c":  "yi taitai",
"/d/zhongzhou/dangpu.c":  "zhou songtian",
"/d/zhongzhou/dongmeng.c":  "guan bing",
"/d/zhongzhou/dukoulu.c":  "shao fu",
"/d/zhongzhou/gongyuan4.c":  "kao guan",
"/d/zhongzhou/guandimiao.c":  "qi gai",
"/d/zhongzhou/huazhuang.c":  "hua dan",
"/d/zhongzhou/huazhuang.c":  "xi zi",
"/d/zhongzhou/hutong2.c":  "liu mang",
"/d/zhongzhou/liangongfang.c":  "lao dan",
"/d/zhongzhou/miaojia_chufang.c":  "chu shi",
"/d/zhongzhou/miaojia_houting.c":  "miao renfeng",
"/d/zhongzhou/miaojia_houting.c":  "tian guinong",
"/d/zhongzhou/miaojia_jushi.c":  "miao ruolan",
"/d/zhongzhou/miaojia_men.c":  "zhong zhaowen",
"/d/zhongzhou/miaojia_zhengting.c":  "zhong zhaoneng",
"/d/zhongzhou/miaojia_zhengting.c":  "zhong zhaoying",
"/d/zhongzhou/wendingbei3.c":  "old man",
"/d/zhongzhou/wendingbei3.c":  "old woman",
"/d/zhongzhou/wendingbei4.c":  "tang zi",
"/d/zhongzhou/wendingnan1.c":  "liu mang",
"/d/zhongzhou/wendingnan2.c":  "qi ying",
"/d/zhongzhou/xiaren.c":  "ya huan",
"/d/zhongzhou/xiyuan.c":  "guan zhong",
"/d/zhongzhou/xiyuan1.c":  "guan zhong",
"/d/zhongzhou/yamen.c":  "ya yi",
"/d/zhongzhou/yanling1.c":  "fu shang",
"/d/zhongzhou/yanling1.c":  "qong han",
"/d/zhongzhou/yanlingdong.c":  "liu mang",
"/d/zhongzhou/yanlingdong1.c":  "jia ding",
"/d/zhongzhou/yanlingdong1.c":  "walker",
"/d/zhongzhou/yanlingdong2.c":  "gu gong",
"/d/zhongzhou/yanlingdong2.c":  "lao gugong",
"/d/zhongzhou/yaopu.c":  "yaopu huoji",
"/d/zhongzhou/yaopuboss.c":  "wu panbing",
"/d/zhongzhou/yinghao.c":  "xiao er",
"/d/zhongzhou/yinghaoup.c":  "fujia dizi",
"/d/zhongzhou/yuanwan.c":  "guan jia",
"/d/zhongzhou/yuanwan.c":  "jia ding",
"/d/zhongzhou/zahuopu.c":  "zhao deyan",
"/d/lanzhou/beimen.c":"guan bing",
"/d/lanzhou/caisicang.c":"cainong",
"/d/lanzhou/caisicang.c":"liu mang",
"/d/lanzhou/guangchang.c":"liumang tou",
"/d/lanzhou/guangchang.c":"xiao fan",
"/d/lanzhouchen/caoyuan3.c":"muyang ren",
"/d/lingzhou/baxian.c":"lao daoshi",
"/d/lingzhou/center.c":"duan yanqing",
"/d/lingzhou/daodian.c":"xiao huoji",
"/d/lingzhou/dawu.c":"ye erniang",
"/d/lingzhou/jiangjunyuan.c":"jia ding",
"/d/lingzhou/kongdi.c":"nanhai eshen",
"/d/lingzhou/piandian.c":"gong nu",
"/d/yueyang/beijie.c":"xing ren",
"/d/yueyang/beimen.c":"gaibang bangzhong",
"/d/yueyang/gaibanggate.c":"xi zhanglao",
"/d/yueyang/jiuxiangshan.c":"bai shijing",
"/d/yueyang/longkou.c":"xu zhanglao",
"/d/yueyang/nanjie.c":"liu zhuzhuang",
"/d/city/zuixianlou.c":  "xiao er",
"/d/city/zuixianlou2.c":  "xian laoban",
"/d/city/zahuopu.c":  "yang yongfu",
"/d/city/tongsiqiao.c":  "liu yan",
"/d/city/heyuanhouyuan.c":  "he yuanwai",
"/d/city/kedian.c":  "xiao er",
"/d/city/wuguan.c":  "chen youde",
"/d/city/houyuan.c":  "cui yuanwai",
"/d/city/xixiang.c":  "cui yingying",
"/d/biancheng/mianguan.c":  "zhang laoshi",
"/d/biancheng/paifang.c":  "guo wei",
"/d/biancheng/nstreet4.c":  "yun zaitian",
"/d/lumaji/zahuo.c":  "san niang",
"/d/huayin/datiepu.c":  "shi lao han",
"/d/huayin/jiuguan.c":  "ma zhanglao",
"/d/houjizhen/kedian.c":  "xiao er",
"/d/houjizhen/jiuguan.c":  "mei shijie",
"/d/zuojiacun/mujiang.c":  "zhang mujiang",
"/d/jinghai/jhd19.c":  "master deng",
"/d/yandang/kezhan.c":  "xiao er",
"/d/yandang/cahuopu.c":  "lao ban",
"/d/nanshaolin/shanmen.c":  "yuan tong",
"/d/yueyang/ximen.c":  "xiang zhanglao",
"/d/tianshui/chaguan.c":  "tea boss",
"/d/tianshui/dangpu.c":  "tang zhanggui",
"/d/datong/tiejiangpu.c":  "liu tie",
"/d/ny/txgate.c":  "zu daoshou",
"/d/fengtian/chaguan.c":  "ma dasao",
"/d/nanchang/qianzhuang.c":  "zhou laoban",
"/d/changsha/jinlou.c":  "li laoban",
"/d/zhongzhou/yuanwan.c":  "guan jia",
"/d/guizhou/ncenter.c":  "wu jiang",
"/d/jinan/street1.c":  "xiazi aming",
"/d/xuzhou/jiuguan.c":  "xiao er",
"/d/mayi/zahuopu.c":  "xiao er",
"/d/suiye/huadian.c":  "hua nong",
"/d/dingxiang/zhubaodian.c":  "zhubao shang",
"/d/baling/yaopu.c":  "wang yaoshi",
"/d/annan/qianzhuang.c": "fan laoban",
"/d/annan/jiuguan.c": "xiao er",
"/d/annan/kezhan.c": "xiao er",
"/d/annan/xijie2.c": "wu yuanjia",
"/d/baituo/cedong.c": "jin hua",
"/d/baituo/chufang.c": "fei fei",
"/d/baituo/houyuan.c": "zhang ma",
"/d/baling/dangpu.c": "meng laoban",
"/d/baling/shuyuan.c": "zhu xiansheng",
"/d/baling/yaopu.c": "wang yaoshi",
"/d/biancheng/cottonshop.c": "song fugui",
"/d/biancheng/endeyuan.c": "ma huihui",
"/d/biancheng/silkshop2.c": "chen daguan",
"/d/biancheng/zahuopu.c": "li mahu",
"/d/cangzhou/kezhan.c": "miao ruolan",
"/d/changsha/zhahuopu.c": "li laoban",
"/d/chengdu/chenmapo.c": "chen mapo",
"/d/chengdu/shimiao2.c": "yuan chanshi",
"/d/chenxiang/beix.c": "wang",
"/d/dali/chahua2.c": "yanghua nu",
"/d/dali/garments.c": "xue laoban",
"/d/dali/jianchuan.c": "pihuo shang",
"/d/datong/dangpu.c": "huang fugui",
"/d/datong/hejiqianzhuang.c": "he quanli",
"/d/datong/langzhongjia.c": "zhong jishi",
"/d/datong/sizhai.c": "zhang tianyou",
"/d/dingxiang/dangpu.c": "zhou laoban",
"/d/dingxiang/datiepu.c": "tie jiang",
"/d/dingxiang/huanggong.c": "da han",
"/d/emei/cangjingge.c": "jingdao shitai",
"/d/fengtian/jiulou.c": "pao tang",
"/d/fengtian/smith.c": "smith zhou",
"/d/fengtian/wujia.c": "wu qian",
"/d/foshan/dangpu.c": "lao chaofeng",
"/d/foshan/huiguan.c": "feng yiming",
"/d/foshan/street4.c": "zhong sisao",
"/d/fuzhou/laozhai.c": "bo chen",
"/d/gaoli/qianzhuang.c": "jin mangui",
"/d/gaoli/sishu.c": "lao xuejiu",
"/d/gaoli/zhubaodian.c": "zhu laoban",
"/d/guanwai/tuyaoguan.c": "jiao wenqi",
"/d/guizhou/dangpu.c": "qiu laoban",
"/d/guizhou/qianzhuang.c": "qian yan",
"/d/guizhou/tiejiangpu.c": "tie jiang",
"/d/hefei/qianzhuang.c": "chang laoban",
"/d/houjizhen/bingqipu.c": "weapon boss",
"/d/houjizhen/yaopu.c": "zhang jishi",
"/d/houjizhen/zahuopu.c": "Yang yonggui",
"/d/huanghe/huanghegate.c": "ma qingxiong",
"/d/huanghe/huanghegate.c": "shen qinggang",
"/d/jiangling/chaguan.c": "chongyi jushi",
"/d/jiangling/citang.c": "tao hong",
"/d/jiangling/kedian.c": "xiao er",
"/d/jinan/firstbrook.c": "song tianer",
"/d/jinan/lake.c": "su rongrong",
"/d/jindezheng/gudong-shop.c": "duanmu",
"/d/jindezheng/tea-room.c": "xiao mei",
"/d/jingzhou/yaopu.c": "huatuo",
"/d/jinling/huadian.c": "jiang qin",
"/d/jinling/qianzhuang.c": "banker",
"/d/jinling/taihuzhai.c": "xiao zhiyu",
"/d/jinling/zhongyaopu.c": "xu lingren",
"/d/jiujiang/bingqidian.c": "tie jiang",
"/d/jiujiang/chaguan.c": "chaguan laoban",
"/d/jiujiang/fanzhuang.c": "xiao er",
"/d/jiujiang/kezhan.c": "xiao er",
"/d/jiujiang/qianzhuang.c": "qian laoban",
"/d/jyguan/zahuopu.c": "mai mai ti",
"/d/kaifeng/cangjing1.c": "zhifa zhanglao",
"/d/kaifeng/daoxiang2.c": "gao yanei",
"/d/lingzhou/chema.c": "xiao er",
"/d/lingzhou/daodian.c": "xiao huoji",
"/d/lingzhou/jiuguan.c": "xiao er",
"/d/lumaji/zahuo.c": "san niang",
"/d/luoyang/dianpu.c": "dian zhu",
"/d/nanchang/qianzhuang.c": "zhou laoban",
"/d/nanchang/xihulou.c": "xiao er",
"/d/nanyang/jiulou1.c": "xiao er",
"/d/nanyang/kedian1.c": "xiao er",
"/d/ny/happyinn0.c": "zgx",
"/d/ny/herbshop.c": "herbalist",
"/d/ny/nyard.c": "liuh wheixin",
"/d/ny/school1.c": "liu anru",
"/d/suiye/shudian.c": "li laoban",
"/d/tanggu/qianyunge.c": "huo ji",
"/d/tanggu/wuqipu.c": "tie jiang",
"/d/yueyang/longsheshan.c": "xiao fan",
"/d/wuxi/datiepu.c": "tiejiang",
"/d/wuxi/qianzhuang.c": "wu xisheng",
"/d/wuxi/sanfengqiao.c": "liumang tou",
"/d/yixing/clshishi.c": "zhan fei",
]);

mapping *where=({
        (["party":        "少林派",
        "where" :         "/d/shaolin/guangchang2",]),
        (["party":      "武当派",
        "where" :       "/d/wudang/guangchang",]),
        (["party":       "灵鹫宫",
        "where" :       "/d/lingjiu/dating",]),
        (["party":       "华山派",
        "where" :       "/d/huashan/qunxianguan",]),
        (["party":       "丐帮",
         "where" :       "/d/city/pomiao",]),
         (["party":       "大理段家",
         "where" :       "/d/dali/wfdating",]),
       (["party":       "古墓派",
         "where" :       "/d/gumu/qianting",]),
              (["party":       "星宿派",
         "where" :       "/d/xingxiu/xxh2",]),
               (["party":       "神龙教",
         "where" :       "/d/shenlong/dating",]),
               (["party":       "逍遥派",
         "where" :       "/d/xiaoyao/qingcaop",]),
               (["party":       "铁掌帮",
         "where" :       "/d/tiezhang/wztang",]),
                (["party":       "昆仑派",
         "where" :       "/d/kunlun/guangchang",]),
               (["party":       "桃花岛",
         "where" :       "/d/taohua/dating",]),
              (["party":       "白驼山派",
         "where" :       "/d/baituo/dating",]),
               (["party":       "雪山寺",
         "where" :       "/d/xueshan/dadian",]),
               (["party":       "全真教",
         "where" :       "/d/quanzhen/datang1",]),
                (["party":       "姑苏慕容",
         "where" :       "/d/mr/yanziwu",]),
                (["party":       "凌霄城",
         "where" :       "/d/lingxiao/dadian",]),
                (["party":       "五毒教",
         "where" :       "/d/wudujiao/dating",]),
                (["party":       "唐门",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "飞天御剑流",
         "where" :       "/d/feitian/daochang",]),
                (["party":       "唐门",
         "where" :       "/d/tangmen/liujiantang",]),
                (["party":       "海南派",
         "where" :       "/d/hainan/jingtang",]),
                (["party":       "侠客岛",
         "where" :       "/d/xiakedao/shiroom24",]),
                (["party":       "崆峒派",
         "where" :       "/d/xibei/kongdong/xuanyuan_gong",]),
                (["party":       "梅庄",
         "where" :       "/d/meizhuang/xiaowu",]),
                (["party":       "靖海派",
         "where" :       "/d/jinghai/jhd19",]),
                (["party":       "红花会",
         "where" :       "/d/huizhu/zongduo",]),
                (["party":       "青城派",
         "where" :       "/d/qingcheng/qiandian",]),
                (["party":       "泰山派",
         "where" :       "/d/taishan/riguan",]),
                (["party":       "嵩山派",
         "where" :       "/d/songshan/chanyuan",]),
                (["party":       "衡山派",
         "where" :       "/d/henshan/zhurongdian",]),
                (["party":       "恒山派",
         "where" :       "/d/hengshan/baiyunan",]),
                (["party":       "中州苗家",
         "where" :       "/d/zhongzhou/miaojia_houting",]),
                (["party":       "关外胡家",
         "where" :       "/d/guanwai/xiaowu",]),
                (["party":       "雁荡派",
         "where" :       "/d/yandang/luoyan6",]),

 });

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "任务精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "随机任务系统已经开始。\n");
        call_out("auto_save", 8);
}

void auto_save()
{
        int i,mem,j;
        object ob, link_ob,*ob_list;
        string id;
/*ob_list = livings();
    ob_list = sort_array(livings(), "sort_user", this_object());
    j=0;
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
if(!ob->query_temp("nhdjoblb")) continue;
if(!ob->query_temp("nhdjobtg")) continue;
if (!environment(ob))  continue;
    j++;
    }
if (j>=38) 
    {
CHANNEL_D->do_channel( this_object(), "rumor", "江湖风平浪静，波澜不起。\n");
}
else
{*/
give_gift();
//}	
        remove_call_out("auto_save");
        //call_out("auto_save", 10);
        call_out("auto_save", 88+random(20));
}



void give_gift()
{
        string gift,msg;
        int amount;
        int i,combatexp,rd,j,num,factor,timep;
        object ob,me,npc,obn;
        object env,room2,*ob_list;
        object *players;
        string room,envn,envn2;
        string *dir2;
        string file;
string *roomlines,*env_rooms;
string location,local,fname,tag;
mapping quest,item,quests;
mapping all_static_npc;
mapping target;


tag = "10000";
if (random(2)==1) tag="15000";
if (random(3)==1) tag="20000";
if (random(4)==1) tag="30000";
if (random(5)==1) tag="50000";
if (random(6)==1) tag="80000";
if (random(7)==1) tag="100000";
if (random(8)==1) tag="130000";
if (random(9)==1) tag="170000";
if (random(10)==1)tag="220000";
if (random(11)==1)tag="300000";
if (random(12)==1)tag="450000";
if (random(13)==1)tag="600000";
if (random(14)==1)tag="800000";
if (random(15)==1)tag="1000000";
if (random(16)==1)tag="2000000";
             
                      
target=where[random(sizeof(where))];

me=this_player();
env_rooms = keys(citynpc);
room = env_rooms[random(sizeof(env_rooms))];
env = load_object(room);

if (!env) log_file("log",sprintf("随机任务错误记录：%s\n",room));
if (objectp(npc = present(citynpc[room], env)))
{
 if (objectp(npc))
{
	seteuid(geteuid(this_object()));

dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
envn2=room;

npc->set_temp("nhdjoblb",0);
npc->delete_temp("nhdjoblb");

npc->set_temp("nhdjoben",0);
npc->delete_temp("nhdjoben");

npc->set_temp("nhdjobtg",0);
npc->delete_temp("nhdjobtg");

npc->set_temp("nhdjobsc",0);
npc->delete_temp("nhdjobsc");
rd=random(9);
//rd=8;
switch( rd )
{
case 0:
     quest = QUESTS_D(tag)->query_quest();
     if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (!quest) log_file("log",sprintf("武林送货错误记录：%s\n",file));
if (quest["quest"])
{
npc->set_temp("nhdjoblb","武林送货");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",quest["quest"]);
npc->set_temp("nhdjobsc","武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+HIM"有批货物要送到 "+quest["quest_city"]+HIM" 的"+quest["quest"]+HIM"手上。\n");
log_file("taskjob",envn+":"+npc->query("name")+"有批货物要送到 "+quest["quest_city"]+" 的"+quest["quest"]+"手上。\n");
}
break;

case 1:
file = read_file("/clone/medicine/map4");	
if (!file)
	file = read_file("/clone/medicine/map4");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
npc->set_temp("nhdjoblb","边疆御敌");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",location);
npc->set_temp("nhdjobsc","边疆御敌:敌人出现在"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+"听说在"+room+HIM"有批外族武士在图谋不轨。\n");
log_file("taskjob",envn+":"+npc->query("name")+"听说在"+room+"有批外族武士在图谋不轨。\n");
}
}
else log_file("log",sprintf("边疆御敌错误记录：%s\n",file));
break;


case 2:	
room2=load_object(target["where"]+".c");
if (room2)
{
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;		
npc->set_temp("nhdjoblb","门派守护");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",target["where"]+".c");
npc->set_temp("nhdjobsc","门派守护:敌人出现在"+target["party"]+"的"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+"听说有批黑道人物要进攻"+target["party"]+HIM"。\n");
log_file("taskjob",envn+":"+npc->query("name")+"听说有批黑道人物要进攻"+target["party"]+"。\n");
}
}
else log_file("log",sprintf("门派任务错误记录：%s\n",target["where"]+".c"));
break;

case 3:
file = read_file("/clone/medicine/map1");	
if (!file)
	file = read_file("/clone/medicine/map1");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
npc->set_temp("nhdjoblb","江湖追杀");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",location);
npc->set_temp("nhdjobsc","江湖追杀:通缉犯出现在"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+"听说有个通缉犯在"+room+HIM"附近出没。\n"NOR);
log_file("taskjob",envn+":"+npc->query("name")+"听说有个通缉犯在"+room+"附近出没。\n");
}
}
else log_file("log",sprintf("江湖追杀错误记录：%s\n",file));
break;

case 4:

file = read_file("/clone/medicine/map22");	
if (!file)
	file = read_file("/clone/medicine/map22");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
npc->set_temp("nhdjoblb","保镖护送");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",location);
npc->set_temp("nhdjobsc","保镖护送:护送到"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+HIM"有个朋友要护送到"+room+HIM"。\n"NOR);
log_file("taskjob",envn+":"+npc->query("name")+"有个朋友要护送到"+room+"。\n");
}
}
else log_file("log",sprintf("保镖护送错误记录：%s\n",file));
break;

case 5:

file = read_file("/clone/medicine/map1");	
if (random(3)==0) file = read_file("/clone/medicine/map3");	
if (!file)
	file = read_file("/clone/medicine/map1");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
npc->set_temp("nhdjoblb","宝物争夺");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",location);
npc->set_temp("nhdjobsc","宝物争夺:宝物出现在"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":听说"+npc->query("name")+HIM"的一件宝物被抢走了。\n"NOR);
log_file("taskjob",envn+":听说"+npc->query("name")+"的一件宝物被抢走了。\n");
}
}
else log_file("log",sprintf("宝物争夺错误记录：%s\n",file));
break;

case 6:

file = read_file("/clone/medicine/map22");	
if (!file)
	file = read_file("/clone/medicine/map22");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
npc->set_temp("nhdjoblb","人物探寻");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",location);
npc->set_temp("nhdjobsc","人物探寻:朋友出现在"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":听说"+npc->query("name")+HIM"的一个朋友需要护送。\n"NOR);
log_file("taskjob",envn+":听说"+npc->query("name")+"的一个朋友需要护送。\n");
}
}
else log_file("log",sprintf("人物探寻错误记录：%s\n",file));
break;

case 7:

quest = QUESTW_D(tag)->query_quest();	
if (!quest) log_file("log",sprintf("寻找物品错误记录：%s\n",file));
if (quest["quest"])
{
npc->set_temp("nhdjoblb","寻找物品");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",quest["quest"]);
npc->set_temp("nhdjobsc","寻物:物品听说在"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( npc, "rumor", envn+":听说"+npc->query("name")+HIM"在找"+quest["quest_city"]+HIM"的"+quest["quest"]+HIM"。\n"NOR);
log_file("taskjob",envn+":听说"+npc->query("name")+"在找"+quest["quest_city"]+"的"+quest["quest"]+"。\n");
}
break;


case 8:

file = read_file("/clone/medicine/map3");	
if (random(3)==0) file = read_file("/clone/medicine/map1");
if (!file)
	file = read_file("/clone/medicine/map3");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
npc->set_temp("nhdjoblb","情报刺探");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",local);
npc->set_temp("nhdjobsc","情报刺探:目标:"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":听说"+npc->query("name")+HIM"想得到"+room+HIM"的情报。\n"NOR);
log_file("taskjob",envn+":听说"+npc->query("name")+"想得到"+room+"的情报。\n");
}
}
else log_file("log",sprintf("情报刺探错误记录：%s\n",file));
break;

default:
     quest = QUESTS_D(tag)->query_quest();
     if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (!quest) log_file("log",sprintf("武林送货错误记录：%s\n",file));
if (quest["quest"])
{
npc->set_temp("nhdjoblb","武林送货");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",quest["quest"]);
npc->set_temp("nhdjobsc","武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( npc, "rumor", envn+":听说"+npc->query("name")+HIM"有批货物要送到 "+quest["quest_city"]+HIM" 的"+quest["quest"]+HIM"手上。\n"NOR);
log_file("taskjob",envn+":听说"+npc->query("name")+"有批货物要送到 "+quest["quest_city"]+" 的"+quest["quest"]+"手上。\n");
}
}

}
}

}



void give_gift2()
{
    object where, ob, *ob_list;
    int i,j;
    string stri;
    string *dir2;
    string room;
object me;
    seteuid(getuid());

me=this_player();
    ob_list = livings();
    ob_list = sort_array(livings(), "sort_user", this_object());
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
if(!ob->query_temp("nhdjoblb")) continue;
if(!ob->query_temp("nhdjobtg")) continue;
    j++;

ob->delete_temp("nhdjoblb");
ob->delete_temp("nhdjobtg");
ob->delete_temp("nhdjobsc");
ob->delete_temp("nhdjoben");
    }
//tell_object(me,HIC"关闭"+j+"个随机任务。\n"NOR);

}


int give_gift3(int rd,object npc,object me)
{
        string gift,msg;
        int amount;
        int i,combatexp,j,num,factor,timep;
        object ob,obn;
        object env,room2,*ob_list;
        object letter,letter2;
        object *players;
        string room,envn,envn2;
        string *dir2;
        string file;
string *roomlines,*env_rooms;
string location,local,fname,tag;
mapping quest,item,quests;
mapping all_static_npc;
mapping target;


tag = "10000";
if (random(2)==1) tag="15000";
if (random(3)==1) tag="20000";
if (random(4)==1) tag="30000";
if (random(5)==1) tag="50000";
if (random(6)==1) tag="80000";
if (random(7)==1) tag="100000";
if (random(8)==1) tag="130000";
if (random(9)==1) tag="170000";
if (random(10)==1)tag="220000";
if (random(11)==1)tag="300000";
if (random(12)==1)tag="450000";
if (random(13)==1)tag="600000";
if (random(14)==1)tag="800000";
if (random(15)==1)tag="1000000";
if (random(16)==1)tag="2000000";
             
                      
target=where[random(sizeof(where))];

env = environment(npc);

if (!env) log_file("log",sprintf("随机任务错误记录：%s\n",room));

seteuid(geteuid(this_object()));

dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");


//rd=random(9);
//rd=8;

if (me->query("hdjob2lb") || me->query("quest"))
{
rd=18;
//me->set_temp("tjoblx",0);
//me->delete_temp("tjoblx");
return 1;
}
me->add_temp("tjoblx",1);
me->apply_condition("taskjob_busy",16);
if ((int)me->query_temp("tjoblx",1)>=7 && !me->query("hdjob2lb") && !me->query("quest"))
{
file = read_file("/clone/medicine/map1");	
if (random(2)==0) file = read_file("/clone/medicine/map4");
if (!file)
	file = read_file("/clone/medicine/map1");
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/map1");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
me->set_temp("hdjob2lb","悬赏");
me->set_temp("hdjob2tg",local);
me->set_temp("hdjob2sc","悬赏:有个恶贼出现在"+room);
me->set_temp("roomjob",local);
//message_vision("$n说道,最后有一个事。是这样的:" +  me->query_temp("hdjob2sc") + "。\n", me, npc);
message_vision("$N终于找出这一系列事件的背后的人出面在"+room+"附近。一定要为武林除害(citan)！\n", me);
rd=18;
}	
return 1;
}	

if (rd<18)
{
switch( rd )
{
case 0:
     quest = QUESTS_D(tag)->query_quest();
     if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (!quest) log_file("log",sprintf("武林送货错误记录：%s\n",file));
if (quest["quest"])
{
//message_vision("$n说道,还有一个事。是这样的:" + "武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"] + "。\n", me, npc);
        letter = new("/quest/task/huowo");
        letter->set("nhwtg",quest["quest"]);
        letter->set("long"," "+"武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]+"\n");
        letter->move(me);
//message_vision("$n说道,货物就麻烦你了一定要好好送到,对方正急着用呢。\n", me, npc);
me->set_temp("nhdjob2lb","武林送货");
me->set_temp("nhdjob2tg",quest["quest"]);
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 任务内容:"+"武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]);
}
break;

case 1:
file = read_file("/clone/medicine/map4");	
if (!file)
	file = read_file("/clone/medicine/map4");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
me->set_temp("nhdjob2lb","边疆御敌");
me->set_temp("nhdjob2tg",location);
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 边疆御敌:敌人出现在"+room);
me->set_temp("roomjob",local);
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$n说道,听说敌军人马，一路烧杀而来。一定要保卫好大好河山。\n", me, npc);
//message_vision("$N得知,听说敌军人马，一路烧杀而来。一定要保卫好大好河山。\n", me);
}
}
else log_file("log",sprintf("边疆御敌错误记录：%s\n",file));
break;


case 2:	
room2=load_object(target["where"]+".c");
if (room2)
{
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;		
me->set_temp("nhdjob2lb","门派守护");
me->set_temp("nhdjob2tg",target["where"]+".c");
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 门派守护:敌人出现在"+target["party"]+"的"+room);
me->set_temp("roomjob",local);
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$N得知,近日黑道联盟要有大举动，形势不妙。一定要消灭这些敌人。\n", me);
}
}
else log_file("log",sprintf("门派任务错误记录：%s\n",target["where"]+".c"));
break;

case 3:
file = read_file("/clone/medicine/map1");	
if (!file)
	file = read_file("/clone/medicine/map1");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
me->set_temp("nhdjob2lb","江湖追杀");
me->set_temp("nhdjob2tg",location);
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/boss");
       letter->move(location);
//call_out("destroying", 0, letter, location);
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 江湖追杀:通缉犯" + letter->query("name") + "出现在"+room);
zujinpc(me,letter);	
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$n说道,听说武林公敌:" + letter->query("name") + "在"+room+"附近出现。\n", me, npc);
//message_vision("$n说道,一定要把他除去。只要找到他，格杀勿论！\n", me, npc);
//message_vision("$N得知,听说武林公敌:" + letter->query("name") + "在"+room+"附近出现。\n", me);

}
}
else log_file("log",sprintf("江湖追杀错误记录：%s\n",file));
break;

case 4:

file = read_file("/clone/medicine/map22");	
if (!file)
	file = read_file("/clone/medicine/map22");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
me->set_temp("nhdjob2lb","保镖护送");
me->apply_condition("taskjob_busy",22);
me->set_temp("nhdjob2tg",location);
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 保镖护送:护送到"+room);
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/hsnpc");
       letter->move(environment(me));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("hstg",me->query_temp("nhdjob2tg"));
letter->set("hsr",me->query("id"));
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$n说道,我的朋友:" + letter->query("name") + "想到"+room+"去 麻烦你护送一下吧。\n", me, npc);
//message_vision("$n说道,希望你们一路顺风 平安到达。\n", me, npc);
//message_vision("$N得知" + letter->query("name") + "想到"+room+"去。\n", me);

}
}
else log_file("log",sprintf("保镖护送错误记录：%s\n",file));
break;

case 5:

file = read_file("/clone/medicine/map1");	
if (random(3)==0) file = read_file("/clone/medicine/map3");	
if (!file)
	file = read_file("/clone/medicine/map1");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
me->set_temp("nhdjob2lb","宝物争夺");
me->set_temp("nhdjob2tg",location);
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/boss2");
       letter->move(location);
letter2 = new("/quest/task/mijian");
letter2->set("killbyn",npc->query("id"));
letter2->move(letter);
letter2->set("killbyn",npc->query("id"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 宝物争夺:追杀" + letter->query("name") + " 宝物出现在"+room);
zujinpc(me,letter);	
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$n说道,我有一件宝物给" + letter->query("name") + "抢走了，帮我找回吧。\n", me, npc);
//message_vision("$n说道,一定帮我抢回来额。用他的血来给邪门歪道一个警告。\n", me, npc);
//message_vision("$N得知一件宝物给" + letter->query("name") + "抢走了。\n", me);
}
}
else log_file("log",sprintf("宝物争夺错误记录：%s\n",file));
break;

case 6:

file = read_file("/clone/medicine/map22");	
if (!file)
	file = read_file("/clone/medicine/map22");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
me->set_temp("nhdjob2lb","人物探寻");
me->apply_condition("taskjob_busy",22);
me->set_temp("nhdjob2tg",location);
room2=load_object(location);
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/hsnpc");
       letter->move(room2);
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("hstg",base_name(environment(npc))+".c");
letter->set("hsr",me->query("id"));
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 人物探寻:朋友" + letter->query("name") + " 出现在"+room);

//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$n说道,我的朋友" + letter->query("name") + "在"+room+" 麻烦你把他护送到我这吧。\n", me, npc);
//message_vision("$n说道,一路顺风 平安归来。\n", me, npc);
//message_vision("$N得知" + letter->query("name") + "在"+room+" 需要护送。\n", me);
}
}
else log_file("log",sprintf("人物探寻错误记录：%s\n",file));
break;

case 7:

quest = QUESTW_D(tag)->query_quest();	
if (!quest) log_file("log",sprintf("寻找物品错误记录：%s\n",file));
if (quest["quest"])
{
me->set_temp("nhdjob2lb","寻找物品");
me->set_temp("nhdjob2tg",quest["quest"]);
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 寻物:寻找 "+quest["quest_city"]+"的"+quest["quest"]);
npc->set_temp("nhdjobxh",quest["quest"]);
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
}
break;


case 8:

file = read_file("/clone/medicine/map3");	
if (random(3)==0) file = read_file("/clone/medicine/map1");
if (!file)
	file = read_file("/clone/medicine/map3");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
if (local)
{
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
me->set_temp("nhdjob2lb","情报刺探");
me->set_temp("nhdjob2tg",local);
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+" 情报刺探:目标:"+room);
me->set_temp("roomjob",local);
me->set_temp("nhdjob2tg",local);
//message_vision("$n说道,还有这样一个事。是这样的:" + me->query_temp("nhdjob2sc") + "。\n", me, npc);
//message_vision("$n说道,这个事再简单不过了,请尽快去刺探吧。\n", me, npc);
}
}
else log_file("log",sprintf("情报刺探错误记录：%s\n",file));
break;

default:
     quest = QUESTS_D(tag)->query_quest();
     if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (!quest) log_file("log",sprintf("武林送货错误记录：%s\n",file));
if (quest["quest"])
{
//message_vision("$n说道,还有一个事。是这样的:" + " 武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"] + "。\n", me, npc);
        letter = new("/quest/task/huowo");
        letter->set("nhwtg",quest["quest"]);
        letter->set("long"," "+"武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]+"\n");
        letter->move(me);
//message_vision("$n说道,货物就麻烦你了一定要好好送到,对方正急着用呢。\n", me,npc);
me->set_temp("nhdjob2lb","武林送货");
me->set_temp("nhdjob2tg",quest["quest"]);
me->set_temp("nhdjob2sc","来源:"+envn+":"+npc->query("name")+"任务内容:"+"武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]);
}
}
return 1;
}
}
/*
void destroying(object obj, object ob)
{   
 obj->move(ob);
   return;      
}
*/

string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山";

if (str=="binghuodao")  

	output="冰火岛";

if (str=="city")  

	output="扬州";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城";

if (str=="city4" || str=="changan")   

	output="长安城";

if (str=="dali")  

	output="大理";

if (str=="emei")  

	output="娥眉山";

if (str=="foshan")  

	output="佛山";

if (str=="gaibang")  

	output="丐帮";

if (str=="gaochang")  

	output="高昌迷宫";

if (str=="guanwai")  

	output="关外";

if (str=="guiyun")  

	output="归云庄";

if (str=="gumu")  

	output="古墓派";

if (str=="hangzhou")  

	output="杭州";

if (str=="heimuya")  

	output="黑木崖";

if (str=="hengshan")  

	output="恒山";

if (str=="henshan")  

	output="衡山";

if (str=="huanghe")  

	output="黄河九曲";

if (str=="huashan")  

	output="华山";

if (str=="jinshe")  

	output="金蛇山洞";

if (str=="lingjiu")  

	output="灵鹫宫";

if (str=="lingzhou")  

	output="灵州";

if (str=="meizhuang")  

	output="梅庄";

if (str=="mingjiao")  

	output="明教";

if (str=="qingcheng")  

	output="青城山";

if (str=="quanzhen")  

	output="全真派";

if (str=="quanzhou")  

	output="泉州";

if (str=="shaolin")  

	output="少林寺";

if (str=="shenlong")  

	output="神龙岛";

if (str=="songshan")  

	output="嵩山";

if (str=="suzhou")  

	output="苏州";

if (str=="taishan")  

	output="泰山";

if (str=="taohua")  

	output="桃花岛";

if (str=="tianlongsi")  

	output="天龙寺";

if (str=="wanjiegu")  

	output="万劫谷";

if (str=="wudang")  

	output="武当山";

if (str=="xiakedao")  

	output="侠客岛";

if (str=="xiangyang")  

	output="襄阳城";

if (str=="xiaoyao")  

	output="逍遥林";

if (str=="xingxiu")  

	output="星宿海";

if (str=="xueshan")  

	output="雪山寺";

if (str=="xuedao")  

	output="大雪山";

if (str=="mr")  

	output="慕容世家";

if (str=="kunlun")  

	output="昆仑山";

if (str=="tiezhang")  

	output="铁掌门";

if (str=="huizhu")  

	output="回族部落";

if (str=="yinju")  

	output="一灯大师居";

if (str=="menggu")  

	output="蒙古草原";

if (str=="qianjin")  

	output="北京千金楼";

if (str=="lingshedao")  

	output="灵蛇岛";

if (str=="ruzhou")  

	output="汝州城";

if (str=="kunming")  

	output="昆明";

if (str=="jingzhou")  

	output="荆州";

if (str=="yanjing")  

	output="盛京";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州";

if (str=="jyguan")  

	output="嘉峪关";

if (str=="changcheng")  

	output="长城";

if (str=="fairyland")  

	output="红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村";

if (str=="feihu")  

	output="闯王宝藏";

if (str=="wuguan")  

	output="襄阳武馆";

if (str=="village")  

	output="华山村";

if (str=="taohuacun")  

	output="桃花村";

if (str=="pingan")  

	output="平安城";

if (str=="lingxiao")  

	output="凌霄城";

if (str=="wudujiao")  

	output="五毒教";

if (str=="hj")  

	output="天山草原";
if (str=="dali/yuxu")  

	output="大理玉虚观";
if (str=="dali/wuliang")  

	output="大理无量山";
if (str=="huanghe/yyd")  

	output="黄河萧府";
if (str=="kaifeng")  

	output="开封城";
if (str=="feitian")  

	output="飞天御剑流";
if (str=="japan")  

	output="日本神户";
if (str=="tangmen")  

	output="唐门";
if (str=="luoyang")  

	output="洛阳城";

if (str=="chengdu" || str=="city3")  

	output="成都";

if (str=="baihuagu")  

	output="百花谷";

if (str=="heizhao")  

	output="百花谷黑沼";

if (str=="jiaxing")  

	output="嘉兴";

if (str=="shiliang")  

	output="温家庄";

if (str=="wuyi")  

	output="武夷山区";

if (str=="yanping")  

	output="延平城";
	

if (str=="jiangling")  
{
	output="江陵城";
}

if (str=="yueyang")  
{
	output="岳阳城";	
}

if (str=="qilian")  
{
	output="祁连山";	
}

if (str=="shouxihu")  
{
	output="瘦西湖";	
}

if (str=="wuxi")  
{
	output="无锡城";	
}

if (str=="yixing")  
{
	output="宜兴城";	
}
if (str=="taiwan")  
{
	output="台湾";	
}
if (str=="nanyang")  
{
	output="南阳";	
}
if (str=="nanshaolin")  
{
	output="南少林";	
}

if (str=="cangzhou")  
{
	output="沧州";	
}

if (str=="tanggu")  
{
	output="塘沽城";	
}

if (str=="yunhe")  
{
	output="京杭运河";	
}

if (str=="hainan")  
{
	output="海南岛";	
}

if (str=="jindezheng")  
{
	output="景德镇";	
}

if (str=="yandang")  
{
	output="雁荡山";	
}

if (str=="jinling")  
{
	output="金陵城";	
}

if (str=="sandboy")  
{
	output="江南农村";	
}

if (str=="huangshan")  
{
	output="黄山";	
}

if (str=="yubifeng")  
{
	output="玉笔峰";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽长白山";	
}

if (str=="annan")  
{
	output="安南";	
}

if (str=="taiyuan")  
{
	output="太原";	
}

if (str=="hefei")  
{
	output="合肥";	
}

if (str=="jiujiang")  
{
	output="九江";	
}

if (str=="baling")  
{
	output="巴陵";	
}

if (str=="xinjiang")  
{
	output="新疆";	
}
if (str=="dingxiang")  
{
	output="定襄";	
}
if (str=="suiye")  
{
	output="碎叶";	
}
if (str=="lumaji")
{
	output="鹿马集";	
}


if (str=="houjizhen")
{
	output="侯集镇";	
}

if (str=="zuojiacun")
{
	output="华亭府";	
}

if (str=="biancheng")
{
	output="边城";	
}


if (str=="jinghai")
{
	output="靖海派";	
}


if (str=="huayin")
{
	output="铜山村";	
}

if (str=="xiyu")
{
	output="西域区域";	
}

if (str=="heifeng")
{
	output="黑风寨";	
}
if (str=="linzhi")
{
	output="西藏林芝地区";	
}


if (str=="cloud" )  
{
	output="东北绮云镇";	
}

if (str=="xinan")
{
	output="西南区域";	
}



if (str=="mayi")  
{
	output="马邑边疆";	
}
if (str=="xuzhou")  
{
	output="徐州城";	
}
if (str=="jinan")  
{
	output="济南城";	
}
if (str=="guizhou")  
{
	output="贵阳城";	
}

if (str=="nanchang")  
{
	output="南昌城";	
}


if (str=="changsha")  
{
	output="长沙城";	
}


if (str=="zhongzhou")  
{
	output="中州城";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北";	
}

if (str=="tianshui")  
{
	output="天水城";	
}

if (str=="datong")  
{
	output="大同府";	
}
if (str=="ny")  
{
	output="宁远城";	
}
if (str=="fengtian")  
{
	output="盛京城";	
}

if (str=="yanmen")  
{
	output="燕门关";	
}
if (str=="cloud")  
{
	output="绮云镇";	
}
if (str=="xueting")  
{
	output="雪亭镇";	
}
if (str=="fuzhou")  
{
	output="福州";	
}
if (str=="welcome")  
{
	output="古村";	
}
if (!output)  
{
	output="未知区域";	
}

if (output=="")  
{
	output="未知区域";	
}


return output;
}
void zujinpc(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)*2/3;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<100)
        maxskill=100;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}

void zujinpc2(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)/2;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<50)
        maxskill=50;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}