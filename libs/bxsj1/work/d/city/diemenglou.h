#define BUFFER_SIZE     1024
void searchstr(object me,string file,string str,int location,string buf);
void donext(string arg,object me,string file,string str,int location,string buf);
void again_check(object me); //为了防止dazhuan 类似的pfm 出现兵器留在上面的bug

int do_chakan(string arg)
{
	object me = this_player();
	string str;
	object *ob_list,obj;
	int i,j,offset;
	string file;

	if(me->is_fighting()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);

	if(!arg)
	{
		if(me->query("quest/special/score"))
			str = HBYEL"你蝶梦游戏分数总共累计："+chinese_number(me->query("quest/special/score"))+"分；其中当前游戏分数："+chinese_number(me->query_temp("quest/special/score"))+"分。\n"NOR;
		else 
			str = HBYEL"你蝶梦游戏目前没有积分。\n"NOR;
		if(me->query("quest/special/second_floor"))
		{
			str += YEL"你成绩骄人，更是曾经闯入二楼"+chinese_number(me->query("quest/special/second_floor"))+"次。"NOR;
			if(me->query("quest/special/gift"))
				str += YEL"并获得了"+chinese_number(me->query("quest/special/gift"))+"次宝物奖励。\n"NOR;
			else 	
				str += YEL"只是还未有获得宝物奖励。\n"NOR;
		}
		tell_object(me,str);
	}
	else if(arg=="top")
	{
		ob_list = filter_array(children(USER_OB), (: userp :));
		ob_list = filter_array(ob_list, (: !wizardp($1) :));
		ob_list = filter_array(ob_list, (: $1->query("quest/special/score") :));
		ob_list = sort_array(ob_list, (: sort_user :));
		reset_eval_cost();
		if (sizeof(ob_list)) {
			str =  "\n            ┏ "+HIY"在线蝶梦高手排行榜"NOR+" ┓\n";
			str += "┏━━┯━━┻━━━━━━┯━━━┻┯━━━━┓\n";
			str += "┃名次│     名     字    │ 门  派 │蝶梦积分┃\n";
			str += "┠──┴─────────┴────┴────┨\n";
			if (sizeof(ob_list)> 10)
				j = 10;
			else 
				j= sizeof(ob_list);
			for( i = 0; i < j; i++) {
				str += sprintf("┃%s%|4d  %8s%-10s  %|8s  %|8d" NOR "┃\n",
				(ob_list[i]->query("id") == me->query("id"))?HIY BRED:"",
				i+1,
				ob_list[i]->query("name") ,
				"("+capitalize(ob_list[i]->query("id"))+")",
				ob_list[i]->query("family/family_name"),
				ob_list[i]->query("quest/special/score"));
			}
			str += "┗━━━━━━━━━━━━━━━━━━━━━━┛\n";  
			if(wizardp(me))
			{
				str =  "\n                  ┏"+HIY"在线蝶梦高手排行榜"NOR+"┓\n";
				str += "┏━━┯━━━━━┻━━━┯━━━━┯┻━━━┯━━━━┓\n";
				str += "┃名次│     名     字    │ 门  派 │蝶梦积分│奖励次数┃\n";
				str += "┠──┴─────────┴────┴────┴────┨\n";
				if (sizeof(ob_list)> 10)
					j = 10;
				else 
					j= sizeof(ob_list);
				for( i = 0; i < j; i++) {
					str += sprintf("┃%s%|4d  %8s%-10s  %|8s  %|8d  %|8d" NOR "┃\n",
						(ob_list[i]->query("id") == me->query("id"))?HIY BRED:"",
						i+1,
						ob_list[i]->query("name") ,
						"("+capitalize(ob_list[i]->query("id"))+")",
						ob_list[i]->query("family/family_name"),
						ob_list[i]->query("quest/special/score"),
						ob_list[i]->query("quest/special/gift"));
				}
				str += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";      
			}
		}
		else
		{
			str =  "\n            ┏ "+HIY"在线蝶梦高手排行榜"NOR+" ┓\n";
			str += "┏━━┯━━┻━━━━━━┯━━━┻┯━━━━┓\n";
			str += "┃        目前没有在线蝶梦高手积分说明        ┃\n";
			str += "┗━━━━━━━━━━━━━━━━━━━━━━┛\n";              
		}
		tell_object(me,str);
	}
	else
	{
			obj = present(arg, environment(me));
			if (!obj) obj = LOGIN_D->find_body(arg);
			if (!obj) obj = find_living(arg);
			if (!obj || !me->visible(obj)) return notify_fail(HIY"你要察看谁的状态？\n"NOR);
			if( obj==me && !wizardp(me)) return notify_fail(HIY"查看自己单独使用chakan即可。\n"NOR);
			if (!wizardp(me)) return notify_fail(HIY""+obj->query("name")+"的状态岂是你能查看的？\n"NOR);
			str =  "\n"+HIY+obj->query("name")+"梦蝶积分状况"NOR+"\n";
			str += "┏━━━━━━━━━┯━━━━┯━━━━┯━━━━┓\n";
			str += "┃    名     字     │ 门  派 │蝶梦积分│奖励次数┃\n";
			str += "┠───────━─┴────┴────┴────┨\n";
			str += sprintf("┃%8s%-10s  %|8s  %|8d  %|8d┃\n",
				obj->query("name") ,
				"("+capitalize(obj->query("id"))+")",
				obj->query("family/family_name"),
				obj->query("quest/special/score"),
				obj->query("quest/special/gift"));
			str += "┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";    
			tell_object(me,str);
			seteuid(geteuid(me));
			file = "/log/quest/SPECIAL";
			if( (offset=file_size(file))>=0 ) 
				searchstr(me,file,obj->query("name")+"("+obj->query("id")+")"+"第",file_size(file),"");
	}
    return 1;
}

void searchstr(object me,string file,string str,int location,string buf)
{
        string * s;
        int i,j,count;

        count = 0;
        while (1) {
                i = location;
                location -= BUFFER_SIZE;
                if (location<0)
                        location=0;
                else
                        i = BUFFER_SIZE;
                s = explode(read_bytes(file,location,i)+buf,"\n");
                buf = s[0]+"\n";
                        
                if (location<=0) j=0; else j=1;
                for(i=sizeof(s)-1;i>=j;i--) {
                        if( strsrch(s[i],str,1)>=0 ) {
                                tell_object(me,s[i]+"\n");
                                count++;        
                        }
                }

                if (location<=0) 
                        return;

				if (count>20) {
                        count = 0;
                        tell_object(me,"== 未完继续 == (ENTER 继续下一页，q 离开)");
                        input_to("donext",me,file,str,location,buf);
                        return;
                }
        }
        return;
} 
void donext(string arg,object me,string file,string str,int location,string buf)
{
        if( arg[0]!='q' )
                searchstr(me,file,str,location,buf);
        else
                tell_object(me,"查询终止。\n");
}
int sort_user(object ob1, object ob2)
{
	string name1, name2;
	int exp1 = ob1->query("combat_exp"), exp2 = ob2->query("combat_exp");
	int sc1, sc2;
	int l1 , l2;
	
	if(!ob1->query("quest/special/score"))
		sc1=0;
	else sc1=ob1->query("quest/special/score");

    if(!ob2->query("quest/special/score"))
		sc2=0;
	else sc2=ob2->query("quest/special/score");

	if (sc1 != sc2) 
		return sc2 - sc1;

	if (exp2 !=exp1)
		return exp2 - exp1;

	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");

	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	l1 = ob1->query("family/generation");
	l2 = ob2->query("family/generation");
	if (l1 != l2) return l1 - l2;
	
	name1 = ob1->query("id");
	name2 = ob2->query("id");
    
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;
}
int do_liaoshang(string arg)
{
	object me = this_player();
	if(arg) return 0;
    if(me->is_fighting()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
    if(me->query("eff_qi")>=me->query("max_qi")/3 && me->query("eff_jing")>=me->query("max_jing")/3) 
        return notify_fail(RED"你受伤不重，请使用yun heal疗伤。\n"NOR);
    
    //疗伤
    if(me->query("eff_qi")<me->query("max_qi")/3)
    {
      me->set("eff_qi",me->query("max_qi")/3);
      tell_object(me,HIR"突然你感到一股神力充斥在房间之中，你的伤势竟然康复大半。\n"NOR);
    }
    //疗精
    if(me->query("eff_jing")<me->query("max_jing")/3)
    {
      me->set("eff_jing",me->query("max_jing")/2);
      tell_object(me,HIR"突然你感到一股神力充斥在房间之中，你的精血恢复大半。\n"NOR);
    }
    tell_room(environment(me),HIR"突然你感觉一股神力充斥在房间之中，原来"+me->name()+"正在招呼异力疗伤！\n"NOR, ({ me }));
    return 1;
}
void again_check(object me) //为了防止dazhuan 类似的pfm 出现兵器留在上面的bug
{
	object *obj;
	int i,x=0;
	if(!me) return;
	obj = all_inventory(this_object());
	for (i = 0; i < sizeof(obj); i++) {
		if (living(obj[i]) || obj[i]->is_character() ) continue;
		if(!obj[i]->query("copy_object")) 
		{
			obj[i]->move(me);
			tell_room(this_object(),HIG"\n突然一个老人溜了进来看了看地上的"NOR+obj[i]->query("name")+HIG"，顺手捡了起来。\n"NOR, ({}));
			x=1;
		}
		else
			destruct(obj[i]);
	}  
	if(x==1) tell_object(me,HBRED"你突然发现原来在蝶梦楼失落的物品竟然还在身上。\n");
}