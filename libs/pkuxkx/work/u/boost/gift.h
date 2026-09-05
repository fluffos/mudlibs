// for gift.c only, to reduce document size.



void show_question(int index, int show_answer)
{
    show_answer = 1;
	write( "问题："HIG + query_temp("jobs/" + index + "/question") + 
		(show_answer ? NOR"\t答案："HIR + query_temp("jobs/" + index + "/answer") : "") +
		NOR"\t答案示例：" + HIW"answer " + query_temp("jobs/" + index + "/sample") + "\n"NOR);
}

void add_question(string question, string answer, string sample)
{
	question_count ++;
	set_temp("jobs/" + question_count + "/question", question);
	set_temp("jobs/" + question_count + "/answer", answer);
	set_temp("jobs/" + question_count + "/sample", sample);
}

string random_string(string s)	//随机打乱一个中文字符串
{
	int len = sizeof(s) / 2;                //前提是都是中文字符，否则乱码...
	int i, j;
	mixed k1, k2;
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

void add_idiom_question_from_dict(int count)
{	
	int total_question_count = 17762, i;
	int start_line = random(total_question_count - count);
	string question = read_file("/u/boost/idiom.dict", start_line, count);
	string * questions = explode(question, "\n");
	for (i = 0; i < sizeof(questions); i++)
		add_question("请将打乱顺序的成语恢复："HIB + random_string(questions[i]) + NOR"", questions[i], random_string(questions[i]));
}

void add_random_math_question()		//四则运算
{
	int max = 1000, i;
	string str;
#define NUM_COUNT 4
	int *n = allocate(NUM_COUNT);
	for (i = 0; i < NUM_COUNT; i++)
		n[i] = random(max) + 1;
	str = "" + n[0];
	for (i = 0; i < NUM_COUNT - 1; i++ )
	{
		switch(random(3))
		{
		case 0:					// '+'
			str = random(2) ? "(" + str + "+" + n[i+1] + ")" : "(" + n[i+1] + "+" + str + ")";
			n[i+1] += n[i];
			break;
		case 1:					// '-'
			str = "(" + str + "-" + n[i+1] + ")";
			n[i+1] = n[i] - n[i+1];
			break;
		case 2:					// '*'
			str = random(2) ? "(" + str + "*" + n[i+1] + ")" : "(" + n[i+1] + "*" + str + ")";
			n[i+1] *= n[i];
			break;
		}
	}
	str += "=?";

	add_question("请计算下面算式的结果："HIW + str + NOR"", "" + n[i] , "" + random(max));
}


void reset_questions()
{
	question_count = 0;
    add_idiom_question_from_dict(MAX_QUESTION);
 		//for (i = question_count; i < MAX_QUESTION; i++)		//太容易做机器人了，以后再说
 		//	add_random_math_question();
}


void ask_gift()
{
    object me = this_player();
#ifndef TEST_MODE
    tell_object(me, "你目前共有点券" + me->query("jobs/reward/point") + "点，你曾经答对" + me->query("jobs/reward/count") + "题，其中有" +
        me->query("jobs/reward/bonus") + "道是在10秒之内回答的。");
#else
    tell_object(me, "你目前共有临时点券" + me->query_temp("jobsreward/point") + "点，你曾经答对" + me->query_temp("jobsreward/count") + "题，其中有" +
        me->query_temp("jobsreward/bonus") + "道是在10秒之内回答的。");
#endif
}



