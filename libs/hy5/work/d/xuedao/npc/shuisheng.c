// shuidai.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("水笙", ({ "shui sheng", "shui", "sheng" }));
       set("long", 
       "她二十岁上下年纪，白衫飘飘，
左肩上悬着一朵红绸制的大花，脸色微黑，相貌却极为俏丽。\n");
       set("gender", "女性");
       set("nickname", HIW"银铃女侠"NOR);
       set("age", 20);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 30);
       set("int", 30);
       set("con", 30);
       set("dex", 30);
       set("per", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 500000);
       set("shen_type", 1);

       set_skill("force", 80);
       set_skill("huashan-neigong", 80);
       set_skill("dodge", 80);
       set_skill("huashan-shenfa", 80);
       set_skill("strike", 80);
       set_skill("huashan-zhangfa", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("huashan-jianfa", 80);
       set_skill("literate", 80);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "huashan-shenfa");
       map_skill("strike", "huashan-zhangfa");
       map_skill("parry", "huashan-jianfa");
       map_skill("sword", "huashan-jianfa");

       set("inquiry", ([
              "落花流水": "你不会不知道江南四侠的大号吧？冷月剑水岱就是我的父亲。",
              "血刀恶僧": "这个家伙自称血刀老祖，其实无恶不作，我看到他一定一剑刺死他。",
       ]));

       setup();
       carry_object("/clone/weapon/changjian")->wield();
}
void init( )
{
        call_out("hunting",300);
}

void hunting()
{
object ob=this_object();
if (this_player())
{
message("vision", HIW"只听得叮玲玲，叮玲玲一阵铃声，一骑马向远处跑走了。\n"NOR, this_player());
}
destruct(ob);
}