//dadi.c 任务使
// [lsg 1999/11/24]

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
#include "../teamjob.c"
void create()
{
        set_name("任务使", ({ "renwu shi", "shi", "renwu"}));
        set("title", HIC"神龙教"NOR);
        set("gender", "男性" );
        set("age", 102);
        set("str", 50);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("long", 
"一位的任务使。专门负责给本派弟子各种任务.\n");
        set("combat_exp", 50000000);
        set("shen_type", 1);

        set("attitude", "peaceful");
        set("max_qi", 35000);
        set("max_jing", 10000);
        set("neili", 55000);
        set("max_neili", 55000);
        set("jiali", 200);
        set("mp","神龙教");
        set_skill("force", 300);
        set_skill("zhemei-shou", 300);
        set_skill("unarmed", 500);
        set_skill("xiantian-qigong", 500);

         map_skill("unarmed","zhemei-shou");
       map_skill("force","xiantian-qigong");
        
        set("inquiry", ([
              "job"  : "本派弟子可以在我这用quest领任务啦，我不会为难你们的。\n",       
 	      "攻打门派"  : (: ask_jianxi :),
 	      "teamjob"  : (: ask_jianxi :),
 	      "奖励"  : (: ask_gift :),
 	      "gongxian"  : (: ask_gift :),
]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();

}
