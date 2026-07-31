// Written by Lonely@IsMUD.net (05/21/2009)

#include <ansi.h>
inherit "inherit/char/boss";

void sp_attack();
void create()
{
        set_name(HIB "秦始皇僵尸" NOR, ({ "qin shihuang", "king" }));
        set("long", HIB "这曾是一位统一六国的王者，现在只是僵尸一个。\n" NOR);
        set("title", HIY "皇帝" NOR);
        set("attitude", "aggressive");
        set("str", 120);
        set("con", 120);
        set("dex", 120);
        set("int", 120);

        set("max_qi", 80000000);
        set("max_jing", 40000000);
        set("neili", 25000000);
        set("max_neili", 25000000);
        set("max_jingli", 50000000);
        set("jingli", 50000000);
        set("jiali", 40000);
        set("level", 70);
        set("combat_exp", 2000000000);
		
				set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: sp_attack :),
        }));

        set("death_msg", HIY "\n$N散落成一堆碎骨头。\n\n" NOR);

        set_skill("force", 3500);
        set_skill("zixia-shengong", 3500);
        set_skill("huashan-neigong", 3480);
        set_skill("dodge", 3500);
        set_skill("feiyan-huixiang", 3500);
        set_skill("huashan-shenfa", 3500);
        set_skill("parry", 3520);
        set_skill("sword", 3520);
        set_skill("lonely-sword", 3520);
        set_skill("blade", 3500);
        set_skill("fanliangyi-dao", 3500);
        set_skill("strike", 3480);
        set_skill("hunyuan-zhang", 3480);
        set_skill("cuff", 3480);
        set_skill("poyu-quan", 3480);
        set_skill("literate", 3480);
        set_skill("martial-cognize", 3420);

        /*
        map_skill("cuff", "poyu-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "dugu-jiujian");
        map_skill("blade", "fanliangyi-dao");
        map_skill("sword", "dugu-jiujian");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");
        */

        set("bonus", 150000);
        set_temp("apply/attack", 50000+random(30000));
        set_temp("apply/damage",50000+random(30000));
        set_temp("apply/unarmed_damage",50000+random(30000));
        set_temp("apply/armor", 50000+random(30000));
        set_temp("apply/add_xuruo", 90);
        set_temp("apply/reduce_damage", 90);
        set_temp("apply/reduce_busy", 36);
        set_temp("apply/add_busy", 50);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void sp_attack()
{
        object *enemies, enemy, ob;
        object *obs;
        string msg;
        int i;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies) == 0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        obs = filter_array(all_inventory(environment(this_object())), (: $1->query("id") == "skeleton fighter" :) );
        if( sizeof(obs) < 7 && !random(5) ) {
                msg = HIY"$N展开手中的黑色幡布，顿时阴风呼号，惨雾弥漫，召唤出数个骷髅武士，\n"
                         "这些骷髅生前是秦皇身边的护卫，死后仍然受他驱策，惨啸着向$n扑来！\n"NOR;
                message_vision(append_color(msg, HIY),this_object(),enemy);
                for( i=0;i<3;i++ ) {
                        ob = new(__DIR__"skeleton");
                        ob->set_from_me(enemy);
                        ob->move(environment(enemy));
                        ob->kill_ob(enemy);
                }
                return;
        }
        if( !enemy->is_busy() && sizeof(ob) > 3 && !random(5) ) {
                msg = HIY"$N祭起手中的五色石印，只见那石印飞到空中，射出一道蒙蒙青光，把$n笼罩在内。\n"
                         "$n只觉得身体仿佛被一座大山压住，四肢动弹不得，就连呼吸都十分艰难，只能眼\n"
                         "睁睁地看着骷髅狞笑着一步步走近！\n" NOR;
                message_vision(append_color(msg, HIY),this_object(),enemy);
                enemy->start_busy(5);
                return;
        }
        /*
        秦皇僵尸久攻不下，感到十分不耐烦，于是把河图虎符都仍在一旁，从身边的剑鞘中
        拔出一把青光闪闪的宝剑，虽然在棺中历经千年岁月，这把宝剑仍然光可鉴人，锋利
        无匹。烛光跳动间你赫然看见，剑鞘上刻着两个篆字：鹿卢。
        */
        switch( random(5) ){
                case 4: msg = HIY "$N"HIY"手一挥，一道金光化作一把利剑射从$n"HIY"穿体而过！\n"NOR; break;
                case 3: msg = HIW "$N"HIW"张开大口，一道道冰刀迅猛而至，$n"HIW"只觉自己气血凝滞，顿受重创。\n"NOR; break;
                case 2: msg = HIR "$N"HIR"双掌并力将一巨大的火球推向$n"HIR"，$n"HIR"被烧的体无完肤。\n"NOR; break;
                case 1: msg = MAG "$N"MAG"一声嚎叫，口中吐出黄沙，狂风呼啸，那尖利的啸声夹杂这黄沙如刀，如剑，越来越尖... 越来越急...\n"
                                  "$n"MAG"全身顿时千创百孔，鲜血直涌而出。\n"NOR;break;
                default: msg= HIG "$N"HIG"脚一跺地，只见$n"HIG"脚边的地上快速生长出树藤紧紧包裹这$n"HIG"，$n"HIG"顿时呼吸不畅，头晕眼花。\n"NOR; break;
        }
        message_vision(msg,this_object(),enemy);
        enemy->receive_damage("qi",50000+random(50000),this_object());
        COMBAT_D->report_status(enemy);
        if( !enemy->is_busy() )
                enemy->start_busy(2);
        return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        int reduce;

        damage = 10000 + random(10000);
        reduce = (int)ob->query_temp("apply/reduce_fire");
        damage -= damage * reduce / 100;
        if( damage < 0 ) damage = 0;
        ob->receive_damage("qi", damage, me);
        ob->receive_wound("qi", damage, me);
        me->set("neili", me->query("max_neili"));
        return HIY "$N" HIY "全身闪出耀眼的金光，登时令$n"
               HIY "全身有若刀绞。\n" NOR;
}
