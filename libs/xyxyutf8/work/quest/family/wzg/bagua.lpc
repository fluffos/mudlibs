#include <ansi.h>
inherit ITEM;

int step = 0;

void create()
{
        set_name("铁八卦", ({"tie bagua","bagua",}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 0);
                set("long","镇元大仙的信物，拿着他去问八仙有何烦恼的心事。\n");
                set("material", "iron");
        }
        setup();
}

void dest_ob()
{
	object env = environment();
	remove_call_out("dest_ob");
	if( env )
	{
		if(env->is_character()) 
    		{ 
      			tell_object(env,"天上忽然传来一声断喝：还我"+this_object()->query("name")+"来！\n");
      			tell_object(env,"只见"+this_object()->query("name")+"凌空而去，霎时间不见了踪影。\n");  
    		} 
    		else 	tell_object(env,this_object()->query("name")+"钻进地里，霎时间不见了踪影。\n");	
    	}
    	destruct(this_object());	
}

void init()
{
	if( environment()
	 && this_object()!=this_player()->query_temp("pendding/wzg_askob") )
	{
		call_out("dest_ob",3);
		return;
	}	
	add_action("do_prepare","ask");
}

mixed *story = 
({
        HIC"你朝$N"HIC"一拱手，说道：敢问这位神仙最近有啥烦恼事？。。。\n"NOR,
        CYN"$N"CYN"$S说道：我等八仙一直都想再游一次东海。\n"NOR,
        CYN"你说道：那去了便是。\n"NOR,
        HIC"$N"HIC"长叹一声说道：奈何祖师爷爷管教甚严，吾等哪敢对之明言？\n"NOR,
        CYN"$N"CYN"觉得万念俱灰，难过地叹了口气。\n"NOR,
        CYN"你说道：此事包在我的身上，我这就去和大仙说个明白。\n"NOR,
        CYN"$N"CYN"唏嘘不已：真的，我不是一个多愁善感的人。。。\n"NOR,
	CYN"$N"CYN"感动得热泪盈眶。\n"NOR,
	CYN"$N"CYN"说道：如此甚好，还烦请英雄替吾等美言几句。\n"NOR,
	HIC"你将小胸脯拍的砰砰直响：此事包在偶身上！\n"NOR,
});

mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

void go_on_process(object me,object who)
{
	remove_call_out("start_smash");
	if( !me || !who) 
        	return;
	call_out("start_smash",2+random(1),me,who);
}

void start_smash(object me,object who)
{
	string str,data;
	mixed line;
	string prompt;
	remove_call_out("start_smash");
	if( !me || !who || !query("asking") || !present(me,environment(who)) )
        	return;
	go_on_process(me,who);        
	line = query_story_message(step);
	if( !line )
	{
		remove_call_out("start_smash");
		switch(base_name(who))
		{
			case "/d/qujing/wuzhuang/npc/caoguojiu"	: data = "5";break;
			case "/d/qujing/wuzhuang/npc/hanxiangzi": data = "6";break;
			case "/d/qujing/wuzhuang/npc/hanzhongli": data = "2";break; 
			case "/d/qujing/wuzhuang/npc/hexiangu"	: data = "8";break;
			case "/d/qujing/wuzhuang/npc/lancaihe"	: data = "7";break; 
			case "/d/qujing/wuzhuang/npc/ludongbin" : data = "3";break;
			case "/d/qujing/wuzhuang/npc/tieguaili" : data = "1";break;
			case "/d/qujing/wuzhuang/npc/zhangguolao" : data = "4";break;
			default : return;
		}
		delete("asking");		
		me->set_temp("pendding/wzg_baxian"+data,1);
		me->add_temp("pendding/fc_wzgask",1);
		tell_object(me,HIY"【灵台观礼】八仙过海：你已替镇元大仙询问了"+chinese_number(me->query_temp("pendding/fc_wzgask"))+"位徒孙的烦恼。\n"NOR);
		if( me->query_temp("pendding/fc_wzgask")>=8 )
			tell_object(me,HIY"【灵台观礼】八仙过海：你已向八仙询问过原委，现在去帮他们与镇元大仙说个情吧。\n"NOR);
		return;
	}
	step++;
	prompt = ""; 
	if( functionp(line) ) 
        	catch(line = evaluate(line));
	if( stringp(line) )
	{
		line = replace_string(line,"$N",who->name());
		switch(base_name(who))
		{
			case "/d/qujing/wuzhuang/npc/caoguojiu"	: str = "乐呵呵的打着白玉板";break;
			case "/d/qujing/wuzhuang/npc/hanxiangzi": str = "晃了晃手中的玉箫";break;
			case "/d/qujing/wuzhuang/npc/hanzhongli": str = "摇了摇手中的蒲扇对你";break; 
			case "/d/qujing/wuzhuang/npc/hexiangu"	: str = "欠身施礼";break;
			case "/d/qujing/wuzhuang/npc/lancaihe"	: str = "竹板那个一敲，";break; 
			case "/d/qujing/wuzhuang/npc/ludongbin" : str = "顶着烈阳，回首潇洒的朝你一笑，";break;
			case "/d/qujing/wuzhuang/npc/tieguaili" : str = "杵了杵拐杖";break;
			case "/d/qujing/wuzhuang/npc/zhangguolao" : str = "摸了摸胡子";break;
			default : return;
		}
		line = replace_string(line,"$S",str);
		tell_object(me,line);
        }
	if(intp(line) && !line)
        	go_on_process(me,who);
}

int do_prepare(string arg)
{
	string data,id,*files;
	object who,me = this_player();
	
	if( !arg || sscanf(arg,"%s about %s",id,arg)!=2 )
		return 0;
	who = present(id,environment(me));
	if( !who || userp(who) || who->is_fighting()
	 || !living(who) )
		return 0;
	id = base_name(who);
	files = ({
		"/d/qujing/wuzhuang/npc/caoguojiu",
		"/d/qujing/wuzhuang/npc/hanxiangzi",
		"/d/qujing/wuzhuang/npc/hanzhongli",
		"/d/qujing/wuzhuang/npc/hexiangu",
		"/d/qujing/wuzhuang/npc/lancaihe",
		"/d/qujing/wuzhuang/npc/ludongbin",
		"/d/qujing/wuzhuang/npc/tieguaili",
		"/d/qujing/wuzhuang/npc/zhangguolao",
	});
	if( member_array(id,files)==-1 )
		return 0;
	switch(id)
	{
		case "/d/qujing/wuzhuang/npc/caoguojiu"	: data = "5";break;
		case "/d/qujing/wuzhuang/npc/hanxiangzi": data = "6";break;
		case "/d/qujing/wuzhuang/npc/hanzhongli": data = "2";break; 
		case "/d/qujing/wuzhuang/npc/hexiangu"	: data = "8";break;
		case "/d/qujing/wuzhuang/npc/lancaihe"	: data = "7";break; 
		case "/d/qujing/wuzhuang/npc/ludongbin" : data = "3";break;
		case "/d/qujing/wuzhuang/npc/tieguaili" : data = "1";break;
		case "/d/qujing/wuzhuang/npc/zhangguolao" : data = "4";break;
		default : return 0;
	}
	if( me->query_temp("pendding/wzg_baxian"+data) )
	{
		if( me->query_temp("pendding/fc_wzgask")>=8 )
			write("你向"+who->name()+"打听最近可有烦恼之事。\n"CYN+who->name()+CYN"说道：这事吾等皆已道明，还烦请"+RANK_D->query_respect(me)+"前去向师祖讲个原委。\n"NOR);
		else	write("你向"+who->name()+"打听最近可有烦恼之事。\n"CYN+who->name()+CYN"说道：这事我知道了，你再去找其他几位师兄弟问问吧。\n"NOR);
		return 1;
	}			
	if( query("asking") )
		return 1;
	set("asking",1);		
	step = 0;
	start_smash(me,who);
	return 1;
}