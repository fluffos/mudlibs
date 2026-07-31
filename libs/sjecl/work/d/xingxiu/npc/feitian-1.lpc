// NPC: feitian.c 飞天子
// Modify By Looklove 2000/10/17
// Modify by leontt 2000/10/22

inherit NPC;
inherit F_MASTER;

string ask_fen(object);
string ask_biao();

void create()
{
        set_name("飞天子", ({ "feitian zi", "feitian", "zi" }) );
        set("gender", "男性" );
        set("nickname", "星宿派七师兄");
        set("age", 28);
        set("long", "他绰号飞天，轻功的造诣已经到了很高的地步。\n");
        set("env/wimpy", 40);
        set("str", 20);
        set("dex", 30);
        set("con", 19);
        set("int", 15);
        set("shen", -1400);
        set("biao", 10);
        create_family("星宿派", 2, "弟子");
                                                       
        set_skill("huagong-dafa", 40);
        set_skill("strike", 30);
        set_skill("chousui-zhang", 30);
        set_skill("force", 40);
        set_skill("dodge", 50);
        set_skill("zhaixingshu", 60);
        map_skill("dodge","zhaixingshu");
        map_skill("force","huagong-dafa");
        map_skill("strike","chousui-zhang");
        map_skill("parry","chousui-zhang");
        prepare_skill("strike", "chousui-zhang");

        set("combat_exp", 80000);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("attitude", "peaceful");
        set("inquiry", 
                ([
                      "毒虫粉" : (: ask_fen,"yao" :),
                      "冰魄粉" : (: ask_fen, "yao3" :),
                      "红磷粉" : (: ask_fen, "yao2" :),
                      "银磷粉" : (: ask_fen, "yao1" :),
                      "追魂镖" : (: ask_biao :),        
                      "biao" : (: ask_biao :),
                ]));
        
        setup();
        carry_object(ARMOR_D("pink_cloth"))->wear();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        mapping myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "星宿派") command("bow " + me->query("id"));
        else if(me->query("combat_exp") < 100000) command("hmm " + me->query("id")); 
        else command("hi " + me->query("id"));
}
void attempt_apprentice(object ob)
{
    command("hehe");
    command("say 我可没功夫来教你。");
    return;
}

string ask_biao()
{
        object ob = this_player(),obj;
 
        if (ob->query("family/family_name") != "星宿派")
                return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

        if (ob->query("combat_exp") < 400000)
                return RANK_D->query_respect(ob) + "功夫太差，给你也是浪费，还是留给其他人吧。";
 
        if (this_player()->query("max_neili") < 1000)
                return RANK_D->query_respect(ob) + "功力不够，灵药多吃有害无宜，过段时间再来吧。";

        if (present("zhuihun biao", ob))
                return RANK_D->query_respect(ob) + "你现在身上不是有吗，怎么又来要了？真是贪得无厌！";
        if (ob->query_temp("zh/busy")>0)
                return RANK_D->query_respect(ob) + "你刚刚要过，怎么又来要了？真是贪得无厌！";

        if (query("biao") < 1) return "对不起，追魂镖已经发完了，你不用再等了。";
 
        obj = new("/clone/weapon/zh_biao");
        obj->move(ob);
        ob->set_temp("zh/busy", 1);
        add("biao", -1);
 
        call_out("delete_zhbiao", 600, ob);

        message_vision("$N得到一枚追魂镖。\n", ob);
        return "好吧，见你这么乖巧，这枚追魂镖就送给你吧。";
}

void delete_zhbiao(object me)
{
        if ( objectp(me) ) me->delete_temp("zh/busy");
}

string ask_fen(string name)
{
        object me;
        me = this_player();
        
        if ( me->query("family/family_name") != "星宿派")
                return RANK_D->query_respect(me) + 
                "你不是我星宿弟子，此话从何说起？";
              
        if ((int)me->query_skill("huagong-dafa",1) < 80)
                return RANK_D->query_respect(me) + 
                "你的化功大法不够，用不上这些东西，别给老仙丢脸。";
                
        if ((int)me->query_temp("fen/asked")>8){
                call_out("delete_fen", 60, me); 
                return "刚才你不是问过了么？";
        }
        
        new("/d/xingxiu/obj/"+name)->move(me);
        me->add_temp("fen/asked",1);
        message_vision("飞天子神色诡异，给了$N一个小纸包。\n",me);
        return "嘿嘿。拿去吧，这可是好东西。";
}

void delete_fen(object me)
{
        if (objectp(me)) me->delete_temp("fen/asked");
}

