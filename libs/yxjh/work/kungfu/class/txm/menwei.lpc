#include <ansi.h>

inherit BHNPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
    set_name(HIC"门卫"NOR,({"men wei","men","wei"}));
        set("gender", "男性" );
        set("age", 25);
        set("shen_type",1);
        set("attitude", "peaceful");
        set("long","他是一位铁血盟的门卫，他太阳穴高高鼓起，显示出他有一身不俗的本领。\n");
        set("nickname", HIR "铁血盟" NOR);
        set("combat_exp",2000000);
        set("str", 30);

        set_skill("unarmed",500);
        set_skill("dodge",500);
        set_skill("parry",500);
        set("max_neili",1000);
        set("neili",1000);

        create_family("铁血盟",3,"弟子");
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",15);
   
}
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "铁血盟") 
             {
               message_vision("门卫对着$N点点头道: 您回来了，快请进吧。\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("门卫冲着$N微笑说：来铁血门的都是热血男儿。\n",ob);
               return;
              }
}
