void do_fight()
{
    int damage, raiseDamage, x, y, lv, sock, exact, evade;
    object enemy, item;
    object* targets;
    mapping cnd = ([]);

    // 沒有敵人
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    lv = query_level();

    switch( random(lv-30) ) {
        case 0..5:
            x = this_object()->query("area_info/x_axis");
            y = this_object()->query("area_info/y_axis");
            exact = COMBAT_D->wittiness(this_object(), 1)*1.2;
            evade = COMBAT_D->intimidate(enemy, 1);

            if( enemy->query_condition("bad_mud") ) return;
            if( !environment(this_object())->is_area() || !environment(this_object())->query_data(x, y, "terrainDamage") ) return;
            message_vision(YEL"\n$N伸出黏黏的雙手，不停地在沙塵堆中攪來攪去攪來攪去...\n"NOR, this_object());
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$N將沙塵揉成球狀砸在$n身上！$n滿身是泥阻礙了攻擊！\n\n"NOR, this_object(), enemy);

                cnd["name"] = BYEL"爛泥巴"NOR;
                cnd["duration"] = lv*10;
                cnd["attack"] = enemy->query("level")*5;
                cnd["intimidate"] = enemy->query("level");

                enemy->set_condition("bad_mud", cnd);
            } else {
                message_vision("$N傻呼呼地用手搔頭，弄的滿頭都是沙塵。\n\n"NOR, this_object());
            }
            return;
            break;
        case 6..15:
            exact = COMBAT_D->wittiness(this_object(), 1);
            evade = COMBAT_D->intimidate(enemy, 1);

            message_vision(HIK"\n$N捏出一團充滿彈性的"HIY"「跳跳泥」"HIK"怪叫一聲就朝$n丟了過去！\n"NOR, this_object(), enemy);
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                raiseDamage = lv*6;

                add_temp("apply/attack", raiseDamage);
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv ) damage = lv/2 + random(lv)/2;
                enemy->receive_damage(damage, this_object());

                // 傷害盾吸收
                damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
                message_vision( sprintf("爛泥擊中$n後發出噁心的臭味，使$n連昨天的晚餐都吐出來了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            } else {
                message_vision("還好$N閃的夠快，爛泥砸在地上，發出有如大便般的臭味...\n\n"NOR, enemy);
                start_busy(2);
            }
            return;
            break;
        case 16..25:
            if( query_condition("body_strength_cond") ) return;
            message_vision(HIY"\n$N的身體一縮一脹，忽然全身發出金屬般的光澤"NOR+YEL"「硬化」\n"NOR, this_object());
            message_vision(HIW"一陣耀眼的光芒後，$N身子似乎變硬了！\n\n"NOR, this_object());

            cnd["name"] = HIY"硬化"NOR;
            cnd["duration"] = lv*10;
            cnd["attack"] = 0;
            cnd["armor"] = lv*5;

            set_condition("body_strength_cond", cnd);
            start_busy(2);
            return;
            break;
        case 26..35:
            exact = COMBAT_D->wittiness(this_object(), 1);
            evade = COMBAT_D->intimidate(enemy, 1);

            message_vision(HIK"\n$N張開大嘴，朝$n吐出一團綠色臭氣"NOR+GRN"「史萊毒」"HIK"接著又吐出"HIR"火焰"HIK"！\n"NOR, this_object(), enemy);
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {

                raiseDamage = lv*3;

                add_temp("apply/attack", raiseDamage);
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv ) damage = lv/2 + random(lv)/2;
                enemy->receive_damage(damage, this_object());

                message_vision( sprintf("$n閃避不急被「史萊毒」擊中，當火焰噴至時發生一陣劇烈爆炸(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);

                cnd["name"] = GRN"史萊毒"NOR;
                cnd["duration"] = lv/2;
                cnd["from"] = this_object();

                if( !enemy->query_condition("vp") ) {
                    tell_object(enemy, HIG"(史萊毒侵入了你的體內，使你痛苦不堪。)\n"NOR);
                    enemy->set_condition("vp", cnd);
                }
                cnd["name"] = HIR"毒爆"NOR;
                cnd["duration"] = lv/5;
                cnd["from"] = this_object();

                if( !enemy->query_condition("firedamage") ) {
                    tell_object(enemy, HIR"(因為毒爆使你燒傷了！)\n"NOR);
                    enemy->set_condition("firedamage", cnd);
                }
            } else {
                message_vision("砸在地上的"GRN"「史萊毒」"NOR"被火焰噴中，發出一連串的小爆炸。\n\n"NOR, this_object());
            }
            return;
            break;
    }
}