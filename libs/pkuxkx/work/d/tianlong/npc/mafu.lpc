//Cracked by Roath
#include <ansi.h>

inherit NPC;

int do_train(string);
int do_walkhorse();
void end_walkhorse(object, int);

int djobid = 1;

void create()
{
        set_name("马夫", ({ "ma fu", "ma", "fu" }) );
        set("gender", "男性");
        set("age", 40);
        set("long",
"这是一个看起来老老实实的马夫，他专门负责给王爷养马。\n");
 
        set("str", 30);
        set("int", 35);
        set("con", 25);
        set("dex", 35);
        set("attitude", "peaceful");
        set("combat_exp", 4000);
        set("title", "平南王府马夫");
        set("inquiry", ([
               "name" : "我是王爷的马夫，专门负责养马。",
                "here" : "这里是马场",
		"工作" : "好的很，我这里正缺人手呢，我这里有两种活，一种是\n"
			 "溜马(walkhorse)，你只要花上一天牵着马到处逛逛就是了。	\n"
			 "另一种是训马(trainhorse)，没俩把刷子你还是别上。 \n",      
        ]));

        set("wanted", ({ "大理平南王府马夫" }));

        setup();
        }
void init()
{
        object me = this_player();
        mapping myfam;

        ::init();
        
        myfam = (mapping)me->query("family");

        add_action("do_train", "train");
        add_action("do_walkhorse", "walkhorse");
        if( interactive(me) && !is_fighting() )
        {
                remove_call_out("greeting");

                call_out("greeting", 1, me);
        }
}
void greeting(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if( !me || environment(me) != environment() ) return;

        if ( myfam && myfam["family_name"] == "大理段家" )
	command("say 这位" + RANK_D->query_respect(me)+ 
"请了，欢迎来到养马场！\n");
        else 
              
  command("say 你是什么人，私闯皇家之地，你想偷马不成！");
}


int do_walkhorse()
{
        object ob;
        string what;
        string *wanted;
	 mapping myfam;
	
	
        ob = this_player();
        myfam = (mapping)ob->query("family");

	if ( myfam && myfam["family_name"] != "大理段家" )
           {
     command("say 这些都是王爷的爱马，我可不放心教给外人！");
 return 1;
        }

        if ( ob->is_busy() || ob->is_fighting() )
        {
                tell_object(ob, "你现在正忙着！\n");
                return 1;
        }               
        if ( ob->query("djob/supervisor") )

        message_vision("$N想给马夫溜马。\n", ob);

        if ( ob->query("djob/supervisor") )
        {
                command("say 哪马还满身贼膘呢，你就想交差？");

                if ( ob->query("djob/supervisor") == "马夫") 
                {
                        add_action("do_say", "say");
                        command("say 如果你急着去练功，你可以跟我说想先走。");
                } else  
                        command("say 如果你想先走，可以直接去告诉"+ob->query("djob/supervisor"));        
                
                return 1;
        }

	 if (query_temp("aaa") > 1)
        
        {
                command("say 最近马都挺好，再溜就得掉膘了。");
                return 1;
        }

        add_temp("aaa", 1);

        wanted = query("wanted");
        what = wanted[random(sizeof(wanted))];

        ob->set("djob/supervisor", "马夫");
        ob->set("djob/object", what);
        ob->set("djob/description", what);
        ob->set("djob/id", djobid);
        ob->set_temp("apply/short", 
                ({ HIW" 大理平南王府马夫"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
        
message_vision("马夫高兴对$N说道：来得正好，这里正缺人手。\n", ob);
        command("say 
你就在这里好好帮我忙吧！");

        call_out("end_walkhorse", 300, ob, djobid);
        djobid++;

        return 1;
}

void end_walkhorse(object who, int jobid)
{
        int i; 
        if ( !objectp(who) || !present(who, environment(this_object())) 
                || (string)who->query("djob/description") != 
"大理平南王府马夫"  
                || (int)who->query("djob/id") != djobid )
                return;

        
message_vision("马夫对$N说道：好，好，马看来有精神多了，你可以走了！\n", 
who);
        command("goodkid " + who->query("id"));
        
        who->delete_temp("apply/short");
        who->add("dali/jobdone", 1);
        who->delete("djob/supervisor");
        who->delete("djob/description");
        who->delete("djob/wage");
        who->delete("djob/object");
        who->delete("djob/id");
	who->add("max_jingli", 1);
        add_temp("aaa", -1);
}


int do_say(string arg)
{
    object ob, who;

    who = this_player();
    ob = this_object();

        if ( arg != "我想先走") return 0;

    if ( who->query("djob/supervisor") != ob->query("name")) return 0;

    message_vision("$N低声说道?我想我还是先去练练功吧…\n", who);
    command("disapp "+ who->query("id"));
    command("say 你这没出息的东西，我看你练功也练不出什么名堂来！");

        who->delete_temp("apply/short");

    this_object()->add_temp("aaa", -1);
    who->add("djob/fail", 1);
    who->delete("djob/supervisor");
    who->delete("djob/description");
    who->delete("djob/object");
    who->delete("djob/id");

    return 1;
}


int do_train(string arg)
{
        object me;
       	int a,b,c,d,reward;
	me=this_player();
        if ( !arg || arg != "horse" )
             return notify_fail( "驯什么？\n");

        if (me->query_temp("trainhorse")) {
                if (me->is_busy())
                        return notify_fail("你正忙着呢。\n");

        if ( me->query("djob/supervisor") )
                return notify_fail(" 先溜完马再说驯马的事。");
        
                tell_object(me, "你开始战战惊惊的驯马了。\n");
  a = me->query_skill("force");
  b = me->query_skill("dodge");
  c = me->query_skill("finger");
  d = me->query_skill("kar");
  reward = random(3);	
if  (random(a+b+c+d) < 40)
{
message_vision("$N刚一靠近，玉骢马撂起一蹶子把$N踢了一个跟斗，躺在地上半天哼哼叽叽爬不起来。\n", me);
	        me->receive_damage("qi", 50);
		me->start_busy(25);
		me->delete_temp("trainhorse");
return 1;
}
if (random(a+b+c+d) > 40 && random(a+b+c+d) < 70){
message_vision("$N小心翼翼的爬上马背，却被玉骢马忽的一个人立，摔在地上半天哼哼叽叽爬不起来。\n", me);
                me->receive_damage("qi", 50);
                me->start_busy(120);
		me->delete_temp("trainhorse");
return 1;
}
else
 {
message_vision("$N用脸轻轻的擦着玉骢马，低声说道：你好可爱呦。\n", me);
 tell_object(me, "贡喜你驯马成功。\n");

 me->add("max_jingli", reward);
me->start_busy(120);
me->add("dali/jobdone", 1);
 me->delete_temp("trainhorse");
}
return 1;
	}
}
