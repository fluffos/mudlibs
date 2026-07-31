#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
     set_name(HIY"元宵使者"NOR, ({ "yuanxiao shizhe", "shizhe" }) );
         set("nickname", HIM"拿过汤圆奖励的人可以跟我要求补偿"NOR);
        set("gender", "男性" );
        set("age", 18);
         set("long",YEL"ask shizhe about 礼物\n"NOR);
        set("shen_type", 1);
        set("combat_exp", 999999999);
        set("str", 300);
        set("dex", 300);
        set("con", 300);
        set("int", 30);
        set("per", 30);
        set("attitude", "friendly");
        set("max_qi", 100000);
        set("neili", 100000);
        set("jingli",21000000);
        set("score", 100000);
        set("no_suck",1);

        set("inquiry", ([
                         "礼物" : (: ask_me :),
        ]));
        setup();
}

string ask_me()
 {
        object me = this_player();
       object obj;
        mapping fam; 
        
         if (! me->query("tygift/20050223") || me->query("tygift/2005_0223") )
                return "对不起只有吃过汤圆的人才能获取该补偿";
               else
        {
                 obj = new("/u/daniel/tangyuan");
                 obj->move(me);
                 me->delete("tygift/20050223");
                 me->set("tygift/2005_0223",1);
                 return "恭喜"+me->name()+"拿到正宗的汤圆了。\n";
        }
}

