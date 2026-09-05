//changgun.c  长棍
//  hongdou 98.09.20

#include <weapon.h>
#include <ansi.h>

inherit ITEM;
//inherit CLUB;

//void setup()
//{}

void init()
{
        add_action("do_bang", "bang");
}

void create()
{        
	set_name("长木棍", ({ "chang gun", "gun" }));        	
	set_weight(3000);        
	if (clonep()) set_default_object(__FILE__);        
	else 
	{                
		set("unit","根");                
		set("long","由树枝制成的一根轻便的长木棍，可以当武器，也可以绑些什么东西。\n");                
		set("value", 200);                
		set("material", "steel");                
//		set("wield_msg", "$N抽出一根$n握在手中。\n");               
//		set("unwield_msg", "$N将手中的$n插回腰间。\n");		
		set("diaoyudao",1);        
	}        
//	init_club(15);        
//	setup();
}

int do_bang(string arg)
{
        object ob,yugan;
        object me = this_player();
	if( !arg || arg!="xian" ) 
	{
	     if ( !arg ) return notify_fail("你要往长木棍上绑什么？\n");
             if ( arg!="xian" )  return notify_fail("那个东西不能绑上！\n"); 
        }
   if (arg=="xian")
	{
	  if (!(ob = present("yu xian", this_player())))
               return notify_fail("你没有哪个东西？\n");
   	  tell_object(me, HIY "你小心地将鱼线绑在长木棍上，立刻制成了一副新渔竿。\n"NOR);
          yugan = new(__DIR__"newyugan");
          yugan->move(me);
//   me->unconcious();
      destruct( ob );
	  destruct(this_object());
	  return 1;
        }       
}
