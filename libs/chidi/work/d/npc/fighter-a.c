// fighter-a.c - 小游侠
#include <ansi.h>
inherit BHNPC;
#define SET_SKILL   50          // 定义基本武功的值，自动生成经验
#define SPE_SKILL   25          // 定义特殊武功的值
#define SET_SEN     30          // 定义正气的值
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
        "刘","林" });
string *name_words = ({ "文","武","斌","彦","良","志","忠","良","志","忠",
        "孝","雄","龙","明","勇","元","华","宏","胜","进","铭","彬","东","伟" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});
void create()
{
        string name, id;
        
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
        
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        
        set_name(name, ({ id, "youxia" }) );
        
        set("title", "小游侠");
        
        set("long", @LONG
一个小游侠，能在江湖行走，武功肯定不会差。
LONG
        );
        set("attitude", "heroism");
        set("gender", "男性" );
        set("age", 16+random(10));
        
        set("str", 20+random(10));
        set("int", 20+random(10));
        set("dex", 20+random(10));
        set("per", 20+random(10));
        set("con", 20+random(10));
        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
        set("shen", SET_SEN);
        set("env/wimpy", 10);
        set("max_neili", 200);      set("neili", 200);  set("jiali", 2);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        set_skill("force",   SET_SKILL);  set_skill("hunyuan-yiqi", SPE_SKILL);
        set_skill("sword",   SET_SKILL);  set_skill("fumo-jian",    SPE_SKILL);
        set_skill("unarmed", SET_SKILL);  set_skill("luohan-quan",   SPE_SKILL);
        set_skill("parry",   SET_SKILL);
        set_skill("shaolin-shenfa",   SPE_SKILL);
        set_skill("dodge",   SET_SKILL);
        set_skill("literate",SET_SKILL);
        map_skill("force",  "hunyuan-yiqi");
        map_skill("sword",  "fumo-jian");
        map_skill("unarmed","luohan-quan");
        map_skill("parry",  "fumo-jian");
        map_skill("dodge",  "shaolin-shenfa");
    
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );
    
        setup();
        carry_object("/clone/misc/cloth")->wear();  // 装备
        carry_object("/d/city/npc/obj/changjian")->wield();
}
int accept_fight(object me)
{
        command("say " + "这位"+RANK_D->query_respect(me) + "，我初涉江湖，不随便和人打架！\n");
        return 0;
}
