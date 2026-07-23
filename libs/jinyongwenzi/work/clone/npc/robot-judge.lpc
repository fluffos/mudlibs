//  robot-judge.c
//  By Jpei  Aug 1997
//  Add cleaner By Bbb
//  Change question format By Look
inherit NPC;
#include <ansi.h>
#include <mudlib.h>

int do_answer(string arg);
int ask_judge();
int ask_rejudge();

string *key=({
"┌■■■┌■┌■■■┌■■■┌■┌■┌■■■┌■■■┌■■■┌■■■┌■■■",
"│■┐■│■└─┐■└─┐■│■│■│■─┘│■─┘└─┐■│■┐■│■┐■",
"│■│■│■┌■■■┌■■■│■■■│■■■│■■■　　│■│■■■│■■■",
"│■│■│■│■─┘└─┐■└─┐■└─┐■│■┐■　　│■│■┐■└─┐■",
"│■■■│■│■■■┌■■■　　│■┌■■■│■■■　　│■│■■■┌■■■",
"└──┘└┘└──┘└──┘　　└┘└──┘└──┘　　└┘└──┘└──┘",
"■■■┐■┐■■■┐■■■┐■┐■┐■■■┐■■■┐■■■┐■■■┐■■■┐",
"■┌■│■│└─■│└─■│■│■│■┌─┘■┌─┘└─■│■┌■│■┌■│",
"■│■│■│■■■│■■■│■■■│■■■┐■■■┐　　■│■■■│■■■│",
"■│■│■│■┌─┘└─■│└─■│└─■│■┌■│　　■│■┌■│└─■│",
"■■■│■│■■■┐■■■│　　■│■■■│■■■│　　■│■■■│■■■│",
"└──┘└┘└──┘└──┘　　└┘└──┘└──┘　　└┘└──┘└──┘",
"┌──┐┌┐┌──┐┌──┐┌┐┌┐┌──┐┌──┐┌──┐┌──┐┌──┐",
"│■■■│■└■■■└■■■│■│■│■■■│■■■└■■■│■■■│■■■",
"│■│■│■┌──■┌─┘■│■┘■│■─┐│■─┐　　│■│■┘■│■┘■",
"│■│■│■│■■■└■■■└■■■└■■■│■■■　　│■│■■■└■■■",
"│■┘■│■│■─┐┌─┘■　　│■┌─┘■│■┘■　　│■│■┘■┌──■",
"└■■■└■└■■■└■■■　　└■└■■■└■■■　　└■└■■■└■■■",
"┌──┐┌┐┌──┐┌──┐┌┐┌┐┌──┐┌──┐┌──┐┌──┐┌──┐",
"■■■│■│■■■│■■■│■│■│■■■┘■■■┘■■■│■■■│■■■│",
"■│■│■│┌─■│┌─■│■└■│■└─┐■└─┐　　■│■└■│■└■│",
"■│■│■│■■■┘■■■│■■■│■■■│■■■│　　■│■■■│■■■│",
"■└■│■│■──┐┌─■│　　■│┌─■│■└■│　　■│■└■│┌─■│",
"■■■┘■┘■■■┘■■■┘　　■┘■■■┘■■■┘　　■┘■■■┘■■■┘",
"┌──┐┌┐┌──┐┌──┐┌┐┌┐┌──┐┌──┐┌──┐┌──┐┌──┐",
"│┌┐│││└─┐│└─┐││││││┌─┘│┌─┘└─┐││┌┐││┌┐│",
"││││││┌─┘│┌─┘││└┘││└─┐│└─┐　　│││└┘││└┘│",
"│││││││┌─┘└─┐│└─┐│└─┐││┌┐│　　│││┌┐│└─┐│",
"│└┘││││└─┐┌─┘│　　││┌─┘││└┘│　　│││└┘│┌─┘│",
"└──┘└┘└──┘└──┘　　└┘└──┘└──┘　　└┘└──┘└──┘"
});

string ans="";
string str="";

varargs void drool(string msg, string who, object ob, string channel);

string *fuck = ({
      "fuck","FUCK","屁眼","操你妈","干你娘","他妈的",
        "放屁","鸡巴","阴道","傻B","傻b","傻X","傻x","tmd","tnnd",
      "婊子","你丫","丫挺","你妈个","去你妈","日你妈","妓女",
        "X你妈","赤佬","瘪三","傻逼","蠢蛋"
        });

varargs void alldrool(string msg, string who, object ob);

string *allfuck = ({
      "屁","操","干","妈","淫","爸","爷爷",
        "奶","鸡","阴","傻","丫","床","日你","赤佬",
        "瘪三","白痴","逼","蠢","妞","cao","穴","值钱",
        "小费","卖","献身","裸","奸","辱","耻","娘",
        "shit","SHIT","妇","旦","儿子","孙子","泡","母狗"
        });

//把这里的排除掉，否则一堆 emote 全记录了，有待增加
string *except = ({
      "奸笑","姑娘","做操","早操","操作","操心","屁股","干活","干工",
"傻哪","干部","起床","阴笑","穴道","买卖","傻笑","哭爹喊娘","霸蕹傻","丝床患",
"死去的爹娘","蠢粗","骸爸蹲","傻诙","蠢献","傻懔","旱奶","裁床还","吃奶的力"
        });

void create()
{
        set_name("机器人法官", ({ "jiqiren faguan", "jiqiren", "faguan", "robot judge", "robot", "judge" }));
        set("shen_type", 0);

        set("gender", "机器");
        set("age", 20);
        set("long", "这是一个专门审判机器人的法官。\n");
        set_skill("dodge", 1000);
        set("max_qi", 10000);
        set("qi", 10000);
        set("max_jing", 10000);
        set("jing", 10000);

        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("inquiry", ([
                "name": "你还有这闲功夫啊？",
                "rumors": "听说你是个机器人，嘿嘿，我这关可是铁面无情呀。",
                "here": "这里是法庭，没事不准喧哗！",
                "审判": (: ask_judge :),
                "审讯": (: ask_judge :),
                "上诉": (: ask_rejudge :),
        ]) );

        setup();

        if( clonep() ){
                CHANNEL_D->register_relay_channel("chat");
                CHANNEL_D->register_relay_channel("rumor");
                CHANNEL_D->register_relay_channel("party");             
		CHANNEL_D->register_relay_channel("sj");
        }


}

void init()
{
        object ob = this_player();
        add_action("do_answer", "answer");
        add_action("do_answer", "huida");
        ob->set_temp("robot_judge", -1);
        if (!wiz_level(ob) && !ob->is_busy()) ob->start_busy(15);
        call_out("ok", 30, ob);
}

void ok(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        ob->delete_temp("robot_judge");
        if (userp(ob) && !wiz_level(ob)) {
            command("say " + ob->name(1) + "现在接受聆讯，任何时候皆可以要求审判。");
            }
        tell_object(ob, "法官抬起头看了看你，示意你可以开始了。\n");
        ob->apply_condition("judgement",10);
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("$N沮丧地发现机器人法官根本不理会作战请求。\n", ob);
}

void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say("机器人法官狞笑着说：我是无敌不死版！\n");
        command("hehe");
}

void die()
{
        unconcious();
}

int do_answer(string arg)
{
        object ob = this_player();
	
        if (!arg) return 0;
        if (ob->query_temp("robot_judge") != 1) return 0;
        ans = ob->query_temp("answer");
        if (arg==ans) {
                tell_object(ob, "机器人法官点了点头，说道：OK，你可以走了。\n");
                command("say 本庭现在宣判：" + ob->name(1) + "被控机器人一案，因控方证据不足，判" + ob->name(1) + "无罪，当庭释放。");
                ob->delete_temp("robot_judge");
                ob->delete_temp("answer");
        ob->delete_condition("robot");
                if (ob->query("catch_robot_place") 
                && ob->query("catch_robot_place") != base_name(environment()) 
                && ob->query("catch_robot_place") != USER_OB ) 
                	ob->move(ob->query("catch_robot_place"));
                else if (ob->query("enter_wuguan")) ob->move("/d/wuguan/dayuan");
                else ob->move("/d/city/chmiao");
        }
        else {
                tell_object(ob, "机器人法官叹了口气道：这么简单都答不对？又是一个机器人！\n");
                command("say 本庭现在宣判：" + ob->name(1) + "，" + ob->query("gender") + "，" + chinese_number(ob->query("age")) + "岁，触犯机器人条例第十七条，判行政拘留，如有不服可以上诉。");
                ob->set_temp("robot_judge", 2);
        }
        return 1;
}

void test_robot(object ob)
{
        int temp, line, ltemp, c, cl, len;
        ans="";
        str="";
        tell_object(ob, "机器人法官敲了敲桌子，说道：“机器人审判开始，请回答一个小问题。”\n");
        ob->set_temp("robot_judge", 1);
        temp = len = random(3) + 3;
        while (temp--) {
            ans += "0";
            ans[<1] += random(10);
        }
        line = random(5)*6;
        for (ltemp = line; ltemp < line+6; ltemp++) {
            for (temp = 0; temp < len; temp++) {
                c = ans[temp] - '0';
                if (c != 1) cl = 7;
                else cl = 3;
                if (c > 1) c = c * 8 - 4;
                else c *= 8;
                cl += c;
                str += key[ltemp][c..cl];
            }
            str += "\n";
        }
        ob->set_temp("answer",ans);
        tell_object(ob, "请用answer命令回答，下面这组数字是什么？\n");
        tell_object(ob, str);
}

int ask_judge()
{
        object ob = this_player();
        int temp;
        if (temp = ob->query_temp("robot_judge")) {
                if (temp < 0) {
                        write("请等一会，法官正在看你的资料。\n");
                        return 1;
                }
                if (temp > 1) {
                        write("你已经被审判过了，如有不服请上诉！\n");
                        return 1;
                }
                else {
                        write("你正在审判中！\n");
                        return 1;
                }
        }
        command("say 本庭现在审理" + ob->name(1) + "被控为机器人一案。");
        test_robot(ob);
        return 1;
}

int ask_rejudge()
{
        object ob = this_player();
        int temp;
        if (temp = ob->query_temp("robot_judge") < 2) {
                if (temp == 1) {
                        write("你正在审判中！\n");
                        return 1;
                }
                else {
                        write("你还没被审判过，上诉什么？！\n");
                        return 1;
                }
        }
        command("say 本庭现在审理" + ob->name(1) + "被判为机器人一案的上诉案。");
        test_robot(ob);
        return 1;
}

void relay_channel(object ob, string channel, string msg)
{
        string who;
        if( !userp(ob) ) return;
        if( ob==this_object() ) return;
        who = ob->query("name");
        drool(msg, who, ob, channel);
//	alldrool(msg,who,ob);
}

//记录脏话，关闭频道
varargs void drool(string msg, string who, object obj, string channel)
{
        mapping mem;
        string *ob;
        object me = this_player();
        int i, flag = 0;

        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
	i = strlen(msg);
	while (i--) {
		if (msg[i] >= 'A' && msg[i] <='Z') {msg[i]+=32; continue;}
		if (msg[i] >= 'a' && msg[i] <='z') continue;
		if (msg[i] > 128) continue;
		msg = msg[0..i-1] + msg[i+1..<1];
	}
        for(i=0;i<sizeof(fuck);i++){
                if (strsrch(msg, fuck[i]) >= 0) flag=1;
        }
        if( flag )
        {       if (wiz_level(me)<3){
                message("shout", HIC "【通告】" + who + "在 " + channel + " 频道讲话中含有不雅言词，暂时关闭所有交谈频道，并记录在案，等候处理。\n" NOR,users());
                log_file("FUCK", sprintf("%s %s(%s)%s：%s\n", ctime(time())[4..19],
                	me->query("name"),me->query("id"),channel,msg));
		me->apply_condition("vote_chblk", 40);
                obj->set("chblk_on", 1);
                obj->set("chblk_party", 1);
		obj->set("chblk_sj", 1);
                }
        }
        return;
}

//记录全部有嫌疑的话，但不关闭频道，留待巫师处理 虽然误记很多，总比 log 全部好点
varargs void alldrool(string msg, string who, object obj)
{
        mapping mem;
        string *ob;
        object me = this_player();
        int i, j,flag = 0;
        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        for(i=0;i<sizeof(allfuck);i++)
        for(j=0;j<sizeof(except);j++){
                if (strsrch(msg, allfuck[i]) >= 0 )     flag=1;
                if (strsrch(msg, except[j]) >= 0) flag =0;
	}
        if( flag )
        {
                write_file( "/log/ALLFUCK", sprintf("%s %s(%s)说：%s\n", ctime(time())[4..19],
                me->query("name"),me->query("id"),msg));
        }
}
