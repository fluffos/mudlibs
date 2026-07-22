// Room: /d/emei/chanfang3.c

inherit ROOM;
int jingzuoing(object me);
int halt_jingzuo(object me);
#include <ansi.h>
#include <skill.h>
#include <room.h>
void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是一间安静宽敞的禅房，乃是庵中弟子打坐修行之所。地下整整
齐齐地放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG
	);
	set("exits", ([ 
	  "west" : __DIR__"wanniananzd",
]));
	set("no_clean_up", 0);
create_door("west", "小门", "east", DOOR_CLOSED);
	setup();

}


void init()
{
	add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo()
{
        int lvl, cycle;
        object where, me;
	me = this_player();
	where = environment(me);
        seteuid(getuid());

        if( me->query_temp("pending/jingzuo") )
                return notify_fail("你已经在静坐了。\n");

     	   if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

      if( me->query("family/family_name") != "峨嵋派" )
              return notify_fail("不是峨嵋派弟子在这里瞎捣什么乱？\n");


        lvl = (int)me->query_skill("dacheng-fofa", 1);
        if( lvl < 30 )
                return notify_fail("你大乘佛法未到火候，不能静坐修练。\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 50 )
                return notify_fail("你现在精不够，无法控制心魔禅定。\n");

        if( present("muyu chui", me) )
                message_vision("\n只听咚，咚，咚，$N用木鱼棰敲了几下。\n", me);
        write("你盘膝坐定，静心片刻便摒绝了一切俗虑杂念。\n");

        tell_room(environment(me),
                me->name() + "盘膝坐下，闭上眼睛开始静坐。\n", me);

        cycle = 2000 / (30 + lvl);
        cycle *= 2;

        me->set_temp("pending/jingzuo", 1);
        me->set_temp("jingzuo/period", 1);
        me->set_temp("jingzuo/cycle", cycle);

        me->start_busy((: jingzuoing :), (: halt_jingzuo :));
        return 1;
}

int jingzuoing(object me)
{
        int period = (int)me->query_temp("jingzuo/period");
        int cycle = (int)me->query_temp("jingzuo/cycle");
        int bonus = 0;

        if( (int)me->query_skill("dacheng-fofa", 1) > 99 && present("muyu chui", me) ) {
                bonus = 2;
                cycle = cycle * 4 / 5;
        }

        if( me->query("food") + me->query("water") < 20 )
                cycle *= 2;
  
    
        if( present("muyu chui", me) && period % 4 == 1 )
                message_vision("\n只听咚，咚，咚，$N用木鱼棰敲了几下。\n", me);

        if( period == 1 )
        if( random(8) > (1 + bonus) ) {
                write("你觉得周围太过噪杂，难以入静。\n");
                period = 0;
        }

        if( period % 4 == 2 )
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

        if (random(12) == 5) {
                me->update_condition();
                if ( (int)me->query("water") > 0 ) me->add("water", -1);
                if ( (int)me->query("food") > 0 ) me->add("food", -1);
        }

        me->improve_skill("dacheng-fofa", 1 + random(3));

        if( period >= cycle ) {
                period = 0;
                write(HIW"
不知过了多久，你由于佛法的奇妙，早已全神贯注去体会那种感觉，而
浑然忘却了时间。。。过了一会，你从那佛法中醒来，轻轻地呼出一口    
起气，顿时有一种佛法无边的感觉。
\n"NOR);

                me->receive_curing("jing", me->query_con());
                me->receive_heal("jing", me->query_con());
                me->improve_skill("dacheng-fofa", me->query("int") + random(3 * me->query("int")));
		me->add("potential", (int)me->query_skill("dacheng-fofa", 1) / 10);
		me->add("combat_exp", (int)me->query_skill("dacheng-fofa", 1) / 15);

                if( me->query_temp("apply/jingzuo") < me->query("int") * me->query("int") / 6 ) { 
                        me->add_temp("apply/jingzuo", 1);
                }

                
        }
                       
        period++;
        me->set_temp("jingzuo/period", period);
        return 1;
}

int halt_jingzuo(object me)
{
        me->delete_temp("pending/jingzuo");
        me->start_busy(1 + random(3));
        me->apply_condition("over_jingzuo", 5 + random(5));
        
        return 1;
}

int update_condition(object me, int duration)
{
        if (duration < 1) {
                return 0;
        }
        me->apply_condition("over_jingzuo", duration - 1);
        return 1;
}
