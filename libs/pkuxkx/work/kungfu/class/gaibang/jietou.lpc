// modified by Zine 5/5/2011 for Gaibang Newbie Job

#include <ansi.h>
inherit NPC;
#include "bonus.h"
#include "gb_extra_job.h"
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",MAG "丐帮弟子" NOR);
        set("gender", "男性");
        set("age", random(45)+25);
        set("long",
                tmp[0]+"是丐帮在江北的一名弟子，负责打听金国的消息。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);
		set("random_npc",1);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);

        set("combat_exp", 100000);
        set("score", 20000);
		set("random_npc",1);
        set_skill("force", 120); // 基本内功
        set_skill("huntian-qigong", 120); // 混天气功
        set_skill("strike", 125); // 基本掌法
        set_skill("xianglong-zhang", 120); // 降龙十八掌
        set_skill("dodge", 120); // 基本躲闪
        set_skill("xiaoyaoyou", 120); // 逍遥游
        set_skill("parry", 120); // 基本招架
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	    map_skill("parry", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
	    map_skill("blade", "liuhe-dao");

        prepare_skill("strike", "xianglong-zhang");
        
        create_family("丐帮", 19, "三袋弟子");
        set("shen_type",1);set("score",1000);setup();
		carry_object("/d/gaibang/obj/cloth")->wear();
}

void init()
{
    add_action("do_jietou","jietou");
}

int do_jietou(string arg)
{
    object paper,ob=this_object();
    object me=this_player();
    string *ids=ob->parse_command_id_list();
    
    if (!arg)
    {
        tell_object(me,"你要和谁接头？\n");
        return 1;
    }
    if (member_array(arg,ids)==-1)
    {
        tell_object(me,"你要和谁接头？\n");
        return 1;
    }
    if (me->query_temp("gbnewbiejob/pin")==ob->query_temp("gbnewbiejob/pin")
        ||me->query_temp("gbnewbiejob/extra")==1
        ||me->query_temp("gbnewbiejob/target")==ob)
    {
        paper=new(__DIR__"newbie_job/info");
        paper->set("owner",me);
        paper->move(me);
        message_vision("$N把一叠"+paper->query("name")+"交给了$n。\n",ob,me);
        extra_job(me,1);
        command("say 兄弟，果然不愧是长老派来的人啊。\n");
        message_vision("$N一闪身，向黑暗中消失了。\n",ob);
        tell_object(me,HIR+"如果你觉得没有把握把这份情报送到下一个人手里，回帮交给鲁长老也可以。\n送到指定的人手中会有额外的奖励。\n"+NOR);
        destruct(ob);
        return 1;    
    }
    else
    {
        message_vision("$N看了看$n，无奈地笑了笑。\n",ob,me);
        return 1;
    }
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
    }
    return 1;
}

int accept_object(object me, object ob)
{
	
    if (me->query_temp("gbnewbiejob/extra")==2&&ob->query("owner")==me
        &&ob->query("gb_newbie_is_qingbao")
        &&this_object()->query_temp("gbnewbiejob/pin")==me->query_temp("gbnewbiejob/pin"))
    {
        message_vision("$N对$n点了点头。\n",this_object(),me);
        message_vision("$N一闪身，向黑暗中消失了。\n",this_object());
        bonus(me);
        call_out("dest",1);
        return 1;
    }
    else
    {
        return notify_fail("这是什么玩意？\n");
    }
}