// que.c 虚竹
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
void do_zoutiesuo(string);

void create()
{
    set_name("虚竹", ({ "xu zhu", "xu" }));
    set("long",
            "这是一个二十五六岁的年轻人, 长得颇为丑陋,\n"+
            "他浓眉大眼，鼻孔上翻，双耳招风，嘴唇甚厚。 \n"+
            "身穿长袍，乃是以一条条锦缎缝缀而成，红黄\n"+
            "青紫绿黑各色锦缎条纹相间，袖口衣领之处，\n"+
            "更镶以灰色貂皮,华贵之中具见雅致。\n");
    set("nickname", RED "梦郎" NOR );
    set("title", HIC"灵鹫宫尊主"NOR);
    set("gender", "男性");
    set("per", 16);
    set("age", 26);
    set("shen_type",1);
    set("attitude", "peaceful");

    set("str", 30);
    set("int", 25);
    set("con", 40);
    set("dex", 30);

    set("max_qi", 4000);
    set("max_jing", 1200);
    set("neili", 8000);
    set("max_neili", 8000);
    set("jiali", 160);
    set("combat_exp", 2500000);
    set("score", 5000);
    
    set_skill("literate",150);
    set_skill("force", 250);
    set_skill("bahuang-gong", 150);
    set_skill("duzun-xinfa", 150);
    set_skill("dodge", 250);
    set_skill("parry", 250);
    set_skill("hand",280);
    set_skill("strike", 280);
    set_skill("zhemei-shou",250);
    set_skill("liuyang-zhang",250);
    set_skill("lingbo-weibu",200);
    set_skill("tianyu-qijian", 200);
    set_skill("beiming-shengong",250);
    set_skill("xiaowuxiang-gong",200);
    set_skill("throwing",180);

    map_skill("force", "beiming-shengong");
    map_skill("strike","liuyang-zhang");
    map_skill("dodge", "lingbo-weibu");
    map_skill("hand", "zhemei-shou");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword", "tianyu-qijian");


    prepare_skill("strike","liuyang-zhang");
    prepare_skill("hand","zhemei-shou");

    create_family("灵鹫宫",2,"尊主");

    set("chat_msg_combat", ({
                (: perform_action, "strike.zhong" :),
                (: perform_action, "hand.duo" :),
                (: perform_action, "sword.changhen" :),
                (: command("unwield jian") :),
                (: command("wield jian") :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: command("unwield jian") :),
                (: command("wield jian") :),
                }) );

    setup();
    carry_object("/d/lingjiu/obj/changpao")->wear();
    carry_object("/clone/weapon/jian")->wield();
    add_money("silver",50);
}

void init ()
{
    object me;
    set("inquiry", ([
                "梦姑" :(:ask_me:),
                ]));
    me = this_player();
    if (interactive(me) && !is_fighting()) {
        remove_call_out("greet");
        call_out("greet", 1, me);
    }
}

void greet(object me)
{
    object ob=this_object(),she,room;
    if ((me->query_temp("lingjiu/find")==2) && (present("princess", environment(me))))
    {
        command("follow none");
        message_vision("虚竹走上前去，仔细端详了梦姑一眼，说道：“梦姑，苍天有眼，我终于找到你了”\n",me);
        me->set("lingjiu/found",1);
        me->delete_temp("lingjiu/find");
        message_vision("虚竹对$N说道：“你先回去吧，等我带梦姑回去后再好好谢你”\n",me);
        message_vision("虚竹和梦姑转身一起走出了房间。\n",me);
        me->delete_temp("lingjiu/leading");
        room = load_object("/d/lingjiu/zhengting");
        ob->move(room);
        she = present ("princess",environment(me));     
        destruct(she);
    }
    return;
}
int ask_me()
{
    object me=this_player();
    if (me->query("lingjiu/found"))
    {
        command("say 梦姑现在就和我生活在一起，这位"+RANK_D->query_respect(me)+",多谢你了！\n");
        return 1;
    }
    if (me->query_temp("lingjiu/find"))
    {
        command("say 这位"+RANK_D->query_respect(me)+",你不是已经答应去给我找梦姑了吗？\n");        return 1;
    }
    if ((string)me->query("family/family_name") == "灵鹫宫" )
        command("say 这位"+RANK_D->query_respect(me)+",你如果能给我找会梦姑，我就收你为徒！\n");
    else
        command("say 这位"+RANK_D->query_respect(me)+",你如果能给我找会梦姑，我必有重谢！\n");          
    me->set_temp("lingjiu/find",1);
    return 1;

}


void attempt_apprentice(object me)
{
    if (!me->query("lingjiu/found"))
    {
        command("say 我找不到梦姑，哪里有心情收什么徒弟呢？");
        return;
    }
    if ((string)me->query("family/family_name") != "灵鹫宫" &&
            !me->query("lingjiu/getten") )
    {
        object book;
        command("say "+RANK_D->query_respect(me)+",感谢你帮我找到了梦姑，我这里有一本金庸先生签过名的天龙八部，就送给你吧！");
        message_vision("虚竹给了$N一本精装的天龙八部”\n",me);
        book=new("/d/lingjiu/obj/tlbb");
        book->move(me);
        me->set("lingjiu/getten",1);  
        return;
    }
    if ((int)me->query_skill("bahuang-gong", 1) < 120) 
    {
        command("say " + RANK_D->query_respect(me) + "是否还应该在八荒功上多下点功夫？");
        return;
    }
    if (me->query_con() < 25) 
    {
        command("say 本门功法极为难练,你的根骨似乎不够.");
        return;
    }
    if  ((int)me->query("family/generation") < 3 )
    {
        command("say " + RANK_D->query_respect(me)+ "已是童姥的弟子，何必来向我请教。\n");
        return;
    }
    if  ((int)me->query("score") < 1000 )
    {
        command("say " + RANK_D->query_respect(me)+ "对本门的贡献不够，我暂时不能收你。\n");
        return;
    }
    command("say 好吧，"+RANK_D->query_respect(me)+"！我就收下你了！\n");
    command("recruit " + me->query("id"));
    return;
}

void recruit_apprentice(object me)
{
    if( ::recruit_apprentice(me) )
        me->set("title",MAG "灵鹫宫" NOR + HIG +"首领" NOR); 
    return;
}


int accept_object(object me,object ob)
{
    if ((string)ob->query("id") == "letter")
        if (me->query_temp("lingjiu/find") == 2)
        {
            message_vision("虚竹接过信，打开看了一遍。\n", me);
            message_vision ("虚竹自言自语地说“终于有梦姑消息了！”\n",me);
            command("say 多谢这位" + RANK_D->query_respect(me) + "。梦姑她现在在哪里？你带我去好吗？");
            me->set_temp("lingjiu/leading",1);
            command("follow " + me->query("id"));
        }
        else    {
            message_vision("虚竹接过信，狐疑地看了你一眼，说道：「这信不是梦姑亲手交给你的吧？」\n",me);
        }

    return 1;
}

void do_zoutiesuo(string arg)
{
    command("zou "+arg);
    return;
}
