
//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIR"狂"+YEL+"沙"+HIR+"刀"NOR, ({ "kuangsha dao","dao" }) );
   set_weight(15000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("super",3);
     set("no_save",1);
     set("no_sell",1);
     set("rumor",1);
     set("material", "iron");
     set("value",5000);
     set("long", YEL"相传突厥境内沙漠中有一处地方异常炎热，此处盛产血黄色相间的铁沙，狂沙刀便由此铁
沙精炼而成。如在光线映照下，刀身寒芒烁动流转，仿似具有灵性生命的巽物神器。其锋
利耐用，自是不用多说，刀主可达志凭借一手狂沙五诀和此刀横行天下，难逢敌手。
\n"NOR);
     set("wield_msg", YEL"$N"+YEL+"左手握鞘平举前方，把$n"+YEL+"从鞘内拔出．发出一下先声夺人，震慑全场的鸣响。\n"NOR);
     set("unequip_msg", HIC"$N"+HIC+"双目射出奇异的光芒，一眨不眨的瞧着$n"+HIC+"，随即收刀后退。\n"NOR);
     set("weapon_prop/dodge",30);
   }
   init_blade(380);
   setup();
}
