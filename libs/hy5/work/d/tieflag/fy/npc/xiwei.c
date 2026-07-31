 //TIE @ FY3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ÇÕÎÀ", ({ "qinwei", "wei" }) );
        set("long",
                "Ò»ÈºÈçÀÇËÆ»¢µÄÇÕÅÉ»¤ÎÀ\n");
        set("cor",20);
        set("attitude", "heroism");
        set("combat_exp", random(500000)+1000000);
        set_skill("unarmed", 70+random(200));
        set_skill("spear", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", 30+random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"ÇÕÎÀºÅµÀ£º·çÆ½£®£®£®£®£®ÀË¾²£®£®£®£®£®£®\n"
        }) ); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changqiang")->wield();
}      
