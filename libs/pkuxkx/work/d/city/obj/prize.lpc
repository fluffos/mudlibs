//荣誉勋章 zine 2 Oct 2010
#include <ansi.h>

inherit ITEM;

void create()
{
	string * color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
    set_name(color[random(sizeof(color))]+"荣誉勋章"NOR, ({ "medal of honor" , "medal" ,"xun zhang"}) );
    set_weight(1);
    if( clonep() )
		set_default_object(__FILE__);
    else 
	{
		set("unit", "枚");
		set("material", "crystal");
		set("value", 1); 
		set("no_give",1);
		set("no_drop",1);
        set("no_sell",1);
        set("no_put",1);
		set("used",0);
		//set("no_get",1);
        //set("no_store",1);
        set("no_give_user",1);

		set("long","这一枚荣誉勋章，以表彰你对北侠作出的贡献。\n"); 
		if (environment())
		{
			set("owned",environment()->query("id"));
		}
	}
        setup();
}



int query_autoload() { return 1; }

int refresh()
{
	this_object()->delete("used");
	return 1;
}

int do_show()
{
	string * color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
	string color2=color[random(sizeof(color))];
	object me=this_player();
	object ob=this_object();

	if(me->query("honorbonus/coinnumber"))
	{
		if (ob->query("used"))
		{
			return notify_fail("虽然你为北侠作出了一定贡献，老拿出来说也不好吧？\n");
		}
		else
		{
			message_vision(color1+"$N拿出$n"+color1+"，向众人讲述自己为北侠作出的贡献，众人不禁心向往之，流出了羡慕的口水。\n"NOR,me,ob);
			tell_room(environment(me),color2+"只见荣誉勋章上篆刻着："+ob->query("long")+"\n"NOR);
			ob->set("used",1);
			me->add_busy(random(1));
			remove_call_out("refresh");
			call_out("refresh",10);
			return 1;
		}
	}
	else
	{
		tell_object(me,"你从哪偷来的勋章，北侠是和谐社会啊！\n");
		return 1;
	}
}

void destruct_me(object where, object me)
{
  message_vision("$n在空气中失去光芒，最近竟失去了踪影。\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();
  string owner1;
  object owner;
  add_action("do_show", ({ "show" }));
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
  owner1=me->query("owned");
  owner=find_player(owner1);
	if(objectp(owner))
	{
		if (owner->query_temp("honorbonus/coinv")==0)
		{
			me->set("long",owner->query("honorbonus/coindescription1"));
			owner->set_temp("honorbonus/coinv",1);
			return;
		}
		if (owner->query_temp("honorbonus/coinv")==1)
		{
			me->set("long",owner->query("honorbonus/coindescription2"));
			owner->set_temp("honorbonus/coinv",2);
			return;
		}
		if (owner->query_temp("honorbonus/coinv")==2)
		{
			me->set("long",owner->query("honorbonus/coindescription3"));
			owner->set_temp("honorbonus/coinv",3);
			return;
		}
		else
		{
			return;
		}
	}
}
