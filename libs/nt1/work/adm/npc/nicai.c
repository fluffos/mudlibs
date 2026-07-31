// 狂人尼采 
// Created by Lonely Nitan@Mud
// 负责建立帮派的ＮＰＣ
// 本来我是想把建立帮派做成一个指令
// 但因为尼采是我的非常敬佩的人，所
// 以就用他了。

#include <ansi.h>
inherit NPC;
#define MAX_EXP 10000000

int check_name(string str, object me);
int create_banghui(string str);

void create()
{
        set_name("尼采", ({"ni cai", "ni", "cai"}));
        set("long", "世纪狂人之一，负责武林帮会(banghui)的建立。\n");
        set("nickname", RED"狂人"NOR);
        set("gender", "男性");
        set("age", 21);
        set("per", 2100);

        set_skill("unarmed", 500);
        set_skill("dodge",   500);
        set_skill("parry",   500);
        set_temp("apply/attack",  100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage",  50);

        set("inquiry", ([
                "banghui"       :"要创建帮会请create <帮会名>\n",
                "bangpai"       :"要创建帮会请create <帮会名>\n",
                "bunch"         :"要创建帮会请create <帮会名>\n",
                "帮会"          :"要创建帮会请create <帮会名>\n",
                "帮派"          :"要创建帮会请create <帮会名>\n",
        ]) );

        set("combat_exp", 21000000);
        set("max_jingli", 21000);
        set("jingli", 21000);
        set("max_neili", 21000);
        set("neili", 21000);
        set("max_qi", 21000);
        set("qi", 21000);
        set("max_jing", 21000);
        set("jing", 21000);
        set("no_suck", 1);
        setup();
}

int check_name(string name, object me)
{
        int i;

        i = strlen(name);

        if ((strlen(name) < 4) || (strlen(name) > 12 )) 
        {
                tell_object(me, "帮会名称请定在二到六个字。\n");
                return 0;
        }
        
        while (i--) 
        {
                if (name[i] <= ' ') 
                {
                        tell_object(me, "对不起，你的帮会名中不能用控制字符。\n");
                        return 0;
                }
                
                if (i%2 == 0 && ! is_chinese(name[i..<0])) 
                {
                        tell_object(me, "请用「中文」命名你的帮会。\n");
                        return 0;
                }
        }
        return 1;
}


void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("create_banghui", "create");
}

int create_banghui(string str)
{
        object me, lingpai, lp;
        int count;
        int base = 10000; 

        me = this_player();
        
        if ((string)me->query("bunch/name"))        
        {
                tell_object(me, "你已经是" + me->query("bunch/name") + "的人了，不能另创帮会。\n");
                return 1;
        }
        
        if (me->query("combat_exp") < MAX_EXP)    
        {
                tell_object(me, RANK_D->query_respect(me) + "的实战经验还差" +
                	    (string)(MAX_EXP - me->query("combat_exp")) + "点，暂时无法开帮立会。\n");
                return 1;
        }
        
     	if (me->query("weiwang") < 100)
     	{
        	tell_object(me, RANK_D->query_respect(me) + "，开帮立会需要一百点江湖威望，"
                    	    + "你才这点威望，谁听你的啊？\n");
        	return 1;
    	}
    	
        if (! count = me->query("lonely/have_create")) 
        	count = 0;
        	
        if (count >= 2)    
        {
                tell_object(me, "尼采怒道：你以为帮会是创着玩吗？想再建帮会，下辈子吧！\n");
                return 1;
        }
        
        if (! str)       
        {
                tell_object(me, "你要创建什么名字的帮会？\n");
                return 1;
        }
        
        if (! check_name(str, me)) return 1;

        if (file_size("/data/guild/" + str + ".o") != -1) 
        {
                tell_object(me, "非常抱歉，你起的帮派名早就有了。\n");
                return 1;
        }
        
        lingpai = new("/clone/misc/lingpai");
        lingpai->create(str);
        lingpai->set("bangzhu", me->query("name"));
        lingpai->set("bangzhu_id", me->query("id"));
        lingpai->set("player", ([me->query("id") : me->query("name")]));
        lingpai->set("npc", ([]));
        lingpai->set("area", ([]));
        lingpai->set("money", 0);
        lingpai->save();
        destruct(lingpai);

        BUNCH_D->create_bunch(str, base); 
        me->set("bunch/name", str);
        me->set("bunch/rank", "领袖");
        me->set("bunch/level", 7);
        count++;
        me->set("lonely/have_create", count);
        me->save();
        command("chat 恭喜" + me->query("name") + "的帮会「" + str + "」创建成功！\n");
        return 1;
}

void greeting(object ob)
{
        string banghui;
        object lingpai;
        if (! ob || environment(ob) != environment()) return;
        if ((string)(banghui = ob->query("bunch/name")))      
        {
                lingpai = new("/clone/misc/lingpai");
                lingpai->create(banghui);
                
                if (lingpai->query("no_use"))    
                {
                        tell_object(ob, "尼采道：" + ob->query("name") + "，你的帮会文件有问题，快与巫师联系吧。\n");
                }
                else if (lingpai->query("bangzhu_id") != "???")    
                {
                        if (lingpai->query("bangzhu_id") == ob->query("id") 
                        &&  lingpai->query("bangzhu") == ob->query("name"))
                        	tell_object(ob, "尼采一抱拳道：这位" + ob->query("bunch/name") +
                        		    ob->query("bunch/rank") + "，贵帮生意如何？\n");
                        		    
                        else    tell_object(ob, "尼采道：" + ob->query("name") +
                        "，贵帮帮主身体可好？\n");
                }
                else    tell_object(ob, "尼采偷偷在你耳边道：贵帮主失踪多日，" +
                        	    RANK_D->query_respect(ob) +
                        	    "只需花一千两黄金就可以买下帮主之位。\n");
                destruct(lingpai);
        }
        else    tell_object(ob, "尼采对你一抱拳道：这位" + RANK_D->query_respect(ob) + "是来创建帮会的吗？\n");
}

int accept_object(object who, object obj)
{
        string banghui;
        object lingpai;
        
        if (! banghui = who->query("bunch/name"))     
        {
                tell_object(who, "尼采笑道：我可不敢平白无故接受你的东西。\n");
                return 0;
        }
        
        lingpai = new("/clone/misc/lingpai");
        lingpai->create(banghui);
        
        if (lingpai->query("no_use"))    
        {
                tell_object(who, "尼采叹道：" + who->query("name") + "，你的帮会文件有问题，快与巫师联系吧。\n");
                destruct(lingpai);
                return 0;
        }
        
        if (lingpai->query("bangzhu_id") != "???")       
        {
                tell_object(who, "尼采十分惊讶，说道：贵帮帮主还活的好好的，我可不改把帮主之位卖给" +
                	    RANK_D->query_respect(who) + "啊。\n");
                destruct(lingpai);
                return 0;
        }
        
        if (! obj->query("money_id"))    
        {
                tell_object(who, "尼采皱眉道：这些破烂我没兴趣。\n");
                destruct(lingpai);
                return 0;
        }
        
        if(obj->value() < MAX_EXP)       
        {
                tell_object(who, "尼采道：至少一千两黄金，不然我如何向上面交待？\n");
                destruct(lingpai);
                return 0;
        }
        
        lingpai->set("bangzhu", who->query("name"));
        lingpai->set("bangzhu_id", who->query("id"));
        lingpai->save();
        destruct(lingpai);
        who->set("bunch/level", 7);
        who->set("bunch/rank", "领袖");
        who->save();
        
        command("chat " + who->query("name") +
        	"花了一千两黄金，买下了" + banghui + "帮主之位。\n");
        return 1;
}

