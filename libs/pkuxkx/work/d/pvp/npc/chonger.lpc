//chonger.c for pk room by becool 2008-11-21
#include <ansi.h>
inherit FAMILY_NPC;
int ask_pvp();
int ask_gem();
void create()
{
        set_name(HIR"虫二"NOR, ({"chong er","chonger","chong"}) );
        set("nickname",HIW"笑面佛"NOR);
        set("gender", "男性");
        set("age", 30);
        set("long",
            "前胸一个“虫”字，后背一个“勇”字，这一定就是虫二大侠了。\n");
        set("combat_exp",900000000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("apply/attack", 500+random(500));
        set("apply/defense", 500+random(500));
        set("max_qi", 70000);
        set("max_jing", 70000);
        set("max_neili", 70000);
        set("neili", 70000);
        family_skill(this_object(), "huashan2", 500+random(250), 1);
        set("chat_chance_combat", 80);
        set("no_get",1);
        set("chat_chance",3);
        set("chat_msg", ({
         HIR"虫二"NOR"语重心长的对你说到：“论武功，我不行；论容貌，你不行！”\n",             
         HIR"虫二"NOR"突然捂着鼻子大喊：“是谁？谁放的屁！”。\n",
         HIR"虫二"NOR"从怀里取出一张照片深情的望着，你凑过头一看，发现正是自己的裸照。\n",                  
        }));
        set("inquiry",([
        "pvp" : (: ask_pvp :),
        "pk" : ( : ask_pvp :),
        "格斗" : ( : ask_pvp :),
        "gem" : ( : ask_gem :),
        "宝石" : ( : ask_gem :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}
int ask_pvp()
{
        object me,room;
        object ob,gem;
        me = this_player();
        if (  !objectp(gem = present("gem", me)) )
        {
                command("shrug");
                command("say " + "没有宝石不能入场！\n");
                return 1;
        }
        else
        {
                command("say " + "好吧，看你很经打的样子，去吧，单挑去东边，群殴去西边。\n");
                command("say " + "记住，一旦开始格斗，就不再有退路，胜者有权搜刮死者身上所有东西。\n");
                return 1;
        }
}
int ask_gem()
{
        command("say " + "宝石就是每次格斗的赌注，不要给我，带在身上就行。宝石的大小种类由格斗双方自行协商。\n");
        return 1;
}
