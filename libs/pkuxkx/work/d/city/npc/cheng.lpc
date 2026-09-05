// cheng.c 程药发
#include <ansi.h>
inherit NPC;
#include <title.h>

//inherit F_SKILL;
int do_unmarry();
string ask_me();
void create()
{
	set_name("程药发", ({ "cheng yaofa", "cheng" }));
	set("title", "扬州知府");
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "他就是程药发，扬州现任知府。\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);
	set("inquiry", ([
		"离婚" : (: do_unmarry :),
		"改名换姓" : (: ask_me :),
		"改名" : (: ask_me :),
	]) );
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	set("shen_type",1);set("score",500);setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}



void init()
{
   add_action("baoshi","baoshi");
	add_action("change_name", "zhuce");
   
}

int do_unmarry()
{
	object me,lover;
	
	me = this_player();
	if (me->query("marry/lover") == 0)
	{
		message_vision("程药发双眼一瞪，朝着$N吼道：你没结婚，捣什么乱！轰出去！\n",me);
		return 1;
	}
	if (!present(me->query("marry/lover"),environment(me)))
	{
		message_vision("程药发双眼一瞪，朝着$N吼道：一个人来就想离婚？滚出去！\n",me);
		return 1;
	}	
	if (!userp(lover = present(me->query("marry/lover"),environment(me)) ) )
	{
		message_vision("程药发双眼一瞪，朝着$N吼道：一个人来就想离婚？滚出去！\n",me);
		return 1;
	}
	if (lover->query("marry/lover") != me->query("id"))
	{
		message_vision("程药发狐疑地看了看，忽然说道：你们俩的婚姻状况不符啊？怎么回事？找巫师吧！我这里解决不了！\n",me);
		return 1;
	}
	if (me->query_temp("unmarry/money_given") || lover->query_temp("unmarry/money_given"))
	{
		shout(HIW+"【官府公告】：" + me->name() + "与" + lover->name() + "一刀两断，从今以后不再是夫妻了！\n");
		message_vision("程药发拿起笔来在姻缘簿上勾了勾，挥挥手：行了行了，你们从此不再是夫妻了！下去吧！\n",me);
		me->delete("marry");
		lover->delete("marry");
		me->delete("married");
		lover->delete("married");
		me->add("unmarried",1);
		lover->add("unmarried",1);
		me->delete("couple");
		lover->delete("couple");
		me->delete_temp("unmarry");
		lover->delete_temp("unmarry");
	}
	else
	{
		me->set_temp("unmarry/money_to_give",1);
		lover->set_temp("unmarry/money_to_give",1);
		message_vision("程药发白眼一翻：想离婚？先交100两金子的手续费！\n",me);
	}
	return 1;
}
int baoshi(string arg)
{   object prisoner,me;
    if(!arg) return 1;
    prisoner=find_player(arg);
    me=this_player();
    if(!prisoner) 
  {
     message("vision","程药发说道：你要保释的人我这里没有\n",me);
     return 1;
  }
    if(!prisoner->query("fanfa"))
  {
     message("vision","程药发呵呵一笑：他明明是个良民嘛，我们抓他干什么?\n",me);
     return 1;
  }
     message("vision","程药发说道：你要保释"+prisoner->query("name")+"吗，他可是犯了\n朝廷的法律的，怎么能放他出去呢？这样吧，你交点保释费吧!\n",me);
     me->set_temp("jiaoqian",1);
     me->set_temp("duixiang",arg);
     return 1;
}  


int destroying(object ob)
{
	destruct(ob);
	return 1;
}
int accept_object(object who, object ob)
{
        object duixiang;
        if(!who->query_temp("jiaoqian") && !who->query_temp("unmarry/money_to_give")) 
        {
           tell_object(who,"程药发慌忙的说道：开什么玩笑，朝廷官员受贿是要杀头的!\n");
           return 0;	
        }
        if (who->query_temp("unmarry/money_to_give"))
        {
                if (ob->query("money_id") && ob->value() >= 1000000) {
			message_vision("程药发一见金子，喜笑颜开，双手捧过来，掂了掂，说道：好吧！想求我什么事？说吧！\n",who);
			who->set_temp("unmarry/money_given",1);
			call_out("destroying",1,ob);
			return 1;
        	}
	        else {
        	         command("say 这种东西鬼才要 ! 滚一边去 !");
                	 command("drop " + ob->query("id"));
        	}
        	return 0;
        }

        duixiang=find_player(who->query_temp("duixiang"));
        if (ob->query("money_id") && ob->value() >= 300000) 
	{
		tell_object(who, "程药发向你挥挥手，好了，去要人吧!\n");

		duixiang->set("canchuyu",1);
                who->delete_temp("jiaoqian");
		return 1;
	}
tell_object(who,"程药发嘿嘿一笑,这些东西，还是给毫毛比较合适.\n");

	return 0;
}




protected int change_name(string arg)
{
        string new_name, name,color;
        int i;
        object me = this_player();


        if (!me->query_temp("name_modify_paid") && !wizardp(me)) {
                command("say 朝廷明文规定，平民不得随意改名换姓，你想坐牢是不是？");
                return 1;
        }

        if ( !arg ) {
                command("say 你到底要改什么名字啊？");
                return 1;
        }

        name = me->query("name");
        new_name = arg;
        if (me->query("chaoting/stayforever"))//By Zine 八旗子弟quest
        {
            return notify_fail("你即获大清皇帝赐姓，就永远保留这个姓名吧！\n");
        }
        switch(me->query("family/family_name")){
                case "峨嵋派":
                case "少林派":  if (me->query("class")) {
                                        if (strwidth(arg) != 2)
                                                return notify_fail("你的名字必须是两个字。\n");
                                        switch (me->query("family/generation")) {
                                                case 40:
                                                        if (arg[0..0] == "清")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                case 39:
                                                        if (arg[0..0] == "道")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                case 38:
                                                        if (arg[0..0] == "慧")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                case 37:
                                                        if (arg[0..0] == "澄")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                case 36:
                                                        if (arg[0..0] == "玄")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                case 35:
                                                        if (arg[0..0] == "渡")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                default:
                                                        if (strwidth(arg) != 2 || name[0..0] != arg[0..0])
                                                                return notify_fail("你的名字必须是两个字，而且第一个字不能变。\n");
                                        }
                                        if (me->query("class") == "huanxi")
                                                me->set("class", "bonze");
                                }
                                break;
				case "天龙寺":  if (me->query("class")) {
                                        if (strwidth(arg) != 2)
                                                return notify_fail("你的名字必须是两个字。\n");
                                        switch (me->query("family/generation")) {
                                                case 15:
                                                        if (arg[0..0] == "本")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                case 16:
                                                        if (arg[0..0] == "了")
                                                                break;
                                                        return notify_fail("辈分不对，重来！\n");
                                                default:
                                                        if (strwidth(arg) != 2 || name[0..0] != arg[0..0])
                                                                return notify_fail("你的名字必须是两个字，而且第一个字不能变。\n");
                                        }
                                        if (me->query("class") == "huanxi")
                                                me->set("class", "bonze");
                                }
                                break;
                case "星宿派":  if(me->query("family/generation") == 2) {
                                        if (strwidth(arg) != 3 || arg[1..2] != "子")
                                                return notify_fail("你的名字必须是三个字，而且以子结尾。\n");
                                }
                                break;
                case "姑苏慕容": if(me->query("family/generation") == 2) {
                                        if (strwidth(arg) < 3 || arg[0..0] != "慕容")
                                                return notify_fail("你的名字必须至少三个字，而且以慕容开头。\n");
                                }
        }

        i = strwidth(new_name);

        if (i <2 || i > 4 ) {
                command("say “"+new_name+"”？");
                command("say 你的中文名字必须是 2 到 4 个中文字才行。");
                return 1;
        }

        while(i--)
                if( i%2==0 && !is_chinese(new_name[i..<1]) ) {
                        command("say 你得用「中文」取名字，本官我可不认识西洋字。");
                        return 1;
                }

	if ( !LOGIN_D->check_legal_name(new_name) ) {
                command("say 你这种名字会造成其他人的困扰，想个其它的。");
                return 1;
        }
		color=COLOR_D->get_color(name);
		name=COLOR_D->uncolor(name);
        CHANNEL_D->do_channel(this_object(), "jh", "从今以后，"+name+"("+getuid(me)+") 改姓名为：" + new_name + "。");
        me->set("name", color+new_name+NOR);
        me->set_face( FACE_FACT, me->query("name") );
        me->add("name_modify", 1);
        log_file("name_modify",sprintf("%-18s 第 %d 次改名于 %s 改为：%s。\n",
                name+"("+getuid(me)+")", me->query("name_modify"), ctime(time()), new_name));
        me->delete_temp("name_modify_paid");
        start_busy(2);
        if (new_name == name)
                command("say 你可真是有钱找我开心来着，改了个一模一样的名字。");
        command("say 你的户籍手续已经办理完毕，你可以走了。");
        return 1;
}

string ask_me()
{
        object me = this_player();

        if(me->query("name") == "名字待定"){
                me->set_temp("name_modify_paid", 1);
                return "此民无名无姓，本官同意改名，你要注册( zhuce <姓名> )什么名字？";
        }

        if( this_object()->is_busy())
                return "我正忙着改写户册呢，你等等。";

        if(me->query_temp("name_wait_modify")){
               command("hmm");
               return "不是告诉了你，这事不那么好办吗？\n";
        }

        if(me->query_temp("name_modify_paid")){
                command("nod");
                return "好吧，你只要注册( zhuce <姓名> )你的新名字就行了。\n";
        }

        command("consider");
        command("say "+me->query("name", 1)+"你有名有姓而要修改户籍和姓名，本官觉得这事很难啊......\n");
        me->set_temp("name_wait_modify", 1);
        if(me->query("class") == "bonze")
                command("say 对了，和尚，尼姑可改不了辈分称号。\n\t比如你叫 本一，就必须 zhuce 以本字开头的名字。");
        return "如果你坚持要改，上报和入册费用是"+chinese_number(100*(me->query("name_modify")+1))+"根金条，可以到张帐房这些手续。\n";
}
