inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR+"npc/¶ËÄ¾Á¼Ó¹";}
void create()
{
	set_name("¶ËÄ¾Á¼Ó¹", ({ "duanmu" }) );
	set("gender", "ÄÐÐÔ" );
	set("age", 22);
	set("long",
		"ÕâÎ»¶ËÄ¾Á¼Ó¹ÕýÐ¦ßäßäµØÃ¦Öø£¬»¹²»Ê±ÄÃÆð¹ÒÔÚ²±×ÓÉÏµÄÄ¨²¼²ÁÁ³¡£\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/guijia",

	}));


	set("area_name","¾°µÂÕò²ØÕä¸ó");
	set("area_file","/d/jindezheng/gudong-shop.c");

        setup();
carry_object("/clone/misc/cloth")->wear();        
}
void init()
{
::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");

}
