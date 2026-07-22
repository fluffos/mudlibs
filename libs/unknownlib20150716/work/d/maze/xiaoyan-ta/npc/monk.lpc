inherit F_VENDOR_SALE;
#include <ansi.h> 

mixed give_map();

void create()
{
        set_name("大和尚", ({"monk"}));
        set("long", "一位大和尚，看起来慈善的很，口里还不停的咏经。\n");
	set_level(29);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");
	set_level(6);
        set("age", 30+random(10));
        set_skill("force", 200+random(10));
        set_skill("unarmed",200+random(10));
        set_skill("dodge", 200+random(10));
        set_skill("parry", 200+random(10));
	set("vendor_goods", ([
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
        ]) );  
        set("inquiry",([
        	"地图" : (: give_map :),
        ]));	      
        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();
}

mixed give_map()
{
	int i,f=0;
	string arg,str,*strs;
	object env,xin,who=this_player();
	env = environment();
	if( this_object()->is_busy() )
		return "我现在正忙。";
	if( objectp(xin=present("xiaoyan map",who))
	 && base_name(xin)=="/d/maze/xiaoyan-ta/obj/map" )
		return "贫僧已经给过你了。";	 
			
	command("go south");	
	str = MAZE_D->query_maze_mainobj(this_object())->display_common_map(environment());
	this_object()->move(env);
	if( !str )
		return "什么地图？大和尚不知。";
	strs = explode(str,"\n");
	str = "";
	for(i=0;i<sizeof(strs);i++)
	{
		arg = strs[i];
		arg = replace_string(arg,"★","  ");
		arg = replace_string(arg,HBWHT"  ","◆");
		arg = replace_string(arg,HBRED"  ","◇");
		arg = COLOR_D->clean_color(arg);
		if( strsrch(arg,"╭")!=-1 )
		{
			f = 1;
			str+= arg+"\n";
		}
		else if( f!=1 )
			continue;
		else
		{
			arg = replace_string(arg,GRN,"");
			arg = replace_string(arg,BGRN,"");
			arg = replace_string(arg,REV,"");
			str+= arg+"\n";	
		}	
	}
	str = "【小雁塔地宫地图】\n"+str+"*注：◆为入口(大和尚处south)，◇为出口。\n";
	xin = new("/d/maze/xiaoyan-ta/obj/map");		
	xin->set("long",str);
	if( !xin->move(who) )
	{
		destruct(xin);
		tell_object(who,HIR"【副本】小雁塔：你的背包满了。\n"NOR);
	}
	else	tell_object(who,HIG"【副本】小雁塔：你得到了 「"HIY"小雁塔地宫地图"HIG"」。\n"NOR);
	return 1;
}