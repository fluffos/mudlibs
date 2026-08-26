void do_fight()
{
    string dogname;
    int damage, raiseDamage, x, y, exact, evade;
    object enemy, me, mob, ob;
    mapping cnd = ([]);

    string *name1 = ({ "蘇", "聖", "邦", "頑固", "愛", "掰", "沖田", "樓", "楊", "風","吸", 
                       "趴", "跛", "愛新覺羅", "娜", "莫", "巴圖", "無", "瑪", "西埃", "莫", 
                       "奪命", "發呆" , "卡", "摩", "克", "阿", "巴", "傑克", "夢幻" });

    string *name3 = ({ "犬", "獸", "狗", "獅", "虎" });

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
        case 1: // 雜耍卡巴吉
            if( random(4) > 1 ) {
                message_vision("\n$N四周快速竄起大量濃霧，只聽$N說道「"HIY"密技"NOR"‧"HIW"煙霧殺人事件"NOR"！」\n", me, enemy);

                raiseDamage = me->query_attr("str")*2;
                if( damage > 70) raiseDamage = 70;

                raiseDamage += me->query_skill("blade");

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                // 判斷命中
                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("但是濃霧很快就散了開來，藏不住$N的身影。\n\n", me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(2);
                    return;
                }
                enemy->receive_damage(damage, me);
                message_vision( sprintf("$n被濃霧所覆蓋找不到$N的蹤跡，結果被攻擊刺傷了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->damage_stat("mp", 10, me);
                me->start_busy(1);
            } else {
                message_vision("\n$N倚著山壁一飛衝天！忽然在空中一蹬『"HIY"雜技"NOR"‧"YEL"獨輪登山"NOR"』從天而降刺向$n！\n", me, enemy);

                raiseDamage = me->query_skill("blade");

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                exact = COMBAT_D->exact(me, enemy, 1) + COMBAT_D->intimidate(me, 1);
                evade = COMBAT_D->evade(enemy, me, 1) + COMBAT_D->wittiness(enemy, 1);

                if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                    message_vision("$N重心不穩，自己從空中跌了下來。\n\n", me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(2);
                    return;
                }
                // 傷害盾吸收
                damage = COMBAT_D->receive_damage(enemy, me, damage);
                enemy->receive_damage(damage, me);
                message_vision( sprintf("$n躲避不急被高速落下的利刃所刺傷(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(1);
            }
            break;

        case 2: // 猛獸使摩奇
            x = me->query("area_info/x_axis");
            y = me->query("area_info/y_axis");
            mob = new(__DIR__"dog.lpc");
            dogname = name1[random(sizeof(name1))] + name3[random(sizeof(name3))];

            if( me->query_temp("dog_clone") != 1 ) {
                message_vision("$N"HIY"舉手吹起口哨，從旁邊跑出一隻"NOR+dogname+HIY"。\n"NOR, me);
                if( environment(me)->is_area() ) {
                    mob->set("name", dogname);
                    if( area_move(environment(me), mob, x, y) ) {
                        mob->guard_ob(me);
                        mob->set_leader(me);
                        me->guard_ob(mob);

                        mob->kill_ob(enemy);
                        if( function_exists("accept_kill", enemy) && !enemy->is_killing(mob) && enemy->accept_kill(mob) ) return;
                        if( !enemy->is_killing(mob) ) enemy->kill_ob(mob);

                        me->set_temp("dog_clone", 1);
                        return;
                    }
                    message_vision("但是$N技術太差，吹不出聲音。\n", me);
                    do_chat((: random_move :));
                    return;
                }
                message_vision("但是這裡是房間，聲音傳不出去。\n", me);
                do_chat((: random_move :));
                return;
            } else {
                if( !present("_ANIMAL_", environment(me)) ) message_vision("$N哭喊著："HIG"寵物阿你跑到哪裡去啦！\n"NOR, me);
                message_vision("\n$N呼叫寵物進行『"HIW"人獸合擊"NOR"』$N揮動鞭子打斷$n的退路後寵物撲上！\n", me, enemy);

                exact = COMBAT_D->exact(me, enemy, 1)/2;
                add_temp("apply/exact", exact);

                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("但是雙方根本就沒有配合好，$N逃過了一劫。\n\n", enemy);
                    me->damage_stat("mp", 10, me);
                    me->start_busy(2);
                } else {
                    raiseDamage = me->query_skill("activity")*4/5;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    enemy->receive_damage(damage, me);
                    me->damage_stat("mp", 20, me);
                    message_vision( sprintf("猛獸嘶吼一聲撲向$n，從$n的身上咬下了一塊肉！(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->start_busy(1);
                }
                add_temp("apply/exact", -exact);
                return;
            }
            break;

        case 3: // 黑貓船長克洛
            message_vision("\n$N雙手下垂不停左右搖擺，配合"HIM"無影腳"NOR"身法使出敵我不分殺招"HIR"『"HIK+BLINK"杓死"NOR+HIR"』\n"NOR, me, enemy);

            exact = COMBAT_D->exact(me, enemy, 1)/3;
            add_temp("apply/exact", exact);

            if( !COMBAT_D->isHit(me, enemy) ) {
                message_vision("$n胡亂揮舞抵抗，恰巧擋下了$N的攻擊。\n\n", me, enemy);
                me->damage_stat("mp", 10, me);
                me->start_busy(1);
            } else {
                raiseDamage = me->query_skill("martial") + 15;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -raiseDamage);

                // 傷害盾吸收
                damage = COMBAT_D->receive_damage(enemy, me, damage);
                enemy->receive_damage(damage, me);
                me->damage_stat("mp", 20, me);
                message_vision( sprintf("「刷刷」數聲無數爪刃從四面八方給予$n嚴重傷害(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->start_busy(1);
            }
            add_temp("apply/exact", -exact);
            break;

        case 4: // 催眠師傑克斯
            exact = COMBAT_D->exact(me, enemy, 1);
            add_temp("apply/exact", exact)/4;

            if( !enemy->is_busy() ) {
                message_vision("\n$N拿起武器左右搖晃說："HIG"當我說一、二、$N"HIG"！"NOR"$n"HIG"就會睡著！\n"NOR, me, enemy);
                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("$N隨後說道："HIG"一！二！$N！...結果他自己睡著了...\n\n"NOR, me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(4);
                } else {
                    me->damage_stat("mp", 20, me);
                    message_vision("$N隨後說道："HIG"一！二！$N！...結果"NOR"$n"HIG"逐漸被催眠而睡著了。\n\n"NOR, me, enemy);
                    me->start_busy(1);
                    enemy->start_busy(3);
                }
            } else {
                message_vision("\n$N將武器快速旋轉「"HIW"圈刃"NOR"」快速的擲向無法行動的$n！\n", me, enemy);
                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("但是$N的攻擊方向似乎沒有算準，只切了幾片樹葉。\n\n", me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(1);
                } else {
                    raiseDamage = me->query_skill("martial")/2;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    enemy->receive_damage(damage, me);
                    me->damage_stat("mp", 20, me);
                    message_vision( sprintf("「啪」地一聲打中$n，$n受創痛苦不堪(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->start_busy(1);
                }
            }
            add_temp("apply/exact", -exact);
            break;

        case 5: // 鬼人阿金
            if( random(4) > 1 ) {
                message_vision("\n$N旋轉手上「"HIK"鉛鎚球"NOR"」忽然高速衝向$n以重力加速度打擊$n！\n", me, enemy);

                exact = COMBAT_D->exact(me, enemy, 1)/2;
                add_temp("apply/exact", exact);

                if( !COMBAT_D->isHit(me, enemy) ) {
                    message_vision("$N身子一歪避過了這次的攻擊...\n\n", enemy);
                    me->damage_stat("mp", 10, me);
                    me->start_busy(3);
                } else {
                    raiseDamage = me->query_skill("spurn");

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    enemy->receive_damage(damage, me);
                    me->damage_stat("mp", 20, me);
                    message_vision( sprintf("$n閃避不及，被砸的眼冒金星...吐出一口鮮血(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->start_busy(1);
                    enemy->start_busy(1);
                }
            } else {
                message_vision("\n$N將鉛鎚球反手旋轉，一記「"HIR"反手側擊"NOR"」砸向$n的肩膀。\n", me, enemy);

                exact = COMBAT_D->exact(me, enemy, 1)*1.7;
                evade = COMBAT_D->evade(enemy, me, 1)*1.5;

                if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                    message_vision("$N稍微往後一退避開了攻擊。\n\n", enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(2);
                } else {
                    raiseDamage = me->query_skill("spurn")*2/3;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(me, enemy, 0);
                    add_temp("apply/attack", -raiseDamage);

                    // 傷害盾吸收
                    damage = COMBAT_D->receive_damage(enemy, me, damage);
                    enemy->receive_damage(damage, me);
                    message_vision( sprintf("「磅」地一聲，鎚球擊中$n肩膀，擊傷了$n(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                    me->damage_stat("mp", 20, me);
                    me->start_busy(1);
                }
            }
            break;

        case 6: // 鐵壁巴拉
            if( enemy->query_condition("firelotus") ) return;
            message_vision("\n$N互擊雙拳鐵壁磨擦產生高熱『"HIM"火焰$N"NOR"』鐵壁一揮烈火噴向$n！\n", me, enemy);

            exact = COMBAT_D->intimidate(me, 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            if( !COMBAT_D->SkillHit(me, enemy, exact, evade) ) {
                message_vision("火焰燒到一半忽然快速減弱而消失殆盡了。\n\n", enemy);
                me->damage_stat("mp", 20, me);
                me->start_busy(2);
            } else {
                add_temp("apply/attack", 60); 
                damage = COMBAT_D->isDamage(me, enemy, 0);
                add_temp("apply/attack", -60);

                enemy->receive_damage(damage, me);
                message_vision( sprintf("火焰在$n四周爆開，形成一片炎熱的火海(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), me, enemy);
                me->damage_stat("mp", 30, me);
                me->start_busy(1);

                cnd["name"] = HIR+"火焰巴拉"+NOR;
                cnd["duration"] = 5;
                cnd["from"] = me;

                enemy->set_condition("firelotus", cnd);
            }
            break;
    }
}