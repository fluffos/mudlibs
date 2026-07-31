// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// defendd.c

#include <ansi.h>
inherit F_DBASE;

#define CHECK_PERIOD    100 // 300s 检查一次 
#define last_check      my["last_check"] 
#define now_fighting    my["now_fighting"] 
#define MIN_EXP         100000


int  filter_user(object me);
void send_enemy(int num, string family);
void move_enemy(object enemy, string family);
void remove_enemy();

mapping familys = ([
// 门派 : ([ 位置 : string*, 大致辈分 : int, 师父档案 : string ]),
"武当派" : ([
        "place" : ({ "/d/wudang/shijie1", "/d/wudang/shibapan","/d/wudang/haohanpo", 
                     "/d/wudang/guangchang", "/d/wudang/tynroad", "/d/wudang/mozhenjing",
                     "/d/wudang/fuzhenguan", "/d/wudang/shiliang", "/d/wudang/yuzhengong",
                     "/d/wudang/zixiaogate", "/d/wudang/shijie2", "/d/wudang/wulaofeng",
                     "/d/wudang/shanlu2", "/d/wudang/shibapan", "/d/wudang/tygate1", 
                     "/d/wudang/shanlu4", "/d/wudang/shanlu3", "/d/wudang/tysroad", 
                     "/d/wudang/shanlu1", "/d/wudang/taiziyan", }),
        "generation" : 3,
	"master" : "/kungfu/class/wudang/zhang", 
	]),

"少林派" : ([
	"place" : ({ "/d/shaolin/xiaojing1", "/d/shaolin/xiaojing2", "/d/shaolin/shijie1",
	      	     "/d/shaolin/shijie2", "/d/shaolin/shijie3", "/d/shaolin/shijie4",
	       	     "/d/shaolin/guangchang1", "/d/shaolin/shijie5", "/d/shaolin/shijie6", 
                     "/d/shaolin/gulou", "/d/shaolin/smdian", 
                     "/d/shaolin/hsyuan2", "/d/shaolin/hsyuan3", "/d/shaolin/hsyuan1", }),
	"generation" : 37,
	"master" : "/kungfu/class/shaolin/xuan-tong", 
	]),

"丐帮" : ([
        "place" : ({ "/d/city/ml1", "/d/city/ml2",
                     "/d/city/ml3", "/d/city/pomiao", 
                     "/d/gaibang/shoushe", "/d/gaibang/inhole",
                     "/d/city/ml4", "/d/gaibang/slandao1",
                     "/d/gaibang/slandao2", }),
	"generation" : 37,
	"master" : "/kungfu/class/gaibang/hong", 
	]),
	
"峨嵋派" : ([
        "place" : ({ "/d/emei/qianfoan", "/d/emei/qingyinge", 
                     "/d/emei/yunufeng", "/d/emei/woyunan", 
                     "/d/emei/shierpan3", "/d/emei/qsjie1", 
                     "/d/emei/xiaolu1",
                     "/d/emei/wanxingan", }),
	"generation" : 37,
	"master" : "/kungfu/class/emei/miejue", 
	]),

"星宿派" : ([
        "place" : ({ "/d/xingxiu/xxroad1", "/d/xingxiu/riyuedong", 
                     "/d/xingxiu/xxh6", "/d/xingxiu/xxh5", "/d/xingxiu/xxh4", 
		     "/d/xingxiu/xxh1", "/d/xingxiu/xxh2", "/d/xingxiu/xxh3", 
		     "/d/xingxiu/xxh4", "/d/xingxiu/shanjiao", }),
	"generation" : 3,
        "master" : "/kungfu/class/xingxiu/ding", 
	]),
	
"华山派" : ([
	"place" : ({ "/d/huashan/yunu", "/d/huashan/square", 
                     "/d/huashan/zhenyue", "/d/huashan/pingxinshi",
                     "/d/huashan/yuquan", "/d/huashan/chaoyang", 
		     "/d/huashan/husun", "/d/huashan/shaluo", 
                     "/d/huashan/pingdi", "/d/huashan/canglong", }),
	"generation" : 14,
	"master" : "/kungfu/class/huashan/yue-buqun", 
	]),

"段氏皇族" : ([
        "place" : ({ "/d/dali/shilin1", "/d/dali/shilin2", "/d/dali/gudao",
                     "/d/dali/road3", "/d/dali/road4", "/d/dali/road5",
                     "/d/dali/dalinorth", "/d/dali/ershuiqiao", "/d/dali/gaolishan2", 
                     "/d/dali/shanlu1", "/d/dali/shanlu2",
                     "/d/dali/zoulang3", "/d/dali/zoulang4", "/d/dali/zoulang1",
                     "/d/dali/shilin1", "/d/dali/shilin2", "/d/dali/zoulang2", }),
	"generation" : 13,
	"master" : "/kungfu/class/duan/duanzm", 
	]),
	
"明教" : ([
        "place" : ({ "/d/mingjiao/baota0", "/d/mingjiao/ljroad1", "/d/mingjiao/ljroad2", 
                     "/d/mingjiao/ljroad3", "/d/mingjiao/htping", "/d/mingjiao/shanlu1", 
                     "/d/mingjiao/shanlu2", "/d/mingjiao/shamo1", "/d/mingjiao/shanting", 
                     "/d/mingjiao/sshanlu4", "/d/mingjiao/tingtang", "/d/mingjiao/sshanlu2", 
                     "/d/mingjiao/tandi", "/d/mingjiao/wu1", "/d/mingjiao/xuanya3", 
                     "/d/mingjiao/xuanya1", "/d/mingjiao/xuanya2", "/d/mingjiao/xikou", }),
	"generation" : 35,
	"master" : "/kungfu/class/mingjiao/zhangwuji", 
	]),

"雪山寺" : ([
        "place" : ({ "/d/xueshan/shanjiao", "/d/xueshan/cangjing", "/d/xueshan/cangjingge"
                     "/d/xueshan/caoyuan", "/d/xueshan/cedian1", "/d/xueshan/cedian2", 
                     "/d/xueshan/chang", "/d/xueshan/chanshi", "/d/xueshan/dadian",  
                     "/d/xueshan/guangcha", "/d/xueshan/houmen", "/d/xueshan/dilao", 
                     "/d/xueshan/hubian1", "/d/xueshan/hubian2", "/d/xueshan/hubian3", 
                     "/d/xueshan/kufang", "/d/xueshan/midao", "/d/xueshan/mishi", }),
        "generation" : 3,
	"master" : "/kungfu/class/xueshan/jiumozhi", 
	]),

"全真教" : ([
        "place" : ({ "/d/quanzhen/cetang", "/d/quanzhen/huizhentang", "/d/quanzhen/shijianyan",
                     "/d/quanzhen/damen", "/d/quanzhen/guozhendian", "/d/quanzhen/xianzhentang",
                     "/d/quanzhen/datang1", "/d/quanzhen/datang2", "/d/quanzhen/datang3",
                     "/d/quanzhen/houtang1", "/d/quanzhen/houtang2", "/d/quanzhen/houtang3", 
                     "/d/quanzhen/houshan", "/d/quanzhen/xiaolu1", "/d/quanzhen/xiaolu2",}),
        "generation" : 6, 
        "master" : "/kungfu/class/quanzhen/wang",
        ]),

"古墓派" : ([ 
        "place" : ({ "/d/gumu/liangong3", "/d/gumu/liangong2", "/d/gumu/liangong",
                     "/d/gumu/zhengting", "/d/gumu/houting", "/d/gumu/xiaoting",
                     "/d/gumu/qianting", "/d/gumu/xiaoting", "/d/gumu/mumen", 
                     "/d/gumu/mumen", "/d/gumu/caodi", "/d/gumu/caodi2", }),
        "generation" : 5, 
        "master" : "/kungfu/class/gumu/longnv",
        ]),

"灵鹫宫" : ([
        "place" : ({ "/d/lingjiu/xianchou", "/d/lingjiu/dadao1", "/d/lingjiu/dadao2",
                     "/d/lingjiu/changl15", "/d/lingjiu/changl6", "/d/lingjiu/dating",
                     "/d/lingjiu/changl7", "/d/lingjiu/changl8", "/d/lingjiu/changl4",
                     "/d/lingjiu/changl3", "/d/lingjiu/daban", "/d/lingjiu/men2",
                     "/d/lingjiu/changl9", "/d/lingjiu/men1", "/d/lingjiu/changl1",
                     "/d/lingjiu/huayuan", "/d/lingjiu/xiaodao1", "/d/lingjiu/xiaodao2",}),
        "generation" : 5, 
        "master" : "/kungfu/class/lingjiu/xuzhu",
        ]), 

"欧阳世家" : ([
        "place" : ({ "/d/baituo/houyuan", "/d/baituo/tuyuan", "/d/baituo/zhuyuan",
                     "/d/baituo/shoushe", "/d/baituo/menlang", "/d/baituo/huayuan",
                     "/d/baituo/damen", "/d/baituo/yuanzi", "/d/baituo/dating", 
                     "/d/baituo/liangong", "/d/baituo/ximen", "/d/baituo/guangchang",}), 
        "generation" : 3, 
        "master" : "/kungfu/class/ouyang/ouyangfeng", 
        ]), 

"桃花岛" : ([
        "place" : ({ "/d/taohua/wofang", "/d/taohua/hyjuchu", "/d/taohua/changlang2", 
                     "/d/taohua/changlang", "/d/taohua/shuilong", "/d/taohua/jingshe",
                     "/d/taohua/haitan", "/d/taohua/tuqiu", "/d/taohua/zhulin",
                     "/d/taohua/road1", "/d/taohua/xiangzhong", "/d/taohua/taolin",
                     "/d/taohua/road2", "/d/taohua/road3", "/d/taohua/road4",}),
        "generation" : 10,
        "master" : "/kungfu/class/taohua/huang", 
        ]),

"血刀门" : ([
        "place" : ({ "/d/xuedao/sroad7", "/d/xuedao/sroad8", "/d/xuedao/shandong1", 
                     "/d/xuedao/wangyougu", "/d/xuedao/sroad9", "/d/xuedao/shandong2",
                     "/d/xuedao/shandong3", "/d/xuedao/syabi", "/d/xuedao/eyabi",}),
        "generation" : 3,
        "master" : "/kungfu/class/xuedao/laozu", 
        ]),

"关外胡家" : ([
        "place" : ({ "/d/guanwai/caoguduo", "/d/guanwai/baihe", "/d/guanwai/xiaoyuan", 
                     "/d/guanwai/milin1", "/d/guanwai/xiaowu", "d/guanwai/houyuan",
                     "/d/guanwai/liangonge", "/d/guanwai/liangong", "/d/guanwai/jingxiu",}),
        "generation" : 4,
        "master" : "/kungfu/class/guanwai/hufei", 
        ]),

"神龙教" : ([
        "place" : ({ "/d/shenlong/zoulang", "/d/shenlong/zhulin", "/d/shenlong/jushi", 
                     "/d/shenlong/road2", "/d/shenlong/road", "/d/shenlong/kongdi",
                     "/d/shenlong/xiaowu", "/d/shenlong/caodi", "/d/shenlong/haitan",}),
        "generation" : 3,
        "master" : "/kungfu/class/shenlong/hong", 
        ]),

"慕容世家" : ([
        "place" : ({ "/d/yanziwu/shuwu", "/d/yanziwu/lanyue", "/d/yanziwu/shuwu", 
                     "/d/yanziwu/zuijing", "/d/yanziwu/canheju", "/d/yanziwu/qiushuan",
                     "/d/yanziwu/huayuan", "/d/yanziwu/jiashan", "/d/yanziwu/jiashan",
                     "/d/yanziwu/longfeng", "/d/yanziwu/yimen", "/d/yanziwu/dannuo",
                     "/d/yanziwu/cuixia", "/d/yanziwu/chuantang", "/d/yanziwu/lixiang",}),
        "generation" : 8,
        "master" : "/kungfu/class/yanziwu/murongbo", 
        ]),

"逍遥派" : ([
        "place" : ({ "/d/xiaoyao/mubanlu", "/d/xiaoyao/liangong", "/d/xiaoyao/xiaodao4", 
                     "/d/xiaoyao/muwu1", "/d/xiaoyao/xiaodao5", "/d/xiaoyao/qingcaop",
                     "/d/xiaoyao/muwu2", "/d/xiaoyao/xiaodao3", "/d/xiaoyao/xiaodao1",
                     "/d/xiaoyao/xiaodao2", "/d/xiaoyao/wuchang2", "/d/xiaoyao/bingqif",}),
        "generation" : 10,
        "master" : "/kungfu/class/xiaoyao/suxingh", 
        ]),

"华山剑宗" : ([ 
        "place" : ({ "/d/huashan/jzroad1", "d/village/hsroad2", "/d/huashan/jzroad1", 
                     "/d/huashan/jzroad2", "/d/huashan/jzroad3", "/d/huashan/jzroad4",  
                     "/d/huashan/jzroad5", "/d/huashan/jzroad6", "/d/huashan/shangu",}),  
        "generation" : 3, 
        "master" : "/kungfu/class/huashan/feng-buping", 
   ]),
]);

// 正派列表
string *zps = ({
        "武当派", "华山气宗", "全真教", "古墓派", "灵鹫宫", "桃花岛", "关外胡家", "段氏皇族", 
        "峨嵋派", "丐帮", "少林派", "逍遥派", "明教","华山剑宗",
});

// 邪派列表
string *xps = ({
        "星宿派", "血刀门", "雪山寺", "欧阳世家", "神龙教", "慕容世家",
});

void create() 
{
        mapping my; 

        seteuid(getuid()); 
        set("channel_id", "门派任务精灵"); 

        CHANNEL_D->do_channel(this_object(), "sys", "门派任务精灵已经启动。"); 

        set_heart_beat(100); 
        my = query_entire_dbase(); 

        now_fighting = ([]);
        last_check = time(); 
}

void heart_beat() 
{
        mapping my; 
        int i, num; 
        object *users;
        string *family, family_name;

        my = query_entire_dbase(); 

        if ((time() - last_check) < CHECK_PERIOD) 
                return;

        // remove_enemy();
        
        family = keys(familys);

        for (i = 0; i < sizeof(family); i++)
        {
                family_name = family[i];

                users = filter_array(users(), (: interactive($1) && 
                                                 $1->query("family/family_name") == $(family_name) 
                                                 && mapp($1->query_temp("swjob/allow")) :));
                num = sizeof(users) * (1 + random(2));
                if (! num) continue;

                // CHANNEL_D->do_channel(this_object(), "sys", "敌人数量： "+ num +"。"); 
                send_enemy(num, family_name);
        }

        last_check  = time(); 
}

void send_enemy(int num, string family)
{
        object enemy, master;
        string enemy_fam;
        int i;
        mapping my = query_entire_dbase(); 

        // 假如要攻打的是正派或者亦正亦邪，就派邪派上场
        if (member_array(family, xps) != -1 
        ||  member_array(family, zps) == -1 && member_array(family, xps) == -1)
                enemy_fam = zps[random(sizeof(zps))];
        // 否则就派正派上场
        else 
                enemy_fam = xps[random(sizeof(xps))];

        for (i = 0; i < num; i++)
        {
                enemy = new("/clone/npc/enemy");
                // enemy->create_family(enemy_fam, familys[enemy_fam]["generation"] + (-1 + random(2)), "弟子");
                enemy->set("is_attacking", family);
                enemy->set_temp("quest_ob", 1);
                enemy->set("long", "这人是前来攻打" + query("is_attacking") ? query("is_attacking") : "别的门派" +
                                   "的一名" + query("family/family_name") ? query("family/family_name") : "未知门派" + "弟子。\n");                
                move_enemy(enemy, family);
        }

        // now_fighting 格式：被攻击者 : 攻击者
        now_fighting[family] = enemy_fam;
        /*
        if (! find_object(familys[family]["master"])) 
                master = load_object(familys[family]["master"]);
        else 
                master = find_object(familys[family]["master"]);

        CHANNEL_D->do_channel(master, "chat", sprintf("听说%s的一班弟子大举杀上我派，我派形势不妙。", enemy_fam)); 
        */
        return;
}

void move_enemy(object enemy, string family)
{
        string *places = familys[family]["place"];
        string place = places[random(sizeof(places))];
        object room;

        if (objectp(room = environment(enemy)))
        {
                tell_room(room, enemy->name() + "一闪身就不见了。\n");
        }
        // CHANNEL_D->do_channel(this_object(), "sys", sprintf("%s : %O", enemy->short(), place)); 
        enemy->move(place);
        
        tell_room(place, "只见一名" + enemy->query("family/family_name") + "弟子不知什么时候钻了出来。\n");

        return;
}

int ask_quest(object ob, object me)
{
        string *places, place;

        string *msg_now = 
        ({
                "最近本门常有人来挑衅", "最近本门似乎不太平安", 
                "最近本门时有敌人进攻", "最近本门似乎很不安稳", 
                "听说就快要有敌人进攻", "常有人对本门虎视眈眈",
        });
        string *msg_do =
        ({
                "赶快到四处巡查巡查", "注意四周都要去查查", 
                "山上山下都仔细看看", "在本门要道好好守着",
                "在险要地方做好防卫", "得防止敌人攻上山来",
        });
        string *msg_place =
        ({
                "虽然说不上山明水秀，但是", "也是一个险要位置，所以",
                "好歹也是个重要关卡，因此", "毕竟算个本门要地，那么",
                "常常有敌人来此攻打，所以", "就怕敌人攻到这里，因此", 
        });

        if (! me->query("family/family_name"))
        {
                ob->command("haha" + me->query("id"));
                message_sort(HIC "$N" HIC "对$n" HIC "道：“" + RANK_D->query_respect(me) +
                             "无门无派，问我要什么任务呢？”\n\n" NOR,ob,me);
                tell_object(me, HIW "你还是先拜个师父再要任务吧。\n" NOR);
                return 1;
        }

        if (ob->query("family/family_name") != me->query("family/family_name"))
        {
                ob->command("?" + me->query("id"));
                message_sort(HIC "$N" HIC "皱着眉头对$n" HIC "道：“这位" +
                             me->query("family/family_name") +"的"+ RANK_D->query_respect(me) +
                             "，你怕是找错人了吧？”\n\n" NOR, ob, me);
                tell_object(me, HIW "这不是你自己的门派，你不应该问这位师傅要任务呀。\n" NOR);
                return 1;
        }

        if (me->query("combat_exp") < MIN_EXP)
        {
                ob->command("sigh");
                message_sort(HIC "$N" HIC "对$n" HIC "道：“唉，你还是等水平高些再来做这个任务不迟。”\n\n" NOR, ob, me);
                tell_object(me, HIW "这个任务得有 " +MIN_EXP+" 点经验值才能做。\n" NOR);
                return 1;
        }

        if (me->query_temp("swjob/allow") && ! wizardp(me))
        {
                ob->command("yi");
                message_sort(HIC "$N" HIC "疑惑地对$n" HIC "道：“你不是已经在做这个任务了么？怎么还来找我？”\n\n" NOR, ob, me);
                tell_object(me, HIW "快去做好准备，守护你的门派吧。\n" NOR);
                return 1;
        } else 
        {
                places = familys[me->query("family/family_name")]["place"];
                place = places[random(sizeof(places))];
                place = place->query("short");
                send_enemy(4, me->query("family/family_name"));

                command("nod" + me->query("id"));
                message_sort(HIC "$N" HIC "赞许地对$n" HIC "道：“好吧，" + msg_now[random(sizeof(msg_now))] +
                             "，你要注意" + msg_do[random(sizeof(msg_do))] + "。”\n\n" NOR, ob, me);
                               
                tell_object(me, HIW + ob->name() + HIW "悄悄告诉你：“" + place + HIW"这个地方" +
                                msg_place[random(sizeof(msg_place))]+ "你最好多注意注意。”\n" NOR);

                me->set_temp("swjob/allow", 1);
                me->apply_condition("swjob", 10 + random(5));
                return 1;
        }
}

// 到时间了，送走敌人
void remove_enemy()
{
        object *enemys;
        int i;
        mapping my = query_entire_dbase();

        if (arrayp(enemys = children("/clone/npc/enemy")))
        {
                for (i = 0; i < sizeof(enemys); i++)
                {
                        if (enemys[i]->is_fighting())
                        {
                                enemys[i]->remove_all_killer();
                                tell_room(environment(enemys[i]), HIW "只见" + enemys[i]->name() +
                                          "突然面色一变，迅速攻出几招，跳出战圈转身逃了。\n");
                        }
                        else {
                                tell_room(environment(enemys[i]), HIW "只见" + enemys[i]->name() +
                                          "掐指一算，突然脸色大变，急急忙忙地逃走了。\n");
                        }
                        destruct(enemys[i]);
                }
        }
        now_fighting = ([]);
        return; 
}

// 做完就得要奖励

int ask_reward(object ob, object me)
{
        int killed, exp, pot, con;

        if (! me->query("family/family_name"))
        {
                ob->command("haha" + me->query("id"));
                message_vision(HIC "$N" HIC "对$n" HIC "道：“" + RANK_D->query_respect(me) 
                                +"无门无派，问我要什么任务呢？”\n\n" NOR,ob,me);
                tell_object(me, HIW "你还是先拜个师父再要任务吧。\n" NOR);
                return 1;
        }

        if (ob->query("family/family_name") != me->query("family/family_name"))
        {
                ob->command("?" + me->query("id"));
                message_vision(HIC "$N" HIC "皱着眉头对$n" HIC "道：“这位" +
                               me->query("family/family_name") + "的" + RANK_D->query_respect(me) +
                               "，你怕是找错人了吧？”\n" NOR,ob,me);
                tell_object(me, HIW "这不是你自己的门派，你不应该问这位师傅要任务呀。\n" NOR);
                return 1;
        }

        if (! me->query_temp("swjob/allow"))
        {
                ob->command("sigh");
                message_vision(HIC "$N" HIC "疑惑地对$n" HIC "道：“你都不是在做这个任务，就想要奖励？”\n" NOR, ob, me);
                tell_object(me, HIW "你总得先要个任务吧。\n" NOR);
                return 1;
        }

        if (! me->query_temp("swjob/finish"))
        {
                ob->command("sigh");
                message_vision(HIC "$N" HIC "疑惑地对$n" HIC "道：“你还没有做完呢，就想要奖励？”\n" NOR, ob, me);
                tell_object(me, HIW "你等做完了再要奖励吧。\n" NOR);
                return 1;
        } else 
        {
                if (! me->query_temp("swjob/killed"))
                {
                        ob->command("hmm");
                        message_vision(HIC "$N" HIC "点点头对$n" HIC "道：“好吧，这次任务你存功未立，就不给你奖励了。”\n" NOR, ob, me);
                        me->delete_temp("swjob");
                        return 1;
                } else 
                {
                        killed = (int)me->query_temp("swjob/killed");
                        ob->command("nod");

                        exp = killed * 100 + random(200);
                        exp = exp / 2 + random(exp / 2);
                        pot = exp / 3 + random(20);
                        con = pot;

                        message_vision(HIC "$N" HIC "点点头对$n" HIC "道：“好！这次任务你成功截杀了" +
                                       chinese_number(killed) + "个敌人，这里是给你的一点奖励。”\n" NOR, ob, me);
                        tell_object(me, HIW "这次任务你得到了" + chinese_number(exp) + "点经验值和" +
                                        chinese_number(pot) + "点潜能值的奖励，你的门派贡献提高了。\n" NOR);
                        me->delete_temp("swjob/allow");
                        me->delete_temp("swjob/killed");
                        me->delete_temp("swjob/finish");
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
                        me->add("contribution", con);
                return 1; 
            }
    }
}
