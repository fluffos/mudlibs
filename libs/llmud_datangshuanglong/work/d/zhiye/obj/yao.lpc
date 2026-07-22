// yao.c
// by augx@sj	3/1/2002

#include <ansi.h>
inherit ITEM;
#include "yao.h";

void create()
{
	set_name("药", ({ "yao" }));
	set_weight(200+random(300));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗丹药。\n");
		set("value", 300);
		set("yao",1);
	}
	setup();
}

void set_type(string yao,int lvl,int value,string save_id,object me,int lower)
{	
	string str;
	if( !mapp(DRUGS[yao]) ) return;
	
	set_name(DRUGS[yao]["name"],DRUGS[yao]["id"]);
	set("long",DRUGS[yao]["long"]+"\n");
	if(me) set("long",query("long")+"这颗丹药似乎是 "+me->short()+" 炼制的。\n");
	set("value",value);
	set("save_id",save_id);
	set("lower",lower);
	set("imbued",DRUGS[yao]["drug_lvl"]);
	set("neili",DRUGS[yao]["neili"]/2+random(DRUGS[yao]["neili"]));
	set("long",query("long")+"服用这颗丹药至少需要"+query("neili")+"点最大内力。\n");
	
	if(lvl>390) lvl = 390 + (lvl-390)*11;
	lvl = MIN(DRUGS[yao]["gain_lvl"],lvl) - DRUGS[yao]["need_lvl"];
	lvl = lvl*100 / (DRUGS[yao]["gain_lvl"]-DRUGS[yao]["need_lvl"]);
	lvl = lvl*7/8 + random(lvl*2/8);
	if(lvl>100) lvl = 100;
	set("lvl",lvl);
	
	if(lvl<10)	str = "极差";
	else if(lvl<25) str = "很差";
	else if(lvl<40) str = "较差";
	else if(lvl<55) str = "一般";
	else if(lvl<65) str = "还行";
	else if(lvl<75) str = "不错";
	else if(lvl<85) str = "较好";
	else if(lvl<95) str = "很好";
	else		str = "极好";
	set("long",query("long")+"这颗丹药的质量看起来似乎"+str+"。\n");
	if(lower) set("long",query("long")+"这颗丹药似乎没有其应有的功效。\n");
}

int drug_setup(mapping mp)
{
	if( !clonep(this_object()) ) return 0;
	if( !mapp(mp) ) return 0;
	
	set_name(DRUGS[mp["yao"]]["name"],DRUGS[mp["yao"]]["id"]);
	set("save_id",	mp["save_id"]);
	set("value",	mp["value"]);
	set("lvl",	mp["lvl"]);
	set("lower",	mp["lower"]);
	set("imbued",	mp["imbued"]);
	set("neili",	mp["neili"]);
	set("long",	mp["long"]);
}

void save_drug(object me)
{
	mapping mp = ([ ]);
	
	if( query("imbued")>3 ) return;
	
	mp["yao"]	= query("id");
	mp["save_id"]	= query("save_id");
	mp["value"]	= query("value");
	mp["lvl"]	= query("lvl");
	mp["lower"]	= query("lower");
	mp["imbued"]	= query("imbued");
	mp["neili"]	= query("neili");
	mp["long"]	= query("long");
	
	me->set("worker/"+mp["save_id"],copy(mp));
	if(userp(me)) me->save();
}

void delete_drug(object me)
{
	if( query("imbued")>3 ) return;
	me->delete( "worker/" + query("save_id") );
}

int move(mixed dest, int silently)
{
	object src = environment(this_object());
	string st;
	int result,utime;
		
	if( (result = ::move(dest, silently)) ) {
		if (src && userp(src)) delete_drug(src);
		if (dest && userp(dest)) save_drug(dest);
		
		if ( (int)query("imbued")<=2 && dest && userp(dest) 
	  	&& (query("neili")*5/10) > dest->query("max_neili") 
	  	&& strsrch(query("save_id"),dest->query("id")) == -1 ) 
			call_out("cant_keep",1,dest);
			
		st = query("save_id");
		st = st[strlen(st)-11..strlen(st)-2];
		sscanf(st,"%d",utime);
		if( (time()-utime) > 432000 ) // 5 day
			call_out("dest_drug",1,dest);
	}
	
	return result;
}

void cant_keep(object me)
{
	if( !me || !userp(me) || environment(this_object())!=me || !environment(me) ) return;
	
	message_vision("但是$N根本拿不住，" + name() + "掉了下来！\n", me);
	if( random(10)==3 || !(this_object()->move(environment(me))) ) {
		message_vision("一下子就失去了踪影！\n",me);
		destruct(this_object());
	}
}

void dest_drug(object me)
{
	if( !me ) return;
	message_vision("$N的"+query("name")+"已经保存过久，已经不能服用了！\n", me);
	log_file("career/worker",sprintf( "overtime:%-8s:%s\n",me->query("id"),query("save_id")), me);
	destruct(this_object());
}

void remove(string euid)
{
	object ob = environment(this_object());
	
	if(!clonep(this_object())) {
		::remove(euid);
		return;
	}
	
	if ( !(int)query_temp("quit_dest") ) {
		if( ob && userp(ob) ) delete_drug(ob);
	}
	else {
		if( ob && userp(ob) ) save_drug(ob);
	}
	
	::remove(euid);
}

void init()
{
	add_action("do_eat","eat");
	add_action("do_eat","fu");
}

int do_eat(string arg)
{
	object me = this_player();
	int busy,lvl,worktime;
	string yao;
	
	if( !living(me) ) return 0;
	if( !id(arg) ) return 0;
	if( query("neili") > me->query("max_neili") )
		return notify_fail("你的内力不够，服用此丹药恐怕会有危险。。\n");
	if( me->query_condition("medicine") > 0 )
		return notify_fail("你上次的药劲儿还没过呢，等会儿再服用吧。\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
		
	yao = query("id");
	if( !mapp(DRUGS[yao]) ) return 0;
	
	worktime = DRUGS[yao]["worktime"];
	if( worktime>0 && stringp(me->query_temp("drug_apply/name")) )
		return notify_fail("你上次服用的"+me->query_temp("drug_apply/name")+NOR"药劲儿还没过呢，等会再服用吧。\n");
	
	lvl = query("lvl");
	busy = DRUGS[yao]["busy"];
	if( busy > 100 )
		me->apply_condition("medicine",busy-100);
	else {
		me->apply_condition("medicine",10);
		WORKER_D->set_drug_busy(me,busy);
	}
	
	if( worktime > 0 ) {
		WORKER_D->set_drug_work(me,worktime*20);
		me->set_temp("drug_apply/name",DRUGS[yao]["name"]);
	}
	
	do_drug(me,yao,lvl,query("lower"));
	
	message_vision(DRUGS[yao]["eat_msg"]+"\n", me);
	log_file("career/fudan", sprintf("%-19s:%-18s:%s\n",
		query("save_id"),me->query("name")+"("+me->query("id")+")",query("name") ), me);
	destruct(this_object());
	return 1;
}	
