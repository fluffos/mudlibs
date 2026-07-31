#include <ansi.h>
inherit NPC; 
int send_fan(); 
void create()
{
        set_name("老妇人", ({ "old woman", "woman" }) );
        set("gender", "女性");
        set("age", 49);
        set("long",
                "老妇人正在忙着做饭。\n"
        );
        set("attitude", "peaceful");
        set("combat_exp", 10);
        set("env/wimpy", 100);
        set("inquiry", ([
                "饭" : (: send_fan :),
                "饭菜" : (: send_fan :),
                "老伴" : "他还在庄家地里干活，连饭都忘了吃。"
        ]) );
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/basket2");
} 
int send_fan()
{
        object bag, me, rice, vege, chop; 
        me = this_player();
        say("老妇人说道：屋外桌上有饭菜，这位" + RANK_D->query_respect(me) +
                "请用一些吧。\n");
        if( bag = present("basket", this_object())) {
                say("老妇人停了一下又说道：请这位" + RANK_D->query_respect(me) +
                        "把这个给我老伴送去好吗？\n");
                rice = new(__DIR__"obj/rice");
                vege = new(__DIR__"obj/vege");
                chop = new(__DIR__"obj/chopstick");
                rice->move(bag);
                vege->move(bag);
                chop->move(bag);
                bag->move(me);
                message_vision(HIY "$N将一件物事交给了$n，转身又去做饭了。\n"NOR, this_object(), me );
   }
        return 1;
}      
