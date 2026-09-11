// ev_guoshi.c
// by Suicide on July 29, 2000

#define   SHOW_VOTE_NAME   1 
private   mapping vote_type = ([]);            //正在投票的类型，<国家名>:<投票名>        

mixed can_be_guoshi(string p_id)
{
if(CHAR_D->get_char(p_id,"loyalty")<90) 
   return "忠诚度不够叫$s怎么相信与你";
if(CHAR_D->get_char(p_id,"reputation")<10000) 
   return "声望不够恐怕难以服众";
if(CHAR_D->get_skill(p_id,"sk_meili")<50) 
   return "治国能力有限$R怎能放心";
if(CHAR_D->get_char(p_id,"nationcontribution")<4000) 
   return "国家贡献不够恐怕难以服众";
return 1;
}

void vote(object officer,object who,string ans)
{int vote_id,i_ans;
 string y_id,m_id,na;
 m_id = (officer->query_id())[0];
 y_id=(who->query_id())[0];
 na = CHAR_D->get_char(m_id,"nation");
 vote_id = VOTE_D->get_special_vote(na,vote_type[na])[0];
 switch(ans)
  {
  case "1" :
  case "2" :
  case "3" :
    {
    sscanf(ans,"%d",i_ans);
    VOTE_D->set_vote(vote_id,i_ans,y_id);
    officer->targetted_action("$N对$T道：$R的意见寡人知道了，先退下吧，让寡人自己好好想想。\n",who);
    officer->clear_answer();
    break;
    }     	
  default:
    officer->targetted_action("$N对$T道：$R的意见寡人有点听不懂，既然如此，你就想好再来吧。\n",who);
    officer->clear_answer();
  return;
  }
}


void new_guoshi_vote(object officer,object who,string ans)
{int vote_id,i_ans;
 string y_id,m_id,na,gs;
 mixed result;
 if (ans=="yes"||ans=="Yes")
 {
 m_id = (officer->query_id())[0];
 y_id=(who->query_id())[0];
 na = CHAR_D->get_char(m_id,"nation");
 gs=COUNTRY_D->get_country(na,"gs");
 if (vote_type[na]=="dismiss")
{
 who->targetted_action(
 "%^CYAN%^$N对$T道：陛下，臣观国师结党营私、混淆朝政，望陛下以社稷为重，罢免其职。%^RESET%^\n",officer);
 
 VOTE_D->add_special_vote(na,"dismiss","最近有人反映国师"+CHAR_D->get_char(gs,"name")
 +"("+y_id+")结党营私、祸国殃民，不知爱卿有何意见啊？\n",3,y_id);   
 }
 else
 {
 who->targetted_action(
"%^CYAN%^$N对$T笑道：$s正是为此事而来，想我国立国以来各城太守各自为政，臣深感忧虑，为能一\n"+
 "        统朝纲，壮大我国，"+"望$R能授我以国师之职，约束各路太守，不知$R以下如何？%^RESET%^\n",officer);
 
 if (stringp(result=can_be_guoshi(y_id)))
    {officer->targetted_action
     ("$N对$T笑道：爱卿"+result+"，还是先回去吧？\n",who);
     return;
    }
    
 officer->targetted_action(
"$N对$T笑道：爱卿德才兼备，堪当此任，不过$s还得和各路太守商议商议，如无异议必授你国师之职。\n",who);
 VOTE_D->add_special_vote(na,"elect",CHAR_D->get_char(y_id,"name")+"("+y_id+
 ")前进宫自荐为国师，寡人考其功绩，欲予之职，不知各位爱卿以下如何？\n",3,y_id);   
}

 CHAR_D->set_char(y_id,"candidate",1);  //设置这个属性，防止申请国师后马上独立
                                        //造成自己即使君主，又是原NPC国的国师
                                        //在pos的独立code前判断此属性
 vote_id = VOTE_D->get_special_vote(na,vote_type[na])[0];
 VOTE_D->add_selectitem(vote_id,({"(1) 同意","(2) 不同意","(3) 弃权"}),0,0);
 VOTE_D->set_vote(vote_id,1,y_id);
}
else
{
   officer->targetted_action("$N对$T道：$R原来不是为此事而来，那就请会吧。\n",who);
   officer->clear_answer();
}
}


void confirm_guoshi_vote(object who, object officer )
{
	string y_id;
	string m_id;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	officer->set_answer(y_id,  (:vote:) );
        officer->targetted_action
          ("$N对$T笑道：你确定了吗？\n",who);
write("确定了就请输入 answer <选项> to "+m_id+"\n");
}


void confirm_if_new_guoshi_vote(object who, object officer ,string type)
{
        string y_id;
	string m_id;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	officer->set_answer(y_id,  (:new_guoshi_vote:) );
	if (type == "dismiss")
        {officer->targetted_action
          ("%^CYAN%^$N对$T笑道：爱卿是不是真的想罢免现在的国师？%^RESET%^\n",who);
         write("确定了就请输入 answer yes  to "+m_id+"\n");
        }
        else
        {officer->targetted_action
          ("%^CYAN%^$N对$T笑道：不知爱卿是否有兴趣做国师替寡人分忧啊？%^RESET%^\n",who);
         write("确定了就请输入 answer yes  to "+m_id+"\n");
        }
}

mixed can_ask(string m_id,string y_id,string y_area)
{
return "$N对$T愤然道：寡人以前轻信奸诈小人予以国师重责，结果害我多次国破家亡，此事以后再休得提起!\n"; //2001.4.13
 if((CHAR_D->get_char(m_id,"nation"))!=m_id)
       return
"$N对$T笑道：这么重要的国家大事$s我不太清楚，$R你还是去问主公吧。\n";
 if((CHAR_D->get_char(m_id,"type"))==TYPE_PLAYER)
       return
"$N对$T笑道：现在一切军国大事寡人还应付的来，还不需要国师协助。\n";
 if((CHAR_D->get_char(m_id,"nation"))!=(CHAR_D->get_char(y_id,"nation")))
       return
"$N对$T笑道：本国大事岂容他国插手，再不滚的话，寡人定要把你抓入大牢。\n";

 if ((AREA_D->get_area(y_area,"leader"))!=y_id)
       return
"$N对$T怒道：这么重要的国家大事，凭你的身份还插不上嘴，叫你们太守亲自来吧。\n";
 if (CHAR_D->get_char(y_id,"grant"))
       return        
"$N对$T笑道：爱卿只是临时太守，还是让你们真正的太守亲自来吧。\n";
 return 1;
}


void ask_guoshi(object who, object officer)
{
        string m_id,y_id,na,vote_id;
        string y_area,gs;
	int i;
	mixed result;
	mapping vote;
	m_id=(officer->query_id())[0];
        y_id=(who->query_id())[0];
        y_area=CHAR_D->get_char(y_id,"area");
        na = CHAR_D->get_char(m_id,"nation");
        if (stringp(result=can_ask(m_id,y_id,y_area)))
           {
            officer->targetted_action(result,who);
            return;
           }
        
        if (gs=COUNTRY_D->get_country(na,"gs")) //如果已经有国师
           vote_type[na] = "dismiss";
        else
           vote_type[na] = "elect";
           
        if (!VOTE_D->get_special_vote(na,vote_type[na])) //如果不存在投票  
           {
           if (vote_type[na]=="dismiss")
             officer->targetted_action(
"$N对$T笑道：本国现在的国师是"+CHAR_D->get_char(gs,"name")+"("+gs+")，难道爱卿对他有意见吗?\n",who);
           else
             officer->targetted_action(
"%^CYAN%^$N对$T笑道：爱卿来得正好，$s正在为国师的事情伤脑筋，真好可以商议商议。%^RESET%^\n",who);
           confirm_if_new_guoshi_vote(who,officer,vote_type[na]);
           return;
           }
        else
          {
           vote_id = VOTE_D->get_special_vote(na,vote_type[na])[0];
     	   printf(VOTE_D->get_special_vote(na,vote_type[na])[1]);
           VOTE_D->show_vote_result(vote_id);
           vote = VOTE_D->get_vote_result(vote_id);
           if (SHOW_VOTE_NAME){
     	   printf("\n\n%%^CYAN%%^赞成者 : ");
     	   for (i=0;i<sizeof(vote[1]);i++)
         	printf("%%^CYAN%%^%s ",CHAR_D->get_char(vote[1][i],"name"));
           printf("%%^RESET%%^\n");
           printf("%%^CYAN%%^反对者 : ");
     	   for (i=0;i<sizeof(vote[2]);i++)
         	printf("%%^CYAN%%^%s ",CHAR_D->get_char(vote[2][i],"name"));
           printf("%%^RESET%%^\n");
           printf("%%^CYAN%%^弃权者 : ");
           for (i=0;i<sizeof(vote[3]);i++)
         	printf("%%^CYAN%%^%s ",CHAR_D->get_char(vote[3][i],"name"));
           printf("%%^RESET%%^\n\n");}
           officer->targetted_action
          ("$N对$T笑道：不知爱卿以下如何？发表一下自己的意见。\n",who);
           confirm_guoshi_vote(who,officer);
          }
}
     	
      
           

