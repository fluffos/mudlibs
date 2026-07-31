inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "ÈýÇåºþ");
        set("long",
"[1;32mºþË®Çå³ºÍ¸Ã÷£¬²»Ê±¿ÉÒÔ¿´µ½¼¸Î²ÓãÌøÉÏË®Ãæ¡£ºþË®¾¡Í·ÊÇ\n"
"Ò»¸ö´óÆÙ²¼¡£ÔÚÕâÀï¿ÉÒÔÌýµ½ÆÙ²¼´ÓÉ½ÉÏÖ±³å¶øÏÂ£¬·¢³öµÄºäºäÀ×Éù¡£ºþ\n"
"±ßÒ»¿é¾ÞÊ¯£¬ÉÏÐ´£¢ÈýÇåºþ£¢£¬ºþÖÐÓÐÒ»Ò¶±âÖÛ¡£\n"
);
        set("exits", ([ 
  "north" : __DIR__"village",
  "east" : __DIR__"lake1",
]));
        set("resource/water",1);
         set("no_magic", 1);
	setup();
}
void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "Ò»Ò¶±âÖÛ»º»ºµØÊ»ÁË¹ýÀ´£¬ô¹¹«½«Ò»¿éÌ¤½Å"
                    "°å´îÉÏµÌ°¶£¬ÒÔ±ã³Ë¿Í\nÉÏÏÂ¡£\n", this_object() );
                message("vision", "ô¹¹«½«Ò»¿éÌ¤½Å°å´îÉÏµÌ°¶£¬ÐÎ³ÉÒ»¸öÏòÉÏ"
                    "µÄ½×ÌÝ¡£\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "Ö»ÌýµÃºþÃæÉÏÒþÒþ´«À´£º¡°±ð¼±Âï£¬"
                    "Õâ¶ùÕýÃ¦×ÅÄÅ¡­¡­¡±\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "°¶±ßÒ»Ö»¶É´¬ÉÏµÄÀÏô¹¹«ËµµÀ£ºÕýµÈ×ÅÄãÄØ£¬ÉÏÀ´°É¡£\n",
            this_object() );
}
void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "ô¹¹«°ÑÌ¤½Å°åÊÕÁËÆðÀ´£¬Öñ¸ÝÒ»µã£¬±âÖÛÏòºþÐÄÊ»È¥¡£\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "ô¹¹«°ÑÌ¤½Å°åÊÕÆðÀ´£¬ËµÁËÒ»Éù¡°×øÎÈà¶¡±£¬"
            "Öñ¸ÝÒ»µã£¬±âÖÛÏò\nºþÐÄÊ»È¥¡£\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}
void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", __DIR__"spirit9");
        message("vision", "ô¹¹«Ëµ¡°µ½À²£¬ÉÏ°¶°É¡±£¬Ëæ¼´°ÑÒ»¿éÌ¤½Å°å"
            "´îÉÏµÌ°¶¡£\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","ô¹¹«°ÑÌ¤½Å°åÊÕÆðÀ´£¬°Ñ±âÖÛÊ»ÏòºþÐÄ¡£\n", room);
        room->delete("yell_trigger"); 
    }
}
int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "´¬¼Ò";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$NÊ¹³ö³ÔÄÌµÄÁ¦Æøº°ÁËÒ»Éù£º¡°" + arg + "¡±\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$NÎüÁË¿ÚÆø£¬Ò»Éù¡°" + arg + "¡±£¬ÉùÒôÖÐÕýÆ½ºÍµØÔ¶Ô¶´«"
            "ÁË³öÈ¥¡£\n", this_player());
    else
        message_vision("$N¹Ä×ãÖÐÆø£¬³¤Ð¥Ò»Éù£º¡°" + arg + "£¡¡±\n",
            this_player());
    if( arg=="´¬¼Ò")
    { 
     if(!this_player()->query_temp("m_success/³õ¼¶"))          return notify_fail("ÄãÊÇÔõÃ´À´µÄ£¿Î×Ê¦×¥µÄ£¿ÄÇ¿É²»ºÃ¡£\n"); 

     if(!this_player()->query_temp("m_success/»ÃÓ°"))          return notify_fail("ÄãÃ»ÄÜÇ×Á¦½â¿ª·âÓ¡£¬²»ÄÜ¶ÉÄã¹ýÈ¥ÄØ¡£\n"); 

     if(!this_player()->query_temp("m_success/ÄõÁú"))          return notify_fail("Äã²Î¼ÓÍÀÁúÁËÂð£¿»òÕßÄãÃ»Ç×ÊÖÉ±ÁËËü£¿ÕâÑùÊÇ²»ÐÐµÄ¡£\n"); 
        check_trigger();
        return 1;
    }
    else
        message_vision("ºþÃæÉÏÔ¶Ô¶´«À´Ò»Õó»ØÉù£º¡°" + arg +
            "¡«¡«¡«¡±\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}


