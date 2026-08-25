// m_ask.c  by fire on Dec 23 1997
private string *answer_list = ({}); // list for answers
nosave private int p_first;
private mapping ask_list=([]);
private mapping asklist=([]); // this is used for extra ask from job
mixed set_asklist(string q, string p,mixed v)
{
	if(!asklist) asklist=([]);
	if(!asklist[q]) asklist[q]=([]);
	asklist[q][p]=v;
	return asklist[q];
}
mixed query_asklist(string q,string p)
{
	if((!q)||(q=="")) return asklist;
	if(!asklist) asklist=([]);
	if(!asklist[q]) return 0;
	return 	asklist[q][p];
}
mixed clear_asklist(string q)
{
	map_delete(asklist,q);
	return asklist;
}
mixed query_ask_str(string item)
{
   return ask_list[item];
}
void add_ask_str(string item,string sen)
{
     ask_list[item]=sen;
}
nomask void add_question(string question, string ans) 
{
if(p_first==0)
{
   p_first=1;
  answer_list=({});
}
        answer_list += ({ ({ question }) + ({ ans }) });
}
nomask string query_question(string ques)
{
    int i;
    string *q_id;
    string *ans_id;
    i = sizeof(answer_list);
    if (!i)
	return "--" ; //means no answer for this question
    while (i--)
        {
            q_id = ({ answer_list[i][0] });
            if(ques==q_id[0])
            {
		ans_id=({ answer_list[i][1] });
		return ans_id[0];
	    }
         }
	return "--";
}
nomask void ans_def_name(object who)
{
	string m_name;
	string m_zi;
        m_name=this_object()->query_chinese_id();
	m_zi=this_object()->query_sg_zi();
	if(m_zi)
	{
		m_zi="字"+m_zi;
	}
	else
	{
		m_zi="";
	}
this_object()->simple_action("$N笑着说道：我乃"+m_name+m_zi+"，请多多指教？\n")
;
	return;
}
nomask void ans_def_here(object who)
{
	string m_name;
	m_name=environment(this_body())->short();
this_object()->simple_action("$N笑着说道：这里是"+m_name+"喜欢这儿吗？\n");
	return;
}
nomask void ans_def_all(object who)
{
    int sum,i;
	mapping ext_ans;
    string ans,*ext_list;
    string p_id=this_object()->query_id()[0];
    sum=sizeof(answer_list);
    if(!sum ||(objectp(this_object()->query_link())&&!CHAR_D->char_exist(p_id) ))
    {   this_object()->targetted_action(
"$N对$T不耐烦地说道，我什么都不知道，别问我。\n",who);
         return;
    }
    ans="$N对$T说道：我知道下面这些，看看哪些对你有用。\n";
    for(i=0;i<sum;++i)
      ans=ans+answer_list[i][0]+"\n";
	ext_ans=who->query_asklist();
	ext_list=keys(ext_ans);
	if(sizeof(ext_list))
	{
		foreach(string q in ext_list)
		{
			if(ext_ans[q]["target"]==p_id)
				ans+=q+"\n";
		}
	}

    this_object()->targetted_action(ans,who);
    return;
}
nomask void ans_def_rumors(object who)
{
this_object()->simple_action("$N笑着说道：长时间没出门了，好象也没听到什么有新的消息。\n");
	return;
}
nomask void ans_def_dunno(object who)
{
	string m_name;
	int p_tmp;
	p_tmp=random(5);
	switch(p_tmp)
	{
		case 0:
this_object()->targetted_action("$N对$T说道：你说什么我听不懂呀。\n",who);
			return;
		case 1:
this_object()->targetted_action("$N对$T说道：你问得事我怎么一点概念都没有呀。\n",who);
			return;
		case 2:
this_object()->targetted_action("$N对$T说道：这个问题最好问问别人。\n",who);
			return;
		case 3:
this_object()->targetted_action("$N对$T瞪大了眼睛：嗯？\n",who);
			return;
		case 4:
this_object()->targetted_action("$N对$T说道：很抱歉，这也正是我想问的问题呀。\n",who);
			return;
	}
	return;
}
nomask void be_asked(object who, string matt)
{
	string ans_id;
	ans_id=query_question(matt);
	if(ans_id=="--")
	{
		switch(matt)
		{
			case "name":
				ans_def_name( who);
				return;
			case "here":
				ans_def_here(who);
				return;
			case "rumors":
				ans_def_rumors(who);
				return;
			case "all":
				ans_def_all(who);
				return;
			default :
				ans_def_dunno(who);
				return;
		}
	}
	this_object()->special_answer(who,matt);
}
mixed direct_ask_liv_about_wrd(object liv, string item)
{
    return 1;
}
