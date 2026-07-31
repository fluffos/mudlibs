 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("一只小山雀", ({ "bird", "little bird" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 1);
        set("long", "这是一只好可爱的小山雀。\n");
        set("attitude", "peaceful");
        set("limbs", ({ "头部", "身体", "左脚", "右脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 1);
        set("chat_msg", ({
"小山雀＂叽～～叽叽＂地向你要东西吃。\n",
        }) );
        set_temp("apply/attack", 400);
        set_temp("apply/armor", 40);
        set_temp("apply/dodge",400);
        set("str",60);
        setup();
        carry_object(__DIR__"obj/tongue");
}   
