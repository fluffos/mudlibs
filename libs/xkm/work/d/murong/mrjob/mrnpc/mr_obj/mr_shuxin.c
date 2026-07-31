/************************
File:   Shuxin.c
Create: Play
Time:   4/25/2002
************************/
#include <ansi.h>;
inherit ITEM;

string *a_str = ({
"%s听了你的意见表示同意。",
"你发现%s对你的作法很是赞同！",
"%s对你会心的微笑着。",
"%s点头同意你的看法。",
});
string *b_str = ({
"你发现%s若有所思。",
"看来%s对你的看法有所怀疑。",
"%s谨慎对待你的意见。",
});
string *c_str = ({
"看来%s对你的见解不以为然。",
"%s对你的态度冷若冰霜。",
"只见%s冷眼看着你，表示出极大的不耐烦。",
});
string *list = ({
"fj","bw","jq","dw","bf","wl",
"ml","cx","mr","kh","zf","js",	
});

void create()
{
	seteuid(ROOT_UID);
        set_name(HIR"使节杖"NOR, ({"shijie zhang", "zhang"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("no_sell", 1);
                set("no_steal", 1);
                set("mrjob", 1);
                set("no_drop", 1);
                set("long", "一根慕容世家专有的使节杖用于招揽(canvass)天下英才。\n");
                set("value", 0);
                set_weight(100);
        }
        setup();
}
void init()
{
        add_action("do_youshui", ({"zhaolan","canvass","zhengzhao"}));
}

int do_youshui(string arg)
{
	object me,ob;
	mapping job;
	string target,msg;
	
	me = this_player();
	job = me->query_temp("Mrjob");
	
	if(!job || job["content"]!="canvass")
 	         return notify_fail("什么？\n");
	if(!arg) return notify_fail("指令格式: canvass [name]\n");

	if( sscanf(arg, "%s", target)!=1 )
	         return notify_fail("什么？\n");

	ob = present(target, environment(me));
	
	if(!ob) return notify_fail("这里没有这个人。\n");
	if(ob==me)	return notify_fail("征召自己你开什么玩笑。\n");
        if(!living(ob))
        	return notify_fail("看他那样子还是救人要紧！\n");
        if(me->is_fighting()||ob->is_fighting())
        	return notify_fail("战斗中不能征召！\n");
        	
	if(ob->query("id")!=me->query_temp("Mrjob_name/id"))
        	return notify_fail("你现在的任务是征召"+
        	me->query_temp("Mrjob_city/name")+me->query_temp("Mrjob_name/name")+
        	"("+me->query_temp("Mrjob_name/id")+")。\n");
 	msg = "征召计策(可选用八项):\n";
        msg +=__FILE__->get_msg();
        write(msg);
        ob->set("chat_chance", 0);
	input_to("do_canvass",me,ob,job,8,0);
        return 1;	
}

int do_canvass(string arg,object me,object ob,mapping job,int i,int j)
{
	mapping can, vass;
	string msg, *type;
	int k;
	
	if(!ob||!living(ob)) 
	{
		me->set_temp("Mrjob_over", 1);
        	me->set_temp("Mrjob_hortation", j);
        	write("你结束了本次的征召任务。\n");        	
        	return 1;
	}
	if( member_array(arg, list)==-1)
        {
 	msg = "征召计策(可选用八项):\n";
        msg +=__FILE__->get_msg();
        write(msg);
	        input_to("do_canvass",me,ob,job,i,j);
                return 1;        	
        }
        can = ob->query("level");
        vass = ob->query(me->query("id"));
        if(vass) type = keys(vass);
        if( type )
        {
        for(k=0;k<sizeof(type);k++)
        {
        	if(arg!=vass[type[k]]) continue;
        	msg = "此计已经使用过。"
                      "   你还有"+chinese_number(i)+"项计策可用。\n";
                msg +=__FILE__->get_msg();
                write(msg);
	        input_to("do_canvass",me,ob,job,i,j);
                return 1;        	
        }
        }
        if(arg)
        ob->set(me->query("id")+"/"+i,arg);
        i--;
        switch(can[arg])
        {
        	case -1:
        	me->set_temp("Mrjob_over", 1);
        	me->set_temp("Mrjob_hortation", j);
        	message_vision("$N对$n摆了摆手，转身离开了。\n",
                 	ob, me);
		destruct(ob);
        	write("你结束了本次的征召任务。\n");        	
        	return 1;
        	case 3:
        	j += can[arg];
                msg = a_str[random(sizeof(a_str))];	
                write(sprintf(msg,me->query_temp("Mrjob_name/name")));
        	break;
        	case 2:
                msg = b_str[random(sizeof(b_str))];	
                write(sprintf(msg,me->query_temp("Mrjob_name/name")));
        	break;
        	case 1:
                j -= can[arg]*3;
                msg = c_str[random(sizeof(c_str))];	
                write(sprintf(msg,me->query_temp("Mrjob_name/name")));
        	break;
        	default:
        	i++;
        	write("本项计策发生错误，请选择其他计策：\n");
        	break;
        }
        me->add_temp("Mrjob_hortation",can[arg]);
        if(i<1)
        {
        	me->set_temp("Mrjob_over", 1);
        	me->set_temp("Mrjob_hortation", j);
        	message_vision("$N对$n说道：来日方常我们后会有期。\n$N健步离开了。\n",
                 	ob, me);
		destruct(ob);
        	write("你完成了本次的征召任务。\n");
        	return 1;
        
        }
       	write("你还有"+chinese_number(i)+"项计策可用。\n");
       	write("选择计策代码：");
        input_to("do_canvass",me,ob,job,i,j);

        return 1;
}
string get_msg()
{
	string msg;
	
        msg =  "─────────────────────────────────\n";
        msg += "1.反间计(fj)    2.宝物诱惑(bw)    3.金钱诱惑(jq)    4.地位诱惑(dw)\n"
               "5.抱负说(bf)    6.夸赞武力(wl)    7.夸赞魅力(ml)    8.夸赞才学(cx)\n"
               "9.美人计(mr)   10.恶言恐吓(kh)   11.武力征服(zf)   12.结束征召(js)\n"
              "─────────────────────────────────\n";
        msg += "选择计策代码：";
	return msg;
}