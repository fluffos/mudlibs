// liumang.c 流氓
#include <ansi.h>
inherit NPC;
string  zuji(string str);
#include "/quest/givegift.c"


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
"/d/beijing/dating.c":  "yl dizi",
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
"/d/city/beimen.c":  "guan bing",
"/d/city/beimen.c":  "ma chaoxing",
"/d/city/beimen.c":  "wu jiang",
"/d/city/beimendajie.c":  "ge ji",
"/d/city/bingyin.c":  "guan bing",
"/d/city/bingyin.c":  "shi qingshan",
"/d/city/bingyin.c":  "wang huaishui",
"/d/city/caibopu.c":  "gu bancheng",
"/d/city/caiyijiekou.c":  "ge ji",
"/d/city/caohebeijie.c":  "qiu xingxing",
"/d/city/caohebeijie.c":  "yang leishi",
"/d/city/caohecexiang.c":  "tang fan",
"/d/city/caohexiaojie.c":  "feng gongying",
"/d/city/caohexiaojie.c":  "you ke",
"/d/city/dangpu.c":  "tang nan",
"/d/city/dayuan.c":  "guan jia",
"/d/city/dayuan.c":  "jia ding",
"/d/city/fengreiroom.c":  "zhao junrong",
"/d/city/jiaowai10.c":  "jiang shangyou",
"/d/city/jiaowai13.c":  "mo bushou",
"/d/city/jiaowai2.c":  "qiu wanjia",
"/d/city/jiaowai4.c":  "zhao gouer",
"/d/city/jiaowai6.c":  "kuai huosan",
"/d/city/lichunyuan.c":  "mao shiba",
"/d/city/lichunyuan.c":  "wei chunfang",
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
"/d/dali/langan4.c":  "fangsha ji",
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
"/d/hangzhou/lingyin0.c":  "lao heshang",
"/d/hangzhou/lingyin3.c":  "kumu chanshi",
"/d/hangzhou/lingyinsi.c":  "lao heshang",
"/d/hangzhou/liuhe1.c":  "meng jianxiong",
"/d/hangzhou/liuhe2.c":  "xin yan",
"/d/hangzhou/liuhe2.c":  "zhou yi",
"/d/hangzhou/liuhe3.c":  "jiang sigen",
"/d/hangzhou/liuhe4.c":  "shi shuangying",
"/d/hangzhou/liuhe5.c":  "wei chunhua",
"/d/hangzhou/liuhe6.c":  "yang chengxie",
"/d/hangzhou/liuhe7.c":  "xu tianhong",
"/d/hangzhou/liuzhuang.c":  "jia ding",
"/d/hangzhou/maojiabu.c":  "old woman",
"/d/hangzhou/marryroom.c":  "hong niang",
"/d/hangzhou/qiantang.c":  "jian ke",
"/d/hangzhou/road12.c":  "li kexiu",
"/d/hangzhou/road12.c":  "qing bing",
"/d/hangzhou/road13.c":  "zhang zhaozhong",
"/d/hangzhou/road14.c":  "luo bing",
"/d/hangzhou/suti4.c":  "wuya",
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
"/d/jiangling/chaifang.c":  "wu kan",
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
"/d/jinan/mjroom.c":  "yang guifei",
"/d/jinan/prison.c":  "ding busan",
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
"/d/kaifeng/cangjing2.c":  "moheseng diyu",
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
"/d/kaifeng/yezhulin.c":  "xiao zhu",
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
"/d/luoyang/lvzuan.c":  "feng buping",
"/d/luoyang/lvzuan.c":  "jianzong dizi",
"/d/luoyang/lvzuan.c":  "yao hou",
"/d/luoyang/mudan.c":  "dou lv",
"/d/luoyang/mudan.c":  "er qiao",
"/d/luoyang/mudan.c":  "gejin zi",
"/d/luoyang/mudan.c":  "guifei shangyue",
"/d/luoyang/mudan.c":  "huolian bilv",
"/d/luoyang/mudan.c":  "jinyu jiaohui",
"/d/luoyang/mudan.c":  "lan furong",
"/d/luoyang/mudan.c":  "lantian yu",
"/d/luoyang/mudan.c":  "nihong huancai",
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
"/d/xiangyang/guangchang.c":  "guo jing",
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

void create()
{
	set_name("笑莫问", ({ "xlssi", "xlssi" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的流氓，长得倒是白白胖胖的，也许以前有过钱。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set("qi",1000000);
	set("max_qi",1000000);
	set("eff_qi",1000000);
	set("eff_jing",1000000);
	set("jing",1000000);
	set("max_jing",1000000);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
void init()
{
        add_action("give_gift6", "testjl");
        add_action("give_test", "tests");
        add_action("give_gift", "quests");
        add_action("give_gift2", "questf");
        add_action("give_gift3", "questt");
        add_action("give_gift4", "questhd");
        add_action("give_gift5", "testhd");

}

int give_test()
{

"/adm/daemons/taskd"->give_gift3(1,this_object(),this_player());
return 1;
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

rd=random(9);
if (wizardp(me) && me->query("jobtest")) rd=(int)me->query("jobtest");

//rd=8;
switch( rd )
{
case 0:
     quest = QUESTS_D(tag)->query_quest();
     if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (!quest) log_file("log",sprintf("武林送货错误记录：%s\n",file));
npc->set_temp("nhdjoblb","武林送货");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",quest["quest"]);
npc->set_temp("nhdjobsc","武林送货:送货到"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+HIM"有批货物要送到 "+quest["quest_city"]+HIM" 的"+quest["quest"]+HIM"手上。\n");
log_file("taskjob",envn+":"+npc->query("name")+"有批货物要送到 "+quest["quest_city"]+" 的"+quest["quest"]+"手上。\n");
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
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;	
npc->set_temp("nhdjoblb","边疆御敌");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",location);
npc->set_temp("nhdjobsc","边疆御敌:敌人出现在"+room);
CHANNEL_D->do_channel( npc, "rumor", envn+":"+npc->query("name")+"听说在"+room+HIM"有批外族武士在图谋不规。\n");
log_file("taskjob",envn+":"+npc->query("name")+"听说在"+room+"有批外族武士在图谋不规。\n");
}
else log_file("log",sprintf("边疆御敌错误记录：%s\n",file));
break;


case 2:	
room2=load_object(target["where"]+".c");
if (room2)
{
local=room2->query("short");
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
else log_file("log",sprintf("江湖追杀错误记录：%s\n",file));
break;

case 4:

file = read_file("/clone/medicine/map2");	
if (!file)
	file = read_file("/clone/medicine/map2");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
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
else log_file("log",sprintf("宝物争夺错误记录：%s\n",file));
break;

case 6:

file = read_file("/clone/medicine/map2");	
if (!file)
	file = read_file("/clone/medicine/map2");
if (file)
{
roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
local=room2->query("short");
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
else log_file("log",sprintf("人物探寻错误记录：%s\n",file));
break;

case 7:

quest = QUESTW_D(tag)->query_quest();	
if (!quest) log_file("log",sprintf("寻找物品错误记录：%s\n",file));
npc->set_temp("nhdjoblb","寻找物品");
npc->set_temp("nhdjoben",envn2);
npc->set_temp("nhdjobtg",quest["quest"]);
npc->set_temp("nhdjobsc","寻物:物品听说在"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( npc, "rumor", envn+":听说"+npc->query("name")+HIM"在找"+quest["quest_city"]+HIM"的"+quest["quest"]+HIM"。\n"NOR);
log_file("taskjob",envn+":听说"+npc->query("name")+"在找"+quest["quest_city"]+"的"+quest["quest"]+"。\n");
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
else log_file("log",sprintf("情报刺探错误记录：%s\n",file));
break;

default:
     quest = QUESTS_D(tag)->query_quest();
     if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();
if (!quest) log_file("log",sprintf("武林送货错误记录：%s\n",file));
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

void give_gift3()
{
    object where, ob, *ob_list;
    int i,j;
    object me=this_player();
    for(i=0; i<=38; i++)
    {
give_gift();
    }
    //i=i-1;
tell_object(me,HIC"开启"+i+"个随机任务。\n"NOR);

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
tell_object(me,HIC"关闭"+j+"个随机任务。\n"NOR);

}


void give_gift4()
{
        int i,combatexp,rd,j,num,factor,timep;
        object ob;
        object env,room2;
        object *players;
        string room;
        string *dir2;
        string file;
string *roomlines;
string location,local,fname;
mapping quest,item,npc,quests;
mapping target;
string envn;
object newob, *ob_list;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                  });
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
        players = users();
        if (sizeof(players) >= 3)
        {
                for (i = 0; i < 3; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->query_temp("hdjoblb")) continue;
                        env = environment(ob);
                        if (!env) continue;
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;
                        
                }
//                if (i >= 3) return;

                //if (objectp(env))
                //        tell_room(env, msg);
                //for (i = 0; i < amount; i++)
                //{
                //        ob = new(gift);
                //       ob->move(env);
                //}
if (objectp(env))
{
dir2=explode(base_name(env),"/");
room=zuji(dir2[1])+env->query("short");
combatexp = (int) (ob->query("combat_exp"));
rd=random(7);
rd=6;
//CHANNEL_D->do_channel( this_object(), "rumor", "玩家互动任务:"+ob->name()+"种类"+rd+"。\n");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             combatexp=combatexp/4;
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

if (rd==0)
{
        if (random(2) == 0 )
     quest = QUESTS_D(tag)->query_quest();
       else
     quest = QUESTH_D(tag)->query_quest();
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;

//        if(quest["quest_type"]=="杀")
//             tell_object(ob,"任务:到"+quest["quest_city"]+"把货物送给『"HIR+quest["quest"]+HIC"』。\n" NOR);
//        else
//             tell_object(ob,"任务:到"+quest["quest_city"]+"附近 的『"HIG+quest["quest"]+HIC"』手上。\n" NOR);
ob->set_temp("hdjoblb","送货");
ob->set_temp("hdjobtg",quest["quest"]);
ob->set_temp("hdjobsc","送货:"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"有批货物要送到"+quest["quest_city"]+"的"+quest["quest"]+"手上。\n");

}

if (rd==6)
{
seteuid(geteuid(this_object()));	
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
ob->set_temp("hdjoblb","悬赏");
ob->set_temp("hdjobtg",local);
ob->set_temp("hdjobsc","悬赏:有个恶贼出现在"+room);
CHANNEL_D->do_channel( this_object(), "rumor", ob->name()+"听说有个悬赏追杀的恶贼出现在"+room+"附近。\n");
}
}

if (rd==4)
{

ob->set_temp("hdjoblb","互动");
ob->set_temp("hdjobtg","互动");
ob->set_temp("hdjobsc","玩家互动任务");
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"有个礼物要送给某个玩家。\n");

}
if (rd==5)
{
target=where[random(sizeof(where))];
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
ob->set_temp("hdjoblb","江湖");
ob->set_temp("hdjoben",local);
ob->set_temp("hdjobtg",target["where"]+".c");
ob->set_temp("hdjobsc","有批黑道人物出现在"+target["party"]+"的"+room);
CHANNEL_D->do_channel( this_object(), "rumor", ob->query("name")+"听说有批黑道人物要进攻"+target["party"]+HIM"。\n");
}
}

}
if (rd==1)
{
quest = QUESTW_D(tag)->query_quest();	
        timep = quest["time"];
        if (!quest["time"]) timep=600;
        timep = timep+360;
        
//        if(quest["quest_type"]=="杀")
//             tell_object(ob,"任务:到"+quest["quest_city"]+"把货物送给『"HIR+quest["quest"]+HIC"』。\n" NOR);
//        else
//             tell_object(ob,"任务:到"+quest["quest_city"]+"附近 找回『"HIG+quest["quest"]+HIC"』。\n" NOR);
ob->set_temp("hdjoblb","寻物");
ob->set_temp("hdjobtg",quest["quest"]);
ob->set_temp("hdjobsc","寻物:"+quest["quest_city"]+"的"+quest["quest"]);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"想要找到"+quest["quest_city"]+"的"+quest["quest"]+"。\n");
}
if (rd==2)
{
seteuid(geteuid(this_object()));	
file = read_file("/clone/medicine/dynamic_location");
	if (ob->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (ob->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (ob->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (ob->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (ob->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");
if (!file)
	file = read_file("/clone/medicine/dynamic_location");

roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
//ob->apply_condition("roomjob",10);
//ob->set_temp("roomjob",local);
ob->set_temp("hdjoblb","刺探");
ob->set_temp("hdjobtg",local);
ob->set_temp("hdjobsc","刺探:"+room);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"想要得到"+room+"的情报。\n");
//tell_object(ob,"任务:到"+room+"去刺探一下情况(citan)。\n" NOR);
//CHANNEL_D->do_channel( this_object(), "rumor", "任务3。\n");
//CHANNEL_D->do_channel( this_object(), "rumor", "任务3:到"+room+"去刺探一下情况(citan)。\n");
//	  tell_object(ob,HIC"任务使说:我听说在『"HIR+room+HIC"』，发生了一些江湖事件。"+
//           "你赶快去『"HIR+local+HIC"』刺探(citan)一下吧。\n"NOR);
//if (wizardp(ob))
//	  tell_object(ob,GRN"WIZ信息:刺探位置『"YEL+fname+GRN"』。\n"NOR);
}

if (rd==3)
{
seteuid(geteuid(this_object()));	
file = read_file("/clone/medicine/dynamic_location");
	if (ob->query("combat_exp",1)<=2000000)
	file = read_file("/clone/medicine/dynamic_location1");
	else if (ob->query("combat_exp",1)<=4000000)
	file = read_file("/clone/medicine/dynamic_location2");
	else if (ob->query("combat_exp",1)<=6000000)
	file = read_file("/clone/medicine/dynamic_location3");
else if (ob->query("combat_exp",1)<=8000000)
	file = read_file("/clone/medicine/dynamic_location4");
else if (ob->query("combat_exp",1)>8000000)
	file = read_file("/clone/medicine/dynamic_location5");
if (!file)
	file = read_file("/clone/medicine/dynamic_location");

roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
if (!room2)
{
	file = read_file("/clone/medicine/dynamic_location");
	roomlines = explode(file,"\n");		
location = roomlines[random(sizeof(roomlines))];
room2=load_object(location);
}
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
//ob->apply_condition("roomjob",10);
//ob->set_temp("roomjob",local);
ob->set_temp("hdjoblb","仇杀");
ob->set_temp("hdjobtg",location);
ob->set_temp("hdjobsc","仇杀:"+room);
CHANNEL_D->do_channel( this_object(), "rumor", "听说:"+ob->name()+"有一个仇敌在"+room+"附近出现。\n");
}
}


if (random(2)==0)
{
   ob_list = users();
    newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];
if(newob->query("combat_exp",1)<100000 || !newob->query_temp("hdjob2tg") || !newob->query_temp("nhdjob2tg")) newob = ob_list[random(sizeof(ob_list))];

if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob && envn && newob->query("age",1)>=20)
{
newob->set_temp("hdjoblb","挑战");
newob->set_temp("hdjobtg",newob->query("id"));
newob->set_temp("hdjobsc","挑战"+newob->name());
CHANNEL_D->do_channel( this_object(), "rumor", "听说:有人悬赏挑战在"+envn+"附近的:"+newob->name()+"。\n");
}
}
}


if (1==1)
{
quest = QUESTS_D(tag)->query_quest();
if (random(2) == 0 ) quest = QUESTH_D(tag)->query_quest();	
if (quest["quest"])
{
   ob_list = users();
    newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("combat_exp",1)<100000) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob) || newob->query("age")<=19) newob = ob_list[random(sizeof(ob_list))];
if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob && envn && newob->query("age",1)>=20)
{
newob->set_temp("hdjoblb","会面");
newob->set_temp("hdjobtg",quest["quest"]);
newob->set_temp("hdjobsc","会面:"+quest["quest_city"]+"的"+quest["quest"]+"想见一下"+newob->name()+"。");
CHANNEL_D->do_channel( this_object(), "rumor", "听说"+quest["quest_city"]+"的"+quest["quest"]+"想见一下"+newob->name()+"。\n");
}
}
}
}

        }
}


stringji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山的";

if (str=="binghuodao")  

	output="冰火岛的";

if (str=="city")  

	output="扬州的";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城的";

if (str=="city4" || str=="changan")   

	output="长安城的";

if (str=="dali")  

	output="大理的";

if (str=="emei")  

	output="娥眉山的";

if (str=="foshan")  

	output="佛山的";

if (str=="gaibang")  

	output="丐帮的";

if (str=="gaochang")  

	output="高昌迷宫的";

if (str=="guanwai")  

	output="关外的";

if (str=="guiyun")  

	output="归云庄的";

if (str=="gumu")  

	output="古墓派的";

if (str=="hangzhou")  

	output="杭州的";

if (str=="heimuya")  

	output="黑木崖的";

if (str=="hengshan")  

	output="恒山的";

if (str=="henshan")  

	output="衡山的";

if (str=="huanghe")  

	output="黄河九曲的";

if (str=="huashan")  

	output="华山的";

if (str=="jinshe")  

	output="金蛇山洞的";

if (str=="lingjiu")  

	output="灵鹫宫的";

if (str=="lingzhou")  

	output="灵州的";

if (str=="meizhuang")  

	output="梅庄的";

if (str=="mingjiao")  

	output="明教的";

if (str=="qingcheng")  

	output="青城山的";

if (str=="quanzhen")  

	output="全真派的";

if (str=="quanzhou")  

	output="泉州的";

if (str=="shaolin")  

	output="少林寺的";

if (str=="shenlong")  

	output="神龙岛的";

if (str=="songshan")  

	output="嵩山的";

if (str=="suzhou")  

	output="苏州的";

if (str=="taishan")  

	output="泰山的";

if (str=="taohua")  

	output="桃花岛的";

if (str=="tianlongsi")  

	output="天龙寺的";

if (str=="wanjiegu")  

	output="万劫谷的";

if (str=="wudang")  

	output="武当山的";

if (str=="xiakedao")  

	output="侠客岛的";

if (str=="xiangyang")  

	output="襄阳城的";

if (str=="xiaoyao")  

	output="逍遥林的";

if (str=="xingxiu")  

	output="星宿海的";

if (str=="xueshan")  

	output="雪山寺的";

if (str=="xuedao")  

	output="大雪山的";

if (str=="mr")  

	output="慕容世家的";

if (str=="kunlun")  

	output="昆仑山的";

if (str=="tiezhang")  

	output="铁掌门的";

if (str=="huizhu")  

	output="回族部落的";

if (str=="yinju")  

	output="一灯大师居的";

if (str=="menggu")  

	output="蒙古草原的";

if (str=="qianjin")  

	output="北京千金楼的";

if (str=="lingshedao")  

	output="灵蛇岛的";

if (str=="ruzhou")  

	output="汝州城的";

if (str=="kunming")  

	output="昆明的";

if (str=="jingzhou")  

	output="荆州的";

if (str=="yanjing")  

	output="燕京的";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州的";

if (str=="jyguan")  

	output="兰州以北嘉峪关的";

if (str=="changcheng")  

	output="北京以北长城的";

if (str=="fairyland")  

	output="昆仑的红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村的";

if (str=="feihu")  

	output="闯王宝藏的";

if (str=="wuguan")  

	output="襄阳武馆的";

if (str=="village")  

	output="华山村的";

if (str=="taohuacun")  

	output="桃花村的";

if (str=="pingan")  

	output="平安城的";

if (str=="lingxiao")  

	output="凌霄城的";

if (str=="wudujiao")  

	output="五毒教的";

if (str=="hj")  

	output="天山。草原的";
if (str=="dali/yuxu")  

	output="大理玉虚观的";
if (str=="dali/wuliang")  

	output="大理无量山的";
if (str=="huanghe/yyd")  

	output="黄河萧府的";
if (str=="kaifeng")  

	output="开封城的";
if (str=="feitian")  

	output="飞天御剑流的";
if (str=="japan")  

	output="日本神户的";
if (str=="tangmen")  

	output="唐门的";
if (str=="luoyang")  

	output="洛阳城的";

if (str=="chengdu" || str=="city3")  

	output="成都的";

if (str=="baihuagu")  

	output="百花谷的";

if (str=="heizhao")  

	output="百花谷黑沼的";

if (str=="jiaxing")  

	output="嘉兴的";

if (str=="shiliang")  

	output="温家庄的";

if (str=="wuyi")  

	output="武夷山区的";

if (str=="yanping")  

	output="延平城的";
	

if (str=="jiangling")  
{
	output="江陵城的";
}

if (str=="yueyang")  
{
	output="岳阳城的";	
}

if (str=="qilian")  
{
	output="祁连山的";	
}

if (str=="shouxihu")  
{
	output="瘦西湖的";	
}

if (str=="wuxi")  
{
	output="无锡城的";	
}

if (str=="yixing")  
{
	output="宜兴城的";	
}
if (str=="taiwan")  
{
	output="台湾的";	
}
if (str=="nanyang")  
{
	output="南阳的";	
}
if (str=="nanshaolin")  
{
	output="南少林的";	
}

if (str=="cangzhou")  
{
	output="沧州的";	
}

if (str=="tanggu")  
{
	output="塘沽城的";	
}

if (str=="yunhe")  
{
	output="京杭运河的";	
}

if (str=="hainan")  
{
	output="海南岛的";	
}

if (str=="jindezheng")  
{
	output="景德镇的";	
}

if (str=="yandang")  
{
	output="雁荡山的";	
}

if (str=="jinling")  
{
	output="金陵城的";	
}

if (str=="sandboy")  
{
	output="江南农村的";	
}

if (str=="huangshan")  
{
	output="黄山的";	
}

if (str=="yubifeng")  
{
	output="玉笔峰的";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内的";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽 长白山的";	
}

if (str=="annan")  
{
	output="安南附近的";	
}

if (str=="taiyuan")  
{
	output="太原附近的";	
}

if (str=="hefei")  
{
	output="合肥附近的";	
}

if (str=="jiujiang")  
{
	output="九江附近的";	
}

if (str=="baling")  
{
	output="巴陵附近的";	
}

if (str=="xinjiang")  
{
	output="新疆附近的";	
}
if (str=="dingxiang")  
{
	output="定襄附近的";	
}
if (str=="suiye")  
{
	output="碎叶附近的";	
}


if (str=="mayi")  
{
	output="马邑边疆附近的";	
}
if (str=="xuzhou")  
{
	output="徐州城附近的";	
}
if (str=="jinan")  
{
	output="济南城附近的";	
}
if (str=="guizhou")  
{
	output="贵阳城附近的";	
}

if (str=="nanchang")  
{
	output="南昌城附近的";	
}


if (str=="changsha")  
{
	output="长沙城附近的";	
}


if (str=="zhongzhou")  
{
	output="中州城附近的";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北附近的";	
}

if (str=="tianshui")  
{
	output="天水城附近的";	
}

if (str=="datong")  
{
	output="大同府附近的";	
}
if (str=="ny")  
{
	output="宁远城附近的";	
}
if (str=="fengtian")  
{
	output="盛京城附近的";	
}

if (str=="yanmen")  
{
	output="燕门关附近的";	
}
if (str=="cloud")  
{
	output="绮云镇附近的";	
}
if (str=="xueting")  
{
	output="雪亭镇附近的";	
}
if (str=="welcome")  
{
	output="古村附近的";	
}
if (!output)  
{
	output="未知区域的";	
}

if (output=="")  
{
	output="未知区域的";	
}


return output;
}


int give_gift6()
{
object me=this_player();
//tell_object(me,HIC"开启奖励。\n"NOR);
"/adm/daemons/giftnew"->give_jl(me);	
return 1;
}	

void give_gift5()
{
        int i,combatexp,rd,j,num,factor,timep;
        object ob;
        object env,room2;
        object *players;
        string room;
        string *dir2;
        string file;
string *roomlines;
string location,local,fname;
mapping quest,item,npc,quests;
     
seteuid(geteuid(this_object()));	

	file = read_file("/clone/medicine/dynamic_location5");

roomlines = explode(file,"\n");		

for(i=0; i<sizeof(roomlines); i++)
{
location = roomlines[i];
room2=load_object(location);
//log_file("log",sprintf("地点信息错误记录：%s\n",location));
if (!room2) log_file("log",sprintf("地点信息错误记录：%s\n",location));
}

}


string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="白驼山的";

if (str=="binghuodao")  

	output="冰火岛的";

if (str=="city")  

	output="扬州的";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="北京城的";

if (str=="city4" || str=="changan")   

	output="长安城的";

if (str=="dali")  

	output="大理的";

if (str=="emei")  

	output="娥眉山的";

if (str=="foshan")  

	output="佛山的";

if (str=="gaibang")  

	output="丐帮的";

if (str=="gaochang")  

	output="高昌迷宫的";

if (str=="guanwai")  

	output="关外的";

if (str=="guiyun")  

	output="归云庄的";

if (str=="gumu")  

	output="古墓派的";

if (str=="hangzhou")  

	output="杭州的";

if (str=="heimuya")  

	output="黑木崖的";

if (str=="hengshan")  

	output="恒山的";

if (str=="henshan")  

	output="衡山的";

if (str=="huanghe")  

	output="黄河九曲的";

if (str=="huashan")  

	output="华山的";

if (str=="jinshe")  

	output="金蛇山洞的";

if (str=="lingjiu")  

	output="灵鹫宫的";

if (str=="lingzhou")  

	output="灵州的";

if (str=="meizhuang")  

	output="梅庄的";

if (str=="mingjiao")  

	output="明教的";

if (str=="qingcheng")  

	output="青城山的";

if (str=="quanzhen")  

	output="全真派的";

if (str=="quanzhou")  

	output="泉州的";

if (str=="shaolin")  

	output="少林寺的";

if (str=="shenlong")  

	output="神龙岛的";

if (str=="songshan")  

	output="嵩山的";

if (str=="suzhou")  

	output="苏州的";

if (str=="taishan")  

	output="泰山的";

if (str=="taohua")  

	output="桃花岛的";

if (str=="tianlongsi")  

	output="天龙寺的";

if (str=="wanjiegu")  

	output="万劫谷的";

if (str=="wudang")  

	output="武当山的";

if (str=="xiakedao")  

	output="侠客岛的";

if (str=="xiangyang")  

	output="襄阳城的";

if (str=="xiaoyao")  

	output="逍遥林的";

if (str=="xingxiu")  

	output="星宿海的";

if (str=="xueshan")  

	output="雪山寺的";

if (str=="xuedao")  

	output="大雪山的";

if (str=="mr")  

	output="慕容世家的";

if (str=="kunlun")  

	output="昆仑山的";

if (str=="tiezhang")  

	output="铁掌门的";

if (str=="huizhu")  

	output="回族部落的";

if (str=="yinju")  

	output="一灯大师居的";

if (str=="menggu")  

	output="蒙古草原的";

if (str=="qianjin")  

	output="北京千金楼的";

if (str=="lingshedao")  

	output="灵蛇岛的";

if (str=="ruzhou")  

	output="汝州城的";

if (str=="kunming")  

	output="昆明的";

if (str=="jingzhou")  

	output="荆州的";

if (str=="yanjing")  

	output="盛京的";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="兰州的";

if (str=="jyguan")  

	output="兰州以北嘉峪关的";

if (str=="changcheng")  

	output="北京以北长城的";

if (str=="fairyland")  

	output="昆仑的红梅山庄";

if (str=="sdxl")  

	output="剑魔独孤求败墓";

if (str=="jqg")  

	output="绝情谷";

if (str=="nio")  

	output="牛家村的";

if (str=="feihu")  

	output="闯王宝藏的";

if (str=="wuguan")  

	output="襄阳武馆的";

if (str=="village")  

	output="华山村的";

if (str=="taohuacun")  

	output="桃花村的";

if (str=="pingan")  

	output="平安城的";

if (str=="lingxiao")  

	output="凌霄城的";

if (str=="wudujiao")  

	output="五毒教的";

if (str=="hj")  

	output="天山。草原的";
if (str=="dali/yuxu")  

	output="大理玉虚观的";
if (str=="dali/wuliang")  

	output="大理无量山的";
if (str=="huanghe/yyd")  

	output="黄河萧府的";
if (str=="kaifeng")  

	output="开封城的";
if (str=="feitian")  

	output="飞天御剑流的";
if (str=="japan")  

	output="日本神户的";
if (str=="tangmen")  

	output="唐门的";
if (str=="luoyang")  

	output="洛阳城的";

if (str=="chengdu" || str=="city3")  

	output="成都的";

if (str=="baihuagu")  

	output="百花谷的";

if (str=="heizhao")  

	output="百花谷黑沼的";

if (str=="jiaxing")  

	output="嘉兴的";

if (str=="shiliang")  

	output="温家庄的";

if (str=="wuyi")  

	output="武夷山区的";

if (str=="yanping")  

	output="延平城的";
	

if (str=="jiangling")  
{
	output="江陵城的";
}

if (str=="yueyang")  
{
	output="岳阳城的";	
}

if (str=="qilian")  
{
	output="祁连山的";	
}

if (str=="shouxihu")  
{
	output="瘦西湖的";	
}

if (str=="wuxi")  
{
	output="无锡城的";	
}

if (str=="yixing")  
{
	output="宜兴城的";	
}
if (str=="taiwan")  
{
	output="台湾的";	
}
if (str=="nanyang")  
{
	output="南阳的";	
}
if (str=="nanshaolin")  
{
	output="南少林的";	
}

if (str=="cangzhou")  
{
	output="沧州的";	
}

if (str=="tanggu")  
{
	output="塘沽城的";	
}

if (str=="yunhe")  
{
	output="京杭运河的";	
}

if (str=="hainan")  
{
	output="海南岛的";	
}

if (str=="jindezheng")  
{
	output="景德镇的";	
}

if (str=="yandang")  
{
	output="雁荡山的";	
}

if (str=="jinling")  
{
	output="金陵城的";	
}

if (str=="sandboy")  
{
	output="江南农村的";	
}

if (str=="huangshan")  
{
	output="黄山的";	
}

if (str=="yubifeng")  
{
	output="玉笔峰的";	
}

if (str=="quanzhouchen")  
{
	output="泉州城内的";	
}

if (str=="qingzh")  
{
	output="青藏高原";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="高丽 长白山的";	
}

if (str=="annan")  
{
	output="安南附近的";	
}

if (str=="taiyuan")  
{
	output="太原附近的";	
}

if (str=="hefei")  
{
	output="合肥附近的";	
}

if (str=="jiujiang")  
{
	output="九江附近的";	
}

if (str=="baling")  
{
	output="巴陵附近的";	
}

if (str=="xinjiang")  
{
	output="新疆附近的";	
}
if (str=="dingxiang")  
{
	output="定襄附近的";	
}
if (str=="suiye")  
{
	output="碎叶附近的";	
}


if (str=="mayi")  
{
	output="马邑边疆附近的";	
}
if (str=="xuzhou")  
{
	output="徐州城附近的";	
}
if (str=="jinan")  
{
	output="济南城附近的";	
}
if (str=="guizhou")  
{
	output="贵阳城附近的";	
}

if (str=="nanchang")  
{
	output="南昌城附近的";	
}


if (str=="changsha")  
{
	output="长沙城附近的";	
}


if (str=="zhongzhou")  
{
	output="中州城附近的";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="西藏或藏北附近的";	
}

if (str=="tianshui")  
{
	output="天水城附近的";	
}

if (str=="datong")  
{
	output="大同府附近的";	
}
if (str=="ny")  
{
	output="宁远城附近的";	
}
if (str=="fengtian")  
{
	output="盛京城附近的";	
}

if (str=="yanmen")  
{
	output="燕门关附近的";	
}
if (str=="cloud")  
{
	output="绮云镇附近的";	
}
if (str=="xueting")  
{
	output="雪亭镇附近的";	
}
if (str=="welcome")  
{
	output="古村附近的";	
}
if (!output)  
{
	output="未知区域的";	
}

if (output=="")  
{
	output="未知区域的";	
}


return output;
}



