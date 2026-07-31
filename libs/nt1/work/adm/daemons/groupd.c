// group_questd.c

inherit F_DBASE;

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <command.h>
#include <npc/name.h>
#include <npc/chinese.c>
#include <npc/japanese.c>
#include <npc/european.c>
#include <npc/masia.c>
#include <npc/indian.c>

#define IDLE 900
#define MAX_MOVED       5

mapping levels = ([
//      combat_exp   skill_level
        200000      : 100,               // level 1
        200000      : 100,               // level 2
        200000      : 100,               // level 3
        800000      : 125,               // level 4
        800000      : 125,               // level 5
        800000      : 125,               // level 6
        1000000     : 150,               // level 7
        1000000     : 150,               // level 8
        1000000     : 150,               // level 9
        2500000     : 250,               // level 10
        2500000     : 250,               // level 11
        2500000     : 250,               // level 12
        5000000     : 350,               // level 13
        5000000     : 350,               // level 14
        9000000     : 450,               // level 15
        15000000    : 500,               // level 16
        17000000    : 550,               // level 17
]);

mapping family = ([
        "少林寺"   : ({ "/d/shaolin/zoulang1","/d/shaolin/hsyuan1",
                       "/d/shaolin/luohan1","/d/shaolin/luohan5",
                       "/d/shaolin/guangchang4","/d/shaolin/zoulang8",
                       "/d/shaolin/wuchang2","/d/shaolin/banruo2",
                       "/d/shaolin/bagua2","/d/shaolin/zhulin4", }),
        "武当派"   : ({ "/d/wudang/wdroad1","/d/wudang/gyroad1",
                       "/d/wudang/jindian","/d/wudang/shanlu4",
                       "/d/wudang/wuyaling","/d/wudang/zixiaogate",
                       "/d/wudang/taizipo", }),
        "全真教"   : ({ "/d/quanzhen/shanlu4","/d/quanzhen/shijie7",
                       "/d/quanzhen/houshan","/d/quanzhen/datang3", }),
        "华山派"   : ({ "/d/huashan/buwei1","/d/huashan/qunxianguan",
                       "/d/huashan/songling1", }),
        "雪山寺"   : ({ "/d/xueshan/hubian1","/d/xueshan/chang",}),
        "灵鹫宫"   : ({ "/d/lingjiu/changl1","/d/lingjiu/liangong",
                       "/d/lingjiu/huayuan","/d/lingjiu/changl6",}),
        "峨嵋派"   : ({ "/d/emei/jinding","/d/emei/woyunan",
                       "/d/emei/hcazhengdian","/d/emei/xiaolu1", }),
        "桃花岛"   : ({ "/d/taohua/road1","/d/taohua/daojufang", }),
        "神龙教"   : ({ "/d/shenlong/damen","/d/shenlong/wuchang", }),
        "古墓派"   : ({ "/d/gumu/zhenting","/d/gumu/qianting", }),
        "星宿派"   : ({ "/d/xingxiu/xxh1","/d/xingxiu/xxh2", }),
        "逍遥派"   : ({ "/d/xiaoyao/qingcaop","/d/xiaoyao/xiaodao4", }),
        "血刀门"   : ({ "/d/xuedao/shandong2","/d/xuedao/syabi", }),
        "慕容世家" : ({ "/d/yanziwu/shuwu","/d/yanziwu/yimen", }),
        "关外胡家" : ({ "/d/guanwai/xiaowu","/d/guanwai/xiaoyuan",}),
        "段氏皇族" : ({ "/d/dali/neitang","/d/dali/chahua7",
                       "/d/dali/chahua3","/d/dali/wfdating", }),
        "欧阳世家" : ({ "/d/baituo/dating","/d/baituo/huayuan",
                       "/d/baituo/houyuan", }),
]);

static mapping place = ([
        "北京东城": ({
                        "/d/beijing/cagc_e","/d/beijing/caroad_e1",
                        "/d/beijing/caroad_e2","/d/beijing/zahuo",
                        "/d/beijing/yancao","/d/beijing/xingchang",
                        "/d/beijing/wang_4","/d/beijing/chaoyang_dao1",
                        "/d/beijing/chaoyang_dao2","/d/beijing/chaoyangmen",
                        "/d/beijing/wang_6","/d/beijing/wang_8",
                        "/d/beijing/xiyuan","/d/beijing/xiyuanup",
                        "/d/beijing/wang_10","/d/beijing/wang_9",
                        "/d/beijing/wang_1","/d/beijing/wang_3",
                        "/d/beijing/wang_5","/d/beijing/wang_7",
                        "/d/beijing/wang_8","/d/beijing/quanjude",
                        "/d/beijing/quanjudeup","/d/beijing/dong_1",
                        "/d/beijing/dong_3","/d/beijing/dongchang_men",
                        "/d/beijing/dongchang","/d/beijing/xiaochang",
                        "/d/beijing/weifu_men","/d/beijing/wang_2",
                        "/d/beijing/dong_2","/d/beijing/guozijian",
                     }),
        "北京西城" : ({
                        "/d/beijing/niaoshi","/d/beijing/xi_1",
                        "/d/beijing/caroad_w1","/d/beijing/yangliu1",
                        "/d/beijing/yangliu2","/d/beijing/yangliu3",
                        "/d/beijing/qingmu_men","/d/beijing/qingmu_dayuan",
                        "/d/beijing/qingmu_fang3","/d/beijing/qingmu_fang1",
                        "/d/beijing/caroad_w1","/d/beijing/caroad_w2",
                        "/d/beijing/cagc_w","/d/beijing/tiananmen",
                        "/d/beijing/cagc_s","/d/beijing/tianqiao",
                        "/d/beijing/yong_1","/d/beijing/duchang",
                        "/d/beijing/huiying","/d/beijing/huiyingup",
                        "/d/beijing/yong_2","/d/beijing/tiepu",
                        "/d/beijing/yong_3","/d/beijing/fu_2",
                        "/d/beijing/hai_men","/d/beijing/hai_dayuan",
                        "/d/beijing/hai_fang","/d/beijing/hai_huating",
                        "/d/beijing/hai_dating","/d/beijing/hai_houyuan",
                        "/d/beijing/mianguan","/d/beijing/fu_1",
                        "/d/beijing/tiantan_n","/d/beijing/tiantan",
                        "/d/beijing/qiao","/d/beijing/hgmen_s",
                        "/d/beijing/gaosheng","/d/beijing/xi_2",
                        "/d/beijing/huichuntang","/d/beijing/bei_2",
                        "/d/beijing/bei_2","/d/beijing/bei_4",
                        "/d/beijing/di_1","/d/beijing/di_3",
                        "/d/beijing/caishi","/d/beijing/ximenkou",
                        "/d/beijing/shi_1","/d/beijing/guandao_1",
                        "/d/beijing/guandao_2","/d/beijing/huangling",
                        "/d/beijing/qingmu_dating",
                     }),
        "扬州城"   : ({ 
                        "/d/city/zuixianlou","/d/city/beidajie2",
                        "/d/city/beimen","/d/city/beidajie1",
                        "/d/city/xidajie1","/d/city/yamen",
                        "/d/city/ximen","/d/city/dongdajie1",
                        "/d/city/zahuopu","/d/city/dongdajie2",
                        "/d/city/dongmen",
                     }),
	 "长安城"   : ({
                        "/d/changan/baihu2","/d/changan/beian-dadao",
                        "/d/changan/beian-daokou","/d/changan/bingying1",
                        "/d/changan/bingying2","/d/changan/bei-chengmen",
                        "/d/changan/qixiang3","/d/changan/qixiang2",
                        "/d/changan/tea-shop","/d/changan/fruit-shop",
                        "/d/changan/qixiang1","/d/changan/jiulou",
                        "/d/changan/jiulou2","/d/changan/yongtai-beikou",
                        "/d/changan/zhubaohang","/d/changan/yongtai-dadao1",
                        "/d/changan/yongtai-dadao2","/d/changan/yongtai-dadao3",
                        "/d/changan/huiwenge","/d/changan/xian-daokou",
                        "/d/changan/xi-chengmen","/d/changan/bingying3",
                        "/d/changan/yongtai-dadao5","/d/changan/yongtai-nankou",
                        "/d/changan/baozipu","/d/changan/huarui1",
                        "/d/changan/mianguan","/d/changan/huarui3",
                        "/d/changan/huadian","/d/changan/bingying5",
                        "/d/changan/huarui4","/d/changan/xiaojinghu",
                        "/d/changan/huarui4","/d/changan/huarui5",
                        "/d/changan/zahuopu","/d/changan/huarui5",
                        "/d/changan/huarui6","/d/changan/tuchangguan",
                        "/d/changan/liande-nankou","/d/changan/xiaojiuguan",
                        "/d/changan/liande-dadao5","/d/changan/xiaojia-qianyuan",
                        "/d/changan/liande-dadao4","/d/changan/dongan-daokou",
                        "/d/changan/dong-chengmen","/d/changan/bingying6",
                        "/d/changan/liande-dadao3","/d/changan/liande-dadao2",
                        "/d/changan/liande-dadao1","/d/changan/liande-beikou",
                        "/d/changan/xiyuan","/d/changan/qixiang6",
                        "/d/changan/yaopu","/d/changan/weapon-shop",
                        "/d/changan/bank","/d/changan/qunyulou",
                        "/d/changan/fufeng2","/d/changan/fufeng3",
                        "/d/changan/fufeng4","/d/changan/xian-dadao",
                        "/d/changan/fufeng5","/d/changan/qinglong1",
                        "/d/changan/baoxiangsi","/d/changan/qinglong2",
                        "/d/changan/nanan-dadao","/d/changan/qinglong3",
                        "/d/changan/yamen","/d/changan/fengxu5",
                        "/d/changan/fengxu4","/d/changan/lingyange",
                        "/d/changan/fengxu3","/d/changan/fengxu2",
                        "/d/changan/dongan-dadao","/d/changan/fengxu1",
                        "/d/changan/baihu3","/d/changan/guozijian",
                     }),
        "成都城"   : ({
                        "/d/city3/shuduroad2","/d/city3/shuduroad1",
                        "/d/city3/eastroad2","/d/city3/eastroad1",
                        "/d/city3/northroad3","/d/city3/northroad2",
                        "/d/city3/northgate","/d/city3/northroad1",
                        "/d/city3/bingqidian","/d/city3/westroad3",
                        "/d/city3/yaodian","/d/city3/westroad2",
                        "/d/city3/westgate","/d/city3/westroad1",
                        "/d/city3/qingyanggong","/d/city3/southroad3",
                        "/d/city3/wuhoucigate","/d/city3/liubeidian",
                        "/d/city3/wuhouci","/d/city3/southroad2",
                        "/d/city3/southgate","/d/city3/tiduroad",
                        "/d/city3/southroad1","/d/city3/eastroad3",
                        "/d/city3/wangjianglou","/d/city3/eastroad2",
                        "/d/city3/eastroad1",
                     }),
        "苏州城"   : ({
                        "/d/suzhou/beimen","/d/suzhou/beidajie2",
                        "/d/suzhou/beidajie1","/d/suzhou/xiyuan",
                        "/d/suzhou/canlangting","/d/suzhou/dongdajie1",
                        "/d/suzhou/hutong1","/d/suzhou/leitai",
                        "/d/suzhou/hutong2","/d/suzhou/hutong3",
                        "/d/suzhou/dongdajie2","/d/suzhou/dongmen",
                        "/d/suzhou/yaopu","/d/suzhou/datiepu",
                        "/d/suzhou/baodaiqiao","/d/suzhou/nandajie1",
                        "/d/suzhou/yanyutang","/d/suzhou/zhenquting",
                        "/d/suzhou/wenmeige","/d/suzhou/lixuetang",
                        "/d/suzhou/zhipoxuan","/d/suzhou/shuyuan",
                        "/d/suzhou/chaguan","/d/suzhou/nandajie2",
                        "/d/suzhou/liuyuan","/d/suzhou/hehuating",
                        "/d/suzhou/gumujiaohe","/d/suzhou/chitang",
                        "/d/suzhou/nanmen","/d/suzhou/tingyu",
                        "/d/suzhou/xidajie1","/d/suzhou/bingying",
                        "/d/suzhou/yunhematou","/d/suzhou/xidajie2",
                        "/d/suzhou/xuanmiao","/d/suzhou/shuchang",
                        "/d/suzhou/ximen",
                     }),
        "杭州城"   : ({
                        "/d/hangzhou/suti2", "/d/hangzhou/jujingyuan",
                        "/d/hangzhou/liuzhuang", "/d/hangzhou/road19",
                        "/d/hangzhou/huangniling", "/d/hangzhou/qinglindong",
                        "/d/hangzhou/dadao1","/d/hangzhou/xilingqiao",
                        "/d/hangzhou/road9","/d/hangzhou/baoshishan",
                        "/d/hangzhou/yuelang","/d/hangzhou/liuzhuang1",
                        "/d/hangzhou/huagang","/d/hangzhou/hupaoquan", 
                        "/d/hangzhou/yuhuangsd","/d/hangzhou/yuhuangshan",
                        "/d/hangzhou/shanlu6","/d/hangzhou/shanlu7",
                        "/d/hangzhou/yuhuangsj","/d/hangzhou/road18",
                        "/d/hangzhou/road20","/d/hangzhou/suti7",
                        "/d/hangzhou/suti7","/d/hangzhou/suti6",
                        "/d/hangzhou/suti5","/d/hangzhou/suti4",
                        "/d/hangzhou/suti3","/d/hangzhou/suti2",
                        "/d/hangzhou/road7","/d/hangzhou/road8",
                        "/d/hangzhou/road9","/d/hangzhou/road10",
                        "/d/hangzhou/road11","/d/hangzhou/road12",
                        "/d/hangzhou/road13","/d/hangzhou/road14",
                        "/d/hangzhou/road15","/d/hangzhou/road16",
                        "/d/hangzhou/xizhaoshan","/d/hangzhou/road17",
                        "/d/hangzhou/road18","/d/hangzhou/qingbomen",
                        "/d/hangzhou/jujingyuan","/d/hangzhou/liulangqiao",
                        "/d/hangzhou/yuquan","/d/hangzhou/dadao1",
                        "/d/hangzhou/dadao2","/d/hangzhou/dalu1",
                        "/d/hangzhou/road1", "/d/hangzhou/road2",
                        "/d/hangzhou/road4", "/d/hangzhou/road3",
                        "/d/hangzhou/hongchunqiao","/d/hangzhou/jiulou",
                        "/d/hangzhou/duanqiao","/d/hangzhou/baiti",
                        "/d/hangzhou/pinghuqiuyue","/d/hangzhou/fangheting",
                        "/d/hangzhou/gushan","/d/hangzhou/gushanpingtai",
                        "/d/meizhuang/shijie","/d/meizhuang/xiaolu",
                        "/d/meizhuang/gate","/d/hangzhou/shanlu8",
                        "/d/hangzhou/shanlu2","/d/hangzhou/shanlu3",
                        "/d/hangzhou/shanlu5","/d/hangzhou/shanlu6",
                        "/d/hangzhou/shanlu7","/d/hangzhou/tulu1",
                        "/d/hangzhou/yanxiadong","/d/hangzhou/maojiabu",
                        "/d/hangzhou/shuiledong","/d/hangzhou/manjuelong",
                     }),
        "襄阳城"   : ({
                        "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
                        "/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
                        "/d/xiangyang/walls2","/d/xiangyang/walle3",
                        "/d/xiangyang/walln4","/d/xiangyang/juyilang", 
                        "/d/xiangyang/bingying1","/d/xiangyang/chaguan",
                        "/d/xiangyang/northroad2","/d/xiangyang/xiaorong2",
                        "/d/xiangyang/xiaorong1","/d/xiangyang/jiekou2",
                        "/d/xiangyang/eastroad2","/d/xiangyang/eastroad1",
                        "/d/xiangyang/biaoju","/d/xiangyang/eastjie2",
                        "/d/xiangyang/eastjie3","/d/xiangyang/bingying2",
                        "/d/xiangyang/eastgate2","/d/xiangyang/walle1",
                        "/d/xiangyang/walle5","/d/xiangyang/walle7",
                        "/d/xiangyang/walle2","/d/xiangyang/walle4",
                        "/d/xiangyang/walle6","/d/xiangyang/walle8",
                        "/d/xiangyang/mujiang","/d/xiangyang/eastjie2",
                        "/d/xiangyang/eastjie3","/d/xiangyang/jiedao",
                        "/d/xiangyang/minju2","/d/xiangyang/eastjie1",
                        "/d/xiangyang/jiangjungate","/d/xiangyang/yaopu",
                        "/d/xiangyang/anfugate","/d/xiangyang/anfupailou",
                        "/d/xiangyang/southjie1","/d/xiangyang/southjie2",
                        "/d/xiangyang/southjie3","/d/xiangyang/xuetang",
                        "/d/xiangyang/nixianglou","/d/xiangyang/duchang",
                        "/d/xiangyang/tiejiangpu","/d/xiangyang/bingying3",
                        "/d/xiangyang/walls1","/d/xiangyang/walls3",
                        "/d/xiangyang/walls5","/d/xiangyang/walls7",
                        "/d/xiangyang/walls4","/d/xiangyang/walls6",
                        "/d/xiangyang/walls8","/d/xiangyang/westjie1",
                        "/d/xiangyang/westjie2","/d/xiangyang/westjie3",
                        "/d/xiangyang/guofugate","/d/xiangyang/guofuyuan",
                        "/d/xiangyang/guofuting","/d/xiangyang/guofuhuayuan",
                        "/d/xiangyang/guofukefang","/d/xiangyang/guofuwoshi",
                        "/d/xiangyang/juyiyuan","/d/xiangyang/juyilianwu2",
                        "/d/xiangyang/juyilianwu1","/d/xiangyang/juyilang",
                        "/d/xiangyang/juyihuayuan","/d/xiangyang/walln8",
                        "/d/xiangyang/juyiwupin","/d/xiangyang/dajiaochang",
                        "/d/xiangyang/bingying4","/d/xiangyang/westgate1",
                        "/d/xiangyang/wallw1","/d/xiangyang/wallw2",
                        "/d/xiangyang/wallw3","/d/xiangyang/wallw4",
                        "/d/xiangyang/wallw5","/d/xiangyang/wallw6",
                        "/d/xiangyang/wallw7","/d/xiangyang/wallw8",
                        "/d/xiangyang/westroad1","/d/xiangyang/westroad2",
                        "/d/xiangyang/shudian","/d/xiangyang/hutong1",
                        "/d/xiangyang/hutong2","/d/xiangyang/xinluofang",
                        "/d/xiangyang/jiekou1","/d/xiangyang/northgate2",
                        "/d/xiangyang/walln1","/d/xiangyang/walln2",
                        "/d/xiangyang/walln3","/d/xiangyang/walln5",
                        "/d/xiangyang/walln6","/d/xiangyang/walln7",
                     }),
        "大理城" : ({
                        "/d/dali/dahejiewest","/d/dali/tusifu",
                        "/d/dali/tusimentang","/d/dali/tusiyishi",
                        "/d/dali/tusihouting","/d/dali/taihejiekou",
                        "/d/dali/shizilukou","/d/dali/baiyiziguan",
                        "/d/dali/dahejieeast","/d/dali/baiyiminju",
                        "/d/dali/stoneshop","/d/dali/garments",
                        "/d/dali/taiheeast","/d/dali/yaoshop",
                        "/d/dali/piandian","/d/dali/wangfulu",
                        "/d/dali/yushanfang","/d/dali/zhengdian",
                        "/d/dali/hualang","/d/dali/yuhuayuan",
                        "/d/dali/gongmen","/d/dali/qiandian",
                        "/d/dali/yujie","/d/dali/paifang",
                        "/d/dali/sheguta","/d/dali/qingchi",
                     }), 
        "大理北城" : ({
                        "/d/wanjiegu/entrance","/d/wanjiegu/shan_road4",
                        "/d/wanjiegu/shan_road1","/d/wanjiegu/shan_road2",
                        "/d/wanjiegu/port2","/d/wanjiegu/bridge",
                        "/d/wanjiegu/port","/d/wanjiegu/riverside3",
                        "/d/wanjiegu/riverside2","/d/dali/road3",
                     }), 
        "大理西城" : ({
                        "/d/dali/shanlin","/d/dali/gelucheng",
                        "/d/dali/biluoshan","/d/dali/zhenxiong",
                        "/d/dali/wuyiminju4","/d/dali/yixibu",
                        "/d/dali/gaolishan2","/d/dali/gaolishan1",
                        "/d/dali/atoubu","/d/dali/lushui",
                        "/d/dali/badidian","/d/dali/lushuieast",
                        "/d/dali/shanlu2","/d/dali/shanlu4",
                        "/d/dali/shanlu4","/d/dali/shanlu5",
                        "/d/dali/minadian",
                     }), 
        "大理东城" : ({
                        "/d/dali/sanglin","/d/dali/yangzong",
                        "/d/dali/nongtian4","/d/dali/dalangan1",
                        "/d/dali/luojiadian","/d/dali/yanan1",
                        "/d/dali/bijishan","/d/dali/yanan2",
                        "/d/dali/hudiequan","/d/dali/xiaodao1",
                        "/d/dali/yuxuguanqian","/d/dali/yuxuguan",
                        "/d/dali/langan1","/d/dali/langan2",
                        "/d/dali/shanlu8","/d/dali/shanlu7",
                        "/d/dali/qingxi","/d/dali/dadieshui",
                        "/d/dali/chahuashan6","/d/dali/chahuashan5",
                     }),
        "大理南城" : ({
                        "/d/dali/feilihu","/d/dali/zhulou2",
                        "/d/dali/zhulou1","/d/dali/qingzhulin",
                        "/d/dali/nongtian1","/d/dali/zhulin",
                        "/d/dali/feilihusouth","/d/dali/yujia",
                        "/d/dali/hexi","/d/dali/zhulin2",
                        "/d/dali/longkou","/d/dali/feilihueast",
                        "/d/dali/wuding","/d/dali/xizhou",
                     }),
]);

string *nations = ({ "日本", "荷兰", "天竺", "日本", "日本",
                     "日本", "英吉利", "法兰西", "西班牙", "葡萄牙",
                     "比利时"});

string *foreigner = ({ "佣兵团", "探险队", "侵略军", "亡命团伙", "流窜犯" });

string *chinese = ({ "黑风寨", "斧头帮", "山西土匪", "山东响马", "湘西土匪",
                     "乌龙岗强盗", "太行山土匪", "落日峰毛贼", "荒漠大盗" });

int all_enemy = 0;
object *all_killer = ({});

void add_killer(object killer);
void be_killed(int num);
int query_enemy();
object *query_killer();
object create_npc(string nation, int lvl);
void init_npc_skill(object ob, int lvl);
void start_quest(int num);
varargs void place_npc(object ob,string arg,string the_type,int lvl,string pp);
void random_move(object ob);
int not_wizard(object ob);

void add_killer(object killer)
{
        if (!objectp(killer) || !userp(killer))
                return;

        if (member_array(killer,all_killer) == -1)
                all_killer += ({ killer });

        return;
}


void be_killed(int num)
{
        all_enemy -= num;
        return;
}

int query_enemy()
{
        return all_enemy;
}

object *query_killer()
{
        return all_killer;
}

void ready_to_start()
{
        remove_call_out("start_quest");
        // call_out("start_quest", IDLE, random(6));
        call_out("start_quest", IDLE, 5);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "任务精灵");
        CHANNEL_D->do_channel( this_object(), "task", "群组任务系统已经启动。");
        ready_to_start();
}

int clean_up()
{
        return 1;
}

object create_npc(string nation, int lvl)
{
        object ob;

        switch (nation)
        {
        case "中国":
                ob = new(CLASS_D("generate") + "/quest_chinese");
                NPC_D->generate_cn_name(ob);
                break;
        case "日本":
                ob = new(CLASS_D("generate") + "/quest_japanese");
                NPC_D->generate_jp_name(ob);
                break;
        case "英吉利":
        case "法兰西":
        case "西班牙":
        case "葡萄牙":
        case "比利时":
        case "荷兰":
                ob = new(CLASS_D("generate") + "/quest_european");
                generate_e_name(ob);
                break;
        case "天竺":
                ob = new(CLASS_D("generate") + "/quest_indian");
                generate_in_name(ob);
                break;
        }
        if (lvl >= 7)
                ob->set("auto_perform",1);
        ob->set("nation", nation);
        init_npc_skill(ob, lvl);

        return ob;
}

// set the the level of the npc's skill
void init_npc_skill(object ob, int lvl)
{
        int sk_lvl;
        string *ks;
        int i;
        int exp;
        mixed my;

        if (lvl < 1) lvl = 1;
        if (lvl >= sizeof(levels)) lvl = sizeof(levels) - 1;

        exp = sort_array(keys(levels), 1)[lvl - 1];
      	 my = ob->query_entire_dbase();
        ob->set("combat_exp", exp);
        sk_lvl = levels[exp];
        my["jing"] = my["eff_jing"] = my["max_jing"] = sk_lvl * 5;
        my["qi"] = my["eff_qi"] = my["max_qi"] = sk_lvl * 10;
        my["jingli"] = my["max_jingli"] = sk_lvl * 3;
        my["neili"] = my["max_neili"] = sk_lvl * 5;
        if (! ob->query_skills())
                return;
        ks = keys(ob->query_skills());
        for (i = 0; i < sizeof(ks); i++)
                ob->set_skill(ks[i], sk_lvl);
}

void start_quest(int num)
{
        string *kp;
        string p,arg,title,pp;
        string startroom;
        object pos,*all_user,ob;
        string the_nation,the_enemy;
        mapping fam_map,party_map;
        int i,all,lvl;

        ready_to_start();

        fam_map = ([]);
        party_map = ([]);

        switch (num)
        {
                case 0:
                case 1:
                case 2:
                        CHANNEL_D->do_channel( this_object(), "task", "群组任务系
统开始产生外敌入侵任务。");
                        arg = "外敌入侵";
                        kp = keys(place);
                        p = kp[random(sizeof(kp))];
                        all_user = users();
                        all_user = filter_array(all_user,(: $1->query("combat_ex
p") > 200000 :));
                        all_user = filter_array(all_user,(: not_wizard :));
                        all = sizeof(users())/2;
                        if (all<10) return;			//玩家太少，终止本次进程。
                        if (all>60) all = 60;
                        all_enemy = all;
                        all_killer = ({});
                        the_nation = nations[random(sizeof(nations))];
                        title = HIW + the_nation + NOR + " " + HIY + 
                                foreigner[random(sizeof(foreigner))] +NOR;
                        for (i = 0;i < all;i ++)
                        {
                                lvl = random(15) + 1;
                                ob = create_npc(the_nation,lvl);
                                place_npc(ob,arg,p,lvl);
                                ob->set("title",title);
                                ob->random_move();
                                ob->random_move();
                                ob->random_move();
                                ob->random_move();
                        }
                        message("story",HIR "【外敌入侵】" NOR+WHT "据说一批来自
" + NOR + HIY + 
                                  the_nation + NOR + WHT +
                                  "的侵略者来到了中国！\n" NOR,users() ); 
                        message("story",HIR "【外敌入侵】" NOR+WHT "根据前线最新
报告，这批入侵者目前在" +
                                  NOR + HIY + p + NOR + WHT + "出没频繁！\n" NOR
,users() ); 
                        message("story",HIR "【外敌入侵】" NOR+WHT "各位同胞，让
我们团结起来，紧握手中" +
                                  "武器，奋勇杀敌，给胆敢侵犯我们中华的敌人狠狠的
打击！\n" NOR,users() ); 
                        break;
                case 3:
                        CHANNEL_D->do_channel( this_object(), "task", "群组任务系
统开始产生门派入侵任务。");
                        arg = "门派";
                        kp = keys(family);
                        for (i = 0;i < sizeof (kp);i ++)
                        {
                                p = kp[i];
                                all_user = users();
                                all_user = filter_array(all_user,(: $1->query("f
amily/family_name") == $2 :),p);
                                all_user = filter_array(all_user,(: not_wizard :
));
                                if (!sizeof(all_user)) continue;	//该门派没有玩家
                                fam_map += ([ p:sizeof(all_user) ]);
                        }
                        if (!sizeof(fam_map)) return;		//MUD中没有属于任何一个门
                        kp = keys(fam_map);
                        p = kp[random(sizeof(kp))];
                        all = fam_map[p];
                        if (all < 5) all = 5;
                        if (all > 20) all = 30 - random(10);
                        all_enemy = all;
                        all_killer = ({});
                        the_nation = "中国";
                        the_enemy = chinese[random(sizeof(chinese))];
                        title = HIY + p + NOR + HIW + "仇家" + NOR + " " + HIY +
 
                                the_enemy + NOR;
                        for (i = 0;i < all;i ++)
                        {
                                lvl = random(15) + 1;
                                ob = create_npc(the_nation,lvl);
                                place_npc(ob,arg,p,lvl);
                                ob->set("title",title);
                                ob->random_move();
                                ob->random_move();
                                ob->random_move();
                                ob->random_move();
                        }
                        message("story",HIR "【门派入侵】" NOR+WHT "据说" + NOR 
+ HIY + 
                                  the_enemy + NOR + WHT + 
                                  "最近又重新出现在江湖，个个携带了武器，一副要找
茬的样子！\n" NOR,users() ); 
                        message("story",HIR "【门派入侵】" NOR+WHT "根据这些人私
下漏出的口风，他们这次是冲着" + 
                                  NOR + HIY + p + NOR + WHT + "来的！\n" NOR ,users());
                        message("story",HIR "【门派入侵】" NOR+WHT "士可杀不可辱
，" + NOR + HIY + p + NOR + WHT +
                                  "还不一起行动起来，把来敌统统打回老家？\n" NOR
,users()); 
                        break;
                default:
                        CHANNEL_D->do_channel( this_object(), "sys", "群组任务系统开始产生帮派挑衅任务。");
                        arg = "帮派";
                        all_user = users();
                        all_user = filter_array(all_user,(: $1->query("bunch") :
));
                        all_user = filter_array(all_user,(: not_wizard :));
                        for (i = 0;i < sizeof (all_user);i ++)
                        {
                                p = all_user[i]->query("bunch/bunch_name");
                                if (!stringp(p)) continue;
                                if (!party_map[p])
                                        party_map[p] = 1;
                                else
                                        party_map[p] += 1;
                        }                                
                        kp = keys(party_map);
                        for (i = 0;i < sizeof(kp);i++)
                                if (party_map[kp[i]] < 3)
                                        map_delete(party_map,kp[i]);
                        if (!sizeof(party_map)) return;
                        kp = keys(party_map);
                        p = kp[random(sizeof(kp))];
                        all = party_map[p] * 2;
                        if (all < 10) all = 20 - random(11);
                        if (all > 20) all = 30 - random(10);
                        all_enemy = all;
                        all_killer = ({});
                        the_nation = "中国";
                        the_enemy = chinese[random(sizeof(chinese))];
                        title = HIY + p + NOR + HIW + "仇家" + NOR + " " + HIY +
 
                                the_enemy + NOR;
                        kp = keys(place);
                        pp = kp[random(sizeof(kp))];
                        for (i = 0;i < all;i ++)
                        {
                                lvl = random(15) + 1;
                                ob = create_npc(the_nation,lvl);
                                place_npc(ob,arg,p,lvl,pp);
                                ob->set("title",title);
                                ob->set("is_attacking", p);
                                ob->random_move();
                                ob->random_move();
                                ob->random_move();
                                ob->random_move();
                        }
                        message("story",HIR "【帮派挑衅】" NOR+WHT "据说" + NOR + HIY + the_enemy + NOR + WHT +
                                  "最近又重新出现在江湖，个个携带了武器，一副要找茬的样子！\n" NOR,users() ); 
                        message("story",HIR "【帮派挑衅】" NOR+WHT "江湖中有人见到他们正在" + NOR + HIY + pp + NOR + WHT +
                                  "集结，气势汹汹，目空一切的样子！\n" NOR, users() ); 
                        message("story",HIR "【帮派挑衅】" NOR+WHT "根据这些人私下漏出的口风，他们这次打定注意要铲平" + 
                                  NOR + HIY + p + NOR + WHT + "！\n" NOR, users() ); 
                        message("story",HIR "【帮派挑衅】" NOR+WHT "真是岂有此理，区区跳梁小丑，" + NOR + HIY + p + 
                                  NOR + WHT + "难道就真的怕了他们不成？\n" NOR , users() ); 
                        break;
        }
}

varargs void place_npc(object ob,string arg,string the_type,int lvl,string pp)
{
        string *kp,option;
        string p,startroom;
        object pos;

        switch (arg)
        {
                case "外敌入侵":
                        ob->set("my_type",arg);
                        startroom = place[the_type][random(sizeof(place[the_type
]))];
                        if (! objectp(pos = get_object(startroom)))
                                log_file("log", sprintf("error to place npc to %
s:%s\n",
                                                        the_type, startroom));
                        ob->set("place", the_type);
                        break;
                case "门派":
                        ob->set("my_type",arg);
                        ob->set("门派",the_type);
                        startroom = family[the_type][random(sizeof(family[the_type]))];
                        if (! objectp(pos = get_object(startroom)))
                                log_file("log", sprintf("error to place npc to %
s:%s\n",
                                                        the_type, startroom));
                        ob->set("place", the_type);
                        break;
                case "帮派":
                        ob->set("my_type",arg);
                        ob->set("帮派",the_type);
                        startroom = place[pp][random(sizeof(place[pp]))];
                        if (! objectp(pos = get_object(startroom)))
                                log_file("log", sprintf("error to place npc to %
s:%s\n",
                                                        the_type, startroom));
                        ob->set("place", pp);
                        break;
                        
        }

        switch (lvl)
        {
                case 1:
                case 2:
                case 3:
                        ob->set("nickname","小喽罗");
                        ob->set("bonus",150);
                        break;
                case 4:
                case 5:
                case 6:
                        ob->set("nickname","普通成员");
                        ob->set("bonus",200);
                        break;
                case 7: 
                case 8:
                case 9:
                        ob->set("nickname","小头目");
                        ob->set("bonus",300);
                        break;
                case 10:
                case 11:
                case 12:
                        ob->set("nickname","大头目");
                        ob->set("bonus",500);
                        break;
                case 13:
                case 14:
                        ob->set("nickname","首领");
                        ob->set("bonus",800);
                        break;
                case 15:
                case 16:
                        ob->set("nickname","大首领");
                        ob->set("bonus",1000);
                        break;
                default:
                        ob->set("nickname","总首领");
                        ob->set("bonus",1500);
                        break;
        }
                        
        ob->move(pos);
        ob->set("startroom", startroom);
        ob->set_temp("moved", ({ }));
        message_vision("$N走了过来。\n", ob);
}

// random move
void random_move(object ob)
{
        mapping exits;
        string *moved;
        string dir;
        string *dirs;
        int i;

        moved = ob->query_temp("moved");
        if (! moved) moved = ({ });
        if (sizeof(moved) >= MAX_MOVED)
        {
                // out of range, move back
                dir = GO_CMD->query_reverse(moved[sizeof(moved) - 1]);
        } else
        {
                exits = environment(ob)->query("exits");
                dirs = keys(exits);
                for (i = 0; i < 12; i++)
                {
                	if (! sizeof(dirs))
                		return;
                        dir = dirs[random(sizeof(dirs))];
                        if (stringp(GO_CMD->query_reverse(dir)) &&
                            ! exits[dir]->query("no_fight"))
                                break;
                        dirs -= ({ dir });
                }
        }

        if (sizeof(moved) &&
            GO_CMD->query_reverse(dir) == moved[sizeof(moved) - 1])
        {
                // move back
                moved = moved[0..<2];
        } else
                moved += ({ dir });
        ob->set_temp("moved", moved);

        GO_CMD->main(ob, dir);
}

int not_wizard(object ob)
{
        if (wizardp(ob)) return 0;
        return 1;
}

