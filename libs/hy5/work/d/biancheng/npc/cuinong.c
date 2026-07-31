#include <ansi.h>

 inherit NPC;
void create()
{
        set_name("翠浓",({"cuinong"}));
        set("title",HIG"边城美人"NOR);
        set("long","她长得也许并不算太美，但却有双会说话的眼睛，灵巧的嘴。她虽然只是静静地坐
在那里，但却自然地有种醉人的风姿和气质。一个这样的女人，无论对任何男人来
说都已足够（ｅｎｊｏｙ）。。。\n");
        set("gender","女性");
        set("age",22);
                
        set("str", 10);
        set("per", 60);
        
        set("combat_exp", 500000);
        set("attitude", "friendly"); 
        setup();
        carry_object("/clone/cloth/female-shoe")->wear();
} 
int accept_fight(object me)
{
        command("say 小女子哪里是您的对手？");
        return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
        if((int)obj->value() >= 500000) me->add_temp("marks/chick2",1);
        return 1;
} 
void init()
{
        add_action("do_enjoy","enjoy");
} 
int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
        me = this_player();
        if((int)me->query_temp("marks/chick2") <=0)
        {
        command("say 哎哟．．．这位" + RANK_D->query_respect(me) +
        "，您还没给赏就想占人家的便宜么？");
        return 1;
        }
        me->add_temp("marks/chick2",-1); 
message_vision("$N轻飘飘地向$n走过来，温柔的抚弄$n的黑发．．．\n",this_object(),me);
        me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
                        destruct(inv[i]);
                }
        maxgin = (int)me->query("max_gin");
        maxkee = (int)me->query("max_kee");
        maxsen = (int)me->query("max_sen");
        me->set("eff_jing", maxgin);
        me->set("jing", maxgin);
        me->set("eff_qi", maxkee);
        me->set("qi", maxkee);
        me->set("eff_jing", maxsen);
        me->set("jing", maxsen);
        wo = new(__DIR__"obj/jade-hua");
        wo->move(me);
        return 1;
} 
