//Mady by:pingpang
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(MAG"炼丹炉"NOR,({"liandan lu","lu"}));
	set_weight(100000);
  set_max_encumbrance(900000);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("long","这是一个炼丹炉,专用来炼取灵丹的.\n");
		set("unit","个");
		set("material","copper");
		set("value",10000);
		set("no_get",1);
		setup();
	}
}
void init()
{
	object ob;
	ob=this_player();
	call_out("check",20,ob);
}
void check()
{
	int i;
	object me,*inv;
	me=this_object();
	inv=all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{if( inv[i]->query("id")=="songzi")
	 if( inv[i]->query("id")=="xuelian")
	 if( inv[i]->query("id")=="mangshedan")
	 if( inv[i]->query("id")=="laoshan shen")
		{message_vision("$N把药品放进炼丹炉里,开始用药匙搅拌.\n",this_player());
		 this_player()->set_temp("marks/药",1);
		 destruct(inv[i]);
		}
	}
}

			
	 
