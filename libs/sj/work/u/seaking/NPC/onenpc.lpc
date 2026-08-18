#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define ONENPC NPCDATA + "onenpc"

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

string query_save_file()
{
        return ONENPC;
}

void create()
{
        seteuid(getuid());

        if (!restore()) {
        set_name("电脑人物", ({ "one npc", "npc", "one" }) );
        set("title", "不知道" );
        set("gender", "男性" );
        set("age", 35);
        set("long","一个傻瓜。\n");
        set("attitude", "heroism");
        set("generation", 0);
        set("winner", "none");

        set("str", 25);
        set("con", 25);
        set("int", 25);
        set("dex", 25);

        set("max_qi", 500);
        set("eff_qi", 500);
        set("qi", 500);
        set("max_jing", 300);
        set("jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("shen_type", 0);

        set("no_clean_up",1);
        set("combat_exp", 400000);

        set_skill("force",  90); 
        set_skill("unarmed",90);
        set_skill("sword",  90);
        set_skill("dodge",  90);
        set_skill("parry",  90);
        setup();
        }
        else {
                set("id", "npc");
                set_name(query("name"), ({ query("id") }));
                setup();
                if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
                if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();        
        }
}

