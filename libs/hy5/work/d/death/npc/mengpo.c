#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIW "孟婆说道：哦！又来了个新的，你叫什么名字？\n\n" NOR,
        HIW "孟婆说道：来！喝了我这孟婆汤再去投胎吧。\n\n" NOR,
        HIW "你端起汤，仰头喝了下去，这味道又酸又咸，恍如人情世事，又酸又咸。\n\n" NOR,
        HIW "一连三碗，你喝下了三次孟婆汤，那前生所有恩怨爱恨，皆尽数忘记。\n\n" NOR,
        HIW "孟婆说道：你已经喝完了汤，去吧，忘却深噩前尘，脱胎重生。\n\n"
                "迷迷糊糊中，你觉得自己又堕入了滚滚轮回。。。\n\n" NOR,
});

void create()
{
        set_name("孟婆", ({ "meng po", "meng", "po" }) );
        set("long","她是由一名面貌阴森的老妇，掌管阴间道上的孟婆亭。\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({
"孟婆嘿嘿一笑：来吧，来吧，喝口我这孟婆汤，忘却前世吧。\n",
"孟婆转身拿出一个空碗，缓缓舀起一碗酸咸的孟婆汤。\n"
        }) );
        set("age", 2107);
        set("combat_exp", 20000);
        set("max_jing", 900);
        set("max_qi", 900);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

void init()
{
        ::init();        
        if( !previous_object()
           || !userp(previous_object()) ) 
            return;
        call_out( "death_stage", 60, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say 咦？！怎么来了个阳人？");
                message_vision("不知从哪里冒出来两个无常，架起$N，一晃就不见了！\n", ob);
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

        inv =  all_inventory(ob);
ob->move(REVIVE_ROOM);
ob->save();
        message("vision","你忽然发现前面多了一个人影，不过那人影又好像已经在那里很久了，只是你一直没发觉。\n", environment(ob), ob);

}

