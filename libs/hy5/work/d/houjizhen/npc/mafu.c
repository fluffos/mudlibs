// mafu.c
// by dicky

inherit NPC;

void create()
{
        set_name("马夫", ({ "ma fu", "mafu", "ma"}));
        set("age", 32);
        set("gender", "男性");
        set("long", "这是马厩驯马和小伙计，平时打理照料马匹。\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set("chat_chance",2);

        setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        say("马夫冷冷地说道：自己把马系好，马走失了，是你自己的事情？\n");
}

