//whuan
//阿秀的丫鬟
#include <ansi.h>
string ask_axiu();  
inherit NPC;
void create()
{
        set_name(GRN"丫鬟"NOR, ({"ya huan", "ya","huan",}));
        set("long","她是阿绣的丫鬟，服侍阿绣的日常起居。" );
        set("gender", "女性");
        set("attitude", "friendly");
        set("age", 18);
        set("shen_type",1);
        set("str", 13);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 300);
        set("eff_qi", 100);
        set("max_jing", 100);
        set("combat_exp", 800);
        set_skill("dodge", 20);
        set_skill("parry", 20); 
        set_skill("cuff", 40);
         set("inquiry",([  
                  "小姐"  : (: ask_axiu :),
                  "阿绣"  : (: ask_axiu :),
                  "here"  : "这里是小姐的闺房，你跑进来干什么？",
                  "rumors": "你问错人了，我对江湖上的传闻可不了解。",
          ]));

        setup();

}
string ask_axiu()
{       object me;
        me=this_player();
        me->set_temp("jinwudao/ask_axiu1", 1);  
        return "有个无耻之徒想要非礼小姐，我上前阻拦，他把我打晕了。\n小姐现在不见了，这可如何是好啊？";
}
