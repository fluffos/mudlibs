#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ÖµÇÚ±ø", ({ "solider", "garrison" }) );
        set("long",
"ÕâÊÇ¸öÕıÔÚÖ´ĞĞÊØ³ÇÈÎÎñµÄÖµÇÚ±ø£¬ËäÈ»ºÍĞí¶àÎäÁÖÈËÎï±ÈÆğÀ´£¬ÖµÇÚ±øÃÇµÄÎä¹¦\n"
"ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓĞ×éÖ¯¡¢ÓĞ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕĞÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕĞÈÇËûÃÇ¡£Èç¹ûÄãÀ´Ñ²³Ç,¿ÉÎÊËûfindbaogao. [37m\n");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
        set("combat_exp", 50000+random(300000));
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

void init()
{
	add_action("do_xunchen", "findbaogao");
}

int do_xunchen()
{
        object *ob_list;
  	  object obn;
        int i;
        object me = this_player();
        if (present("xunchen1", me))  
         {
               message_vision("$N¶Ô×Å$nËµ£ºÄãÉíÉÏ²»ÊÇÒÑ¾­ÓĞÕâÀïµÄÑ²³Ç±¨¸æÁËÂğ!!\n", this_object(), me);
               return 1;
         }
        else
        obn=new(__DIR__"xunchen1");
        obn->random(1);
        obn->move(me);
        command("say Ñ²³Ç±¨¸æ£¬ÄãÄÃÈ¥¸øÍõ´óÈË°É!");
        return 1;
}
//}

