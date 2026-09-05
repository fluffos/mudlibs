//紧身宝甲
#include <weapon.h>
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
 set_name(HIW"紧身宝甲"NOR,({"bao jia","jia"}));
set_weight(500);
if(clonep())
set_default_object(__FILE__);
else
{
set("long","秦桧杀了岳飞之后天天都有人刺杀他,为岳飞报仇。为此秦桧用重金得到了这一个宝甲用来防身之用.\n");
set("material","cloth");
set("unit","件");
 set("value",360000);
set("no_pawn",1);
set("no_sell",1);
set("sell_in_playershop",1);
set("wear_msg",HIY"$N将紧身宝甲穿在里面,感觉舒服极了.\n同时$N又想道:秦桧这恶贼,竟也穿得到这等宝物。真是....\n"NOR);
set("remove_msg",HIY"$N将$n脱了下来，抖了抖身上的灰尘.\n"NOR);
set("armor_prop/armor",600);
setup();
}
}
