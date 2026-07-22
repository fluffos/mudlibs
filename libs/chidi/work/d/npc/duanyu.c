// duanyu.c 段誉
#include <ansi.h>
inherit BHNPC;
void create()
{
    set_name("段誉", ({"duan yu", "duan", "yu"}));
    set("nickname", GRN"大理王子"NOR);
    set("gender", "男性");
    set("age", 20);
    set("long", 
        "他是一个身穿青衫的年轻男子。脸孔略尖，自有一股书生的呆气。\n");
    set("attitude", "peaceful");
    
    set("str", 12);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("chat_chance", 15);
    set("chat_msg", ({
        "段誉叹了口气道：“唉……何时能再见到语嫣啊……”\n",
        (: random_move :),
    }));
    set("inquiry", ([
        "大理" : "大理是个好地方，山清水秀，风景宜人。\n",
        "王语嫣" : "唉，她心里只有她表哥，从来就没把我放在眼里。\n",
        "拜师" : "嗯....，我的师傅是老子、孔子和庄子，他们的学问我还没学全呢。\n",
    ]));
    set("jing", 200000);
    set("max_jing", 200000);
    set("jingli", 20000);
    set("max_jingli", 20000);
    set("qi", 2000000);
    set("max_qi", 2000000);
    set("neili", 4000000);
    set("max_neili", 4000000);
    set("jiali",2000);
    
    set("combat_exp", 500000000);
     
    set_skill("force", 100000);        // 基本内功
    set_skill("beiming-shengong", 100000); // 北冥神功
    set_skill("unarmed", 120000);      // 基本指法
    set_skill("sword", 120000);        // 基本剑法
    set_skill("six-finger", 120000);  // 六脉神剑
    set_skill("dodge", 150000);        // 基本躲闪
    set_skill("lingboweibu", 150000);      // 凌波微步
    set_skill("parry", 800000);         // 基本招架

    map_skill("force", "beiming-shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("parry", "six-finger");
    map_skill("unarmed", "six-finger");
    
    setup();
    
    carry_object("/d/city/obj/gangjian");
    carry_object("/clone/misc/cloth")->wear();
}
