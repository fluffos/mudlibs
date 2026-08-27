#include <ansi.h>
#include <armor.h>
inherit F_AUTOLOAD;
inherit SHIELD;
object user;
void create()
{
set_name("[1;37m五芒星之盾[0m",({"five_star shield","shield"}) );
set("long","一面由海底火山岩磨成的五角形盾牌,上面隱隱約約透出聖潔的光芒。\n");
set_weight(3650);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","aerolite"); //隕石(aerolite)
set("armor_type","shield");
set("unit", "面");
set("value",6150);
//set("armor_prop/defense",5);
set("armor_prop/str",-3);
set("armor_prop/int",2);
set("armor_prop/wis",1);
set("limit_lv",45);
set("level",45);
//set("armor_prop/armor",95);
set("wear_msg","$N將$n高舉過頭, 閉起眼睛誠心禱告..\n$n化為一股光球包圍住$N!!\n");
set("unequip_msg", "$N放下手中的$n, 身旁祝福的光芒漸漸消失的無影無蹤。\n");
        }
        setup();
user=this_player();
}

int query_autoload() { return 1; }

void init()
{
 add_action("do_wear","wear");
 add_action("do_remove","remove");
}

int do_remove(string str)
{
 user = this_player();
 if(str=="shield" || str=="all" )
 {
  user->delete_temp("magic_shield");
  set_heart_beat(0);
 }
 return 0;
}

int do_wear(string str)
{
 user = this_player();
 
 if(str=="shield" ) 
 {
  if(user->query("level")<45) return notify_fail ("你的等級不夠。\n");;
  set_heart_beat(1);
  user->set_temp("magic_shield",1);
 }
 return 0;
}

void heart_beat()
{
object user;
int heal,tmp;
user = this_player();
if(!user) return ;
if(query("equipped") && !user->query_temp("magic_shield")) user->set_temp("magic_shield",1);
if(!query("equipped") && user->query_temp("magic_shield")) user->set_temp("magic_shield",0);
if(user->is_fighting() && query("equipped") )
{
 if(user->query("max_mp") > user->query("mp") )
 {
  if(random(user->query("lck")) > 40 || random(20) < 4 ) 
   {
   heal = random(20) + (int)user->query("int")/4 + 1 ;
   tmp = user->query("max_mp");
   tmp -= user->query("mp");
   if(heal > tmp) heal = tmp;
   user->add("mp", heal);
   message_vision("\n$N[1;38m發出一道聖潔的光芒增強了$n[1;38m的魔力﹗[0m\n",this_object(),user);
   }
    return;
  }
 }
return;
}