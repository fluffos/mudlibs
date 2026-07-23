//Cracked by Kafei
// liu 07/01
// Modified by xuanyuan 10/19/2001

#include <ansi.h>

void setup_ob(object me,object victiom);
string *herbs = ({
                                         BEAST_D("yufeng"),
});

string *beasts = ({
                                         BEAST_D("laohu"),
                                         BEAST_D("dufeng"),
                                         BEAST_D("lion"),
                                         BEAST_D("tuying"),
                                         BEAST_D("dog"),
                                         BEAST_D("mulang"),
                                         BEAST_D("bmonkey"),
                                         BEAST_D("xbaozi"),
});


void init()
{
                  object ob = this_player();
                  add_action("do_search", "find");
                  add_action("do_search", "zhao");
                  add_action("do_catch", "zhua");
                  add_action("do_catch", "paw");
                  if( interactive(ob))
                  {
                         this_player()->delete_temp("herb");
                         if( ob->query_temp("gm/feng") )
                                 set("count",random(4));
                  }
}

int do_search(string arg)
{
                  object me,ob;
                  int power;
                  me = this_player();

		  if( !arg || !(arg == "yufeng" || arg == "yu feng" || arg == "feng" || arg == "bee") )
			return notify_fail("你要寻找什么？\n");

                  if( me->is_fighting() || me->is_busy() )
                                         return notify_fail("你正忙着。\n");

                  if( me->query_temp("herb/got",1) )
                                         return notify_fail("这里已经找过了，再找也找不出什么了！\n");

                  if( !present("fengjiang ping", me) )
                                         return notify_fail("你没有工具，无法吸引玉蜂！\n");

                   if( present("yufeng", me) )
                   return notify_fail("你身上不是已经有了玉蜂了吗？怎么还想要呀。\n");
                  if( (int)me->query("jingli") < 30 )
                                         return notify_fail("你太累了，先歇息一会儿吧。\n");

                  me->add_temp("herb/times", 1);
                  me->add("jingli", -10);
                  me->start_busy(1+random(1));

                  if( query("count") < 1 && (int)me->query_temp("herb/times") > 5 ){
                                         return notify_fail("你把四周的树枝找翻遍了，可是没发现什么，看来这里没指望了！\n");
                if(random(9)==1){me->move("d/zhongnan/milin1");}
                if(random(9)==2){me->move("d/zhongnan/milin2");}
                if(random(9)==3){me->move("d/zhongnan/milin3");}
                if(random(9)==4){me->move("d/zhongnan/milin4");}
                if(random(9)==5){me->move("d/zhongnan/milin5");}
                if(random(9)==6){me->move("d/zhongnan/milin6");}
                if(random(9)==7){me->move("d/zhongnan/milin7");}
                if(random(9)==8){me->move("d/zhongnan/milin8");}
                if(random(9)==9){me->move("d/zhongnan/milin9");}
                if(random(9)==0){me->move("d/zhongnan/gumu");}
                
                }
                  message_vision("$N爬上树梢，仔细地看有没有玉蜂或是蜂巢！\n", me);

                  power = (int)me->query_temp("herb/times") * ( me->query("kar")+me->query("int") + me->query("str") )/3;
                  power *= query("count");

                  if( power/2 + random(power/2) > 250 ) {
                                         me->set_temp("herb/found", 1);
                                         message_vision(WHT"\n$N仔细的环视四周，拨开挡着视线的树枝，忽然发现树梢之上有一只玉蜂！\n"NOR, me);
                                        return 1;
                  }

                  if(random(8)==1)
                  {
                                ob=new(beasts[random(sizeof(beasts))]);
                                ob->move(environment(me));
                                message_vision(HIR"突然从草丛中惊起一只$N，它大概受了惊吓，发疯似地向$n发起进攻！\n"NOR, ob,me);

                                if(ob->query("id")=="xiao baozi")setup_ob(ob,me);
                                ob->kill_ob(me);
                                ob->start_busy(1+random(3));
                                return 1;
                  }

                  if(random(101)==50)
                  {
                         message_vision(HIR"\n$N一不小心没抓住树差，从树上掉了下来，一屁股坐在地上，蜂浆瓶也摔坏了！\n"NOR, me);
                         ob = present("fengjiang ping", me);
                         if(ob)destruct(ob);
                  }
                  return 1;
}

void setup_ob(object me,object victim)
{
        object *inv;
        mapping skill_status;
        string *sname;
        int i, max = 0, max1, j;

        if ( !me->query_temp("copied") ) {
                if ( mapp(skill_status = victim->query_skills()) ) {
                skill_status = victim->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
                }


                max1 = (int)max + random(max);

                //max = (int)max*3/4 + 1 + random((int)max/4);

//              if( me->query("combat_exp",1) < 10000 ) max1 /2;
                me->set_skill("dodge", max1);
                me->set_skill("parry", max1);
                me->set_skill("force", max1);

                me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)/10));
                me->set("max_qi", victim->query("max_qi"));
                me->set("eff_qi", victim->query("max_qi"));
                me->set("max_jing", victim->query("max_jing"));
                me->set("eff_jing", victim->query("max_jing"));
                me->set("qi", me->query("max_qi"));
                me->set("jing", me->query("max_jing"));
                me->set("jiali", victim->query("jiali")*3/4);
                if ( victim->query("max_jingli") > 0 ) {
                        me->set("max_jingli", victim->query("max_jingli"));
                }
                else me->set("max_jingli", 500);
                me->set("jingli", me->query("max_jingli"));

                me->set("no_sing", 1);
                me->set_temp("copied", 1);
                }
        }
}

int do_catch(string arg)
{
                  object me, ob,herb;
                  int exp;

                  me = this_player();

		  if( !arg || !(arg == "yufeng" || arg == "yu feng" || arg == "feng" || arg == "bee") )
			return notify_fail("你要抓什么？\n");

                  if( me->is_fighting() || me->is_busy() )
                                         return notify_fail("你正忙着。\n");
                  if( !(ob = present("fengjiang ping", me)) )
                                         return notify_fail("你没有蜂浆瓶，怎么抓？\n");

                  if( (int)me->query("jingli") < 25 )
                                         return notify_fail("你太累了，先歇息一会儿吧。\n");

                  me->add("jingli", -20);
                  me->start_busy(3);

                  if( !me->query_temp("herb/found") ) {
                                         message_vision("$N一不小心没抓住树差，从树上掉了下来，一屁股坐在地上，蜂浆瓶也摔坏了！\n", me);
                                         destruct(ob);
                                         return 1;
                  }

                  add("count", -1);
              herb = new(herbs[random(sizeof(herbs))]);
              herb->set("owner/id", me->query("id"));
                  herb->move(me);

                  message_vision(HIY"$N小心翼翼的伸过手去，猛一挥手，把$n"+HIY"抓在手里！\n"NOR, me,herb);
                  if(me->query_temp("gm/feng",1))
                  {
				me->set_temp("yufeng_find",1);
                  }

                  if(random(2)==1)
                  {
                          message_vision(HIY"\n$N兴奋过度，蜂浆瓶从口袋里划落出去，掉在地上摔坏了！\n"NOR, me);
                          destruct(ob);
                  }
                  else if(random(4)==2)
                  {
                          message_vision(HIY"\n$N过分紧张，一失手没抓住，结果$n"+HIY"受到惊吓，头也不会的飞走了！\n"NOR, me,herb);
                          destruct(herb);
                  }
                  me->delete_temp("herb/found");
                  me->set_temp("herb/got", 1);
                  return 1;
}