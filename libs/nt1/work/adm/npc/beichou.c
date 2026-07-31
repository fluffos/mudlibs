// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("北丑", ({ "bei chou", "bei", "chou", "xizi" }));
        set("long", @LONG
这是一个身着戏子打扮的瘦小老头，长得尖嘴
猴腮，天生一副奸相。谁人能知这便是当今武
林中号称「南贤北丑」戏子北丑。虽其排名在
南贤之下，但却也是南贤生平最畏惧之人。
LONG);
        set("nickname", HIW "北戏子" NOR);
        set("title", HIC "武林泰斗" NOR);
        set("gender", "男性" );
        set("age", 68);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 12000000);

        set("inquiry", ([
                "帮派"  :"要创建帮会请先组队，人数不能少于五个，然后 team bunch <帮会名> 就可以了。\n",
                "帮会"  :"要创建帮会请先组队，人数不能少于五个，然后 team bunch <帮会名> 就可以了。\n",
                "建帮"  :"要创建帮会请先组队，人数不能少于五个，然后 team bunch <帮会名> 就可以了。\n",
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({
                CYN "北丑贼眯眯的说：天算地算不如人算，可是再怎么算戏子我都知道。\n" NOR,
        }));

        setup();
        carry_object("d/city/obj/cloth")->wear();

        if (! clonep(this_object()))
        {
                move("/d/city/kedian");
                message_vision(CYN "\n$N" CYN "笑嘻嘻道：来了来了，戏子我来了。\n"
                               NOR, this_object());
                set("startroom", "/d/city/kedian");
        }
}
