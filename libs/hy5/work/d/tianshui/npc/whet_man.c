// whet_man.c

inherit NPC;
 
void create()
{
        set_name("Ä¥µ¶ÈË", ({"whet man", "man"}));
        set("long", @TEXT
ÒÔ°ïÈËÄ¥²Ëµ¶ÎªÉú¡£
TEXT
	);
	set("gender","ÄÐÐÔ");
	set("age",37);
	set("con",30);
	set("str",20);
	set("combat_exp",1300);
        set("attitude","peaceful");
	set("chat_chance",5);
	set("chat_msg", ({
	"Ä¥µ¶ÈËº°×Å£º¡°Ä¥²Ëµ¶à¶£¡Ä¥¼ô×ÓÄ¥µ¶à¶£¡¡±\n",
	(: random_move :),
}) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/m_stone");
}