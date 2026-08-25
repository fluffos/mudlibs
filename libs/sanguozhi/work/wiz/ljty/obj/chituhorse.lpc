// chituhorse.c by ljty 1998.03.29
#include <sanguo.h>
#include <ansi.h>
inherit M_HORSE;
inherit M_VALUE;
void setup()
{
  set_id("chituhorse", HIR+"赤兔马"+NOR);
  add_id("chitu");
  add_id("horse");
  add_id("ma");
  set_relations("on");
  set_unit("匹");
  set_long("这就是天下第一神驹赤兔马，神骏异常，正可谓人中吕布，马中赤兔
");
  set_size(MEDIUM);
  set_value(-1);
  set_currency_type("gold");
    set_attack_ability(200);
    set_defence_ability(200);
    set_attack_power(70);

  set_max_capacity(VERY_LARGE*2);
  // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
  set_in_room_desc(HIR+"赤兔马"+NOR+"(chituhorse)");
set_get_on_msg("$N翻身跃上"HIR+"赤兔马"+NOR+"，"HIR+"赤兔马"+NOR+"长嘶一声，两腿人立，其势欲飞。\n");
set_get_off_msg("$N猛的一拉缰绳，"HIR+"赤兔马"+NOR+"前腿急抬，啪的一下止住，接着$N翻身跃下"HIR+"赤兔马"+NOR+"。\n");
}

string get_arrival_msg()
{
  return get_riders_as_string()+ "骑着"HIR+"赤兔马"+NOR+"，如飞似的跑了过来。\n";
}
string get_departure_msg()
{
  return get_riders_as_string()+
"两腿一夹"HIR+"赤兔马"+NOR+"，只见"HIR+"赤兔马"+NOR+"一声龙吟，四腿猛一蹬地，如腾云驾雾般的向远方飞去。\n";
}
