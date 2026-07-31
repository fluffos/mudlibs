// rankd.c
// 1996-02-15 dts ranking related to "shen"
// 2003-07-02 Updated by zjb@TY 
#pragma save_binary

string query_rank(object ob)
{
        mapping fam;
        int dj;

        dj   = ob->query("zjb_dj/dj");
        fam  = ob->query("family/family_name");

        if(ob->query("ty_rank"))
                return NOR"【"HIW+ob->query("ty_rank")+NOR"】"; 

        if(wizardp(ob)&&ob->query("env/own_rank"))
             return NOR"【"HIW+ob->query("ty_rank")+NOR"】"; 
             
        if( wizardp(ob) && ob->query("rank_info/title") ) {
						if (ob->query("rank_info/title2"))
						return ob->query("rank_info/title")+ob->query("rank_info/title2");
						else return ob->query("rank_info/title");
				}
		
				if ( !ob->query("rank_info/title2"))
				ob->set("rank_info/title2","");     

        if( ob->is_ghost() ) 
                return NOR "【"HIB"孤魂野鬼"NOR"】";

                switch(wizhood(ob)) {
                case "(boss)":                 
                         return NOR "【"HIY"游戏策划"NOR"】" +ob->query("rank_info/title2") ;
                case "(admin)":                 
                        return NOR "【"HIR"天界总管"NOR"】" +ob->query("rank_info/title2");
                case "(arch)":                  
                        return NOR "【"HIY"八部天神"NOR"】" +ob->query("rank_info/title2");               
                case "(wizard)":                
                        return NOR "【"HIC"护法尊者"NOR"】" +ob->query("rank_info/title2");
                case "(apprentice)":            
                        return NOR "【"HIG"天宫侍卫"NOR"】" +ob->query("rank_info/title2");  
                case "(immortal)":              
                        return NOR "【"HIB"逍遥散仙"NOR"】" +ob->query("rank_info/title2");
                default: break;
                }

        if (dj > 150)
        {
                if (ob->query("gender") == "无性")
                        return CYN "【 九千岁 】" NOR+ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return HIW "【 圣  僧 】" NOR+ob->query("rank_info/title2");
                case "武当派":
                        return HIW "【 天  尊 】" NOR+ob->query("rank_info/title2");
                case "峨嵋派":
                        return HIW "【 圣  尼 】" NOR+ob->query("rank_info/title2");
                case "逍遥派":
                        return HIW "【 逸  仙 】" NOR+ob->query("rank_info/title2");
                case "灵鹫宫":
                        return HIW "【天山姥姥】" NOR+ob->query("rank_info/title2");
                case "星宿派":
                        return HIW "【星宿老怪】" NOR+ob->query("rank_info/title2");
                case "古墓派":
                        return HIW "【 神  侠 】" NOR+ob->query("rank_info/title2");
                case "全真教":
                        return HIW "【 中神通 】" NOR+ob->query("rank_info/title2");
                case "昆仑派":
                        return HIW "【 三  圣 】" NOR+ob->query("rank_info/title2");
                case "桃花岛":
                        return HIW "【 东  邪 】" NOR+ob->query("rank_info/title2");
                case "雪山寺":
                        return HIW "【不动明王】" NOR+ob->query("rank_info/title2");
                case "丐帮":
                        return HIW "【 北  丐 】" NOR+ob->query("rank_info/title2");
                case "天地会":
                        return HIW "【 英  雄 】" NOR+ob->query("rank_info/title2");
                case "神龙教":
                        return HIW "【神龙教主】" NOR+ob->query("rank_info/title2");
                case "五毒教":
                        return HIW "【毒手残心】" NOR+ob->query("rank_info/title2");
                case "明教":
                        return HIW "【光明圣使】" NOR+ob->query("rank_info/title2");
                case "梅庄":
                        return HIW "【 庄  主 】" NOR+ob->query("rank_info/title2");
                case "天龙寺":
                        return HIW "【 圣  僧 】" NOR+ob->query("rank_info/title2");
                case "华山派":
                        return HIW "【 剑  圣 】" NOR+ob->query("rank_info/title2");
                case "日月神教":
                        return HIW "【日月圣尊】" NOR+ob->query("rank_info/title2");
                case "慕容世家":
                        return HIW "【 大燕皇 】" NOR+ob->query("rank_info/title2");
                case "大理段家":
                        return HIW "【 南  帝 】" NOR+ob->query("rank_info/title2");
                default:
                        return HIW "【金榜高手】" NOR+ob->query("rank_info/title2");
                }
        } else
        if (dj > 100)
        {
                if (ob->query("gender") == "无性")
                        return HIY "【大内高手】" NOR+ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return HIY "【 神  僧 】" NOR+ob->query("rank_info/title2");
                case "武当派":
                        return HIY "【 真  人 】" NOR+ob->query("rank_info/title2");
                case "峨嵋派":
                        return HIY "【 神  尼 】" NOR+ob->query("rank_info/title2");
                case "逍遥派":
                        return HIY "【 护  法 】" NOR+ob->query("rank_info/title2");
                case "灵鹫宫":
                        return HIY "【灵鹫左使】" NOR+ob->query("rank_info/title2");
                case "星宿派":
                        return HIY "【 毒圣手 】" NOR+ob->query("rank_info/title2");
                case "古墓派":
                        return HIY "【 隐  侠 】" NOR+ob->query("rank_info/title2");
                case "全真教":
                        return HIY "【 真  人 】" NOR+ob->query("rank_info/title2");
                case "昆仑派":
                        return HIY "【 武  狂 】" NOR+ob->query("rank_info/title2");
                case "桃花岛":
                        return HIY "【 半  邪 】" NOR+ob->query("rank_info/title2");
                case "雪山寺":
                        return HIY "【 法  王 】" NOR+ob->query("rank_info/title2");
                case "丐帮":
                        return HIY "【 神  丐 】" NOR+ob->query("rank_info/title2");
                case "天地会":
                        return HIY "【 英  豪 】" NOR+ob->query("rank_info/title2");
                case "神龙教":
                        return HIY "【神龙无敌】" NOR+ob->query("rank_info/title2");
                case "五毒教":
                        return HIY "【 毒  王 】" NOR+ob->query("rank_info/title2");
                case "明教":
                        return HIY "【 法  王 】" NOR+ob->query("rank_info/title2");
                case "梅庄":
                        return HIY "【 乐  神 】" NOR+ob->query("rank_info/title2");
                case "天龙寺":
                        return HIY "【 神  僧 】" NOR+ob->query("rank_info/title2");
                case "华山派":
                        return HIY "【 剑  豪 】" NOR+ob->query("rank_info/title2");
                case "日月神教":
                        return HIY "【圣教长老】" NOR+ob->query("rank_info/title2");
                case "慕容世家":
                        return HIY "【 皇  尊 】" NOR+ob->query("rank_info/title2");
                default:
                        return HIY "【红榜高手】" NOR+ob->query("rank_info/title2");
                }
        } else
        if (dj > 70)
        {
                if (ob->query("gender") == "无性")
                        return HIR "【东厂万户】" NOR+ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return HIR "【 长  老 】" NOR+ob->query("rank_info/title2");
                case "武当派":
                        return HIR "【 天  师 】" NOR+ob->query("rank_info/title2");
                case "峨嵋派":
                        return HIR "【 德  尼 】" NOR+ob->query("rank_info/title2");
                case "逍遥派":
                        return HIR "【 逸  士 】" NOR +ob->query("rank_info/title2");
                case "灵鹫宫":
                        return HIR "【灵鹫右使】" NOR +ob->query("rank_info/title2");
                case "星宿派":
                        return HIR "【星宿毒师】" NOR +ob->query("rank_info/title2");
                case "古墓派":
                        return HIR "【 游  侠 】" NOR +ob->query("rank_info/title2");
                case "全真教":
                        return HIR "【 天  师 】" NOR +ob->query("rank_info/title2");
                case "昆仑派":
                        return HIR "【 棋  王 】" NOR +ob->query("rank_info/title2");
                case "桃花岛":
                        return HIR "【 药  王 】" NOR +ob->query("rank_info/title2");
                case "雪山寺":
                        return HIR "【 国  师 】" NOR +ob->query("rank_info/title2");
                case "丐帮":
                        return HIR "【 铁  丐 】" NOR +ob->query("rank_info/title2");
                case "天地会":
                        return HIR "【 豪  杰 】" NOR +ob->query("rank_info/title2");
                case "神龙教":
                        return HIR "【 白龙使 】" NOR +ob->query("rank_info/title2");
                case "五毒教":
                        return HIR "【 毒  仆 】" NOR +ob->query("rank_info/title2");
                case "明教":
                        return HIR "【 散  人 】" NOR +ob->query("rank_info/title2");
                case "梅庄":
                        return HIR "【 画  圣 】" NOR +ob->query("rank_info/title2");
                case "华山派":
                        return HIR "【 剑  侠 】" NOR +ob->query("rank_info/title2");
                case "日月神教":
                        return HIR "【 护  法 】" NOR +ob->query("rank_info/title2");
                case "慕容世家":
                        return HIR "【 家  臣 】" NOR +ob->query("rank_info/title2");
                default:
                        return HIR "【黑榜高手】" NOR +ob->query("rank_info/title2");
                }
        } else
        if (dj > 40)
        {
                if (ob->query("gender") == "无性")
                        return HIG "【东厂千户】" NOR +ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return HIG "【 罗  汉 】" NOR +ob->query("rank_info/title2");
                case "武当派":
                        return HIG "【 道  长 】" NOR +ob->query("rank_info/title2");
                case "峨嵋派":
                        return HIG "【 贤  尼 】" NOR +ob->query("rank_info/title2");
                case "逍遥派":
                        return HIG "【 隐  士 】" NOR +ob->query("rank_info/title2");
                case "灵鹫宫":
                        return HIG "【 洞  主 】" NOR +ob->query("rank_info/title2");
                case "星宿派":
                        return HIG "【星宿护卫】" NOR +ob->query("rank_info/title2");
                case "古墓派":
                        return HIG "【 少  侠 】" NOR +ob->query("rank_info/title2");
                case "全真教":
                        return HIG "【 道  长 】" NOR +ob->query("rank_info/title2");
                case "昆仑派":
                        return HIG "【 琴  痴 】" NOR +ob->query("rank_info/title2");
                case "桃花岛":
                        return HIG "【 卜算子 】" NOR +ob->query("rank_info/title2");
                case "雪山寺":
                        return HIG "【僧兵头领】" NOR +ob->query("rank_info/title2");
                case "丐帮":
                        return HIG "【 侠  丐 】" NOR +ob->query("rank_info/title2");
                case "天地会":
                        return HIG "【 大  侠 】" NOR +ob->query("rank_info/title2");
                case "神龙教":
                        return HIG "【 青龙使 】" NOR +ob->query("rank_info/title2");
                case "五毒教":
                        return HIG "【 教  徒 】" NOR +ob->query("rank_info/title2");
                case "明教":
                        return HIG "【 旗  主 】" NOR +ob->query("rank_info/title2");
                case "梅庄":
                        return HIG "【 总  管 】" NOR +ob->query("rank_info/title2");
                case "华山派":
                        return HIG "【 剑  客 】" NOR +ob->query("rank_info/title2");
                case "日月神教":
                        return HIG "【 护  教 】" NOR +ob->query("rank_info/title2");
                default:
                        return HIG "【武林高手】" NOR +ob->query("rank_info/title2");
                }
        } else
        if (dj > 20)
        {
                if (ob->query("gender") == "无性")
                        return HIC "【东厂百户】" NOR +ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return HIC "【 尊  者 】" NOR +ob->query("rank_info/title2");
                case "武当派":
                        return HIC "【 道  士 】" NOR +ob->query("rank_info/title2");
                case "峨嵋派":
                        return HIC "【 师  太 】" NOR +ob->query("rank_info/title2");
                case "逍遥派":
                        return HIC "【 方  士 】" NOR +ob->query("rank_info/title2");
                case "灵鹫宫":
                        return HIC "【 仕  女 】" NOR +ob->query("rank_info/title2");
                case "星宿派":
                        return HIC "【 小毒虫 】" NOR +ob->query("rank_info/title2");
                case "古墓派":
                        return HIC "【江湖豪杰】" NOR +ob->query("rank_info/title2");
                case "全真教":
                        return HIC "【 道  士 】" NOR +ob->query("rank_info/title2");
                case "昆仑派":
                        return HIC "【江湖豪杰】" NOR +ob->query("rank_info/title2");
                case "桃花岛":
                        return HIC "【 秀  才 】" NOR +ob->query("rank_info/title2");
                case "雪山寺":
                        return HIC "【 僧  兵 】" NOR +ob->query("rank_info/title2");
                case "丐帮":
                        return HIC "【 义  丐 】" NOR +ob->query("rank_info/title2");
                case "铁掌帮":
                        return HIC "【 教  头 】" NOR +ob->query("rank_info/title2");
                case "天地会":
                        return HIC "【 侠  客 】" NOR +ob->query("rank_info/title2");
                case "红花会":
                        return HIC "【 侠  客 】" NOR +ob->query("rank_info/title2");
                case "神龙教":
                        return HIC "【 赤龙使 】" NOR +ob->query("rank_info/title2");
                case "五毒教":
                        return HIC "【 教  众 】" NOR +ob->query("rank_info/title2");
                case "明教":
                        return HIC "【 门  主 】" NOR +ob->query("rank_info/title2");
                case "梅庄":
                        return HIC "【 护  院 】" NOR +ob->query("rank_info/title2");
                case "崆峒派":
                        return HIC "【 道  士 】" NOR +ob->query("rank_info/title2");
                case "华山派":
                        return HIC "【 剑  士 】" NOR +ob->query("rank_info/title2");
                case "日月神教":
                        return HIC "【 堂  主 】" NOR +ob->query("rank_info/title2");
                default:
                        return HIC "【武林异士】" NOR +ob->query("rank_info/title2");
                }
        } else
        if (dj > 10)
        {
                if (ob->query("gender") == "无性")
                        return YEL "【东厂十户】" NOR +ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return YEL "【 禅  师 】" NOR +ob->query("rank_info/title2");
                case "武当派":
                        return YEL "【 小道士 】" NOR +ob->query("rank_info/title2");
                case "峨嵋派":
                        return YEL "【 尼  姑 】" NOR +ob->query("rank_info/title2");
                case "逍遥派":
                        return YEL "【 郎  中 】" NOR +ob->query("rank_info/title2");
                case "灵鹫宫":
                        return YEL "【 侍  女 】" NOR +ob->query("rank_info/title2");
                case "星宿派":
                        return YEL "【 弟  子 】" NOR +ob->query("rank_info/title2");
                case "古墓派":
                        return YEL "【武林中人】" NOR +ob->query("rank_info/title2");
                case "全真教":
                        return YEL "【 小道士 】" NOR +ob->query("rank_info/title2");
                case "昆仑派":
                        return YEL "【武林中人】" NOR +ob->query("rank_info/title2");
                case "桃花岛":
                        return YEL "【 书  生 】" NOR +ob->query("rank_info/title2");
                case "雪山寺":
                        return YEL "【 喇  嘛 】" NOR +ob->query("rank_info/title2");
                case "丐帮":
                        return YEL "【 乞  丐 】" NOR +ob->query("rank_info/title2");
                case "天地会":
                        return YEL "【 侠  士 】" NOR +ob->query("rank_info/title2");
                case "神龙教":
                        return YEL "【 随龙使 】" NOR +ob->query("rank_info/title2");
                case "五毒教":
                        return YEL "【初入江湖】" NOR +ob->query("rank_info/title2");
                case "明教":
                        return YEL "【 教  徒 】" NOR +ob->query("rank_info/title2");
                case "梅庄":
                        return YEL "【 随  从 】" NOR +ob->query("rank_info/title2");
                case "华山派":
                        return YEL "【 剑  侍 】" NOR +ob->query("rank_info/title2");
                case "日月神教":
                        return YEL "【 教  徒 】" NOR +ob->query("rank_info/title2");
                default:
                        return YEL "【武林人士】" NOR +ob->query("rank_info/title2");
                }
        } else
        {
                if (ob->query("gender") == "无性")
                        return GRN "【 公  公 】" NOR +ob->query("rank_info/title2");

                switch (fam)
                {
                case "少林派":
                        return GRN "【 比  丘 】" NOR +ob->query("rank_info/title2");
                case "武当派":
                        return GRN "【 道  童 】" NOR +ob->query("rank_info/title2");
                case "峨嵋派":
                        return GRN "【 小尼姑 】" NOR +ob->query("rank_info/title2");
                case "逍遥派":
                        return GRN "【 学  童 】" NOR +ob->query("rank_info/title2");
                case "灵鹫宫":
                        return GRN "【 使  女 】" NOR +ob->query("rank_info/title2");
                case "星宿派":
                        return GRN "【 仆  人 】" NOR +ob->query("rank_info/title2");
                case "古墓派":
                        return GRN "【初入江湖】" NOR +ob->query("rank_info/title2");
                case "全真教":
                        return GRN "【 道  童 】" NOR +ob->query("rank_info/title2");
                case "昆仑派":
                        return GRN "【 弟  子 】" NOR +ob->query("rank_info/title2");
                case "桃花岛":
                        return GRN "【 学  童 】" NOR +ob->query("rank_info/title2");
                case "雪山寺":
                        return GRN "【 沙  弥 】" NOR +ob->query("rank_info/title2");
                case "丐帮":
                        return GRN "【 小叫花 】" NOR +ob->query("rank_info/title2");
                case "天地会":
                        return GRN "【 义  士 】" NOR +ob->query("rank_info/title2");
                case "神龙教":
                        return GRN "【 弟  子 】" NOR +ob->query("rank_info/title2");
                case "五毒教":
                        return GRN "【 仆  人 】" NOR +ob->query("rank_info/title2");
                case "明教":
                        return GRN "【 教  众 】" NOR +ob->query("rank_info/title2");
                case "梅庄":
                        return GRN "【 仆  人 】" NOR +ob->query("rank_info/title2");
                case "华山派":
                        return GRN "【 剑  童 】" NOR +ob->query("rank_info/title2");
                case "日月神教":
                        return GRN "【 教  众 】" NOR +ob->query("rank_info/title2");
                default:
                        return GRN "【初入武林】" NOR +ob->query("rank_info/title2");
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师太";
                                else return "师太";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 50 ) return "姑娘";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师父";
                                else return "大师";
                                break;
                        case "taoist":
                                if( age < 18 ) return "道兄";
                                else return "道长";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壮士";
                                else return "老前辈";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壮士";
                                else return "老爷子";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "贼尼";
                                break;
                        case "taoist":
                                return "妖女";
                                break;
                        default:
                                if( age < 30 ) return "小贱人";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                return "死牛鼻子";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 50 ) return "臭贼";
                                else return "老匹夫";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "小女子";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫僧";
                                else return "老纳";
                                break;
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 50 ) return "在下";
                                else return "老头子";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "本姑娘";
                                else return "老娘";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "大和尚我";
                                else return "老和尚我";
                                break;
                        case "taoist":
                                return "本山人";
                                break;
                        default:
                                if( age < 50 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}

string query_close(object ob, int age, string rgender)
{
        int a1, a2;
        string gender;
        if (objectp(ob) )       {
                if( !age )
                        a1 = this_player()->query("age");
                else
                        a1 = ob->query("age");
                if( !age)
                        a2 = ob->query("age");
                else    a2 = age;
        }
        
        if( !rgender )
                gender = ob->query("gender");                                           
        else    gender = rgender;

        switch ( gender ) {
        case "女性" :
                if (a1 > a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 > a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

varargs string new_short( object ob ,int withshort)
{
    mixed tmp;
    string icon="", str;
    if(!objectp(ob))
    {
          CHANNEL_D->do_channel(this_player(),"chat","object参数错误！");
          return "";
    }
    if(!ob->query_temp("apply/id")||!ob->query_temp("apply/name")||!ob->query_temp("apply/short"))
          str = ob->query("name") + "(" +ob->query("id") + ")" +(!withshort?"":ob->short());
    else
          str = ob->query_temp("apply/name")[0] + "(" +ob->query_temp("apply/id")[0] + ")" +(!withshort?"":ob->query_temp("apply/short")[0]);
    if( (tmp = ob->query("icon")))
    {
          if( intp(tmp) )
                icon = sprintf("%d",tmp);
          else if( stringp(tmp) )
                icon = tmp;
          else 
                icon = "00901";
    }
    else
    {
          if(userp(ob)) icon=( ob->query("gender") == "男性" )?"1174":"1173";
          else if(living(ob)) icon = "00901";
          else icon = "00961";
    }
    while( sizeof(icon)<5 )
          icon = "0" + icon;

    return str + icon;
}


string query_self_close(object ob, int age)
{
        int a1, a2;
        string gender;
        if( objectp(ob) ) {
                if( !age )
                        a1 = this_player()->query("age");
                else
                        a1 = ob->query("age");
                if( !age)
                        a2 = ob->query("age");
                else    a2 = age;
        }

        if( age )
                gender = ob->query("gender");
        else
                gender = this_player()->query("gender");

        switch (gender) {

        case "女性" :
                if (a1 > a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 > a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}

