// NPC: /d/wizard/npc/shitong.c
// Date: Look 99/10/25

inherit NPC;

string ask_gonglao(object me);

void create()
{
        set_name("狱卒", ({ "yuzu" }));
        set("long", "他是官府监狱的狱卒，一脸威严的表情。\n");
        set("age", 47);
        set("combat_exp", 20000);
        set("int", 10);
        set("con", 50);
        set("dex", 50);
        set("str", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("max_qi", 9000);
        set("qi", 9000);
        set("max_jing", 300);
        set("jing", 300);
        set("eff_jingli", 300);
        set("jingli", 300);
        set("max_neili", 300);
        set("neili", 300);
        
        set("inquiry", ([
              "释放" : (: ask_gonglao :),                        
        ]));

        setup();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_gonglao(object who)
{
        int i;
        object me=this_player();
        i = me->query_condition("killer");
        if ( !i ) return RANK_D->query_respect(me)+"没有杀人，跑这里来做什么？哦，对了，你是巫师！\n";
        if(random(10) > 3) return RANK_D->query_respect(me)+"这是什么意思，自己的事情，问我干什么？\n";
        message_vision("$N悄悄对$n说道，"+RANK_D->query_respect(me)+"还有" + CHINESE_D->chinese_number((i-175)/6) + "个时辰就出去了。\n",who,me);
        return RANK_D->query_respect(me)+"可不要再乱杀无辜了哦！";
}
