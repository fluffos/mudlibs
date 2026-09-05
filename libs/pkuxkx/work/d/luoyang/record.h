#include <ansi.h>
#define TIME this_object()->query("record_time")
#define MAX this_object()->query("max_record_item")
#define RECORD "/data/business/exp_record_base_on_time"+TIME
string query_save_file()
{
        return RECORD;
}
string look_bang();
string look_pai();
void init()
{
    add_action("do_start","start");
    add_action("do_exp","listexp");
    add_action("do_del","del");
    add_action("do_detail","detail");
    add_action("do_query","query");
}

int reset_desc()
{
    set("item_desc", ([
		"bang" : (:look_bang:),
        "pai" :(:look_pai:),]));
}

string get_time(int time)
{
    string msg="";
    int hr,min,sec,tmp;
    if (time<=0)
    {
        return "error.";
    }
    if (time>3600)
    {
        hr=time/3600;
        tmp=time%3600;
        if (tmp>60)
        {
            min=tmp/60;
            tmp=tmp%60;
        }
        else
        {
            min=0;
            tmp=tmp%60;
        }
        if (tmp>0)
        {
            sec=tmp;
        }
        else
        {
            sec=0;
        }
    }
    else if (time>60)
    {
        hr=0;
        min=time/60;
        tmp=time%60;
        if (tmp>0)
        {
            sec=tmp;
        }
        else
        {
            sec=0;
        }
    }
    else
    {
        hr=0;
        min=0;
        sec=time;
    }
    if (hr)
    {
        msg+=chinese_number(hr)+"小时";
    }
    if (min)
    {
        msg+=chinese_number(min)+"分";
    }
    if (sec)
    {
        msg+=chinese_number(sec)+"秒";
    }
    return msg;
}

string get_color(int i)
{
    switch (i)
    {
    case 1:
    return HBBLU+HIR;
    case 2:
    return HBBLU+RED;
    case 3:
    return HBBLU+HIY;
    case 4:
    return HBBLU+YEL;
    case 5:
    return HBBLU+HIG;
    case 6:
    return HBBLU+GRN;
    case 7:
    return HBBLU+HIC;
    case 8:
    return HBBLU+CYN;
    case 9:
    return HBBLU+HIM;
    case 10:
    return HBBLU+MAG;
    default:
    return HBBLU+BLU;
    }
}

string look_pai()
{
    return "这里是比较各方武林人士在『"+get_time(TIME)+"』的时间内谁获得exp最快的排行榜，用"+HIW+"start"+NOR+"命令开始个人"+get_time(TIME)+"挑战。\n此榜运行一段时间之后，可以用"+HIW+"detail"+NOR+"察看排行榜的趣闻，用"+HIW+"query"+NOR+"查询自己挑战的剩余时间。\n
    "+HIW+"注：此处禁止乱丢垃圾。\t个人可以同时挑战所有五个榜。\n"+NOR;
}
int do_del(string arg)
{
    int n,i,m,j,k,flag=0;
    object me=this_player(),ob=this_object();
    string serial;
    if (me->query("id")!="zine")
    {
        return 0;
    }
    if (!arg||sscanf(arg,"%d",n)!=1)
    {
        tell_object(me,"你要删除哪条记录？\n");
        return 1;
    }
    if (n<1||n>MAX)
    {
        tell_object(me,"记录在1至"+MAX+"之间。\n");
        return 1;
    }
    ob->restore();
    reset_desc();
    serial="record_"+TIME;
    for (i=1;i<=MAX;i++)
    {
        if (ob->query(serial+"/no"+i+"record")==0&&i<=MAX)
        {
            flag=1;
            m=i-1;
            break;
        }
    }
    if (flag==0)
    {
        m=MAX;
    }
    for (i=n;i<=m;i++)
    {
        k=i+1;
        ob->set(serial+"/no"+i+"record",ob->query(serial+"/no"+k+"record"));
        ob->set(serial+"/no"+i+"id",ob->query(serial+"/no"+k+"id"));
        ob->set(serial+"/no"+i+"name",ob->query(serial+"/no"+k+"name"));
    }
    ob->save();
    tell_object(me,"你删除了第"+n+"条记录。\n");
    return 1;
}

int do_detail()
{
    object ob=this_object();
    object me=this_player();
    string msg="\n排行榜趣闻：\n";
    ob->restore();
    reset_desc();
    if (ob->query("max_peer"))
        msg+="本榜上榜次数最多的人："+ob->query("max_peer_name")+"("+capitalize(ob->query("max_peer_id"))+")，累计上榜"+ob->query("max_peer")+"次。\n";
    if (ob->query("max_first"))
        msg+="登上榜首次数最多的人："+ob->query("max_first_name")+"("+capitalize(ob->query("max_first_id"))+")，累计上榜"+ob->query("max_first")+"次。\n";
    if (ob->query("longest_time"))
        msg+="榜首保持最久的人："+ob->query("longest_time/name")+"("+capitalize(ob->query("longest_time/id"))+")，保持记录"+get_time(ob->query("longest_time/period"))+"，当时记录为"+ob->query("longest_time/record")+"\n";
    if (ob->query("shortest_time/period"))
        msg+="榜首保持最短的人："+ob->query("shortest_time/name")+"("+capitalize(ob->query("shortest_time/id"))+")，保持记录"+get_time(ob->query("shortest_time/period"))+"，当时记录为"+ob->query("shortest_time/record")+"\n";
    if (me->query("count_in_bang"))
    {
        msg+="▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n";
        msg+="你共计上榜"+chinese_number(me->query("count_in_bang"))+"次";
    }
    if (me->query("count_in_bang_adv"))
        msg+="，其中占据榜首"+chinese_number(me->query("count_in_bang_adv"))+"次。";
    msg+="\n";
    if (msg=="\n排行榜趣闻：\n\n")
    tell_object(me,"这里暂时没有什么趣闻。\n");
    else
    tell_object(me,msg);
    return 1;
}
string fake_name(string name)
{
    name=name[0..0]+"某";
    return name;
}

string fake_id(string id)
{
    int i,len;
    len=strwidth(id);
    id=id[0..0];
    for (i=0;i<len-1;i++)
    {
        id+="*";
    }
    return id;
}
string look_bang()
{
    object ob=this_object();
    object me=this_player();
    string msg,serial,place,name,id,col="|";
    int i,record,rela_record,flag=0;
    float calc,hr;
    ob->restore();
    reset_desc();
    if (ob->query("record_"+TIME))
    {
        serial="record_"+TIME;
        msg="\n"+sprintf("%|54s\n",HIW+"『"+get_time(TIME)+"』自我挑战玩家记录")+NOR;
        msg+=HBBLU+HIW+sprintf("%s%|8s%s%|16s%s%|14s%s%|12s%s%|12s%s%s\n",col,"名次",col,"姓名",col,"id",col,"获得经验记录",col,"经验/小时",col,NOR);
        for (i=1;i<=MAX;i++)
        {
            if (ob->query(serial+"/no"+i+"name"))
            {
                place="第"+chinese_number(i)+"名";
                name=COLOR_D->uncolor(ob->query(serial+"/no"+i+"name"));
                id=ob->query(serial+"/no"+i+"id");
                hr=to_float(TIME)/3600;
                record=ob->query(serial+"/no"+i+"record");
                calc=to_float(record)/hr;
                rela_record=to_int(calc);
                if (!wizardp(me)&&ob->query(serial+"/no"+i+"anonymous")&&ob->query(serial+"/no"+i+"id")!=me->query("id"))
                {
                    name=fake_name(name);
                    id=fake_id(id);
                }
                id="("+id+")";
                msg+=get_color(i)+sprintf("%s%|8s%s%|16s%s%|14s%s%12d%s%12d%s%s\n",col,place,col,name,col,id,col,record,col,rela_record,col,NOR);
                flag=1;
            }
        }
        if (flag==0)
        {
            msg+=HBBLU+HIW+sprintf("%s%-53s%s\n",col,"暂时未有任何人上榜。",col)+NOR;
        }
        return msg;
    }
    else
    {
        msg="\n"+sprintf("%|54s\n",HIW+"『"+get_time(TIME)+"』自我挑战玩家记录")+NOR;
        msg+=HBBLU+HIW+sprintf("%s%|8s%s%|16s%s%|14s%s%|12s%s%s\n",col,"名次",col,"姓名",col,"id",col,"获得经验记录",col,NOR);
        msg+=HBBLU+HIW+sprintf("%s%-53s%s\n",col,"暂时未有任何人上榜。",col)+NOR;
        return msg;
    }
}
int compare(int inc,string serial,int i,object ob)
{
    int j=i+1;
    if (inc>ob->query(serial+"/no"+j+"record")&&inc<=ob->query(serial+"/no"+i+"record"))
    {
        return j;
    }
    return 0;
}

int RecordPast(object ob,string serial)
{
    int num=sizeof(ob->query("past_record"))+1;
    int longest_time=ob->query("longest_time/period"),shortest_time=ob->query("shortest_time/period"),period;
    ob->set("past_record/"+num+"/id",ob->query(serial+"/no"+1+"id"));
    ob->set("past_record/"+num+"/name",ob->query(serial+"/no"+1+"name"));
    ob->set("past_record/"+num+"/record",ob->query(serial+"/no"+1+"record"));
    ob->set("past_record/"+num+"/time",time());
    if (time()-(int)ob->query(serial+"/no"+1+"time")>longest_time)
    {
        period=time()-(int)ob->query(serial+"/no"+1+"time");
        ob->set("longest_time/period",period);
        ob->set("longest_time/id",ob->query(serial+"/no"+1+"id"));
        ob->set("longest_time/name",ob->query(serial+"/no"+1+"name"));
        ob->set("longest_time/record",ob->query(serial+"/no"+1+"record"));
    }
    if (shortest_time)
    {
        if (time()-(int)ob->query(serial+"/no"+1+"time")<shortest_time)
        {
            period=time()-(int)ob->query(serial+"/no"+1+"time");
            ob->set("shortest_time/period",period);
            ob->set("shortest_time/id",ob->query(serial+"/no"+1+"id"));
            ob->set("shortest_time/name",ob->query(serial+"/no"+1+"name"));
            ob->set("shortest_time/record",ob->query(serial+"/no"+1+"record"));
        }
    }
    else
    {
        period=time()-(int)ob->query(serial+"/no"+1+"time");
        ob->set("shortest_time/period",period);
        ob->set("shortest_time/id",ob->query(serial+"/no"+1+"id"));
        ob->set("shortest_time/name",ob->query(serial+"/no"+1+"name"));
        ob->set("shortest_time/record",ob->query(serial+"/no"+1+"record"));
    }
    
}

int Count_in(object ob,object me,int flag)
{
    int max_peer,max_first,my;
    if (!flag)
    {
        me->add("count_in_bang",1);
    }
    else
    {
        me->add("count_in_bang",1);
        me->add("count_in_bang_adv",1);
    }
    max_peer=ob->query("max_peer");
    max_first=ob->query("max_first");
    my=me->query("count_in_bang");
    if (my>=max_peer)
    {
        ob->set("max_peer",my);
        ob->set("max_peer_id",me->query("id"));
        ob->set("max_peer_name",me->query("name"));
    }
    my=me->query("count_in_bang_adv");
    if (my>=max_first)
    {
        ob->set("max_first",my);
        ob->set("max_first_id",me->query("id"));
        ob->set("max_first_name",me->query("name"));
    }
}

int RecordRankMe(string serial,object ob,int rank,int inc,object me,int anonymous)
{
    string name,id;
    int i,len;
    name=COLOR_D->uncolor(me->query("name"));
    ob->set(serial+"/no"+rank+"record",inc);
    ob->set(serial+"/no"+rank+"id",me->query("id"));
    ob->set(serial+"/no"+rank+"name",name);
    ob->set(serial+"/no"+rank+"time",time());
    if (anonymous)
    {
        ob->set(serial+"/no"+rank+"anonymous",1);
    }
    else
    {
        ob->set(serial+"/no"+rank+"anonymous",0);
    }
}

int get_place(int inc,string serial,object ob,object me,int anonymous)
{
    int i,j,k,l,m=0,n,flag=0;
    ob->restore();
    reset_desc();
    for (i=1;i<=MAX;i++)
    {
        if (ob->query(serial+"/no"+i+"record")==0&&i<MAX)
        {
            m=i;
            n=m-1;
            break;
        }
    }
    for (i=1;i<=MAX;i++)
    {
        if (inc>ob->query(serial+"/no"+1+"record"))//最大
        {
            if (ob->query(serial+"/no"+MAX+"record"))
            RecordPast(ob,serial);
            for (j=MAX-1;j>0;j--)
            {
                l=j+1;
                ob->set(serial+"/no"+l+"record",ob->query(serial+"/no"+j+"record"));
                ob->set(serial+"/no"+l+"id",ob->query(serial+"/no"+j+"id"));
                ob->set(serial+"/no"+l+"name",ob->query(serial+"/no"+j+"name"));
            }
            RecordRankMe(serial,ob,1,inc,me,anonymous);
            Count_in(ob,me,1);
            ob->save();
            tell_object(me,HIR+"自我挑战结束，恭喜！你现在是北侠"+get_time(TIME)+"时间内加经验最快的人了。\n"+NOR);
            if (ob->query(serial+"/no"+MAX+"record")>1)
            {
                CHANNEL_D->do_channel(this_object(), "jh","洛阳城传闻：" + me->query("name")+"(" + capitalize(me->query("id")) + ")"+"现在是整个北侠"+get_time(TIME)+"时段内练功最快的人了！", -1);
            }
            return 1;
        }
        else if (inc<=ob->query(serial+"/no"+MAX+"record"))//不入榜
        {
            tell_object(me,WHT+"自我挑战结束，事实证明，这次你做得不算快，至少和真正快的人相比还是有差距的。\n"+NOR);
            return 1;
        }
        else if (m&&inc<=ob->query(serial+"/no"+n+"record"))
        {
            RecordRankMe(serial,ob,m,inc,me,anonymous);
            Count_in(ob,me,0);
            ob->save();
            tell_object(me,HIR+"自我挑战结束，恭喜！你现在是北侠"+get_time(TIME)+"时间内加经验第"+chinese_number(m)+"快的人了。\n"+NOR);
            return 1;
        }
        else //中间
        {
            if (k=compare(inc,serial,i,ob))
            {
                flag=1;
                for (j=MAX-1;j>=k;j--)
                {
                    l=j+1;
                    ob->set(serial+"/no"+l+"record",ob->query(serial+"/no"+j+"record"));
                    ob->set(serial+"/no"+l+"id",ob->query(serial+"/no"+j+"id"));
                    ob->set(serial+"/no"+l+"name",ob->query(serial+"/no"+j+"name"));
                }
                RecordRankMe(serial,ob,k,inc,me,anonymous);
                Count_in(ob,me,0);
                ob->save();
                tell_object(me,HIR+"自我挑战结束，恭喜！你现在是北侠"+get_time(TIME)+"时间内加经验第"+chinese_number(k)+"快的人了。\n"+NOR);
                return 1;
            }
        }         
    }
    if (flag==0)
    {
        tell_object(me,WHT+"自我挑战结束，事实证明，这次你做得不算快，至少和真正快的人相比还是有差距的。\n"+NOR);
        return 1;
    }
}

string finish_by(string arg,int flag)
{
    object me,ob=this_object();
    int post_exp,exp,inc;
    string serial;
    if (!arg)
    {
        return "手动更新谁的记录？\n";
    }
    if (!me=find_player(arg))
    {
        return arg+"不在线！\n";
    }
    if (!me->query_temp("exp_record_base_on_time/"+TIME))
    {
        return "记录丢失！\n";
    }
    if (wizardp(me))
    {
        return "禁止巫师上榜！\n";
    }
    post_exp=(int)me->query_temp("exp_record_base_on_time/"+TIME);
    exp=(int)me->query("combat_exp");
    if (!flag&&me->query("grandmaster"))
    {
        inc=exp-post_exp-1000000;
    }
    else
    {
        inc=exp-post_exp;
    }
    me->delete_temp("exp_record_base_on_time/"+TIME);
    if (inc<=0)
    {
        return "exp未增长！\n";
    }
    serial="record_"+TIME;
    get_place(inc,serial,ob,me,0);
    return "进入数据比较……\n";
}

int finish(object me,int flag)
{
    object ob=this_object();
    int post_exp,exp,inc;
    string serial;
    if (!me)
    {
        return 2;
    }
    if (!me->query_temp("exp_record_base_on_time/"+TIME))
    {
        return 3;
    }
    if (wizardp(me))
    {
        return 4;
    }
    post_exp=(int)me->query_temp("exp_record_base_on_time/"+TIME);
    exp=(int)me->query("combat_exp");
    if (!flag&&me->query("grandmaster"))
    {
        inc=exp-post_exp-1000000;
    }
    else
    {
        inc=exp-post_exp;
    }
    me->delete_temp("exp_record_base_on_time");
    if (inc<=0)
    {
        return 5;
    }
    serial="record_"+TIME;
    get_place(inc,serial,ob,me,0);
    return 1;
}

int finish_passive(string id,int flag)
{
    object me,ob=this_object();
    int post_exp,exp,inc;
    string serial;
    if (!me=find_player(id))
    {
        return 2;
    }
    if (!me->query("exp_record_base_on_time/"+TIME+"period")||!me->query("exp_record_base_on_time/"+TIME+"start_from"))
    {
        return 3;
    }
    post_exp=(int)me->query("exp_record_base_on_time/"+TIME);
    if (time()-(int)me->query("exp_record_base_on_time/"+TIME+"start_from")>me->query("exp_record_base_on_time/"+TIME+"period")+10)
    {
        me->delete("exp_record_base_on_time");
        return 4;
    }
    me->delete("exp_record_base_on_time");
    if (wizardp(me))
    {
        return 5;
    }
    exp=(int)me->query("combat_exp");
    if (!flag&&me->query("grandmaster"))
    {
        inc=exp-post_exp-1000000;
    }
    else
    {
        inc=exp-post_exp;
    }
    if (inc<=0)
    {
        return 6;
    }
    serial="record_"+TIME;
    get_place(inc,serial,ob,me,1);
    return 1;
}

int do_query()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("exp_record_base_on_time/"+TIME))
    {
        tell_object(me,"你并未参加这里的『"+get_time(TIME)+"』个人挑战。\n");
        return 1;
    }
    if (!me->query_temp("exp_record_base_on_time/"+TIME+"duedate"))
    {
        tell_object(me,"你的数据丢失，不符合查询条件。\n");
        return 1;
    }
    if (time()>=me->query_temp("exp_record_base_on_time/"+TIME+"duedate"))
    {
        tell_object(me,"你的挑战时间已经达到，还没有出结果吗？如果是，请联系Zine吧。\n");
        return 1;
    }
    tell_object(me,"尚余"+get_time((int)me->query_temp("exp_record_base_on_time/"+TIME+"duedate")-time())+"完成这里的『"+get_time(TIME)+"』个人挑战。\n");
    return 2;
}

int do_start()
{
    object me=this_player();
    object ob=this_object();
    int time=TIME;
    if (me->query_temp("exp_record_base_on_time/"+TIME))
    {
        tell_object(me,"你的『"+get_time(time)+"』自我挑战已经开始了。\n");
        return 1;
    }
    me->set_temp("exp_record_base_on_time/"+TIME,me->query("combat_exp"));
    me->set_temp("exp_record_base_on_time/"+TIME+"duedate",time()+time);
    tell_object(me,HIR"你开始了自我挑战，在"+get_time(time)+"获得尽可能多的经验。\n"NOR);
    if (me->query("grandmaster"))
    {
        call_out("finish",time,me,1);
    }
    else
    {
        call_out("finish",time,me,0);
    }
    return 1;
}

int AI_add_in()
{
    int i,flag=0,time,limit;
    object *users=users();
    string id;
    users = filter_array(users, (: environment :));
    limit=TIME/30;
    for (i=0;i<sizeof(users);i++)
    {
        if (!wizardp(users[i])&&users[i]->query("antirobot/deactivity")<2&&users[i]->query("combat_exp")>10000000&&flag<limit)
        {
            flag+=1;
            time=flag+TIME;
            users[i]->set("exp_record_base_on_time/"+TIME,users[i]->query("combat_exp"));
            users[i]->set("exp_record_base_on_time/"+TIME+"period",time);
            users[i]->set("exp_record_base_on_time/"+TIME+"start_from",time());
            id=users[i]->query("id");
            if (users[i]->query("grandmaster"))
            {
                call_out("finish_passive",time,id,1);
            }
            else
            {
                call_out("finish_passive",time,id,0);
            }
        }
    }
    return 1;
}
