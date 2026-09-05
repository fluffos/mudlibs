//quest_release.h
//超度任务，主要是任务分配
//seagate@pkuxkx 2010/10/17

#include <ansi.h>

//超度任务分配函数，注意超度任务本身都写入quest_release属性
//属性含义如下：
//promoter                    任务发起人
//start                       任务起始标志
//letter                      是否拿书信标志
//name                        任务目的地名称
//target                      任务目的地路径
//page                        做法事的时候翻开的书页
//success                     任务完成标志
string start_release(string name,string questid)
{
	object me,ob,gseng;
	string rname;
	mapping locate=([
		"洛阳金刀王府":"/d/luoyang/damen",
		"洛阳汝阳王府":"/d/ruyang-wangfu/wangfu-fumen",
		"北京鹿鼎公府":"/d/beijing/tingyuan",
		"北京鳌府":"/d/beijing/aobai2",
		"北京康亲王府":"/d/beijing/kangqin/door",
		"北京庄府":"/d/beijing/zhuang3",
		"襄阳郭府":"/d/xiangyang/keting",
		"扬州崔员外家":"/d/city/dayuan",
		"扬州正气山庄":"/d/city/damen",
		"苏州万景山庄":"/d/suzhou/wanjing",
		"苏州狮子林":"/d/suzhou/shizilin",
		"泉州巨鲸帮":"/d/quanzhou2/jujing-bang",
		"杭州马善钧家":"/d/hangzhou/damen",
		"杭州提督府":"/d/hangzhou/tidufu/tidufu",
		"华山村地保家":"/d/village/ehouse2",
		"日月神教农夫家":"/d/riyuejiao/xiaoyuan",
		"白驼山张记打铁铺":"/d/baituo/datiepu",
		"北疆小镇巴依家":"/d/xingxiu/house",
		"明教绿柳山庄":"/d/mingjiao/lvliu1",
		"灵州大将军府":"/d/lingzhou/jiangjungate",
		"大轮寺天云马场":"/d/dalunsi/tianyunmc",
		"大理平西王府":"/d/pingxiwangfu/wangfugate",
		"大理土司":"/d/dalicheng/tusi1",
		"长安小雁塔":"/d/changan/xiaoyanta",
		"长安大雁塔":"/d/changan/dayanta",
		"江州韩家":"/d/jiangzhou/dating",
		"南昌岳麓书院":"/d/nanchang/shuyuan2",
		"岳阳李保长家":"/d/yueyang/jia",
		"成都老唐家":"/d/chengdu/jia",
		"平西王府大门":"/d/pingxiwangfu/wangfugate",
		"晋阳萧府":"/d/jinyang/xiaofu"]);
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	rname=keys(locate)[random(1000)%sizeof(keys(locate))];
	me->set_temp("quest_release/promoter",this_object()->query("name"));
	me->set_temp("quest_release/letter",1);
	me->set_temp("quest_release/start",1);
	me->set_temp("quest_release/name",rname);
	me->set_temp("quest_release/target",locate[rname]);
	
	ob=new("/newbiequest/shaolin/obj/letter");
	gseng=new("/newbiequest/shaolin/npc/gao-seng");
	ob->set("owner",me->query("id"));
	gseng->move(locate[rname]);
	ob->move(me);
	command("say 这封书信收好，到时候和万安寺的高僧见面以这封书信为凭证！");
	this_object()->newbieDesc("帮洛阳万安寺的僧侣给"+HIG+rname+NOR+"举办一场法事。\n");
	return "洛阳万安寺最近人手有点紧张，请我寺僧人帮忙一起给"+HIG+rname+NOR+"举办一场法事，万安寺的高僧已经过去了，请"+me->query("name")+NOR"拿着这封信去见高僧。\n我们只是过去帮着，你跟着高僧念完一段经文就可以回来了。";
}

string fail_release()
{
	if(!mapp(this_player()->query_temp("quest_release")))
		return "你没有领超度任务。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_release");
	return "你连这点小事也干不好！\n";
}

string end_release(int reward)
{
	if(!mapp(this_player()->query_temp("quest_release")))
		return "你没有领超度任务。\n";
	else if(!this_player()->query_temp("quest_release/success"))
		return "你还没有去啊，万安塔的大师们差你一个就可以开始举办法事了！\n";

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_release");
	return "万安塔的大师回信给方丈了，对你的表现赞不绝口。\n";
}