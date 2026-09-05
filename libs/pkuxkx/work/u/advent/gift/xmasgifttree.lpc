// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
    add_action("do_wish","wish");
}

void create()
{ 
                
       set_name(HIG"圣诞树"NOR,({"xmas tree","tree"}));
        set_weight(9999999);
           set("no_get",1);
        set_max_encumbrance(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","棵");
           set("long",RED"这是一棵华丽的圣诞树,上面悬挂着各种各样的礼物.\n 你看了才想起是圣诞节到了，不禁想对着它祝福(wish)一番！\n"NOR);
                                                  
        }
        
}

int do_wish(string arg)
{
     object me= this_player();
	object gift;
	 tell_object(me,HIM"\n你对着圣诞树，默默地祈祷，祈祷你明年会一帆风顺！\n"NOR);
    tell_object(me,HIW"\天空中忽然传来一阵美妙的乐声, 刹时间霞光万道, 祥云四起,\n
		圣诞老人驾着鹿拉雪橇，背着个极大的口袋，满面笑容从天空中飞来。\n"NOR);

	tell_object(me,HIM"\n只见圣诞老人打开圣诞礼品袋，从里边掏出一件圣诞礼物，交给了你！\n"NOR);
	tell_object(me,HIC"\n圣诞老人哈哈一笑，驾着雪橇飞远了。\n"NOR);
    gift=new("/u/advent/gift/xmas");
    gift->move(me);
	tell_object(me,HIM"\n你得到了一件圣诞礼物，是好吃的噢！\n"NOR);
	me->start_busy(2);
     return 1;
}

