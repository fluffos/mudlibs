//  礼品分发器

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("礼品分发器", ({"gift box","box"}) );
	setup();
}
void init()
{
	add_action("do_giftall","giftall");
//	add_action("do_gift",gift);
}

int do_gift()
{
return 1;
}

int do_giftall()
{
	shout( HIC"天空中忽然传来一阵美妙的乐声, 刹时间霞光万道, 祥云四起,\n\n你目注天空，不知将发生了什么事情。\n"NOR);
        call_out("wizard",1);
	return 1;
}
void wizard()
{
        //shout( HIC"\n只见天神、巫师们站在祥云之中，面带微笑，正注视着大地上的芸芸众生。\n"NOR);
        //shout(HIY"\n大家不自禁放下手中的武器，跪在地上向天空膜拜。\n"NOR);
        call_out("sagift",1);
}

void sagift()
{
        //shout(HIM"\n只见巫师双手一扬，无数个物品向地上落下，降落到每个人的身上。\n"NOR);
        //shout(HIC"\n随后彩云越收越小, 巫师的身影消失不见了！\n"NOR);
        call_out("guo",1);
}
void guo()
{
	object *usr;
	object giftguo;
	usr=users();
	for(int i=0;i<sizeof(usr);i++)
{
//      if(usr[i]->query("id")!="hongdou") 
                 { giftguo=new("/d/city/player/obj/baowu");
          giftguo->move(usr[i]);
			tell_object(usr[i],HIM"\n你得到了一份珍贵的礼物，不禁欣喜若狂！\n"NOR);
                        //usr[i]->start_busy(15);
		}
	}
}
