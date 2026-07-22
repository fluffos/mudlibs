// yaochu.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void set_status(int i);
int query_status();

void create()
{
	set_name("药锄", ({ "yao chu", "yaochu" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄药锄。\n");
		set("olong", "这是一柄药锄。可以用来采药(caiyao)。\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N拿起一柄$n。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
		set("worker_tool",1);
	}
	set("used",70);
	set("oused",70);
	init_staff(20);
	set_status(70);
	set("worker",1);
	set("stime",time());
	setup();
}

void set_status(int i)
{
	int j;
	j = (int)(i*100/query("oused"));
	if(j>90) set("long",query("olong")+"看起来还是完好的。\n");
	else if(j>50) set("long",query("olong")+"看起来已经用过一段时间了。\n");
	else if(j>20) set("long",query("olong")+"看起来已经有些破损了。\n");
	else if(j>0) set("long",query("olong")+"看起来就要坏了。\n");
	else set("long",query("olong")+"看起来已经坏掉了。\n");
	set("used",i);
}

int query_status()
{
	return query("used");
}

void use()
{
	object me = environment(this_object());
	if( query_status()<=0 ) return;
	if( query_status()>2 && (time()-query("stime"))>7200 ) {
		tell_object(me,"你的"+query("name")+"似乎有些生锈了！\n");
		set_status(2);
	}
	set_status(query_status()-1);
	if( query_status()<=0 ) {
		if( objectp(me) && userp(me) )
			tell_object(me,"你的"+query("name")+"坏掉了！\n");
		broken("坏掉的");
	}
}
