// gems - by xbd

#include <ansi.h>

inherit ITEM;
inherit F_GEMS;

void create()
{
	int lev, i,j,fn;
	string gem, s,filen;
	object ob;
	object me = this_player();

	i = random(12);
	if (i == 1) gem = "ruby";
	else if (i == 2) gem = "topaz";
	else if (i == 3) gem = "sapphire";
	else if (i == 4) gem = "emerald";
	else if (i == 5) gem = "amethyst";
	else if (i == 6) gem = "windjade";
	else if (i == 7) gem = "firejade";
	else if (i == 8) gem = "icejade";
	else if (i == 9) gem = "thunderjade";
	else if (i == 10) gem = "earthjade";
	else if (i == 11) gem = "diamond";
	else gem = "skull";

	j = random(100);
	if (j < 50) lev = 1;
	else if (j < 75) lev = 2;
	else if (j < 90) lev = 3;
	else if (j < 95) lev = 4;
	else if (j < 96) lev = 5;
	else if (j < 97) lev = 6;
	else if (j < 98) lev = 7;
	else lev = 8;

if (lev >4 && random(3)>0)
lev=3;
if (lev >4 && random(2)==1)
lev=3;

if (lev >5 && random(2)==1)
lev=4;
if (lev >5 && random(3)==1)
lev=4;

if (lev >=6 && random(2)==1)
lev=6;
if (lev >=6 && random(3)==1)
lev=6;

if (lev >=7 && random(2)==1)
lev=6;
if (lev >=7 && random(3)==1)
lev=6;

if (lev >=8 && random(2)==1)
lev=7;
if (lev >=8 && random(3)==1)
lev=7;

if (i > 0) i=i*10;
fn=i+lev;

	set_name(query_gem_name(gem, lev)+HIY" 原石"NOR, ({query_gem_id(gem, lev)}));
	set_weight(100);
	set("long", query_all_effect(gem));
	set("unit", "颗");
	set("no_put",1);
       set("treasure",1);       
//	set("no_get",1);
//	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
//        set("no_clone",1);
        set("no_pawn",1);
             set("treasure",1);	
	set("value", 10000 * lev * lev * lev);
	set("material", gem);
	set("lb", i);
	set("level", lev);
	//filen="/clone/gem/gem"+fn;
	//set("name","AAA"+fn);

	           //ob = new(filen);
          // ob->move(this_player());
//destruct(this_object());
	
	setup();

}

void init()
{
	add_action("do_combine", "search");
	add_action("do_combine", "jianding");
}


int set_level(int lb,int lev)
{       
	int lev2,i,j,fn;
	string gem, s;
	object me = this_player();

	if (!lb && lb!=0)
{
		 i = random(12);
}
else
{
	i = lb;
if (i > 11) i = random(12);
}			

	if (i == 1) gem = "ruby";
	else if (i == 2) gem = "topaz";
	else if (i == 3) gem = "sapphire";
	else if (i == 4) gem = "emerald";
	else if (i == 5) gem = "amethyst";
	else if (i == 6) gem = "windjade";
	else if (i == 7) gem = "firejade";
	else if (i == 8) gem = "icejade";
	else if (i == 9) gem = "thunderjade";
	else if (i == 10) gem = "earthjade";
	else if (i == 11) gem = "diamond";
	else gem = "skull";

	if (!j)  j=random(100);
	if (j < 50) lev2 = 1;
	else if (j < 75) lev2 = 2;
	else if (j < 90) lev2 = 3;
	else if (j < 95) lev2 = 4;
	else if (j < 96) lev2 = 5;
	else if (j < 97) lev2 = 6;
	else if (j < 98) lev2 = 7;
	else lev2= 8;

  if (!lev) lev=lev2;


if (i > 0) i=i*10;


	set_name(query_gem_name(gem, lev)+HIY" 原石"NOR, ({query_gem_id(gem, lev)}));
	set_weight(100);
	set("long", query_all_effect(gem));
	set("unit", "颗");
	set("no_put",1);
       set("treasure",1);       
//	set("no_get",1);
//	set("no_drop",1);
	set("no_beg",1);
	set("no_steal",1);
//        set("no_clone",1);
        set("no_pawn",1);
            set("treasure",1);	
	set("value", 10000 * lev * lev * lev);
	set("material", gem);
	set("lb", i);
	set("level", lev);
        return 1;
}

int do_combine(string arg)
{
	int i;
	object ob;
	int lev, j,fn;
	string s,filen;
	object *inv, gem, me = this_player();

	if (!wizardp(me) && !arg || arg == "")
		return notify_fail("你想鉴定什么宝石？\n");
	if (!wizardp(me) && arg != query("id")) return 0;
	
	if (me->query("max_neili") < 100 || me->query("neili") < 300)
		return notify_fail("以你现在的内力修为，还无法运功鉴定宝石！\n");

	if ((int)me->query("score") < 300 )
		return notify_fail("以你现在的江湖阅历，还无法运功鉴定宝石！\n");

				message_vision(HIY"$N暗运内力劲透宝石，但见" + name() + HIY"表面异彩流动，
渐渐的$N收回了内力，只觉" + name() + HIY"表面的杂质和渣滓全部被融化了！\n", me);
				me->add("max_neili", -2);
				me->add("neili", -200);
				me->add("score", -200);
				me->start_busy(1);
i=query("lb");
lev=query("level");
fn=i+lev;

	filen="/clone/gem/gem"+fn;
	

	           ob = new(filen);
//	ob->set_level(10,8);
	//ob->set("name","AAA");
  
           ob->move(this_player());
//ob->set("name","lb"+i+"lev"+lev);
//destruct(this_object());


				destruct(this_object());
				return 1;
}
