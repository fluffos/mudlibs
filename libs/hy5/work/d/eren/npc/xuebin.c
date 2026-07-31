#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;  
int kill_him(); 
void create()
{ 
        set_name("薛斌",({"xuebin"}));
        set("title",YEL"好汉庄老庄主"NOR);
        set("long", "薛斌抬起手掩住嘴，轻轻地咳嗽着，阳光照在他身上，虽然还只不过是刚升起来的
阳光，但在他感觉中，却好像是夕阳。他自己却连夕阳无限好的时光都已过去，他
的生命已到了深夜。。\n");
        set("age",59);
        set("combat_exp", 5500000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "白天羽" : (: kill_him :),
        ]));
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//         defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        

        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
int kill_him()
{
        object me, another;
        
        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"薛斌现在没空回答你。\n");
                return 1;
                }
        message_vision(CYN"$N道：“那次我们做的事，虽然不够光明磊落，但现在若回到十九年前，我
还是会再同样做的。。。。因为白天羽实在不是个东西。”\n",this_object());
        return 1;
}     
