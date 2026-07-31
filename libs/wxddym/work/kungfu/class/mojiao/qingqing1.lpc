// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#define MOON_BLADE    "/clone/lonely/moonblade"

mixed ask_blade();

void create()
{
        set_name("青青", ({"qing qing", "qing"}));
        set("gender", "女性");
        set("age", 21);
        set("shen_type", -1);
        set("long", "
穿着一身淡青色的衣服，就像是春天晴朗的天空，
晴空下清澈的湖水，湖水中倒映着的远山，美得
神秘而朦胧。笑容清新，甜柔，纯洁，高贵。腰
上挂着一柄弯刀，弯刀是用纯银作刀鞘，刀柄上
镶着一粒光泽圆润的明珠。");

        set("attitude", "peaceful");

        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("neili", 130000);
        set("max_neili", 130000);
        set("jiali", 3000);

        set("combat_exp", 150000000);
        set("score", 0);

        set_skill("force", 280);
        set_skill("moshen-xinfa", 280);
        set_skill("chiyou-kuangzhanjue", 250);
        set_skill("dodge", 280);
        set_skill("moshen-bufa", 280);
        set_skill("jiutian-xiaoyaobu", 250);
        set_skill("strike", 280);
        set_skill("moshen-zhangfa", 280);
        set_skill("cuff", 280);
        set_skill("moshen-quanfa", 280);
        set_skill("sword", 280);
        set_skill("moshen-jianfa", 280);
        set_skill("blade", 280);
        set_skill("moshen-daofa", 280);
        set_skill("moon-blade", 280);
        set_skill("parry", 250);
        set_skill("literate", 210);
        set_skill("medical", 200);
        set_skill("mojiao-medical", 200);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "moshen-zhangfa");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "moshen-jianfa");
        map_skill("blade", "moon-blade");
        map_skill("parry", "moon-blade");

        prepare_skill("strike", "moshen-zhangfa");

        create_family("魔教", 40, "弟子");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.ting" :),
                (: perform_action, "blade.yue" :),
                (: exert_function, "recover" :),
        }) );

        set("inquiry", ([
                "圆月弯刀"      : (: ask_blade :),
        ]));

        set_temp("apply/attack", 280);
        set_temp("apply/damage", 280);
        set_temp("apply/unarmed_damage", 280);
        set_temp("apply/armor", 280);

        set("master_ob", 5);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        add_money("silver",70);
}

void attempt_apprentice(object ob)
{
        command("say 我不收徒，你还是另找他人吧！");
}

mixed ask_blade()
{
        object ob,owner;
        object gift;
        object me;

        me = this_player();
        if (me->query("family/family_name") != query("family/family_name"))
                return "你找死啊？";

        if ((int)me->query("combat_exp")<2000000)
                return "你武功太差了，就别给我魔教丢脸了。";
/*
        if (me->query("birthday") < 1234804783 && ! me->query("washgift", 1)) {
        gift = new("/clone/item/washgift");
        gift->move(me, 1);
        gift->set("bindable", 3);
        gift->set("bind_owner", me->query("id"));
        gift->set("autoload", 1);
        gift->set("setdbase", 1);
        me->set("washgift", 1);
        tell_object(me, HIW "青青给了你一个洗天赋丹。\n" NOR);
        }
*/
        call_other(MOON_BLADE, "???");
        ob = find_object(MOON_BLADE);
        if (! objectp(ob))
                return "刀没了！";

        if (objectp(owner = environment(ob)))
        {
                if(owner == me)
                {
                        destruct(ob);
                        return "你什么意思？不要就拿回来嘛。\n";
                }
                if(owner->is_character())
                {
                        return "刀已经被" + owner->name(1) + "拿走了。等归还后你再来取吧。\n";
                }
                return "刀已经被人借走了。现在不知道在什么地方。\n";
        }
        ob->move(me, 1);
        ob->start_borrowing();
        message_vision("$N掏出一把象月芽儿样的弯刀，递给$n，"
                       "道：“你可要拿好了！切勿被他人拿走”。\n", this_object(), me);
        return 1;
}
