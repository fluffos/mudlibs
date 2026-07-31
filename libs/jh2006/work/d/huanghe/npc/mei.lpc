// mei.c 梅超风
// Modified by Darken/Numa@SJ for taohua quest

#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "梅超风" ,({ "mei chaofeng", "mei" }));
        set("title", "黑风双煞");
        set("nickname", HIB"铁尸"NOR);
        set("gender", "女性");
        set("age", 32);
        set("long",
            "梅超风是黄药师唯一的女弟子，本来极受黄药师疼爱，可惜她与师兄陈玄风\n"
            "暗生情愫，他们偷了《九阴真经下卷》私奔。\n"
            "她面色大概因为久居海岛显得黝黑，模样却颇为俏丽。她在桃花弟子中尤精\n"
            "通鞭法。\n");
        set("attitude", "aggressive");
        set("str", 47);
        set("int", 32);
        set("con", 35);
        set("unique", 1);
        set("no_get", "梅超风对你而言太重了。\n");
        set("max_qi",3500);
        set("qi",3500);
        set("max_jing",1000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 1000000);

        set_skill("claw", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("leg", 200);
        set_skill("jiuyin-baiguzhua", 200);
        set_skill("bihai-chaosheng", 200);
        set_skill("suibo-zhuliu", 200);
        set_skill("xuanfeng-tui", 200);

        map_skill("force", "bihai-chaosheng");
        map_skill("parry", "jiuyin-baiguzhua");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("claw", "jiuyin-baiguzhua");
        map_skill("leg", "xuanfeng-tui");
        prepare_skill("claw", "jiuyin-baiguzhua");

        create_family("桃花岛", 2, "被逐弟子");
        set("inquiry", ([
           "铁尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "洪七公":   "洪七公武功高强，而且教会郭靖那小儿降龙十八掌，可恨！",
           "黄蓉":     "她是我师父的独女，最是刁蛮任性。",
           "郭靖":     "哼，就是这个小子暗算了我师哥，我绝不会放过他！",
           "杨康":     "康儿是我的徒弟，你见过他么？",
           "梅超风":   "不就是我么？你是白痴啊？",
           "陈玄风":   "他是我的师哥，也是我的夫君，可惜被郭靖那小儿暗算了。",
           "黄药师":   "他是我师父。"]) );
        setup();
}

void die()
{
        object ob = this_object(),me,cor;

        if (!ob->query_temp("target"))
        {
                call_out("do_die",1,ob);
                return;
        }
        
        me = query_temp("last_damage_from");

        if (me->query("id") != ob->query_temp("target"))
        {
                ob->revive(1);
                command("say 好，居然还有" + me->name(1) + "帮你，哼！");
                message_vision(HIY"梅超风见形势不好，转身逃了！\n"NOR, me);
                destruct(ob);
                return;
        }
        else
        {
                if (me->query_temp("thd/onquest")>2
                && me->query_temp("thd/onquest")<4)
                {
                        ob->revive(1);
                        ob->reicarnate();
                        message_vision(HIY"梅超风运起残存的内力，又跳起来狠狠的瞪着$N。\n"NOR, me);
                        if (objectp(cor = present("corpse",environment(ob))))
                        {
                                tell_room(environment(ob),"梅超风将陈玄风的尸体扶了起来背在背上。\n");
                                call_out("do_dest",1,cor);
                        }
                        command("stare");
                        command("say 哼，咱们走着瞧！");
                        message_vision(HIY"梅超风抱起陈玄风的尸身，一晃眼就不见了。\n\n\n"NOR, me);
                        if (me->query("thd/quest1")<1 && random(me->query_kar()/10)>0)
                        {
                                message_vision(HIW"$N长途奔走又和黑风双刹缠斗许久，身法进步了一些！\n"NOR,me);
                                me->set("thd/quest1",1);
//                                me->add("dex",1);
//write_file("/log/thdadd",sprintf("%s %s(%s)dex add 1。\n",ctime(time())[4..19],me->name(1),me->query("id")));
                        }
                        me->set_temp("thd/onquest",4);
                }
                else if (me->query_temp("thd/onquest")>5
                      && me->query_temp("thd/onquest")<7)
                {
/*
                        if (me->query("thd/quest1")<2)
                        {
                                message_vision(HIW"$N和梅超风再次苦斗，臂力增加不少！\n"NOR,me);
                                me->set("thd/quest1",2);
                                me->add("str",1);
                        }
*/
                        me->set_temp("thd/onquest",7); 
                message_vision(HIM"梅超风身上掉下一把用皮革包裹的匕首。\n"NOR,me);
                message_vision(HIM"$N将匕首和皮革收了起来。\n"NOR,me);
                        new("/d/huanghe/skin")->move(me);
                        new("/d/huanghe/bishou")->move(me);
                        call_out("do_die",1,ob);
                        return;
                }
                call_out("do_dest",1,ob);
                return;
        }
}


void do_die(object ob)
{
        :: die();
}

void do_dest(object ob)
{
        destruct(ob);
}

