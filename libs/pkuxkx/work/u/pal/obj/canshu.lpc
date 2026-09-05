// dumpling.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("参数", ({"canshu", "dumpling"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的肉包子。\n");
		set("unit", "个");
		set("value", 50);
		set("food_remaining", 3);
             set("food_supply", 10);
	}
}

void init()
{
  add_action("kan","kan");
}
  


int kan()
{
   object me=this_player();   
message("vision","pk_level:"+(string)me->query("pk_level")+"\n"+"accomplish1:"+(string)me->query("accomplish1")+"\n"+
"accomplish2:"+(string)me->query("accomplish2")+"\n"+"pkscore:"+(string)me->query("pkscore")+"\n"+
"deathname:"+me->query("deathname")+"\n"+"deathexp:"+(string)me->query("deathexp")+"\n"+"pker:"
+(string)me->query("pker")+"\n"+"mudage:"+(string)me->query("mudage")+"\n"+"mud_age:"+(string)me->query("mud_age")+"\n"+
"reward:"+(string)me->query("reward")+"\n"+"pktitle:"+me->query("pktitle")+"\n",me);
   return 1;
}




