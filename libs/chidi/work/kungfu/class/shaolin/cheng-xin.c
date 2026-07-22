// Npc: /kungfu/class/shaolin/cheng-xin.c
// Date: YZC 96/01/19
inherit BHNPC;
inherit F_MASTER;
void create()
{
    set_name("澄心", ({
        "chengxin luohan",
        "chengxin",
        "fuhu",
        "luohan",
    }));
    set("long",
        "他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
        "太阳穴高高鼓起，似乎身怀绝世武功。\n"
    );
    set("nickname", "伏虎罗汉");
    set("gender", "男性");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 60);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
    set("max_qi", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 100);
    set("combat_exp", 200000);
    set("score", 5000);
set_skill("force",180);
set_skill("hunyuan-yiqi",180);
set_skill("dodge",180);
set_skill("shaolin-shenfa",180);
set_skill("unarmed",180);
set_skill("qianye-shou",180);
set_skill("parry",180);
set_skill("buddhism",180);
set_skill("literate",180);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "qianye-shou");
    map_skill("parry", "qianye-shou");
    
    create_family("少林派", 37, "弟子");
    setup();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
#include "/kungfu/class/shaolin/cheng.h"
