//吏部尚书

#include <ansi.h>
inherit NPC;

#include <title.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_ciguan();
int ask_tasks();
int ask_yin();
int ask_promote();
int ask_bac();
int ask_zhenxuan();
int ask_fail();
int position_me(object me);
void create()
{
    set_name("吏部尚书", ({"libu shangshu", "shangshu"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的吏部尚书。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",2);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
    set_temp("ming/increasecredit",1+random(5));
    
	set("inquiry", ([
	
     "工作": (: ask_tasks :),
     "job": (: ask_tasks :),
     "失败": (: ask_fail :),
     "fail": (: ask_fail :),
     "官印": (: ask_yin :),
     "yin": (: ask_yin :),
     "升迁": (: ask_promote :),
     "promote": (: ask_promote :),
     "备案": (: ask_bac :),
     "backup": (: ask_bac :),
     "辞官": (: ask_ciguan :),
     "ciguan": (: ask_ciguan :),
	 "甄选": (: ask_zhenxuan :),
     "zhenxuan": (: ask_zhenxuan :),
	]));

    setup();
    setup_player_name();
}

void init()
{
    add_action("do_guan","guan");
}

int ciguan(object me)
{
    message_vision(HIC"$N向皇宫的方向一长揖，既然辞去了大明的官职，从此再无牵挂。\n"NOR,me);
    return 1;
}


int ask_ciguan()
{
    int ciguan_exp,ciguan_gold,exp;
    object me=this_player();
    object ob=this_object(),ming;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT}),*names=({});
	string color1=color[random(sizeof(color))];
    
    if (!me->query("mingpin"))
    {
        tell_object(me,"你根本就不是大明的官员，来生什么事？\n");
        return 1;
    }
    if (!me->query_temp("大明辞官"))
    {
        message_vision("$N道：辞官意味着放弃在大明的一切，当然朝廷也不会亏待与你，你想清楚了就来跟我辞官吧。\n",ob);
        me->set_temp("大明辞官",1);
        return 1;
    }
    me->set_title(TITLE_MING1,color1+"闲云野鹤"+NOR);
	me->set_title(TITLE_MING2);
	me->set_title(TITLE_MING3);
    ciguan_exp=me->query("combat_exp")/225*(6-(int)me->query("mingpin"))+me->query("combat_exp")/175000*me->query("ming/credit");
    if (wizardp(me))
    {
        tell_object(me,ciguan_exp+"\n");
    }
    if (ciguan_exp>1000000)
    {
        ciguan_exp=1000000+(ciguan_exp-1000000)/5*4;
    }
    if (ciguan_exp>2000000)
    {
        ciguan_exp=2000000+(ciguan_exp-2000000)/5*3;
    }
    if (ciguan_exp>3000000)
    {
        ciguan_exp=3000000+(ciguan_exp-3000000)/10*3;
    }
    if (ciguan_exp>3500000)
    {
        ciguan_exp=3500000+(ciguan_exp-3500000)/10*1;
    }
    ciguan_gold=(6-(int)me->query("mingpin"))*1000000+me->query("ming/credit")*5000;
	if (ciguan_gold>0)
	{
		message_vision("$N道：人各有志，我也不拦你。大明待官员一向优渥，这里再赠你仪程一份。\n",ob);
		MONEY_D->pay_player(me,ciguan_gold);
	}
    
    if (ciguan_exp<0)
    {
        ciguan_exp=0;
    }
    if (me->query("mingpin")>4) //降低比例
    {
        ciguan_exp=1000+random(2000);
    }
    me->add("combat_exp",ciguan_exp);
    tell_object(me,HIW"回想起在大明为官的经历，你的经验增加了"+chinese_number(ciguan_exp)+"点。\n"NOR);
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	if (ming->query("all_the_daming_officers"))
	{
		names=ming->query("all_the_daming_officers");
	}
	if (member_array(me->query("id"),names)!=-1)
	{
		names-=({me->query("id")});
	}
	ming->set("all_the_daming_officers",names);
    ming->save();
    me->delete_temp("大明辞官");
    me->delete("mingpin");
    me->delete("ming");
    me->set("ming_already_ciguan",1);
    me->add_busy(1);
    delete_officer(me);
    call_out("ciguan",1,me);
    return 1;
    
}

int ask_bac()
{
    object me=this_player();
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你根本不是大明官员，备案干嘛？\n");
        me->add_busy(2);
        return 1;
    }
    if (me->query("ming/pro"))
    {
        tell_object(me,"大人早先已决定从事"+me->query("ming/pro")+"职，无法再改变了。\n");
        me->add_busy(2);
        return 1;
    }
    else
    {
        me->set("ming/pro","文");
        tell_object(me,"大人从此正式成为我大明文官系统中一员。\n");
        me->add_busy(2);
        return 1;
    }
}

int do_guan()
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi"),me=this_player();
    mapping *title;
    int i;
    string msg="";
    ob->restore();
    if (me->query("id")!="zine")
    {
        return 0;
    }
    title=ob->query("give_titles");
    if (!title)
    {
        tell_object(me,"暂无记录\n");
        return 1;
    }
    for (i=0;i<sizeof(title);i++)
    {
        msg+="职务："+title[i]["title"];
        msg+="官员："+title[i]["owner"];
        msg+="\n";
    }
    if (msg)
    {
        tell_object(me,msg);
    }
    return 1;
}

int ask_promote()
{
    object me=this_player();
    int i,pin=me->query("mingpin");
	string pro=me->query("ming/pro");
	mapping require;
	//文     武
//1 3500 1 3500
//2 1600 2 2100
//3 750  3 1250
//4 240  4 650
//5 120  5 220
//6 25   6 25
//7 10   7 -
//8 5
//9 -
	mapping *promote_require=({
        (["pro":"文","pin":1,"credit":3500,"designate_effect":100,]),
		(["pro":"文","pin":2,"credit":1600,"designate_effect":40,]),
		(["pro":"文","pin":3,"credit":750,"designate_effect":15,]),
		(["pro":"文","pin":4,"credit":240,"designate_effect":10,]),
		(["pro":"文","pin":5,"credit":120,"designate_effect":0,]),
		(["pro":"文","pin":6,"credit":25,"designate_effect":0,]),
		(["pro":"文","pin":7,"credit":10,"designate_effect":0,]),
		(["pro":"文","pin":8,"credit":5,"designate_effect":0,]),
		(["pro":"武","pin":1,"credit":3500,"designate_effect":100,]),
		(["pro":"武","pin":2,"credit":2100,"designate_effect":40,]),
		(["pro":"武","pin":3,"credit":1250,"designate_effect":15,]),
		(["pro":"武","pin":4,"credit":650,"designate_effect":10,]),
		(["pro":"武","pin":5,"credit":220,"designate_effect":0,]),
		(["pro":"武","pin":6,"credit":25,"designate_effect":0,]),
	});
    if (me->is_busy() || me->is_fighting())
    {
		command("say 你这么忙，过些时候再来吧！");
        return 1;
    }
    if (!pin)
    {
        command("say 老夫执掌吏部二十余年，大明官员都见过，怎么不认识你？");
        return 1;
    }
	pin=pin-1;
    if (pin==0)
    {
        command("say 大人早已位极人臣，升无可升了。");
        return 1;
    }
    if (!pro)
    {
        command("say 升为高级官员之前，你要先去想好今后是做文臣还是武将，选定之后，不能再改了。");
        command("say 文臣就在老夫这里备案，武将要去五军都督府留名(sign)。");
        return 1;
    }
	for (i=0;i<sizeof(promote_require);i++)
	{
		if (pin==promote_require[i]["pin"]&&pro==promote_require[i]["pro"])
		{
			require=promote_require[i];
			break;
		}
	}
	if (!require)
	{
		command("say 你的官品需要Zine来解决。\n");
		return 1;
	}
    if (me->query("ming/credit")<require["credit"]-(int)me->query("ming/designate_obtain")*require["designate_effect"])
    {
        command("say 大人加入我大明后，种种功绩吏部全有记录，可惜资历尚欠缺了点。");
		command("say 要升任"+chinese_number(pin-1)+"品官员，至少需要"+require["credit"]+"点功绩。");
        return 1;
    }
    if (pin==2&&!me->query("ming/2to1"))
    {
        command("say 一品名额有限，论资排辈暂时轮不到你。");
        return 1;
    }
	if (me->query("ming/designate_obtain")&&pin<=4)
	{
		me->delete("ming/designate_obtain");
	}
    command("say 大人的资历功绩足以升任"+chinese_number(pin)+"品官员，请静候佳音吧。");
    return 1;
}

int ask_yin()
{
    object me=this_player();
    object* inv;    
    object guanyin;
    int i;
    inv = deep_inventory(me);
    if (!me->query("mingpin"))
    {
        command("say 老夫执掌吏部二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    for(i=sizeof(inv)-1; i>=0; i--)
    {
        if((inv[i])->query("guanyin"))
        {
            command("say 你身上不是正有一具官印吗？\n");
            return 1;
        }
    }
    me->add_busy(1);
    guanyin=new("/d/yingtianfu/neicheng/obj/guanyin");
    guanyin->set("owner",me->query("id"));
    guanyin->move(me);
    message_vision("$N拿出一具官印，交给$n。\n",this_object(),me);
    return 1;
}

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("mingtasks"))
    {
        command("say 你记错了吧？我什么时候给过你任务？");
        return 1;
    }
    if (!me->query_temp("mingtasks_want_abandon"))
    {
        command("say 你真的要放弃吗？");
        tell_object(me,"如需放弃本次大明任务，请再次输入"+HIG+"ask shangshu about fail。\n"+NOR);
        me->set_temp("mingtasks_want_abandon",1);
        return 1;
    }
    command("say 好吧，我另找别人去做了。");
    me->delete_temp("mingtasks_want_abandon");
    me->delete_temp("mingtasks");
    return 1;
}

int ask_tasks()
{
    object me=this_player();
    object ob=this_object();
	mapping *tasks=({
		(["name":"鸿胪寺","id":"honglusi","officer":"鸿胪寺卿","start_pin":9]),
		(["name":"翰林院","id":"hanlinyuan","officer":"翰林学士","start_pin":9]),
		(["name":"兵部","id":"bingbu","officer":"兵部尚书","start_pin":9]),
		(["name":"工部","id":"gongbu","officer":"工部尚书","start_pin":9]),
		(["name":"太医院","id":"taiyiyuan","officer":"太医院使","start_pin":9]),
		(["name":"户部","id":"hubu","officer":"户部尚书","start_pin":9]),
		(["name":"礼部","id":"libu2","officer":"礼部尚书","start_pin":9]),
		(["name":"五军都督府","id":"dudufu","officer":"五军都督府都督同知","start_pin":9]),
		(["name":"吏部","id":"libu","officer":"吏部侍郎","start_pin":9]),
		(["name":"刑部","id":"xingbu","officer":"刑部尚书","start_pin":9]),
		(["name":"宗人府","id":"zongrenfu","officer":"宗人令","start_pin":9]),
		(["name":"詹事府","id":"zhanshifu","officer":"詹士府詹士","start_pin":9]),
		(["name":"太常寺","id":"taichangsi","officer":"太常寺卿","start_pin":9]),
		(["name":"大理寺","id":"dalisi","officer":"大理寺卿","start_pin":9]),
	});
	mapping give_task;
    string *tasks_mj=({"兵部","工部","户部","五军都督府","吏部","刑部","宗人府","詹事府"});
	string *tasks_mj_id=({"bingbu","gongbu","hubu","dudufu","libu","xingbu","zongrenfu","zhanshifu"});
	string title="",new_title,name,*titles;
    int tasknumber,cdtime=3600*(int)me->query("mingpin");
	if (identification(me,"詹士府詹士"))
	{
		cdtime-=3600;
	}
    if (me->query("mingjiaonewbiejob/damingstart")&&time()-me->query("mingjiaonewbiejob/damingstart")<240)
    {
        command("say 虽然你是明教来的客卿，也不能接了任务不做是不是？等等再来吧。\n");
        return 1;
    }
    if (me->query("mingjiaonewbiejob/daming"))//明教，大明互通
    {
        if (me->query("mingjiaonewbiejob/damingfinish"))
        {
            command("say 你已经完成了，快去找杨左使复命吧。\n");
            return 1;

        }
        if (me->query_temp("mingtasks"))
        {
            command("say 你已经领过任务了，还不快去做？\n");
            return 1;
        }
        tasknumber=random(sizeof(tasks_mj));
        command("say 现在"+tasks_mj[tasknumber]+"人手不足，你去帮帮他们吧。\n");
        me->set("mingjiaonewbiejob/damingstart",time());
        me->set_temp("mingtasks/"+tasks_mj_id[tasknumber]+"/start",1);
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 老夫执掌吏部二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
    if (me->query_temp("mingtasks"))
    {
		if (me->query("mingpin")>3)
        command("say 你已经领过任务了，还不快去做？");
		else
		command("say 大人快去吧。");
        return 1;
    }
    if ((int)me->query("mud_age")-(int)me->query("ming/taskstime")<cdtime)
    {
        command("say 朝廷也不能把官员给累死，你先去休息一会吧。");
        return 1;
    }
    me->add_busy(1);
    if (!me->query("ming/special"))
    {
        command("say 你有空的时候去通政司报个到(baodao)。");
    }
    if (me->query("mingpin")>6)
    {
        command("say 朝廷现在在裁汰冗员，你有空多去帮帮苏州的老夫子。");
        return 1;
    }
    
    if (me->query("mingpin")==1)
    {
        command("say 老大人乃国之柱石，下官怎敢劳动老大人？");
        return 1;
    }
    else
    {
		for (int i=0;i<sizeof(tasks);i++)
		{
			if (tasks[i]["start_pin"]<me->query("mingpin"))
			{
				tasks-=({tasks[i]});
			}
		}
		if (sizeof(tasks))
		give_task=tasks[random(sizeof(tasks))];
		else
		{
			command("say 暂时没有任何任务可以给你。");
			return 1;
		}
		title=TITLE_MING1;
		if (title)
		{
			titles=me->query("multi_title");
			if (titles)
			{
				if (member_array(title,titles)==-1)
				{
					me->set("multi_title", ({title}));
				}
			}
			else
			{
				me->set("multi_title", ({title}));
			}
			
		}
		title="";
        me->set("ming/taskstime",me->query("mud_age"));
		me->set_temp("mingtasks/"+give_task["id"]+"/start",1);
		name=me->query("name")[0..1];
		if (me->query("mingpin")==2)
		{
			title=me->get_title(TITLE_MING1)+HIW+"兼"+give_task["officer"]+NOR+" "+me->query("name")+"(" + capitalize(me->query("id")) + ")";
			new_title="暂兼"+give_task["officer"];
		}
		if (me->query("mingpin")==3)
		{
			title=me->get_title(TITLE_MING1)+WHT+"暂代"+title+NOR+" "+me->query("name")+"(" + capitalize(me->query("id")) + ")";
			new_title="暂代"+give_task["officer"];
		}
		if (title!="")
		{
			if (me->query("ming/title")!=give_task["officer"])
			{
				command("say 此刻"+give_task["name"]+"事务繁重，毫无头绪，"+name+"大人去"+new_title+"一职一段时间吧。");
				me->set_temp("apply/short",title);
				me->set_temp("ming_multi_title",time());
			}
			else
			command("say 此刻"+give_task["name"]+"事务繁重，大人去帮帮他们吧。");
		}
		else
		{
			command("say 此刻"+give_task["name"]+"事务繁重，"+give_task["officer"]+"正在找人帮忙，你去看看吧。");
		}
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
    int n;
	if (ruyi->query("jade_ruyi")!=1)
	    return notify_fail("吏部尚书不想要你的东西。\n");
    else
    {
        n=4+random(3);
        message_vision("吏部尚书接过$N手里的嘉奖令，颤声道：皇上御赐的嘉奖令。\n",me);
        message_vision("吏部尚书把嘉奖令封存起来，并仔细记下了$N的功绩。\n",me);
        me->add_busy(1);
        me->add("ming/credit",n);
        tell_object(me,"你偷偷瞄见，吏部尚书在你名下功绩加了"+chinese_number(n)+"点。\n");
        call_out("dest",0,ruyi);
        return 1;
    }
    
}

int check_list(object me,string depart)
{
    object npc,ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i,flag=0;
    string name,npc_pool;
    if (!me)
    {
        return 1;
    }
    if (!depart)
    {
        return 1;
    }
    ob->restore();
    for (i=0;i<1000;i++)
    {
        if (ob->query("daming_backup_officer/"+i))
        {
            npc=new(__DIR__"random_npc");
            npc_pool="daming_backup_officer/";
            npc->set_init_ability(npc_pool,i);
            ob->delete("daming_backup_officer/"+i);
            ob->save();
            name=npc->query("name");
            command("say 好吧，"+name+"从此就是"+me->query("ming/depart_name")+"的官员了。\n");
            tell_object(me,name+"已经回到了了"+me->query("ming/depart_name")+"，开始待命干活了。\n");
            add_officer_in(npc,depart);
            flag=1;
            destruct(npc);
            return 1;
        }
    }
    if (flag==0)
    {
        command("say 本官现在这里也没有合适的人手啊。你等等再来吧。");
    }
    return 1;
}

int ask_zhenxuan()
{
    object ob=this_object(),me=this_player();
    string depart;
    if (!me->query("mingpin"))
    {
        return 0;
    }
    if (ob->is_busy())
    {
        tell_object(me,ob->name()+"这会正忙着呢。\n");
        return 1;
    }
    if (me->query("mingpin")>3)
    {
        tell_object(me,"甄选官员只有各部三品以上大员方可进行。\n");
        return 1;
    }
    if (!me->query("ming/depart"))
    {
        me->set("ming/depart",get_my_depart(me));
    }
    depart=classify_depart(me);
    command("say "+me->query("ming/depart_name")+"现在缺人？让我查一查。");
    ob->start_busy(5);
    remove_call_out("check_list");
    call_out("check_list",3,me,depart);
    return 1;
}