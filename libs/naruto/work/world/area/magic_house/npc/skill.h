void do_fight()
{
    int damage, raiseDamage, i, exact, evade;
    object enemy, me;
    mapping cnd = ([]);

    // 沒有敵人
    me = this_object();
    enemy = me->query_opponent();
    if( !enemy ) return;

    // 敵人在不同位置
    if( environment(me)->is_area() ) {
        if( !area_environment(me, enemy) ) return;
    } else {
        if( environment(enemy) != environment(me) ) return;
    }
    switch( me->query("sktree") ) {
        case 1: // 雜耍小丑
            exact = COMBAT_D->exact(me, enemy, 1) + COMBAT_D->intimidate(me, 1);
            evade = COMBAT_D->evade(enemy, me, 1) + COMBAT_D->intimidate(enemy, 1);

            message_vision("\n$N從背後拿出五把鋼刀不停地在手上耍弄，忽然一個翻身朝$n擲了過來！\n", me, enemy);
            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision(HIC"結果鋼刀全部都射空了，卻不知$N何時又拿出五把鋼刀把玩著。\n\n"NOR, me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(2);
                return;
            }
            i = random(5) + 1;
            raiseDamage = 150*i;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 100 ) damage = 10 + random(90);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, me, damage);
            enemy->receive_damage(damage, me);
            message_vision( sprintf(HIC"「咻咻」數聲只見"+chinese_number(i)+"把鋼刀不偏不倚地插在$n的身上，血流如柱"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->damage_stat("mp", 20, me);
            me->start_busy(1);
            break;

        case 2: // 魔術小丑
            exact = COMBAT_D->exact(me, enemy, 1)/3;
            add_temp("apply/exact", exact);

            message_vision("\n$N拿出一塊黑布，將手上的匕首包了起來，臉上露出詭異的笑容...\n"NOR, me, enemy);
            if( !COMBAT_D->isHit(me, enemy) ) {
                message_vision(HIM"接著$N從黑布中拿出一隻小白兔然後大聲說道：謝謝$n的觀賞！\n\n"NOR, me, enemy);
                me->damage_stat("mp", 10, me);
                me->start_busy(1);
                return;
            }
            raiseDamage = 300 + random(300);

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 200 ) damage = 120 + random(80);

            enemy->receive_damage(damage, me);
            me->damage_stat("mp", 20, me);
            message_vision( sprintf(HIM"忽然在$n的後方憑空出現一隻拿著匕首的手，用力刺了$n一刀"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            add_temp("apply/exact", -exact);
            me->start_busy(1);
            break;

        case 3: // 空中飛人
            exact = COMBAT_D->exact(me, enemy, 1)/4;
            add_temp("apply/exact", exact);

            message_vision("\n$N忽然一跳數丈！抓住空中的鞦韆飛快地朝$n盪了過去！\n", me, enemy);
            if( !COMBAT_D->isHit(me, enemy) ) {
                message_vision(HIW"結果$n發現了$N的移動方向，$N只好放棄攻擊又跳了下來。\n\n"NOR, me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(1);
                return;
            }
            raiseDamage = 400 + random(200);

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 150 ) damage = 100 + random(50);

            enemy->receive_damage(damage, me);
            me->damage_stat("mp", 20, me);
            message_vision( sprintf(HIW"只見$N以雙腳勾住鞦韆給了$n一記重重的上勾拳"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            add_temp("apply/exact", -exact);
            me->start_busy(1);
            break;

        case 4: // 踩球小丑
            exact = COMBAT_D->exact(me, enemy, 1)*1.6;
            evade = COMBAT_D->evade(enemy, me, 1)*1.5;

            message_vision("\n$N將踩在腳下的大球用力一翻，整顆球快速的射向$n。\n", me, enemy);
            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision(HIG"$n稍微往右一退避開了攻擊，不知何時$N又把球踩回腳下。\n\n"NOR, me, enemy);

                me->damage_stat("mp", 20, me);
                me->start_busy(2);
                return;
            }
            raiseDamage = 500 + random(100);

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 150 ) damage = 80 + random(70);

            // 傷害盾吸收
            damage = COMBAT_D->receive_damage(enemy, me, damage);
            enemy->receive_damage(damage, me);
            message_vision( sprintf(HIG"「磅」地一聲，$n就像被鐵球擊中，整個人哀嚎不停"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->damage_stat("mp", 20, me);
            me->start_busy(1);
            break;

        case 5: // 火圈小丑
            exact = COMBAT_D->intimidate(me, 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            message_vision("\n$N拿起正在燃燒的火圈說道："HIG"該$n拉！快從這圈圈跳過去！\n"NOR, me, enemy);
            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision(HIR"$N將火圈朝$n丟了過來，但是$n身手矯健的從火圈中心跳了過去。\n\n"NOR, me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(2);
                return;
            }
            raiseDamage = 200;

            me->add_temp("apply/attack", raiseDamage); 
            damage = COMBAT_D->isDamage(me, enemy, this_object());
            me->add_temp("apply/attack", -raiseDamage);

            if( damage < 50 ) damage = 20 + random(30);

            enemy->receive_damage(damage, me);
            message_vision( sprintf(HIR"但是$N沒經過訓練跳不過火圈，全身被火焰燒傷了"NOR"(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
            me->damage_stat("mp", 30, me);
            me->start_busy(1);

            cnd["name"] = HIR+"燒傷"+NOR;
            cnd["duration"] = 5;
            cnd["from"] = me;

            enemy->set_condition("firedamage", cnd);
            break;
    }
}