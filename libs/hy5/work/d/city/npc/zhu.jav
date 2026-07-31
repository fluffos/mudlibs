// zhu.c 朱熹

inherit NPC;
inherit F_DEALER;

string ask_buy();
void create()
{
        set_name("朱熹", ({ "zhu xi", "zhu" }));
        set("long",
"朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
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
        "买书": (:ask_buy:),
        "书" : "唉!书到用时方恨少。",
        "借书":"借？你不还我到哪里找你？哼!",
        ]));
        set("vendor_goods", ({
                __DIR__"obj/lbook1",
                __DIR__"obj/lbook2",
                __DIR__"obj/lbook3"
        }));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
                "朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
                "朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
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
                message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 50);
        if( me->query_skill("literate", 1) > 21){
        tell_object(me,
"你现在已有一定的文化知识,也可以自己读书深造了。\n");
        return 1;}
                return 1;
         }
}

string ask_buy()
{
//      int i;
        return "我这可有不少读书人必读的书哟!\n";
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
