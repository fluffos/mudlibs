// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int shen;
        int budd;
        int age;
        int exp;
        if( ob->is_ghost() )
                return HIB "【 地狱无常 】" NOR;
        exp=ob->query("combat_exp");
        shen = ob->query("shen");
        age = ob->query("age");
        if (!(fam = ob->query("family"))) if (age <= 16)
                                            return HIC"【 未成年儿童 】"NOR;
                                        else if (age<=30)
                                            return HIC"【   青年人   】"NOR;
                                        else if (age<=60)
                                             return HIC"【   中年人   】"NOR;
                                        else return HIC"【   老年人   】"NOR; 
         switch(ob->query("gender")) {
        case "女性":
                switch(wizhood(ob)) {
                case "(adroot)":
                        return HIW "【   第一大当家   】" NOR;
                case "(admin)":
                        return HIM "【   大夫人   】" NOR;
                case "(hufa)":
                        return HIB "【   二夫人   】" NOR;
                case "(arch)":
                        return HIY "【   三夫人   】" NOR;
                case "(wizard)":
                        return HIG "【   四夫人   】" NOR;
                case "(apprentice)":
                        return HIC "【   五夫人    】" NOR;
                case "(immortal)":
                        return HIC "【   女管家   】" NOR;
                default:
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return "【    PK女魔   】";
                        if (fam["family_name"] == "峨嵋派")
                     {
                           if (exp<10000) return HIW"【   小尼姑   】"NOR;
                           else if (exp<50000) return HIC"【   瘦尼姑   】"NOR;
                           else if (exp<100000) return HIM"【   胖尼姑   】"NOR;
                           else if (exp<200000) return HIB"【    尼姑    】"NOR;
                           else if (exp<400000) return HIY"【   大尼姑   】"NOR;
                           else if (exp<600000) return HIG"【   老尼姑   】"NOR;
                           else if (exp<800000) return HIR"【 尼姑庵主持 】"NOR;
                           else if (exp<1000000) return WHT"【  方外神尼  】"NOR;
                           else return CYN"【   尼姑精   】";
                      }
                       if (fam["family_name"] == "华山派")
                     {
                           if (exp<10000) return HIW"【   女剑手   】"NOR;
                           else if (exp<50000) return HIC"【   女剑士   】"NOR;
                           else if (exp<100000) return HIM"【   女剑客   】"NOR;
                           else if (exp<200000) return HIB"【   女剑侠   】"NOR;
                           else if (exp<400000) return HIY"【   女剑魔   】"NOR;
                           else if (exp<600000) return HIG"【   女剑王   】"NOR;
                           else if (exp<800000) return HIR"【   女剑圣   】"NOR;
                           else if (exp<1000000) return WHT"【   女剑尊   】"NOR;
                           else return CYN"【   女剑神   】";
                      }
                      if (fam["family_name"] == "逍遥派")
                     {
                           if (exp<10000) return HIW"【   女郎中   】"NOR;
                           else if (exp<50000) return HIC"【   女大夫   】"NOR;
                           else if (exp<100000) return HIM"【   女医生   】"NOR;
                           else if (exp<200000) return HIB"【   女巫医   】"NOR;
                           else if (exp<400000) return HIY"【   女医师   】"NOR;
                           else if (exp<600000) return HIG"【   女医圣   】"NOR;
                           else if (exp<800000) return HIR"【   女医仙   】"NOR;
                           else if (exp<1000000) return WHT"【   女医神   】"NOR;
                           else return CYN"【  世外神医  】";
                      }
                    if (fam["family_name"] == "武当派" ||fam["family_name"] == "全真教")
                     {
                           if (exp<10000) return HIW"【   小道童   】"NOR;
                           else if (exp<50000) return HIC"【   小道姑   】"NOR;
                           else if (exp<100000) return HIM"【    道姑    】"NOR;
                           else if (exp<200000) return HIB"【   大道姑   】"NOR;
                           else if (exp<400000) return HIY"【   女道长   】"NOR;
                           else if (exp<600000) return HIG"【   女真人   】"NOR;
                           else if (exp<800000) return HIR"【   女天师   】"NOR;
                           else if (exp<1000000) return WHT"【  护法天师  】"NOR;
                           else return CYN"【   女半仙   】";
                      }
                    if (fam["family_name"] == "古墓派")
                     {
                           if (exp<10000) return HIW"【   未出师   】"NOR;
                           else if (exp<50000) return HIC"【   小侠女   】"NOR;
                           else if (exp<100000) return HIM"【    侠女    】"NOR;
                           else if (exp<200000) return HIB"【   大侠女   】"NOR;
                           else if (exp<400000) return HIY"【  盖世女侠  】"NOR;
                           else if (exp<600000) return HIG"【  旷世女侠  】"NOR;
                           else if (exp<800000) return HIR"【  绝世女侠  】"NOR;
                           else if (exp<1000000) return WHT"【   女神侠   】"NOR;
                           else return CYN"【  宇内高手  】";
                      }
                     if (fam["family_name"] == "丐帮")
                     {
                           if (exp<10000) return HIW"【   小要饭   】"NOR;
                           else if (exp<50000) return HIC"【   小乞丐   】"NOR;
                           else if (exp<100000) return HIM"【   女乞丐   】"NOR;
                           else if (exp<200000) return HIB"【  女乞丐头  】"NOR;
                           else if (exp<400000) return HIY"【 丐帮女舵主 】"NOR;
                           else if (exp<600000) return HIG"【  丐帮堂主  】"NOR;
                           else if (exp<800000) return HIR"【  丐帮护法  】"NOR;
                           else if (exp<1000000) return WHT"【 丐帮副帮主 】"NOR;
                           else return CYN"【    神丐    】";
                      }
                     if (fam["family_name"] == "灵鹫宫")
                     {
                           if (exp<10000) return HIW"【  灵鹫弟子  】"NOR;
                           else if (exp<50000) return HIC"【  灵鹫师姐  】"NOR;
                           else if (exp<100000) return HIM"【 灵鹫大师姐 】"NOR;
                           else if (exp<200000) return HIB"【  灵鹫使者  】"NOR;
                           else if (exp<400000) return HIY"【 灵鹫左护法 】"NOR;
                           else if (exp<600000) return HIG"【 灵鹫右护法 】"NOR;
                           else if (exp<800000) return HIR"【  灵鹫管事  】"NOR;
                           else if (exp<1000000) return WHT"【 灵鹫二宫主 】"NOR;
                           else return CYN"【  灵鹫宫主  】";
                      }
                      if (fam["family_name"] == "星宿派" ||fam["family_name"] == "白驼山派")
                     {
                           if (exp<10000) return HIW"【   小妖女   】"NOR;
                           else if (exp<50000) return HIC"【   小魔女   】"NOR;
                           else if (exp<100000) return HIM"【    魔女    】"NOR;
                           else if (exp<200000) return HIB"【   女魔头   】"NOR;
                           else if (exp<400000) return HIY"【  盖世女魔  】"NOR;
                           else if (exp<600000) return HIG"【  旷世女魔  】"NOR;
                           else if (exp<800000) return HIR"【  绝世女魔  】"NOR;
                           else if (exp<1000000) return WHT"【   女狂魔   】"NOR;
                           else return CYN"【 超级女魔头 】";
                      } 
                                
}
           default:
                switch(wizhood(ob)) {
                case "(adroot)":
                        return HIW "【 第一大当家  】" NOR;
                case "(admin)":
                        return HIM "【   大当家   】" NOR;
                case "(hufa)":
                        return HIB "【   二当家   】" NOR;
                case "(arch)":
                        return HIY "【   三当家   】" NOR;
                case "(wizard)":
                        return HIG "【   四当家   】" NOR;
                case "(apprentice)":
                        return HIC "【   五当家   】" NOR;
                case "(immortal)":
                        return HIC "【   男管家   】" NOR;
                default:
                      if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return "【   PK狂魔   】";
                          else
                                 if (fam["family_name"] == "少林派")
                     {
                           if (exp<10000) return HIW"【   小沙弥   】"NOR;
                           else if (exp<50000) return HIC"【   小和尚   】"NOR;
                           else if (exp<100000) return HIM"【    和尚    】"NOR;
                           else if (exp<200000) return HIB"【   大和尚   】"NOR;
                           else if (exp<400000) return HIY"【    禅师    】"NOR;
                           else if (exp<600000) return HIG"【    罗汉    】"NOR;
                           else if (exp<800000) return HIR"【    方丈    】"NOR;
                           else if (exp<1000000) return WHT"【    圣僧    】"NOR;
                           else return CYN"【    神僧    】";
                      }
                       if (fam["family_name"] == "华山派")
                     {
                           if (exp<10000) return HIW"【    剑手    】"NOR;
                           else if (exp<50000) return HIC"【    剑士    】"NOR;
                           else if (exp<100000) return HIM"【    剑客    】"NOR;
                           else if (exp<200000) return HIB"【    剑侠    】"NOR;
                           else if (exp<400000) return HIY"【    剑魔    】"NOR;
                           else if (exp<600000) return HIG"【    剑仙    】"NOR;
                           else if (exp<800000) return HIR"【    剑圣    】"NOR;
                           else if (exp<1000000) return WHT"【    剑尊    】"NOR;
                           else return CYN"【    剑神    】";
                      }
                      if (fam["family_name"] == "逍遥派")
                     {
                           if (exp<10000) return HIW"【    郎中    】"NOR;
                           else if (exp<50000) return HIC"【    大夫    】"NOR;
                           else if (exp<100000) return HIM"【    医生    】"NOR;
                           else if (exp<200000) return HIB"【    巫医    】"NOR;
                           else if (exp<400000) return HIY"【    医师    】"NOR;
                           else if (exp<600000) return HIG"【    医圣    】"NOR;
                           else if (exp<800000) return HIR"【    医仙    】"NOR;
                           else if (exp<1000000) return WHT"【    医神    】"NOR;
                           else return CYN"【  世外神医  】";
                      }
                      if (fam["family_name"] == "武当派")
                     {
                           if (exp<10000) return HIW"【   小道童   】"NOR;
                           else if (exp<50000) return HIC"【   小道士   】"NOR;
                           else if (exp<100000) return HIM"【    道士    】"NOR;
                           else if (exp<200000) return HIB"【    道长    】"NOR;
                           else if (exp<400000) return HIY"【   大道长   】"NOR;
                           else if (exp<600000) return HIG"【    真人    】"NOR;
                           else if (exp<800000) return HIR"【    天师    】"NOR;
                           else if (exp<1000000) return WHT"【  护法天师  】"NOR;
                           else return CYN"【    半仙    】";
                      }
                      if (fam["family_name"] == "古墓派")
                     {
                           if (exp<10000) return HIW"【   未出师   】"NOR;
                           else if (exp<50000) return HIC"【   小侠客   】"NOR;
                           else if (exp<100000) return HIM"【    侠客    】"NOR;
                           else if (exp<200000) return HIB"【   大侠客   】"NOR;
                           else if (exp<400000) return HIY"【  盖世大侠  】"NOR;
                           else if (exp<600000) return HIG"【  旷世大侠  】"NOR;
                           else if (exp<800000) return HIR"【  绝世大侠  】"NOR;
                           else if (exp<1000000) return WHT"【   神侠   】"NOR;
                           else return CYN"【  宇内高手  】";
                      }
                      if (fam["family_name"] == "丐帮")
                     {
                           if (exp<10000) return HIW"【   小要饭   】"NOR;
                           else if (exp<50000) return HIC"【   小乞丐   】"NOR;
                           else if (exp<100000) return HIM"【    乞丐    】"NOR;
                           else if (exp<200000) return HIB"【   乞丐头   】"NOR;
                           else if (exp<400000) return HIY"【  丐帮舵主  】"NOR;
                           else if (exp<600000) return HIG"【  丐帮堂主  】"NOR;
                           else if (exp<800000) return HIR"【  丐帮护法  】"NOR;
                           else if (exp<1000000) return WHT"【 丐帮副帮主 】"NOR;
                           else return CYN"【    神丐    】";
                      }
            
                      if (fam["family_name"] == "星宿派" ||fam["family_name"] == "白驼山派")
                     {
                           if (exp<10000) return HIW"【    小妖    】"NOR;
                           else if (exp<50000) return HIC"【   小魔头   】"NOR;
                           else if (exp<100000) return HIM"【    魔头    】"NOR;
                           else if (exp<200000) return HIB"【   大魔头   】"NOR;
                           else if (exp<400000) return HIY"【  盖世魔头  】"NOR;
                           else if (exp<600000) return HIG"【  旷世魔头  】"NOR;
                           else if (exp<800000) return HIR"【  绝世魔头  】"NOR;
                           else if (exp<1000000) return WHT"【  变态狂魔  】"NOR;
                           else return CYN"【  超级魔头  】";
                      }            
                      if (fam["family_name"] == "全真教")
                     {
                           if (exp<10000) return HIW"【   散人   】"NOR;
                           else if (exp<50000) return HIC"【    真人    】"NOR;
                           else if (exp<100000) return HIM"【  三清真人  】"NOR;
                           else if (exp<200000) return HIB"【    法师    】"NOR;
                           else if (exp<400000) return HIY"【   大法师   】"NOR;
                           else if (exp<600000) return HIG"【    天师    】"NOR;
                           else if (exp<800000) return HIR"【  护法天师  】"NOR;
                           else if (exp<1000000) return WHT"【    半仙    】"NOR;
                           else return CYN"【    地仙    】";
                      }
                      if (fam["family_name"] == "大理段家")
                     {
                           if (exp<10000) return HIW"【  王府火工  】"NOR;
                           else if (exp<50000) return HIC"【  火工总管  】"NOR;
                           else if (exp<100000) return HIM"【 王府卫士 】"NOR;
                           else if (exp<200000) return HIB"【 铁血卫士 】"NOR;
                           else if (exp<400000) return HIY"【 金刚战士 】"NOR;
                           else if (exp<600000) return HIG"【 王府亲卫 】"NOR;
                           else if (exp<800000) return HIR"【  王府卫队长  】"NOR;
                           else if (exp<1000000) return WHT"【 王府总管 】"NOR;
                           else return CYN"【  王府大总管  】";
                     }
                              switch(ob->query("class")) {
                                case "eunach":
                                        budd = ob->query_skill("pixie-jian",1);
                                        if (budd >= 110)
                                                return HIY "【   千岁爷   】" NOR;
                                        else if (budd >= 100)
                                                return HIY "【  东厂总管  】" NOR;
                                        else if (budd >= 90)
                                                return HIY "【 东厂侍卫长 】" NOR;
                                        else if (budd >= 80)
                                                return HIY "【  东厂侍卫  】" NOR;
                                        else if (budd >= 70)
                                                return HIY "【  东厂卫士  】" NOR;
                                        else if (budd >= 60)
                                                return HIY "【  东厂太监  】" NOR;
                                        else return "【   小太监   】";
                                case "prostitute":
                                        return "【   龟公   】";
                                default:
                                        if (age <= 16)
                                            return HIC"【 未成年儿童 】"NOR;
                                        else if (age<=30)
                                            return HIC"【   青年人   】"NOR;
                                        else if (age<=60)
                                             return HIC"【   中年人   】"NOR;
                                        else return HIC"【   老年人   】"NOR;                               
}
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
                                else if( age < 30 ) return "姑娘";
                                else if( age < 40 ) return "大婶";
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
                        case "scholar":
                                if( age < 18 ) return "小相公";
                                else if( age < 50 ) return "相公";
                                else return "老先生";
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
                                if( age < 18 ) return "小贼尼";
                                if( age < 30 ) return "贼尼";
                                else return "老贼尼";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小妖女";
                                if( age < 30 ) return "妖女";
                                else return "老妖婆";
                                break;
                        default:
                                if( age < 18 ) return "小娘皮";
                                if( age < 25 ) return "小贱人";
                                if( age < 40 ) return "贼婆娘";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小贼秃";
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小杂毛";
                                if( age < 30 ) return "死牛鼻子";
                                else return "老杂毛";
                                break;
                        case "scholar":
                                if( age < 18 ) return "小书呆子";
                                else if( age < 50 ) return "臭书呆子";
                                else return "老童生";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 30 ) return "直娘贼";
                                if( age < 50 ) return "臭贼";
                                if( age < 80 ) return "老匹夫";
                                else return "老不死";
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
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 20 ) return "小女子";
                                if( age > 50 ) return "老身";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小衲";
                                if( age < 40 ) return "贫僧";
                                else return "老衲";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小道";
                                if( age < 30 ) return "贫道";
                                else return "老道";
                                break;
                        case "scholar":
                                if( age < 30 ) return "晚生";
                                else return "不才";
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
                        case "taoist":
                                return "本仙姑";
                                break;
                        default:
                                if( age < 20 ) return "本姑娘";
                                if( age < 30 ) return "本姑奶奶";
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
                                if( age < 30 ) return "本山人";
                                return "老道我";
                                break;
                        case "scholar":
                                if( age < 50 ) return "本相公";
                                else return "老夫子我";
                                break;
                        default:
                                if( age < 20 ) return "本少爷我";
                                if( age < 40 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}

