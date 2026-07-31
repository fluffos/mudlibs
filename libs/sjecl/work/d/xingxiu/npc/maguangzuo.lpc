// maguangzuo.c 马光佐

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("马光佐", ({ "ma guangzuo", "ma", "guangzuo" }) );
        set("gender", "男性");   
        set("age", 37);
        set("long","身高八尺，粗手大脚，脸带傻笑，双眼木然。\n");
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("attitude", "heroism");
        set("unique", 1);

        set("str", 28);
        set("con", 26);
        set("int", 20);
        set("dex", 24);
        set("per", 13);

        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 900);
        set("eff_jingli", 600);
        set("max_neili", 900);        

        set_skill("force", 100);  
        set_skill("yijin-jing", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("strike", 100);
        set_skill("cuff", 100);
        set_skill("weituo-zhang", 100);
        set_skill("parry", 100);
        set_skill("luohan-quan", 100);
        set_skill("shaolin-shenfa", 100);
        map_skill("parry", "luohan-quan");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("force","yijin-jing");
        map_skill("strike", "weituo-zhang");
        prepare_skill("strike", "weituo-zhang");
        prepare_skill("cuff", "luohan-quan"); 

        setup();        
        carry_object("/clone/misc/cloth")->wear();
}
