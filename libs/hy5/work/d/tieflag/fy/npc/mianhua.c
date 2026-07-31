 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("老板娘", ({ "boss" }) );
        set("gender", "女性" );
        set("age", 52);
        set("long",
                "老板娘善长补衣服，补出来的衣服又牢固而且不难看。\n");
        set("combat_exp", 50);
        set("str",20);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
 //       add_action("do_bu","bu");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "老板娘笑道：这位" + RANK_D->query_respect(ob)
                                + "，你的衣衫看起来好象要补一下了。\n");
                        break;
                case 1:
                        say( "老板娘说道：这位" + RANK_D->query_respect(ob)
                                + "，你的衣衫都被人砍破了，来补一下吧。\n");
                        break;
   }
} 
