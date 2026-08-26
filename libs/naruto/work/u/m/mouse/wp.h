mapping record = ([
    0: ([ "name": "",
          "long": "",
          "buff1": "move",
          "buff2": "carriage",
       ]),
    1: ([ "name": HIR"淡紅",
          "long": "武器的刃頭上帶有一絲紅色，不知是何用途。\n",
          "buff1": "attack",
          "buff2": "intimidate",
       ]),
    2: ([ "name": HIB"淡藍",
          "long": "武器的刃頭上帶有一絲藍色，不知是何用途。\n",
          "buff1": "armor",
          "buff2": "wittiness",
       ]),
    3: ([ "name": HIG"淡綠",
          "long": "武器的刃頭上帶有一絲綠色，不知是何用途。\n",
          "buff1": "evadebuff",
          "buff2": "evade",
       ]),
    4: ([ "name": HIY"淡黃",
          "long": "武器的刃頭上帶有一絲黃色，不知是何用途。\n",
          "buff1": "exactbuff",
          "buff2": "exact",
       ]),
    5: ([ "name": HIR"火紅",
          "long": HIR"武器的刃身充滿了火燄的紋痕，看起來非常漂亮。\n"NOR,
          "buff1": "attack",
          "buff2": "intimidate",
       ]),
    6: ([ "name": HIB"水藍",
          "long": HIB"武器的刃身充滿了水面的波痕，看起來非常漂亮。\n"NOR,
          "buff1": "armor",
          "buff2": "wittiness",
       ]),
    7: ([ "name": HIG"草綠",
          "long": HIG"武器的刃身充滿了葉子的葉痕，看起來非常漂亮。\n"NOR,
          "buff1": "evadebuff",
          "buff2": "evade",
       ]),
    8: ([ "name": HIY"金黃",
          "long": HIY"武器的刃身充滿了金塊的鑿痕，看起來非常漂亮。\n"NOR,
          "buff1": "exactbuff",
          "buff2": "exact",
       ]),
    9: ([ "name": RED"血紅",
          "long": RED"整把武器有如鮮血般的深紅，給人一種深不可測的感覺。\n"NOR,
          "buff1": "attack",
          "buff2": "intimidate",
       ]),
   10: ([ "name": BLU"海藍",
          "long": BLU"整把武器有如海底般的深藍，給人一種深不可測的感覺。\n"NOR,
          "buff1": "armor",
          "buff2": "wittiness",
       ]),
   11: ([ "name": GRN"墨綠",
          "long": GRN"整把武器有如叢林般的深綠，給人一種深不可測的感覺。\n"NOR,
          "buff1": "evadebuff",
          "buff2": "evade",
       ]),
   12: ([ "name": YEL"暗黃",
          "long": YEL"整把武器有如泥沼般的深黃，給人一種深不可測的感覺。\n"NOR,
          "buff1": "exactbuff",
          "buff2": "exact",
       ]),
]);

void die()
{
    object wp;
    int i, a;

    // 設定噴這種東西的 mob 打死得到的學點都是 1 點
    set_level(1);

    // 判斷此 mob 死亡後所留下的武器種類
    switch( this_object()->query("wp_number") ) {
        case 1: if( file_size("/mouse/wp/broad_sword.lpc") < 0 ) return 0;
                if( catch(wp = new("/mouse/wp/broad_sword.lpc")) ) return 0;
                break;
        case 2: if( file_size("/mouse/wp/thin_sword.lpc") < 0 ) return 0;
                if( catch(wp = new("/mouse/wp/thin_sword.lpc")) ) return 0;
                break;
        case 3: if( file_size("/mouse/wp/stone_lance.lpc") < 0 ) return 0;
                if( catch(wp = new("/mouse/wp/stone_lance.lpc")) ) return 0;
                break;
    }

    // 能力設定部份
    switch( random(1000) ) {
        case 0..25: wp->set("number", 40);
                       i = random(4)+9;
                       break;
        case 201..500: wp->set("number", 8);
                       i = random(4)+1;
                       break;
        case 701..800: wp->set("number", 20);
                       i = random(4)+5;
                       break;
        default: i = 0; wp->set("number", 4); break;
    }
    wp->set("name", record[i]["name"] + wp->query("name"));
    wp->set("long", wp->query("long") + record[i]["long"]);

    a = wp->query("number");
    switch( wp->query("wield_as") ) {
        case "righthand": wp->set("apply_weapon/righthand/"+record[i]["buff1"], a);
                          wp->set("apply_weapon/righthand/"+record[i]["buff2"], a*3/4);
                          break;
        case "lefthand": wp->set("apply_weapon/lefthand/"+record[i]["buff1"], a/2);
                         wp->set("apply_weapon/lefthand/"+record[i]["buff2"], a*3/8);
                         break;
        case "twohanded": wp->set("apply_weapon/twohanded/"+record[i]["buff1"], a/2);
                          wp->set("apply_weapon/twohanded/"+record[i]["buff2"], a*3/8);
                          break;
    }
    wp->delete("number");
    switch( random(100) ) {
        case 2: wp->set("name", RED"燃燒的"+wp->query("name")); wp->set("number", 1); break;
        case 14: wp->set("name", GRN"閉鎖的"+wp->query("name")); wp->set("number", 8); break;
        case 20: wp->set("name", BLU"極凍的"+wp->query("name")); wp->set("number", 3); break;
        case 32: wp->set("name", HIY"迅捷的"+wp->query("name")); wp->set("number", 6); break;
        case 44: wp->set("name", HIR"灼熱的"+wp->query("name")); wp->set("number", 2); break;
        case 57: wp->set("name", HIG"幽靜的"+wp->query("name")); wp->set("number", 4); break;
        case 75: wp->set("name", HIB"冷漠的"+wp->query("name")); wp->set("number", 7); break;
        case 89: wp->set("name", YEL"神速的"+wp->query("name")); wp->set("number", 5); break;
        default: wp->set("number", 0); break;
    }
    switch( wp->query("wield_as") ) {
        case "righthand": switch( wp->query("number") ) {
                              case 0: break;
                              case 1: wp->add("apply_weapon/righthand/str", 10); break;
                              case 2: wp->add("apply_weapon/righthand/str", 6); break;
                              case 3: wp->add("apply_weapon/righthand/con", 10); break;
                              case 4: wp->add("apply_weapon/righthand/con", 6); break;
                              case 5: wp->add("apply_weapon/righthand/dex", 6); break;
                              case 7: wp->add("apply_weapon/righthand/int", 10); break;
                              case 8: wp->add("apply_weapon/righthand/int", 6); break;
                          break;
                          }
        case "lefthand": switch( wp->query("number") ) {
                              case 0: break;
                              case 1: wp->add("apply_weapon/lefthand/str", 5); break;
                              case 2: wp->add("apply_weapon/lefthand/str", 3); break;
                              case 3: wp->add("apply_weapon/lefthand/con", 5); break;
                              case 4: wp->add("apply_weapon/lefthand/con", 3); break;
                              case 5: wp->add("apply_weapon/lefthand/dex", 5); break;
                              case 6: wp->add("apply_weapon/lefthand/dex", 3); break;
                              case 7: wp->add("apply_weapon/lefthand/int", 5); break;
                              case 8: wp->add("apply_weapon/lefthand/int", 3); break;
                          break;
                          }
        case "twohanded": switch( wp->query("number") ) {
                              case 0: break;
                              case 1: wp->add("apply_weapon/twohanded/str", 5); break;
                              case 2: wp->add("apply_weapon/twohanded/str", 3); break;
                              case 3: wp->add("apply_weapon/twohanded/con", 5); break;
                              case 4: wp->add("apply_weapon/twohanded/con", 3); break;
                              case 5: wp->add("apply_weapon/twohanded/dex", 5); break;
                              case 6: wp->add("apply_weapon/twohanded/dex", 3); break;
                              case 7: wp->add("apply_weapon/twohanded/int", 5); break;
                              case 8: wp->add("apply_weapon/twohanded/int", 3); break;
                          break;
                          }
    }

    // 死亡後產生訊息，並將武器掉在地上
    message_vision("$N臨死前手上$n把持不住，直接掉落在地上。\n"NOR, this_object(), wp);
    if( environment(this_object())->is_area() ) move_side(wp, this_object());
    else wp->move(environment(this_object()));
    ::die();
    return;
}
