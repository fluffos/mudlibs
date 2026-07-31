//Cracked by Roath
// zhixiang.c 制香道长 
// Marz@XKX, 11/11/96
// xQin 04/01

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();
void greeting(object);
int do_say(string);
//int do_kill(string);

void create()
{
        set_name("制香道长", ({ "zhixiang daozhang", "zhixiang", "zhixiang daozhang", "zhixiang", "daozhang" }));
        set("nickname", "制香道长");
        set("long",
                "他就是冲虚的师弟凌虚。\n"
                "他四十多岁，职位制香道长，负责制造香火，兼收香火钱。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 18000);
        set("max_jing", 18850);
        set("neili", 122500);
        set("max_neili", 12500);
set_temp("no_kill",1);
set("no_get",1);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("score", 6000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 180);
        set_skill("dodge", 160);
        set_skill("tiyunzong", 160);
        set_skill("strike", 180);
        set_skill("taiji-quan",180);
        set_skill("parry", 160);
        set_skill("sword", 150);
        set_skill("literate", 150);
        set_skill("taoism", 150);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");

        set("inquiry", 
                ([
                        "香火" : "香火练制不易，不能随便于人，虔诚奉献者方能得之。\n",
                        "进香" : "进香？童言无忌！童言无忌！要说敬香才是！\n",
                        "敬香" : "殿堂的香火能绵延不断，都因为我武当弟子和山外香客及时敬奉。\n",
                        "虔诚奉献" : "虔诚奉献就是主动多捐献香火钱，多作义工。\n",
                        "敬奉" : "敬奉就是主动多捐献香火钱，多作义工。\n",
                        "松林" : "武当松林在山门附近。\n",
                        "柏林" : "武当柏林就在遇真宫后。\n",
                        "材料" : "材料就是红松和青柏，我每天都要派人去砍伐。\n",
                        "job" : (: ask_job :),
                        "砍树" : (: ask_job :),
                        "伐木" : (: ask_job :),
                        "工作" : "我这里每天都需要人去砍树，如果你能主动送些过来，那更好。\n",
                        "干活" : "我这里每天都需要人去砍树，如果你能主动送些过来，那更好。\n",
                ]));
                                
        set("wanted", ({ HIR"红松树干"NOR }));

        set("chat_chance", 5);
        set("chat_msg", ({
                "道长说道：香火练制不易，不能随便于人，虔诚奉献者方能得之。\n",
                "道长说道：红松和青柏都是炼制香火的好材料。\n",
                "道长说道：制香材料是从林子里砍伐而来。\n",
                "道长说道：武当的松林和柏林都长了几百年了，还没有人走通过。\n",
                "道长说道：砍树的时候要多加小心，我派出砍树的道士，有些就有去无回。\n",
        }) );

        setup();
      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void init()
{
        object me = this_player();
        
        ::init();

//        add_action("do_kill", "kill");

}

string ask_job()
{
        object ob;
object killer;
int k;
        string what;
        string *wanted;

        ob = this_player();

        if ( ob->query("job/supervisor") )
        {
                command("say 你第一份活儿都没做完就想做第二份？");

                if ( ob->query("job/supervisor") == "制香道长") 
                {
                add_action("do_say", "say");
                return ("如果你干不了我派给你的活，可以直接跟我说你干不了。");
                }
                
                return ("如果你干不了，可以直接去告诉"+ob->query("job/supervisor"));    
        }

        if ((int)ob->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你办事不利,等会再来!\n", this_object(), ob);
                return ("先去做别的事吧!");
            }

//        if (query_temp("stock") > 10)
//                return ("你来晚了，今天的活儿我都分派完了。");

//        add_temp("stock", 1);

        wanted = query("wanted");
        what = wanted[random(sizeof(wanted))];

        ob->set("job/supervisor", "制香道长");
        ob->set("job/object", what);
        ob->set("job/description", what);
        ob->set("job/wage", 3);
        ob->set_temp("apply/short", 
                ({ HIW"武当伐木　"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
                                

//if (1)
if (random(40)==1)
{
        message_vision("听说松林中有不明身份的武林人物来和武当挑衅！小心一点。\n", ob);
killer=new(__DIR__"killer",1);
if ((int)ob->query_skill("force",1) > 10)
{
k=(int)ob->query_skill("force",1);
}
else k=10;
      killer->move("/quest/menpaijob/wudang/zx/pine_forest"+(random(9)+1));
        killer->set("combat_exp",ob->query("combat_exp"));
        killer->set("qi", ob->query("max_qi"));
        killer->set("eff_qi", ob->query("max_qi"));
        killer->set("max_qi", ob->query("max_qi"));
        killer->set("jing", ob->query("max_jing"));
        killer->set("eff_jing", ob->query("max_jing"));
        killer->set("max_jing", ob->query("max_jing"));
        killer->set("neili", ob->query("max_neili"));
        killer->set("max_neili", ob->query("max_neili"));
        killer->set_skill("xue-dao", k);
        killer->set_skill("unarmed",k);
        killer->set_skill("xianglong-zhang",k);
        killer->set_skill("dodge", k);
        killer->set_skill("blade", k);
        killer->set_skill("parry", k);
        killer->set_skill("dashou-yin", k);
        killer->set_skill("shenkong-xing", k);
        killer->set_skill("longxiang", k);
        killer->set_skill("huntian-qigong", k);
}
        message_vision("制香道长高兴对$N说道：来得正好，这里正缺人手！\n", ob);
        return ("我需要"+ what +"造香用，你去给我砍些来吧！\n");
}

int accept_object(object who, object ob)
{

        object obn, wage;       
        int i, j, k,l;
        int exp,pot;
        string *wanted;

                if (ob->query("money_id") )     
        {
                if ((string)(who->query("family/family_name")) == "武当派") 
                        tell_object(who, 
                        "道长对你赞叹道：武当山香火鼎盛，全靠象道兄这样捐献香火啊！\n");
                else  
                        tell_object(who, 
                        "道长对你赞叹道：武当山香火鼎盛，全靠象您这样的虔诚香客啊！\n");

                return 1;
        } else if (  ((string)who->query("job/supervisor") == "制香道长")
                        && (string)who->query("job/object") == (string)ob->query("name") )   
        {
                i = (int)who->query("wdjob/wage");
                l = (int)who->query("wdjob/wage");
                if (i < 0 ) i = 2;
                if (i > 800) i=800;
                wage = new("/clone/money/silver");
k=random(i);
                if (k < 0 ) k = 2;
if (k>80)k=80;
                wage->set_amount(k);
                wage->move(who);

                command("say 有劳这位"+RANK_D->query_respect(who)+"了。");
                command("thumb " + who->query("id"));
if (random(10)<2)
{
               message_vision("$N通过为武当做事，提高了对武当的忠心。\n", who);
               who->add("guarded",1);
}
                message_vision("制香道长给$N"+chinese_number(k)+"两白银作为工作报酬。\n", who);
                j=random(i);
if ((string)(who->query("family/family_name")) == "武当派") 
{
if ((20+j) < 50)
exp =90;
if ((20+j) > 200)
exp =300;
if (exp <90 ) exp=90;
if (exp >350) exp=350;
                who->add("combat_exp", exp);
                who->add("potential", exp*2/3);
                message_vision("$N的修为加了"+chinese_number(exp)+"点。\n", who);
                message_vision("$N的潜能加了"+chinese_number(exp*2/3)+"点。\n", who);
                message_vision("$N武当制香任务做了"+chinese_number(l)+"次了。\n", who);
}
                who->delete_temp("jobwd");
                who->delete_temp("apply/short");
                who->add("wdjob/wage", 1);
                who->delete("job/supervisor");
                who->delete("job/description");
                who->delete("job/wage");
                who->delete("job/object");
                who->start_busy(4);
                return 1;
        } else if( (int)member_array((string)ob->query("name"), (string *)query("wanted")) != -1 )    
        {
                
                message_vision("制香道长高兴对$N说道：来得正好，这正是我所需要的！\n", who);

    
                if ( who->query("family/family_name") == "武当派"  )
                {
                        if ( random(2) ) 
                        {
                                tell_object(who, "我这有新制香火一枝，你拿去贡奉吧。\n");
                                who->add("wudang/offerring", -1-random(3));
                                obn = new(__DIR__"incense");
                                obn->move(who);
                        }
                        
                }

                who->delete_temp("jobwd");
                command("say 你如此自愿为武当效力，日后必成武当栋梁！");
                command("thumb " + who->query("id"));
                
                return 1;
        }


        return 0;
}


int do_say(string arg)
{
    object ob, who;

    who = this_player();
    ob = this_object();

        if ( (string)arg != "干不了") return 0;

    if ( who->query("job/supervisor") != ob->query("name")) return 0;

    message_vision("$N低声说道：道长分派的活我干不了…\n", who);
    command("pat "+ who->query("id"));
    command("say 没关系，下此好好干！");

who->apply_condition("menpai_busy",2+random(4));
                who->delete_temp("jobwd");
    who->delete_temp("apply/short");
    who->delete("job/supervisor");
    who->delete("job/description");
    who->delete("job/wage");
    who->delete("job/object");

    return 1;
}

