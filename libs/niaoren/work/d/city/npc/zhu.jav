// zhu.c 朱熹

inherit NPC;
inherit F_DEALER;

string ask_buy();
void create()
{
        set_name("朱熹", ({ "zhu xi", "zhu" }));
        set("long",
"朱先生被稱為當世第一大文學家，肚子里的墨水比海還要深。\n");
        set("gender", "男性");
        set("age", 65);
        set_skill("literate", 300);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
        "買書": (:ask_buy:),
        "書" : "唉!書到用時方恨少。",
        "借書":"借？你不還我到哪里找你？哼!",
        ]));
        set("vendor_goods", ({
                __DIR__"obj/lbook1",
                __DIR__"obj/lbook2",
                __DIR__"obj/lbook3"
        }));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "朱熹說道：普天之下，莫非王土﹔率土之濱，莫非王臣。\n",
                "朱熹說道：出家人，小過損益焉﹔無妄大過，未濟咸困之。\n",
                "朱熹說道：大學之道，在明明德。在親民，在止于至善。 \n",
                "朱熹說道：格物致知，誠意正心，修身齊家，治國平天下。\n",
        }) );
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/朱"))
                return 0;
        ob->add_temp("mark/朱", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if (!(int)who->query_temp("mark/朱"))
                who->set_temp("mark/朱", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("朱熹同意指點$N一些讀書寫字的問題。\n", who);
                who->add_temp("mark/朱", ob->value() / 50);
        if( me->query_skill("literate", 1) > 21){
        tell_object(me,
"你現在已有一定的文化知識,也可以自己讀書深造了。\n");
        return 1;}
                return 1;
         }
}

string ask_buy()
{
//      int i;
        return "我這可有不少讀書人必讀的書喲!\n";
//        i = (int)me->query_temp("ask_book");
}

void init()
{
        object me = this_player();
        add_action("do_list","list");
        if( me->query_skill("literate", 1) > 21)
        add_action("do_buy", "buy");
        return ;
}
