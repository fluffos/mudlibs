// modified by Zine 5/5/2011 for Gaibang Newbie Job

#include <ansi.h>
#include <title.h>
#include "bonus.h"
#include "gb_extra_job.h"
inherit NPC;
//inherit F_AQUESTMASTER;
inherit F_MASTER;
       string ask_me();

void consider();
int ask_job();
int ask_fail();
void create()
{
        set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
        set("title",MAG "丐帮" NOR + YEL "九袋" NOR+ MAG "长老" NOR);
        set("nickname", GRN "掌棒龙头" NOR);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
                "因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 120); // 基本内功
        set_skill("huntian-qigong", 120); // 混天气功
        set_skill("strike", 125); // 基本掌法
        set_skill("xianglong-zhang", 120); // 降龙十八掌
        set_skill("dodge", 120); // 基本躲闪
        set_skill("xiaoyaoyou", 120); // 逍遥游
        set_skill("parry", 120); // 基本招架
        set_skill("staff", 115); // 基本棍杖
	set_skill("blade", 120);
	set_skill("liuhe-dao", 110);
        set_skill("begging", 100);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-dao");

        prepare_skill("strike", "xianglong-zhang");
        set("inquiry",
                ([
                        "棒法秘籍" : (: ask_me :),
                        "job" : (: ask_job :),
                        "任务" : (: ask_job :),
                        "fail" : (: ask_fail :),
                        "失败" : (: ask_fail :),
                ]));
        set("book_count", 2);

        create_family("丐帮", 18, "九袋长老");
        set("shen_type",1);set("score",10000);setup();
		carry_object("/d/gaibang/obj/cloth")->wear();
}

void init()
{
    add_action("do_answer","answer");
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    object tasks,target,where,thing;
    mapping new_task=ZQUEST_D->get_quest();
    string targetfile,rm,item_name,item_id;
    int times=0,n=random(100);
    int pin=1+random(10000);
    string *color=({HIR,RED,HIW,WHT,MAG,HIM,HIC,CYN,HIB,BLU,HIG,GRN,HIY,YEL});
    string *desc=({"为富不仁","祸害乡里","偷鸡摸狗","唯利是图","寡廉鲜耻"});
    if (me->query("family/family_name")!="丐帮")
    {
        command("say 阁下不是我帮弟子，这是何意？");
        return 1;
    }
    if (!me->query("is_beggar"))
    {
        command("say 你不是污衣派弟子，去看看彭长老有没有活吧。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        command("say 等你忙完再来找我吧。");
        return 1;
    }
    if (me->query_temp("gb_newbie_finish"))
    {
        command("say 你打探到的消息还没有回复(answer)我呢。");
        return 1;
    }
    if (me->query("gbnewbiejob/start"))
    {
        command("say 你上次任务还没有完成呢！");
        return 1;
    }
    if (time()-me->query("gbnewbiejob/lasttime")<120)
    {
        command("say 你刚刚做过任务，先去休息一会吧。");
        return 1;
    }
    else
    {
        if ((int)me->query("gbnewbiejob/times")%2==0)
        {
            extra_job(me,0);
            return 1;
        }
        while (!find_living(new_task["id"])||time()-(int)find_living(new_task["id"])->query("questtime")<900||
            (find_living(new_task["id"])&&environment(find_living(new_task["id"]))&&base_name(environment(find_living(new_task["id"])))!=find_living(new_task["id"])->query("startroom")))
        {
            times+=1;
            if (times>10)
            {
                command("say 我略感不适，你片刻之后再来吧。");
                return 1;
            }
            new_task=ZQUEST_D->get_quest();
        }
        target=find_living(new_task["id"]);
        where=environment(target);
        if (!where||TASK_D->place_belong(where)=="未知区域"||TASK_D->place_belong(where)=="不明区域")
        {
            me->delete("gbnewbiejob/start");
            me->delete_temp("gbnewbiejob");
            command("say 我暂时没什么事，你迟点再来吧。");
            return 1;
        }
        me->set_temp("gbnewbiejob/pin",pin);
        me->set("gbnewbiejob/start","steal");
        me->set("gbnewbiejob/lasttime",time());
        me->set_temp("gbnewbiejob/steal",1);
        me->set_temp("gbnewbiejob/target",target);
        
        n=random(sizeof(color));
        thing=new(__DIR__"newbie_job/item");
        item_name=color[n]+new_task["item"]+NOR;
        item_id=new_task["item_id"];
        thing->set_name(item_name,({item_id,}));
        thing->set("long",new_task["item_desc"]);
        thing->set("stealby",0);
        thing->set("pin",pin);
        thing->move(target);
        target->set("questtime",time());
        me->set_temp("gbnewbiejob/item",thing->query("name"));
        me->set_temp("gbnewbiejob/theitem",thing);
        
        message_vision("$N对$n说道："+target->query("name")+"在"+TASK_D->place_belong(where)+desc[random(sizeof(desc))]+"，你去把其身上的"+color[n]+thing->query("name")+NOR+"("+thing->query("id")+")偷(steal)回来交给我。\n",ob,me);
        return 1;
    }
}

int dest(object ob)
{
	if(ob)
	destruct(ob);
	return 1;
}

int accept_object(object me, object ob)
{
	if (me->query("gbnewbiejob/start")
        &&ob->query("pin")
        &&(int)ob->query("pin")==(int)me->query_temp("gbnewbiejob/pin")
        &&ob->query("stealby")==me->query("id"))
    {
        bonus(me);
        this_object()->add_busy(1);
        remove_call_out("dest");
        call_out("dest",1,ob);
        return 1;
    }
    else if (me->query_temp("gbnewbiejob/extra")==2&&ob->query("owner")==me
        &&ob->query("gb_newbie_is_qingbao"))
    {
        command("say 情报拿回来了？也不错啦。");
        me->set_temp("gbnewbiejob/extra",1);
        bonus(me);
        call_out("dest",1,ob);
        return 1;
    }
    else if (ob->query("pin")&&(int)ob->query("pin")!=(int)me->query_temp("gbnewbiejob/pin"))
    {
        command("say 我要去你偷的不是这样东西吧？");
        return 1;
    }
    else if (ob->query("stealby")!=me->query("id"))
    {
        command("say 我让你去偷，不是去抢，乞丐也要有尊严的！");
        return 1;
    }
    else
    {
        return notify_fail("这是什么玩意？\n");
    }
}


int ask_fail()
{
    object me=this_player();
    object ob=this_object();
    
    if (me->query("family/family_name")!="丐帮")
    {
        command("say 阁下不是我帮弟子，这是何意？");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        command("say 等你忙完再来找我吧。");
        return 1;
    }
    if (!me->query("gbnewbiejob/start"))
    {
        command("say 你没接过任务啊！");
        return 1;
    }
    me->delete("gbnewbiejob/start");
    me->delete_temp("gbnewbiejob");
    command("say 没关系，没做到就算了吧。");
    punish(me);
    return 1;
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ((string)ob->query("family/family_name")!="丐帮")
        {
		command("say 我们丐帮需要一袋一袋升，"+ RANK_D->query_respect(ob)+ "先要从一袋弟子做起。");
                return;
        }
        if (ob->query("dai")<8)
        {
               	command("say " + RANK_D->query_respect(ob) + "的袋数不够。不能拜我辈。");
                return;
        }
        if ((int)ob->query("score")<800){
           command("sigh");
           command("say 小兄弟请回吧!我是不会收一个对本帮不忠之人的.");
           return;}
        if (ob->query("dai")== 8 )
        {
        if ( (int)ob->query("int") >= 25 ) {
                command("say 我们丐帮的武艺一向以刚猛为主，" +
                RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
                return;
        }
        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "丐帮" NOR + YEL +"八袋" NOR + MAG "弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;
}
string ask_me()
{
        mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "丐帮")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
  if (this_player()->query("combat_exp")<5000)
             return RANK_D->query_respect(this_player()) +
            "初来乍到，还不能给你棒法秘籍。";
         if (this_player()->query("score")< 100)
             return "你新来乍到，问那么多干什么.";
        if (query("book_count") < 1)
                return "你来晚了，帮主的「棒法秘籍不在此处。";
        add("book_count", -1);
        ob = new("/d/gaibang/obj/staff_book");
        ob->move(this_player());
        return "好吧，帮主的「棒法秘籍」就给你拿回去好好钻研。";
}
 


