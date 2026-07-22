//job之刺杀叛徒
// By yfeng 25/9/99

#include <ansi.h>
#include "list.h"

string give_job(object ob);

string give_job(object ob)
{
	int time;
	mapping mpWhere,mpPassword,mptw;
	object obMishi;
	
	mpWhere=where[random(sizeof(where))];
	mpPassword=password[random(sizeof(password))];
	obMishi=new(__DIR__"mishi");
	obMishi->clone(ob,-20-random(6));//密使比我低20-25级
	command("nod "+ob->query("id"));
	message_vision(CYN"
$N对$n说道：由于火云教反叛告密，我火云教密使"+HIC+obMishi->name()+CYN"近日在"+HIG+mpWhere["name"]+CYN"一带遇难，无法与我们联系，
你且速去"+mpWhere["name"]+"营救我火云特别人物。\n"NOR,this_object(),ob);
	command("tell "+ob->query("id")+" 此人相貌如此这般 这般...");
	command("whisper "+ob->query("id")+" 你与其联络暗号为"+mpPassword["password"]+"，切口为"+mpPassword["confirm"]+"。");
	obMishi->set("guarder_id",ob->query("id"));
	ob->delete_temp("tdh_job");
    ob->set_temp("tdh_job/job_name","保护密使");
    ob->set_temp("tdh_job/password",mpPassword["password"]);
    ob->set_temp("tdh_job/confirm",mpPassword["confirm"]);
    ob->set_temp("tdh_job/time",(time=60+random(25)));// busy time :5-8min
    ob->set_temp("tdh_job/target_name",obMishi->name());
    ob->set_temp("tdh_job/f_where",mpWhere["where"]);
    ob->set_temp("tdh_job/f_city",mpWhere["name"]);
    obMishi->move(mpWhere["where"]);
    while(mpWhere["where"]==(mptw=where[random(sizeof(where))]));
    mpWhere=mptw;
    ob->set_temp("tdh_job/s_where",mpWhere["where"]);
    ob->set_temp("tdh_job/s_city",mpWhere["name"]);	
    ob->set_temp("tdh_job/job_fail_msg",HIY"突然，一个细若蚊嘘的声音传入你耳：叛徒正派高手追杀于你，此地不宜久留！\n"NOR);
    obMishi->apply_condition("tdh_job_mishi",time-2);
    ob->apply_condition("tdh_job_busy",time);
    call_out("meet_fanpan",20+random(21),ob);//20-40秒后，遇到第一个反叛
    return "此去切记行踪莫露，否则危险重重！\n";      
}

int meet_fanpan(object ob)
{
    object obFanpan;
    
    if((ob->query_temp("tdh_job/job_name")=="保护密使")
        && (ob->query_temp("tdh_job/meet_fanpan")!=1)
        && (interactive(ob))
        && !environment(ob)->query("no_fight"))
    {
	    obFanpan=new(__DIR__"fanpan1");
        obFanpan->clone(ob,-5-random(11));//第一个反叛比我低5-15级
	    obFanpan->apply_condition("tdh_job_fanpan",ob->query_condition("tdh_job_busy")/2);
        obFanpan->move(environment(ob));
        ob->start_busy(1);      
        message_vision(HIB"突然，一个黑影向$N袭来!!! \n"NOR,ob);
        message_vision(HIW"$N见来者声势极强，不便硬接，猛吸一口气，向后飞去。\n"NOR,ob);
        message_vision(CYN"只听$N阴笑道：反贼还不束手就擒，我看你往哪跑！\n"NOR,obFanpan);
        message_vision(CYN"$N哼了一声：如此说来，我到要看你有几斤几两？\n"NOR,ob);
        obFanpan->kill_ob(ob);
        obFanpan->set_leader(ob);
        ob->start_busy(1);
        ob->add_temp("tdh_job/meet_fanpan",1);//遇到第一个反叛
        call_other(__DIR__"fanpan1","zhuisha",ob);
        return 1;
    }
    call_out("meet_fanpan",3+random(3),ob);
    return 2;
}

void destructing(object ob)
{
	destruct(ob);
}

int accept_object(object ob,object obj)
{
	if(obj->query("id")!="qingmu ling")
		return notify_fail(CYN+this_object()->name()+"似乎不懂你的意思。\n"NOR);
	if(!ob->query("tiandihui/join"))
	{
		command("say 此物你从何而来！！！");
		command("consider "+ob->query("id"));
		ob->delete_temp("mark/have_ling");
		call_out("destructing",1,obj);
		call_out("kill_ob",3,ob);
		return 1;
	}
	if(ob->query_condition("tdh_job_busy"))
	{
		command("say 此令你从何而来？");
		command("say 这是我火云教号令之物，怎落入你手？");
		ob->delete_temp("tdh_job");
		ob->delete_temp("mark/have_ling");
		call_out("destructing",1,obj);
		return 2;
	}
	ob->delete_temp("mark/have_ling");
	command("say "+give_job(ob));
	call_out("destructing",1,obj);	
	return 1;
}
