int num;

void do_fight()
{
    mapping cnd = ([]);
    int damage, raiseDamage, i, exact, evade;
    object enemy;
    object* targets;

    enemy = this_object()->query_opponent();
    targets = this_player()->query_enemy();

    if( !enemy ) return;
    if( this_object()->is_busy() ) return;

    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( query("skill_list") ) {
        case 0: // 武田家-風林火山
            if( random(2) == 1 ) {
                command("perform takeda lance.lunge");
            } else {
                if( this_object()->query_condition("fourskills") != 0 ) break;
                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N揮舞著"+query("name")+"使出武田家秘傳技巧「"HIC"風"HIG"林"HIR"火"HIY"山"NOR"」與大自然同化，共存共生！\n\n", this_object(), enemy);

                cnd["name"] = HIC"風"HIG"林"HIR"火"HIY"山"NOR;
                cnd["duration"] = 60;

                this_object()->set_condition("fourskills", cnd);
            }
            break;
        case 1: // 吳氏-妖炎拳連擊
            if( random(2) == 1 ) {
                command("perform wu fire finger.fire");
            } else {
                add_temp("apply/attack", 100);
                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N暴喝一聲「"HIR"妖炎拳"NOR"第貳拾柒式─"RED"火山"NOR"」同時右手握拳朝地面一擊！\n\n"NOR, this_object(), enemy);
                for(i=1;i<4;i++) {
                 message_vision(CYN"火山爆發 第"+chinese_number(i)+"擊\n"NOR, this_object(), enemy);
                    COMBAT_D->fight(this_object(), enemy, this_object()->query_temp("weapon/twohanded"));
                }
                add_temp("apply/attack", -100);
                message_vision("\n$N"CYN"收回了對"NOR"$n"CYN"的妖炎拳攻擊！\n\n"NOR, this_object(), enemy);
                this_object()->start_busy(5);
            }
            break;
        case 2: // 魏氏-冰凍劍
            if( random(2) == 1 ) {
                command("perform wei ice sword.ice");
            } else {
                if( enemy->is_busy() ) return;
                exact = COMBAT_D->intimidate(this_object(), 1)*1.2;
                evade = COMBAT_D->wittiness(enemy, 1);

                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N以「魏氏"HIC"薄冰劍"NOR"」耍起劍舞，一時間雪花紛飛煞是好看。\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("不過$N立即回過神來，沒有被這陣雪花所影響。\n\n", enemy, this_object());
                    this_object()->start_busy(2);
                } else {
                    message_vision("$N好似看呆了，又像被這雪花所冷凍，整個人呆愣住了！\n\n", enemy, this_object());
                    enemy->start_busy(5);
                }
            }
            break;
        case 3: // 毛利家-龍骨總櫓
            if( random(2) == 1 ) {
                command("perform mouri bow.loose");
            } else {
                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N使用造船技巧「"HIW"龍骨"NOR"」與「"HIK"總櫓"NOR"」幫自己增加防禦能力。\n"NOR, this_object(), enemy);
                if( random(this_object()->query_level()) < 10 ) {
                    this_object()->add_temp("apply/armor", -num);
                    num = 0;
                    message_vision("結果$N的製作手段太過粗糙，全身增加的防禦都崩落了！\n\n", this_object(), enemy);
                    this_object()->start_busy(2);
                } else {
                    damage = random(this_object()->query_level());
                    if( num <= 0 ) num = damage;
                    else num += damage;
                    message_vision("經過了$N的補強，使$N自身的防禦提高了許多！\n\n", this_object(), enemy);
                    this_object()->add_temp("apply/armor", damage);
                }
            }
            break;
        case 4: // 上杉-越後之龍
            if( random(2) == 1 ) {
                command("perform nagao katana.hew");
            } else {
                exact = COMBAT_D->exact(this_object(), enemy, 1)*1.1;
                evade = COMBAT_D->evade(enemy, this_object(), 1);

                this_object()->damage_stat("mp", 15, this_object());
                message_vision("\n$N利用離心力連續旋轉發動攻擊「"HIW"越後龍攀"NOR"‧"HIC"車輪"NOR"」有如龍捲風捲向$n！\n"NOR, this_object(), enemy);
                if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                    message_vision("誰知$n早就離開了攻擊範圍，$N自己轉的頭暈目眩！\n\n", this_object(), enemy);
                    this_object()->start_busy(6);
                } else {
                    raiseDamage = 700;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("wield/righthand"));
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 200 ) damage = 150 + random(50);

                    enemy->receive_damage(damage, this_object());
                    if( damage >= 600 ) {
                        message_vision( sprintf("$n完全被旋風所迷惑，不但受創嚴重，連方向都搞不清楚了(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                        enemy->start_busy(3);
                    } else {
                        message_vision( sprintf("$n被捲入旋風當中，被銳利的武士刀砍的體無完膚(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                    }
                    this_object()->start_busy(2);
                }
            }
            break;
        case 5: // 織田-鐵砲合擊
            if( random(2) == 1 ) {
                switch( random(3) + 1) {
                    case 1: command("perform germ gun.loose");
                    case 2: command("perform germ gun.loose");
                    case 3: command("perform germ gun.loose"); break;
                }
            } else {
                exact = COMBAT_D->intimidate(this_object(), 1)*1.8;

                this_object()->damage_stat("mp", 5, this_object());
                message_vision("\n$N將種子島"REV"鐵砲"NOR"的子彈取出換成另一種紅色子彈「"RED"釣瓶彈"NOR"」射擊！\n"NOR, this_object(), enemy);
                for(i=0;i<sizeof(targets);i++) {
                    if( i == 4 ) break;

                    evade = COMBAT_D->wittiness(targets[i], 1)*1.5;

                    if( !COMBAT_D->SkillHit(this_object(), targets[i], exact, evade) ) {
                        message_vision("沒想到紅色子彈發射後居然爆裂散射攻擊，可惜沒打中$n\n", this_object(), targets[i] );
                    } else {
                        raiseDamage = 250;

                        add_temp("apply/attack", raiseDamage); 
                        damage = COMBAT_D->isDamage(this_object(), targets[i], query_temp("weapon/twohanded"));
                        add_temp("apply/attack", -raiseDamage);

                        if( damage < 100 ) damage = random(20) + 80;

                        // 傷害盾吸收
                        damage = COMBAT_D->receive_damage(targets[i], this_object(), damage);
                        targets[i]->receive_damage(damage, this_object());
                        message_vision( sprintf("紅色子彈發射後立刻爆裂散射四周，正好射中了$n造成傷害(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                    }
                }
                message_vision("\n", this_object());
                this_object()->start_busy(2);
            }
            break;
    }
    return;
}