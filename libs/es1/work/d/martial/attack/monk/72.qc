
            本次更动少林 72 绝技的内容, 主要是更动特攻出现机率,由
        原来的纯粹数字 random 改为与各 72 的 gonfu level 相关。一
        般 72 绝技 (body-def、bolo-fist、dragon-claw、keep-flower)
        皆改为与该 gonfu level 成直线正相关, 最高出现率(when lv=35)
        1/10, 最低则为 0, 原来的机率则是 2/37; 而 power-finger 特攻
        为连续攻击, 本来就是 random 出现的, 惟原来是单纯的数字 
        random, 今改为与 lv 成直线正相关, 最高出现率(when lv=35)为 
        1/6 最低为 0, 原为14/100; 在连续攻击中, 继续连续攻击的机率
        , 最高(when lv=35)为 1/3, 最低为 0, 原为 27/100 (即原机率
        的两倍) 。


            另外, 亦期望能将各项特攻强度改成与 gonfu level 成正相关,
        其中 keep-flower & power-finger 的特攻强度较难以定义, 因此,
        keep-flower 改为 block_attack 的回合数与 gonfu level 的随机值
        正相关; power-finger 则无更动(有这麽高的连续攻击率应该不错了).
        bolo-fist 原来就成正相关, 特攻强度未更动; dragon-claw 则由原来
        的与 int 正相关改为与 gonfu level 正相关。body-def 的特攻原为
        this_player()->receive_healing(); 但未开放, angel 与我都觉得
        不太适当, 因此新增特攻－－内力反震, 反震强度与玩家的内力值成
        正相关, 为模拟反震, 玩家可同时回复 hp 以抵销原来的受创。

            以上为此次更动内容之大要, 含有档案:
        /d/martial/attack/monk/general/b_f.c (bolo_fist)
        /d/martial/attack/monk/general/d_c.c (dragon_claw)
        /d/martial/attack/monk/general/k_f.c (keep_flower)
        /d/martial/attack/monk/general/p_f.c (power_finger)
        /d/martial/defense/monk/general/b_d.c (body_def)

            各项 gonfu 之原档案仍在, 以供比对之用。

                                          Sincerely your Vincent..
