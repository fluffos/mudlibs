// que.c 岳不群
// Modified by iszt@pkuxkx, 2007-04-15, added job
// Modified by Zine,2011-05-08,added newbie job
#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

#include <no1master.h>
#include "random_npc.h"
#include "bonus.h"
#include "random_user_quest.h"
int ask_job();
int ask_fail();
int ask_times();
int ask_finish();
int ask_taojiao();
string ask_for_leave();
int ask_join();
void create()
{
	set_name("岳不群",({"yue buqun","yue"}));
	set("nickname", RED "君子" NOR + "剑");
	set("title", YEL "华山派" NOR + GRN "第十八代" NOR + YEL "掌门" NOR);
	set("long", "华山掌门岳不群，他今年四十多岁，人称君子剑，素以温文尔雅著称。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	set("max_qi", 1200);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 1000000);
	set("score", 50000);

	set_skill("force",150);
	set_skill("zixia-shengong", 150);
	set_skill("cuff", 150);
	set_skill("poyu-quan", 150);
	set_skill("strike", 150);
	set_skill("hunyuan-zhang", 150);
	set_skill("dodge", 150);
	set_skill("huashan-shenfa", 150);
	set_skill("yangwu-jian", 160);
	set_skill("yunushijiu-jian", 50);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("huashan-jianfa",150);
	set_skill("literate", 150);

	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

	create_family("华山派",18,"掌门");

	set("inquiry", ([
		"job" : (: ask_job :),
		"fail" : (: ask_fail :),
		"times" : (: ask_times :),
		"finish" : (: ask_finish :),
		"送信" : (: ask_job :),
		"失败" : (: ask_fail :),
		"功劳" : (: ask_times :),
		"完成" : (: ask_finish :),
    "讨教" : (: ask_taojiao :),
    "taojiao" : (: ask_taojiao :),
    "脱离门派" : (: ask_for_leave :),
	"回归气宗" : (: ask_join :),
	]));

	setup();
	setup_no1master();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/huashan/obj/baishan")->wear();
}
int ask_join()
{
	object me=this_player();
	mapping myfam;
	if (!(myfam = this_player()->query("family"))|| myfam["family_name"] != "华山派")
	{
		command("say 你非本派弟子，此话谈何说起？");
		return 1;
	}
	if (!me->query("huashan_newskills/jianzong"))
	{
	  if ( !me->query("huashan_newskills/qizong") )
	    me->set("huashan_newskills/qizong",1);
		command("say 不要妄谈什么剑宗，我们气宗才是嫡传正宗。");
		return 1;
	}
	if (!me->query("huashan_newskills/attempt_qizong"))
	{
		command("say 既然你有拨乱反正之心，我却要考验考验你，过一天后再来吧。");
		me->set("huashan_newskills/attempt_qizong",time());
		return 1;
	}
	
  if ( me->query_skill_mapped("force") )
  {
    command("say 加入气宗这么严肃的事情请不要激发内功。");
    return 1;
  }
	
	if (time()-me->query("huashan_newskills/attempt_qizong")<86400)
	{
		command("say 还没满一天呢。");
		return 1;
	}
	else
	{
		command("say 好吧，我就把你收入华山嫡传正宗门墙了。");
		me->delete("huashan_newskills/jianzong");
		me->set("huashan_newskills/qizong",1);
		tell_object(me,HIR+"恭喜你，加入了华山气宗。\n"+NOR);
		me->delete("huashan_newskills/attempt_qizong");
		return 1;
	}
}
string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("family/family_name") != "华山派")
		return "你非我华山派弟子，脱离门派的事情我作不得主。";

	me->set_temp("pending/leave_huashan", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我华山派而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_huashan") != 1)
		return 0;
	message_vision("$N对$n说道：「从此你就不再是我华山派门下了，请好自为之！」\n",this_object(), me );
	tell_object(me,HIR "你决定叛出华山派门下！\n" NOR);
	me->delete_temp("pending/leave_huashan");
  me->expell_family("华山派");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}	

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name")!="华山派")
	{
		command("say 你非我派弟子，我不能收你。");
		return ;
	}
//男号能拜宁中则，女号不能拜老岳？开放岳也收女弟子，否则女号学不到养吾剑。by lordstar@2017-10-10
/*
	if((string)ob->query("gender")!="男性")
	{
		command("say 我不收女弟子。姑娘，你还是拜内子吧！");
		return;
	}  */
	if ((int)ob->query("max_neili") <200) {
		command("say 我华山派原有剑宗、气宗之争。最终气宗为首。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该多练练内力？");
		return;
	}
	if ((int)ob->query("score") < 500)
	{
		command("sigh "+ob->query("id"));
		command("say 你对本门的贡献太少了，我不能传授你更高深的功夫。");
		return;
	}
	if ((int)ob->query("shen") < 1000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
		return;
	}
	command("say 好吧，小兄弟！我就收下你了！\n");
	command("say 你今后可要惩恶扬善，匡扶正义！绝不可为非作歹，否则为师绝不会放过你的！\n");
	command("recruit "+ob->query("id"));
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
		if (this_player()->query("shen")<10000)
			ob->set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
		else 
			ob->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
	}
}

void re_rank(object student)
{
		if (this_player()->query("shen")<10000)
			student->set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
		else 
			student->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  student->set_title(TITLE_RANK, student->query("title"));
}



int othertaojiao(object me)
{
    object ob=this_object();
    if (me->query("combat_exp")<3000000)
    {
        me->set_skill("huashan-neigong", me->query_skill("huashan-neigong", 1)+10);
        me->set_skill("huashan-jianfa", me->query_skill("huashan-jianfa", 1)+10);
        tell_object(me,HIM"岳不群传授了你一些本派内功和剑法方面的秘诀。\n"NOR);
        message_vision("$N凝重地说道：我派“剑掌五连环”绝技失传已久，你天资尚可，我传你一些心得，不过还是慎用为妙。\n",ob);
        me->set("huashannewbiejobsword",1000);
        return 1;
    }
    else
    {
        me->set_skill("huashan-neigong", me->query_skill("huashan-neigong", 1)+5);
        me->set_skill("huashan-jianfa", me->query_skill("huashan-jianfa", 1)+5);
        tell_object(me,"岳不群传授了你一些本派内功和剑法方面的秘诀。\n");
        return 1;
    }
}
int ask_taojiao()
{
    object me=this_player();
    object sword;
    if (this_object()->is_busy())
    {
        message_vision("岳不群正忙着呢！",me);
        return 1;
    }
    if(me->query("family/family_name")!="华山派")
    {
        command("say 阁下与我派素无渊源，讨教从何说起？");
        return 1;
    }
    if (!me->query("huashannewbiejobdone"))
    {
        command("say 你为我派做的贡献还不够啊，多做做本门任务吧。");
        return 1;
    }
    if (me->query("huashannewbiejobreward"))
    {
        command("say 我不是指点过你了吗。");
        return 1;
    }
    
    if (me->query("level")<16)
    {
        command("say 你的级别太低了，等到十六级以后再来找我讨教吧。");
        return 1;
    }
    me->set("huashannewbiejobreward",1);
    sword=new("obj/gem/weapon");
    sword->gen_weapon(1+random(9),8500+random(600),9999,"sword");
    sword->set("forge/max",2);
    if (random(1000)>995)
    {
        sword->set("forge/max",3);
    }
    sword->move(me);
    message_vision("$N面色凝重地对$n道："+sword->query("name")+"是我派镇派之宝，我就把它传给你吧。\n\n",this_object(),me);
    me->add_busy(1);
    this_object()->add_busy(1);
    remove_call_out("othertaojiao");
    call_out("othertaojiao",1,me);
    return 1;

}

int accept_object(object me,object ob)
{
	object jian;
	if (ob->query("id") == "heimuya tu")
	{
		command("say 多谢这位" + RANK_D->query_respect(me) + "把这幅图带了回来，这把碧水剑本来是准备给小女作生日礼物的，就送给你作个纪念吧！\n");
		tell_object(me,HIG "你的道德上升了！\n" NOR);
		me->add("shen",5000);
		jian = new("/d/riyuejiao/obj/bishuijian");
		jian->move(me);
		message_vision("岳不群给了$N一把" + HIG "碧水剑" NOR + "。\n",me);
		this_object()->start_busy(3);
		call_out("destroying",1,ob);
		return 1;
	}
	return 0;
}

int destroying(object ob)
{
	destruct(ob);
	return 1;
}

int after_random_npc(object me,object thetarget)
{
    object where,letter;
    object ob=this_object();
    where=environment(thetarget);
    
    if (!where)
    {
        command("say 你等会儿再来吧。");
        return 1;
    }
    if (!where&&wizardp(me))
    {
        tell_object(me,"没环境\n");
    }
    if (wizardp(me))
    {
        tell_object(me,thetarget->query("name"));
        tell_object(me,where->query("short")+"\n");
    }
    
    if (where)
    {
        message_vision("$N对$n说道："+thetarget->query("name")+"在"+TASK_D->place_belong(where)+"，本座有封信，你去送给他吧。\n",ob,me);
        me->set_temp("hsnewbiejob/songxin/level",2 );
        me->set("hsnewbiejob/start",1);
        me->set("hsnewbiejob/lasttime",time());
        me->set_temp("hsnewbiejob/songxin",1);
        me->set_temp("task_stat/songxin/songxin_starttime",time());
        me->set_temp("hsnewbiejob/songxin/target_name", thetarget->query("name"));
	    me->set_temp("hsnewbiejob/songxin/target_id", thetarget->query("id"));
	    me->set_temp("hsnewbiejob/songxin/where", where->query("short"));
        letter = new(__DIR__"job/letter2");
        letter->do_init(me);
	    letter->move(me);
    }
    else
    {
        command("say 你等会儿再来吧。");
    }
    return 1;
}


int hsnewjob(object me)
{
    int n;
    string respect = RANK_D->query_respect(me);
	int count = 0;
	object where;
	object* inv;
	int i;
	object target;
	int shen = me->query("shen");
	string msg;
	object letter;
    if(!wizardp(me) && time() - query("last_give_time") < 10)
	{
		command("say 多谢这位"+respect+"好意，这里暂时没有什么任务。");
		return 1;
	}
    if (!me->query("hsnewbiejob/intro"))
    {
        me->set("hsnewbiejob/intro",1);
        tell_object(me,HIR"华山入门任务帮助请在游戏中使用命令help task-huashan获得。\n"NOR);
    }
    if (me->query("hsnewbiejob/start"))
    {
        command("say 你不是要过任务了吗？快去完成它吧。");
        return 1;
    }
	if(time() - ((int)me->query("hsnewbiejob/lasttime")+(int)me->query("hsnewbiejob/user")*120) < 60)
	{
		command("say 你先下去休息休息吧。");
		return 1;
	}
    
	if(query("startroom") != file_name(environment()))
	{
		command("say 我尚有要事在身，等我回到华山再说吧。\n");
		return 1;
	}
    if (me->query("hsnewbiejob/user"))
    {
        lookingforplayer(me);
        return 1;
    }
    if (random(100)>90)
    {
        lookingforplayer(me);
        return 1;
    }
	while(!target && count < 5)
        {
            where = TASK_D->random_place_ex(me);
            inv = all_inventory(where);
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
                    continue;
                if(inv[i]->query("combat_exp") < 60000 || inv[i]->query("age")<20)
                    continue;
                if(inv[i]->query("uni_target") || inv[i]->query("age")<20)
                    continue;
                target = inv[i];
            }
            count++;
        }
        if(!target || !random(4))
        {
            target = TASK_D->random_carrier();
			target->set("chat_chance",3);
            target->move(where);
            for (i=0;i<3;i++)
                if (target)  target->random_move();
        }
        if(!target)
        {
            command("say 嗯……信还没写好，你稍等一会吧。");
            return 1;
        }
        msg = RED"$N交给$n一封盖着火漆印戳的密函。\n"NOR;
		msg += CYN"$N说道：「多谢" + respect + NOR+CYN"，请将这封密函火速送到"
			+TASK_D->place_belong(where)+where->query("short")+NOR
			CYN"附近的"+target->query("name")+CYN"手上。」\n"NOR;
		message_vision(msg, this_object(), me);
		command("say 此事事关重大，全拜托" + respect + "了！");
		me->set_temp("hsnewbiejob/songxin/level",1 );
        me->set("hsnewbiejob/start",1);
        me->set("hsnewbiejob/lasttime",time());
        me->set_temp("hsnewbiejob/songxin",1);
        me->set_temp("task_stat/songxin/songxin_starttime",time());
        me->set_temp("hsnewbiejob/songxin/target_name", target->query("name"));
	    me->set_temp("hsnewbiejob/songxin/target_id", target->query("id"));
        me->set_temp("hsnewbiejob/songxin/targetwhere", where);
	    me->set_temp("hsnewbiejob/songxin/where", where->query("short"));
        letter = new(__DIR__"job/letter2");
        letter->do_init(me);
	    letter->move(me);
  
	
	return 1;
}
int HS_qizong60Mplus_remain(object me)//气宗给了福利60M+可以做10次任务，计算一天还能做几次
{
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	if (me->query("family/family_name")!="华山派"||me->query("huashan_newskills/jianzong"))
	return -1;
	if (date!=me->query("huashan_newskills/bonus/sx_date"))
	{
		me->set("huashan_newskills/bonus/sx_date",date);
		me->set("huashan_newskills/bonus/remain",10);
	}
	return me->query("huashan_newskills/bonus/remain");
}
int ask_job()
{
	object me = this_player();
	string respect = RANK_D->query_respect(me);
	int count = 0;
	object where;
	object* inv;
	int i;
	object target;
	int shen = me->query("shen");
	string msg;
	object letter;

	if(me->query("huashan/on_songxin"))
	{
		command("say 不是已经交给你任务了么？");
		return 1;
	}
    if ((me->query("family/enter_time")>1304899200||me->query("env/newbiejob"))&&me->query("combat_exp")>=60000 && me->query("family/family_name")=="华山派" &&!me->query("huashannewbiejobdone"))
    {
        hsnewjob(me);
        return 1;
    }
	if(me->query("combat_exp") < 100000)
	{
        if (me->query("family/enter_time")<=1304899200 && me->query("family/family_name")=="华山派")
        {
            tell_object(me,"入门早的弟子可以自行选择做华山新手任务或者其他任务例如唱戏，红豆等等。\n");
            tell_object(me,"如希望尝试新手任务，请set newbiejob yes\n");
        }
		command("patfy " + me->query("id"));
		command("say " + respect + "还是先去练练功吧。");
		return 1;
	}
	if(me->query("combat_exp") > 60000000)
	{
		if ((!me->query("safari")||me->query("safari/exp/songxin")<=me->query("exp/songxin"))&&HS_qizong60Mplus_remain(me)<1)
		{
			command("say " + respect + "武功如此高强，在下如何敢劳动大驾？");
			return 1;
		}
	}
	if(!wizardp(me) && time() - query("last_give_time") < 10)
	{
		command("say 多谢这位"+respect+"好意，这里暂时没有什么任务。");
		return 1;
	}
	if(!wizardp(me) && time() - me->query("huashan/last_fail") < 180)
	{
		message_vision(CYN"$N脸一沉道：「上次交给"+respect+NOR
			CYN"的任务才失败不久，还是等等吧。」"NOR, this_object());
		return 1;
	}
	if(!wizardp(me) && time() - me->query("huashan/last_songxin") < 60)
	{
		command("say "+respect+"先下去休息休息吧。");
		return 1;
	}
	if(query("startroom") != file_name(environment()))
	{
		command("say 我尚有要事在身，等我回到华山再说吧。\n");
		return 1;
	}

	while(!target && count < 5)
	{
		where = TASK_D->random_place_ex(me);
		inv = all_inventory(where);
		for(i=sizeof(inv)-1; i>=0; i--)
		{
			if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类")
				continue;
			if(inv[i]->query("combat_exp") < 60000 || inv[i]->query("age")<20)
				continue;
			if(inv[i]->query("uni_target") || inv[i]->query("age")<20)
				continue;
			target = inv[i];
		}
		count++;
	}
	if(!target || !random(4))
	{
		target = TASK_D->random_carrier();
		target->move(where);
		for (i=0;i<3;i++)
			if (target)  target->random_move();
	}
	if(!target)
	{
		command("say 嗯……信还没写好，你稍等一会吧。");
		return 1;
	}
	if (me->query("combat_exp")>60000000&&me->query("family/family_name")=="华山派"&&!me->query("huashan_newskills/jianzong"))
	me->add("huashan_newskills/bonus/remain",-1);
	//任务统计系统记录任务开始时间
	me->set_temp("task_stat/songxin/songxin_starttime",time());
	
	me->set("huashan/on_songxin", 1);
    me->set_temp("huashan/on_songxin", 1);
	me->set_temp("huashan/songxin/target_name", target->query("name"));
	me->set_temp("huashan/songxin/target_id", target->query("id"));
	me->set_temp("huashan/songxin/where", where->query("short"));
	letter = new(__DIR__"job/letter");
	command("nod");
	if(shen > 100000000 && random(5))
	{
		msg = RED"$N交给$n一封盖着火漆印戳的密函。\n"NOR;
		msg += CYN"$N说道：「多谢" + respect + NOR+CYN"，请将这封密函火速送到"
			+TASK_D->place_belong(where)+where->query("short")+NOR
			CYN"附近的"+target->query("name")+CYN"手上。」\n"NOR;
		message_vision(msg, this_object(), me);
		command("say 此事事关重大，全拜托" + respect + "了！");
		me->set_temp("huashan/songxin/level", 2);
	}
	else if(shen >= 0 && random(5))
	{
		msg = RED"$N交给$n一封盖着火漆印戳的密函。\n"NOR;
		msg += CYN"$N对$n道：「我这里正好有封密函，麻烦你跑一趟，交给"
			+TASK_D->place_belong(where)+where->query("short")+NOR
			CYN"附近的"+target->query("name")+CYN"。」\n"NOR;
		message_vision(msg, this_object(), me);
		command("addoil2 "+ me->query("id"));
		me->set_temp("huashan/songxin/level", 1);
	}
	else if(shen>=0 || (shen >= -100000000 && random(5)))
	{
		msg = RED"$N交给$n一封盖着火漆印戳的密函。\n"NOR;
		msg += CYN"$N道：「多谢" + respect + NOR+CYN"，你赶紧把它送到"
			+TASK_D->place_belong(where)+where->query("short")+NOR
			CYN"附近的"+target->query("name")+CYN"手中。」\n"NOR;
		message_vision(msg, this_object(), me);
		command("care");
		me->set_temp("huashan/songxin/level", 1);
	}
	else
	{
		command("say 多谢这位"+respect+"好意，这里暂时没有什么任务。");
		tell_object(me, RED"岳不群偷偷塞给你一封盖着火漆印戳的密函。\n"NOR);
		command("whisper "+me->query("id")+" 这封机密函件，火速送给"
			+TASK_D->place_belong(where)+where->query("short")+
			"附近的"+target->query("name")+"，好处少不了你的。");
		me->set_temp("huashan/songxin/level", 3);
	}
	letter->do_init(me);
	letter->move(me);
	return 1;
}
int ask_fail()
{
	object me = this_player();
    if (me->query_temp("hsnewbiejob/songxin")&& me->query("family/family_name")=="华山派")
    {
        if(present("mi han", me))
		destruct(present("mi han", me));
        punish(me);
        return 1;
    }
	if(!me->query("huashan/on_songxin"))
	{
        if (me->query("hsnewbiejob/start"))
        {
            command("say 没完成？那也没什么大不了的，算了吧。");
            punish(me);
            return 1;
        }
		command("heng");
		command("say 你又没有任务，放弃什么？");
		return 1;
	}
	if(query("startroom") != file_name(environment()))
	{
		command("say 我尚有要事在身，等我回到华山再说吧。\n");
		return 1;
	}
	command("sigh");
	command("say 如此不中用，你下去面壁思过吧。");
	write(HIR"你的任务失败，经验和潜能降低了。\n"NOR);
	me->set("huashan/last_fail", time());
	me->delete_temp("huashan/songxin");
	me->delete("huashan/on_songxin");
        me->delete_temp("huashan/on_songxin");
	if(present("mi han", me))
		destruct(present("mi han", me));
	me->add("combat_exp", -me->query("huashan/last_reward"));
	me->add("exp/songxin", -me->query("huashan/last_reward"));
	me->add("potential", -me->query("huashan/last_reward")/4);
	me->add("pot/songxin", -me->query("huashan/last_reward")/4);
	if(me->query("combat_exp") < 2000)
		me->set("combat_exp", 2000);
	return 1;
}
int ask_times()
{
	object me = this_player();
	if(!me->query("huashan/songxin_times"))
	{
		command("say 你无甚功劳。\n");
		return 1;
	}
	command("say 你现在已经帮我送了"
		+chinese_number(me->query("huashan/songxin_times"))+"件密函。");
	command("patfy " + me->query("id"));
	return 1;
}
int ask_finish()
{
	object me = this_player();
	int reward, cost_time,exp,pot,rep;
	int job_level;
	string system_msg;
    if (me->query_temp("hsnewbiejob/songxin/finish")&& me->query("family/family_name")=="华山派")
    {
        bonus(me);
        return 1;
    }
	if(!me->query("huashan/on_songxin"))
	{
		command("heng");
		command("say 你又没有任务，完成什么？");
		return 1;
	}
	if(!me->query_temp("huashan/songxin/finish"))
	{
		command("heng");
		command("say 你把密函送到哪里去了？");
		return 1;
	}
	if(query("startroom") != file_name(environment()))
	{
		command("say 我尚有要事在身，等我回到华山再说吧。\n");
		return 1;
	}
	if(random(30))
		command("great");
	else
		CHANNEL_D->do_channel(this_object(), "rw", "junzi "+me->query("id"), 1);
	if (!me->query("biography/jobs/songxin"))
	{
		me->set("biography/jobs/songxin",time());//个人传记记录第一次完成任务时间ZINE
	}
	message_vision(CYN"$N拍着$n的肩头，道：「辛苦你了！」\n"NOR, this_object(), me);

	write(HIW"你被奖励了：\n");
	system_msg = me->query("name")+"在华山送信任务中获得：";
	job_level = query_temp("huashan/songxin/level");

	reward = me->query("combat_exp")/1000000;
	if (reward>500)
	reward=500+to_int(sqrt(to_float(reward-500)));
	reward += job_level*10;
	if(reward > 10)
		reward = reward/2 + 5;
	reward = 1400 + reward * 100 - me->query_per() * 20;
	reward += me->query_temp("huashan/songxin/killer") * 600;
	reward += random(reward)/4;
    
	if(!me->query_temp("huashan/songxin/killer"))
		reward /= 50;
	reward = reward*42/20;//同步当时REWARDD里0.47的奖励，Zine 07272011同时加入reward管理。
    if (me->query("safari")&&me->query("combat_exp")>60000000&&reward>8000)
    {
        reward=8000+random(501);
    }
	reward = REWARD_D->add_exp(me,reward);
    me->set("huashan/last_reward", reward);
	me->add("exp/songxin", reward);
	write("\t"+chinese_number(reward)+"点经验；\n");
	system_msg += reward + "点经验；";
	exp=reward;
    //加入任务统计系统 by icer
	cost_time = time()-me->query_temp("task_stat/songxin/songxin_starttime");
    COMBAT_D->add("task_stat/songxin/complete_times",1);
    COMBAT_D->add("task_stat/songxin/cost_time",cost_time);
    COMBAT_D->add("task_stat/songxin/exp",reward);
    COMBAT_D->add("task_stat/songxin/expratio",to_float(reward)/me->query("combat_exp"));

	reward = me->query_skill("force", 1) + 10;
	reward += random(reward) / 4;
	reward += me->query_temp("huashan/songxin/killer") * 200;
	if(!me->query_temp("huashan/songxin/killer"))
		reward /= 50;
    reward = REWARD_D->add_pot(me,reward);
	me->add("pot/songxin", reward);
	write("\t"+chinese_number(reward)+"点潜能；\n");
	system_msg += reward + "点潜能；";
	pot=reward;
    COMBAT_D->add("task_stat/songxin/pot",reward);


	reward = me->query_skill("literate", 1)/100;
	reward ++;
	if(reward > 4)
		reward = 2 + reward/2;
	reward = random(reward)+1;
	reward *= 100;
	if(!me->query_temp("huashan/songxin/killer"))
		reward /= 50;
	reward = REWARD_D->add_rep(me,reward);
	write("\t"+chinese_number(reward)+"点江湖声望。\n");
	system_msg += reward + "点江湖声望。";
	rep=reward;
    COMBAT_D->add("task_stat/songxin/repute",reward);
	//STATISTIC_D->task_record("SONGXIN",exp,pot,rep,1);
	me->add("huashan/songxin_times", 1);
	write("你总共已经送了"+chinese_number(me->query("huashan/songxin_times"))+"件密函。\n"NOR);
	CHANNEL_D->do_channel(this_object(), "sys_misc", system_msg);

	me->set("huashan/last_songxin", time());
	me->delete_temp("huashan/songxin");
	me->delete("huashan/on_songxin");
	
	return 1;
}

#include "/kungfu/class/masterdie.h"