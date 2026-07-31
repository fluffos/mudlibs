#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file,shimen;
	string str;
	object ob;
 
	if (! environment(me)) 
		return 0; 

	if (! arg )
		return help(me);
			     if (me->is_fighting())
			return notify_fail("当你想钻圈圈的时候，被啊三一脚踹了出来。\n");
	if (me->is_busy())
		return notify_fail("你正忙著呢。\n");

	if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
		
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢。\n");

	if (! me->query("born"))
		return notify_fail("你还没有出生呢！\n");

	if (me->query("doing"))
		return notify_fail("你还想干什么？！\n");
		
	if (environment(me)->query("no_magic"))
		return notify_fail("你发现这里有点古怪！\n");		
	
	if (arg == "back")
	{			
		if (me->query_temp("jun_quest/party"))
			return notify_fail("你还想在战争中使用？！\n");

		if (present("biao huo", me))
			return notify_fail("你身上带著镖银，不能施展！\n");
		
		if (present("letter", me) || present("receipt", me)) 
			return notify_fail("你身上带著密函，不能施展。\n");
		
		if(me->query("family/family_name") == "魔教")
			shimen = "/d/wansong/fuguitin";
		if(me->query("family/family_name") == "玄冥谷")
			shimen = "/d/xuanminggu/xuanmingfeng";
		if(me->query("family/family_name") == "神龙教")
			shimen = "/d/shenlong/dating";
		if(me->query("family/family_name") == "星宿派")
			shimen = "/d/xingxiu/riyuedong";
		if(me->query("family/family_name") == "少林派")
			shimen = "/d/shaolin/fzlou2";
		if(me->query("family/family_name") == "武当派")
			shimen = "/d/wudang/xiaoyuan";
		if(me->query("family/family_name") == "峨嵋派")
			shimen = "/d/emei/hcahoudian";
		if(me->query("family/family_name") == "丐帮")
			shimen = "/d/city/gbxiaowu";
		if(me->query("family/family_name") == "桃花岛")
			shimen = "/d/taohua/dating";
		if(me->query("family/family_name") == "古墓派")
			shimen = "/d/gumu/zhengting";
		if(me->query("family/family_name") == "血刀门")
			shimen = "/d/xuedao/shandong3";
		if(me->query("family/family_name") == "雪山寺")
			shimen = "/d/xueshan/neidian";
		if(me->query("family/family_name") == "欧阳世家")
			shimen = "/d/baituo/dating";
		if(me->query("family/family_name") == "灵鹫宫")
			shimen = "/d/lingjiu/dating";
		if(me->query("family/family_name") == "关外胡家")
			shimen = "/d/guanwai/xiaowu";
		if(me->query("family/family_name") == "慕容世家")
			shimen = "/d/yanziwu/shangyu";
		if(me->query("family/family_name") == "段氏皇族")
			shimen = "/d/dali/neitang";
		if(me->query("family/family_name") == "逍遥派")
			shimen = "/d/xiaoyao/qingcaop";
		if(me->query("family/family_name") == "全真教")
			shimen = "/d/quanzhen/shiweishi";
		if(me->query("family/family_name") == "明教")
			shimen = "/d/mingjiao/dadian";
		if(me->query("family/family_name") == "华山派")
			shimen = "/d/huashan/qunxianguan";
		if(me->query("family/family_name") == "日月神教")
			shimen = "/d/heimuya/up1";
		if(me->query("family/family_name") == "华山剑宗")
			shimen = "/d/huashan/xiaowu";
		if(me->query("family/family_name") == "移花宫")
			shimen = "/d/yihua/yaoyue";
		if(me->query("family/family_name") == "唐门世家")
			shimen = "/d/tangmen/tangltt";
		if(me->query("family/family_name") == "白云城")
			shimen = "/d/baiyun/zhongzhou";
		if(me->query("family/family_name") == "蜀山派")
			shimen = "/d/shushan/shangqing";
        if(me->query("family/family_name") == "玄冥谷")
			shimen = "/d/xuanminggu/xuanmingfeng";
		if(me->query("family/family_name") == "浣花剑派")
			shimen = "/d/huanhua/zhenmei";
		if(me->query("family/family_name") == "绝情谷")
			shimen = "/d/jueqing/zizhuxuan";
		
		if (base_name(environment(me)) == shimen)
			return notify_fail("你已经到了。\n");
		
			
		if(!me->query("family/family_name"))
			return notify_fail("你有师门吗？！\n");

		message("vision", me->name() + "举起右手在面前极速画了一个圆，竟划破了面前的"
			"空间，只见圆内的空间真空将" + me->name() + "给吸了进去。\n",
			environment(me), ({me}));
		
		tell_object(me, "你从空间裂缝中钻出。\n");

		me->move(shimen);


		return 1;
	}

     str = me->query_temp("pet_id");      
		     
     if (! stringp(file = me->query("can_whistle/" + str)))
		return notify_fail("你并没有这个魔幻兽。\n");

	if (file_size(file + ".c") < 0)
		return notify_fail("你并没有这个魔幻兽!\n");
				
	if (arg == "change" && ! me->query("beastdied"))
	{
		if (! objectp(ob = present(str, environment(me))))
			return notify_fail("你得首先把你的魔幻兽召唤到身旁来。\n");
		
		if (ob->query("owner") != me->query("id"))
			return notify_fail("你的魔幻兽并不在你的身旁。\n");
				
		if (! living(ob)) return notify_fail("你的魔幻兽目前处于昏迷状态呢。\n");

		message_vision("$N举起右手在面前极速画了一个圆，大喊"
			"一声，“$n，铠化！”\n", me, ob);
		
		if (! ob->receive_change(me))
		{
			message_vision("然而什么也没有发生 :)\n", me);			
			return 1;
		} 
	} else
	if (arg == "recover" && ! me->query("beastdied"))
	{
		 if (! objectp(ob = present(str, me)))
			return notify_fail("你身上并没有任何铠化的魔幻兽。\n");
				       
		if (ob != me->query_temp("is_changing"))
			return notify_fail("你身上并没有任何铠化的魔幻兽。\n");  

		if (ob->query("owner") != me->query("id"))
			return notify_fail("你身上并没有任何铠化的魔幻兽。\n");
					
		if (! living(ob)) return notify_fail("你的魔幻兽目前处于昏迷状态呢。\n");

		message_vision("$N集中心智，在心中慢慢的呼道：“$n，解除铠化。”\n", me, ob);
		
		if (! ob->receive_recover(me))
		{
			message_vision("然而什么也没有发生 :)\n", me);			
			return 1;
		}		  
	}

	else return help(me);
	return 1;
}

int help(object me)
{
 write(@HELP
指令格式 : recall change|recover <id>
让魔幻兽铠化或解除铠化，让魔幻兽复活的指令为< recall reborn >
回到扬州客店的指令为 < recall back >。
HELP
    );
    return 1;
}