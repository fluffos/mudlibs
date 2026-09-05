// azi.c 阿紫
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/new_quest/qxiepai.h"
#include "/new_quest/quest.h"
string ask_me();
string ask_zhen();
string ask_san();
string ask_for_shenmuding();
string ask_for_help();
void consider();
void do_answer(string);

void create()
{
        set_name("阿紫", ({ "a zi","azi","zi" }));
        set("nickname", "星宿派小师妹");
        set("title",HIR "星宿派" NOR + GRN +"妖女" NOR);
        set("long",
                "她就是丁春秋弟子阿紫。\n"
                "她容颜俏丽，可眼神中总是透出一股邪气。\n");
        set("zhen_count",20); 
        set("san_count",10);
        set("gender", "女性");
        set("age", 15);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 25);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("combat_exp", 50000);
        set("score", 10000);
        set("start_room","/d/xingxiu/xxroad4");
        set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "name"   : "我就是阿紫呀！！",
                "quest":   (: ask_quest() :),
                "cancelquest":   (: ask_cancel() :),
                "取消任务":   (: ask_cancel() :),
                "碧磷针":  (: ask_zhen() :),
                "清心散":  (: ask_san() :),
				"神木鼎" : (:ask_for_shenmuding :),
				"神木王鼎" : (:ask_for_shenmuding :),
				"神木宝鼎" : (:ask_for_shenmuding :),
				"help" : (: ask_for_help :),
				"帮助" : (: ask_for_help :),
        ]) );
         set("chat_chance", 5);
        set("chat_msg", ({
		"阿紫突然咯咯地笑了起来，问你道：“等我练成了化功大法，姊夫就应该会喜欢我了吧？”\n",
		"阿紫笑着笑着突然又叹了口气，愁道：“只怕我还是比不上阿朱。”\n",
		"阿紫望着面前的一段枯枝，痴痴地问道：“姊夫，你说是我姊姊漂亮，还是我漂亮？”\n",
		"阿紫凝视着天边的晚霞，幸福地说道：“我心目中的英雄，是一个顶天立地的好男儿，
总会在紧急关头来救我，把那些老魔小丑打得落花流水。”\n",
    "阿紫突然轻轻拉着路边一棵大树的枝叶央求道：“姊夫，你就说句喜欢我吧，就一句，
哪怕只是骗我一忽儿，那也是好的。”\n",
		"阿紫凄然一笑道：“可惜我猜中了这开头，却猜不到这结局。”\n",
        }));        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
        set_skill("force", 50);
        set_skill("huagong-dafa", 50);
        set_skill("dodge", 50);
        set_skill("zhaixinggong", 50);
        set_skill("strike", 50);
        set_skill("xingxiu-duzhang", 50);
        set_skill("hand", 50);
        set_skill("zhaixing-shou", 50);
        set_skill("parry", 50);
        set_skill("staff", 50);
        set_skill("tianshan-zhang", 50);
        set_skill("literate", 80);
        set_skill("poison", 80);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "xingxiu-duzhang");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
        create_family("星宿派", 2, "弟子");
		set("NoBusyAsking",1);
        set("no_get","把阿紫搬走了，让别人怎么办？做人不要那么自私。\n");
		setup();
}

void attempt_apprentice(object ob)

{
        int reward;
        object ntool;
        object me=this_player();
        string title;
        if (me->query("xxnewbiejob/apprentice"))
        {
            if (me->query("family/family_name")=="星宿派")
            {
                command("smile");
                return;
            }
            else
            {
                command("say 你被逐出门墙才不久，就又回来了？");
                return;
            }
        }
        if (me->query_temp("apprentice/finish"))
        {
            ntool=present("newbie guider",me);
            if (ntool)
            {
                destruct(ntool);
            }
            command("say 好吧，我就收下你了。");
            command("recruit " + ob->query("id"));
            me->delete_temp("apprentice");
            me->set("xxnewbiejob/apprentice",1);
            reward=5000;
		    reward=REWARD_D->add_exp(me,reward);
            write(HIW"因为完成星宿入门任务，你被奖励了：\n");
            write("\t"+chinese_number(reward)+"点经验。\n");
            command("say 好吧，既然你已经门内各位前辈请过安了，为师送你去后山修炼。");
            command("say 武学之道，唯有勤修苦练，你身上的新手精灵暂时用不着了，为师替你保管。");
            me->move("/d/xingxiu/wenjinting");
            return;
        }
        else
        {
            title=HIR+"星宿派"+HIG+"挂名弟子 "+NOR+me->query("name") + "(" + capitalize(me->query("id")) + ")";
            me->set_temp("apply/short",title);
            command("say 你初到我派，先做个挂名弟子吧，给派内各位前辈请安(qingan)，我正式收你为徒。");
            me->set_temp("apprentice/step",1);
            return;
        }
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("exert qisuck " + target->query("id"));
}

string ask_for_help()
{
	object me = this_player();
	object worm = present( "xunxiang chong", me);
	string pbelong, pshort;
	if (!objectp(worm))
		return "滚！"+me->query("name")+"你这"+RANK_D->query_rude(me)+"凑什么热闹，莫非是来消遣本姑娘的？";
	if ((time()-me->query("bingcan-duzhang/ask_azi"))<300)
	{
		command("kick "+me->query("id"));
		return me->query("name")+"你这"+RANK_D->query_rude(me)+"，比本姑娘还要好吃懒做！脖子上顶个脑袋做什么用的？";
	}
	if(me->query("balance")<2000000)
		return "穷光蛋！帮忙不用给辛苦费的吗？";
    me->add("balance",-2000000);//扣款
    tell_object(me,"阿紫嘿嘿奸笑了两声，搓搓手指，做了一个要钱的动作。\n");	
    tell_object(me,"你不禁在心里骂了一句：“死丫头”，但还是老老实实地通知钱庄转账20两黄金给阿紫。\n");
	pbelong = worm->query("shenmuding_place_belong");
	pshort = worm->query("shenmuding_place_short");
	if (!pbelong || !pshort)
	{
		return "让我瞧瞧……咦，哎呦喂，这是什么情况？完蛋了，本姑娘居然也找不到神木王鼎在哪里……";
	}
	else
	{
		return "以本姑娘推测，神木王鼎定然是在 "HIG+pbelong+NOR" 的 "HIG+pshort+NOR" 去快找吧，别把它玩坏喽。";	
	}
}

string ask_for_shenmuding()
{
	object me = this_player();
	if (!me->query_temp("ask_ding_shenmuding"))
	{
		command("sleepy");
		return "你刚才说啥来着……算了算了，别再说了，我忙着呢，懒得理你！";
	}
	if ((time()-me->query("bingcan-duzhang/ask_azi"))<7200)
	{
		command("kick");
		return "你老问老问烦不烦啊？小心我揍你哦！";
	}
	me->set("bingcan-duzhang/ask_azi",time());
	me->delete_temp("ask_ding_shenmuding");
	me->set_temp("ask_azi_shenmuding", 1);
	remove_call_out("do_give_xiansuo");
	call_out("do_give_xiansuo", 1, me);
	return "嘘……别声张，我偷偷告诉你，师父的宝鼎被我弄丢了。如果你有空就帮我找找吧，找到了记得速速送还给我！";
}

void do_give_xiansuo(object me)
{
	object ob, where;
	if (!me || environment(me) != environment())
		return;
	ob = new(__DIR__"obj/worm");
	if (objectp(ob))
	{
		while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd")
		{
			where = TASK_D->random_place();
		}
		ob->set("shenmuding_place", file_name(where));
		ob->set("shenmuding_place_belong", TASK_D->place_belong(where));
		ob->set("shenmuding_place_short", COLOR_D->uncolor(where->query("short")));
		ob->set("belong_user", me->query("id"));
		ob->move(me);
		tell_object(me, "阿紫趁别人不注意，偷偷塞给你一样东西。\n");
	}
}

string ask_me()
{
        mapping fam;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if ( this_player()->query_temp("marks/阿") )
                return "“怎么，我不是刚刚告诉你了吗?”\n";
        if (this_player()->query_temp("marks/丁") )
        {
                write("阿紫悄悄对你说道：你都知道了，冰魄杖是我给老怪藏了起来了,\n"
                        "你到逍遥洞找找，找到了，你就拿着吧，我要着也没用。\n");
                this_player()->set_temp("marks/阿", 1);
                return "这可不能让外人听到啊！";
        }
        else
        {
                write(HIY"你发现阿紫的脸有点红.\n"NOR);
                return("我...我不知道。。\n");
        }       
}

string ask_zhen()
{
        object zhen, ob, me;
        mapping fam;
		int pflv;
		
		ob = this_object();
		me = this_player();

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                        "与本派素无来往，为何窥觑本派宝物？";
        if (this_player()->query("score") < 200)
                return "这位" + RANK_D->query_respect(this_player()) +
                        "对本门忠心不够，没有资格获得本门宝物。";
        if (time()-ob->query("give_bilinzhen")<600)
                return "你来晚了，碧磷针我已经给光了。";

		ob->set("give_bilinzhen", time());

		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "星宿派") 
			pflv=0;

        zhen = new("/d/xingxiu/npc/obj/bilinzhen");
		if (pflv>0)
			zhen->set_amount((pflv>=4)?((pflv+1)*(pflv+1)):(pflv*5));
        zhen->move(me);
        message_vision("阿紫从腰间捏出一"+((pflv>0)?"丛":"根")+"绿幽幽的" + HIG + "碧磷针"+ NOR + "交给$N。\n", me);
        return "碧磷针炼制不易，一定要仔细使用啊。";
} 

string ask_san()
{
        object san;
        mapping fam;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                        "与本派素无来往，为何窥觑本派清心散？";
        if (this_player()->query("score") < 200)
                return "这位" + RANK_D->query_respect(this_player()) +
                        "对本门忠心不够，没有资格获得清心散。";
		if (environment()!=load_object(query("startroom")))
			return "被人弄到这里，你觉得我身上还会有清心散吗？";
		if (time()-this_player()->query("AskXxQXSTime")<30)
		{
			this_player()->add_busy(5);
			return "絮絮叨叨，才问过又问。";
		}
		if (time()-query("LastTimeSan")<60)
		{
				this_player()->add_busy(2);		
			return "清心散十分珍惜，过一会再来拿吧。";
		}
        /*if (query("san_count") == 0)
                return "你来晚了，清心散我已经给光了。";*/
        add("san_count",-1);
		set("LastTimeSan",time());
		this_player()->set("AskXxQXSTime",time());
        san = new("/d/xingxiu/obj/xxqingxi");
        san->move(this_player());
        message_vision("阿紫从腰间捏出一包清心散交给$N。\n",this_player());
        return "清心散能解本派剧毒，一定要珍惜使用啊。";
}

