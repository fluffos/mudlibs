#include <ansi.h>
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

string insert_string(string str)
{
              int len=strwidth(str);
              int i,j;
              string tmp="";
        string *spch = ({"├","┝","┞","┟","┠","┡","┢","┣","│","┬","┭","┮","┯",
                "┰","┱","┲","┳","┼","┽","┾","┿","╀","╁","╂","＄","￡","‰",
                "％","℃","¤","￠","ㄇ","ㄋ","ㄎ","ㄑ","ㄘ","ㄨ","ㄙ","ㄖ","ㄒ","ㄏ",
                "ㄙ","ㄩ","ョ","ュ","ャ","ω","ψ","γ","δ","§","№","☆","★","○","●","◎",
                "◇","◆","□","℃","‰","€","°","¤","〓","↓","↑","←","→","※","▲","△",
                "■","＃","＆","＠","＼","︿","￣","―","♂","♀"});

               for(i=0;i<strwidth(str);i++)
               {
                 tmp+=str[i..i];
                 if(random(10)==1 && i%2)
                 tmp+=spch[random(sizeof(spch))]; 
               }
               return tmp;
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
                                
                                        str = swap_word(quest[0]);   //随机交换两个字的次序，对人没有问题，对机器人很难。 by Jason
                                        str = insert_string(str); //随机插入字符，增加机器人难度，by whuan
                                
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
                                me->set_temp("gbnewbiejob/answer",j);
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

int question(object me)
{
    string questions=get_question(me);
    int errortimes;
    while (questions == "题库出错了!" && errortimes < 10)
        {
        	questions=get_question(me);
        	errortimes = errortimes + 1;
        }
    me->set_temp("gbnewbiejob/questiontime",time());
    tell_object(me,"请在1分钟内回答以下问题。\n\n");   
    tell_object(me,HIY+questions+"\n"NOR);
    tell_object(me,"\n");
    tell_object(me,"请用answer来回答(例如“answer 3”，表示你认为第三个答案是正确的\n");
    return 1;
}

int checking(object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
    if (me->query_temp("gbnewbiejob/checkfinish"))
    {
        return 1;
    }
    if (me->query_temp("gbnewbiejob/check_degree")>5&&(!random(20)||wizardp(me)))
    {
        question(me);
        return 1;
    }
    call_out("checking",1,me);
    return 1;
}
int do_dating()
{
    int i;
    object me=this_player();
    object *all;
    if (me->query("family/family_name")!="丐帮")
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("gbnewbiejob/start")!="check")
    {
        return 0;
    }
    if (me->query_temp("gbnewbiejob/checkfinish"))
    {
        tell_object(me,"打探完了，再留下来也不会有什么新的消息了。\n");
        return 1;
    }
    if (me->query_temp("gbnewbiejob/check")!=this_object()->query("gate"))
    {
        tell_object(me,"你弄错了左长老交代给你的任务了吧？\n");
        return 1;
    }
    me->add_busy(5);
    all=all_inventory(this_object());
    i=random(sizeof(all));
    if (all[i]&&all[i]!=me)
    {
        tell_object(me,"你仔细向"+all[i]->name()+"打听江湖中最近的消息。\n");
    }
    else
    {
        tell_object(me,"虽然没找到和人搭话的机会，但你还是通过观察搜集了一些情报。\n");
    }
    if (!me->query_temp("gbnewbiejob/checking"))
    {
        me->set_temp("gbnewbiejob/checking",1);
        call_out("checking",1,me);
    }
    me->add_temp("gbnewbiejob/check_degree",1);
    if (me->query_temp("gbnewbiejob/check_degree")>random(10)+5)
    {
        me->set_temp("gbnewbiejob/checkfinish",1);
        tell_object(me,"你已经完成了打听消息的任务，可以回去复命了！\n");
    }
    return 1;
}

int do_answer(string arg)
{
        int exp,pot;
        object me=this_player();
        if (time()-(int)me->query_temp("gbnewbiejob/questiontime")>60||!me->query_temp("gbnewbiejob/answer")) return 0;
        if (!arg || arg=="") 
        {
                tell_object(me,"你答案呢？");      
                return 1;        
        }
        if (to_int(arg)!=me->query_temp("gbnewbiejob/answer"))
        {
                tell_object(me,"恭喜你，答错了！\n");
                me->delete_temp("gbnewbiejob/answer");
                return 1;
        }   
        tell_object(me,HIG+"恭喜你，答对了！\n"+NOR);
        exp=50+random(50);
        pot=50+random(50);
        me->add("combat_exp",exp);
        me->add("potential",pot);
        tell_object(me,HIG+"你被奖励了"+chinese_number(exp)+"点经验、"+chinese_number(pot)+"点潜能。\n"+NOR);
        me->delete_temp("gbnewbiejob/answer");
        return 1;
}
