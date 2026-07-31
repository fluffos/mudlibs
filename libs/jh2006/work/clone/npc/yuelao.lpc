// yuelao.c 月下老人

inherit NPC;

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
        set_name("月下老人", ({ "yuexiao laoren", "yuelao", "laoren" }));
        set("long", 
                "他就是传说中专管天上地下姻缘的月下老人了。\n"
                "他满脸红光，须眉皆白，看起来已不知有多少岁了。\n"
                "他正坐在那儿翻看一本书，左手黏着一根红绳，口中自言自语着些什么。\n");
        set("gender", "男性");
        set("age", 3000);
        set("attitude", "friendly");
        set("str", 500);
        set("int", 500);
        set("con", 300);
        set("per", 25);
        
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("combat_exp", 20000000);

        set_skill("force", 500);
        set_skill("dodge", 800);
        set_skill("unarmed", 500);
        set_skill("parry", 800);
        set_skill("literate", 900);

        setup();
}

void init()
{
        add_action("do_register", "register");
        add_action("do_register", "jiehun");
        add_action("do_divorce", "divorce");
        add_action("do_divorce", "lihun");
        add_action("do_zuomei", "zuomei");
}

int do_register()
{
        object me, who, meiren;
        me=this_player();

        if (!me->query_temp("marry")) {
                command("say 咦？我这姻缘簿上没有你的名字呀 ... ..."); 
                command("say 唉，请你先回去，等我给你找到你那姻缘再来吧。");
                return 1;
        }
        if (me->query("gender")=="女性") {
                command("say 嗯，请你的未婚夫上前来。");
                return 1;
        }
        if (!objectp(who=present(me->query_temp("marry"),environment(me)))) {
                command("say 嗯，你的姻缘是有了，可是为什么你的未婚妻没一起来？");
                command("say 请带你的未婚妻到这里来，我才能为你们完成登记手续。");
                return 1;
        }
        if (who->query_temp("marry")!=me) {
                command("say 啊？！？你的未婚妻为何又答应另嫁他人了？！？");
                command("say 你们想开什么玩笑？！搞清楚再来！！！");
                return 1;
        }
        if (!who->query_temp("meiren")) {
                command("say
这姻缘嘛，俗话说的好“父母之命，媒妁之言”。这泥潭里无父母，那也罢了。");
                command("say 若再无媒妁之言，那也太不象话了。");
                command("say 你们去找个媒人来吧，由他在此做证，我才能为你们主婚。");
                return 1;
        }
        if (!objectp(meiren=present(who->query_temp("meiren"),environment(me)))) {
                command("say 嗯，你二人都在这儿了，可是那媒人又跑哪儿去啦？");
                command("say 快把媒人找到这儿来，我才能为你们完成登记手续。");
                return 1;
        }

        command("say 哈哈哈哈！好极了，一切齐备，我这就为你们登记！");
        write("月下老人低头把姻缘簿翻了翻，写下些什么。\n");
        command("say 恭喜，恭喜！");
        command("chat 哈哈哈哈！！！！");
        command("chat "+me->name()+"和"+who->name()+"由"+meiren->name()+"做媒，今日喜结良缘，各位泥友做个见证。");
        command("chat 恭祝两位白头偕老，早生贵子。");
        
        who->delete_temp("marry");
        who->delete_temp("meiren");
        who->set("marry/id",me->query("id"));
	who->set("marry/name",me->query("name"));
        me->delete_temp("marry");
        me->set("marry/id",who->query("id"));
	me->set("marry/name",who->query("name"));
	new("/clone/misc/marry-token")->move(me);
	new("/clone/misc/marry-token")->move(who);
	message_vision("$N和$n交换了定情信物。\n", me, who);

        return 1;
}

int do_zuomei(string arg)
{
        object me, who;
        me=this_player();

        if (!arg || !objectp(who=present(arg,environment(me)))) {
                tell_object(me,"你要给谁做媒？\n");
                return 1;
        }
        if (who->query("gender")=="男性") {
                tell_object(me, "嗯，请媒人为女方做媒。");
                return 1;
        }
        if (!who->query_temp("marry")) {
                tell_object(me,"嗯？这人没打算结婚啊，你瞎起什么哄？！？\n");
                return 1;
        }
	if (me==who->query_temp("marry")) {
		write("自己给自己做媒，不太好吧？\n");
		return 1;
	}
        command("say "+RANK_D->query_respect(me)+"原意给"+who->name()+"做媒？");
        command("say 这可是成人之美的善事啊，好极了，我这就记录下来");
        who->set_temp("meiren", me);
        return 1;
}

int do_divorce(string arg)
{
        object me,who;
        me=this_player();

        if (!arg) {
                write("你打算跟谁离婚？\n");
                return 1;
        }
                
        if (!me->query("marry")) {
                command("say 你根本没结过婚！");
                return 1; }
        if (me->query("gender")=="男性") {
                if (me->query("marry/id") != arg) {
                        command("say 这人根本不是你妻子！");
                        return 1; }
                if (!who=find_player(arg)) {
                        command("say 对不起，你妻子现在不在线上，不能办理离婚手续");
                        return 1; }
                if (!me->query_temp("divorcing")) {
                        command("say 唉，你当真想休了你的妻子吗？如果是，请再向我申请一次。");
                        me->set_temp("divorcing",1);
                        return 1; }
		me->delete_temp("divorcing");
                me->delete("marry");
		me->add("divorce", 1);
                who->delete("marry");
                tell_object(who, me->name(1)+"把你休了。\n");
        }
        else {
                if (me->query("marry/id") != arg) {
                        command("say 这人根本不是你丈夫！");
                        return 1; }
                if (!who=find_player(arg)) {
                        command("say 对不起，你丈夫现在不在线上，不能办理离婚手续");
                        return 1; }
                if (!me->query_temp("divorcing")) {
                        command("say 唉，你当真想抛弃你的丈夫吗？如果是，请再向我申请一次。");
                        me->set_temp("divorcing",1);
                        return 1; }
		me->delete_temp("divorcing");
                me->delete("marry");
		me->add("divorce", 1);
                who->delete("marry");
                tell_object(who, me->name(1)+"抛弃了你，不知是跟谁私奔去了。\n");
        }
        command("say 唉 ... ...");
        command("chat 从今天起，"+me->name(1)+"和"+who->name(1)+"就不再是夫妻了。");
        command("chat 又一桩失败的婚姻，唉 ... ... ");
	if (present("yu pei", me)) present("yu pei", me)->lost(me);
	if (present("xiang nang", me)) present("xiang nang", me)->lost(me);
	if (present("yu pei", who)) present("yu pei", who)->lost(who);
	if (present("xiang nang", who)) present("xiang nang", who)->lost(who);
        return 1;
}
