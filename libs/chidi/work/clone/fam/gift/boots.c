// armor.c
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
    set_name(HIM"英雄战靴"NOR , ({ "boots","hero boots" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("no_paimai",1);
        set("unit","双");//单位        
        set("express","can_shenghua");//可进化标志
        set("sh_lvl",0);//原始装备标志
        set("material","zhuangbei");//进化装备类标志
        set("point",5);//伤害力
        set("stype","BOOTS");//道具的子类别 
        set("ctype","靴子");//道具的类别的中文名 
        set("type","boots");//道具的类型
       /*-----------特殊屬性---------------------*/ 
        set("armor",1200);//防禦
        set("defense1",20);//追加躲避
        set("dexerity",25);//追加身法        
      /*--------------END------------------------*/
        set("wear_msg", HIY "只见$N一邊溫柔的靴子套上，一邊猥瑣的唱道：“從此以后，無憂無求，世事平淡但當中有妳，已經足夠！”\n" NOR);
        set("remove_msg", HIC"$N將靴子用力一扯一摔，舒服得長聲呻吟，一股隻可會意，不可言語的味道直衝妳的鼻孔。\n" NOR);
	 set("long",HIR "\t   〖英雄套裝〗－－英雄战靴\n"NOR
YEL"\t這是一雙用烈火孽龍腹部軟皮所製，\n"
"\t經上古鉅鱷咀嚼一仟萬次打磨拋光！\n"
"\t絕對是跳牆私會PLMM的最佳選擇哦！\n"
"\t传说得到英雄套装的人将成为\n"
"\t江湖的至尊人物。\n"NOR
HIY"\t ----------進化基數----------\n"NOR
HIG"\t   追加防禦：1200 ×進化次數\n"NOR
HIG"\t   追加躲避：20   ×進化次數\n"NOR
HIG"\t   追加身法：25   ×進化次數\n"NOR
HIY"\t ----------------------------\n"NOR);	
    }
setup();
}
void owner_is_killed() { destruct(this_object()); }
 