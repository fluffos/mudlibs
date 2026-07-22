// armor.c
#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
    set_name(HIM"英雄披风"NOR , ({ "surcoat","hero surcoat" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "件");//单位
        set("no_drop",1);//不允许drop
        set("no_give",1);//不允许give
        set("no_put",1);//不允许put
        set("no_sell",1);//不允许sell
        set("express","can_shenghua");//可进化标志
        set("sh_lvl",0);//原始装备标志
        set("material","zhuangbei");//进化装备类标志
        set("point",20);//伤害力
        set("stype","SURCOAT");//道具的子类别 
        set("ctype","披风");//道具的类别的中文名 
        set("type","surcoat");//道具的类型
       /*-----------特殊屬性---------------------*/ 
        set("armor",3000);//防禦
        set("defense1",300);//追加躲避
        set("attack1", 300);//追加身法
        set("dodge",1000);//追加轻功
      /*--------------END------------------------*/
        set("wear_msg", HIY "只见$N把披风迎风一展，潇洒的披在肩上，身后带出了无数的跳蚤和小强——汗！”\n" NOR);
        set("remove_msg", HIC"$N将披风脱下，小心的叠成一团，放在怀里，贱贱的说道：“我怀上了。”\n" NOR);
	 set("long",HIR "\t   〖英雄套裝〗－－英雄披風\n"NOR
YEL"\t這是一件以烈火孽龙的肉翼所构成，\n"
"\t上面绘画着一模糊的人像，其忧郁\n"
"\t的眼神，唏嘘的须根，已经彻底的\n"
"\t把其靈魂出卖了——小白猪，传说\n"
"\t得到英雄套装的人将成为江湖\n"
"\t的至尊人物。\n"NOR
HIY"\t  ----------進化基數----------\n"NOR
HIG"\t    追加防禦：3000 ×進化次數\n"NOR
HIG"\t    追加躲避：300  ×進化次數\n"NOR
HIG"\t    追加伤害：300  ×進化次數\n"NOR
HIG"\t    追加轻功：1000 ×進化次數\n"NOR
HIY"\t  ----------------------------\n"NOR);	
    }
setup();
}
void owner_is_killed() { destruct(this_object()); }
