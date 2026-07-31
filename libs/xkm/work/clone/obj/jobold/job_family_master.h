//Cracked by Kafei
//wzfeng 2000 6
//job_family_master.h
//产生任务发布人名单

#include <ansi.h>
static mapping family_skills_award=([
					  "武当派" :({"taiji-shengong","taiji-quan","taiji-jian","taoism"}),
					  "星宿派"	:({"huagong-dafa","poison","chousui-zhang","sanyin-zhua"}),
					  "华山派"	:({"zhengqi-jue","zixia-gong","ziyin-yin","hunyuan-zhang"}),
					  "桃花岛"	:({"bitao-xuangong","qimen-dunjia","tanzhi-shentong","yuxiao-jian"}),
					  "丐帮"	:({"shexing-diaoshou","xianglong-zhang","shexing-diaoshou","dagou-bang"}),
					  "峨嵋派"	:({"linji-zhuang","mahayana","persuading","jinding-zhang"}),
					  "白驼山"	:({"hamagong","poison","lingshe-zhang","training"}),
					  "全真教"	:({"xiantian-gong","sanhua-juding","chunyang-quan","taoism"}),
					  "雪山派"	:({"longxiang-banruo","lamaism","huoyan-dao","yujiamu-quan"}),
					  "大理段家":({"buddhism","kurong-changong","yiyang-zhi","qingyan-zhang"}),
					  "少林派"	:({"buddhism","hunyuan-yiqi","yizhi-chan","jingang-quan"}),
					  ]);


static mapping family_master=([
					   "武当派" :"掌门人张真人/张真人/zhang sanfeng/湖北武当山/张三丰",
					  "星宿派"	:"星宿老仙/老仙/ding chunqiu/星宿海/丁春秋",
					  "华山派"	:"岳掌门/掌门/yue buqun/华山/岳不群",
					  "桃花岛"	:"庄主/庄主/lu chengfeng/太湖归云庄/陆乘风",
					  "丐帮"	:"洪帮主/帮主/hong qigong/扬州总舵/洪七公",
					  "峨嵋派"	:"掌门灭绝师太/掌门/miejue shitai/四川峨嵋山/灭绝师太",
					  "白驼山"	:"欧阳主人/主人/ouyang feng/西域白驼山/欧阳锋",
					  "全真教"	:"掌门人丘处机/掌门/qiu chuji/终南山/丘处机",
					  "雪山派"	:"大轮明王鸠摩智/大轮明王/jiumozhi/西藏大雪山/鸠摩智",
					  "大理段家"	:"段王爷/王爷/duan zhengchun/云南大理/段正淳",
					  "少林派"	:"玄慈方丈/方丈/xuanci dashi/嵩山少林寺/玄慈大师",
					  ]);
static mapping family_master_place=([
					   "武当派" :"/d/wudang/xiaoyuan",
					  "星宿派"	:"/d/xingxiu/riyuedong",
					  "华山派"	:"/d/huashan/buwei1",
					  "桃花岛"	:"/d/taihu/shufang",
					  "丐帮"	:"/d/gaibang/gbxiaowu",
					  "峨嵋派"	:"/d/emei/hz_back",
					  "白驼山" : "/d/baituo/lingshege",
					  "全真教"	:"/d/zhongnan/dadian",
					  "雪山派"	:"/d/xueshan/angqian2",
					  "大理段家":"/d/dali/wangfu8",
					  "少林派"	:"/d/shaolin/fzlou2",
					  ]);

static mapping assess_place=([
					   "武当派" :"/d/wudang/sanqingdian",
					  "星宿派"	:"/d/xingxiu/riyuedong",
					  "华山派"	:"/d/huashan/buwei1",
					  "桃花岛"	:"/d/taihu/dating",
					  "丐帮"	:"/d/gaibang/pomiao",
					  "峨嵋派"	:"/d/emei/daxiong",
					  "白驼山" : "/d/baituo/dating",
					  "全真教"	:"/d/zhongnan/dadian",
					  "雪山派"	:"/d/xueshan/guangchang",
					  "大理段家":"/d/dali/wangfu4",
					  "少林派"	:"/d/shaolin/dxbdian",
					  ]);

static mapping family_master_basefile=([
					   "武当派" :"/kungfu/class/wudang/zhang",
					  "星宿派"	:"/kungfu/class/xingxiu/ding",
					  "华山派"	:"/kungfu/class/huashan/buqun",
					  "桃花岛"	:"/kungfu/class/taohua/huang",
					  "丐帮"	:"/kungfu/class/gaibang/hong",
					  "峨嵋派"	:"/kungfu/class/emei/miejue",
					  "白驼山" : "/kungfu/class/baituo/feng",
					  "全真教"	:"clone/npc/qiu",
					  "雪山派"	:"/kungfu/class/xueshan/jiumo",
					  "大理段家":"/kungfu/class/dali/zhengchun",
					  "少林派"	:"/kungfu/class/shaolin/xuan-ci",
					  ]);


static mapping *wudang_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N拍了拍$n的头,说道：“$P，你来的正好。”\n",
		"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近经常有蒙古哒子出现，时常杀我中原百姓，你速去将其除去，为我百姓除害。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),


	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),
		([
		"job_tell_mode":"assess",		
		"prompt":HIY"掌门张真人已传下号令，马上召开武当重要会议，请您尽快赶到武当山三清殿。\n"NOR,
		"send_to" :"各位武当弟子请了！",
		"send_to1":"为察看各位武当弟子近期来的表现，定于三日后在武当山三清殿召开门派大会。",
		"kick_out": "$N说道：“现在我武当派正在进行掌门会议，请非本门英雄离开此处。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“我武当开派以来，行侠江湖，多行仁义之事，一直已维护江湖正义为己任，除暴安良，驱逐哒子。”\n",
		"assess_start":"$N说道：“现在开始武当派大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为我武当所做贡献最大，特传授你武当太极精要，望你能将我武当发扬光大。”\n",
		"assess_punish":"$N说道：“$P，你数次违我武当号令，令武当威严受损，该受门规处置！”\n",
		"assess_award_common":"$N说道：“希望我武当能振兴武林，凡武当弟子须时时牢记我武当精义。”\n",
		"assess_end":"$N说道：“这次武当大会到此结束。”说罢$N道袍一挥。\n"
		
		]),
		});
static mapping *xingxiu_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n「嘿嘿嘿」奸笑了几声，说道：“$P，本尊正有事找你呢。”\n",
		"time_over" : "$N啪的对着$n就是一记耳光，打的$n眼冒金星，头昏目眩。\n"
						"$N对$n大吼道：“$P，你怎么现在才来，是否不把老仙我放在眼里？\n"
						"下次要再如此，看我不用万毒攻心之法整治你！”\n"

		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有些自称江湖大侠的狂妄之辈，时常阻我星宿弟子办事，你去为老仙我将他杀了。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“干得好，$P，老仙我越来越欣赏你了。”\n"
		]),
		([
		"job_tell_mode":"assess",		
		"prompt":HIY"星宿老仙已传下号令，马上召开星宿派百仙大会，请您尽快赶到星宿海日月洞。\n"NOR,
		"send_to" :"各位星宿弟子听了！",
		"send_to1":"为察看你们对老仙我的忠诚心，现定于三日后在星宿海日月洞召开百仙大会。",
		"kick_out": "$N说道：“现在星宿派正在举行百仙大会，请非本门人士离开。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“自从老仙我开创星宿一派来，星宿派威振武林，星宿老仙的名号更是享誉天下。”\n",
		"assess_start":"$N说道：“现在开始百仙大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为老仙所做贡献最大，特传授你星宿毒技和化攻大法精要，老仙我越来越喜欢你了，嘿嘿！”\n",
		"assess_punish":"$N说道：“$P，你数次违我命令，现已万毒穿心之法处置。”\n",
		"assess_award_common":"$N说道：“希望星宿派能争霸武林，老仙我长生不老。”\n",
		"assess_end":"$N说道：“这次白仙大会到此结束。”说罢$N道袍一挥。\n"
		
		]),




		});
static mapping *huashan_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好，我正有事要让你去办。”\n",
		"time_over" :  "$N对$n皱了皱眉，说道：“$P，你怎么现在才来，我本有重要任务让你去做，可现在为时已晚。\n"
						"$N对$n说道：“你延误掌门命令，该受门规处治。”\n"

		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近经常有邪派妖人出现，时常杀我华山弟子，你速去将其除去，为我华山除害。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),

		([
		"job_tell_mode":"assess",		
		"prompt":HIY"岳掌门已传下号令，令华山弟子人速华山正气堂召开门派评定大会。\n"NOR,
		"send_to" :"各位华山弟子请了！",
		"send_to1":"为审查大家近期的所作所为，现定于三日后在华山正气堂召开门派评定大会，凡我华山弟子，务必到时参加。",
		"kick_out": "$N说道：“现在华山派正在召开重要会议，闲杂人等请速离去。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“想我华山派，乃武林正派，行侠仗义于江湖，惩恶除奸，在江湖上声威显赫。”\n",
		"assess_start":"$N说道：“好，现在开始华山派评定大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为我华山立功不小，我将华山派镇山之宝紫霞功要决传授于你，望你今后行侠仗义，造福武林！”\n",
		"assess_punish":"$N说道：“$P，你数次违我掌门号令，该当严惩！”\n",
		"assess_award_common":"$N说道：“希望各位继续努力，将我华山发扬光大。”\n",
		"assess_end":"$N说道：“这次评定大会到此结束。”\n"
		
		]),






		});

static mapping *taohua_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好。”\n",
		"time_over" : "$N对$n冷哼一声，说道：“$P，我以为你永远也不会来了。我本有要事找你，但你误我时机，该受重罚！\n"
					"$N说道：“我东邪门下，岂能有不尊师命之徒！下次再犯，一并治罪！”\n"

		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有人杀我桃花弟子，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),

		([
		"job_tell_mode":"assess",		
		"prompt":HIY"桃花岛主黄药师已经传下号令，令东邪门人速回太湖归云庄，在大厅侯命。\n"NOR,
		"send_to" : "凡我东邪门人听了",
		"send_to1":	"三日后，老夫会于太湖归云庄察看各位近期来的表现，到时须来归云庄见我。",
		"kick_out": "$N说道：“现在东海桃花岛正在召开重要会议，闲杂人等请速离去。”\n",
		"kick_out_player": "$N将$n赶了出去。\n",
		"family":"$N说道：“想我东海桃花岛，武功自称一派，江湖中那个不惧我东邪门人？哈哈哈......”\n",
		"assess_start":"$N说道：“好，现在开始。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为我桃花岛闯下不小威名，我将一生武功精髓传授于你，今后不要堕了我黄老邪的威名！”\n",
		"assess_punish":"$N说道：“$P，你数次违我命令，该当严惩！”\n",
		"assess_award_common":"$N说道：“希望各位继续努力，让江湖中人莫要小瞧了我桃花岛。”\n",
		"assess_end":"$N说道：“老夫还有要事去办，就不多留了，我们有缘再会。”\n"
		
		]),



		});

static mapping *gaibang_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N拍拍$n的肩，说道：“$P，来，老叫化给你份差事。”\n",
	"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有人杀我丐帮弟子，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),

		([
		"job_tell_mode":"assess",		
		"prompt":HIY"洪帮主已传下号令，马上召开改帮大会，请您尽快赶到扬州总舵。\n"NOR,
		"send_to" : "各位丐帮英雄请了！",
		"send_to1":	"为察看各位弟子近期来的表现，定于三日后在扬州总舵召开丐帮大会。",
		"kick_out": "$N说道：“现在我丐帮正在进行重要会议，请非本门英雄离开此处。”\n",
		"kick_out_player": "$N将$n一脚踢了出去。\n",
		"family":"$N说道：“想我丐帮，向来行侠江湖，多行仁义之事，一直已维护江湖正义为己任。”\n",
		"assess_start":"$N说道：“现在开始丐帮大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为我丐帮所做贡献最大，特传授丐帮降龙掌法和打狗帮精要与你。”\n",
		"assess_punish":"$N说道：“$P，你数次违我帮主号令，该受帮规处置！”\n",
		"assess_award_common":"$N说道：“希望丐帮能振兴武林，凡丐帮弟子须时时牢记我改帮精义。”\n",
		"assess_end":"$N说道：“这次丐帮大会到此结束。”\n"
		
		]),



		});
static mapping *emei_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好。”\n",
	"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有魔教妖人出没，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),
		([
		"job_tell_mode":"assess",		
		"prompt":HIY"掌门灭绝师太已经传下法旨，令峨嵋弟子速回峨嵋山华藏庵大雄宝殿召开掌教大会。\n"NOR,
		"send_to" : "峨嵋弟子听了！",
		"send_to1":	"三日后于华藏庵大雄宝殿召开峨嵋大会，凡峨嵋弟子，到时务必参加。",
		"kick_out": "$N说道：“现在峨嵋派正在召开重要会议，闲杂人等请速离去。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“我峨嵋派自郭祖师开创以来，一直是行侠江湖，除恶扬善。本次大会，重在考核各门人近来所作所为。”\n",
		"assess_start":"$N说道：“峨嵋派评定大会正式开始。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为峨嵋所做贡献不小，现授予你峨嵋派至高武学精义，望今后行侠仗义，除恶出奸！”\n",
		"assess_punish":"$N说道：“$P，你数次违我峨嵋掌门意旨，该当严惩！”\n",
		"assess_award_common":"$N说道：“还望各位能牢记我峨嵋派信义，行侠仗义，除恶扬善。”\n",
		"assess_end":"$N说道：“本次评定大会到此结束。”\n"
		
		]),





		});
static mapping *baituo_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N回过头看了$n一眼，说道：“$P，我现在差你去办件事。”\n",
	"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有人与我白驼山做对，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),
		([
		"job_tell_mode":"assess",		
		"prompt":HIY"欧阳主人已经传下命令，令白驼弟子速回西域白驼山庄召开评议大会。\n"NOR,
		"send_to" : "白驼山弟子听了！",
		"send_to1":	"三日后于西域白驼山庄召开评议大会，到时务必参加。",
		"kick_out": "$N说道：“现在白驼山派正在召开重要会议，闲杂人等请速离去。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“我西域白驼山自创建以来，向来我行我素，凡有阻碍我白驼山之人，一律杀无赦！”\n",
		"assess_start":"$N说道：“白驼山评定大会正式开始。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为白驼山做贡献不小，现传授你蛤蟆功要决，望多为白驼山争口气！”\n",
		"assess_punish":"$N说道：“$P，你数次违我意旨，该当严惩！”\n",
		"assess_award_common":"$N说道：“还望各位能牢记我的训斥。”\n",
		"assess_end":"$N说道：“本次评定大会到此结束。”\n"
		
		]),



		});
static mapping *quanzhen_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好。”\n",
		"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"

		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有人杀我全真弟子，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),


		([
		"job_tell_mode":"assess",		
		"prompt":HIY"掌门丘真人已经传下法旨，令全真弟子速回终南山重阳宫长春殿召开掌教大会。\n"NOR,
		"send_to" : "全真教徒听了！",
		"send_to1":	"三日后于终南山重阳宫长春殿召开掌教大会，凡我全真教门下，务必准时参加。",
		"kick_out": "$N说道：“现在全真教正在召开重要会议，闲杂人等请速离去。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“我全真自重阳真人开创以来，一直行侠江湖，除恶扬善。本次大会，重在考核各门人近来所作所为。”\n",
		"assess_start":"$N说道：“全真教掌教评定大会正式开始。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为我全真教所做贡献不小，现授予你我教至高武学精义，望今后行侠仗义，多做我辈善事！”\n",
		"assess_punish":"$N说道：“$P，你数次违我全真教意旨，该当严惩！”\n",
		"assess_award_common":"$N说道：“还望各位能牢记重阳祖师所训，行侠仗义，除恶扬善。”\n",
		"assess_end":"$N说道：“本次评定大会到此结束。”\n"
		
		]),


		});
static mapping *xueshan_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好，本尊差你去办件事。”\n",
		"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有人杀我雪山弟子，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),
		([
		"job_tell_mode":"assess",		
		"prompt":HIY"大轮寺的钟声已经响起，催促各喇嘛们回到大轮寺广场召开宏法大会。\n"NOR,
		"send_to" : "各位雪山派喇嘛听旨！",
		"send_to1":	"为评定各喇嘛们近日的所作所为，将于三日后于大轮寺广场召开宏法大会。",
		"kick_out": "$N说道：“现在我雪山派喇嘛们正在进行重要的会议，请闲杂人等离开此处。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“我密宗自葛巴活佛以来，宣扬佛法，以普渡众生为目的，整救世人于苦难之中。”\n",
		"assess_start":"$N说道：“阿弥陀佛！现在开始宏法大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为我密宗所做贡献最大，本座传授你密宗武学精要，望你能将密宗发扬光大。”\n",
		"assess_punish":"$N说道：“$P，你数次违我指令，该受本座严惩！”\n",
		"assess_award_common":"$N说道：“希望各位继续努力，时时刻刻牢记活佛教义。”\n",
		"assess_end":"$N说道：“这次大会到此结束，阿弥陀佛！”。说罢起座离席。\n"
		
		]),



		});
static mapping *dali_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好。”\n",
		"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有人杀我大理段家弟子，你速去将其除去。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),
		([
		"job_tell_mode":"assess",		
		"prompt":HIY"段王爷已经传下旨意，令大理段家之人速回王府大殿，召开王府大会。\n"NOR,
		"send_to" : "各位大理段家的英雄请了！",
		"send_to1":	"为评定各位近日的所作所为，将于三日后于大理王府大殿召开王府大会，请大家务必出席。",
		"kick_out": "$N说道：“现在我大理段家正在进行重要的会议，请闲杂人等离开此处。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“大理段家虽在南疆为君，不过支出中原武林，须保持先人遗训，行侠仗义，维护武林。”\n",
		"assess_start":"$N说道：“现在开始王府大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为大理做贡献最大，现传授你大理段家武学精要，望你能再接再厉。”\n",
		"assess_punish":"$N说道：“$P，你数次违我旨意，该受严惩！”\n",
		"assess_award_common":"$N说道：“希望各位能行侠仗义，造福武林。”\n",
		"assess_end":"$N说道：“这次王府大会到此结束！”。说罢起座离席。\n"
		
		]),



		});
static mapping *shaolin_message = ({
	([
		"job_tell_mode":"传话",
		"time_noover" : "$N对$n点了点头,说道：“$P，你来的正好，老纳正有事找你。”\n",
		"time_over" : "$N对$n皱了皱眉，说道：“$P，你怎么此时才到？我本有重要任务让你去做，却被你延误时机。\n"
						"下次要再如此，必当重罚。”\n"
		]),
	([
		"job_tell_mode":"oppose_pker",
		"pk_npc" : "$N说道:“近日在$ROOM附近有强盗出没，你速去将其除去，为民除害。”\n"
		]),
	([
		"job_tell_mode":"protect",
		"npc" : "$N说道:“近来江湖动乱，常有无辜百姓被邪派妖人所杀，搞得江湖人心惶惶。\n"
				"刚才有人求上门来，向我武当寻求保护，我派你去$ROOM处等他，护送他去目的地。”\n"
		]),

	([
		"job_tell_mode":"award",
		"opposepk_award" : "$N说道:“辛苦你了，$P，你为本门立下了一功。”\n"
		]),

		([
		"job_tell_mode":"assess",		
		"prompt":HIY"方丈大师已经传下法旨，招少林弟子速回少林寺，在大雄宝殿召开少林大会。\n"NOR,
		"send_to" : "阿弥陀佛！！",
		"send_to1":	"请少林弟子速回少林寺，三日后于大雄宝殿召开少林大会。",
		"kick_out": "$N说道：“现在我少林派正在进行少林大会，请闲杂人等离开此处。”\n",
		"kick_out_player": "$N将$n请了出去。\n",
		"family":"$N说道：“自达摩祖师开创少林，我少林时刻已宣扬佛法，普渡众生为己任，整救世人于苦难之中。”\n",
		"assess_start":"$N说道：“阿弥陀佛！现在开始少林大会。”\n",
		"assess_award_best":"$N说道：“$P，近段时间内，你为维护武林正义所做贡献不小，本座传授你少林武学精要，望你能将少林发扬光大。”\n",
		"assess_punish":"$N说道：“$P，你数次违我指令，该受本座严惩！”\n",
		"assess_award_common":"$N说道：“希望各位继续努力，时刻牢记佛法，普渡众生。”\n",
		"assess_end":"$N说道：“本次大会到此结束，阿弥陀佛！”。说罢起座离席。\n"
		]),
		});





