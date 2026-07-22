//by xiaoyao

inherit NPC;

string ask_degree();
string ask_food();
string ask_pighead();
string ask_highhand();
string ask_pigexp();

void create()
{
    set_name("钱老本", ({ "qian laoben", "qian" }) );
    set("gender", "男性" );
    set("age", 47);
    set("long", 
   "他当年是天地会拱猪第一高手，现在已经离开拱坛多年了。\n");

    set("shen_type", 1);

    set("attitude", "heroism");
    set("inquiry", ([
        "成绩" : "用 pigscore 可以查自己拱猪和得猪头的次数。\n",
        "pigscore" : "用 pigscore 可以查自己拱猪和得猪头的次数。\n",
        "拱猪" : "help pig_cmds 拱猪的有关命令，help pig_rules 规则，pigscore 成绩。\n",
        "拱猪帮" : (:ask_degree:),
        "rank" : (:ask_degree:),
        "吃的" : (: ask_food :),
        "food" : (: ask_food :),
        "pighead" : (: ask_pighead :),
        "猪头" : (: ask_pighead :),
        "highhand" : (: ask_highhand :),
        "排名" : (: ask_highhand :),
        "pigexp" : (: ask_pigexp :),
        "经验" : (: ask_pigexp :),
    ]));

    setup();
    carry_object("/d/city/npc/obj/niupi")->wear();
    carry_object("/clone/weapon/tieguo")->wield();
}

void init()

{
    object me = this_player();

    add_action("do_check", "pigscore");
    add_action("do_clearpig", "我要放弃目前的拱猪成绩。");

    ::init();
    if (interactive(me = this_player())) {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
    }
}

string ask_degree()
{
     object me = this_player();

    int pighead = (int)me->query("pig_new/head");
    int pigmade = (int)me->query("pig_new/pig_made");

    string title,newtitle;
    int index,level;

    title = me->query("title");
    if (title) {
        index = strsrch(title,"、");
        if (index>1) 
            title = title[0..(index-1)];
        else if (index!=-1)
            return ("你的称号太怪，我没法改。\n");
    }
    me->set("title",title);

    level = (pigmade-pighead)*(pigmade+1)/(pighead+1);

    if (level < 1 ) newtitle = "新手";
    else if (level < 4) newtitle = "学童";
    else if (level < 9) newtitle = "童生";
    else if (level < 16) newtitle = "书生";
    else if (level < 25) newtitle = "秀才";
    else if (level < 36) newtitle = "举人";
    else if (level < 49) newtitle = "解元";
    else if (level < 64) newtitle = "贡士";
    else if (level < 81) newtitle = "会元";
    else if (level < 100) newtitle = "进士";
    else if (level < 121) newtitle = "庶吉士";
    else if (level < 144) newtitle = "传胪";
    else if (level < 169) newtitle = "探花";
    else if (level < 196) newtitle = "榜眼";
    else if (level < 225) newtitle = "状元";
    else if (level < 256) newtitle = "翰林";
    else if (level < 289) newtitle = "学士";
    else if (level < 324) newtitle = "大学士";
    else if (level < 361) newtitle = "首辅";
    else if (level < 400) newtitle = "领袖";
    else if (level < 500) newtitle = "大宗师";
    else newtitle = "帮主";

    if (title && title!="") title = title+"、拱猪帮" + newtitle;
    else title = newtitle;

    title = title + " " + me->query("name") + 
        "(" + capitalize(me->query("id")) + ")";
    me->set_temp("apply/short", ({title}));

    return "凭阁下的拱猪经验，依老夫看，你可以做拱猪门"+newtitle+"。\n";
}

int do_check()
{
    object me = this_player();
    int pigplayed = (int)me->query("pig_new/played");
    int pighead = (int)me->query("pig_new/head");
    int pigmade = (int)me->query("pig_new/pig_made");
    int score = (int)me->query("pig_new/score");

    write("你玩了 " + pigplayed +  " 次拱猪，拱出 " +
        pigmade + " 个猪头，你得了 " + pighead + " 个猪头，总分 " + 
        score + " 分。\n");


    return 1;
}


void greeting(object me)
{
    int total = (int)me->query("pig_new/played");
    int pighead = (int)me->query("pig_new/head");
    int score = (int)me->query("pig_new/score");
    int pigmade = (int)me->query("pig_new/pig_made");
    string newtitle;
    int level;

        switch(random(9)) {
        case 1:
        command("pig " + me->query("id"));
                break;

        case 2:
            if (total == 0) 
                        command("say 你看样子还是个拱坛新手吧。");
        else if (total > 100) 
            command("say 你玩得真不少啊！");
          else 
                        command("pig " + me->query("id"));
                break;

        case 3:
        if (total > 100) 
            command("courage " + me->query("id"));
                else 
                        command("pig " + me->query("id"));
                break;

        case 4:
        if (total * (-100 ) < score) 
            command("say 你玩得多，得猪少，好样的！");
        else if (pighead>0) 
            command("say 噫，你怎么长着" + 
                CHINESE_D->chinese_number(pighead) + "个猪头？");
                break;

        case 5:
        if (pighead>0) 
            command("say 噫，你怎么长着" + 
                CHINESE_D->chinese_number(pighead) + "个猪头？");
                command("laugh " + me->query("id"));
                break;
        case 6:
        command("welcome " + me->query("id"));
                break;
                
        case 7:
        command("touch " + me->query("id"));
                break;
         
        case 8:
        command("hoho " + me->query("id"));
                break;
        
        
         

        default:
        level = (pigmade-pighead)*(pigmade+1)/(pighead+1);

        if (level < 1 ) newtitle = "新手";
        else if (level < 4) newtitle = "学童";
        else if (level < 9) newtitle = "童生";
        else if (level < 16) newtitle = "书生";
        else if (level < 25) newtitle = "秀才";
        else if (level < 36) newtitle = "举人";
        else if (level < 49) newtitle = "解元";
        else if (level < 64) newtitle = "贡士";
        else if (level < 81) newtitle = "会元";
        else if (level < 100) newtitle = "进士";
        else if (level < 121) newtitle = "庶吉士";
        else if (level < 144) newtitle = "传胪";
        else if (level < 169) newtitle = "探花";
        else if (level < 196) newtitle = "榜眼";
        else if (level < 225) newtitle = "状元";
        else if (level < 256) newtitle = "翰林";
        else if (level < 289) newtitle = "学士";
        else if (level < 324) newtitle = "大学士";
        else if (level < 361) newtitle = "首辅";
        else if (level < 400) newtitle = "领袖";
        else if (level < 500) newtitle = "大宗师";
        else newtitle = "帮主";

                if (level < 1 )
                        command("say 你还是个拱猪新手啊！");
                else 
                        command("say 拱猪"+ newtitle + "辛苦啦！");
                break;
        }
    return;
}

string ask_food()
{

    return "你赶快去拱猪。拱出了猪头，大家分着吃。";
}


int do_clearpig()
{
    object me = this_player();
    int pigplayed = (int)me->query("pig_new/played");
    int pighead = (int)me->query("pig_new/head");
    int pigmade = (int)me->query("pig_new/pig_made");
    int score = (int)me->query("pig_new/score");

    if (pigplayed < 50) 
        write("你的经验还不足，多拱几次，可能会有进步。\n");

    else {
        me->add("pig_old/played", pigplayed);
        me->add("pig_old/head", pighead);
        me->add("pig_old/pig_made", pigmade);
        me->add("pig_old/score", score);

        me->delete("pig_new/played");
        me->delete("pig_new/head");
        me->delete("pig_new/pig_made");
        me->delete("pig_new/score");

        message_vision("$N红着脸，悄悄地在钱老本耳边说了几句话。\n", me);
        message_vision("钱老本紧紧地握住$N的双手：努力吧，你一定会成功的！\n", me);
        write("你的拱猪成绩全部清除了。\n");
    }
    return 1;
}

string ask_pighead()
{
        object where,obj,*ob_list;
        string msg, name;
        int i, pighead = 0;

        ob_list = users();

        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                if( ob_list[i]->query("pig_new/head") > pighead 
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        pighead = obj->query("pig_new/head");
                }
        }

        if ( !obj ) {
                msg ="咦，好象没人吃过猪头。\n";
                return msg;
        }

        obj->set_temp("mostpigs",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="哈哈，现在书剑里数"+name+"吃的猪头最多。\n";

        return msg;
}

string ask_highhand()
{
        object where, obj, *ob_list;
        string msg, name;
        int i, highrank = 0, mypighead, mypigmade, mypigrank;

        ob_list = users
();

        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                mypighead = (int)ob_list[i]->query("pig_new/head");
                mypigmade = (int)ob_list[i]->query("pig_new/pig_made");
                mypigrank = (mypigmade-mypighead)*(mypigmade+1)/(mypighead+1);
                if( mypigrank > highrank 
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        highrank = mypigrank;
                }
        }

        if ( !obj ) {
                msg ="咦，这里全是拱猪新手啊。\n";
                return msg;
        }

        obj->set_temp("pighighhand",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="哈哈哈，现在书剑里的拱猪高手是"+name+"。\n";

        return msg;
}


string ask_pigexp()
{
        object where, obj, *ob_list;
        string msg, name;
        int i, pigexp = 0, mypigexp;

        ob_list = users();

        for( i = 0; i < sizeof(ob_list); i++) {
                where = environment(ob_list[i]);
                  mypigexp = (int)ob_list[i]->query("pig_played") 
                        + (int)ob_list[i]->query("pig/played")
                        + (int)ob_list[i]->query("pig_old/played")
                        + (int)ob_list[i]->query("pig_new/played");
                if( mypigexp > pigexp 
                && where
                && strsrch(file_name(where), "/d/") >= 0) {
                        obj = ob_list[i];
                        pigexp = mypigexp;
                }
        }

        if ( !obj ) {
                msg ="咦，这里全是拱猪新手啊。\n";
                return msg;
        }

        obj->set_temp("pighighexp",1);
        name = obj->query("name")+"("+obj->query("id")+")";
        msg ="哈哈哈，现在书剑里的拱猪经验最多的是"+name+"。\n";

        return msg;
}
