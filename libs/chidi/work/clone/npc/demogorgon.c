// demongorgon.c
#include <ansi.h>
inherit BHNPC;
void create()
{
     
        set_name( HIW "侮天鬼王" NOR, ({ "demogorgon" }) );
        set("long",
                "侮天鬼王神情倨傲地站在你面前，他高大的身躯跟一股令人窒息的\n"
                "可怕杀气正压得你几乎喘不过气来，你的心里似乎有一个声音在告\n"
                "诉你：「 快 逃 ！！」\n");
        set("age", 7006);
        set("pursuer", 1);
        set("attitude", "peaceful");
        set("max_jingli", 2100000);
        set("jingli", 2100000000);
        set("max_neili", 2100000);
        set("neili", 2100000000);
         set("max_qi", 2100000000);
        set("max_jing", 2100000000);
        set("demogorgon",1);
        set("str", 12000);
        set("can_perform/pixie-jian/duo",1);
        set("no_die", 1);
        set("dex", 100000+random(100000));
        set("title",HIR "杀人魔" NOR);
        set("int", 24);
        set("no_suck", 1);
        set("no_suck1", 1);
        set("con", 10000);
        set("jiali",5000000);
        set("kar", 1000);
        set("per", 1000);
        set("combat_exp", 2100000000);
        set_skill("blade", 2000000);
        set_skill("unarmed", 2000000);
        set_skill("parry", 2000000);
        set_skill("dodge", 2000000);
        set_skill("hubo", 2000000);
        set_skill("sword", 20000000);
        set_skill("pixie-jian", 20000000);
        set_skill("taiji-shengong", 15000);
        set_skill("piaomiao-shenfa", 2000000);
        set_skill("taixuan-gong", 2000000);
        set_skill("king-of-dragon", 2000000);
        set_skill("tiandao-blade", 2000000);
        map_skill("unarmed", "taixuan-gong");
        map_skill("parry", "taixuan-gong");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("blade", "tiandao-blade");
        map_skill("sword", "pixie-jian");
        map_skill("force", "king-of-dragon");
        set_temp("apply/attack1", 1500000);
	 set_temp("apply/defense1", 1400000);
	 set_temp("apply/damage", 15000);
	 set_temp("apply/armor", 10000);
        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
           (: command("perform duo") :), 
        }) );
        setup();
        set("water",2120100);
        set("food",2120100);
        carry_object(__DIR__"obj/wizardsword")->wield();
        carry_object("/clone/misc/red_cloth")->wear();
}

void unconcious()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) return;
        message("vision",
                HIR "\n\n你听到一声带著愤恨、惊恐、与野兽般的咆哮声响彻整个天空。\n\n"
                HIW "侮天鬼王" HIR "嘶哑地吼著：可恶的" + ob->name(1) + "，我一定会报仇的～～～\n\n"
                        "然後一道黑色火焰呼啸著冲上云端，大地又恢复了宁静。\n\n" NOR,
          environment() );
        destruct(this_object());
}

void die()
{
   unconcious();
}

void leave()
{
        message_vision("$N"+GRN+"左右看了看，发现目标已经不见了，于是迈开大步，头也不回地走了。\n"+NOR,this_object());
        this_object()->move(VOID_OB);
        destruct(this_object());
}
void killed_enemy(object obj)
{
    if (query("kill_ob")) delete("demogorgon");
       call_out("leave",1);
}
void init()
{
    ::init();
    add_action("do_go","go");
    add_action("do_kill","kill");
    add_action("do_kill","hit");    
    add_action("do_kill","fight");
}

int do_go(string arg)
{
        mapping exit;
        if( !mapp(exit = environment()->query("exits")) || undefinedp(exit[arg]) )
                return 0;
        if (is_killing(this_player()))
                     {
                        message_vision(YEL "$N见势不好，转身要走，被$n"+YEL+"一把拦在面前。想走？没那么容易！\n"NOR, this_player(), this_object());
                        return 1;
                        }
        return 0;
}

int do_kill(string arg)
{
    if (!arg) return 0;
   if (id(arg))
  {   
    set("kill_ob",1);
    if (!is_killing(this_player()))
    message_vision("$N"+CYN+"恶狠狠地瞪了$n一眼：想和我打？你活腻了？\n" NOR,this_object(),this_player());  
    command("perform duo");
    set("eff_qi",query("max_qi"));
    set("eff_jing",query("max_jing"));
    set("jing",query("max_jing"));
    set("qi",query("max_qi"));
    add("neili",1000);
    kill_ob(this_player());
   }
    return 0;
}
