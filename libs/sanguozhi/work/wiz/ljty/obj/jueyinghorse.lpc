// jueyinghorse.c by ljty 1998.03.29
#include <sanguo.h>
#include <ansi.h>

inherit M_HORSE;
inherit M_VALUE;
void setup()
{
  set_id("jueyinghorse", HIW+"绝影马"+NOR);
  add_id("jueying");
  add_id("horse");
  add_id("ma");
  set_relations("on");
  set_unit("匹");
  set_long("这是汉大丞相曹操的心爱宝马，其速度之快堪称绝影");
  set_size(MEDIUM);
  set_value(-1);
  set_currency_type("gold");
    set_attack_ability(190);
    set_defence_ability(190);
    set_attack_power(60);

  set_max_capacity(VERY_LARGE*2);
  // So people will see: Sitting on the horse you see Rust...
    set_preposition("on");
  set_in_room_desc(HIW+"绝影马"+NOR+"(jueyinghorse)");
set_get_on_msg("$N翻身跃上"HIW+"绝影马"+NOR+"，"HIW+"绝影马"+NOR+"四腿刨地，猛的立起，就要向前冲出。\n");
set_get_off_msg("$N一拉缰绳，"HIW+"绝影马"+NOR+"身体前匐，$N轻轻跃下"HIW+"绝影马"+NOR+"。\n");
}
string get_arrival_msg()
{
  return get_riders_as_string()+"骑着"HIW+"绝影马"+NOR+"，如飞似的跑了过来。\n";
}
string get_departure_msg()
{
  return get_riders_as_string()+
"两腿一夹"HIW+"绝影马"+NOR+"，只见"HIW+"绝影马"+NOR+"刷的一声向前跃去，转眼便没了踪影。\n";
}
