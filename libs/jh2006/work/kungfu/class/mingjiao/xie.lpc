// NPC xie.c 谢逊
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_dao();
string ask_boat();
void create()
{
        object ob;
        set_name("谢逊",({"xie xun","xie","xun"}));
        set("title","明教护教法王");
        set("nickname",HIY"金毛狮王"NOR);
        set("long", "他就是明教的四大护法之一的金毛狮王。\n"+
                    "他身材魁伟异常，满头金发散披肩头。但双目已瞎。\n"+
                    "在你面前一站，威风凛凛，真如天神一般。\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -13000);
        set("str", 30);
        set("per", 16);
        set("int", 29);
        set("con", 35);
        set("dex", 27);        
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 70);
        set("combat_exp", 1350000);
        set("unique", 1);

        set_skill("cuff",160); 
        set_skill("dodge",160);
        set_skill("force", 160);
        set_skill("blade",160);
        set_skill("literate",110);
        set_skill("piaoyi-shenfa", 160);
        set_skill("qishang-quan",180);
        set_skill("hunyuan-yiqi", 160);
        set_skill("parry", 160);
        set_skill("lieyan-dao",160);        
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "qishang-quan");
        map_skill("blade", "lieyan-dao");
        prepare_skill("cuff","qishang-quan");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "strike.qishang" :),
                (: exert_function, "roar" :),
	}));

        set("inquiry", ([
                 "张无忌"  : "他是我的义子，我已很久没有见到他了。",
                 "七伤拳经" : (: ask_me :),
                 "屠龙刀"  : (: ask_dao :),
                 "船"  : (: ask_boat :),
                 "船舶"  : (: ask_boat :),
                 "造船"  : (: ask_boat :),
                 "中原"  : (: ask_boat :),
                 "成昆"  : "他就是我那狗贼师傅，他杀了我一家四口，此仇不共戴天！",
        ]));

        create_family("明教", 36, "法王");
        setup();
        if (clonep()) {
                ob = unew(BINGQI_D("tulong-dao"));             
                if (ob){
                    ob->move(this_object());
                    ob->wield();
                    }
                carry_object(ARMOR_D("xiongpi"))->wear();
        }  
}

void attempt_apprentice(object ob)
{     
        command("say 老夫不收弟子。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}

void kill_ob(object me)
{        
        command("stare "+me->query("id"));
        ::kill_ob(me);
}

string ask_me()
{
        mapping fam; 
        object me = this_player();
        if (!(fam = me->query("family")) || fam["family_name"] != "明教")
                return "七伤拳经？没听说过。";
        if (fam["master_name"] != "张无忌")
                return RANK_D->query_respect(me)+"还是请回吧，你说的是崆峒派的绝技，我怎么会知道？";
        if (me->query("xie_qishang"))
                return "我不是已经传了你这拳经了吗？怎么还要问！";
        if (!me->query_temp("marks/七伤"))
                return "我这七伤拳经除了我义子，不传外人！";
        command("consider");
        command("say 无忌这孩子，怎么可将七伤拳传予他人呢！");
        command("say 也罢，无忌既然让你来到这里，我就传了你吧。");
        me->set("xie_qishang", 1);
        me->delete_temp("marks/七伤");
        me->add("max_jingli", 50);
        me->add("max_neili", 50);
        command("whisper "+me->query("id")+" 五行之气调阴阳，损心伤肺摧肝肠，藏离精失意恍惚，三焦齐逆兮魂魄飞扬！");
        return "你回去吧。";
}

string ask_boat()
{ 
        object me = this_player();
        if (!me->query("xie_qishang")) return "船？这极北冰火岛离开中原万里，哪来的船舶？";
        command("say 当年我帮义弟义妹他们在后山丛林中砍伐(chop)树木，然后才搬到海边造船(make)。");
            return "也不知道现在他们和我那无忌孩儿都怎么样了。";
}

string ask_dao()
{
        mapping fam; 
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player())+"与本教素无来往，不知此话从何谈起？";
        if(present("tulong dao",this_object())){
           command("wield dao");
           command("say 武林至尊，宝刀屠龙，号令天下，莫敢不从，倚天不出，谁与争锋。");
           write("\n谢逊棒着屠龙宝刀，低头冥思刀口之秘。\n\n");
           this_player()->set_temp("xie_tld", 1);
           return "不寻到宝刀中之秘，我之大仇如何得报？唉......";
        }
        else return "武林至尊，宝刀屠龙，号令天下，莫敢不从！";
}

int accept_object(object who, object ob,object me)
{
       me=this_object();
       if(ob->query("name") != "成昆的首级" || ob->query("id") != "shouji") {
               command("say 老夫对这样东西没什么兴趣……");
               return 0;
       }            
       if(ob->query("victim_user")) {
               command("say 这不是成昆！这不是成昆！");
               return 0;
       }      
       command("say 啊……成昆的人头！ 成昆的人头！");
       command("chat 哈哈哈！……成昆的人头！ 成昆的人头！");
       call_out("destroy", 1, ob);
       if(ob->query("kill_by") != who){
               command("say 但他好象不是你杀的吧？你是怎么得到这块人头的？");
               return 1;
       }     
       if(who->query_temp("xie_tld") && present("tulong dao",me)){
           command("say 你让我大仇得报，这把刀就算我的谢礼，只可惜不能手刃了那恶贼。");           
           command("give tulong dao to "+who->query("id"));
           who->delete_temp("xie_tld");
           return 1;
       }
       else{
           command("say 你让我大仇得报，这只熊掌算是我的谢礼吧，只可惜不能手刃了那恶贼。");
           message_vision("$N交给$n一块烤熟的熊掌。\n", me, who);
           new(FOOD_D("xzhang"))->move(who);
           return 1;
      }
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
