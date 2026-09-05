//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "户部库房");
        set("long", 
"这里户部的衙门的库房。\n"

        );
        set("exits", ([
                
              
                
                
                
                "out" : __DIR__"hu_room2",
                
                
                
        ]));
        
        
        setup();
   
}
int desc(object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (environment(me)!=this_object())
	{
		return 1;
	}
	tell_object(me,HIC+"你来到了"+this_object()->query("short")+"，决定静观其变，守株待兔，抓住内鬼。\n"+NOR);
	return 1;
}
int theif_appear(object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (environment(me)!=this_object())
	{
		return 1;
	}
	tell_object(me,HIR+BLINK+"内鬼出现了，快去捉(zhuo)住他。\n"+NOR);
	me->set_temp("mingtasks/hubu/hu_zei",time());
	return 1;
}
int do_zhuo()
{
	object me=this_player();
	if (!me->query_temp("mingtasks/hubu/huku"))
	{
		return 0;
	}
	if (!me->query_temp("mingtasks/hubu/hu_zei"))
	{
		return 0;
	}
	if (me->is_busy())
	{
		tell_object(me,"你刚想上前做贼，却发现自己手忙脚乱呢。\n");
		return 1;
	}
	if (me->query_temp("mingtasks/hubu/task3finish"))
	{
		tell_object(me,"你不是已经抓到一个内鬼了吗？水至清则无鱼啊，回去复命吧。\n");
		return 1;
	}
	if (time()-me->query_temp("mingtasks/hubu/hu_zei")>5)
	{
		tell_object(me,"你的行动太慢了，内鬼已经溜走了。\n");
		return 1;
	}
	me->set_temp("mingtasks/hubu/task3finish",1);
	message_vision(HIG+"$N一把抓住了内鬼，可以去复命了。\n"+NOR,me);
	return 1;
}
string reshow_ansi(string *ansis,object me)
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,*pool=({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
	a=pool[random(sizeof(pool))];
	pool-=({a});
	b=pool[random(sizeof(pool))];
	pool-=({b});
	c=pool[random(sizeof(pool))];
	pool-=({c});
	d=pool[random(sizeof(pool))];
	pool-=({d});
	e=pool[random(sizeof(pool))];
	pool-=({e});
	f=pool[random(sizeof(pool))];
	pool-=({f});
	g=pool[random(sizeof(pool))];
	pool-=({g});
	h=pool[random(sizeof(pool))];
	pool-=({h});
	i=pool[random(sizeof(pool))];
	pool-=({i});
	j=pool[random(sizeof(pool))];
	pool-=({j});
	k=pool[random(sizeof(pool))];
	pool-=({k});
	l=pool[random(sizeof(pool))];
	pool-=({l});
	m=pool[random(sizeof(pool))];
	pool-=({m});
	n=pool[random(sizeof(pool))];
	pool-=({n});
	o=pool[random(sizeof(pool))];
	pool-=({o});
	p=pool[0];
	me->set_temp("mingtasks/hubu/z/line",({a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p}));
	return ansis[a]+" "+ansis[b]+" "+ansis[c]+" "+ansis[d]+" "+ansis[e]+" "+ansis[f]+" "+ansis[g]+" "+ansis[h]+" "+ansis[i]+" "+ansis[j]+" "+ansis[k]+" "+ansis[l]+" "+ansis[m]+" "+ansis[n]+" "+ansis[o]+" "+ansis[p]+"\n";
}
int show_mess(object me)
{
	string *ansis=({"☆","★","㊣","◎","○","●","⊕","⊙","△","▲","◇","◆","□","■","▽","▼",});
	string line1="",line2="",line3="",line;
	int i,n,*count=({}),total=0;
	for (i=0;i<5+random(3);i++)
	{
		n=random(sizeof(ansis));
		count+=({n});
		line1+=ansis[n];
		total+=1;
	}
	me->set_temp("mingtasks/hubu/z/line1",count);
	count=({});
	for (i=0;i<5+random(3);i++)
	{
		n=random(sizeof(ansis));
		count+=({n});
		line2+=ansis[n];
		total+=1;
	}
	me->set_temp("mingtasks/hubu/z/line2",count);
	count=({});
	for (i=0;i<5+random(3);i++)
	{
		n=random(sizeof(ansis));
		count+=({n});
		line3+=ansis[n];
		total+=1;
	}
	me->set_temp("mingtasks/hubu/z/line3",count);
	me->set_temp("mingtasks/hubu/z/total",total);
	line=reshow_ansi(ansis,me);
	tell_object(me,"前三排是货物的编号，第四排是存储的仓库编号，只要一一对应，就可以了。\n");
	tell_object(me,HIC+"a排货物      "+NOR+line1+"\n");
	tell_object(me,HIC+"b排货物      "+NOR+line2+"\n");
	tell_object(me,HIC+"c排货物      "+NOR+line3+"\n");
	tell_object(me,HIW+"仓库编号     "+NOR+line+"\n");
	tell_object(me,"假如第一排第一个货物是☆，而仓库第一格也是☆，你可以使用命令guilei a 1 to 1，将货物归类。\n归类到一定程度，任务就完成了，a,b,c分别对应三排货品，比如b 2就是第二排第二种货品。\n");
	me->set_temp("mingtasks/hubu/z/replay",HIC+"a排货物      "+NOR+line1+"\n"+HIC+"b排货物      "+NOR+line2+"\n"+HIC+"c排货物      "+NOR+line3+"\n"
	+HIW+"仓库编号     "+NOR+line+"\n"+"假如第一排第一个货物是☆，而仓库第一格也是☆，你可以使用命令guilei a 1 to 1，将货物归类。\n归类到一定程度，任务就完成了，a,b,c分别对应三排货品，比如b 2就是第二排第二种货品。\n");
	tell_object(me,"如果你记不住了，可以用replay命令重看货物的摆放。\n");
	return 1;
}
int do_replay()
{
	object me=this_player();
	if (me->query_temp("mingtasks/hubu/task4finish"))
	{
		tell_object(me,"别玩了，快回去复命吧。\n");
		return 1;
	}
	if (!me->query_temp("mingtasks/hubu/z/replay"))
	{
		return 0;
	}
	tell_object(me,me->query_temp("mingtasks/hubu/z/replay"));
	return 1;
}
int do_zhengli()
{
	object me=this_player();
	if (!me->query_temp("mingtasks/hubu/hu_zhengli"))
	{
		return 0;
	}
	if (me->query_temp("mingtasks/hubu/task4finish"))
	{
		tell_object(me,"别玩了，快回去复命吧。\n");
		return 1;
	}
	if (me->is_busy())
	{
		tell_object(me,"你忙得焦头烂额。\n");
		return 1;
	}
	if (me->query_temp("mingtasks/hubu/hu_zhengli")==2)
	{
		tell_object(me,"快些着手把。\n");
		return 1;
	}
	me->set_temp("mingtasks/hubu/hu_zhengli",2);
	show_mess(me);
	return 1;
}

int record(object me,string line,int posi)
{
	string *lines=({});
	int *posis=({});
	if (me->query_temp("mingtasks/hubu/z/done_line"))
	{
		lines=me->query_temp("mingtasks/hubu/z/done_line");
	}
	if (me->query_temp("mingtasks/hubu/z/done_posi"))
	{
		posis=me->query_temp("mingtasks/hubu/z/done_posi");
	}
	lines+=({line});
	posis+=({posi});
	me->set_temp("mingtasks/hubu/z/done_line",lines);
	me->set_temp("mingtasks/hubu/z/done_posi",posis);
}
int do_guilei(string arg)
{
	object me=this_player();
	string line,*done_line=({});
	int i,posi,heap,*lines,*base_line,*done_posi=({});
	if (!me->query_temp("mingtasks/hubu/z/total"))
	{
		return 0;
	}
	if (me->query_temp("mingtasks/hubu/task4finish"))
	{
		tell_object(me,"别玩了，快回去复命吧。\n");
		return 1;
	}
	if(!arg || (sscanf(arg, "%s %d to %d", line,posi,heap)!=3 ))
	{
		tell_object(me,"你弄清楚归类的规则了吗？\n");
		tell_object(me,"假如第一排第一个货物是☆，而仓库第一格也是☆，你可以使用命令guilei a 1 to 1，将货物归类。\n归类到一定程度，任务就完成了，a,b,c分别对应三排货品，比如b 2就是第二排第二种货品。\n");
		return 1;
	}
	if (me->query_temp("mingtasks/hubu/z/done_line"))
	{
		done_line=me->query_temp("mingtasks/hubu/z/done_line");
	}
	if (me->query_temp("mingtasks/hubu/z/done_posi"))
	{
		done_posi=me->query_temp("mingtasks/hubu/z/done_posi");
	}
	for (i=0;i<sizeof(done_line);i++)
	{
		if (done_line[i]==line&&done_posi[i]==posi)
		{
			return notify_fail("这件货品已经被你归类过了。\n");
		}
	}
	if (heap<1||heap>16)
	{
		tell_object(me,"有这类货品吗？\n");
		return 1;
	}
	if (line=="a")
	{
		lines=me->query_temp("mingtasks/hubu/z/line1");
	}
	else if (line=="b")
	{
		lines=me->query_temp("mingtasks/hubu/z/line2");
	}
	else if (line=="c")
	{
		lines=me->query_temp("mingtasks/hubu/z/line3");
	}
	else
	{
		tell_object(me,"有这排货品吗？a,b,c分别代表第一，第二及第三排。\n");
		return 1;
	}
	base_line=me->query_temp("mingtasks/hubu/z/line");
	if (posi<1||posi>sizeof(me->query_temp("mingtasks/hubu/z/line1"))+1)
	{
		tell_object(me,"有这样货品吗？\n");
		return 1;
	}
	if (lines[posi-1]==base_line[heap-1])
	{
		me->add_temp("mingtasks/hubu/z/succ",1);
		record(me,line,posi);
		tell_object(me,"你整理了一件货品入库。\n");
		if (me->query_temp("mingtasks/hubu/z/succ")>me->query_temp("mingtasks/hubu/z/total")/2)
		{
			tell_object(me,"你归类顺利，快去复命吧！\n");
			me->set_temp("mingtasks/hubu/task4finish",1);
			return 1;
		}
		return 1;
	}
	else
	{
		me->add_temp("mingtasks/hubu/z/fail",1);
		record(me,line,posi);
		tell_object(me,"乱堆乱放，你把一件货品弄错了地方。\n");
		if (me->query_temp("mingtasks/hubu/z/fail")>me->query_temp("mingtasks/hubu/z/total")/3)
		{
			tell_object(me,"你乱堆乱放，任务失败了！\n");
			me->delete_temp("mingtasks");
			return 1;
		}
		return 1;
	}
}
void init()
{
	object me=this_player();
	add_action("do_zhuo","zhuo");
	add_action("do_zhengli","zhengli");
	add_action("do_guilei","guilei");
	add_action("do_replay","replay");
	if (!me->query_temp("mingtasks/hubu/huku"))
	{
		return;
	}
	if (me->query_temp("mingtasks/hubu/huku")==2)
	{
		return;
	}
	me->set_temp("mingtasks/hubu/huku",2);
	call_out("desc",1,me);
	call_out("theif_appear",10+random(20),me);
	return;
}