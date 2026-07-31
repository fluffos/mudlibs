#include <ansi.h>
#include <localtime.h>
string *party_names = ({
	"新手盟","白驼山派","南海派","痴心妄想门","大理段家","峨嵋派","飞天御剑流","丐帮","姑苏慕容","古墓派","胡苗世家","恒山派","衡山派","红花会","华山派","浣花剑派","昆仑派","灵鹫宫","凌霄城","梅庄","明教","青城派","全真教","日月神教","杀手楼","神龙教","圣剑魔宫","蜀山派","嵩山派","泰山派","唐门","桃花岛","铁掌帮","通吃帮","五毒教","武当派","舞蝶仙","逍遥派","星宿派","玄天派","雪山寺","血刀门","血河派","移花宫","云龙门","少林派",
});
string *party_where = ({
	"/d/new/lgting1","/d/baituo/dating","/d/hainan/baiyunshan","/d/cxwxm/gc","/d/dali/duan2","/d/emei/dadian","/d/feitian/damen","/d/city/pomiao","/d/mr/dating","/d/gumu/gmht","/d/zhongzhou/miaojia_zhengting","/d/hengshan/baiyunan","/d/hen/hengyang","/d/honghua/damen","/d/huashan/square","/d/huanhua/dating","/d/kunlun/bwc","/d/lingjiu/damen","/d/lingxiao/dadian","/d/meizhuang/zoulang1","/d/mingjiao/shanmen","/d/qingcheng/shangqing","/d/quanzhen/sanqingdian","/d/heimuya/shimen","/d/shashou/qiandian","/d/shenlong/damen","/d/hangzhou/duanqiao","/d/shushan/tianshi","/d/songshan/qianting","/d/taishan/zhangren","/d/tangmen/liujiantang","/d/taohua/dating","/d/tiezhang/guangchang","/d/tongchi/tingyuan","/d/wudujiao/dating","/d/wudang/sanqingdian","/d/wudie/jm","/d/xiaoyao/qingcaop","/d/xingxiu/xxh2","/d/xuantian/door","/d/xueshan/dadian","/d/xuedao/sroad9","/d/xuehepai/xueku","/d/yihua/yihua_ge","/d/city2/dating","/d/shaolin/guangchang2",
});
string family_zhan()
{
	object me,ob,killer;
	object room;
	mixed *local;
	int j,k,num;
	
    me = this_player();
    ob = this_object();
	k = random(sizeof(party_names));
	local = localtime(time());
	
	if (me->query("family/family_name") != ob->query("family/family_name"))
		return ""+RANK_D->query_respect(me)+ "与本门毫无干系，何必参合本门事物。\n"NOR;
	if (me->query("family/master_id") != ob->query("id"))
		return ""+RANK_D->query_respect(me)+ "并非我的亲传弟子，这种门派大事岂能交给你。\n"NOR;
	if (me->query("family/master_name") != ob->query("name"))
		return ""+RANK_D->query_respect(me)+ "并非我的亲传弟子，这种门派大事岂能交给你。\n"NOR;
	if ( local[LT_MDAY] == (int)me->query("day_family_zhan_timecd"))	//每天
		return ""+RANK_D->query_respect(me)+ "想干什么，灭门之战每天只能进行一次。\n"NOR;
		
	for(j=0; j<=sizeof(party_names); j++)
	{
		if (me->query("family/family_name") == party_names[j]) num=j;
	}
	if (me->query("family/family_name") == party_names[k]) k = random(sizeof(party_names));
	if (me->query("family/family_name") == party_names[k]) k = random(sizeof(party_names));
	if (me->query("family/family_name") == party_names[k]) k = random(sizeof(party_names));
	if (me->query("family/family_name") == party_names[k]) k = random(sizeof(party_names));
	if (me->query("family/family_name") == party_names[k]) k = random(sizeof(party_names));

	if (me->query("family/family_name") != party_names[k])
	{
		message("channel:chat", HIR"\n【门派战争】"HIC+me->query("family/family_name")+" "+ob->query("name")+"：众弟子听令！\n"NOR, users());
		message("channel:chat", HIR"\n【门派战争】"HIC+me->query("family/family_name")+" "+ob->query("name")+"：顺我者生，逆我者亡！\n"NOR, users());
		message("channel:chat", HIR"\n【门派战争】"HIC+me->query("family/family_name")+" "+ob->query("name")+"："HIG+party_names[k]+HIC"与我派做对，这一次誓必要消灭"HIG+party_names[k]+HIC"！\n"NOR, users());
		me->set("day_family_zhan_timecd", local[LT_MDAY]);
		for(j=0; j<=5; j++)
		{
			killer=clone_object("/quest/haojie/jobnpc/"+num);
			killer->set_temp("family_kill",party_names[k]);
			if(!( room = find_object(party_where[k]) )) room = load_object(party_where[k]);
			killer->move(room);
			call_out("do_dest",600,killer);
		}
	}
	return "好！门派战争开始了。\n";
}

void do_dest(object killer)
{
	if ( !objectp(killer) ) return ;
	if (killer) 
	{
        message("channel:chat", HIC"\n【门派战争】"+killer->query_temp("family_kill")+"：哼，这次就先放你们一马，下次一定杀得你们鸡犬不留！"NOR"。\n", users());
        destruct(killer);
    }
	return ;
}
