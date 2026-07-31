inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "ÉîÌ¶");
        set("long",
"[1;32mÖÜÎ§Ò»Æ¬ºÚ°µ£¬´ó¸ÅÒÑ¾­ÉîÈëµØµ×ÁË°É¡£½å×ÅÌ¦Şº·¢³öµÄÓÄ\n"
"ÓÄÁ×¹â£¬¿ÉÒÔ¿´µ½Ç°·½²»Ô¶´¦ÓĞÒ»¸öÉîÌ¶(tan)£¬º®Æø±ÆÈË¡£\n"
);
        set("exits", ([ 
       "eastup" : __DIR__"spirit6",
        ]) );


        set("no_magic", 1);
	setup();
}


void init()
{
        add_action("do_look", "look");
        add_action("do_approach", "approach");
}

int do_look(string arg)
{
        object me;
        object room;
        me = this_player();
        if(!arg || arg != "ÉîÌ¶" && arg != "tan" ) return 0;
        switch ( random (2)) {
                case 0:
tell_object(me,"Ì¶±ß³¤ÂúÁËÌ¦Şº£¬»¹ÊÇ²»Òª¿¿£¨£á£ğ£ğ£ò£ï£á£ã£è£©µÄÌ«½ü¡£\n"); 
                break;
                case 1:
message_vision("$NÌ½Í·ÏòÌ¶ÀïÍûÈ¥¡£ \n", me); 
tell_object(me,"ºÚ²»Â¡ßËµÄÌ¶Ë®Éî²»¼ûµ×¡£ \n");
                break;
        }


        return 1;
}
int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
        if(!arg || arg != "ÉîÌ¶" && arg != "tan" ) return 0;
        switch ( random (3)) {
                case 0:
message_vision("$N×ß½üÉîÌ¶Ì½Í·ÏòÀïÍûÈ¥¡£ \n", me); 
tell_object(me,"Ì¶Ë®Éî²»¼ûµ×£¬²»¹ıÄãËÆºõ¿ÉÒÔÌıµ½µ×ÏÂÁ÷Ë®µÄÉùÒô¡£ \n");
                break;
                case 1:
message_vision("$N×ß½üÉîÌ¶Ì½Í·ÏòÀïÍûÈ¥¡£°¥Ñ½£¡Ò»²»Ğ¡ĞÄµôÁË½øÈ¥£¡\n", me); 
message_vision("$NµÄÍ·×²ÔÚÌ¶±ÚÉÏ£¬Ò»ÏÂ×Ó»èÁË¹ıÈ¥£¡\n", me); 
                call_out("be_saved",8);
                me->unconcious();
                room = find_object(__DIR__"spirit10");
                 if(!objectp(room)) room=load_object(__DIR__"spirit10");
                me->move(room);
                break;
                case 2:
message_vision("$N×ß½üÉîÌ¶Ì½Í·ÏòÀïÍûÈ¥¡£°¥Ñ½£¡Ò»²»Ğ¡ĞÄµôÁË½øÈ¥£¡\n", me);
              room = find_object(__DIR__"underwater");
                if(!objectp(room)) room=load_object(__DIR__"underwater");
                me->move(room);
                break;
        }

        return 1;
}

int be_saved()
{   
            object me;            me=this_player();

            me->remove_call_out("revive");
            me->revive();
            me->reincarnate();
message_vision("$NÂıÂıÇåĞÑ¹ıÀ´£¬·¢ÏÖ×Ô¼ºÔÚÒ»¼äĞ¡ÎİÖĞ£¡\n", me); 
message_vision("Ò»¸öÃÀÀöµÄ¾«Áé×åÅ®×Ó¿´¼û$N»Ö¸´ÁËÖª¾õ£¬¹ØÇĞµØ×ßÁË¹ıÀ´£¡\n", me);
           return 1;
}

