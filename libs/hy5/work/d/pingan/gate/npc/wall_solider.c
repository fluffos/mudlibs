
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ÖµÇÚ±ø", ({ "wall solider", "solider" }) );
        set("long",
"ÕâÊÇ¸öÕýÔÚÖ´ÐÐÊØ³ÇÈÎÎñµÄÖµÇÚ±ø£¬ËäÈ»ºÍÐí¶àÎäÁÖÈËÎï±ÈÆðÀ´£¬ÖµÇÚ±øÃÇµÄÎä¹¦\n"
"ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓÐ×éÖ¯¡¢ÓÐ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕÐÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕÐÈÇËûÃÇ¡£ [37m\n");
        set("attitude", "heroism");
        set("str", 27);
	set("vendetta", "authority");
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000);


        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "ÖµÇÚ±øºÈµÀ£º»¹²»¿ì·ÅÏÂÎäÆ÷ÊøÊÖ¾Í¸¿£¿\n",
                "ÖµÇÚ±øºÈµÀ£º´óµ¨µóÃñ¾¹¸Ò¾Ü²¶£¿·´ÁË£¡·´ÁË£¡\n"
        }) );

        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}
