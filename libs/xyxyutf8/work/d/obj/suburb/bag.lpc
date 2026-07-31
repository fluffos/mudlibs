//Cracked by 凌惊雪 1.8.2003
inherit ITEM;
#include <ansi.h>
string *names1 = ({
"/d/obj/suburb/axe/axe",
"/d/obj/suburb/blade/blade",
"/d/obj/suburb/fork/fork",
"/d/obj/suburb/hammer/hammer",
"/d/obj/suburb/spear/spear",
"/d/obj/suburb/staff/staff",
"/d/obj/suburb/stick/stick",
"/d/obj/suburb/sword/sword",
"/d/obj/suburb/whip/whip",
});
string *names2 = ({
"101",
"102",
"103",
"104",
"105",
"106",
"107",
"108",
"109",
"110",
"111",
"112",
});
string *names3 = ({
"/d/obj/suburb/armor/head1",
"/d/obj/suburb/armor/head2",
"/d/obj/suburb/armor/head3",
"/d/obj/suburb/armor/head4",
"/d/obj/suburb/armor/head5",
"/d/obj/suburb/armor/armor1",
"/d/obj/suburb/armor/armor2",
"/d/obj/suburb/armor/armor3",
"/d/obj/suburb/armor/pifeng1",
"/d/obj/suburb/armor/pifeng2",
"/d/obj/suburb/armor/pifeng3",
"/d/obj/suburb/armor/shoes1",
"/d/obj/suburb/armor/shoes2",
"/d/obj/suburb/armor/cloth1",
"/d/obj/suburb/armor/cloth2",
});
void create() {
        set_name("包袱", ({ "bag","bao" }) );
        set_weight(100);
        if( clonep() )                 
        	set_default_object(__FILE__);
        	else 	{
        	set("long", HIY"一个沉甸甸的包袱，看来里面裹着好东西。\n你可以用(dakai)或者(chai)来打开看看。\n"NOR);	
                set("unit", "只");
    		set("no_beg",1);
    		set("no_get",1);
//    		set("no_give",1);
    		set("no_steal",1);
                set("value", 500);
        	}
}

void init() 
{
  add_action("do_open","chai");
  add_action("do_open","dakai");
}

int do_open(string arg)
{
	object me, newob;
	me = this_player(); 
        if(me->query("gender")=="男性")
    		tell_object(me,"你迫不及待地将"+HIG+"包袱"NOR+"打开，\n");
        else
    		tell_object(me,"你小心翼翼地将"+HIY+"包袱"NOR+"打开，\n");
	if(random(500)>495)
	{
		newob=new(names1[random(sizeof(names1))]+names2[random(sizeof(names2))]);
		newob->move(me);
        	message_vision("$N发现了一件上古兵器"+newob->query("name")+HIM"。\n",me);
		message("channel:chat", HIM"【小雨西游】听说"+me->name() + HIM"得到了一件上古兵器"NOR+newob->query("name")+HIM"!"NOR"。\n", users());
	}
	else if(random(500)>495)
	{
		newob=new(names3[random(sizeof(names3))]);
		newob->move(me);
        	message_vision("$N发现了一件上古宝物"+newob->query("name")+HIM"。\n",me);
		message("channel:chat", HIM"【小雨西游】听说"+me->name() + HIM"得到了一件上古宝物"NOR+newob->query("name")+HIM"!"NOR"。\n", users());
	}
	else if(random(500)>480)
	{
		newob=new("obj/money/gold");
		newob->set_amount(1+random(10));
		newob->move(me);
        	message_vision("$N发现了一些黄金。\n",me);
	}
	else if(random(500)>480)
	{
		newob=new("obj/money/silver");
		newob->set_amount(1+random(100));
		newob->move(me);
        	message_vision("$N发现了一些白银。\n",me);
	}
	else if(random(500)>480)
	{
		newob=new("obj/money/coin");
		newob->set_amount(1+random(100));
		newob->move(me);
        	message_vision("$N发现了一些铜钱。\n",me);
	}
	else 
	{
        	message_vision("$N什么也没发现。\n",me);
	}
	destruct(this_object());
	return 1;
}
