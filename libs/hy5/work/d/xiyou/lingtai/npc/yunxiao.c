// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ÔÆÏö", ({"yun xiao", "yun"}));
        set("gender", "ÄĞĞÔ" );
        set("age", 33);
        set("long",
"·½´çÉ½ÈıĞÇ¶´µÚÈı´úµÜ×ÓÖĞµÄ½Ü³öÈËÎï¡£
ÔÚ³¡±ß×ªÀ´×ªÈ¥·¢Ğ©ÀÎÉ§¡£\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("·½´çÉ½ÈıĞÇ¶´", 3, "µÜ×Ó");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
      
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
}


void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            "ÔÆÏö´òÁË¸öÅçÌç£®\n",
            "ÔÆÏöÉÏÉÏÏÂÏÂ´òÁ¿ÁËÄã¼¸ÑÛ¡£\n",
	    "ÔÆÏöºßÁËÒ»Éù¡£\n"
        }) );
}

ÿ
