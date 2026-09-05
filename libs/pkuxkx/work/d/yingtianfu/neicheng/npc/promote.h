#include <ansi.h>
#include <title.h>
string get_major(string arg);
string classify_depart(object me);
string add_officer_in(object me,string depart_name);
int delete_officer(object me);
//各种title汇总
mapping *upper_title=({
        (["title":"保和殿大学士","owner":"","owner_name":"","pin":1,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xueshi1","department":1,]),
        (["title":"文华殿大学士","owner":"","owner_name":"","pin":1,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xueshi2","department":1,]),
        (["title":"武英殿大学士","owner":"","owner_name":"","pin":1,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xueshi3","department":1,]),
        (["title":"文渊阁大学士","owner":"","owner_name":"","pin":1,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xueshi4","department":1,]),
        (["title":"体仁阁大学士","owner":"","owner_name":"","pin":1,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xueshi5","department":1,]),
        (["title":"东阁大学士","owner":"","owner_name":"","pin":1,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xueshi6","department":1,]),
        (["title":"吏部尚书","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/li-shangshu","department":10,]),
        (["title":"兵部尚书","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/bing-shangshu","department":11,]),
        (["title":"刑部尚书","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xing-shangshu","department":12,]),
        (["title":"工部尚书","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/gong-shangshu","department":13,]),
        (["title":"户部尚书","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/hu-shangshu","department":14,]),
        (["title":"礼部尚书","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/li2-shangshu","department":15,]),
        (["title":"左都御史","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/zuodu","department":16,"assign":1,]),//
        (["title":"右都御史","owner":"","owner_name":"","pin":2,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/youdu","department":16,"assign":1,]),
        (["title":"吏部左侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/li-shilang","department":10,]),
        (["title":"吏部右侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/li-shilang2","department":10,]),
        (["title":"兵部左侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/bing-shilang","department":11,]),
        (["title":"兵部右侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/bing-shilang2","department":11,]),
        (["title":"刑部左侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xing-shilang","department":12,]),
        (["title":"刑部右侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xing-shilang2","department":12,]),
        (["title":"工部左侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/gong-shilang","department":13,]),
        (["title":"工部右侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/gong-shilang2","department":13,]),
        (["title":"户部左侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/hu-shilang","department":14,]),
        (["title":"户部右侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/hu-shilang2","department":14,]),
        (["title":"礼部左侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/li2-shilang","department":15,]),
        (["title":"礼部右侍郎","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/li2-shilang2","department":15,]),
        (["title":"左副都御史","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/zuofu","department":16,]),
        (["title":"右副都御史","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/youfu","department":16,]),
		(["title":"大理寺卿","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc1","department":12,]),
		(["title":"太常寺卿","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc3","department":15,]),//宗庙礼仪
		(["title":"詹士府詹士","owner":"","owner_name":"","pin":3,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/zhanshi","department":15,]),
        (["title":"五军都督府 大都督","owner":"","owner_name":"","pin":1,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/wujun-dadudu","department":2,"ying":0,"armys":0,]),
        (["title":"五军都督府 左都督","owner":"","owner_name":"","pin":1,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/wujun-zuodudu","department":2,"ying":0,"armys":0,]),
        (["title":"五军都督府 右都督","owner":"","owner_name":"","pin":1,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/wujun-yoududu","department":2,"ying":0,"armys":0,]),
        (["title":"五军都督府 都督同知","owner":"","owner_name":"","pin":1,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/wujun-dudu","department":2,"ying":0,"armys":0,]),
        (["title":"五军都督府 都督佥事","owner":"","owner_name":"","pin":2,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/jianshi","department":2,"ying":1,"armys":1,]),
        (["title":"三大营都指挥同知","owner":"","owner_name":"","pin":2,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/zhihui","department":21,"ying":2,"armys":2,]),
        (["title":"三大营都指挥使","owner":"","owner_name":"","pin":2,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/zhihuishi","department":21,"ying":2,"armys":2,]),
        (["title":"水师提督","owner":"","owner_name":"","pin":2,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/shui-du","department":22,"ying":5,"armys":5,]),
        (["title":"御前侍卫统领","owner":"","owner_name":"","pin":2,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/yuqian","department":23,]),
        (["title":"御林军统领","owner":"","owner_name":"","pin":2,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/yulin","department":25,"ying":4,"armys":4,]),
        (["title":"京卫指挥使司 指挥使","owner":"","owner_name":"","pin":3,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/j_zhihui","department":24,"ying":1,"armys":1,]),
        (["title":"京卫指挥使司 指挥同知","owner":"","owner_name":"","pin":3,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/j_tongzhi","department":24,"ying":1,"armys":1,]),
        (["title":"京卫指挥使司 指挥佥事","owner":"","owner_name":"","pin":3,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/j_lianshi","department":24,"ying":1,"armys":1,]),
        (["title":"一等侍卫","owner":"","owner_name":"","pin":3,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/1_shiwei","department":23,]),
        (["title":"御前带刀侍卫","owner":"","owner_name":"","pin":3,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/dao_shiwei","department":23,]),
		(["title":"锦衣卫指挥使","owner":"","owner_name":"","pin":3,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/jywei_zhihui","department":26,"assign":1,]),//*
    });
string * pre_wu_title_lower=({"腾骧左卫","腾骧右卫","武骧左卫","武骧右卫","金吾前卫","金吾后卫","羽林左卫","羽林右卫"});
mapping *lower_title=({
        (["title":"光禄寺卿","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc2","department":23,"vacacy":1]),//管理侍卫
        (["title":"太仆寺卿","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc4","department":11,"vacacy":1]),//管理马匹 ，兵部
        (["title":"鸿胪寺卿","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/honglusiqin","department":15,"vacacy":1]),
        (["title":"太医院使","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/taiyiyuanshi","department":13,"vacacy":1]),
        (["title":"翰林学士","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/hanlinxueshi","department":15,"vacacy":1]),
		(["title":"左佥都御史","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/zuolian","department":16,"vacacy":1]),//*
        (["title":"右佥都御史","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/youlian","department":16,"vacacy":1]),//*
		(["title":"大理寺少卿","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc1_s","department":12,"vacacy":1]),//*
		(["title":"太常寺少卿","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc3_s","department":15,"vacacy":1]),//*
		(["title":"詹士府少詹士","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/zhanshi_s","department":15,"vacacy":2]),//*
		(["title":"国子监祭酒","pin":4,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/jijiu","department":15,"vacacy":1]),//*
		(["title":"卫指挥使","pin":4,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_wei_2","department":21,"vacacy":8,"pre_title":1]),//*
		(["title":"王府侍卫统领","pin":4,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_wei_3","department":27,"vacacy":8,]),//*
		(["title":"锦衣卫南镇抚使","pin":4,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/jy_npc_wei_1","department":26,"vacacy":1,]),//*
		(["title":"锦衣卫北镇抚使","pin":4,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/jy_npc_wei_2","department":26,"vacacy":1,]),//*
        (["title":"翰林侍读学士","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc5","department":15,"vacacy":2]),
        (["title":"翰林侍讲学士","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc6","department":15,"vacacy":2]),
        (["title":"翰林院 侍读","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc7","department":15,"vacacy":2]),
        (["title":"翰林院 侍讲","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc8","department":15,"vacacy":2]),
        (["title":"翰林院 修编","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc9","department":15,"vacacy":2]),
        (["title":"翰林院 检讨","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc10","department":15,"vacacy":2]),
		(["title":"大理寺丞","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc_dali_1","department":15,"vacacy":2]),//*
		(["title":"尚宝司卿","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc_shaobao_1","department":15,"vacacy":2]),//*
		(["title":"光禄寺少卿","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npc_guanglu_1","department":23,"vacacy":2]),//*
		(["title":"吏部郎中","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcaa","department":10,"vacacy":3]),//*
        (["title":"兵部郎中","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcba","department":11,"vacacy":3]),//*
        (["title":"刑部郎中","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcca","department":12,"vacacy":3]),//*
        (["title":"工部郎中","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcda","department":13,"vacacy":3]),//*
        (["title":"户部郎中","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcea","department":14,"vacacy":3]),//*
        (["title":"礼部郎中","pin":5,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcfa","department":15,"vacacy":3]),//*
		(["title":"五军都督府经历","pin":5,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_dudu","department":2,"vacacy":12]),//*
		(["title":"卫指挥佥事","pin":5,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_wei_3","department":21,"vacacy":10,"pre_title":1]),//*
        (["title":"吏部主事","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npca","department":10,"vacacy":4]),
        (["title":"兵部主事","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcb","department":11,"vacacy":4]),
        (["title":"刑部主事","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcc","department":12,"vacacy":4]),
        (["title":"工部主事","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcd","department":13,"vacacy":4]),
        (["title":"户部主事","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npce","department":14,"vacacy":4]),
        (["title":"礼部主事","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcf","department":15,"vacacy":4]),
        (["title":"都察院经历","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcg","department":16,"vacacy":3]),
        (["title":"大理寺寺正","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcy","department":12,"vacacy":2]),
        (["title":"詹事府丞","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcz1","department":15,"vacacy":3]),
        (["title":"詹事府善赞","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcz2","department":15,"vacacy":3]),
        (["title":"詹事府司直郎","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcz3","department":15,"vacacy":6]),
        (["title":"钦天监主簿","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcx","department":15,"vacacy":2]),
        (["title":"太医院判","pin":6,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/taiyi-yuanpan","department":13,"vacacy":2]),
        (["title":"五城兵马指挥","pin":6,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npcz","department":11,"vacacy":2]),
		(["title":"三大营都指挥使司经历","pin":6,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_dudu2","department":21,"vacacy":16]),//*
		(["title":"卫所镇抚","pin":6,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_wei_31","department":21,"vacacy":16,"pre_title":1]),//*
		(["title":"吏科都给事中","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcaaa","department":10,"vacacy":1]),//*
        (["title":"兵科都给事中","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcbaa","department":11,"vacacy":1]),//*
        (["title":"刑科都给事中","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npccaa","department":12,"vacacy":1]),//*
        (["title":"工科都给事中","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcdaa","department":13,"vacacy":1]),//*
        (["title":"户科都给事中","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npceaa","department":14,"vacacy":1]),//*
        (["title":"礼科都给事中","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/daming_npcfaa","department":15,"vacacy":1]),//*
		(["title":"监察御史","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/jian_yushi","department":16,"vacacy":12]),//*
		(["title":"大理寺评事","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/dali_pingshi","department":12,"vacacy":4]),//*
		(["title":"行人司正","pin":7,"pro":"文","npc":"/d/yingtianfu/neicheng/npc/xingren_z","department":15,"vacacy":1]),//*
		(["title":"安抚司佥事","pin":7,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/anfu_lianshi","department":2,"vacacy":20,"pre_title":1]),//*
		(["title":"总旗","pin":7,"pro":"武","npc":"/d/yingtianfu/neicheng/npc/daming_npc_wei_32","department":21,"vacacy":16,"pre_title":1]),//*
    });
 mapping *lowest_title=({
		(["title":"国子监丞","pin":8,"pro":"文","department":15]),//*
		(["title":"行人司行人","pin":8,"pro":"文","department":15]),//*
		(["title":"部院照磨","pin":8,"pro":"文","department":10+random(6)]),//*
		(["title":"五经博士","pin":8,"pro":"文","department":15]),//*
		(["title":"御医","pin":8,"pro":"文","department":13]),//*
		(["title":"协律郎","pin":8,"pro":"文","department":11]),//*
		(["title":"翰林典籍","pin":8,"pro":"文","department":15]),//*
		(["title":"博士","pin":8,"pro":"文","department":15]),//*
		(["title":"国子监助教","pin":8,"pro":"文","department":15]),//*
		(["title":"国子学正","pin":9,"pro":"文","department":15]),//*
		(["title":"上林苑典署","pin":9,"pro":"文","department":10+random(6)]),//*
		(["title":"鸿胪寺署丞","pin":9,"pro":"文","department":15]),//*
		(["title":"赞礼郎","pin":9,"pro":"文","department":10+random(6)]),//*
		(["title":"待诏","pin":9,"pro":"文","department":10+random(6)]),//*
		(["title":"通事舍人","pin":9,"pro":"文","department":10+random(6)]),//*
		(["title":"国子学录","pin":9,"pro":"文","department":15]),//*
		(["title":"国子典籍","pin":9,"pro":"文","department":15]),//*
		(["title":"鸣赞序班","pin":9,"pro":"文","department":15]),//*
    });
mapping *sanjie_title=({
			(["title":"特进光禄大夫","pin":1,"is_major":1,"major_entry":0,"period":3600*24*30,"credit":600,"pro":"文","rank":1]),
			(["title":"特进荣禄大夫","pin":1,"is_major":1,"major_entry":0,"period":3600*24*18,"credit":480,"pro":"文","rank":2]),
			(["title":"光禄大夫","pin":1,"is_major":0,"major_entry":1,"period":3600*24*16,"credit":600,"pro":"文","rank":3]),
			(["title":"荣禄大夫","pin":1,"is_major":0,"major_entry":0,"period":3600*24*15,"credit":480,"pro":"文","rank":4,"preliminary":1]),
			(["title":"特进光禄大夫","pin":1,"is_major":1,"major_entry":0,"period":3600*24*30,"credit":600,"pro":"武","rank":1]),
			(["title":"特进荣禄大夫","pin":1,"is_major":1,"major_entry":0,"period":3600*24*18,"credit":480,"pro":"武","rank":2]),
			(["title":"光禄大夫","pin":1,"is_major":0,"major_entry":1,"period":3600*24*16,"credit":600,"pro":"武","rank":3]),
			(["title":"荣禄大夫","pin":1,"is_major":0,"major_entry":0,"period":3600*24*15,"credit":480,"pro":"武","rank":4,"preliminary":1]),
			(["title":"资德大夫","pin":2,"is_major":1,"major_entry":0,"period":3600*24*15,"credit":100,"pro":"文","can_promote":1,"rank":5]),
			(["title":"资政大夫","pin":2,"is_major":1,"major_entry":0,"period":3600*24*10,"credit":0,"pro":"文","can_promote":1,"rank":6]),
			(["title":"资善大夫","pin":2,"is_major":1,"major_entry":0,"period":3600*24*8,"credit":0,"pro":"文","rank":7]),
			(["title":"正奉大夫","pin":2,"is_major":0,"major_entry":1,"period":3600*24*8,"credit":0,"pro":"文","rank":8]),
			(["title":"通奉大夫","pin":2,"is_major":0,"major_entry":0,"period":3600*24*6,"credit":0,"pro":"文","rank":9]),
			(["title":"中奉大夫","pin":2,"is_major":0,"major_entry":0,"period":3600*24*5,"credit":0,"pro":"文","rank":10,"preliminary":1]),
			(["title":"龙虎将军","pin":2,"is_major":1,"major_entry":0,"period":3600*24*15,"credit":100,"pro":"武","can_promote":1,"rank":5]),
			(["title":"金吾将军","pin":2,"is_major":1,"major_entry":0,"period":3600*24*10,"credit":0,"pro":"武","can_promote":1,"rank":6]),
			(["title":"骠骑将军","pin":2,"is_major":1,"major_entry":0,"period":3600*24*8,"credit":0,"pro":"武","rank":7]),
			(["title":"奉国将军","pin":2,"is_major":0,"major_entry":1,"period":3600*24*8,"credit":0,"pro":"武","rank":8]),
			(["title":"定国将军","pin":2,"is_major":0,"major_entry":0,"period":3600*24*6,"credit":0,"pro":"武","rank":9]),
			(["title":"镇国将军","pin":2,"is_major":0,"major_entry":0,"period":3600*24*5,"credit":0,"pro":"武","rank":10,"preliminary":1]),
			(["title":"正议大夫","pin":3,"is_major":1,"major_entry":0,"period":3600*24*5,"credit":0,"pro":"文","can_promote":1,"rank":11]),
			(["title":"通议大夫","pin":3,"is_major":1,"major_entry":0,"period":3600*24*4,"credit":0,"pro":"文","can_promote":1,"rank":12]),
			(["title":"嘉议大夫","pin":3,"is_major":1,"major_entry":0,"period":3600*24*4,"credit":0,"pro":"文","rank":13]),
			(["title":"大中大夫","pin":3,"is_major":0,"major_entry":1,"period":3600*24*4,"credit":0,"pro":"文","rank":14]),
			(["title":"中大夫","pin":3,"is_major":0,"major_entry":0,"period":3600*24*3,"credit":0,"pro":"文","rank":15]),
			(["title":"亚中大夫","pin":3,"is_major":0,"major_entry":0,"period":3600*24*3,"credit":0,"pro":"文","rank":16,"preliminary":1]),
			(["title":"昭武将军","pin":3,"is_major":1,"major_entry":0,"period":3600*24*5,"credit":0,"pro":"武","can_promote":1,"rank":11]),
			(["title":"昭毅将军","pin":3,"is_major":1,"major_entry":0,"period":3600*24*4,"credit":0,"pro":"武","can_promote":1,"rank":12]),
			(["title":"昭勇将军","pin":3,"is_major":1,"major_entry":0,"period":3600*24*4,"credit":0,"pro":"武","rank":13]),
			(["title":"安远将军","pin":3,"is_major":0,"major_entry":1,"period":3600*24*4,"credit":0,"pro":"武","rank":14]),
			(["title":"定远将军","pin":3,"is_major":0,"major_entry":0,"period":3600*24*3,"credit":0,"pro":"武","rank":15]),
			(["title":"怀远将军","pin":3,"is_major":0,"major_entry":0,"period":3600*24*3,"credit":0,"pro":"武","rank":16,"preliminary":1]),
			(["title":"中议大夫","pin":4,"is_major":1,"major_entry":0,"period":3600*24*3,"credit":0,"pro":"文","can_promote":1,"rank":17]),
			(["title":"中宪大夫","pin":4,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","can_promote":1,"rank":18]),
			(["title":"中顺大夫","pin":4,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","rank":19]),
			(["title":"朝请大夫","pin":4,"is_major":0,"major_entry":1,"period":3600*24*2,"credit":0,"pro":"文","rank":20]),
			(["title":"朝议大夫","pin":4,"is_major":0,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","rank":21]),
			(["title":"朝列大夫","pin":4,"is_major":0,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","rank":22,"preliminary":1]),
			(["title":"广威将军","pin":4,"is_major":1,"major_entry":0,"period":3600*24*3,"credit":0,"pro":"武","can_promote":1,"rank":17]),
			(["title":"宣威将军","pin":4,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","can_promote":1,"rank":18]),
			(["title":"明威将军","pin":4,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","rank":19]),
			(["title":"信武将军","pin":4,"is_major":0,"major_entry":1,"period":3600*24*2,"credit":0,"pro":"武","rank":20]),
			(["title":"显武将军","pin":4,"is_major":0,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","rank":21]),
			(["title":"宣武将军","pin":4,"is_major":0,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","rank":22,"preliminary":1]),
			(["title":"奉政大夫","pin":5,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","can_promote":1,"rank":23]),
			(["title":"奉议大夫","pin":5,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","rank":24]),
			(["title":"奉直大夫","pin":5,"is_major":0,"major_entry":1,"period":3600*24*2,"credit":0,"pro":"文","rank":25]),
			(["title":"奉训大夫","pin":5,"is_major":0,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","rank":26,"preliminary":1]),
			(["title":"武节将军","pin":5,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","can_promote":1,"rank":23]),
			(["title":"武德将军","pin":5,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","rank":24]),
			(["title":"武毅将军","pin":5,"is_major":0,"major_entry":1,"period":3600*24*2,"credit":0,"pro":"武","rank":25]),
			(["title":"武略将军","pin":5,"is_major":0,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","rank":26,"preliminary":1]),
			(["title":"承德郎","pin":6,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","can_promote":1,"rank":27]),
			(["title":"承直郎","pin":6,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"文","rank":28]),
			(["title":"宣德郎","pin":6,"is_major":0,"major_entry":1,"period":3600*24*1,"credit":0,"pro":"文","rank":29]),
			(["title":"儒林郎","pin":6,"is_major":0,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":30]),
			(["title":"承务郎","pin":6,"is_major":0,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":31,"preliminary":1]),
			(["title":"承信校尉","pin":6,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","can_promote":1,"rank":27]),
			(["title":"昭信校尉","pin":6,"is_major":1,"major_entry":0,"period":3600*24*2,"credit":0,"pro":"武","rank":28]),
			(["title":"忠武校尉","pin":6,"is_major":0,"major_entry":1,"period":3600*24*1,"credit":0,"pro":"武","rank":29]),
			(["title":"忠显校尉","pin":6,"is_major":0,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"武","rank":30,"preliminary":1]),
			(["title":"宣议郎","pin":7,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","can_promote":1,"rank":32]),
			(["title":"文林郎","pin":7,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":33]),
			(["title":"承事郎","pin":7,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":34]),
			(["title":"征仕郎","pin":7,"is_major":0,"major_entry":1,"period":3600*24*1,"credit":0,"pro":"文","rank":35]),
			(["title":"从仕郎","pin":7,"is_major":0,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":36,"preliminary":1]),
			(["title":"承信校尉","pin":7,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"武","can_promote":1,"rank":31]),
			(["title":"昭信校尉","pin":7,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"武","rank":32]),
			(["title":"忠武校尉","pin":7,"is_major":0,"major_entry":1,"period":3600*24*1,"credit":0,"pro":"武","rank":33]),
			(["title":"忠显校尉","pin":7,"is_major":0,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"武","rank":34,"preliminary":1]),
			(["title":"修职郎","pin":8,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","can_promote":1,"rank":37]),
			(["title":"迪功郎","pin":8,"is_major":1,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":38]),
			(["title":"修职佐郎","pin":8,"is_major":0,"major_entry":1,"period":3600*24*1,"credit":0,"pro":"文","rank":39]),
			(["title":"迪功佐郎","pin":8,"is_major":0,"major_entry":0,"period":3600*24*1,"credit":0,"pro":"文","rank":40,"preliminary":1]),
			(["title":"登仕郎","pin":9,"is_major":1,"major_entry":0,"period":3600*12,"credit":0,"pro":"文","can_promote":1,"rank":41]),
			(["title":"将仕郎","pin":9,"is_major":1,"major_entry":0,"period":3600*12,"credit":0,"pro":"文","rank":42]),
			(["title":"登仕佐郎","pin":9,"is_major":0,"major_entry":1,"period":3600*12,"credit":0,"pro":"文","rank":43]),
			(["title":"将仕佐郎","pin":9,"is_major":0,"major_entry":0,"period":3600*12,"credit":0,"pro":"文","rank":44,"preliminary":1]),
	});
//辅助
object *ming_all()
{
	object *ob;
	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	ob = filter_array(ob, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
	return ob;
} 
//散阶相关
string set_me_duty(object me)
{
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (me->query("mingpin")==sanjie_title[i]["pin"]&&me->query("ming/pro")==sanjie_title[i]["pro"]&&sanjie_title[i]["preliminary"]==1)
		return sanjie_title[i]["title"];
	}
	return "";
}
string major(int is_major)
{
	if (is_major)
	return "正";
	else
	return "从";
}
int reset_me_duty(object me)
{
	string title;
	if (!me->get_title(TITLE_MING2))
	{
		
	}
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (me->query("mingpin")==sanjie_title[i]["pin"]&&me->query("ming/pro")==sanjie_title[i]["pro"]&&major(sanjie_title[i]["is_major"])==get_major(me->get_title(TITLE_MING2)))
		title=sanjie_title[i]["title"];
	}
	me->set_title(TITLE_MING2,title);
	return 1;
}
int get_duty_rank_no(object me)
{
	int rank=0;
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (sanjie_title[i]["title"]==me->get_title(TITLE_MING2)&&me->query("ming/pro")==sanjie_title[i]["pro"])
		rank=sanjie_title[i]["rank"];
		break;
	}
	if (me->query("ming/pro")=="武"&&me->query("mingpin")==7)
	rank+=4;
	if (!rank)
	rank=44;
	return rank;
}
string promote_me_duty(object me)
{
	int i,rank=0;
	mapping title,new_title;
	for (i=0;i<sizeof(sanjie_title);i++)
	{
		if (sanjie_title[i]["title"]==me->get_title(TITLE_MING2)&&sanjie_title[i]["pro"]==me->query("ming/pro")&&sanjie_title[i]["pin"]==me->query("mingpin"))
		{
			rank=sanjie_title[i]["rank"];
			title=sanjie_title[i];
			if (rank==1)
			return "";
			if (!rank)
			return set_me_duty(me);
		}
	}
	for (i=0;i<sizeof(sanjie_title);i++)
	{
		if (sanjie_title[i]["rank"]==rank-1&&sanjie_title[i]["pro"]==me->query("ming/pro")&&sanjie_title[i]["pin"]==me->query("mingpin"))
		{
			new_title=sanjie_title[i];
			if (me->query("ming/credit")-me->query("ming/duty_promote/credit")>title["credit"]&&me->query("mud_age")-me->query("ming/duty_promote/promote_time")>title["period"]&&title["can_promote"]!=1)
			{
				me->set("ming/duty_rank",new_title["rank"]);
				return new_title["title"];
			}
		}
	}
	return "";
}
string get_major(string arg)
{
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (sanjie_title[i]["title"]==arg)
		{
			if (sanjie_title[i]["is_major"])
			return "正";
			else
			return "从";
		}
	}
	return "";
}
int can_promote(object me)
{
	string duty=me->get_title(TITLE_MING2);
	if (!duty)
	return 0;
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (sanjie_title[i]["title"]==duty&&sanjie_title[i]["pro"]==me->query("ming/pro")&&sanjie_title[i]["pin"]==me->query("mingpin")&&sanjie_title[i]["can_promote"])
		return 1;
	}
	return 0;
}
//部门相关
int get_my_depart(object me)
{
    mapping *titles;
    int i,pin=me->query("mingpin");
    string title=me->query("ming/title");
    if (!pin||!title)
    return 0;
    if (pin>3)
    {
		if (pin>7)
		titles=lowest_title;
		else
        titles=lower_title;
    }
    else
    titles=upper_title;
    for (i=0;i<sizeof(titles);i++)
    {
        if (title==titles[i]["title"])
        return titles[i]["department"];
    }
    return 0;
}
string retro_classify_depart(string arg)
{
    if (arg=="depart_neige")
	return "内阁";
    if (arg=="depart_dudufu")
	return "五军都督府";
    if (arg=="depart_libu")
	return "吏部";
    if (arg=="depart_bingbu")
	return "兵部";
    if (arg=="depart_xingbu")
	return "刑部";
    if (arg=="depart_gongbu")
	return "工部";
    if (arg=="depart_hubu")
	return "户部";
    if (arg=="depart_libu2")
	return "礼部";
    if (arg=="depart_duchayuan")
	return "都察院";
    if (arg=="depart_zhihui")
	return "都指挥司";
    if (arg=="depart_shuishi")
	return "水师";
    if (arg=="depart_shiweichu")
	return "侍卫处";
    if (arg=="depart_jingying")
	return "京营";
    if (arg=="depart_yulinjun")
	return "御林军";
    return "NULL";
}
string classify_depart(object me)
{
    if (me->query("ming/depart")==1)
    {
        me->set("ming/depart_name","内阁");
        return "depart_neige";
    }
    if (me->query("ming/depart")==2)
    {
        me->set("ming/depart_name","五军都督府");
        return "depart_dudufu";
    }
    if (me->query("ming/depart")==10)
    {
        me->set("ming/depart_name","吏部");
        return "depart_libu";
    }
    if (me->query("ming/depart")==11)
    {
        me->set("ming/depart_name","兵部");
        return "depart_bingbu";
    }
    if (me->query("ming/depart")==12)
    {
        me->set("ming/depart_name","刑部");
        return "depart_xingbu";
    }
    if (me->query("ming/depart")==13)
    {
        me->set("ming/depart_name","工部");
        return "depart_gongbu";
    }
    if (me->query("ming/depart")==14)
    {
        me->set("ming/depart_name","户部");
        return "depart_hubu";
    }
    if (me->query("ming/depart")==15)
    {
        me->set("ming/depart_name","礼部");
        return "depart_libu2";
    }
    if (me->query("ming/depart")==16)
    {
        me->set("ming/depart_name","都察院");
        return "depart_duchayuan";
    }
    if (me->query("ming/depart")==21)
    {
        me->set("ming/depart_name","都指挥司");
        return "depart_zhihui";
    }
    if (me->query("ming/depart")==22)
    {
        me->set("ming/depart_name","水师");
        return "depart_shuishi";
    }
    if (me->query("ming/depart")==23)
    {
        me->set("ming/depart_name","侍卫处");
        return "depart_shiweichu";
    }
    if (me->query("ming/depart")==24)
    {
        me->set("ming/depart_name","京营");
        return "depart_jingying";
    }
    if (me->query("ming/depart")==25)
    {
        me->set("ming/depart_name","御林军");
        return "depart_yulinjun";
    }
    return "NULL";
}
string add_officer_in(object me,string depart_name)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i,flag=0;
    string save_path,old_depart,*departs=({"depart_neige","depart_dudufu","depart_libu","depart_bingbu","depart_xingbu","depart_gongbu","depart_hubu","depart_libu2","depart_duchayuan","depart_zhihui","depart_shuishi","depart_shiweichu","depart_jingying","depart_yulinjun",});
    if (!me)
    return "调动哪位官员？\n";  
    if (!depart_name)
	return "调动官员到哪个部门？\n";
    if (member_array(depart_name,departs)==-1)
	return "没有这个部门。\n";
    ob->restore();
    for (i=100;i<301;i++) 
    {
        if (ob->query(depart_name+"/officers/"+i+"/id")==me->query("id"))
		return depart_name+"已有此官员记录。\n";
    }
    if (me->query("ming/depart"))
	old_depart=classify_depart(me);
    if (me->query("ming/depart_name_serial"))
	old_depart=me->query("ming/depart_name_serial");
    for (i=100;i<301;i++) 
    {
        if (ob->query(old_depart+"/officers/"+i+"/id")==me->query("id"))
        {
            ob->delete(old_depart+"/officers/"+i);
            ob->save();
        }
    }
    for (i=100;i<301;i++)
    {
        save_path=depart_name+"/"+"officers/";
        if (!ob->query(save_path+i))
        {
            if (!userp(me))
			me->save_npc(save_path,i);
            else
            {
                ob->set(save_path+i+"/name",me->query("name"));
                ob->set(save_path+i+"/id",me->query("id"));
                ob->set(save_path+i+"/tongyu",me->query("ming/ability/tongyu"));
                ob->set(save_path+i+"/zhengwu",me->query("ming/ability/zhengwu"));
                ob->set(save_path+i+"/lianbing",me->query("ming/ability/lianbing"));
                ob->set(save_path+i+"/renji",me->query("ming/ability/renji"));
                ob->set(save_path+i+"/zhihui",me->query("ming/ability/zhihui"));
                ob->set(save_path+i+"/qinmian",me->query("ming/ability/qinmian"));
                ob->save();
            }
            me->set("ming/depart_name_serial",depart_name);
            flag=1;
            return "添加官员记录成功。\n";
        }
    }
    if (flag==1)
	return "添加官员记录成功。\n";
    else
	return "添加官员失败，可能原因：人员超编。\n";
}
int delete_officer(object me)//非正常情况去除，玩家辞官,npc死亡。
{
    string old_depart;
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i;
    mapping *give_titles;
	if (!me)
	return 0;
    if (me->query("ming/depart"))
	old_depart=classify_depart(me);
    if (me->query("ming/depart_name_serial"))
	old_depart=me->query("ming/depart_name_serial");
    ob->restore();
	if (ob->query("give_titles"))
	give_titles=ob->query("give_titles");
	for (i=0;i<sizeof(give_titles);i++)
	{
		if (give_titles[i]["owner"]==me->query("id"))
		{
			give_titles[i]["owner"]="";
			give_titles[i]["owner_name"]="";
		}
	}
	ob->set("give_titles",give_titles);
    for (i=100;i<301;i++) 
    {
        if (ob->query(old_depart+"/officers/"+i+"/id")==me->query("id"))
        {
            ob->delete(old_depart+"/officers/"+i);
            ob->save();
        }
    }
	ob->save();
    return 1;
}
//身份识别
int identification(object me,string title)
{
    mapping* titles;
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    titles=ob->query("give_titles");
    if (!titles)
    return 0;
	if (me->query("ming/promote_from_depart_position")&&title==me->query("ming/promote_from_depart_position")&&me->query("mingpin")==1)
	return 1;
    for (int i=0;i<sizeof(titles);i++)
    {
        if (titles[i]["title"]==title&&titles[i]["owner"]==me->query("id"))
		return 1;
    }
    return 0;
}
int identifications(object me,string * all_titles)
{
	string title;
    mapping* titles;
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    titles=ob->query("give_titles");
    if (!titles)
    return 0;
    for (int i=0;i<sizeof(titles);i++)
    {
        if (titles[i]["owner"]==me->query("id"))
        {
            title=titles[i]["title"];
			if (member_array(title,all_titles)!=-1)
			return 1;
        }
    }
	if (me->query("ming/promote_from_depart_position")&&me->query("mingpin")==1)
	{
		title=me->query("ming/promote_from_depart_position");
		if (member_array(title,all_titles)!=-1)
		return 1;
	}
    return 0;
}
//升官相关
string ming_title(object me)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    mapping *give_outs,*titles=({}),*suit_titles=({}),give_title;
    int i,pin=(int)me->query("mingpin")-1,depart=me->query("ming/depart");
    string title,pro=me->query("ming/pro");
    if (me->query_temp("ming/hor_promote"))
    pin=pin+1;
    if (!pin||!pro)
    return "";
    ob->restore();
	me->set("mingpin",pin);
	if (pin<4)
	{
		if (ob->query("give_titles"))
		give_outs=ob->query("give_titles");
		else
		give_outs=upper_title;
		for (i=0;i<sizeof(give_outs);i++)
		{
			if (give_outs[i]["pin"]==pin&&give_outs[i]["pro"]==pro&&give_outs[i]["owner"]=="")
			titles+=({give_outs[i]});
			if (give_outs[i]["pin"]==pin&&give_outs[i]["pro"]==pro&&give_outs[i]["owner"]==""&&give_outs[i]["department"]==me->query("ming/depart"))
			suit_titles+=({give_outs[i]});
		}
		if (!sizeof(titles))//分配失败
		return "";
		else
		{
			if (me->query_temp("ming/hor_promote")==3)
			{
				title=me->query_temp("ming/hor_promote_title");
				me->set("ming/depart",me->query_temp("ming/hor_promote_depart"));
			}
			else
			{
				if (sizeof(suit_titles))
				{
					give_title=suit_titles[random(sizeof(suit_titles))];
					title=give_title["title"];
				}
				else
				{
					give_title=titles[random(sizeof(titles))];
					title=give_title["title"];
				}
				me->set("ming/depart",give_title["department"]);
			}
			for (i=0;i<sizeof(give_outs);i++)
			{
				if (give_outs[i]["title"]==title)
				{
					give_outs[i]["owner"]=me->query("id");
					give_outs[i]["owner_name"]=me->query("name");
				}
				if (give_outs[i]["title"]!=title&&give_outs[i]["owner"]==me->query("id"))
				{
					give_outs[i]["owner"]="";
					give_outs[i]["owner_name"]="";
				}
			}
			ob->set("give_titles",give_outs);
			ob->save();
			DAMING_D->reset_positions();
			return title;
		}
	}
	else if (pin<=7)
	{
		if (ob->query("give_mediate_titles"))
		give_outs=ob->query("give_mediate_titles");
		else
		give_outs=lower_title;
		for (i=0;i<sizeof(give_outs);i++)
		{
			if (give_outs[i]["pin"]==pin&&give_outs[i]["pro"]==pro&&give_outs[i]["vacacy"]>0)
			titles+=({give_outs[i]});
			if (give_outs[i]["pin"]==pin&&give_outs[i]["pro"]==pro&&give_outs[i]["vacacy"]>0&&give_outs[i]["department"]==me->query("ming/depart"))
			suit_titles+=({give_outs[i]});
		}
		if (!sizeof(titles))//分配失败
		return "";
		else
		{
			if (sizeof(suit_titles))
			{
				give_title=suit_titles[random(sizeof(suit_titles))];
				title=give_title["title"];
			}
			else
			{
				give_title=titles[random(sizeof(titles))];
				title=give_title["title"];
			}
			me->set("ming/depart",give_title["department"]);
			if (give_title["pre_title"]==1)
			title=pre_wu_title_lower[random(sizeof(pre_wu_title_lower))]+title;
			for (i=0;i<sizeof(give_outs);i++)
			{
				if (give_outs[i]==give_title)
				give_outs[i]["vacacy"]-=1;
				if (strsrch(me->query("ming/title"),give_outs[i]["title"])!=-1)
				give_outs[i]["vacacy"]+=1;
			}
			ob->set("give_mediate_titles",give_outs);
			ob->save();
			return title;
		}
	}
	else
	{
		give_outs=lowest_title;
		for (i=0;i<sizeof(give_outs);i++)
		{
			if (give_outs[i]["pin"]==pin&&give_outs[i]["pro"]==pro)
			titles+=({give_outs[i]});
			if (give_outs[i]["pin"]==pin&&give_outs[i]["pro"]==pro&&give_outs[i]["department"]==me->query("ming/depart"))
			suit_titles+=({give_outs[i]});
		}
		if (!sizeof(titles))//分配失败
		return "";
		else
		{
			if (sizeof(suit_titles))
			{
				give_title=suit_titles[random(sizeof(suit_titles))];
				title=give_title["title"];
			}
			else
			{
				give_title=titles[random(sizeof(titles))];
				title=give_title["title"];
			}
			me->set("ming/depart",give_title["department"]);
			title=give_title["title"];
			return title;
		}
	}
}

string extra_ming_title(object me)
{
    string* title1a=({"东南","西南","九边"});//+督师
    string* title_local=({"扬州","镇江","杭州","苏州","福州","泉州","南昌","岳阳","江州","成都","牙山"});
    string* title2a=({"山东","山西","河南","陕西","四川","江西","湖广","浙江","福建","广东","广西","云南","贵州"});//+总督
    string* title3a=({"山东","山西","河南","陕西","四川","江西","湖广","浙江","福建","广东","广西","云南","贵州"});//+巡抚
    string* title1b=({"三大营总管"});
    string* title2b=({"御林军副统领"});
    string* title3b=({"山东","山西","河南","陕西","四川","江西","湖广","浙江","福建","广东","广西","云南","贵州"});//+将军
    int i,pin=(int)me->query("mingpin")-1;
    string title,pro=me->query("ming/pro");
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    mapping *titles;
    if (me->query_temp("ming/hor_promote")||me->query("ming/suikao_longtime_not_in"))
    pin=pin+1;
    if (!pin||!pro)
    return "";
    ob->restore();
    if (ob->query("give_titles"))
	{
		titles=ob->query("give_titles");
		for (i=0;i<sizeof(titles);i++)
		{
			if (titles[i]["owner"]==me->query("id"))
			{
				titles[i]["owner"]="";
				titles[i]["owner_name"]="";
			}
		}
		ob->set("give_titles",titles);
		ob->save();
	}
    if (pro=="文")
    {
		if (pin==7)
        title=title_local[random(sizeof(title_local))]+"知县";
		if (pin==6)
        title=title_local[random(sizeof(title_local))]+"同知";
		if (pin==5)
        title=title_local[random(sizeof(title_local))]+"通判";
		if (pin==4)
		title=title_local[random(sizeof(title_local))]+"知府";
        if (pin==3)
		title=title_local[random(sizeof(title_local))]+"巡抚";
        if (pin==2)
		title=title_local[random(sizeof(title_local))]+"布政使";
        if (pin==1)
		title_local[random(sizeof(title_local))]+"督师";
        return title;
    }
    else if (pro=="武")
    {
		if (pin==7)
		title=title_local[random(sizeof(title_local))]+"兵马副指挥";
		if (pin==6)
		title=title_local[random(sizeof(title_local))]+"兵马指挥";
		if (pin==5)
		title=title_local[random(sizeof(title_local))]+"千户";
		if (pin==4)
		title=title_local[random(sizeof(title_local))]+"卫指挥佥事";
        if (pin==3)
		title=title_local[random(sizeof(title_local))]+"总兵";
        if (pin==2)
		title=title2b[random(sizeof(title2b))];
        if (pin==1)
		title=title1b[random(sizeof(title1b))];
        return title;
    }
    else
	return "";
}
int position_me(object me)
{
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string title,vice_title;
    string new_depart;
	object *ob;
    int pin=me->query("mingpin");
	if (me->query("ming/2to1")&&me->query("mingpin")==2&&!me->query_temp("ming/hor_promote"))
	{
		me->set("ming/promote_from_depart_position",me->query("ming/title"));
		message( "channel:" + "chat",HBBLU+HIW + "【大明】封天承运皇帝，诏曰：" +me->query("ming/title")+me->query("name")+HBBLU+HIW+"调入",users());
		if (me->query("ming/pro")=="武")
		message( "channel:" + "chat","五军都督府，开府仪同三司。钦此。\n"NOR,users());
		else
		message( "channel:" + "chat","内阁，开府仪同三司。钦此。\n"NOR,users());
	}
	if (!me->query("ming/pro"))
	{
		if (random(100)>49)
		me->set("ming/pro","武");
		else
		me->set("ming/pro","文");
	}
    title=ming_title(me);
    if (title==""||me->query("ming/suikao_longtime_not_in"))
    title=extra_ming_title(me);
    if (title=="")
    {
        tell_object(me,"暂时无法升官，我也不知道为什么！\n");
        return 1;
    }
	me->set("title",HIW+"大明 "+color[random(sizeof(color))]+title+NOR);
    me->set_title(TITLE_MING1,me->query("title"));
    me->set("ming/title",title);
	if (!me->query_temp("ming/hor_promote"))
	{
		vice_title=set_me_duty(me);
		if (vice_title!="")
		{
			me->set_title(TITLE_MING2,vice_title);
			tell_object(me,"成为从"+chinese_number(me->query("mingpin"))+"品官员后，你被初授"+vice_title+"的散阶。\n");
			me->set("ming/duty_promote/credit",me->query("ming/credit"));
			me->set("ming/duty_promote/promote_time",me->query("mud_age"));
		}
		else
		{
			me->set_title(TITLE_MING2);
		}
		tell_object(me,"恭喜"+me->query("name")+NOR+"大人，官至"+chinese_number(me->query("mingpin"))+"品"+title+"。\n"NOR);
		if (me->query("mingpin")!=1)
		{
			ob=ming_all();
			message( "channel:" + "chat",HIW + "【大明】吏部行文：" +me->query("name")+HIW+"即日调任"+title+"。\n"+NOR,ob);
		}
	}
    new_depart=classify_depart(me);
    add_officer_in(me,new_depart);
    if (me->query_temp("ming/hor_promote")==1)
    {
        me->delete_temp("ming/hor_promote");
        tell_object(me,"因为官位重叠，你被调任"+title+"。\n");
    }
    if (me->query_temp("ming/hor_promote")==2)
    {
        me->delete_temp("ming/hor_promote");
        tell_object(me,"你被上峰调任"+title+"。\n");
    }
	if (me->query_temp("ming/hor_promote")=="change_pro")
    {
		reset_me_duty(me);
        me->delete_temp("ming/hor_promote");
        tell_object(me,"你转职后，调任"+title+"。\n");
    }
    return 1;
}
int re_position(string arg)
{
	object me;
	if (!me=find_player(arg))
	return notify_fail("查无此人！\n");
	if (!me->query("mingpin"))
	return notify_fail("此人非大明官员！\n");
	return position_me(me);
}