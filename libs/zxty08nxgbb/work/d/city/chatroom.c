inherit ROOM;
void create()
{
        set("short", "´óéÅÊ÷ÉÏ");
        set("long", @LONG
ÈËËµ´óÊ÷µ×ÏÂºÃ³ËÁ¹£¬Ã»Ïëµ½´óÊ÷ÉÏ¸üÁ¹¿ì¡£Õâ¿Ã´óéÅÊ÷Õæ²»À¢ÎªÇ§ÄêÉñÄ¾£¬
ÖÁ½ñÈÔÂÌÒ¶·±Ã¯¡£¾İËµÕâÀïµÄÊ±¼äÊÇ¶³½áµÄ£¬Òò´Ë±ã³ÉÎªĞí¶àÍæ¼ÒÁÄÌìµÄµØ·½¡£
ÕâÀï°Ú×Å¼¸ÕÅÓÃéÅÊ÷¸ù×öµÄÒÎ×Ó£¬ÖĞ¼äÓÃ¼¸¸ùéÅÊ÷Ö¦´îÔÚÒ»Æğ£¬ËãÊÇÒ»¸ö²è¼¸ÁË¡£
µ±ÄãÌ§Í·ÍùÉÏ¿´µÄÊ±ºòËÆºõÓĞ¸öÓ°ÔÚÊ÷ÉÒÖ®¼äÒÆ¶¯£¬²»¹ıÒ²ĞíÊÇ·ç´µ¶¯ËùÔì³ÉµÄ
´í¾õ¡£

[1;33mÍæ¼ÒÈçĞè×Ô½¨·¿¼äÇëHelp here[2;37;0m

LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
        "down": __DIR__"guangchang",
        "up"  : __DIR__"chatroom2",
//         "east"  : "/d/pk/entry",
         "north"  : __DIR__"xxci1",
          "south"  : "/d/daniel/vip/viproom",
        ]));
        set("objects", ([
       "/d/daniel/npc/paimai": 1,
        "/d/zjb/zuqiu": 1,
//        "/clone/misc/bingqipu" : 1,
]));
        set("no_fight",1);
         set("no_magic",1);
          set("valid_startroom","1");
        set("freeze",1);
        setup();
        call_other("/d/board/comm_b", "???");
}
void init()
{
    add_action("no_action", "shot");
        add_action("do_help", "help");
        add_action("do_chathere", "chathere");
        add_action("do_enter", "enter");
        add_action("do_newchat", "newchat");
//      if (wizardp(this_player())) return;
    add_action("do_jump","tiao");
add_action("discmds",({"sleep","lianjia","respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","xi","learn","kill","steal","xue","conjure","fight","hit","xi","perform","prcatice","scribe","tuna","surrender"}));
    add_action("do_climb", "climb");
}
int no_action(string str)
{
       write(HIY"Ê÷ÉÏ±ğÂÒÀ´£¡£¡£¡ \n"NOR);
       return 1;
}
int discmds()
{
        tell_object(this_player(),"ÏÖÔÚÄã»¹ÊÇ×¨ĞÄÁÄÌì°É£¡\n");
        return 1;
}
int do_help(string arg)
{
        if (! arg || arg != "here")
                return 0;
        else {
                write(@LONG

        ÕâÀï¿ÉÒÔÊ¹ÓÃµÄ×¨ÃÅÃüÁîÓĞ£º
    enter        ½øÈëÒ»¸öÁÄÌìÊÒ
    chathere     ²éÔÄÕâÀïµÄÁÄÌìÊÒ
    newchat      ½¨Á¢ĞÂµÄÁÄÌìÊÒ

LONG
);
                return 1;
        }
}

int do_climb(string arg)
{

    object me;
    me=this_player();
        if( !arg || arg!="up") return notify_fail("ÄãÒªÍùÄÄ¸ö·½ÏòÅÀ£¿\n");

    if ((string)me->query("gender")!="Å®ĞÔ")
    message("vision",
        me->name() + "Õ½Õ½¾¤¾¤µØ¾¾×¡Ê÷¸É£¬Æ¨¹ÉÒ»Å¤Ò»Å¤µØ¼ÌĞøÍùÉÏÅÀ¡£\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "ÏóÏÉ×Ó°ã¼ÌĞøÏòÉÏÆ®È¥£¬×ªË²¼´ÊÅ¡£\n",
        environment(me), ({me}) );
     else message("vision",
        me->name() + "Õ½Õ½¾¤¾¤µÄ×¥×¡Ê÷¸ÉÍùÉÏÅÀÈ¥¡£\n",
        environment(me), ({me}) );
     me->move(__DIR__"chatroom2");
     if((string)me->query("gender")!="Å®ĞÔ")
        message("vision",
        me->name() + "Æø´­ĞêĞêµØÅÀÁËÉÏÀ´¡£\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    
        message("vision","Ò»ÕóÇåÏã·ÉÀ´£¬Äã¶¨ÑÛÒ»¿´£¬"+
        me->name() + "ÒÑ¾­æÃæÃÓñÁ¢ÔÚÄãÑÛÇ°¡£\n",
        environment(me), ({me}) );   
  
   else 
        message("vision", me->name() + "Õ½Õ½¾¤¾¤µØ´ÓÏÂÃæÅÀÁËÉÏÀ´¡£\n", environment(me), ({me}) );             
    return 1;
}   
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("ÄãÒªÍùÄÄÌø£¿\n");
      if (me->is_fighting() || me->is_busy() )  return notify_fail("ÄãÕıÃ¦×ÅÄØ£¡\n");
        message("vision",
                me->name() + "ÓÌÔ¥ÁËÒ»ÏÂ£¬¹ÄÆğÓÂÆø£¬ÌøÁËÏÂÈ¥¡£\n¡°àØ¡±µÄÒ»¾ŞÏì£¬ËÆºõÌıµ½"+me->name()+"²Òº¿ÁËÒ»Éù!\n",
                environment(me), ({me}) );
                me->move(__DIR__"guangchang");
        message("vision",
                me->name() + "²Òº¿Ò»Éù£¬´ÓÊ÷ÉÏµôÁËÏÂÀ´¡£\n",
                environment(me), ({me}) );
        return 1;
}
int valid_leave(object me, string dir)
{

        if ( dir=="down" && !wizardp(me))
        return notify_fail("ÅÌ¸ù²»ÖªµÀ¸øÄÄ¸ö»µ¼Ò»ï¿³¶ÏÁËâ£¬¿´À´Ö»ÄÌøÅÀ(tiao)ÏÂÈ¥£¡\n");
         if ( dir=="up" && !wizardp(me))
        return notify_fail("ÕâÀïÃ»·¨Ö±½Ó×ß£¬¿´À´ÄãÖ»ÄÜÅÀ(climb)ÉÏÈ¥£¡\n");

        else return 1;
}
int do_chathere()
{
        object me = this_player();
        object *chatrooms, *player;
        string msg;
        int i;

        chatrooms = children("/d/city/newchat");
        chatrooms = filter_array(chatrooms, (: $1->query("owner") && ! $1->query("secret") :));

        if (! sizeof(chatrooms)) 
                return notify_fail("ÕâÀïÃ»ÓĞÈÎºÎ¿ÉÒÔ½øÈëµÄÁÄÌìÊÒ¡£\n");

        msg = "ÔÚÕâÀï¿ÉÒÔ½øÈëµÄÁÄÌìÊÒÓĞ£º\n";
        msg += HIC "¡Ô" HIW "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤" HIC "¡Ô\n" NOR;

        for (i = 0; i < sizeof(chatrooms); i++)
        {
                player = all_inventory(chatrooms[i]);
                player = filter_array(player, (: userp($1) :));

                msg += sprintf("%s   %-25s ÏÖÔÚ£º%dÈË\n", (chatrooms[i]->can_into(me) ? HIC : HIR), 
                        chatrooms[i]->query("short"), sizeof(player));
        }
        msg += HIC "¡Ô" HIW "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤" HIC "¡Ô\n" NOR;

        write(msg);
        return 1;
}

int do_enter(string arg)
{
        object me = this_player();
        object room, *chatrooms;
        int i;
        
        if (! arg) return notify_fail("ÄãÒª½øÈëÊ²Ã´ÁÄÌìÊÒ£¿\n");

        chatrooms = children("/d/city/newchat");
        for (i = 0; i < sizeof(chatrooms); i++)
        {
                if (chatrooms[i]->query("owner") == arg)
                {
                        room = chatrooms[i];
                        break;
                }
        }
        if (! objectp(room) || room->query("secret") && ! room->can_into(me))
                return notify_fail("Ã»ÓĞÕâ¸öÁÄÌìÊÒ¡£\n");
        else
        {
                 message_vision("$N" NOR "¿ì²½Ïò"HIC + room->query("short")
                                  +NOR"×ßÈ¥¡£\n", me);
                if (! room->can_into(me) && ! wizardp(me))
                {
                        message_vision("¿´À´$N²¢²»ÊÜ»¶Ó­£¬×ªÁËÒ»È¦ÓÖ»ØÀ´ÁË¡£\n", me);
                        return 1;
                }
                else
                {
                        tell_room(room, me->name() + "×ßÁË¹ıÀ´¡£\n");
                        me->move(room);
                        return 1;
                }
        }
}

int do_newchat(string arg)
{
        object me = this_player();
        object *chatrooms, room, board;
        int i;

/*
        if (me->query_skill("fadai-qigong", 1) < 50 )
                return notify_fail("ÄãµÄ·¢´ôÉñ¹¦µÈ¼¶Ì«µÍ£¬ÎŞ·¨·¢´ô³öÒ»¸öÁÄÌìÊÒÀ´¡£\n");
*/

        chatrooms = children("/d/city/newchat");
        for (i = 0; i < sizeof(chatrooms); i++)
        {
                if (chatrooms[i]->query("owner") == me->query("id"))
                        return notify_fail("ÄãÒÑ¾­´´½¨ÁËÒ»¸öÁÄÌìÊÒÁË¡£\n");
        }

                room = new("/d/city/newchat");
                room->set("owner", me->query("id"));
                room->set("short", me->name() + "(" + me->query("id")
                                   + ")" + "µÄÁÄÌìÊÒ");
        room->set("long", sort_string(
                "ÕâÀïÊÇ" + me->name() + "Îª´ó¼ÒÌá¹©µÄÁÄÌìÊÒ£¬ÖĞ¼ä¼¸¸ö×ÀµÊ£¬ÉÏÃæÁãÁãÉ¢É¢µÄ°Ú"
                "×Å²èË®ºÍÑÌ»Ò¸×£¬µØÉÏÔòÊÇÒ»µØµÄ¹Ï×ÓÆ¤ºÍÑÌÍ·£¬³ı´ËÖ®Íâ¿Õ¿Õµ´µ´µÄÊ²"
                "Ã´Ò²Ã»ÓĞ¡£ÔÚÃÅ¿ÚÍáÍáĞ±Ğ±µÄ·Å×ÅÒ»¸öºÚ°å(chalkboard)£¬ÉÏÃæĞ´×Å¼¸ĞĞ"
                "×Ö¡£", 64, 4));

        if (me->query("env/auto_ban"))
                set("banned", me->query("env/auto_ban"));

        if (me->query("env/auto_invite"))
                set("permitted", me->query("env/auto_invite"));


        if (wizardp(me)) room->set("forwizard", 1);

        message_vision("$N½¨ºÃÁËÁÄÌìÊÒ¡£\n", me);
        message_vision("$NËÊËÊ¼ç£¬Íù" + room->query("short") + "×ßÈ¥¡£\n", me);
                
        me->move(room);
        return 1;
}

