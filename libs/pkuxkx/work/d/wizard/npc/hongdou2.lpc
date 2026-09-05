//hongdou 开心辞典npc                                                                                                
//by kiden@pkuxkx                                                                                                
#include <ansi.h>
inherit NPC;   

string get_question(object me); //随机选择开心词典题目
string get_words(object me);//随机抽取单词
int ask_test();//出题
int ask_gre();//GRE出题
string insert_string(string str);
int do_answer(string arg);//回答开心词典
int do_guess(string arg);//回答GRE单词
void create()                                                                                          
{  
        set_name("红豆", ({ "hongdou npc","hongdou"}) ); 
        set("gender","女性");   
        set("title",HIY"开心使者"NOR);
        set("age",25);
        set("per",40); 
        set("str",40); 
        set("int",40); 
        set("dex",40); 
        set("con",40); 
        set("kar",40);
        set("attitude", "friendly");
        set("combat_exp", 2000000000);
        set("apply/attack",  300000); 
        set("apply/defense", 30000);
        set("inquiry",([
                "test":(: ask_test :),
                        "question":(: ask_test :),
                        "开心词典":(: ask_test :),
                        "开心辞典":(: ask_test :),
                        "gre":(: ask_gre :),
                        "english":(: ask_gre :),
                        "GRE":(: ask_gre :),
                        "English":(: ask_gre :),
                        "单词":(: ask_gre :),
        ]));
        set("shen_type",1);set("score",500000);setup();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}

void init()
{
        add_action("do_answer", "answer");
        add_action("do_guess", "guess");
}

int ask_test()
{
        object me;
        string family,question;
        string *familys=({"丐帮","全真派","天龙寺","古墓派","日月神教","桃花岛","峨嵋派","明教","华山派","少林派","武当派","星宿派"});
        int errortimes;
        me=this_player();
        family=me->query("family/family_name");
        
        
        if (!me->query_temp("hongdou_warning"))
        {
                tell_object(me,HIR"请你先仔细看一下自己所在门派的help或wiki，以免有损失！\n"NOR);
                tell_object(me,HIR"如果继续，请再次ask。\n"NOR);                
                me->set_temp("hongdou_warning",1);
                return 1;
        }
        
        if (me->is_busy())
        {
                tell_object(me,"红豆说道：回答问题太费脑筋了，你还是休息一下吧。\n");
                return 1;
        }

        if (me->query("last_kxcd")-240>=time() && !wizardp(me))  //如果答错或者不答至少需要间隔1分钟
        {
                tell_object(me,"红豆说道：回答问题太费脑筋了，你还是休息一下吧。\n");
                return 1;
        }
        
        if(me->query_temp("answer_kxcd") && !wizardp(me))
        {
            //超时没有回答问题
            tell_object(me,"你没有在规定时间内回答问题！\n");
            me->delete_temp("kxcd/lianxu");
            me->delete_temp("answer_kxcd");
            return 1;
        }
        if (member_array(family,familys)!=-1&&me->query("combat_exp")<300000)
        {
            tell_object(me,"你想起之前师门给你的教诲，决定早早回去给师门做事。\n");
            return 1;
        }
        if (me->query("kxcd/success")>=60&&me->query("combat_exp")<100000)
        {
            tell_object(me,"在达到十万经验之前，你只有六十次答题奖励机会。\n");
            return 1;
        }
        if (me->query("kxcd/success")>=180&&me->query("combat_exp")<200000)
        {
            tell_object(me,"在达到二十万经验之前，你只有一百八十次答题奖励机会。\n");
            return 1;
        }
        if (me->query("kxcd/success")>=300&&me->query("combat_exp")<300000)
        {
            tell_object(me,"在达到三十万经验之前，你只有三百次答题奖励机会。\n");
            return 1;
        }
        if (me->query("kxcd/success")>=500)
        {
                tell_object(me,"红豆道：你是此中高手，这些都难不倒你了。\n");
                return 1;
        }
        if(time()-query_temp("last_test_time")<3) //加一个等待防止刷题
        {
        	      tell_object(me,"红豆答道：我正在准备出题，请你稍等！\n");
        	      return 1;
        }
        set_temp("last_test_time",time());
        me->set("last_kxcd",time()+300);
        question=get_question(me);
        errortimes=0;
        while (question == "题库出错了!" && errortimes < 10)
        {
        	question=get_question(me);
        	errortimes = errortimes + 1;
        }
        tell_object(me,"红豆说道：准备好了吗？我开始出题了哦。\n\n");   
        tell_object(me,HIY+question+"\n"NOR);
        tell_object(me,"\n");
        tell_object(me,"红豆说道：请用answer来回答(例如“answer 3”，表示你认为
                第三个答案是正确的)，你只有3分钟的时间。你可以求助广大的bt们。\n");
                return 1;
}
string random_string(string s)
{
        int len = sizeof(s) / 2;                //前提是都是中文字符，否则乱码...
        int i, j;
        mixed k1,k2;
        for(i = 0; i < len; i++)
        {
                j = random(len - i) + i;
                k1 = s[2*i];
                k2 = s[2*i+1];
                s[2*i] = s[2*j];
                s[2*i + 1] = s[2*j + 1];
                s[2*j] = k1;
                s[2*j + 1] = k2;
        }       
        return s;
}
/*
string get_question(object me)
{
        int i, j, k;

        string file,str,*quest_list,*quests;
        string *quest;
        int answer;
        file = read_file("/d/wizard/npc/QRdata");
        quest_list =  explode(file,"\n");
        while(1)
        {
                i = random(sizeof(quest_list));
                quests =  explode(quest_list[i],"@@@@");
                if (sizeof(quests) == 2)
                {
                        quest = explode(quests[0],"√"); //有些题有敏感字用√分开了，所以需要踢掉那些
                        if(sizeof(quest) == 5)
                        {
                                answer = to_int(replace_string(quests[1]," ",""));
                                
                                if (random(me->query_temp("kxcd/lianxu")) > 10)
                                {
                                        tell_object(this_player(), this_object()->query("name") + "说道：看来不来点狠的是难不住你了！\n");
                                        this_object()->command("grin");                                 
//                                        str = random_string(quest[0]);  //随机打乱题目 //太狠了，by whuan
                                        str = insert_string(quest[0]); //随机插入字符，by whuan
                                }
                                else
                                        str = quest[0];
                                j = random(4) + 1;                                      //从答案中随机挑一个与现有答案交换
                                for( k = 1; k <= 4; k++)        
                                {
                                        str += "\n"+k+".  ";
                                        if (k == j)
                                                 str += quest[answer];
                                        else if( k == answer)
                                                str += quest[j];
                                        else 
                                                str += quest[k];
                                }
                                me->set_temp("answer_kxcd",j);
                                return str;
                        }
                }
        }
        return "题库出错了!";   
}
*/
int do_answer(string arg)
{
        object me=this_player();
        if (!me->query_temp("answer_kxcd")) return 0;
        if (!arg || arg=="") 
        {
                tell_object(me,"红豆疑惑道：你的答案呢？");      
                return 1;        
        }
        if (to_int(arg)!=me->query_temp("answer_kxcd"))
        {
                tell_object(me,"红豆笑道：哈哈，你回答错了，正确的答案是"HIR+
                        me->query_temp("answer_kxcd")+NOR"。\n");
                me->delete_temp("kxcd/lianxu");
                me->delete_temp("answer_kxcd");
                return 1;
        }   
        tell_object(me,"红豆说道：恭喜你，答对了！\n");
        if (me->query("last_kxcd")<=time())
        {
                tell_object(me,"红豆说道：可惜你答题太慢，没有奖励！\n");
				me->delete("last_kxcd");
				me->delete_temp("answer_kxcd");
                return 1;
        }
        /*if (me->query("family/family_name")=="明教"&& me->query("family/enter_time")>1303862399 &&me->query("combat_exp")>=5000)
        {
            tell_object(me,"红豆笑道：贵派代掌门杨逍和我说了，让明教弟子赶紧回明教应付六大派围攻。\n");
            return 1;
        }*/ //明教已作判断
        if (me->query("combat_exp")<300000) //for 10大主流门派，新手判断
        {
            me->set("newbie_hongdou",1);
        }
        tell_object(me,"你的经验和潜能提高了！\n");     
        me->add("kxcd/success",1);
        me->add("combat_exp",50+random(50));
        me->add("potential",50+random(20));
        if (me->query("combat_exp")>300000)
        {
            me->add("potential",random(20));
        }
        me->add_temp("kxcd/lianxu",1);
        me->delete("last_kxcd");
        me->delete_temp("answer_kxcd");
        // 添加busy，机器人答题对系统影响太大。
        me->start_busy(2+random(8));
        if(me->query_temp("kxcd/lianxu")==20)
        {
                tell_object(me,"你已经连续答对20道题了，真是小强啊!\n");
                me->add("potential",2000);
                tell_object(me,"你获得了2000潜能的额外奖励！\n");
        }   
        if(me->query_temp("kxcd/lianxu")==50)
        {
                tell_object(me,"你已经连续答对50道题了，真是大牛啊!\n");
                me->add("potential",10000);
                tell_object(me,"你获得了10000潜能的额外奖励！\n");
                CHANNEL_D->do_channel(this_object(), "bd", me->query("id")+"连续答对了50道题！");
                CHANNEL_D->do_channel(this_object(), "bd", "admire "+me->query("id"), 1);
        }
        return 1;
}
string insert_string(string str)
{
              int len=strwidth(str);
              int i,j;
              string tmp="";
        string *spch = ({"├","┝","┞","┟","┠","┡","┢","┣","│","┬","┭","┮","┯",
                "┰","┱","┲","┳","┼","┽","┾","┿","╀","╁","╂","＄","￡","‰",
                "％","℃","¤","￠","ㄇ","ㄋ","ㄎ","ㄑ","ㄘ","ㄨ","ㄙ","ㄖ","ㄒ","ㄏ",
                "ㄙ","ㄩ","ョ","ュ","ャ","ω","ψ","γ","δ"});

               for(i=0;i<strwidth(str);i++)
               {
                 tmp+=str[i..i];
                 if(random(10)==1 && i%2)
                 tmp+=spch[random(sizeof(spch))]; 
               }
               return tmp;
}

//交换一些词的次序
string swap_word(string str)
{
    int len=strwidth(str);
    string* words=({});
    int i;
    int w1;
    string tmp;
    
    
    for(i=0;i<sizeof(str);i++)
    {        
        if(str[i]>160&&str[i]<255&&i<sizeof(str)-1)
        {
            words += ({str[i..(i+1)]});
            i++;
        }
        else
        {
            words += ({str[i..i]});
        }
    
    }
    
    if(sizeof(words) < 2) return str;
    w1 = random(sizeof(words) - 1);
    
    tmp = words[w1];
    words[w1] = words[w1+1];
    words[w1+1] = tmp;
    str = "";
    
    for(i=0;i<sizeof(words);i++)
    {    
        str += words[i];
    }
    
    return str;         
}

string get_words(object me)
{
          int max_line=6715;//单词的多少
          int i=random(max_line)+1;
          string question;//读出来的题目
          string *file;
          string output="";
          
          question=read_file("/d/wizard/npc/grewords.txt",i,1);
          if (!question) return "";
          file=explode(question,"@@@@");
          if (sizeof(file) == 2)
          {
              me->set_temp("gre/explain",file[1]);
              me->set_temp("gre/words",file[0]);
              output=file[1];
              return output;
          }
          return "";
}

int do_guess(string arg)
{
        object me=this_player();
        if (!me->query_temp("gre/words")) return 0;
        if (!arg || arg=="") 
        {
                tell_object(me,"红豆疑惑道：你的答案呢？");      
                return 1;        
        }
        
        if (arg!=me->query_temp("gre/words"))
        {
                tell_object(me,"红豆笑道：哈哈，你回答错了，正确的答案是"HIR+
                        me->query_temp("gre/words")+NOR"。\n");
                me->delete_temp("gre");
                return 1;
        }   
        tell_object(me,"红豆说道：恭喜你，答对了！\n");
        me->add("kxcd/gre",1);
        me->delete_temp("gre");
        if (me->query("kxcd/gre")<=500)
        {
                tell_object(me,"你的经验和潜能提高了！\n");  
                me->add("combat_exp",50+random(50));
                me->add("potential",50+random(20));
        }
        else
        {
                tell_object(me,"红豆笑道：很不错，你已经答对了"+me->query("kxcd/gre")+"道GRE单词题了。\n");
        }
        return 1;
}
int ask_gre()
{
        object me=this_player();
        string question; //题目
        if (me->query("last_kxcd")>=time() && !wizardp(me))  //如果答错或者不答至少需要间隔1分钟

        {
                tell_object(me,"红豆说道：回答问题太费脑筋了，你还是休息一下吧。\n");
                return 1;
        }
        if(time()-query_temp("last_gre_time")<3) //加一个等待防止刷题
        {
        	      tell_object(me,"红豆答道：我正在准备出题，请你稍等！\n");
        	      return 1;
        }
        set_temp("last_gre_time",time());
        me->set("last_kxcd",time()+60);
        question=get_words(me);
        tell_object(me,"红豆说道：准备好了吗？我开始出题了哦。\n现在给你考的是GRE单词题，根据下面单词的中文解释回答出正确的单词。\n");   
        tell_object(me,HIY+question+"\n"NOR);
        tell_object(me,"红豆说道：请用“guess 答案”的方式来回答。\n");
        return 1;
}

string get_question(object me)
{
        int max_questions=703;//题目数
        int i, j, k;
        string file,str,quest_list,*quests;
        string *quest;
        int answer;
        
        i = random(max_questions)+1; //随机选一行
        quest_list=read_file("/d/wizard/npc/QRdata.txt",i,1); //读出该行

        quests =  explode(quest_list,"@@@@"); //读取问题和正确答案
        while(1)
        {
                if (sizeof(quests) == 2)
                {
                        quest = explode(quests[0],"√"); //读出题目部分
                        if(sizeof(quest) == 5)
                        {
                                answer = to_int(replace_string(quests[1]," ",""));
                                
                                if (random(me->query_temp("kxcd/lianxu")) > 40)
                                {
                                        tell_object(this_player(), this_object()->query("name") + "说道：看来不来点狠的是难不住你了！\n");
                                        this_object()->command("grin");  
                                        str = swap_word(quest[0]);   //随机交换两个字的次序，对人没有问题，对机器人很难。 by Jason
                                        str = insert_string(str); //随机插入字符，增加机器人难度，by whuan
                                }
                                else
                                        str = quest[0];
                                j = random(4) + 1; //从答案中随机挑一个与现有答案交换
                                for( k = 1; k <= 4; k++)        
                                {
                                        str += "\n"+k+".  ";
                                        if (k == j)
                                                 str += quest[answer];
                                        else if( k == answer)
                                                str += quest[j];
                                        else 
                                                str += quest[k];
                                }
                                me->set_temp("answer_kxcd",j);
                                return str;
                        }
		                else
		                return "题库出错了!";
                }
                else
                return "题库出错了!";
        }
        return "题库出错了!";   
}
