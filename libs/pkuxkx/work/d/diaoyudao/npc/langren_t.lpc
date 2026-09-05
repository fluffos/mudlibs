// langren_t.c
//cgbii 96.10.4

inherit NPC;

int ask_me();

void create()
{
        set_name("浪人头目", ({ "langren tou", "tou" }) );
        set("gender", "男性" );
        set("age", 51);
        set("long",
         "此人一脸彪悍之色，面上好大的一条刀疤，十足的武士派头。\n");

        set_skill("blade", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set("combat_exp", 20000);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("shen", -2000);
        set("str", 28);
        set("dex", 25);
        set("con", 20);
        set("int", 20);
        set("attitude","heroism");
        set("inquiry", ([
                "老船家" : "就是我抢了那老家伙的东西又怎样.....\n",
                "东西" : "不就是条破烂珍珠项链呗！\n",
                "珍珠项链" : (: ask_me :),
        ]) );
        setup();
        carry_object(__DIR__"obj/wushi_dao")->wield();
        carry_object(__DIR__"obj/he_fu")->wear();
}
void init()
{
        ::init();
        add_action("do_bihua", "bihua");
}

int ask_me()
{
        say(
"浪人头目瞄了" + this_player()->name() + "一眼，满不在乎的说道：\n"
"不错，东西是我抢的，你要怎麽样!  你们中原武士没有多少本事，来了\n" 
"这么多个都是送死的，嘿!  你不服气? 那好，咱俩来决斗，你又本事打\n"
"赢了，我马上还给你东西。 你要输了，就死啦死啦的！嘿！怎麽着，敢\n"
"不敢比划(bihua)几下?\n");
        return 1;
        
}

int do_bihua()
{
        object me, obj, lian;
        int current_qi;
        me = this_object();
        obj = this_player();
        lian = new(__DIR__"obj/xianglian");
        current_qi = (int)me->query("qi");
        say(obj->name() + "对浪人头目说：好吧，那" + RANK_D->query_self_rude(obj) + 
"就同你这萝卜头见个高低。\n");
              while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 50) { 
                        if ( !present(obj, environment()) )
                                return 1;
                        COMBAT_D->do_attack(obj, me, query_temp("weapon"));
                        if (((int)me->query("qi")*100/current_qi)< 50) {
                                say(
"浪人头目对" + obj->name() + "说道：今儿您赢了我，不代表我们大和民族败\n"
"       给你，你给我记住！！天皇万岁..万岁...万.....\n"
                                );
                                lian->move(obj);
                    message_vision("$N交给$n一条项链之后就用武士刀剖腹自尽了。\n", me, obj);
                    me->die(); 
                                return 1;
                        }
                    COMBAT_D->do_attack(me, obj);
                }
                say(
"浪人头目冲着" + obj->name() + "恶恨恨的道：就凭你这点本事还敢来跟\n"
"别人出头，今天我就要你的小命！八格牙路！你别跑!\n"
                );
                message("vision",
obj->name() + "吓得屁滚尿流，拚命的往城里逃了过去。\n", environment(obj), ({obj}) );
                obj->move("/d/diaoyudao/matou0");
                message("vision",
obj->name() + "从码头那边连滚带爬的逃了过来，样子十分狼狈。\n", environment(obj), ({obj}) );

                return 1;
        
}
