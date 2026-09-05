//by lordstar
//管理rbz数据

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIW"荣宝斋掌柜"NOR, ({"rbz master", "rbz"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", "天下第一大掌柜");
        set("env/invisibility",1);
        set("long", "一个胖胖的掌柜，每天负责在这里管理荣宝斋的财物。\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set("max_qi", 1500000);
        set("qi",1500000);
        set("max_jing", 1500000);
        set("jing",1500000);
        set("shen_type",1);
		set("score",0);
		
		set("rbz_all_sell_number", 0);
		set("discount", 
			([
				"90" : 2000,
				"80" : 4000,
				"70" : 6000,
				"60" : 8000,
				"50" : 10000,
			]) 
		);
		
		setup();

		remove_call_out("update_rbz");
        call_out("update_rbz",1);  

}

int discount()
{
	int num = (int)this_object()->query("rbz_all_sell_number");
	mapping dc = this_object()->query("discount");
	if (sizeof(dc)<=0) return 10;
	if ( num >= dc["50"] ) return 5;
	else if ( num >= dc["60"] ) return 6;
	else if ( num >= dc["70"] ) return 7;
	else if ( num >= dc["80"] ) return 8;
	else if ( num >= dc["90"] ) return 9;
	else return 10;
}

void update_rbz()
{
	object me;
	int ds, num, nds, nnum;
	string msg;
	mapping dc;
	me = this_object();
	if (!environment(me)) {
		destruct(me);
		return;
	}
	me->set("last_update", time());
	me->set("next_update", time()+3600*24);
	remove_call_out("update_rbz");
    call_out("update_rbz", 3600*24);  
	dc = me->query("discount");
	ds = me->discount();
	num = me->query("rbz_all_sell_number");
	if (ds>=9) 
	{
		me->set("rbz_all_sell_number", 0);
		me->set("last_update_num", num);
		CHANNEL_D->do_channel(me, "jh", HIM+"今日荣宝斋生意兴隆，所有库存宝物转售一空！"NOR, -1);		
	}
	else 
	{
		nds = 10-ds;
		if (nds>3) nds=3;
		nds = ds + 1 + random(nds);
		if (sizeof(dc)<=0) nnum = 0;
		else nnum = dc[""+nds+"0"];
		me->set("rbz_all_sell_number", nnum);
		nnum = num - nnum;
		me->set("last_update_num", nnum);
		if (nnum<4000) msg="冷清";
		else if (nnum<6000) msg="一般";
		else msg="兴隆";	
		CHANNEL_D->do_channel(me, "jh", HIM+"今日荣宝斋生意"+msg+"，转售出库存宝物共计"+chinese_number(nnum)+"件！"NOR, -1);	
	}
	return;
}

int show_update()
{
	int n;
	object me = this_object();
	n = (int)me->query("last_update");
	if (n>0) write("上一次更新时间："+n+"\n");
	n = (int)me->query("last_update_num");
	if (n>0) write("上一次更新消减库存 "+n+" 件。\n");
	n = (int)me->query("next_update");
	if (n>0) write("下一次更新时间："+n+"\n");
	return 1;
}

