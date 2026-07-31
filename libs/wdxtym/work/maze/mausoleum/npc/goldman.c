// Written by Lonely@IsMUD.net (05/21/2009)

#include <ansi.h>
inherit "inherit/char/boss";

void random_move();
void sp_attack();
void create()
{
        set_name( "金人", ({ "gold man"}));
        set_color("$HIY$");
        set("long", @LONG
这是秦始皇完成统一大业之后，收缴天下兵器，熔化之后铸成的一座金人，身高三丈，
重达千石，如同一座巍峨的山峰，耸立在你面前。秦始皇死后，这座金人就作为墓室
的守卫者，数千年来一直守卫着秦陵的内宫。它刀枪不入，力大无穷，触动机关之后
在东方仙术的作用下赫然使出一套失传已久的武技，古往今来不知有多少盗墓的好手
栽在它的手上。
LONG );
        set("title", HIY "九大护法" NOR);
        set("attitude", "aggressive");
        set("str", 120);
        set("con", 120);
        set("dex", 30);
        set("int", 30);

        set("max_qi", 5000000);
        set("max_jing", 2500000);
        set("neili", 2500000);
        set("max_neili", 2500000);
        set("max_jingli", 500000);
        set("jiali", 20000);
        set("level", 60);
        set("combat_exp", 1000000000);

        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: sp_attack :),
        }));

        set("death_msg", HIY "\n$N散落成一堆青铜。\n\n" NOR);

        set_skill("force", 2500);
        set_skill("zixia-shengong", 2500);
        set_skill("huashan-neigong", 2480);
        set_skill("dodge", 2500);
        set_skill("feiyan-huixiang", 2500);
        set_skill("huashan-shenfa", 2500);
        set_skill("parry", 2520);
        set_skill("sword", 2520);
        set_skill("dugu-jiujian", 2520);
        set_skill("blade", 2500);
        set_skill("fanliangyi-dao", 2500);
        set_skill("strike", 2480);
        set_skill("hunyuan-zhang", 2480);
        set_skill("cuff", 2480);
        set_skill("poyu-quan", 2480);
        set_skill("literate", 2480);
        set_skill("martial-cognize", 2420);

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

        set("bonus", 20000);
        set_temp("apply/attack", 20000+random(10000));
        set_temp("apply/damage",20000+random(10000));
        set_temp("apply/unarmed_damage",20000+random(10000));
        set_temp("apply/armor", 20000+random(10000));
        set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 33);
        set_temp("apply/add_busy", 40);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object me;

        ::init();
        if( !interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void sp_attack()
{
        object *enemies, enemy;
        string msg;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies) == 0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        switch( random(7) ){
                case 6: msg = HIY"$N猛地一跺脚，一道震波从地面传来，$n顿受重创，扑通摔倒在地。\n"NOR;break;
                case 5: msg = HIY"$N突然向你扑来，死死地将你抱住，$n听见自己全身的骨骼格格作响，似乎要在这一抱之下化为齑粉"NOR; break;
                case 4: msg = HIY"$N突然高高跃起，巨大的身躯遮天蔽日。你想要施展身法闪躲开来，无奈金人的体积实在太大，\n"
                                 "而墓室中的空间不大，闪躲的余地十分有限，只听到一声巨响，你的身躯被金人活活砸入地面\n"NOR; break;
                case 3: msg = HIY"$N双手突然发出强烈的光芒，令$n睁不开眼，$n感到一阵具痛。片刻后光芒散去，$n赫然发现$N的手中多出一柄巨斧正在滴血，\n"
                                 "$n被$N使出一套失传已久的古代斧法所伤！\n"NOR; break;
                case 2: msg = HIY"$N双手突然发出强烈的光芒，令$n睁不开眼，$n感到一阵具痛。片刻后光芒散去，$n赫然发现$N的手中多出一柄巨剑正在滴血，\n"
                                 "$n被$N使出一套失传已久的古代剑法所伤！\n"NOR; break;
                case 1: msg = HIY"$N双手突然发出强烈的光芒，令$n睁不开眼，$n感到一阵具痛。片刻后光芒散去，$n赫然发现$N的手中多出一柄巨锤正在滴血，\n"
                                 "$n被$N使出一套失传已久的古代锤法所伤！\n"NOR; break;
                default: msg = HIY"$N双手突然发出强烈的光芒，令$n睁不开眼，$n感到一阵具痛。片刻后光芒散去，$n赫然发现$N的手中多出一柄巨刀正在滴血，\n"
                                 "$n被$N使出一套失传已久的古代刀法所伤！\n"NOR; break;
        }
        message_vision(append_color(msg, HIY),this_object(),enemy);
        enemy->receive_damage("qi",10000+random(10000),this_object());
        COMBAT_D->report_status(enemy);
        if( !enemy->is_busy() )
                enemy->start_busy(2);
        return;
}

/*
varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}
*/

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        int reduce;

        damage = 5000 + random(5000);
        reduce = (int)ob->query_temp("apply/reduce_fire");
        damage -= damage * reduce / 100;
        if( damage < 0 ) damage = 0;
        ob->receive_damage("qi", damage, me);
        ob->receive_wound("qi", damage, me);
        me->set("neili", me->query("max_neili"));
        return HIY "$N" HIY "全身闪出耀眼的金光，登时令$n"
               HIY "全身有若刀绞。\n" NOR;
}

int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place, my_birth_place;
        object env;
        string userid,mazeobj;
        int x,y;

        if( !mapp(exits = environment()->query("exits")) ) return 0;

        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place = env->query("exits/"+direction);
        //my_birth_place = file_name(this_object());

        //ccommand("say "+to_go_place);
        if( sscanf(to_go_place,"/f/mausoleum/%s/%s/%d/%d",userid,mazeobj,x,y)!=4 )
                return 1;
        command("go " + direction);
        add_temp("random_move", 1);
        return 1;
}

varargs void die(object killer)
{
        object *obs, env;
        object me, ob, mazeobj;
        int exp, pot, mar;
        int count, finished;
        string owner;
        int password;

        me = this_object();

        if( objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
                me->recover();
                return;
        }

        if( query("death_msg") )
                message_vision(query("death_msg"), this_object());

        env = environment(me);
        if( !killer )
                killer = me->query_last_damage_from();

        if( objectp(killer) ) {
                mazeobj = FUBEN_D->query_maze_mainobj(killer);
                if( !mazeobj->query("quest/to_kill/"+name()) )
                        mazeobj->set("quest/to_kill/"+name(), 9);

                count = mazeobj->query("quest/to_kill/"+name());
                finished = mazeobj->query("quest/killed/"+name());
	        finished++;
	        if( finished > count )
		        finished = count;
	        mazeobj->set("quest/killed/"+name(),finished);
	        owner = FUBEN_D->query_fuben_owner(killer);
	        password = random(10);
	        mazeobj->set("quest/password/"+finished, password);
	        FUBEN_D->tell_fuben("mausoleum",owner,HIW"杀死 "+name()+": "+finished+"/"+count+"。\n密码 "+password+"\n"NOR);

                obs = pointerp(killer->query_team()) ?
                                killer->query_team() : ({ killer });
                obs = filter_array(obs, (: environment($1) == $(env) :));

                exp = me->query("bonus");
                pot = exp / 2;
                mar = pot / 2;
                foreach( object user in obs )
                        GIFT_D->bonus(user, ([
                                "exp" : exp, "pot" : pot, "mar" : mar ]));
        }

        return ::die(killer);
}

void unconcious()
{
        object ob;

        if( objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
                this_object()->recover();
                return;
        }

        die();
}
