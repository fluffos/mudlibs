int num=0;

void do_check()
{
    if( num > 0) {
        set("chat_chance", 10);
        this_object()->heal_stat("hp", num);
        message_vision( sprintf("$N"HIW"從地上撿起骸骨補充剛才消耗骨頭的傷害(%d) %s\n\n", num, COMBAT_D->report_status(this_object()) ), this_object());
        num = 0;
        return;
    }
    message_vision(CYN"$N檢查著四周有沒有敵人....\n"NOR, this_object());
    return;
}

void do_fight()
{
    int damage, raiseDamage, i, exact, evade;
    object enemy, item;
    object* targets;

    // 沒有敵人
    set("chat_chance", 100);
    enemy = this_object()->query_opponent();
    targets = this_object()->query_enemy();

    if( !enemy ) return;
    // 敵人在不同位置
    if( environment(this_object())->is_area() ) {
        if( !area_environment(this_object(), enemy) ) return;
    } else {
        if( environment(enemy) != environment(this_object()) ) return;
    }
    switch( random(5) ) {
        case 0: // 唐松之舞-攻擊多人
            num = num + 30;
            this_object()->receive_damage(15, this_object());
            message_vision("\n$N"NOR"從身上爆出幾根骨頭使出「"HIY"唐松之舞"NOR"」骨頭有如開花般射向四周！\n"NOR, this_object(), enemy);
            for(i=0;i<sizeof(targets);i++) {
                if( i == this_object()->query_level()/10 ) break;   // 照等級攻擊人數、剛之郎是6人 其他輝夜是3人
                if( !COMBAT_D->isHit(this_object(), targets[i]) ) {
                    message_vision("骨頭趴趴趴地插的滿地都是，但是卻沒有擊中$N\n", targets[i], this_object());
                    this_object()->start_busy(2);
                } else {
                    raiseDamage = this_object()->query_level()*7;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 150 ) damage = this_object()->query_level()*3 + random(50);

                    // 傷害盾吸收
                    damage = COMBAT_D->receive_damage(targets[i], this_object(), damage);
                    targets[i]->receive_damage(damage, this_object());
                    message_vision( sprintf("骨頭毫無目標地亂射，卻正好射中了$n造成一些傷害(%d) %s\n", damage, COMBAT_D->report_status(targets[i]) ), this_object(), targets[i]);
                    targets[i]->start_busy(1);
                }
            }
            message_vision("\n", this_object());
            break;
        case 1: // 鐵線花之舞-單體傷害
            num = num + 50;
            exact = COMBAT_D->intimidate(this_object(), 1)*1.5;
            evade = COMBAT_D->wittiness(enemy, 1);

            this_object()->receive_damage(25, this_object());
            message_vision("\n$N"NOR"手骨瞬間爆出，變成有如刺槍般的「"HIR"鐵線花之舞"NOR"」戳向$n的胸口！\n"NOR, this_object(), enemy);
            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("$N瞬間轉身將攻擊力道施力在槍骨的尖部，使$n的攻擊偏離了方向。\n\n", enemy, this_object());
                this_object()->start_busy(1);
            } else {
                raiseDamage = this_object()->query_level()*10;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                add_temp("apply/attack", -raiseDamage);

                if( damage < 140 ) damage = this_object()->query_level()*4 + random(50);

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("$n極力閃避攻擊，卻仍然被槍骨刺中身體的側部，形成一個血流如柱的窟窿(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
            }
            break;
        case 2: // 朔夜之舞-連續傷害
            num = num + 50;
            exact = COMBAT_D->exact(this_object(), enemy, 1)/5;
            add_temp("apply/exact", exact);

            this_object()->receive_damage(25, this_object());
            message_vision("\n$N"NOR"將十根手指對準了$n「"HIM"朔夜之舞"NOR"」骨頭「碰碰碰」地像機槍般射擊$n！\n"NOR, this_object(), enemy);
            for(i=0;i<3;i++) {
                if( !COMBAT_D->isHit(this_object(), enemy) ) {
                    message_vision("結果攻擊沒有擊中$N...\n", enemy, this_object());
                } else {
                    raiseDamage = this_object()->query_level()*5;

                    add_temp("apply/attack", raiseDamage); 
                    damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                    add_temp("apply/attack", -raiseDamage);

                    if( damage < 50 ) damage = this_object()->query_level() + random(25);

                    // 傷害盾吸收
                    damage = COMBAT_D->receive_damage(enemy, this_object(), damage);
                    enemy->receive_damage(damage, this_object());
                    message_vision( sprintf("$n「噗」地一聲被指骨戳出了一道傷口(%d) %s\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                }
            }
            add_temp("apply/exact", -exact);
            message_vision("\n", this_object());
            break;
        case 3: // 早蕨之舞-高傷害
            num = num + 200;
            exact = COMBAT_D->intimidate(this_object(), 1);
            evade = COMBAT_D->wittiness(enemy, 1);

            this_object()->receive_damage(100, this_object());
            message_vision("\n$N"NOR"身子往地下一沉，使出捨命必殺"HIY"『"HIR+BLINK"早蕨之舞"NOR+HIY"』"NOR"全身骨頭戳向四面八方！\n"NOR,this_object(), enemy);

            if( !COMBAT_D->SkillHit(this_object(), enemy, exact, evade) ) {
                message_vision("無數骨頭從地面直衝而上，將四周刺成骨山，但是沒打中$N...\n\n", enemy, this_object());
                this_object()->start_busy(2);
            } else {
                raiseDamage = this_object()->query_level()*20;

                add_temp("apply/attack", raiseDamage); 
                damage = COMBAT_D->isDamage(this_object(), enemy, query_temp("weapon/righthand"));
                add_temp("apply/attack", -raiseDamage);

                if( damage < 350 ) damage = this_object()->query_level()*10 + random(100);

                enemy->receive_damage(damage, this_object());
                message_vision( sprintf("「噗噗」連續幾聲，$n早已被戳成蜂窩，躺在紅色的血泊中(%d) %s\n\n", damage, COMBAT_D->report_status(enemy) ), this_object(), enemy);
                this_object()->start_busy(1);
            }
            break;
        case 4: // 脊骨劍
            if( this_object()->query_temp("weapon/righthand") != 0 ) break;

            item = new(__DIR__"wp/spinal.lpc");
            num = num + 300;

            this_object()->receive_damage(150, this_object());
            message_vision(HIW"$N施展起了「"NOR+YEL"山茶之舞"HIW"」將背部整條脊椎骨拔了出來！\n"NOR, this_object());
            item->move(this_object());
            item->wield("righthand");
            break;
    }
    return;
}
