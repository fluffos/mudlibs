void die()
{
    object item = new(query("item_drop"));
    int i, j, corr=1;
    string new_name = "";
    string id = item->query("id");

    // 判斷 mob 死亡後應該噴出的東西為何
    if( !query("item_drop") ) {
        ::die();
        return;
    }
    if( !objectp(item) ) {
        destruct(item);
        ::die();
        return;
    }
    switch( random(1000) ) {
        case 0..5:
            new_name += HIY"(超凡)";
            corr = 3;
            break;
        case 6..20:
            new_name += HIW"(不凡)";
            corr = 2;
            break;
    }
    if( item->query("wield_as") ) {
        mapping apply = item->query("apply_weapon/" + item->query("wield_as"));
        if( random(1000) < 5 ) {
            switch( random(4) ) {
                case 0:
                    new_name += HIG "青龍";
                    apply["con"] += 3*corr;
                    id = "qinglong " + id;
                    break;
                case 1:
                    new_name += HIR "朱雀";
                    apply["int"] += 3*corr;
                    id = "zhuque " + id;
                    break;
                case 2:
                    new_name += HIW "白虎";
                    apply["str"] += 3*corr;
                    id = "baihu " + id;
                    break;
                case 3:
                    new_name += HIB "玄武";
                    apply["dex"] += 3*corr;
                    id = "xuanwu " + id;
                    break;
            }
        }
        if( random(100) < 8 ) {
            switch( random(4) ) {
                case 0:
                    new_name +=  "長生";
                    apply["con"] += 1*corr;
                    break;
                case 1:
                    new_name +=  "帝旺";
                    apply["int"] += 1*corr;
                    break;
                case 2:
                    new_name +=  "冠帶";
                    apply["str"] += 1*corr;
                    break;
                case 3:
                    new_name +=  "臨官";
                    apply["dex"] += 1*corr;
                    break;
            }
        }
        if( new_name != "" ) {
            new_name += item->query("name") + NOR;
            item->set("name", new_name);
            item->set("id", id);
            item->set("apply_weapon/" + item->query("wield_as"), apply);
        }
    } else if( item->query("wear_as") ) {
        mapping apply = item->query("apply_armor/" + item->query("wear_as"));
        if( random(100) < 7 ) {
            switch( random(6) ) {
                case 0:
                    new_name += HIC "積極的";
                    apply["intimidate"] += 3*corr;
                    break;
                case 1:
                    new_name += HIC "沉著的";
                    apply["wittiness"] += 3*corr;
                    break;
                case 2:
                    new_name += HIC "高超的";
                    apply["exact"] += 3*corr;
                    break;
                case 3:
                    new_name += HIC "靈巧的";
                    apply["evade"] += 3*corr;
                    break;
                case 4:
                    new_name += HIC "穩重的";
                    apply["armor"] += 3*corr;
                    break;
                case 5:
                    new_name += HIC "兇暴的";
                    apply["attack"] += 3*corr;
                    break;
            }
        }
        if( random(100) < 1 ) {
            switch( random(4) ) {
                case 0:
                    new_name += HIC "火神";
                    apply["intimidate"] += 5*corr;
                    id = "Vulcan " + id;
                    break;
                case 1:
                    new_name += HIC "水神";
                    apply["wittiness"] += 5*corr;
                    id = "Narcissus " + id;
                    break;
                case 2:
                    new_name += HIC "海神";
                    apply["exact"] += 5*corr;
                    id = "Poseidon " + id;
                    break;
                case 3:
                    new_name += HIC "酒神";
                    apply["evade"] += 5*corr;
                    id = "Dionysus " + id;
                    break;
                case 4:
                    new_name += HIC "戰神";
                    apply["attack"] += 5*corr;
                    id = "Mars " + id;
                    break;
                case 5:
                    new_name += HIC "山神";
                    apply["armor"] += 5*corr;
                    id = "Nymphs " + id;
                    break;
            }
        }
        if( new_name != "" ) {
            new_name += item->query("name") + NOR;
            item->set("name", new_name);
            item->set("id", id);
            item->set("apply_armor/" + item->query("wear_as"), apply);
        }
    }
    // 讓物品被記憶重登不修改能力
    item->set("changed", 1);

    // 物品最後再丟在地上，有機率判斷
    if( query("molecule") ) i = query("molecule");
    else i = 1;

    if( query("denominator") ) j = random(query("denominator"))+1;
    else j = random(100)+1;

    // 直接掉落在地上，回到屍體上的判斷太多
    if( i >= j ) {
        message_vision("$N配在身上的$n因此脫落而掉落到地面。\n"NOR, this_object(), item);
        if( environment(this_object())->is_area() ) move_side(item, this_object());
        else item->move(environment(this_object()));
    }
    ::die();
    return;
}
