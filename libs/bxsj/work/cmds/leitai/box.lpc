#include <ansi.h>

inherit ITEM;

string *number = ({ 
"A","B","C","D","E",
"F","G","H","I","J",
"K","L","M","N","O",
"P","Q","R","S","T",
"U","V","W","X","Y",
"Z" }); 

void create()
{
        set_name("抽签盒", ({ "box"}) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", "这是一个专门用来抽签的盒子。 需要巫师来 setup 。\n");
        set("material","wood");
        set("no_get",1);
        set("value", 100000000);
        set("location", 1);
        set("size", 26); 
        }
        setup();
        set("location", 1);
}
void init()
{
    	add_action("do_get",({"抽","chou"}));
    	add_action("do_set", "setup");
}

int do_set(string arg)
{
  	object me,ob;
  	string *nu;
  	int i,j;
  	i = (int)sizeof(number);
  
  	me = this_player();
  	ob = this_object();
  
  	if(!wizardp(me)) 
  		return notify_fail("你无权这么做。\n");
  	if (!arg || sscanf(arg,"%d", j) != 1)
		return notify_fail ("setup <数字>\n");
  	j--;
  	if( j < 1) return notify_fail("数量必须大于 1 。\n");
  	if( j > i) j = i;
  	ob->set("size", j);
  	ob->set("arg", number[0..j]);
  	ob->set("long","这是一个专门用来抽签的盒子。 需要巫师来 setup 。\n");
  	nu = this_object()->query("arg");
  	message_vision("$N将抽签数定为从 A 到 "+nu[j]+" 。\n",me);  
  	return 1;
}
int do_get()
{
  	object me,ob;
  	string msg, *arg;
  	int i = query("size");
  
  	me=this_player();
  
  	if(me->is_fighting() || me->is_busy()) 
  		return notify_fail("你正忙着呢。\n");
  	if(!arrayp(arg = this_object()->query("arg"))) 
  		return notify_fail("这抽签盒还没 setup 。\n");
  	if(i > sizeof(arg)) i = sizeof(arg);
  	if(i <= 0) 
  		return notify_fail("签已经抽完了。\n");
  
  	msg = arg[random(sizeof(arg))];  

  	this_object()->set("arg", arg - ({ msg }));
  	ob = unew(BINGQI_D("tieling"));
  	ob->set_name(GRN+msg+" 签"NOR, ({ "qian"}) ); 
  	ob->set("long", "这是一支抽出来的令签，上面写着 "GRN+msg+NOR" 。\n");
  	ob->set("unit", "支");
  	ob->delete("value");
  	ob->move(me);
  	message_vision("$N伸手从抽签盒中摸出一支$n来。\n",me, ob); 
  	this_object()->set("long", this_object()->query("long")+ob->name()+" ： "+me->name()+" \n");
  	me->start_busy(2);
  	return 1;
}