// jingzuo.c
// Dec.11 1997 by Venus
#include <ansi.h>
void wakeup(object me, object where);
void del_jingzuoed(object me);
#include "/quest/givegift.c"
int main(object me, string arg)
{
        mapping fam;
        object where = environment(me);
       int lv = (int) me->query_skill("mahayana",1);
        seteuid(getuid());

        if ((!(fam = me->query("family")) || fam["family_name"] != "峨嵋派") && !wizardp(me))
             return notify_fail("只有峨嵋派才能静坐！\n");
//        if (where->query("no_sleep_room"))
//             return notify_fail("这里太纷杂，你没法静心静坐。\n");
	if( me->query_temp("dushi") )
		return notify_fail("你已经在劝人家罢斗了！\n");

       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

        if (where->query("sleep_room"))
             return notify_fail("这里太纷杂，你没法静心静坐。\n");
        if (me->query("eff_jing")<50)
             return notify_fail("你受伤太重，没法静坐。\n");
        if (me->is_busy())
             return notify_fail("你正忙着呢！\n");
        if (me->is_fighting())
             return notify_fail("战斗中想静坐？你不要命啦！\n");
	me->save();
        if ((me->query("mud_age") - me->query_temp("jingzuo_time") < 80) && !wizardp(me))
             return notify_fail("你刚才静坐过，现在头脑一片空白。\n");
        if (me->query_skill("linji-zhuang",1) < 40)
             return notify_fail("你的临济十二庄还太浅薄了，没法静心静坐。\n");
        if (me->query_skill("mahayana",1) < 40)
//       if (me->query("potential")-me->query("learned_points")>50000)
//             return notify_fail("你的潜能太多了，没法静心静坐。\n");

//        if (where->query("sleep_room"))
//        {
             write(HIC"你往地上盘膝一坐，开始静坐。\n"NOR);
             write(HIC"你往地上盘膝一坐，开始静坐。\n"NOR);
        write("你盘膝坐定，静心片刻便摒绝了一切俗虑杂念。\n");

             write(HIG"不一会儿，你神游天外，物我两忘。\n"NOR);
        switch(random(4)) {
        case 0:
               write(HIW"
尔时，须菩提闻说是经，深解义趣，涕泪悲泣，而白佛言：“希有，世
尊！佛说如是甚深经典，我从昔来所得慧眼，未曾得闻如是之经。世尊！
若复有人得闻是经，信心清净，则生实相，当知是人，成就第一希有功
德。世尊！是实相者，则是非相，是故如来说名实相。世尊！我今得闻
如是经典，信解受持不足为难，若当来世，后五百岁，其有众生，得闻
是经，信解受持，是人则为第一希有。何以故？此人无我相、人相、众
生相、寿者相。所以者何？我相即是非相，人相、众生相、寿者相
即是非相。何以故？离一切诸相，则名诸佛。”           
 \n"NOR);
               break;
        case 1:
               write(GRN"
“须菩提！菩萨亦如是。若作是言：‘我当灭度无量众生’，则不名菩
萨。何以故？须菩提！无有法名为菩萨。是故佛说：一切法无我、无人、
无众生、无寿者。须菩提！若菩萨作是言：‘我当庄严佛土’，是不名
菩萨。何以故？如来说：庄严佛土者，即非庄严，是名庄严。须菩提！
若菩萨通达无我法者，如来说名真是菩萨。
\n"NOR);
               break;
        case 2:
               write(CYN"
云何无明？善男子，一切众生从无始来，种种颠倒，犹如迷人，四方易
处。妄认四大为自身相，六尘缘引为自心相。譬彼病目见空中华及第二
月善男子，空实无华，病者妄执。由妄执故，非唯惑此虚空自性，亦复
迷彼实华生处。由此妄有轮转生死。故名无明。此无明者，非有实体。
如梦中人，梦时非无，及至於醒，了无所得。如众空华灭於虚空，不可
言说有定灭处。何以故，无生处故，一切众生於无生中，妄见生灭，是
故说名轮转生死。
\n"NOR);
               break;
        case 3:
               write(HIY"
须菩提！又念过去于五百世作忍辱仙人，于尔所世，无我相、无人相、
无众生相、无寿者相。是故须菩提！菩萨应离一切相，发阿耨多罗三藐
三菩提心，不应住色生心，不应住声香味触法生心，应生无所住心。若
心有住，则为非住。是故佛说：菩萨心不应住色布施。须菩提！菩萨为
利益一切众生，应如是布施。如来说：一切诸相，即是非相。又说：一
切众生，则非众生。须菩提！如来是真语者、实语者、如语者、不诳语
者、不异语者。须菩提！如来所得法，此法无实无虚。须菩提！若菩萨
心住于法而行布施，如人入暗，则无所见；若菩萨心不住于法而行布施，
如人有目，日光明照，见种种色。须菩提！当来之世，若有善男子、善
女人，能于此经受持读诵，则为如来以佛智慧，悉知是人，悉见是人，
皆得成就无量无边功德。
\n"NOR);
                break;
        }

             me->set_temp("block_msg/all",1);
             message_vision(HIC"$N一躬身，坐在床上，闭目端念，静心打坐。\n"NOR,me);
             where->add_temp("jingzuo_person", 1);

             me->set("no_get", 1);
             me->set("no_get_from", 1);
             me->disable_player("<静坐中>");
lv=lv/5;
if (lv<28) lv=28;
             call_out("wakeup",random(lv)+1 , me, where);

             return 1;
//        } else return notify_fail("这里太纷杂，你没法静心静坐。\n");
}

void wakeup(object me,object where)
{
       int skillslvl,addp,addc,exppot,intpot;
if (!me) return;
       skillslvl = (int) me->query_skill("mahayana",1);

//       exppot = (int)(me->query("combat_exp")/20000);
//       intpot = (int)(me->query_int()/10);
       addp = (int)(random(skillslvl)+1);
       addc = (int)(random(skillslvl)+8);
       me->add("jing",-15);
       me->add("eff_jing",-3);
if (addp > 80) addp=80;
if (addc > 100) addc=100;
addp=addp/2+5;
addc=addc/2+8;

       me->start_busy(3);
       me->enable_player();

       message_vision(HIG"$N静坐完毕，缓缓睁眼，长长吐了一口气。\n"NOR,me);
       me->set_temp("block_msg/all", 0);
       me->set_temp("jingzuo_time", me->query("mud_age"));
                write(HIW"
不知过了多久，你由于佛法的奇妙，早已全神贯注去体会那种感觉，而
浑然忘却了时间。。。过了一会，你从那佛法中醒来，轻轻地呼出一口    
起气，顿时有一种佛法无边的感觉。
\n"NOR);

       write(HIB"你静坐完毕，好累的感觉。\n"NOR);
addnl(me,"exp",addc);

       where->add_temp("jingzuo_person", -1);
       me->delete("no_get");
       me->delete("no_get_from");
       return;
}

int help(object me)
{
        write(@HELP
指令格式 : jingzuo <精点数>

这个指令是峨嵋派弟子用以静坐修道的命令.

HELP
        );
        return 1;
}
