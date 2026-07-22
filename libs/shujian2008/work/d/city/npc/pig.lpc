//圣诞神猪 pig.c
//Created by campsun 2003.12.14

inherit NPC;

#include "pig.h"
#include <ansi.h>

                     
mapping map_menpai = (["wd" : wd_desc,
                        "hs" : hs_desc,
                        "ss" : ss_desc,
                        "gm" : gm_desc,
                        "gb" : gb_desc,
                        "tz" : tz_desc,
                        "dls" : dls_desc,
                        "mr" : mr_desc,
                        "sld" : sld_desc,
                        "xx" : xx_desc,
                        "em" : em_desc,
                        "mj" : mj_desc,
                        "thd" : thd_desc,
                        "tls" : tls_desc,
                        "sl" :sl_desc
                        ]);

mapping pig_desc;
string pig_party;


string gGetRndColor()
{
        string* color = ({RED,GRN,YEL,BLU,MAG,CYN,HIR,HIG,HIY,HIB,HIM,HIC,HIW});
        return color[random(sizeof(color))];
}
                 
void create ()
{
        set_name("pig",({"pig"}));

        set("shen_type", 1);
         set("gender", "女性");
        set("age", random(10)+10);
        set("attitude","heroism");
        
        set("str", 20);
        set("con", 20);
        set("int", 20);
        set("dex", 20);
        set("kar", 20);
        set("per", random(40));
        set("max_jing",3000);
        set("max_qi",3000);
        set("cloned",0);
        set("gong",1);
        set("answer",0);
        set("getfood",0);
        set("party","tls");
        set("quest_passed",0);
        set("combat_exp",50000000);
        setup();
}    

void init()
{

        string strTemp;
        object ob = this_object();
        
        
        add_action("do_gong","gong");
        add_action("do_answer","answer");
        if (!ob->query("cloned")){
                //pig_party = str_menpai[random(sizeof(str_menpai))];
                pig_party = ob->query("party");
                pig_desc = map_menpai[pig_party];
                
                set_name(gGetRndColor() + pig_desc["nickname"]  + "猪"NOR,({pig_party + " piggy","piggy","pig"}));
                set("long",gGetRndColor() + "这是一只肥肥胖胖可爱的大猪。\n" + pig_desc["desc"] + "\n似乎要" +YEL "拱（Gong）"NOR + "她才有可能生蛋。"NOR);
                set("cloned",1);
                set("chat_chance", 5);
                call_out("do_over",6000);
        }
        strTemp = query("name") + gGetRndColor() +"鼻子里发出“哼哼唧唧”的声音。\n"NOR;
        strTemp = strTemp + query("name") +gGetRndColor() + "哼唧着：「拱我呀，你倒是拱我呀，WIZ都已经拱过我了，你也拱我呀~~~~」。\n"NOR;
        strTemp = strTemp + query("name") +gGetRndColor() + "哼唧着：「" + pig_desc["say_desc"]+"」。\n"NOR;
        set("chat_msg", ({strTemp}) );
}
int do_gong(string arg)
{
        object me = this_player();
        object ob = this_object();
        int i,improve;
        
        if (!ob->query("gong"))
                return 0;
        
        if (me->query("family/family_name")!=pig_desc["party"])
        {
                tell_object(me,HIG"你以为是头猪，就可以拱着玩么？真是岂有此理！！！\n"NOR);
                return 1;
        }
        message_vision(HIG"$N用自己的鼻子凑上去推$n"+HIG+"，哼唧着“你这只大肥猪怎么就那么沉呀”。\n"NOR,me ,ob);
        
        if (random(me->query("kar"))<=0)
        {
                ob->set("gong",0);
                ob->set("answer",1);
                tell_object(me,HIW"你因为努力拱猪，内力修为得到了提升。\n"NOR);
                improve = random(10) + 10;
                me->add("max_neili",improve);
                log_file("quest/sdgift",sprintf("%s %s(%s)努力拱%s提升内力%s点。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
                message_vision("$N"+HIG+"帮$n擦了擦脸上的汗：「拱得很辛苦吧？」\n"NOR,ob ,me);
                switch (ob->query("quest_passed"))
                {
                case 0: 
                        message_vision("$N"+HIG+"说道：「看你们拱得那么辛苦，我来问问你们，你们回答（"+RED+"answer"+NOR+HIG"）对了我就动弹一下表示我的慰问。」\n"NOR,ob);
                        message_vision("$N"+HIG+"说道：「"+gGetRndColor() +pig_desc["question"] +HIG+"」\n"NOR,ob );
                break;
                case 1:
                        i = random(sizeof(question2));
                        set("question2_answer",question2[i]["answer"]);
                        message_vision("$N"+HIG+"说道：「看你们拱得那么辛苦，我来问问你们，你们回答（"+RED+"answer"+NOR+HIG"）对了我就动弹一下表示我的慰问。」\n"NOR,ob);
                        message_vision("$N"+HIG+"说道：「"+gGetRndColor() +question2[i]["question"] +HIG+"」\n"NOR,ob );
                break;
                case 2:
                        i = random(sizeof(food));
                        set("food_id",food[i]["id"]);
                        set("food_name",food[i]["name"]);
                        message_vision("$N"+HIG+"说道：「看你们拱得那么辛苦，我就大发慈悲生个蛋吧。」\n"NOR,ob );
                        message_vision("$N"+HIG+"东张西望：「生蛋这种事情，实在是需要营养啊。」\n"NOR,ob );
                        message_vision("$N"+HIG+"说道：「这有什么好奇怪的，我是猪么，自然要搞点吃的，我才能生蛋生得痛快，你们去弄个【"+gGetRndColor()+ob->query("food_name")+HIG"】过来吧？」\n"NOR,ob );
                        ob->set("getfood",1);
                        ob->set("gong",0);
                        ob->set("answer",0);
                break;
                }
                
        }
        if(!wizardp(me)) me->start_busy(2);
        me->add_temp("havegong",1);
        return 1;
}
int do_answer(string arg)
{
        object me = this_player();
        object ob = this_object();
        int improve;
        
        if (!ob->query("answer"))
                return 0;
        switch (ob->query("quest_passed"))
        {
        case 0:
                if (arg != pig_desc["answer"])
                {
                        message_vision("$N"+gGetRndColor()+"对$n嘿嘿一笑：「大家快来看猪脑袋呀…………」\n"NOR,ob ,me);
                        return 1;
                }
                ob->set("quest_passed",1);
        break;
        case 1:
                if (arg != ob->query("question2_answer"))
                {
                        message_vision("$N"+gGetRndColor()+"对$n嘿嘿一笑：「大家快来看猪脑袋呀…………」\n"NOR,ob ,me);
                        return 1;
                }
                ob->set("quest_passed",2);
        break;  
        }
        tell_object(me,HIW"你因为问题回答正确，获得一些潜能奖励。\n"NOR);
        improve = random(100) + 100;
        me->add("potential",improve);
        log_file("quest/sdgift",sprintf("%s %s(%s)答对了%s提出的问题 提升潜能%s点。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));        
        message_vision("$N"+gGetRndColor() + "拍了拍$n的头：「还算聪明……」\n"NOR,ob ,me);
        message_vision("$N"+gGetRndColor() + "看着发呆的$n，哼唧道：「发什么愣呀，回答出那么简单的问题就指望我生蛋？继续拱吧你……」\n"NOR,ob ,me);
        ob->set("answer",0);    
        ob->set("gong",1);      
        return 1;               
                

}
int accept_object(object who, object ob)
{
        object me,ofood,egg;
        int i;
        int improve;
        ofood = ob;
        ob = this_object();
        me = this_player();
        
        if (!ob->query("getfood")) return 0;
        
        if (strip(ofood->query("name"))!=strip(ob->query("food_name"))) return 0;
        //if (ofood->query("id")!=ob->query("food_id")) return 0;
        
        message_vision("$N"+gGetRndColor() + "高兴得跳了起来。抱着$n痛苦流涕：「我终于吃到这么美味的$n啦。」\n"NOR,ob ,ofood);
    message_vision("$N"+gGetRndColor() + "将$n吃的精光。\n"NOR,ob ,ofood);
        message_vision("$N"+gGetRndColor() + "向$n使了一媚眼，$n怀中的小鹿乱跳。\n"NOR,ob ,me);
        tell_object(me,HIW"你因为帮猪找到了食物，获得一些经验奖励。\n"NOR);
        improve = random(500) + 500;
        me->add("combat_exp",improve);
        log_file("quest/sdgift",sprintf("%s %s(%s)喂%s 提升实战经验%s点。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
        
        call_out("destroying", 1, ofood);
        if (random(10)>2)
        {
                i = random(sizeof(food));
                set("food_id",food[i]["id"]);
                set("food_name",food[i]["name"]);
                ob->set("food",1);
                message_vision("$N"+HIG+"摸摸自己的肚子：「诶，我还没吃饱呢。」\n"NOR,ob );
                message_vision("$N"+HIG+"说道：「你们再去弄个【"+gGetRndColor()+ob->query("food_name")+HIG"】过来吧？」\n"NOR,ob );
                return 1;               
        }
        else
        {
                message_vision("$N"HIG"摸摸自己的肚子：「吃的真饱啊。这就给你生个蛋吧！」\n"NOR,ob );
                command("chat " + me->query("name") + HIY"，书剑全体工作人员祝你圣诞快乐！！！"NOR);
                message_vision("$N"+HIG+"给$n一颗「猪泥圣蛋」！！！\n"NOR,ob,me );
                egg = new("/d/city/npc/obj/egg");
                egg->move(me);
                log_file("quest/sdgift",sprintf("%s %s(%s)得到了「猪泥圣蛋」。\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),));
                call_out("do_over",10);
                return 1;
        }
}
void do_over()
{
        object ob = this_object();
        remove_call_out("do_over");
        message_vision("$N"+HIG+"说道：「吃饱了，我该去睡一觉了。」\n"NOR,ob );
        message_vision("$N"+HIG+"一步一晃的离开了。\n"NOR,ob );
        destruct(ob);
        return; 
}
void die()
{
        unconcious();
}

void unconcious()
{
	say(this_object()->name()+"哼一声: 见过不会死的猪么？现在见到了吧\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        clear_conditions_by_type("poison");
}

void destroying(object ob)
{     
       if (!ob) return;
       if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
        else destruct(ob);
}