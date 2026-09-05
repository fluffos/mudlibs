//司礼监掌印太监

#include <ansi.h>
inherit NPC;
#include <title.h>


int ask_tasks();
int ask_promote();
void create()
{
    set_name("掌印太监", ({"zhangyin taijian", "taijian","jian"}));
    set("title", HIW"大明 "HIM"司礼监"NOR);
    set("gender", "无性");
    set("age", 60);
    set("long", "他就是当今内廷司礼监的掌印太监。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    set("ming/tj/pin",4);
	set("inquiry", ([
	
     "工作": (: ask_tasks :),
     "job": (: ask_tasks :),
     "升迁": (: ask_promote :),
     "promote": (: ask_promote :),
	
	]));

    setup();
   
}

void init()
{
    add_action("do_select","select");
}

int ask_promote()
{
    string* title1a=({"内宫监 管理","御用监 掌司","司设监 管理","御马监 提督","神宫监 掌司","尚膳监 总理","尚宝监 掌司","尚绶监 掌司",
        "直殿监 掌司","尚衣监 佥书","都知监 司房","惜薪司 总理","钟鼓司 佥书","宝钞司 佥书","混堂司 佥书","兵仗局 提督","银作局 管理",
        "浣衣局 佥书","巾帽局 管理","内织造局 管理","针工局 管理","酒醋面局 管理","司苑局 管理"});//6品
    string* title2a=({"司礼监 秉笔","内宫监 总理","御用监 把总","司设监 总理","御马监 监督","神宫监 佥书",
        "尚膳监 提督","尚宝监 佥书","尚绶监 佥书","直殿监 佥书","尚衣监 管理","都知监 佥书"});//5品副
	string* title2b=({"惜薪司","钟鼓司","宝钞司","混堂司","兵仗局","银作局","浣衣局","巾帽局","内织造局","针工局","酒醋面局","司苑局"});//5品正官
    
    object me=this_player();
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string title;
	string color1=color[random(sizeof(color))];
	string color2=color[random(sizeof(color))];
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (!me->query("ming/tj/pin"))
    {
        command("say 你不是我内廷中人也敢来欺骗杂家？\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        command("say 你到底是何人，混入我内廷？\n");
        return 1;
    }
    if (me->query("ming/tj/pin")>7)
    {
        command("say 你这个小太监，去找李公公吧，别来烦杂家。\n");
        return 1;
    }
    if (me->query("ming/tj/pin")==7)
    {
        if (me->query("ming/credit")>250)
            {
                    title=title1a[random(sizeof(title1a))];
                    me->set("ming/title",title+"太监");
					me->set("title",HIW+"大明 "+HIM+"内廷六品太监 "+color2+title+"太监"+NOR);

          me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+HIM+"内廷六品太监 "+color2+title+"太监"+NOR, "大明");			
					
					me->set("ming/tj/pin",6);
                message("chat",HIW"【大明】内廷任命："+me->query("name")+HIW+"加入内廷后，勤快能干，晋升"+title+"太监。\n"NOR,users());
                command("say 你加入大明内廷，尚算勤勉，从今天起，你就是"+title+"太监了。\n");
                return 1;
            }
            else
            {
                command("say 你这个小皮猴子才来几天就想升职，快滚。\n");
                return 1;
            }
       
    }
    if (me->query("ming/tj/pin")==6)
    {
        if (me->query("ming/credit")>800)
            {
                if (me->query("ming/credit")>900)
                {
                
                    title=title2b[random(sizeof(title2b))];
                    me->set("ming/title",title+"掌印太监");
					me->set("title",HIW+"大明 "+RED+"内廷五品太监 "+color2+title+color1+"掌印太监"+NOR);

          me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+RED+"内廷五品太监 "+color2+title+color1+"掌印太监"+NOR, "大明");

					me->set("ming/tj/pin",5);
                    me->set("ming/tj/zhuguan",1);
                    me->set("ming/tj/office",title+"掌印太监值房");
                    message("chat",HIW"【大明】内廷任命："+me->query("name")+HIW+"加入内廷后，勤快能干，晋升"+title+"掌印太监。\n"NOR,users());
                    command("say 你加入大明内廷，尚算勤勉，从今天起，你就是"+title+"掌印太监了。\n");
                    return 1;
                }
                else
                {
                    title=title2a[random(sizeof(title2a))];
                    me->set("ming/title",title+"太监");
					me->set("title",HIW+"大明 "+MAG+"内廷五品太监 "+color2+title+"太监"+NOR);
			    
			    me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+MAG+"内廷五品太监 "+color2+title+"太监"+NOR, "大明");
				
					me->set("ming/tj/pin",5);
                    me->set("ming/tj/office",title+"太监值房");
                    message("chat",HIW"【大明】内廷任命："+me->query("name")+HIW+"加入内廷后，勤快能干，晋升"+title+"太监。\n"NOR,users());
                    command("say 你加入大明内廷，尚算勤勉，从今天起，你就是"+title+"太监了。\n");
                    return 1;
                }
            }
        else
            {
                command("say 你这个小皮猴子才来几天就想升职，快滚。\n");
                return 1;
            }
       
    }
    
            else
            {
                command("say 十二监掌印太监需要陛下亲自任命的。\n");
                return 1;
            }
    
    
}


int ask_tasks()
{
    object me=this_player();
    object ob=this_object();
    string *tasks=({"内宫监","御用监","司设监","东厂"});
    int tasknumber,cdtime=2400*(int)me->query("ming/tj/pin");
    
    if (!me->query("ming/tj/pin"))
    {
        command("say 你不是我内廷中人也敢来欺骗杂家？\n");
        return 1;
    }
    if (me->query("mud_age")-me->query("ming/tj/gonggui")>60*60*8*(9-(int)me->query("ming/tj/pin")))
    {
        command("say 你好久没去抄写宫规了，先去杂役处吧。\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        command("say 你不是我内廷中人也敢来欺骗杂家？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
    if (me->query_temp("mingtasks"))
    {
        tell_object(me,"你已经领过任务了，还不快去做？\n");
        return 1;
    }
    if ((int)me->query("mud_age")-(int)me->query("ming/taskstime")<cdtime)
    {
        tell_object(me,"内廷最近比较清闲，你过段时间再来吧。\n");
        return 1;
    }
    me->add_busy(1);
    /*if (!me->query("ming/special"))
    {
        tell_object(me,"你有空的时候去通政司报个到(baodao)。\n");
    }*/
    if (me->query("ming/tj/pin")>7)
    {
        command("say 你还没有通过宫规测试，赶紧去杂役处报到吧。\n");
        return 1;
    }
    
    if (me->query("ming/tj/pin")==4)
    {
        command("say 公公当勤去皇上身前问安才是。\n");
        return 1;
    }
    else
    {
        tasknumber=random(sizeof(tasks));
        command("say 现在"+tasks[tasknumber]+"据说被弄得乌烟瘴气，你去监督监督他们吧。\n");
        me->set("ming/taskstime",me->query("mud_age"));
        if (tasknumber==0)
        {
            me->set_temp("mingtasks/neigong/start",1);
        }
        if (tasknumber==1)
        {
            me->set_temp("mingtasks/yuyong/start",1);
        }
        if (tasknumber==2)
        {
            me->set_temp("mingtasks/sishe/start",1);
        }
        if (tasknumber==3)
        {
            me->set_temp("mingtasks/dongchang/start",1);
        }
        return 1;
    }
}

int do_select(string arg)
{
    object me=this_player();
    object ob=this_object();
    string* title2a=({"司礼监 秉笔","内宫监 总理","御用监 把总","司设监 总理","御马监 监督","神宫监 佥书",
        "尚膳监 提督","尚宝监 佥书","尚绶监 佥书","直殿监 佥书","尚衣监 管理","都知监 佥书"});//5品副
	string* title2b=({"惜薪司","钟鼓司","宝钞司","混堂司","兵仗局","银作局","浣衣局","巾帽局","内织造局","针工局","酒醋面局","司苑局"});//5品正官
    string title;
    
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
	string color2=color[random(sizeof(color))];
    if (!me->query_temp("tj/canselect"))
    {
        return 0;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query("ming/tj/pin")<=5)
    {
        
        return notify_fail("公公的今日的地位已升无可升了。\n");
    }
    if (!me->query("ming/tj/pin"))
    {
        command("你不是我内廷中人也敢来欺骗杂家？\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        command("say 你到底是何人，混入我内廷？\n");
        return 1;
    }
    if (!arg)
    {
        return notify_fail("主官(zhuguan)还是次官(ciguan)你必须选一个。\n");
    }
    if (arg=="zhuguan"||arg=="主官")
    {
                    title=title2b[random(sizeof(title2b))];
					me->set("title",HIW+"大明 "+color2+title+color1+"掌印太监"+NOR);
			    
			    me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+color2+title+color1+"掌印太监"+NOR, "大明");

					me->set("ming/tj/pin",5);
                    me->set("ming/tj/zhuguan",1);
                    me->set("ming/tj/office",title+"掌印太监值房");
                    message("chat",HIW"【大明】内廷任命："+me->query("name")+HIW+"加入内廷后，勤快能干，晋升"+title+"掌印太监。\n"NOR,users());
                    command("say 即有皇上旨意，你也选定，从今天起，你就是"+title+"掌印太监了。\n");
                    return 1;
    }
    if (arg=="ciguan"||arg=="次官")
    {
                    title=title2a[random(sizeof(title2a))];
					me->set("title",HIW+"大明 "+color2+title+"太监"+NOR);

			    me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3}), HIW+"大明 "+color2+title+"太监"+NOR, "大明");			
				
					me->set("ming/tj/pin",5);
                    me->set("ming/tj/office",title+"太监值房");
                    message("chat",HIW"【大明】内廷任命："+me->query("name")+HIW+"加入内廷后，勤快能干，晋升"+title+"太监。\n"NOR,users());
                    command("say 你加入大明内廷，尚算勤勉，从今天起，你就是"+title+"太监了。\n");
                    return 1;
    }
    else
    {
        tell_object(me,"你到底选的是什么？\n");
        return 1;
    }
}

int dest(object ruyi)
{
	if(ruyi)
	destruct(ruyi);
	return 1;
}

int accept_object(object me, object ruyi)
{
	if (ruyi->query("ming/tjpromote")!=1)
	    return notify_fail("司礼监掌印太监不想要你的东西。\n");
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (!me->query("ming/tj/pin"))
    {
        return notify_fail("你不是我内廷中人也敢来欺骗杂家？\n");
    }
    if (me->query("ming/tj/pin")<=5)
    {
        
        return notify_fail("公公的今日的地位已升无可升了。\n");
    }
    else
    {
        message_vision("司礼监掌印太监接过$N手里的晋升令，颤声道：皇上亲笔的晋升令。\n",me);
        message_vision("司礼监掌印太监把晋升令封存起来，并仔细记下了$N的功绩。\n",me);
        tell_object(me,"司礼监掌印太监道：按皇上的旨意，你可以选择(select)出任十二监以外掌印太监(zhuguan)，或十二监的次官(ciguan)。\n");
        tell_object(me,"司礼监掌印太监接着道：十二监以外掌印太监以后可出任各地镇守太监，将永无机会问鼎司礼监掌印太监这一职务。\n");
        tell_object(me,"司礼监掌印太监道：不过也不用太在意，毕竟掌印太监只有一人，也不是人人可以做到。还是拿点实惠的好啊。\n");
        me->set_temp("tj/canselect",1);
        me->add_busy(2);
        call_out("dest",0,ruyi);
        return 1;
    }
    
}