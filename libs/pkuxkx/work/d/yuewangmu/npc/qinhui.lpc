//秦桧
// Modified by iszt@pkuxkx, 2007-02-28

inherit NPC;

#include <ansi.h>

void consider();

void create()  
{
        set_name(HIR"秦桧"NOR, ({ "qin hui", "qin", "hui" }));
        set("gender", "男性");
        set("age", 30);
        set("shen", -1000000);
        set("str", 15);
        set("dex", 20);
        set("long",HIW"这就是奸臣秦桧！人人得而诛之的奸臣，你还等什么？动手吧！\n"NOR);

        set("shen_type", -1);
        set("attitude", "heroism");
        set("env/wimpy", 90);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider() :),
                (HIY"秦桧哀求道：「岳飞的死不管我的事啊，您放过我吧！」\n"NOR)
        }) );
        set_skill("flatter",500);
        set_skill("dodge", 200);
        set_skill("parry", 200);

        map_skill("parry", "flatter");

        set("inquiry",([
                "风波亭"  : ("这就是风波亭啊？……"),
                "岳飞"  : ("嘿嘿，终于把他除了，谁让他欠我二两银子呢！哼！"),
        ]));

        set("chat_chance", 8);
        set("chat_msg", ({
"岳飞终于被我给除了，这下爽了！\n",
"这几天总是有刺客杀我，我加派了人手保护我，不知道安不安全。\n",
"咦？你是怎么进来的?？护卫...护卫...啊，外面的护卫呢？都被你杀了？\n"
        }) );

        setup();
//      carry_object("/d/yuewangmu/obj/jsbaojia")->wear();
}

void die()
{
        object me,qin;
        qin = this_object();
        if( objectp(me = qin->get_damage_origin_object())) 
        {
                message_vision(HIR"\n$N看到秦桧肥硕的身躯在自己眼前痛苦的挣扎，最后慢慢的倒了下去。\n\n"NOR,me);
                message_vision(HIR"$N长嘘一口气，仰天长叹：「岳王爷，您瞑目吧！」\n\n"NOR,me);
                message_vision(HIR"奸贼秦桧终于得到了他应有的下场！\n\n"NOR,me);
                message_vision(HIY"$N突然感到自己好像是正义的化身！\n\n"NOR,me);
                tell_object(me,"你的道德增加了一万点！\n");
                me->add("shen", 10000);
        }
        ::die();
        return;
}

void consider()
{
        object *enemy,target;
        object baojia;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("perform parry.qiurao " + target->query("id"));
        command("say 岳飞的死不关我的事啊，"+RANK_D->query_respect(target)+"放过我吧！\n");
}
