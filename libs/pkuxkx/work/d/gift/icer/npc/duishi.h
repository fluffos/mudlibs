int POEMS=2795;
string POEMDIR="/d/gift/icer/poem/";
string *poem;
string author,title,answer,ask;

void init()
{
	add_action("do_answer","answer");
	add_action("do_question","question");
}

void do_come()
{
	message_vision("一个" + this_object()->name() + "嘴里念念有词地慢慢踱了过来。\n",this_object());
	command("hi " + this_object()->query("target"));
	if (environment(this_object()))
		command("act 中秋佳节，来到" + environment(this_object())->query("short") + "一游，吟诗作对，不亦乐乎！");
}
void do_dest()
{
	message_vision(this_object()->name() + "嘴里念念有词地慢慢走远了。\n",this_object());
	destruct(this_object());
}

int do_answer(string arg)
{
	object yuebing;
	object me = this_player();
	int type,i;
	string level;
	
	if (time()-me->query_temp("duishi/answer_time") < 10)
	{
		tell_object(me,"你刚对过一次，歇歇再对吧。\n");
		return 1;
	}
	me->set_temp("duishi/answer_time",time());
	if (!query("answered"))
	{
		message_vision("$N见那" + this_object()->name() + "苦思不得其解，不禁答道：『" + arg + "』！\n",me);
		if (arg == answer)
		{
			message_vision(this_object()->name() + "恍然大悟，惊喜地看了一眼$N，说道：『没错没错！就是这个！这位" + RANK_D->query_respect(me) + "真是饱读诗书啊，佩服！佩服！！\n",me);
			set("answered",1);
			yuebing = new(__DIR__"obj/yuebing");
	
							if (random(900)== 1)
								type = 7;
							else if (random(30) == 1) 
							{
								i = random(3)+4;
								if (i==4) type = 3;
								else type = i;
							} else {
								i = random(3)+1;
								if (i==3) type = 4;
								else type = i;
							}
							if (random(900)==1)
								level = "极品";
							else if (random(30) == 1)
								level = "精选";
							else level = "普通";
							if (me->query("id") == COMBAT_D->query("special"))
							{
								type = 11+random(4);
								COMBAT_D->delete("special");
							}
							yuebing->set_prop(type,level,24+random(7));		
							message_vision(this_object()->name() + "从书袋中拿出一块" + yuebing->name() + "递给$N说道：『多谢这位" + RANK_D->query_respect(me) + "为在下答疑解惑，时近中秋，这块月饼就作为在下的一点心意吧！\n",me);
	
			yuebing->move(me);
			CHANNEL_D->do_channel(this_object(),"rumor","听说" + me->name() + "与" + this_object()->name() + "吟诗作对得到一块" + yuebing->name() + "。",0);
			command("thank " + me->query("id"));
			call_out("do_dest",1);
		}
		else message_vision(this_object()->name() + "若有所悟，但抬起头来思考一会儿，却朝着$N摇了摇头，转过去接着仔细思索起来...\n",me);
	}
	return 1;
}
string rtrim(string arg)
{
	int len;
	len = strwidth(arg)-1;
	while (arg[len..len] == " ")
	{
		arg = arg[0..len-1];
		len--;
	}
	return arg;
}
void new_test()
{   
	string filename,buf;
    int i,length,k;
    //0:题目 1:作者 2:上句 3:下句
    int testtype; 

    length=0;
    k=1+random(POEMS);
    filename= POEMDIR+"/poem"+k+".txt";
    buf=read_file(filename,1,1);
    CHANNEL_D->do_channel(this_object(),"sys",buf,0);
    sscanf(buf,"%s：%s",author,title);
    title = replace_string(title,"\n","");
    i=0;
    length=0;
    poem=({});
    while(buf=read_file(filename,2+i,1)) {
      if(strwidth(buf)>2) {
        buf=rtrim(replace_string(buf,"\n",""));
        buf = replace_string(buf,"\"","");
        poem+=({buf});
		length++;
      }
      i++;
    }
    testtype = random(4);
   	
    if (testtype == 0)
    {
    	ask = this_object()->name() + "皱眉自言自语道：『" + poem[random(length)] + "』这首诗的题目是什么呢？(answer)\n";
    	answer = title;
    }
    if (testtype == 1)
	{
		ask = this_object()->name() + "轻拍自己的额头，说道：『" + poem[random(length)] + "』这句诗是出自哪位的笔下来着？(answer)\n";
		answer = author;
	}
	if (testtype == 2)
	{
		i = random(length);
		if (i == 0) 
			i = 1;
		ask = this_object()->name() + "一边踱步，一边自言自语：『" + poem[i] + "』的上句是.....(answer)\n";
		answer = poem[i-1];
	}
	if (testtype == 3)
	{
		i = random(length);
		if (i == length-1) 
			i = length-2;
		ask = this_object()->name() + "苦恼地说道：『" + poem[i] + "』的下句,下句是什么呢？(answer)\n";
		answer = poem[i+1];
	}
	set("ask",ask);
	set("answer",answer);
    return;
}

int do_question()
{
	object me = this_player();
	if (time() - me->query_temp("duishi/get_question") < 10)
	{
		tell_object(me,"你刚问过题目，休息一会儿吧！\n");
		return 1;
	}
	me->set_temp("duishi/get_question",time());
	message_vision(ask,me);
	return 1;
}