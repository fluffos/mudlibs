#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIY "地藏王菩萨念道：阿弥陀佛！\n\n" NOR,
        HIY "地藏王菩萨伸出一只手，发出无限光芒，按在你的顶门之上。\n\n" NOR,
        HIY "地藏王菩萨轻叹一声：汝虽为佛门弟子，却要遭受如此苦难，只因因果如此，善哉！善哉！\n\n" NOR,
        HIY "地藏王菩萨道：汝当一心向佛，历十纪灾难，才能超脱苦海，终成正果！\n\n" NOR,
        HIY "地藏王菩萨叹道：佛曰“我不入地狱，谁入地狱？”，你走吧，去偿还那前世的孽债。\n\n"
                HIW"你觉得自己的意识越来越弱，渐渐不省人事了。。。\n\n" NOR,
});

void create()
{
        set_name("地藏王菩萨", ({ "dizangwang pusa", "pusa", "budda" }) );
        set("title",  HIY"阴间轮回王"NOR );
        set("long", "你低头埋首，无法看清他的宝象。\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"大殿中响起一阵：“阿弥陀佛”的声音。\n",
"又走进来几名厉鬼，都双手合十，跪在地上。\n",
        }) );
        set("age", 300000);
        set("combat_exp", 200000);
        set("max_jing", 1000);
        set("max_qi", 1000);
        setup();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 60, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say 轮回无常，阳间之人，应当回到阳间去才是。");
                message_vision("两名力士闪了出来，架起$N，一晃就不见了！\n", ob);
                ob->reincarnate();
                ob->move(REVIVE_ROOM);
                tell_object(ob, HIW"你一阵晕旋，醒来后却发现自己已经回到了阳间！\n"NOR);
                message("vision","你忽然发现人影不知从什么地方冒了出来。\n", environment(ob), ob);
                return;
        }

        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
ob->save();
        ob->move(REVIVE_ROOM);
        message("vision","你忽然发现前面多了一个人影，不过那人影又好像已经在那里很久了，只是你一直没发觉。\n", environment(ob), ob);
}
