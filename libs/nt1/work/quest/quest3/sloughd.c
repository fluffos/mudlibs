// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sloughd.c 处理泥潭野老任务的守护进程

#include <ansi.h>

#pragma optimize
#pragma save_binary

// 定义提供给外部调用的接口函数
varargs public void   bonus(object who, mapping b, int flag);
public void   delay_bonus(object who, mapping b);

#define ONE_DAY                 (86400 / 365)
#define MAX_QUEST_LEVEL         3

mapping place = ([
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
                        "/d/beijing/weifu_men","/d/beijing/weifu_zoulang1",
                        "/d/beijing/weifu_dayuan","/d/beijing/weifu_zoulang2",
                        "/d/beijing/weifu_dating","/d/beijing/weifu_shufang",
                        "/d/beijing/dong_2","/d/beijing/guozijian",
                        "/d/beijing/wang_2",
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
                        "/d/beijing/fukedian","/d/beijing/kediandayuan",
                        "/d/beijing/hai_men","/d/beijing/hai_dayuan",
                        "/d/beijing/hai_fang","/d/beijing/hai_huating",
                        "/d/beijing/hai_dating","/d/beijing/hai_houyuan",
                        "/d/beijing/mianguan","/d/beijing/fu_1",
                        "/d/beijing/tiantan_n","/d/beijing/tiantan",
                        "/d/beijing/yongdingdao","/d/beijing/yongdingmen",
                        "/d/beijing/qiao","/d/beijing/hgmen_s",
                        "/d/beijing/gaosheng","/d/beijing/xi_2",
                        "/d/beijing/huichuntang","/d/beijing/bei_2",
                        "/d/beijing/kangfu_men","/d/beijing/kangfu_dayuan",
                        "/d/beijing/kangfu_zoulang1","/d/beijing/kangfu_dating",
                        "/d/beijing/kangfu_zoulang2","/d/beijing/kangfu_xifang",
                        "/d/beijing/kangfu_dongfang","/d/beijing/kangfu_shufang",
                        "/d/beijing/bei_2","/d/beijing/bei_4",
                        "/d/beijing/di_1","/d/beijing/di_3",
                        "/d/beijing/di_4","/d/beijing/aofu_men",
                        "/d/beijing/aofu_zoulang1","/d/beijing/aofu_dayuan",
                        "/d/beijing/aofu_dating","/d/beijing/aofu_zoulang2",
                        "/d/beijing/aofu_houyuan","/d/beijing/aofu_zoulang3",
                        "/d/beijing/aofu_shufang","/d/beijing/aofu_naofang",
                        "/d/beijing/caishi","/d/beijing/ximenkou",
                        "/d/beijing/shi_1","/d/beijing/guandao_1",
                        "/d/beijing/guandao_2","/d/beijing/huangling",
                        "/d/beijing/shi_3","/d/beijing/di_xigc",
                        "/d/beijing/di_2","/d/beijing/dianmen",
                        "/d/beijing/di_dajie1","/d/beijing/di_5",
                        "/d/beijing/di_dajie2","/d/beijing/di_anmen",
                        "/d/beijing/qingmu_dating",
                     }),
        "扬州城"   : ({ 
                        "/d/city/zuixianlou2","/d/city/zuixianlou3",
                        "/d/city/zuixianlou","/d/city/beidajie2",
                        "/d/city/beimen","/d/city/beidajie1",
                        "/d/city/qianzhuang","/d/city/guangchang",
                        "/d/city/xidajie1","/d/city/yamen",
                        "/d/city/xidajie2","/d/city/wuguan",
                        "/d/city/ximen","/d/city/dongdajie1",
                        "/d/city/zahuopu","/d/city/dongdajie2",
                        "/d/city/yaopu","/d/city/datiepu",
                        "/d/city/dongmen",
                     }),
	 "长安城"   : ({
                        "/d/changan/huanggong","/d/changan/bridge1",
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
                        "/d/changan/yongtai-dadao4","/d/changan/miao",
                        "/d/changan/yongtai-dadao5","/d/changan/yongtai-nankou",
                        "/d/changan/baozipu","/d/changan/huarui1",
                        "/d/changan/nanan-daokou","/d/changan/huarui2",
                        "/d/changan/mianguan","/d/changan/huarui3",
                        "/d/changan/huadian","/d/changan/bingying5",
                        "/d/changan/bingying4","/d/changan/nan-chengmen",
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
                        "/d/changan/qixiang5","/d/changan/shoushi-dian",
                        "/d/changan/biaoju-damen","/d/changan/qixiang4",
                        "/d/changan/bank","/d/changan/qunyulou",
                        "/d/changan/baihu1","/d/changan/fufeng1",
                        "/d/changan/fufeng2","/d/changan/fufeng3",
                        "/d/changan/fufeng4","/d/changan/xian-dadao",
                        "/d/changan/fufeng5","/d/changan/qinglong1",
                        "/d/changan/baoxiangsi","/d/changan/qinglong2",
                        "/d/changan/bridge2","/d/changan/qinglong2",
                        "/d/changan/nanan-dadao","/d/changan/qinglong3",
                        "/d/changan/yamen","/d/changan/fengxu5",
                        "/d/changan/fengxu4","/d/changan/lingyange",
                        "/d/changan/fengxu3","/d/changan/fengxu2",
                        "/d/changan/dongan-dadao","/d/changan/fengxu1",
                        "/d/changan/baihu3","/d/changan/guozijian",
                     }),
        "成都城"   : ({
                        "/d/city3/guangchang","/d/city3/tidugate",
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
                        "/d/city3/eastroad1","/d/city3/jiudian",
                        "/d/city3/wuguan",
                     }),
        "苏州城"   : ({
                        "/d/suzhou/beimen","/d/suzhou/beidajie2",
                        "/d/suzhou/zijinan","/d/suzhou/jiudian",
                        "/d/suzhou/beidajie1","/d/suzhou/xiyuan",
                        "/d/suzhou/canlangting","/d/suzhou/dongdajie1",
                        "/d/suzhou/hutong1","/d/suzhou/leitai",
                        "/d/suzhou/hutong2","/d/suzhou/hutong3",
                        "/d/suzhou/dongdajie2","/d/suzhou/dongmen",
                        "/d/suzhou/yaopu","/d/suzhou/datiepu",
                        "/d/suzhou/baodaiqiao","/d/suzhou/nandajie1",
                        "/d/suzhou/jubaozhai","/d/suzhou/shizilin",
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
                        "/d/hangzhou/road5","/d/hangzhou/liuhe2",
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
                        "/d/hangzhou/qiantang","/d/hangzhou/liuheta",
                        "/d/hangzhou/yuquan","/d/hangzhou/dadao1",
                        "/d/hangzhou/dadao2","/d/hangzhou/dalu1",
                        "/d/hangzhou/liuzhuang2","/d/hangzhou/liuzhuang",
                        "/d/hangzhou/road1", "/d/hangzhou/road2",
                        "/d/hangzhou/road4", "/d/hangzhou/road3",
                        "/d/hangzhou/hongchunqiao","/d/hangzhou/jiulou",
                        "/d/hangzhou/duanqiao","/d/hangzhou/baiti",
                        "/d/hangzhou/pinghuqiuyue","/d/hangzhou/fangheting",
                        "/d/hangzhou/gushan","/d/hangzhou/gushanpingtai",
                        "/d/meizhuang/shijie","/d/meizhuang/xiaolu",
                        "/d/meizhuang/gate","/d/hangzhou/shanlu8",
                        "/d/hangzhou/chufang","/d/hangzhou/tiejiangpu",
                        "/d/hangzhou/yaodian","/d/hangzhou/jingcisi",
                        "/d/hangzhou/jingci","/d/hangzhou/shanlu1",
                        "/d/hangzhou/shanlu2","/d/hangzhou/shanlu3",
                        "/d/hangzhou/fajingsi","/d/hangzhou/fajinsi",
                        "/d/hangzhou/faxisi","/d/hangzhou/shanlu4",
                        "/d/hangzhou/shanlu5","/d/hangzhou/shanlu6",
                        "/d/hangzhou/shanlu7","/d/hangzhou/tulu1",
                        "/d/hangzhou/yanxiadong","/d/hangzhou/maojiabu",
                        "/d/hangzhou/maojiabu","/d/hangzhou/huangniling",
                        "/d/hangzhou/shuiledong","/d/hangzhou/manjuelong",
                     }),
        "襄阳城"   : ({
                        "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
                        "/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
                        "/d/xiangyang/guangchang", "/d/xiangyang/dingzi",
                        "/d/xiangyang/westgate2","/d/xiangyang/northgate1",
                        "/d/xiangyang/eastgate1","/d/xiangyang/southgate2",
                        "/d/xiangyang/walls2","/d/xiangyang/walle3",
                        "/d/xiangyang/walln4","/d/xiangyang/juyilang", 
                        "/d/xiangyang/northgate2","/d/xiangyang/northjie",
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
                        "/d/xiangyang/qianzhuang","/d/xiangyang/southgate1",
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
                        "/d/xiangyang/guofushufang","/d/xiangyang/dangpu",
                        "/d/xiangyang/juyiyuan","/d/xiangyang/juyilianwu2",
                        "/d/xiangyang/juyilianwu1","/d/xiangyang/juyilang",
                        "/d/xiangyang/juyihuayuan","/d/xiangyang/juyimale",
                        "/d/xiangyang/juyifemale","/d/xiangyang/juyichufang",
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
                        "/d/xiangyang/walln8",
                     }),
        "大理一带" : ({
                        "/d/dali/northgate", "/d/dali/southgate",
                        "/d/dali/shanlu2", "/d/dali/buxiongbu",
                        "/d/dali/jinzhihe", "/d/dali/xiaodao1",
                        "/d/dali/tianweijing", "/d/dali/wuding",
                        "/d/dali/luwang", "/d/dali/gudao",
                        "/d/dali/biluoxueshan", "/d/dali/zhenxiong",
                        "/d/dali/yixibu", "/d/dali/cangshanzhong",
                        "/d/dali/wumeng", "/d/dali/hongsheng", 
                        "/d/dali/tusifu","/d/dali/tusimentang",
                        "/d/dali/tusiyishi","/d/dali/dahejiewest",
                        "/d/dali/dahejieeast","/d/dali/baiyiziguan",
                        "/d/dali/baiyiminju","/d/dali/center",
                        "/d/dali/taihejiekou","/d/dali/sheguta",
                        "/d/dali/qingchi","/d/dali/taiheeast",
                        "/d/dali/stoneshop","/d/dali/garments",
                        "/d/dali/yaoshop","/d/dali/paifang",
                        "/d/dali/yujie","/d/dali/gongmen",
                        "/d/dali/qiandian","/d/dali/yuhuayuan",
                        "/d/dali/hualang","/d/dali/yushanfang",
                        "/d/dali/piandian","/d/dali/chahuashan1",
                        "/d/dali/chahuashan2","/d/dali/chahuashan3",
                        "/d/dali/chahuashan4","/d/dali/chahuashan5",
                        "/d/dali/chahuashan6","/d/dali/dadieshui",
                        "/d/dali/qingxi","/d/dali/xiaodao1",
                        "/d/dali/hudiequan","/d/dali/yuxuguanqian",
                     }),
                     
]);

void place_npc(object ob, object who)
{
        string *kp;
        string p;
        string startroom;
        object pos;

        kp = keys(place);

        // select the exact position
        for (;;)
        {
                p = kp[random(sizeof(kp))];
                startroom = place[p][random(sizeof(place[p]))];
                if (! objectp(pos = get_object(startroom)))
                {
                        log_file("log", sprintf("error to place npc to %s:%s\n",
                                                p, startroom));
                        continue;
                }
                break;
        }

        // move to the position
        ob->move(pos);
        ob->set("place", p);
        ob->set("startroom", startroom);
        ob->set_temp("quester", who->query("id"));
        ob->set_temp("moved", ({ }));
        message_vision("$N走了过来。\n", ob);
}

private void special_bonus(object me, object who, mixed arg)
{
        string *ob_list = ({
                "/clone/gift/xiandan",
                "/clone/gift/shenliwan",
                "/clone/gift/unknowdan",
                "/clone/gift/xisuidan",
                "/d/item/obj/hantie",
                "/d/item/obj/wujins",
                "/d/item/obj/butian",
                "/d/item/obj/tiancs",
                "/clone/gift/jinkuai",
        });
        object ob;

        message_vision("$n对$N微微一笑，道：干得不赖，辛苦"
                       "了，正好我这里有点东西，你就拿去吧。\n",
                       who, me);

        if (stringp(arg))
                ob = new(arg);
        else
                ob = new(ob_list[random(sizeof(ob_list))]);
        ob->move(who, 1);
        tell_object(who, HIM "你获得了一" + ob->query("unit") + ob->name() +
                        HIM "。\n" NOR);
}

varargs public void bonus(object who, mapping b, int flag)
{
        int exp;                // 奖励的经验
        int pot;                // 奖励的潜能
        int mar;                // 奖励的实战体会
        int shen;               // 奖励的神
        int score;              // 奖励的江湖阅历
        int weiwang;            // 奖励的江湖威望
        int pot_limit;          // 潜能的界限
        int mar_limit;          // 实战体会的界限
        int percent;            // 奖励的有效百分比
        string msg;             // 奖励的描述信息

        // 获得奖励的百分比
        percent = b["percent"];
        if (percent < 1 || percent > 100)
                percent = 100;

        exp = b["exp"] * percent / 100;
        pot = b["pot"] * percent / 100;
        mar = b["mar"] * percent / 100;
        shen = b["shen"] * percent / 100;
        score = b["score"] * percent / 100;
        weiwang = b["weiwang"] * percent / 100;

        if (! flag)
        {
                pot_limit = who->query_potential_limit() - who->query("potential");
                if (pot > pot_limit) pot = pot_limit;
                if (pot < 1) pot = 0;

                mar_limit = who->query_experience_limit() - who->query("experience");
                if (mar > mar_limit) mar = mar_limit;
                if (mar < 1) mar = 0;
        } else
        {
                if (who->query_potential_limit() < who->query("potential"))
                        pot = 1 + random(2);

                if (who->query_experience_limit() < who->query("experience"))
                        mar = 1;
        }

        // 生成提示信息
        if (stringp(msg = b["prompt"]))
                msg = HIG + msg + HIG "，你获得了";
        else
                msg = HIG "通过这次锻炼，你获得了";

        if (exp > 0) msg += chinese_number(exp) + "点经验、";
        if (pot > 0) msg += chinese_number(pot) + "点潜能、";
        if (mar > 0) msg += chinese_number(mar) + "点实战体会、";
        if (shen > 0) msg += chinese_number(shen) + "点正神、";
        if (shen < 0) msg += chinese_number(-shen) + "点负神、";
        if (score > 0) msg += chinese_number(score) + "点江湖阅历、";
        if (weiwang > 0) msg += chinese_number(weiwang) + "点威望、";

        msg += "能力得到了提升。\n" NOR;
        tell_object(who, sort_msg(msg));

        // bonus
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("experience", mar);
        who->add("shen", shen);
        who->add("score", score);
        who->add("weiwang", weiwang);
}

// 延迟奖励：有时候给出奖励的时候应该是在某些事件发生以后，
// 但是在该事件发生时给与奖励更易于书写程序，所以奖励生成的
// 地方在事件正在发生的时候，但是要让玩家看起来是在事件发生
// 以后。比如杀人，人死亡的时候给与奖励是容易做的，但是我希
// 望玩家在看到NPC 的死亡信息以后才看到奖励的信息，这时候就
// 用delay_bonus了。
public void delay_bonus(object who, mapping b)
{
        who->start_call_out((: call_other, __FILE__,
                               "bonus", who, b :), 1);
}

// 领取任务
// 如果目前正在协助别人，不能领取任务
int ask_quest(object me, object who)
{
        object ob;              // 任务重的某些物件或人物
        mapping q;              // WHO的人物
        object aob;             // WHO目前正在协助的对象
        int exp;                // WHO的经验
        int t;                  // 用来计算时间的变量
        int level;              // QUEST的等级
        string place;

        message_vision("$n向$N打听有关任务的情况。\n", me, who);

        if (who->query("combat_exp") < 2000000)
        {
                message_vision("$N瞪大眼睛看着$n，道：“你乳臭未干，怕是不行哟！\n",
                               me, who);
                return 1;
        }  
                      
        q = who->query("slough");
        if (mapp(q))
        {
                if (q["task"])
                {
                        message_vision("$N一脸怒容对$n道：你不是要了个任务吗？不想干就拿些"
                                       "钱出来，我好请别人！\n", me, who);
                        return 1;
                }
        }

        if (me->query("eff_qi") * 2 < me->query("max_qi") ||
            me->query("qi") * 2 < me->query("max_qi"))
        {
                message_vision("$N捂着胸口，一副非常痛苦的样子，对你的"
                               "话显然没有听进去。\n", me);
                return 1;
        }

        if (objectp(aob = who->query_temp("quest/assist")))
        {
                message_vision("$N看了看$n，道：“我听说你不是帮" +
                               aob->name(1) + "去了么？先办妥了"
                               "再说吧！”\n", me, who);
                return 1;
        }

        level = who->query_temp("slough/next_level");
        if (level < 0 || level > MAX_QUEST_LEVEL)
                level = 0;

        ob = new(CLASS_D("generate") + "/slough_killer.c");
        place_npc(ob, who);
        NPC_D->set_from_me(ob, who, 100);
        ob->add_temp("apply/attack", ob->query_skill("force") *
				     (level - 1) / 15);
        ob->add_temp("apply/defense", ob->query_skill("force") *
			              (level - 1) / 15);
        ob->add_temp("apply/damage", 5 + level * 7);
        ob->add_temp("apply/unarmed_damage", 5 + level * 7);
        ob->add_temp("apply/armor", 10 + level * 15);
        ob->set_temp("quester", who->query("id"));
                   
        // NPC_D->random_move(ob);
        place = ob->query("place");

        message("vision", me->name() + "小声的对" + who->name() +
                "吩咐着什么，" + who->name() +
                "一边听，一边不住的点头。\n",
                environment(who), ({ who }));

        tell_object(who, sort_msg(HIC + me->name() + "对你说道：难得你" +
                "有如此侠义心肠，老夫近日获悉在" + place + "一带有一名" +
                "杀人狂魔为患，你就先去调查一下情况，根据我的资料，这个" +
                "人的名字好象叫" + ob->query("name") + "(" + ob->query("id") + 
                ")" + "，把他的门派底细弄清楚后立刻回来报告给我！\n" NOR)); 
                                
        who->set("slough/task", 1);  
        switch (level)
        {
        case 0:
                message_vision("$N顿了顿，又对$n道：“这个事情"
                        "容易办得很，你要是还办不成那可不象话。”\n",
                        me, who);
                break;
        case 1:
                break;
        case 2:
                message_vision("$N看了看$n又道：“这个事情很是有些"
                        "难办，你要是不行我就另找人吧。”\n",
                        me, who);
                break;
        case 3:
                message_vision("$N叹了口气，郑重的对$n道：“这次"
                        "任务凶险得紧，你不要勉强自己，不行就算了。”\n",
                        me, who);
                break;
        }
  
        who->set("slough/check", 1);            
        who->set("slough/name", ob->name());
        who->set("slough/id", ob->query("id"));
        who->set("slough/level", level);
        who->set("slough/place", place);
        t = time();
        who->set("slough/time", t);
        t = time() / ONE_DAY;
        t += 8;
        t = t * ONE_DAY - 1;
        who->set("slough/limit", t);
        message("vision", me->name() + "在$N耳边悄声说道：“你务必要在" +
                     CHINESE_D->chinese_monthday(t) + "之前完成！”\n", who);
        who->start_busy(1);
        return 1;
}

int do_answer(object me, object ob, string arg)
{
        object killer;
        object gold;
        int amount;
        
        if (! ob->query("slough/inquiry"))
        {
                message_vision(HIY "$N对$n怒道：“还不快去，在这里磨蹭什么？\n" NOR, me, ob); 
                return 1;
        } 
        
        if (! arg || arg == "")
        { 
                tell_object(ob, "请用 answer <门派> 回答！\n");
                return 1;
        }               

        if (! objectp(killer = find_living(ob->query("slough/id"))))
        {
                message_vision(
                        HIW "$N为难地对$n说道：辛苦你了，可是这人好象失踪了！\n" NOR, me, ob);
                ob->delete("slough/inquiry");
                ob->delete("slough/check"); 
                return 1;
        }

        if (arg != killer->query("family/family_name"))
        {
                message_vision(HIW "$N脸色一沉对$n道：“胡说！哪里是什么" + arg + "，你给我再去查查看！”\n" NOR, 
                        me, ob);
                ob->delete("slough/inquiry");
                return 1;
        } else
        {
                message_sort(HIW "$N面露微笑对$n点头赞许道：“不错，不错，正是" +
                        arg + "，和我想的一样！”" + "我得到消息说" +
                        killer->query("name") + "已逃到了" + killer->query("place") +
                        "，正在那里行凶，请你立刻赶去除掉他吧！\n" NOR, me, ob);

                amount = 20 + random(10);
                gold = new("/clone/money/silver");
                gold->set_amount(amount);
                gold->move(ob);
      
                message_sort(
                        MAG "$N顿了顿，接着对$n道：“对了，你一路辛苦，花费也去了不少吧？"
                        "这里有" + sprintf("%d两白银，就全当给你些酬劳吧，可别嫌少呀！”\n" NOR +
                        WHT "$N说完，转身走入书房，拿出一些白银交给$n。\n" NOR, amount),
                        me, ob); 

                ob->delete("slough/inquiry");
                ob->delete("slough/check"); 
                ob->set("slough/chased", 1); 
                ob->set("slough/place", killer->query("place"));
                killer->start_kill(ob);   
                return 1;
        }
}

int accept_object(object me, object who, object ob)
{
        mapping q;              // WHO的任务
        string msg;             // 掌门说的消息
        object dob;             // 打晕敌人的人
        int bonus;              // 奖励(正整数，1是正常)
        int t;                  // 用来计算时间的变量
        int exp;                // 获得的经验
        int pot;                // 获得的潜能
        int mar;                // 获得的实战体会
        int weiwang;            // 获得的威望
        int score;              // 获得的江湖阅历
        int lvl;                // 人物的等级
        int quest_level;        // QUEST的等级
        int quest_count;        // 连续QUEST的数目
        int timeover;           // 标志：超时了？
        int added;              // 做任务的时候额外出现的敌人或敌人逃走
	mixed special = 0;      // 是否有特殊奖励
        int money = 40 + random(20);
        object obj;
        
        q = who->query("slough");

        if (ob->query("money_id"))
        {
                if(! who->query("slough/task"))
                {
                        message_vision("$N接过" + ob->name() + "，呵呵大笑，对$n道：那我可就不客气了。\n", 
                                me, who);
                }

                if (ob->value() < 100 * money) 
                {
                        message_sort(
                                "$N一双尖针般的眼睛直盯着$n：这点钱可不够我的开销！"
                                "最少也要" + sprintf(HIR " %d " NOR "两" HIY "白银" NOR "啊！\n",
                                money), me, who);
                                
                        return 0;
                } else
                {                                                      
                        message_sort(
                                "$N接过" + ob->name() + "，呵呵大笑，对$n道："
                                "没有关系，下次继续努力！\n", me, who);
                                
                        destruct(ob);        
                        who->delete("slough_count");
	                who->delete_temp("slough/next_level");     
                        who->start_busy(1);

                        obj = find_living(q["id"]);
                        who->delete("slough");
                        if (! obj || obj->query_temp("quester") != who->query("id"))
                                return 1;

                        if (environment(obj))
                                message_vision("$N看了看四周，急急忙忙的走掉了。\n", obj);    
                                               
                        destruct(obj);
                }
                return 1;
                
        } else
        {
                if (! mapp(q) || ! ob->is_corpse() && ! ob->is_head())
                        return 0;
        
                if (! stringp(ob->query("owner_id")))
                {
                        message_vision("$N捂着鼻子看了看" + ob->name() + "，道"
                                       "：“什么臭烘烘的？快给我拿走。”\n", me);
                        return 0;
                }
        
                if (ob->query("owner_id") != q["id"])
                        return 0;

                msg = "$N接过" + ob->name() + "，呵呵大笑，对$n道：“";
                msg += "干得好，漂亮！";
                msg += "”\n";
                t = time();
                if (who->query("slough/succeed"))
                {
                        msg += "$N赞许道：“这次没想到你的卓越表现，成功的解救了当地的百姓！”\n";
                        timeover = 0;
                } else                        
                if (who->query_temp("quest/escape_times"))
                {
                        msg += "$N赞许道：“这次没想到敌人这么强悍，实在未曾料到，辛苦，辛苦！”\n";
                        timeover = 0;
                } else
                if (t > q["limit"])
                {
                        msg += "$N摇摇头，又道：“可惜，不是让你" +
                               CHINESE_D->chinese_monthday(t) + "前做完吗？算"
                               "了，将功补过，你先退下吧。”\n";
                        timeover = 1;
                } else
                {
                        if (t - q["time"] < ONE_DAY)
                        {
                                msg += "$N点点头道：“你很不错，这么快就完成了"
                                        "，好好干！”\n";
                        } else
                                msg += "$N点点头道：“这次不错，辛苦了。”\n";

                        timeover = 0;
                }

                // bonus为1表示正常奖励，为2表示扣除一半。
                bonus = (ob->query("killed_by") == who->query("id")) &&
                        (ob->query("defeated_by") == who ||
                         ! ob->query("defeated_by") &&
                           ob->query("defeated_by_who") == who->name(1));
                if (ob->query("assist") == who)
                {
                        dob = ob->query("defeated_by");
                        msg += "$N欣慰的对$n道：“这次你能够得到" +
                               (dob ? dob->name(1) : "同门师兄弟") +
                               "的帮忙，也属不易！以后彼此要多加照应！”\n";
                        bonus = 2;
                } else
                if (bonus)
                        bonus = 1;

                destruct(ob);
                lvl = NPC_D->check_level(who);
                exp = 500 + random(200) + lvl * 20;
                pot = 150 + random(50) + lvl * 20;
                weiwang = 20 + random(30) + lvl * 2;
                score = 20 + random(30) + lvl * 2;
                quest_count = who->query("slough_count") + 1;

                // add temped for keep compactible with old version
                if (who->query_temp("slough/total_count"))
                {
                        quest_count = who->query_temp("slough/total_count") + 1;
                        who->delete_temp("slough/total_count");
                }

                // 根据任务完成的次数修正奖励
                if (quest_count >= 500)
                {
                        // 连续完成了超过500次的任务
                        exp += 80 + random(quest_count / 20 + 1);
                        pot += 45 + random(quest_count / 25 + 1);
                        mar = 50 + random(20);
                        weiwang += 8 + random(20);
                        score += 4 + random(15);
                } else
                if (quest_count >= 200)
                {
                        // 连续完成了超过200次的任务
                        exp += 70 + random(quest_count / 20 + 1);
                        pot += 40 + random(quest_count / 25 + 1);
                        mar = 20 + random(10);
                        weiwang += 5 + random(15);
                        score += 3 + random(10);
                } else
                if (quest_count >= 100)
                {
                        // 连续完成了超过100次的任务
                        exp += 50 + random(quest_count / 20 + 1);
                        pot += 30 + random(quest_count / 25 + 1);
                        weiwang += 3 + random(10);
                        score += 2 + random(10);
                } else
                if (quest_count >= 10)
                {
                        // 连续完成了超过10次的任务
                        exp += 45 + random(quest_count / 20 + 1);
                        pot += 25 + random(quest_count / 25 + 1);
                        weiwang += 1 + random(5);
                        score += 1 + random(5);
                }

                switch (quest_level = q["level"])
                {
                case 0:
                        exp = exp / 2 + 1;
                        pot = pot / 2 + 1;
                        weiwang = weiwang / 3 + 1;
                        score = score / 4 + 1;
                        msg += "$N看着$n接着说道：“还行吧，下次我给你个难点的任务。”\n";
                        break;
                case 1:
                        msg += "$N对$n又道：“不错，看来我可以托付些重任给你了。”\n";
                        break;
                case 2:
                        exp += exp / 4;
                        pot += pot / 4;
                        weiwang += weiwang / 4;
                        score += score / 4;
                        msg += "$N对$n笑道：“真是不错，不愧是泥潭的矫矫者。”\n";
                        break;
                case 3:
                        exp += exp / 2;
                        pot += pot / 2;
                        weiwang += weiwang / 2;
                        score += score / 2;
                        msg += "$N赞许道：“非常不错，你将来成就一定不可估量。”\n";
                        break;
                }

                if (quest_count == 50)
                {
                        msg += "$N哈哈大笑两声道：“真有你的，连着上百"
                               "次任务都完成的漂漂亮亮，很好，很好。”\n";
			special = 1;
                } else
                if (quest_count == 100)
                {
                        msg += "$N大喜道：“不错不错，真实不错，两百"
                               "次任务干得很好。”\n";
			special = "/clone/gift/puti-zi";
                } else
                if (quest_count == 200)
                {
                        msg += "$N叹道：“真是长江后浪推前浪，想不到你接连五百"
                               "次任务都无一疏漏，不易，不易！”\n";
			special = "/clone/gift/tianxiang";
                } else
                if (quest_count >= 500)
                {
                        msg += "$N深深叹了口气，道：“想不到你连着上五百次"
                               "任务无一失手，看来泥潭真是后继有人啊！”\n";
			special = "/clone/gift/jiuzhuan";
                        quest_count = 0;
                } else
                if ((quest_count % 10) == 0)
                {
                        msg += "$N喜道：“真是不赖，居然连着" +
                               chinese_number(quest_count) +
                               "次都没有失手，干的好！”\n";
                }

                quest_level = q["level"];
                quest_level++;
                if (quest_level > MAX_QUEST_LEVEL)
                        quest_level = 1;

                who->set("slough_count", quest_count);
                who->set_temp("slough/next_level", quest_level);
        }

        if ((added = (int)who->query_temp("slough/help_count")) > 0)
        {
                msg += HIY "$N" HIY "又道：“这次敌人伏下帮手，而你能随"
                       "机应变，完成任务，可喜，可贺！”\n" NOR;
                who->delete_temp("slough/help_count");
        }
        added += (int)who->query_temp("quest/escape_times") * 2;
        who->delete_temp("quest/escape_times");
        // 根据NPC的帮手和逃走的次数调整经验
        if (added)
        {
                exp += exp * added / 2;
                pot += pot * added / 2;
        }

        message_vision(msg, me, who);
        who->delete("slough");
        if (! bonus) return 1;

        exp /= bonus;
        pot /= bonus;
        mar /= bonus;
        weiwang /= bonus;
        score /= bonus;
        // bouns
        if (timeover)
        {
                exp /= 2;
                pot /= 3;
                mar /= 2;
                weiwang /= 4;
                score /= 4;
        } else
        {
                // 0.01% to get a special object
                if (random(2000) == 1 || special)
			special_bonus(me, who, special);
        }

        bonus(who, ([ "exp" : exp, "pot" : pot, "mar" : mar,
                      "weiwang" : weiwang, "score" : score ]), 1);
        return 1;
}
