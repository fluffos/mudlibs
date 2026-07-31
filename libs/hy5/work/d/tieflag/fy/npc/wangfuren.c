 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC;
object ob; 
void create()
{
        set_name("樊夫人", ({ "furen" }) );
        set("gender", "男性" );
        set("title", HIR "祭剑师"NOR);
        set("age", 52);
        set("long",
                "樊夫人并非哪家的太太，他本是三清宫的一个姓樊名夫人的老道士，\n人到老年无所事事，在这里给人祭剑。\n");
        set("combat_exp", 50000);
    set("str",30);
        set("attitude", "friendly");
        set("busy", 0);
        setup();
        add_money("gold", random(2));
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
 //       add_action("do_ji","ji");
//        add_action("do_answer", "answer");
        //if (!objectp(environment(this_object())->query("processing"))
        //      environment(this_object())->set("processing", ob);
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("hell sword", ob)) {
                if (ob->query("宿命A") || ob->query("宿命B")){
                   if(ob->query("stone_mark/pstone")){
                                message_vision("\n$N微阖双眼看了看$n的幽冥紫灵剑，沉吟半晌道：幽冥紫灵剑向来只有一把，这一把定为赝品。\n",
                                                this_object(), ob);
                                return;
                        }
                        message_vision(HIY"\n$N人眼中透出热切的光，看着幽冥紫灵剑，喃喃地说：“这可是用千古难求\n"NOR, this_object());
                        message_vision(HIY"的幽冥紫晶炼成的啊。可惜冶剑之人不得其法，空误了地府之珍。”\n"NOR, this_object());
                        message_vision("\n$N说：“如果" + RANK_D->query_respect(ob) 
+ "愿意以百金相赠，我可以把幽冥紫晶提炼还原。”\n" +
"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ ）\n", this_object()); 
                        ob->set_temp("furen_yes_no", 1);
                } else {        
                        message_vision(YEL"$N的眼光扫过$n的幽冥紫灵剑，眼光让人琢磨不透。\n"NOR, this_object(), ob);
                }
        } else {
                switch( random(5) ) {
                        case 0:
                                say( "樊夫人笑道：这位" + RANK_D->query_respect(ob)
                                        + "，你的宝刃看起来好象要血祭一下了。\n");
                                break;
                        case 1:
                                say( "樊夫人说道：这位" + RANK_D->query_respect(ob)
                                        + "，你的宝刃杀气不足，来血祭一下宝刃吧。\n");
                                break;
                }
        }
}
