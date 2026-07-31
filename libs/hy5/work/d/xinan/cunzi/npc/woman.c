//Writen by lnwm (May.28.1997)
//woman.c

inherit NPC;

void create()
{
        set_name("¸¾ÈË", ({ "fu ren","woman" }) );
        set("gender", "Å®ÐÔ" );
        set("age", 35);
        set("long",
"Ò»¸öµäÐÍµÄËÄ´¨ÏçÏÂÅ®ÈË£¬×ÜÊÇ¿´ÆðÀ´Ã¦Ã¦ÂµÂµµÄ¡£\n"
        );
        set("combat_exp", 1000);

        set("inquiry", ([
        "º¢×Ó"          : "ÎÒÓÐÒ»¸öÄÐº¢ºÍÒ»¸öÅ®º¢",     
        "ÄÐº¢"          : "¾ÍÎÒÄÇÐ¡×ÓÌÔÆø£¬Äã¿´£¬µ½ÏÖÔÚ»¹Ã»ÓÐ»ØÀ´",
        ]) );

        set("chat_chance", 10);
        set("chat_msg",({                             
"Å®ÈË·ÅÏÂÊÖÀïµÄ»î£¬¿´ÁË¿´ÍâÃæËµ£ºÎÒÄÇ¸öÐ¡×ÓÔõÃ´»¹²»»ØÀ´¡£\n",
"Å®ÈË·ÅÏÂÊÖÀïµÄ»î£¬¿´ÁË¿´ÍâÃæ£¬×ªÍ·¶ÔÕÉ·òËµ£ºÄãÒ²²»³öÈ¥ÕÒÕÒ¡£\n",
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
            remove_call_out("greeting");
            call_out("greeting", 2, ob);
        }
}                            

void greeting(object ob)
{
    object obj;
    if( !ob || environment(ob)!= environment(this_object()) )
        return;
        write("\nÅ®ÈË¿´¼ûÄã½øÀ´£¬Ð¦ÁËÐ¦£¬Ëµ:'Ëæ±ã×ø'.\n");
        write("\nÅ®ÈËËµ£ºÇë³¢³¢ÎÒÃÇ×Ô¼º²úµÄ²èÒ¶¡£\n");
/*
    if( objectp(present("hua cha",ob) ) && !me->query_temp("marks/lnwm/»¨²")è)
    {
        write("\nÅ®ÈËµÝ¸øÄãÒ»±­Çå²è¡£\n");
        obj = new( __DIR__ "obj/tea");
            obj -> move(ob);
        
    }
*/
}                                                     




