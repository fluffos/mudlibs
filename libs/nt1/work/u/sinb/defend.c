// Daemon:/adm/daemons/defendd.c

#include <ansi.h>
inherit F_DBASE;

#define CHECK_PERIOD    100 // 300s 检查一次 
#define last_check	my["last_check"] 
#define now_fighting	my["now_fighting"] 
#define MIN_EXP		100000


int filter_user(object me);
void send_enemy(int num, string family);
void move_enemy(object enemy, string family);
void remove_enemy();

mapping familys = ([
// 门派 : ([ 位置 : string*, 大致辈分 : int, 师父档案 : string ]),
"武当派" : ([
	"place" : ({ "/d/wudang/shijie1", "/d/wudang/shibapan", "/d/wudang/caihong",
		"/d/wudang/guangchang", "/d/wudang/tynroad", "/d/wudang/wangbeipo",
		"/d/wudang/husunchou", "/d/wudang/gudao1", "/d/wudang/yuzhengong",
        "/d/wudang/gudao2", "/d/wudang/gudao3", "/d/wudang/wulaofeng",
		"/d/wudang/shanlu2", "/d/wudang/gudao2", "/d/wudang/tygate1", 
        "/d/wudang/zixiao", "/d/wudang/shijie2", "/d/wudang/tysroad", 
        "/d/wudang/shijie3", "/d/wudang/shuitan", "/d/wudang/xuanwumen", }),
	"generation" : 3,
	"master" : "/kungfu/class/wudang/zhang", 
	]),

"少林派" : ([
	"place" : ({ "/d/shaolin/xiaojing1", "/d/shaolin/xiaojing2", "/d/shaolin/shijie1",
		"/d/shaolin/shijie2", "/d/shaolin/shijie3", "/d/shaolin/shijie4",
		"/d/shaolin/guangchang1", "/d/shaolin/shijie5", "/d/shaolin/shijie6", 
        "/d/shaolin/gulou", "/d/shaolin/chufang", "/d/shaolin/smdian", 
        "/d/shaolin/qfdian", "/d/shaolin/qyping", "/d/shaolin/houdian",
        "/d/shaolin/hsyuan2", "/d/shaolin/hsyuan3", "/d/shaolin/hsyuan1", }),
	"generation" : 37,
	"master" : "/kungfu/class/shaolin/xuan-tong", 
	]),

"丐帮" : ([
    "place" : ({ "/d/gaibang/zhulin1", "/d/gaibang/zhulin2",
        "/d/gaibang/zhulin3", "/d/gaibang/gbxiaowu", 
        "/d/gaibang/underem", "/d/gaibang/inhole",
        "/d/gaibang/pomiao", "/d/gaibang/slandao1",
        "/d/gaibang/slandao2",}),
	"generation" : 37,
	"master" : "/kungfu/class/gaibang/hong", 
	]),
"峨嵋派" : ([
    "place" : ({ "/d/emei/baoguo", "/d/emei/jinding", 
        "/d/emei/leidong", "/d/emei/huazang", 
        "/d/emei/cangjing", "/d/emei/lingyun", 
        "/d/emei/qingyin", "/d/emei/valley", "/d/emei/valleypath",
        "/d/emei/lengshan1", "/d/emei/lengshan2", }),
	"generation" : 37,
	"master" : "/kungfu/class/emei/miejue", 
	]),

"星宿派" : ([
    "place" : ({ "/d/xingxiu/shanluan", "/d/xingxiu/riyuedong", 
        "/d/xingxiu/xxh6", "/d/xingxiu/xxh5", "/d/xingxiu/xxh4", 
        "/d/xingxiu/xxh3", "/d/xingxiu/xxh2", "/d/xingxiu/xxh1", 
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
        "/d/huashan/zoulang", "/d/huashan/canglong", }),
	"generation" : 14,
	"master" : "/kungfu/class/huashan/linghu", 
	]),
"大理段家" : ([
    "place" : ({ "/d/dali/shilin1", "/d/dali/shilin2", "/d/dali/shilin3",
        "/d/dali/road3", "/d/dali/road4", "/d/dali/road5",
        "/d/dali/road6", "/d/dali/road7", "/d/dali/wls", 
        "/d/dali/shanlu1", "/d/dali/shanlu2", "/d/tls/shanlu3",
        "/d/dali/tower", "/d/dali/tower1", "/d/dali/tower2",
        "/d/dali/shilin1", "/d/dali/shilin2", "/d/dali/shilin3",
        "/d/tls/yideng1", "/d/tls/yideng2",  "/d/tls/yideng3",
		 }),
	"generation" : 13,
	"master" : "/kungfu/class/dali/kurong", 
	]),
"明教" : ([
    "place" : ({ "/d/mingjiao/banshanting", "/d/mingjiao/banshanyao", "/d/mingjiao/beixiangfang", 
        "/d/mingjiao/zoulang1", "/d/mingjiao/zoulang2", "/d/mingjiao/zoulang3", 
        "/d/mingjiao/midao1", "/d/mingjiao/midao2", "/d/mingjiao/midao3", 
        "/d/mingjiao/xiangfang_1", "/d/mingjiao/guangchang1", "/d/mingjiao/ruijinqi", 
        "/d/mingjiao/diecong1", "/d/mingjiao/diecong2", "/d/mingjiao/diecong3", 
        "/d/mingjiao/liehuoqi", "/d/mingjiao/jmqmen", "/d/mingjiao/shanmen"
		 }),
	"generation" : 35,
	"master" : "/d/mingjiao/npc/zhangwuji", 
	]),
"密宗" : ([
    "place" : ({ "/d/xueshan/shanjiao", "/d/xueshan/cangjing", "/d/xueshan/cangjingge"
        "/d/xueshan/caoyuan", "/d/xueshan/cedian1", "/d/xueshan/cedian2", 
        "/d/xueshan/chang", "/d/xueshan/chanshi", "/d/xueshan/dadian",  
        "/d/xueshan/guangcha", "/d/xueshan/houmen", "/d/xueshan/dilao", 
        "/d/xueshan/hubian1", "/d/xueshan/hubian2", "/d/xueshan/hubian3", 
        "/d/xueshan/kufang", "/d/xueshan/midao", "/d/xueshan/mishi", 
		 }),
	"generation" : 10,
	"master" : "/kungfu/class/xueshan/jiumozhi", 
	]),
"铁掌帮" : ([
	"place" : ({ "/d/tiezhang/road-3", "/d/tiezhang/shanjiao", "/d/tiezhang/shanmen", 
		"/d/tiezhang/shanlu-2", "/d/tiezhang/shanlu-1", "/d/tiezhang/guangchang", 
		"/d/tiezhang/lgfang", "/d/tiezhang/guajia", "/d/tiezhang/wztang", 
		"/d/tiezhang/zoulang-1", "/d/tiezhang/zoulang-2", "/d/tiezhang/zoulang-3", 
		"/d/tiezhang/zoulang-4", "/d/tiezhang/shanlu-1", "/d/tiezhang/shanlu-3", 
		"/d/tiezhang/shanlu-4", "/d/tiezhang/shanlu-5", "/d/tiezhang/shanlu-6", 
		"/d/tiezhang/shanlu-7", "/d/tiezhang/shanlu-8", "/d/tiezhang/shanlu-9", 
		"/d/tiezhang/bqshi", "/d/tiezhang/chufang", "/d/tiezhang/hxfang", 
		"/d/tiezhang/hhyuan-1", "/d/tiezhang/hhyuan-2", "/d/tiezhang/pingtai", 
		"/d/tiezhang/shangu-1", "/d/tiezhang/shangu-2", "/d/tiezhang/sslin-2", 
		 }),
	"generation" : 15,
	"master" : "/d/tiezhang/npc/qqren", 
	]),
]);

// 正派列表
string *zps = ({
"武当派", "少林派", "丐帮", "峨嵋派", "华山派", "大理段家", 
});

// 邪派列表
string *xps = ({
"星宿派", "明教", "密宗", "铁掌帮",
});

void create() 
{
	mapping my; 

	seteuid(getuid()); 
	set("channel_id", "门派任务精灵"); 

	CHANNEL_D->do_channel(this_object(), "sys", "门派任务精灵已经启动。"); 

// For test
        set_heart_beat(3); 
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

	remove_enemy();
	
	family = keys(familys);

	for (i = 0; i < sizeof(family); i++)
	{
		family_name = family[i];

		users = filter_array(users(), (: interactive($1) && $1->query("family/family_name") == $(family_name) 
                                && mapp($1->query_temp("swjob/allow")) :));
		num = sizeof(users) * (1 + random(2));
		if (! num) continue;

		CHANNEL_D->do_channel(this_object(), "sys", "敌人数量： "+ num +"。"); 
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
        || member_array(family, zps) == -1 && member_array(family, xps) == -1)
                enemy_fam = zps[random(sizeof(zps))];
        // 否则就派正派上场
        else enemy_fam = xps[random(sizeof(xps))];

        for (i = 0; i < num; i++)
        {
                enemy = new("/clone/npc/enemy");
                enemy->create_family(enemy_fam, familys[enemy_fam]["generation"] 
                                + (-1 + random(2)), "弟子" );
                enemy->set("is_attacking", family);
                move_enemy(enemy, family);
        }

        // now_fighting 格式：被攻击者 : 攻击者
        now_fighting[family] = enemy_fam;

        if (! find_object(familys[family]["master"])) 
                master = load_object(familys[family]["master"]);
        else master = find_object(familys[family]["master"]);

        CHANNEL_D->do_channel(master, "chat",
                        sprintf("听说%s的一班弟子大举杀上我派，我派形势不妙。", enemy_fam)); 

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
        CHANNEL_D->do_channel(this_object(), "sys",
                sprintf("%s : %O", enemy->short(), place)); 
        enemy->move(place);
        tell_room(place, "只见一名" + enemy->query_family() + "弟子不知什么时候钻了出来。\n");

        return;
}


int ask_job(object ob, object me)
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
                message_vision(HIC "$N" HIC "对$n" HIC "道：“" + RANK_D->query_respect(me) 
                                +"无门无派，问我要什么任务呢？”\n\n" NOR,ob,me);
		tell_object(me, HIW "你还是先拜个师父再要任务吧。\n" NOR);
		return 1;
	}

	if (ob->query("family/family_name") != me->query("family/family_name"))
	{
		ob->command("?" + me->query("id"));
		message_vision(HIC "$N" HIC "皱着眉头对$n" HIC "道：“这位" 
                        + me->query("family/family_name") +"的"+ RANK_D->query_respect(me) +"，你怕是找错人了吧？”\n\n" NOR,ob,me);
		tell_object(me, HIW "这不是你自己的门派，你不应该问这位师傅要任务呀。\n" NOR);
		return 1;
	}

	if (me->query("combat_exp") < MIN_EXP)
	{
		ob->command("sigh");
		message_vision(HIC "$N" HIC "对$n" HIC "道：“唉，你还是等水平高些再来做这个任务不迟。”\n\n" NOR, ob, me);
		tell_object(me, HIW "这个任务得有 " +MIN_EXP+" 点经验值才能做。\n" NOR);
		return 1;
	}

        if (me->query_temp("swjob/allow") && ! wizardp(me))
	{
		ob->command("yi");
		message_vision(HIC "$N" HIC "疑惑地对$n" HIC "道：“你不是已经在做这个任务了么？\n怎么还来找我？”\n\n" NOR, ob, me);
                tell_object(me, HIW "快去做好准备，守护你的门派吧。\n" NOR);
		return 1;
	}

	else {
                places = familys[me->query("family/family_name")]["place"];
		place = places[random(sizeof(places))];
		place = place->query("short");

		command("nod" + me->query("id"));
		message_vision(HIC "$N" HIC "赞许地对$n" HIC "道：“好吧，" + msg_now[random(sizeof(msg_now))]
		 +"，你要注意\n" + msg_do[random(sizeof(msg_do))] + "。”\n\n" NOR, ob, me);
		tell_object(me, HIW + ob->name() + HIW "悄悄告诉你：“" + place + HIW"这个地方" 
		+ msg_place[random(sizeof(msg_place))]+"\n你最好多注意注意。”\n" NOR);

		me->set_temp("swjob/allow", 1);
		me->apply_condition("swjob", 50 + random(50));
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
				tell_room(environment(enemys[i]), HIW "只见" + enemys[i]->name()
					+ "突然面色一变，迅速攻出几招，跳出战圈转身逃了。\n");
			}
			else {
				tell_room(environment(enemys[i]), HIW "只见" + enemys[i]->name()
					+ "掐值一算，突然脸色大变，急急忙忙地逃走了。\n");
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
	int killed, exp, pot;

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
		message_vision(HIC "$N" HIC "皱着眉头对$n" HIC "道：“这位" 
                        + me->query("family/family_name") +"的"+ RANK_D->query_respect(me) +"，你怕是找错人了吧？”\n" NOR,ob,me);
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
	}

	else {
		if (! me->query_temp("swjob/killed"))
		{
			ob->command("hmm");
			message_vision(HIC "$N" HIC "点点头对$n" HIC "道：“好吧，这次任务你存功未立，就不给你奖励了。”\n" NOR, ob, me);
			me->delete_temp("swjob");
			return 1;
		}
		else {
                        killed = (int)me->query_temp("swjob/killed");
			ob->command("nod");

            exp = killed *40 + random(200);
			exp = exp/2 + random(exp/2);
			pot = exp/3 +random(2);

			message_vision(HIC "$N" HIC "点点头对$n" HIC "道：“好！这次任务你成功截杀了"
				+ chinese_number(killed) +"个敌人，这里是给你的一点奖励。”\n" NOR, ob, me);
			tell_object(me, HIW "这次任务你得到了" + chinese_number(exp) + "点经验值和" 
				+ chinese_number(pot) + "点潜能值的奖励。\n" NOR);
                        me->delete_temp("swjob/allow");
                        me->delete_temp("swjob/killed");
                        me->delete_temp("swjob/finish");
			me->add("combat_exp", exp);
			me->add("potential", pot);

			return 1;
		}
	}
}
