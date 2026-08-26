int isSock(object ob, object enemy)
{
    return (COMBAT_D->sock(ob, enemy, 1) > random(100));
}

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
            exact = COMBAT_D->intimidate(this_object(), 1)*1.2;
            evade = COMBAT_D->wittiness(enemy, 1);

            if( !environment(this_object())->is_area() || !environment(this_object())->query_data(x, y, "terrainDamage") ) return;
            message_vision(HIR"\n$N活蹦亂跳地跳到火霧中，雙手凝聚起來，慢慢出現一顆"HIY"光球"HIR"...\n"NOR, this_object());
            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                raiseDamage = lv*7;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv*2 ) damage = lv + random(lv);

                // 傷害盾吸收
                damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("$N兩手一張「"HIY"龜派氣功"NOR"」轟隆一聲將$n擊飛出去(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            } else {
                message_vision("但是光球光芒漸暗，很快地就消失了。\n\n"NOR, this_object());
            }
            return;
            break;
        case 6..15:
            if( query_condition("body_strength_cond") ) return;

            message_vision(HIW"\n$N目不轉睛的盯著月亮，眼神逐漸兇暴，身形愈來愈巨大！\n"NOR, this_object());
            message_vision(HIR"$N暴吼一聲，似乎已經巨化完成了。\n\n"NOR, this_object());

            cnd["name"] = HIR"巨大化"NOR;
            cnd["duration"] = lv*10;
            cnd["attack"] = lv*2;
            cnd["armor"] = lv;

            set_condition("body_strength_cond", cnd);
            start_busy(2);
            return;
            break;
        case 16..25:
            set_skill("sock power", lv*2);
            sock = isSock(this_object(), enemy);
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);
            delete_skill("sock power");

            if( sock ) message_vision(HIR"\n(致命一擊) "HIY"$N右臂一陣爆漲「"HIW"強力硬猴拳"HIY"」$N左手撐地衝向前方，拳風快速砸向$n！\n"NOR, this_object(), enemy);
            else message_vision(HIY"\n$N甩動右臂「"HIW"硬猴拳"HIY"」$N怪叫一聲，將力量集中於右臂強力一擊！\n"NOR, this_object());

            if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                raiseDamage = lv*6;

                add_temp("apply/attack", raiseDamage);
                damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                if( damage < lv*2 ) damage = lv + random(lv);
                if( sock ) damage = (damage * COMBAT_D->sockPower(this_object(), enemy, 1))/100;

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("「碰」地一聲，$n只感覺腦袋一陣劇痛後毫無知覺，好像被打斷了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            } else {
                message_vision("結果拳頭打偏了，在$n頭旁吹起一陣強風，嚇的$n一身冷汗。\n\n"NOR, this_object(), enemy);
                start_busy(4);
            }
            return;
            break;
        case 26..35:
            exact = COMBAT_D->intimidate(this_object(), 1)*9/10;
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision(HIR"\n$N靈活地衝到$n"HIR"身前，一式「"HIW"硬猴拳"NOR"‧"HIY"壹掌肆式"HIR"」戳擊打拍一氣呵成！\n"NOR, this_object(), enemy);
            for(x=0;x<4;x++) {
                if( COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    raiseDamage = lv*5;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < lv*2 ) damage = lv + random(lv);

                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("$n受到這記攻擊擊中，身子疼痛不已，哇哇大叫(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                } else {
                    message_vision("還好$N功夫練的不到家，這記攻擊並沒有成功。\n"NOR, this_object(), enemy);
                }
            }
            start_busy(3);
            message_vision("\n"NOR, this_object());
            return;
            break;
    }
}