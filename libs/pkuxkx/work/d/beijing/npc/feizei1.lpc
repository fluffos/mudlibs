//飞贼feizei.c
//这个飞贼是多隆任务产生的飞贼
#include <ansi.h>
inherit NPC;
#include <random_name.h>
#include "npc_setup.h"
mapping *quest = ({
      (["short":                "天龙寺三元宫",
       "place" :              "/d/tianlong/dadian",]),
      (["short":                "扬州青竹林",
       "place" :              "/d/city/ml1",]),
     (["short":                "峨嵋山门",
       "place" :              "/d/emei/shanmen",]),
     (["short":                "扬州西门",
       "place" :              "/d/city/ximen",]),
     (["short":                "襄阳雪峰脚下",
       "place" :              "/d/xiangyang/westr5",]),
     (["short":                "苏州留园",
       "place" :              "/d/suzhou/liuyuan",]),
     (["short":                "苏州寒山寺",
       "place" :              "/d/suzhou/hanshansi",]),
     (["short":                "苏州立雪堂",
       "place" :              "/d/suzhou/lixuetang",]),
     (["short":                "苏州致爽阁",
       "place" :              "/d/suzhou/zhishuang",]),
     (["short":                "泉州向阳老宅",
       "place" :              "/d/quanzhou/laozhai",]),
     (["short":                "泉州码头",
       "place" :              "/d/diaoyudao/matou0",]),
     (["short":                "白驼山蛇谷",
       "place" :              "/d/baituo/shegu1",]),
      (["short":                "扬州中央广场",
       "place" :              "/d/city/guangchang",]),
      (["short":                "襄阳黑松岭",
       "place" :              "/d/xiangyang/eroad5",]),
      (["short":                "平西王府后花园",
       "place" :              "/d/pingxiwangfu/garden",]),
      (["short":                "黑沼小屋",
       "place" :              "/d/yideng/yideng/yingguju",]),
      (["short":                "星宿海",
       "place" :              "/d/xingxiu/xxh1",]),
      (["short":                "武当三清殿",
       "place" :              "/d/wudang/sanqing",]),
      (["short":                "峨嵋万年庵",
       "place" :              "/d/emei/wannian",]),
      (["short":                "峨嵋千佛庵大殿",
       "place" :              "/d/emei/dadian",]),
      (["short":                "峨嵋药王洞",
       "place" :              "/d/emei/houshan/ywdong",]),
      (["short":                "明教广场",
       "place" :              "/d/mingjiao/guangchang",]),
      (["short":                "明教碧水潭畔",
       "place" :              "/d/mingjiao/bishuitanpan",]),
      (["short":                "姑苏慕容茶花林",
       "place" :              "/d/murong/mlin7",]),
      (["short":                "明教大沙漠",
       "place" :              "/d/mingjiao/shamo7",]),
      (["short":                "少林寺石阶",
       "place" :              "/d/shaolin/shijie4",]),
      (["short":                "汝州城",
       "place" :              "/d/shaolin/ruzhou",]),
      (["short":                "华山猢狲愁",
       "place" :              "/d/huashan/husun",]),
      (["short":                "华山玉女峰",
       "place" :              "/d/huashan/yunu",]),
      (["short":                "杀手帮清风堂",
       "place" :              "/d/pker/qingfengtang",]),
      (["short":                "杀手帮练武场",
       "place" :              "/d/pker/wuchang1",]),
      (["short":                "大理万劫谷",
       "place" :              "/d/tianlong/gu",]),
      (["short":                "扬州城北门",
       "place" :              "/d/city/beimen",]),
      (["short":                "灵鹫独尊厅",
       "place" :              "/d/lingjiu/zhengting",]),
      (["short":                "襄阳帅府大厅",
       "place" :              "/d/xiangyang/sfdating",]),
      (["short":                "少林寺走廊",
       "place" :              "/d/shaolin/zoulang7",]),
      (["short":                "武当桃园小路",
       "place" :              "/d/wudang/tyroad8",]),
      (["short":                "少林寺般若堂九部",
       "place" :              "/d/shaolin/banruo9",]),
      (["short":                "灵鹫仙愁门",
       "place" :              "/d/lingjiu/xianchou",]),
      (["short":                "日月朱雀堂",
       "place" :              "/d/riyuejiao/zhuquetang",]),
       (["short":                "六盘山",
       "place" :              "/d/xingxiu/xxroad3",]),
       (["short":                "丝绸之路",
       "place" :              "/d/xingxiu/silk1",]),
       (["short":                "汉水南岸",
       "place" :              "/d/shaolin/hanshui1",]),
       (["short":                "桃花岛赏月台",
       "place" :              "/d/taohuadao/shangyuetai",]),
       (["short":                "汉水北岸",
       "place" :              "/d/shaolin/hanshui2",]),
       (["short":                "华山之巅",
       "place" :              "/hslj/biwu",]),
       (["short":                "天山脚下",
       "place" :              "/d/xingxiu/shanjiao",]),
       (["short":                "华山脚下",
       "place" :              "/d/huashan/path1",]),
       (["short":                "华山千尺幢",
       "place" :              "/d/huashan/qianchi",]),
       (["short":                "全真净人访",
       "place" :              "/d/quanzhen/jingrenf",]),
       ([      "short":                "全真凝雪阁",
                "place":                "/d/quanzhen/ninglg",
        ]),([      "short":                "陆家庄後院",
                "place":                "/d/quanzhou/yuan",
        ]),([     "short":                "玉皇顶",
                 "place":               "/d/taishan/yuhuang",
         ]),([      "short":                "泰山柴门",
                "place":                "/d/taishan/fefe8",
        ]),([      "short":                "天山山路",
                "place":                "/d/xingxiu/tianroad1",
        ]),([      "short":                "嘉峪关",
                "place":                "/d/xingxiu/jiayuguan",
        ]),([      "short":                "月儿泉",
                "place":                "/d/xingxiu/yueerquan",
        ]),([      "short":                "巴依家客厅",
                "place":                "/d/xingxiu/house1",
        ]),([      "short":                "丐帮林间小屋",
                "place":                "/d/city/gbxiaowu",
        ]),([      "short":                "全真延灵阁",
                "place":                "/d/quanzhen/yanlingg",
        ]),([      "short":                "古墓大厅",
                "place":                "/d/gumu/dating",
        ]),([      "short":                "古墓小厅",
                "place":                "/d/gumu/xiaoting",
        ]),([      "short":                "铁枪庙",
                "place":                "/d/quanzhou/tieqiang",
        ]),([      "short":                "嘉兴南湖",
                "place":                "/d/quanzhou/nanhu1",
        ]),([      "short":                "牙山湾西口",
                "place":                "/d/yashan/wanxi3",
        ]),([      "short":                "牙山海边基地",
                "place":                "/d/yashan/waneast3",
        ]),([      "short":                "牙山小荒地",
                "place":                "/d/yashan/wansouth3",
        ]),([      "short":                "牙山驿道",
                "place":                "/d/yashan/yidao3",
        ]),([      "short":                "古墓侧室",
                 "place":                "/d/gumu/ceshi",
        ]),([      "short":                "古墓断龙石",
                 "place":                "/d/gumu/duanlongshi",
        ]),([      "short":                "终南山小溪",
                 "place":                "/d/gumu/xiaoxi",
        ]),([      "short":                "终南山地下河",
                 "place":                "/d/gumu/dixiahe2",
        ]),([      "short":                "白驼草莓地",
                 "place":                "/d/baituo/caomeide",
        ]),([      "short":                "少林石阶",
                 "place":                "/d/shaolin/shijie7",
        ]),([      "short":                "归云庄后花园",
                 "place":                "/d/guiyunzhuang/houhuayuan",
        ]),([      "short":                "归云庄练功房",
                 "place":                "/d/guiyunzhuang/liangongfang1",
        ]),([      "short":                "归云庄炼丹房",
                 "place":                "/d/guiyunzhuang/danfang",
        ]),([      "short":                "归云庄密林",
                 "place":                "/d/guiyunzhuang/milin1",
        ]),([      "short":                "太湖阁",
                 "place":                "/d/guiyunzhuang/taihuge",
        ]),([      "short":                "黑风山脚",
                 "place":                "/d/guiyunzhuang/shanlu1",
        ]),([      "short":                "千尺幢",
                 "place":                "/d/huashan/qianchi",
        ]),([      "short":                "泰山斗母宫",
                 "place":                "/d/taishan/doumo",
        ]),([      "short":                "太湖街",
                 "place":                "/d/guiyunzhuang/taihujie",
        ]),([      "short":                "嘉兴河岸",
                 "place":                "/d/quanzhou/river",
        ]),([      "short":                "岳王墓忘忧亭",
                 "place":                "/d/yuewangmu/wangyouting",
        ]),([      "short":                "岳王墓墓后空地",
                 "place":                "/d/yuewangmu/muhou",
        ]),([      "short":                "桃花岛试剑峰",
                 "place":                "/d/taohuadao/shijianfeng",
        ]),([      "short":                "少林藏经阁小屋",
                 "place":                "/d/shaolin/cjlou2",
        ]),([      "short":                "扬州丽春院",
                 "place":                "/d/city/lichunyuan",
        ]),([      "short":                "明教巨木坛",
                 "place":                "/d/mingjiao/jm-tan",
        ]), ([      "short":                "明教了望塔",
                 "place":                "/d/mingjiao/liaowang",
        ]),([      "short":                "绿柳山庄小院",
                 "place":                "/d/mingjiao/yuan2",
        ]),([      "short":                "桃花岛竹林",
                 "place":                "/d/taohuadao/zhulin2",
        ]),([      "short":                "星宿山谷口",
                 "place":                "/d/xingxiu/gu2",
        ]),([      "short":                "扬州房产公司",
                 "place":                "/d/city/fangchan",
        ]),([      "short":                "桃源驿路",
                 "place":                "/d/yideng/yideng/road2",
        ]),([      "short":                "杀手帮山门",
                 "place":                "/adm/npc/shanmen",
        ]),([      "short":                "大驿道",
                 "place":                "/d/taishan/yidao",
        ]),([      "short":                "全真石阶",
                 "place":                "/d/quanzhen/shijie4",
        ]),([      "short":                "无名谷底",
                 "place":                "/d/quanzhou/wuminggudi",
        ]),([      "short":                "五里街",
                 "place":                "/d/taohuadao/wulijie1",
        ]),([      "short":                "华山村南村口",
                 "place":                "/d/village/sexit",
        ]),([      "short":                "华山村小巷尽头",
                 "place":                "/d/village/alley2",
        ]),([      "short":                "星宿海",
                 "place":                "/d/xingxiu/xxh2",
        ]),([      "short":                "天山脚下",
                 "place":                "/d/xingxiu/shanjiao",
        ]),([      "short":                "丝绸之路",
                 "place":                "/d/xingxiu/silk2",
        ]),([      "short":                "沙漠绿洲",
                 "place":                "/d/xingxiu/luzhou",
        ]),([      "short":                "正气山庄",
                 "place":                "/d/city/shanzhuang",
        ]),([      "short":                "武庙",
                 "place":                "/d/city/wumiao",
        ]),([      "short":                "姑苏慕容钓鱼台",
                 "place":                "/d/murong/tdiaoyu",
        ]),([      "short":                "听香水榭",
                 "place":                "/d/murong/tingxiang",
        ]),([      "short":                "琴韵小居",
                 "place":                "/d/murong/qinyun",
        ]),([      "short":                "景山",
                 "place":                "/d/beijing/jingshan",
        ]),([      "short":                "天坛丹陛桥",
                 "place":                "/d/beijing/tiantan/danbiqiao",
        ]),([      "short":                "北京天桥",
                 "place":                "/d/beijing/tianqiao",
        ]),([      "short":                "天地会大厅",
                 "place":                "/d/luoyang/qingmutang",
        ]),([      "short":                "鳌府后院",
                 "place":                "/d/beijing/aobai4",
        ]),([      "short":                "庄府大门",
                 "place":                "/d/beijing/zhuang3",
        ]),([      "short":                "康亲王府后花园",
                 "place":                "/d/beijing/kangqin/garden",
        ]),([      "short":                "乾清门",
                 "place":                "/d/beijing/zijin/qianqingmen",
        ]),
      });

mapping query_quest()
{
  return quest[random(sizeof(quest))];
}
int do_yes();
int do_no();
void create()
{
    set_name(get_rndname(), ({get_rndid(), }));
    set("nickname", get_rndnick());
    set("age", 10 + random(50));

    set("chat_chance", 5);
    set("chat_msg", ({
	(: random_move :)
	}) );
    setup();
    call_out("destroyme",600);    
}

void destroyme()
{
	      message_vision("$N嘿嘿奸笑了两声道：“过了这么久了，应该风平浪静了吧，我闪！”\n",this_object());
        destruct(this_object());
}

void init()
{
	object ob, me;
	mapping dizhis;
	int exp, nei, nei1;

	::init();

	ob = this_player();
	me = this_object();
        nei = me->query("neili",1);
        nei1 = ob->query("neili",1);


	dizhis = query_quest();
	exp = me->query("combat_exp");

	if (interactive(ob)
		&& ob->query("class") == "officer")
	{
		if (ob->query_temp("feizei/gkill1") && (me->query("catcher") == ob->query("id") || me->query("catcher") == "auto create"))
		{
			message_vision(HIR"$n看到$N目光冷冷注视着自己一动不动，不由停下了脚步。\n"NOR, ob, me);
			switch(random(4))
			{
           			case 0:
				message_vision(
					"$n嘿嘿奸笑几声，连忙赔笑道，这位"+RANK_D->query_respect(ob)+"是"
"官府的捕头吧？！大家都是武林中人，今天能否高抬贵手？我必有重谢！你好好斟酌一下，是否愿意？\n",ob,me);
			write (HIY"你可以选择同意(yes)或者拒绝(no)。\n"NOR);
			ob->set_temp("guanf_huida1", me->query("name"));
			if (random(2) == 0)
			ob->delete_temp("feizei/gkill1");
			break;
				case 1:
			message_vision(
				HIR"$n阴笑一声说道，这麽多不怕死的？再来十个大爷我也不怕！\n"
				"随即眼睛一瞪，向着$N就冲了过去！\n"NOR,ob,me);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
			ob->delete_temp("feizei/gkill1");
			break;
				case 2:
			message_vision(
	WHT"$n待$N走到近前，冷冷一笑，说道，你千里追到这里，我看你又能奈我何！\n"NOR,ob,me);
			write (WHT"你感到一股无形的杀气，心中不由一颤。\n"NOR);
			ob->delete_temp("feizei/gkill1");
			break;
				case 3:
			message_vision(
			"$n忽然泪流满面，一幅可怜的神情对$N说道，小人上有老下有小，而且完全是官府被\n"
			"陷害才落此地步，望你老明察秋毫，网开一面，我今生一定感激不禁。\n",ob,me);
			write (HIY"你可以选择同意(yes)或者拒绝(no)。\n"NOR);
			ob->delete_temp("feizei/gkill1");
			ob->set_temp("guanf_huida1", me->query("name"));
				break;
			}
		}
	if (ob->query_temp("feizei/gkill1")
	&& (string)me->query("name") == ob->query_temp("guanfu_huida1"))
	{
		message_vision(
			HIR"$n看到$N走到近前，狠狠的骂道，不识抬举的东西，我好言相劝没用，\n"
			"今天就让你尝尝大爷的厉害。\n"NOR,ob,me);
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
		ob->delete_temp("guanf_huida1");
		ob->delete_temp("feizei/gkill1");
	}
        }
	if (ob->query_temp("feizei/gkill2") && (me->query("catcher") == ob->query("id") || me->query("catcher") == "auto create"))
	{
	switch(random(4))
	    {
		case 0:
			message_vision(
				HIR"$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,
				ob,me);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
			return;
			break;
		case 1:
			message_vision(
			HIY"$n一看到$N，嘿嘿一笑，头也不回挤进行人之中，脚下抹油溜了。\n"NOR,ob,me);
			ob->delete_temp("feizei/gkill2");
			ob->set_temp("feizei/gkill3",1);
			break;
		case 2:
			message_vision(
				HIR"$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,
				ob,me);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
			return;
			break;
		case 3:
			message_vision(
				HIR"$n额头青筋跳动，冷哼了一声，瞪着通红的眼睛向着$N就冲了过去。\n"NOR,
				ob,me);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
			return;
			break;
		}
	   write(WHT"" + me->short() + "好象往「" + dizhis["short"] + "」的方向逃去了。\n"NOR);
	   me->set("can_arrest", 1);
           me->move(dizhis["place"]);
           return;
	}
	if (ob->query_temp("feizei/gkill3") && (me->query("catcher") == ob->query("id") || me->query("catcher") == "auto create"))
	{
 message_vision(HIR"$n气急败坏的对$N嚷道：“杀人不过头点地，你一再苦苦相逼，大爷今天就和你拼个鱼死网破。”\n"NOR,ob,me);
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
		return ;
	}
	if (find_call_out("dest") == -1)
	call_out("dest", 480);
	add_action("do_yes","yes");
	add_action("do_no","no");
}

int do_yes()
{
        object r_shen, me, ob;
        me = this_object();
        ob = this_player();

        if (!ob->query_temp("guanf_huida1"))
        return 0;
        if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
        return 0;
        switch (random(6))
        {
        	case 0:
	        command("say 这位"+RANK_D->query_respect(ob)+"一定前途远大，嘿嘿，我是不会亏待你的。\n");
	        me->add_money("gold", 10 + random(20));
        	command("give " + ob->query("id") + " gold");
        	message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        	break;

		case 1:
	        command("say 我早就看出这位"+RANK_D->query_respect(ob)+"是当世的俊杰，嘿嘿，这点小礼物请务必收下。\n");
	        me->add_money("gold", 15 + random(20));
        	command("give " + ob->query("id") + " gold");
        	message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        	break;

		case 2:
	        command("say 您老人家功夫如此出众，小的实在想不出拿什麽孝敬您老，回头我想起在说吧。\n");
        	message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        	break;

		case 3:
	        command("say 这位"+RANK_D->query_respect(ob)+"前途远大，一身正气，嘿嘿，佩服。\n");
        	me->add_money("gold",20+random(30));
        	command("give "+ob->query("id")+" gold");
        	message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        	break;

		case 4:
	        command("say 这位"+RANK_D->query_respect(ob)+"真是义薄云天，这个小礼物敬请务必收下。\n");
	        me->add_money("gold",30+random(30));
        	command("give "+ob->query("id")+" gold");
	        message_vision("$N嘿嘿一笑，转身离开，一眨眼就消失不见了。\n",me);
        	break;

		case 5:
        	command("say 自古邪正势不两立，在下不过开个小小玩笑，千万不要当真啊。\n");
        	command("laugh " + ob->query("id"));
        	write("对方好象在拿你取笑，你不由怒火中烧。\n");
		tell_room(environment(me), me->query("name")+"纵身跳入行人之中，转眼就不见了。\n", ({me}));
        	break;
	}
	ob->delete_temp("guanf_huida1");
	ob->delete_temp("feizei/gkill1");
        destruct(me);
	return 1;
}


int do_no()
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if (!ob->query_temp("guanf_huida1"))
        return 0;
        if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
        return 0;

        if ((int)ob->query("shen") < 1)
        {
        command("say 这位"+RANK_D->query_respect(ob)+"一身瘴气，你我本是一路货色，却在这里装什么侠义英雄呢？！\n");
        ob->delete_temp("guanf_huida1");
        ob->delete_temp("feizei/gkill1");
        me->kill_ob(ob);
        return 1;
        }
        command("say 这位"+RANK_D->query_respect(ob)+"一身正气，不愧名门正派弟子，不过不知道功夫怎麽样？！\n");
        command("hehe " + ob->query("id"));
        ob->delete_temp("guanf_huida1");
        ob->delete_temp("feizei/gkill1");
        me->kill_ob(ob);
        return 1;
}

void die()
{
        object ob, me, bao;
        mapping dizhis;

        ob = this_object();
        dizhis = query_quest();

	if (!objectp( me = get_damage_origin_object()))
	{
		message_vision(HIR"巫师提示：请使用有last_damage的perform，不好意思这个任务只能算你失败了^_^。\n"NOR, ob);
		destruct(ob);
		return;
	}
	if (ob->query("catcher") != me->query("id") && ob->query("catcher") != "auto create")
	{
		message_vision(WHT"$N无辜地喊到：难道没有天理了吗？？？为什么杀我？？？\n"NOR,ob);
		message_vision("$N一口鲜血喷出，倒在地上，死了。\n",ob);
		destruct(ob);
		return;
	}
        if (!me->query_temp("feizei/gkill3")
        &&  !me->query_temp("feizei/gkill2") )
        {
        message_vision(WHT"$N深吸口气，冷笑道，好身手！说完强忍伤痛纵身向「" + dizhis["short"] + "」处逃走。\n"NOR,ob,me);
        me->set_temp("feizei/gkill2",1);
        ob->reincarnate();
        ob->delete_temp("last_damage_from");
        ob->move(dizhis["place"]);
        return;
        }
        if (me->query_temp("feizei/gkill2"))
        {
        message_vision(WHT"$N冷笑一声，说道，好俊的功夫！说完纵身向「" + dizhis["short"] + "」处逃走。\n"NOR,ob,me);
        me->delete_temp("feizei/gkill2");
        me->set_temp("feizei/gkill3",1);
        ob->reincarnate();
        ob->delete_temp("last_damage_from");
        ob->set("can_arrest", 1);
        ob->move(dizhis["place"]);
        return;
        }
        //加入一段代码
	bao = new(__DIR__"obj/caibao");
	bao->set("owner", me);
	if(ob->query("bao_value"))
	bao->set("value", ob->query("bao_value"));
	bao->move(ob);
        me->delete_temp("feizei");
        if ((me->query("class") == "officer") && (ob->query("catcher")=="auto create"))
	{
		me->add("chaoting/catch_feizei",1);
                tell_object(me,"感谢你为地方治安做了贡献！到现在为止你已经抓了" + CHINESE_D->chinese_number(me->query("chaoting/catch_feizei")) 
			+ "个流窜的飞贼。\n");
	}
    if(!random(30))
    {
        CHANNEL_D->do_channel(this_object(), "bd", "hero", 1);
        CHANNEL_D->do_channel(this_object(), "bd", sprintf("%s，来世老子不会放过你！", me->name()));
    }
    ::die();
}

void unconcious()
{
	die();
}
int accept_fight(object me)
{
	command("say 大爷我正要赶路，没心思和你动手。");
	return 0;
}
void dest()
{
       object ob;
       ob = this_object();
       if (environment())
       message_vision("只见$N忽然急转身行，纵身钻进行人中，转眼就踪迹皆无。\n", ob);
       destruct(this_object());
}

void reincarnate()
{
    set("eff_jing", query("max_jing"));
    set("eff_qi", query("max_qi"));
    set("qi", query("max_qi"));
    set("neili", query("max_neili"));
}
