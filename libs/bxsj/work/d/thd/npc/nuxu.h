int ask_marry()
{
        object nvxu, user;
        
object ob = this_player();
        string id;
        int user_load = 0, user_exist = 1;

        if (ob->query("gender") != "男性" && ob->query("gender") != "女性") {
                command("sneer " + ob->query("id"));
                command("say 你也想娶老婆？下辈子吧！");
                return 1;
        }
        if (ob->query("gender") == "女性") {
                command("say 你当我女儿是同性恋啊？快滚！");
                return 1;
        }
        if (ob->query("class") == "bonze") {
                command("sneer " + ob->query("id"));
                command("say 和尚也动了凡心，想娶老婆？先还俗再说吧！");
                return 1;
        }
        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id) {
                if (id == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
                        say(CYN"黄药师笑道：" + RANK_D->query_rude(ob) + "，还不快叫岳父？！\n"NOR);
                        return 1;
                }
                if (!(user = find_player(id))) {
                        user = new(LOADUSER_OB, id);
                        user->set_name("", ({ id }));
                        if (!user->restore()) {
                                destruct(user);
                                user_exist = 0;
                        }
                        else user_load = 1;
                }
                if (user_exist && nvxu->query("death_count") == user->query("death_count")) {
                        command("say 小女已经许配给" + nvxu->query("name") + "了。");
                        if (user_load) destruct(user);
                        return 1;
                }
                if (user_load) destruct(user);
        }
        if (ob->query("marry")) {
                command("sneer " + ob->query("id"));
                command("say 你不是已经娶了妻子了吗？我最恨负心薄幸的人，再来罗嗦，休怪老夫无理！");
                return 1;
        }
        if ((int)ob->query("shen") <= -200000) {
                command("say 我生平最讨厌两种人，你们这种无恶不作的邪魔外道就是其一，哼！");
                return 1;
        }
        if ((int)ob->query("shen") >= 200000) {
                command("say 我生平最讨厌两种人，你们这种自命大侠的沽名钓誉之徒就是其一，哼！");
                return 1;
        }
        if (ob->query("age") > 49) {
                command("sneer " + ob->query("id"));
                command("say 你这么个糟老头也想做我女婿？干脆我做你女婿算了。\n");
                return 1;
        }
        if (ob->query("age") < 20) {
                command("say 你还小，等长大了再来吧。\n");
                command("pat " + ob->query("id"));
                return 1;
        }
        command("say 好吧，不过我要出三道试题考考你。");
        command("say 第一道是武功，第二道是音律，第三道是默写。");
        command("say 必须三阵都不输掉才行！");
        command("say 要是准备好了就来过第一关吧！");
        ob->set_temp("thd_marry", 1);
        return 1;
}

int ask_test1()
{
        object ob=this_player();
        object me=this_object();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") > 1) {
                command("say 已经过了这关还来罗嗦什么！");
                return 1; 
        }
        
        me->set("combat_exp", 250000);
        me->set("jiali", 25);
        if (present("biyu xiao",me))
                command("unwield xiao");
        me->prepare_skill("strike");
        me->prepare_skill("leg");
        me->prepare_skill("hand");
        me->prepare_skill("finger");
        me->prepare_skill("sword");
        me->reset_action();
        me->prepare_skill("strike", "luoying-zhang");
        say("\n黄药师喝道：第一招是落英神剑掌，小心接招了！\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("biyu xiao",me))
                carry_object("/clone/weapon/biyuxiao.lpc")->wield();
        else
                command("wield xiao");
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                if (!present("biyu xiao",me))
                        carry_object("/clone/weapon/biyuxiao.lpc")->wield();
                else
                        command("wield xiao");
                me->prepare_skill("finger");
                me->reset_action();
                me->prepare_skill("strike", "luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                me->set("combat_exp", 2000000);
                me->set("jiali", 100);
                return 1;
        }
        me->prepare_skill("strike");
        me->reset_action();
        me->prepare_skill("strike", "luoying-zhang");
        say("\n黄药师喝道：第二招是玉箫剑法，小心接招了！\n");
        if (!present("biyu xiao",me))
                carry_object("/clone/weapon/biyuxiao.lpc")->wield();
        else
                command("wield xiao");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                if (!present("biyu xiao",me))
                        carry_object("/clone/weapon/biyuxiao.lpc")->wield();
                else
                        command("wield xiao");
                me->prepare_skill("finger");
                me->reset_action();
                me->prepare_skill("strike", "luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                me->set("combat_exp", 2000000);
                me->set("jiali", 100);
                return 1;
        }
        if (present("biyu xiao",me))
                command("unwield xiao");
        me->prepare_skill("strike");
        me->reset_action();
        me->prepare_skill("hand", "lanhua-shou");
        say("\n黄药师喝道：第三招是兰花拂穴手，小心接招了！\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                if (!present("biyu xiao",me))
                        carry_object("/clone/weapon/biyuxiao.lpc")->wield();
                else
                        command("wield xiao");
                me->prepare_skill("finger");
                me->reset_action();
                me->prepare_skill("strike", "luoying-zhang");
                me->prepare_skill("leg", "xuanfeng-tui");
                me->set("combat_exp", 2000000);
                me->set("jiali", 100);
                return 1;
        }
        me->prepare_skill("hand");
        me->reset_action();
        me->prepare_skill("finger", "tanzhi-shentong");
        say("\n黄药师喝道：第四招是弹指神通，小心接招了！\n");
        COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
        if (!present("biyu xiao",me))
                carry_object("/clone/weapon/biyuxiao.lpc")->wield();
        else
                command("wield xiao");
        me->prepare_skill("finger");
        me->reset_action();
        me->prepare_skill("strike", "luoying-zhang");
        me->prepare_skill("leg", "xuanfeng-tui");
        me->set("combat_exp", 2000000);
        me->set("jiali", 100);
        if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
                command("sneer");
                command("chat 如此不济，也想做我的女婿？！");
                return 1;
        }

        write("黄药师说道：好吧，这第一关就算你过了。\n");
        write("黄药师说道：你要是准备好了就来过第二关吧！\n");
        tell_room(environment(ob), "黄药师对" + ob->name() + "说道：好吧，这第一关就算你过了。\n", ({ob}));
        ob->set_temp("thd_marry", 2);
        return 1;
}

int ask_test2()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 2) {
                say("黄药师喝道：怎么，想作弊么？！\n");
                return 1; 
        }
        if (ob->query_temp("thd_marry") > 2) {
                command("say 已经过了这关还来罗嗦什么！");
                return 1; 
        }
        
        command("say 所谓五音，除了宫商角徵外，还有一个是什么？");
        return 1;
}

int ask_test3()
{
        object ob=this_player();

        if (!ob->query_temp("thd_marry")) return 0;
        if (ob->query_temp("thd_marry") < 3) {
                say("黄药师喝道：怎么，想作弊么？！\n");
                return 1; 
        }
        command("say 九阴真经言道：天之道，损有余而补不足，是故....，后面的三个字是什么？");
        return 1;
}

int ask_nvxu()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0;

        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id == ob->query("id")) {
                if (nvxu->query("death_count") < ob->query("death_count"))
                        command("say 小女现在仍然待字闺中。");
                else
                        say(CYN"黄药师笑道：" + RANK_D->query_rude(ob) + "，还不快叫岳父？！\n"NOR);
        }
        else {
                if (id) {
                        if (!(user = find_player(id))) {
                                user = new(LOADUSER_OB, id);
                                user->set_name("", ({ id }));
                                if (!user->restore()) {
                                        command("say 小女现在仍然待字闺中。");
                                        destruct(user);
                                        return 1;
                                }
                                user_load = 1;
                        }
                }
                if (!id || nvxu->query("death_count") < user->query("death_count"))
                        command("say 小女现在仍然待字闺中。");
                else
                        command("say 我已把小女许配给" + nvxu->query("name") + "为妻了。");
                if (user_load) destruct(user);
        }
        return 1;
}

