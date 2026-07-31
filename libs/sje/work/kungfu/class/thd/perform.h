int ask_shenjian()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "桃花岛") {
                command("say 是这幅对联的上联。");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 2) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query("age") < 17) {
                command("say 要使用这样的绝招需要定力，你还是等长大些再说吧。");
                return 1;
        }
/*
        if (ob->query("gender") == "男性" && ob->query("age") < 40) {
                command("say 这招本来我也可以教授于你，不过你就不期望其它更好的途径吗？");
                return 1;
        }
*/
        if (ob->query_skill("luoying-zhang",1) < 80) {
                command("say 要使用这样的绝招需要深厚的掌力，你还是多练习练习“落英神剑掌”再说吧。");
                return 1;
        }
        write("黄药师说道：你既然是桃花岛的弟子，我就教你一招“桃花影里飞神剑”吧！\n");
        write("黄药师细心地向你讲解这一招，你终于学会了。\n");
        perform |= 2;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_yuxiao()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "桃花岛") {
                command("say 是这幅对联的下联。");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 1) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query("age") < 17) {
                command("say 要使用这样的绝招需要定力，你还是等长大些再说吧。");
                return 1;
        }
/*
        if (ob->query("gender") == "男性" && ob->query("age") < 40) {
                command("say 这招本来我也可以教授于你，不过你就不期望其它更好的途径吗？");
                return 1;
        }
*/
        if (ob->query_skill("yuxiao-jian",1) < 80) {
                command("say 要使用这样的绝招需要高深的剑法，你还是多练习练习“玉箫剑法”再说吧。");
                return 1;
        }
        write("黄药师说道：你既然是桃花岛的弟子，我就教你一招“碧海潮生按玉箫”吧！\n");
        write("黄药师细心地向你讲解这一招，你终于学会了。\n");
        perform |= 1;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_kuangfeng()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "桃花岛") {
                command("say " +  RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 4) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query("age") < 23) {
                command("say 要使用这样的绝招需要定力，你还是等长大些再说吧。");
                return 1;
        }
/*
        if (ob->query("gender") == "男性" && ob->query("age") < 40) {
                command("say 这招本来我也可以教授于你，不过你就不期望其它更好的途径吗？");
                return 1;
        }
*/
        if (ob->query_skill("luoying-zhang",1) < 100 && ob->query_skill("xuanfeng-tui",1) < 100) {
                command("say 要使用这样的绝招需要高深的掌法和腿法，你还是多练习练习“落英神剑掌”和“旋风扫叶腿”再说吧。");
                return 1;
        }
        write("黄药师说道：你既然是桃花岛的弟子，我就教你一招我的看家功夫“狂风绝技”吧！\n");
        write("黄药师细心地向你讲解这一招，你终于学会了。\n");
        perform |= 4;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_lingxi()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "桃花岛") {
                command("say " +  RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 8) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query("age") < 23) {
                command("say 要使用这样的绝招需要定力，你还是等长大些再说吧。");
                return 1;
        }
/*
        if (ob->query("gender") == "男性" && ob->query("age") < 40) {
                command("say 这招本来我也可以教授于你，不过你就不期望其它更好的途径吗？");
                return 1;
        }
*/
        if (ob->query_skill("tanzhi-shentong",1) < 100) {
                command("say 要使用这样的绝招需要很强的指劲，你还是多练习练习“弹指神通”再说吧。");
                return 1;
        }
        write("黄药师说道：你既然是桃花岛的弟子，我就教你“弹指神通”的绝招“灵犀一指”吧！\n");
        write("黄药师细心地向你讲解这一招，你终于学会了。\n");
        perform |= 8;
        ob->set("thd/perform", perform);
        return 1;
}

int ask_huayu()
{
        object ob = this_player();
        int perform;
        
        if (ob->query("family/family_name") != "桃花岛") {
                command("say " +  RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
                return 1;
        }
        perform = ob->query("thd/perform");
        if (perform & 16) {
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if (ob->query("age") < 23) {
                command("say 要使用这样的绝招需要定力，你还是等长大些再说吧。");
                return 1;
        }
/*
        if (ob->query("gender") == "男性" && ob->query("age") < 40) {
                command("say 这招本来我也可以教授于你，不过你就不期望其它更好的途径吗？");
                return 1;
        }
*/
        if (ob->query_skill("tanzhi-shentong",1) < 120) {
                command("say 要使用这样的绝招需要很强的指劲，你还是多练习练习“弹指神通”再说吧。");
                return 1;
        }
        write("黄药师说道：你既然是桃花岛的弟子，我就教你“弹指神通”的绝招“漫天花雨”吧！\n");
        write("黄药师细心地向你讲解这一招，你终于学会了。\n");
        perform |= 16;
        ob->set("thd/perform", perform);
        return 1;
}