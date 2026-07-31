//封神台守卫
//by junhyun@SK

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{

        set_name(HIG"守卫"NOR, ({ "guard" }) );
        set("race", "人类");
        set("age", 3000);
        set("long", "看来守卫不会让你进去的。\n");
        set("str", 20);
        set("cor", 30);
        set("max_neili", 3000);
        set("neili", 5000);
        set("neili", 5000);
        set("max_neili", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 1000000+random(1000000));
         set("combat_exp", 5000000);

 
        set_temp("apply/armor", 80);
        set_temp("apply/damage",80);
        set_temp("apply/armor_vs_force",300);
        set_weight(1000000);
        setup();
        initlvl((200+random(100)),1);
        //carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}


void init()
{
        ::init();
        add_action("do_cast", "cast");
        add_action("do_perform", "perform");
        add_action("do_bian", "bian");
        add_action("do_ji", "ji");

}

/*int do_dou()
{
        object me,who;
        me =this_object();
        who=this_player();

        if(me->is_fighting())
                return notify_fail("慢慢来，不要急。\n");
        message_vision("$N对$n大喊一声：看招！\n\n", who,me);
        me->kill_ob(who);
        who->kill_ob(me);
//        COMBAT_D->do_attack(me, who, query_temp("weapon"));
        me->set("owner",who->query("id"));
        return 1;
}
void die()
{
        string owner;
        object owner_ob;

        owner = query("owner");

        if(!owner) return ::die(); // added by mon.

        owner_ob= find_player(owner);

        if( owner_ob && (object)query_temp("last_damage_from") == owner_ob ) {
                owner_ob->add_temp("mark/人", 1);
                owner_ob->add_temp("mark/仙", 1);
        message_vision("$N喝道：休得猖狂，待我回家取法宝来收你。\n",this_object());
                destruct(this_object());
                return;
        }
        ::die();
}  */

int do_cast(string arg)
{
        object who = this_player();
        object me = this_object(); 
        message_vision("$N张开嘴，结结吧吧地念了几声咒语。\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who); 
        return 1;
}        

/* int do_exert(string arg)
{               
        object who = this_player();
        object me = this_object();
        message_vision("$N鬼鬼祟祟地一运气。\n",who);
        message_vision("$N对$n摇了摇头。\n", me, who); 
        return 1;
} */

int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N脸色不大对，好象动了杀机！\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who);  
        return 1;
}   

int do_ji(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N偷偷把手伸进怀里，想用什么法宝！\n", who);
        message_vision ("$N对$n摇了摇头。\n", me, who);  
        return 1;
}

