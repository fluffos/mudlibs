
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
        set_name("¼§ÁéÑà", ({ "ji lingyan", "ji" }) );
        set("gender", "Å®ĞÔ" );
        set("age", 18);
        set("title",WHT "ÇÉÊÖÎŞË«"NOR);
        set("long",
"³¤·¢¹âÁÁÈç¾µ£¬°×ÅÛÓë³¤·¢Ëæ·ç¶øÎè£¬Ò»ÕÅ²Ô°×µÄÁ³£¬ÒÔ¼°Ò»Ë«ÃÀÀö\n¶øÃÔÃ£µÄÑÛ¾¦¡£ËıÓĞË«½à°×ÈçÓñµÄÊÖ£¬ÄãºÜÄÑÏëÏó¾ÍÊÇÕâË«ÊÖ£¬×ö³ö\nÁË·çÔÆ³Ç×îÃÀÀöµÄÒÂ·ş¡£\n");
        set("combat_exp", 50000);
    set("str", 20);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("inquiry", ([
                "Ç®°ü" : (: tell_him :),
                 ])); 
	set("vendor_goods", ({
                __DIR__"obj/m_cloth1",
                __DIR__"obj/g_gloves",
                __DIR__"obj/m_cloth2",
                __DIR__"obj/m_cloth3",
                __DIR__"obj/m_cloth4",
                __DIR__"obj/m_boots1",
                __DIR__"obj/m_boots2",
                __DIR__"obj/w_skirt1",
                __DIR__"obj/w_skirt2",
                __DIR__"obj/w_skirt3",
                __DIR__"obj/w_skirt4",
                __DIR__"obj/w_girth1",
                __DIR__"obj/w_girth2",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
                case 0:
                        say( " ¼§ÁéÑà¹Å¹ÖµØĞ¦ÁËĞ¦£ºÕâÎ»"
                                + RANK_D->query_respect(ob)
                                + "£¬ÄãÓĞÃ»ÓĞ¶ªÁËÇ®°ü£¿ \n");
                        break;
                case 1:
                        say( " ¼§ÁéÑàĞ¦×ÅµÀ£ºÕâÎ»"
                                + RANK_D->query_respect(ob)
                                + "£¬ÎÒÃÇÕâĞ©ÒÂ·şµÄÊÖ¹¤¿ÉÊÇÌìÏÂÎŞË«µÄ£¬¡£¡£¡£ \n");
                        break;
                                case 2:
                        say ( " ¼§ÁéÑàĞ¦×ÅµÀ£ºÕâÎ»"
                                + RANK_D->query_respect(ob)
                                + "£¬ÕâÀïµÄ¶«Î÷¾ø¶ÔÄÜÈÃÄãÂúÒâ¡£¡£¡£ \n");
                       break;
        }
} 
                                  
int tell_him()
{
    object me;
    me =this_player();
        
    tell_object(me,"¼§ÁéÑàÌìÕæµØÕ£ÁËÕ£ÑÛ¾¦£¬¡¸ÎÒÇ°Á½ÌìÔÚÇ°ÃæµÄÉ½ÁÖÀï¼ñµ½¸öÆÄ¾«ÖÂµÄÇ®°ü£¬Èç¹ûÄãÒª£¬ÄÃÈş°ÙÁ½½ğ×ÓÀ´°É¡£¡¹\n");
               
    return 1;
} 

int accept_object(object who, object ob)
{
	    object obj;
                if( (int)ob->value() >= 3000000 ) {
                        say( name()+"¸ßĞËµÃÌøÁËÆğÀ´£¬È»ááĞ¡ĞÄµØ½«"+ob->name()+"·ÅÈë»³ÄÚ¡£\n");
                    message_vision(NOR"$N´ÓÒÂÎïÖĞÕÒ³öÒ»¸öÇ®°ü¸ø$n¡£\n\n"NOR, this_object(),this_player());

                    //    say ("\n$N´ÓÒÂÎïÖĞÕÒ³öÒ»¸öÇ®°ü¸ø$n¡£\n",this_object(),this_player());¡
                    obj = new(__DIR__"obj/notecase");
                    obj->move(this_player());


                        return 1;
                } else {
                        command("say ÕâĞ©Ç®£¬»¹²»¹»ÎÒ×ö¼şÏñÑùµãµÄÒÂ·şÄØ¡£");
                        return 0;
                }
        return 0;
}  