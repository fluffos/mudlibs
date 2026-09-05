
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("圣诞袜子", ({"gift sock","sock"}) );
	setup();
}
void init()
{
	add_action("do_fenfa","fenfa");
}
int do_fenfa()
{
	shout( HIG"天空中忽然传来一阵美妙的乐声, 刹时间霞光万道, 祥云四起,\n\n哇，是圣诞节到了！\n"NOR);
	call_out("wizard",8);
	return 1;
}
void wizard()
{
    shout( HIW"\圣诞老人驾着鹿拉雪橇，背着个极大的口袋，满面笑容从天空中飞来。\n"NOR);
	shout(HIY"\n拼杀了一年的江湖侠客们都等着看今年会得到什么样的礼物。\n"NOR);
	call_out("liwu",8);
}

void liwu()
{
	shout(HIM"\n只见圣诞老人双手一扬，无数件礼物飞舞在空中，缓缓降落到每个人的身上。\n"NOR);
	shout(HIC"\n圣诞老人哈哈一笑，驾着雪橇飞远了。\n"NOR);
	call_out("socks",5);
}
void socks()
{
	object *usr;
	object gift;
	usr=users();
	for(int i=0;i<sizeof(usr);i++)
{
               {       
                gift=new("/d/gift/advent/xmas");
                gift->move(usr[i]);
			tell_object(usr[i],HIM"\n你得到了一件圣诞礼物，是好吃的噢！\n"NOR);
			usr[i]->start_busy(2);
		}
	}
}
