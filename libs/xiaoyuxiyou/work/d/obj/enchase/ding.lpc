#include <ansi.h>
inherit ITEM;

nosave mapping Hb = ([
	"/d/obj/enchase/xuefenfen" 		: ({"/d/obj/enchase/hongyan-po","/d/obj/enchase/limang-shi",}),
	"/d/obj/enchase/weapon-shengji-1" 	: ({"/d/obj/enchase/hongyan-po","/d/obj/enchase/hongyan-po","/d/obj/enchase/hongyan-po",}),
	"/d/obj/enchase/weapon-shengji-2"	: ({"/d/obj/enchase/limang-shi","/d/obj/enchase/limang-shi","/d/obj/enchase/limang-shi",}),
	"/d/obj/enchase/weapon-shengji-3"	: ({"/d/obj/enchase/weapon-shengji-1","/d/obj/enchase/weapon-shengji-2",}),
]);

int is_container() {return 1;}
int query_autoload(){return 1;}

void create()
{
	set_name(RED"祝融"YEL"鼎"NOR,({"zhurong ding","ding"}));
	set_weight(8888);
	set_max_encumbrance(8888);
	set_max_items(500);
	if( clonep() )
        	set_default_object(__FILE__);
	else    
	{
        	set("unit", "口");
        	set("long", "相传这是参照远古大巫祝融法宝仿制而成，内有乾坤，将各种宝贝放进去可以进行融合(ronghe)。\n");
        	set("no_put", 1);
        	set("no_give",1);
        	set("no_sell",1);
        }       
}

void init()
{
	add_action("do_ronghe","ronghe");
}

int same_arr(mixed *x,mixed *y)
{
	int i;
	string tmp;
	if( !x || !y )
		return 0;
	if( sizeof(x)!=sizeof(y) )
	{
		set("error","sizeof不一致");
		return 0;
	}
	for(i=0;i<sizeof(x);i++)
	{
		if( member_array(x[i],y)==-1 )
		{
			set("error",x[i]+"不属于");
			return 0;
		}
		continue;
	}
	return 1;
}		

void clear_inv()
{
	int i;
	object *inv;
	if( !environment() 
	 || !userp(environment()) )
		return;	 
	inv = all_inventory();	
	for(i=0;i<sizeof(inv);i++)
	{
		tell_object(environment(),HIR"火光一闪，"+inv[i]->query("name")+HIR"顿时化作一团红雾在"+query("name")+HIR"内辗转翻腾。\n"NOR);
		destruct(inv[i]);
	}
}

string find_file(mixed *tmp)
{
	mixed *ss;
	int i;
	ss = keys(Hb);
	for(i=0;i<sizeof(ss);i++)
	{
		if( same_arr(tmp,Hb[ss[i]]) )
			return ss[i];
	}
	return 0;
}

int do_ronghe()
{
	int i,k;
	string file;
	mixed *hb;
	object me,ob,*inv,*tmp;
	
	me = this_player();
	if( !present(this_object(),me) )
		return 0;
	
	inv = all_inventory();
	if( !inv )
	{
		write(query("name")+"里面的宝贝数量不够。\n");
		return 1;
	}
	
	tmp=({});
	for(i=0;i<sizeof(inv);i++)
	{
		if( !inv[i]->can_ronghe() )
		{
			write(inv[i]->query("name")+"不能融合。\n");
			return 1;
		}
		file = base_name(inv[i]);
		if( !inv[i]->query_amount() )
			tmp+= ({file});
		else
		{
			for(k=0;k<inv[i]->query_amount();k++)
				tmp+= ({file});				
		}
	}
	set("tmp",tmp);
	hb = values(Hb);
	for(i=0;i<sizeof(hb);i++)
	{
		if( same_arr(tmp,hb[i]) )
		{
			write(HIR"\n只见"NOR+query("name")+NOR HIR"内四壁红光一闪，四下里卷起万千火蛇，将内中宝贝团团包裹。\n"NOR);
			clear_inv();
			file = find_file(tmp);
			if( !file )
			{
				write("\n红光闪过，"+query("name")+"内是空无一物！\n");
				return 1;
			}
			ob = new(file);
			if( !ob )
			{
				write("\n红光闪过，"+query("name")+"内是空无一物！\n");
				return 1;
			}
			ob->move(this_object());
			write("\n一阵翻江倒海过后，"+query("name")+"内恢复了平静，但见重重霞光中现出了"+ob->query("name")+"！\n");
			return 1;
		}
		else	continue;
	}
	write("请确认这几样宝贝能够融合。\n");
	return 1;
}								