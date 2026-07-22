// Ãµ¹åÑç»áÌü.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
// amount: µ¥Î»ÊÇgold
int can_afford(object me,int amount)
{
        int total;
        object thgold,thcash,gold;
        thgold = present("thousand-gold_money",me);
        thcash = present("thousand-cash_money",me);
        gold = present("gold_money",me);
        total = 0;
        if( thgold ) total += thgold->query_amount()*1000;
        if( thcash ) total += thcash->query_amount()*10;
        
        if( gold ) total += gold->query_amount();
        if( total < amount ) return 0;
        return 1;
}
// amount: µ¥Î»ÊÇgold
int pay_money(object me,int amount)
{
        int total;
        object thgold,thcash,gold;

        thgold = present("thousand-gold_money",me);
        thcash = present("thousand-cash_money",me);
        gold = present("gold_money",me);
        total = 0;
        if( thgold ) {
            total += thgold->query_amount()*1000;
            destruct(thgold);
        }
        if( thcash ) {
            total += thcash->query_amount()*10;
            destruct(thcash);
        }
        if( gold ) {
            total += gold->query_amount();
            destruct(gold);
        }
        if( total < amount ) return 0;
                total-=amount;
        if( total > 1000 ) {
            thgold=new(THGOLD_OB);
            if (!thgold->move(me)) thgold->move(environment(me));
                thgold->set_amount(total/1000);
                total %= 1000;
        }
        if( total > 10 ) {
        thcash=new(THCASH_OB);
        if (!thcash->move(me)) thcash->move(environment(me));
        thcash->set_amount(total/10);
            total %= 10;
        }
    if( total > 0 ){
        gold=new(GOLD_OB);
        if (!gold->move(me)) gold->move(environment(me));
        gold->set_amount(total);
    }
}


varargs protected void
create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", GRN+"Ò»ÅÌÈÈÆøÌÚÌÚ, ÏãÅçÅçµÄ"+nmstr+"¡£\n"+NOR);
        obj->move(this_object());
}

varargs protected void
create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/water");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", YEL+"Ò»±­¿É¿ÚµÄ" + nmstr + "¡£\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

varargs protected void
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/wine");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", RED+"Ò»±­´¼ÕıµÄ" + nmstr + "¡£\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

void create()
{
        set("short", HIG"Ãµ¹åÑçÌü"NOR);
        set("long", @LONG
½øÃÅÈÆ¹ıÒ»µÀµ­»Æ³ñÆÁ·ç£¬Ó­ÃæÇ½ÉÏ¹Ò×ÅÒ»¸±¡ºÃµ¹åº¬Â¶¡»Í¼£¬ÏÊÄÛÓû
µÎ£¬»¨°êÇá·Ö£¬ËÆÓĞÏãÆøÓ¯ÊÒ¡£ÌüÄÚ³ÂÁĞÉİ»ª£¬ÕıÖĞÑëÒ»ÕÅµñ»¨éªÄ¾ÇàÆáÇ¶
Óñ´óÔ²×À£¬ËÄÖÜÊ®¶şÕÅÏâÒøÏóÑÀ·öÊÖºìÄ¾ÒÎ£¬±­ÍëÉ×óç£¬ÈëÑÛÉú»Ô¡£
    ÕâÀï±ãÊÇ×íÏÉÂ¥µÄÃµ¹åÌü£¬×ÀÉÏÆ½ÆÌ×ÅÒ»·İ²Ëµ¥(menu)¡£
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"zxlpath",
        ]));
        set("no_sleep_room",1);
        set("item_desc", ([
                "menu": @TEXT
³Ğ°ì¸÷Ê½¾ÆÏ¯, »¶Ó­»İ¹Ë£º

        order marry:    ¶©»é´óÑç        (3000Á½»Æ½ğ)

        order player:   ÈººÀ´óÑç        (5000Á½»Æ½ğ)

        order end:      ½á  Êø

TEXT
        ]) );
//        create_door("out", "ºìÄ¾ïÎ»¨ÃÅ", "enter", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}

void init()
{
        object me;

        add_action("do_order", "order");
        add_action("do_broadcast", "broadcast");
        if (query("order_owner")) {
                me = this_player();
                me->set("food", me->query("food") / 8);
                me->set("water", me->query("water") / 8);
        }
        add_action("do_get", "get");
}
int do_get(string arg)
{
	if (!arg)	return 0;
	if (arg=="all" && query("order_owner")){
		write("ÄãÊÇÃÖÂŞ·ğÏÂ·²£¬ÕâÃ´´óµÄÎ¸¿Ú£¿\n");
		return 1;
	}
	return 0;
}
int do_broadcast(string arg)
{
        string type;
        string mesg;
        object me;

        me = this_player();
        if (query("order_owner") != me->query("id"))
                return 0;
        type = query("order_type");
        if (type == "marry") {
                mesg = me->name() + "ÏÖÔÚÔÚ×íÏÉÂ¥Ãµ¹åÌü¾ÙĞĞ¶©»é¾ÆÑçÁË  !!!\n";
        } else if (type == "player") {
                mesg = me->name() + "ÏÖÔÚÔÚ×íÏÉÂ¥Ãµ¹åÌüÑçÇë¸÷Â·Ó¢ĞÛºÀ½Ü  !!!\n";
       }
        message("channel:chat", HIR+"¡¾Í¨¸æ¡¿"+mesg+NOR, users() );
        return 1;
}

int do_order(string arg)
{
        object me, env;
        object* oblist;
        string mesg;
        int idx;

        me = this_player();
        env = this_object();
        mesg = query("order_owner");
        if (mesg && (arg == "end") && (mesg == me->query("id"))) {
                mesg = "Ãµ¹åÌüµÄÑç»á½áÊøÁË  !!!\n";
                message("channel:chat", HIR+"¡¾Í¨¸æ¡¿"+mesg+NOR, users() );
                delete("order_owner");
                delete("order_type");
                oblist = all_inventory(env);
                for(idx=0; idx<sizeof(oblist); idx++) {
                        if (!objectp(oblist[idx]))
                                continue;
                        if (userp(oblist[idx]))
                                continue;
                        destruct(oblist[idx]);
                }
                return 1;
        }
        if (mesg)
                return notify_fail("ÕâÀïÒÑ¾­±»ÈË°ü×âÁË.\n");
         notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÇ®»òÁãÇ®²»¹».\n");
        if (arg == "marry") {
                mesg = me->name() + "ÏÖÔÚÔÚ×íÏÉÂ¥Ãµ¹åÌü¾ÙĞĞ¶©»é¾ÆÑçÁË  !!!\n";
                if (can_afford(me,3000) == 0)
                        return 0;
                pay_money(me,3000);
                create_water(HIG"Áú¾®²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
                create_water(RED"ÆÕ¶ı²è"NOR, ({ "tea" }), WHT"Ë®¾§Õµ"NOR );
                create_wine(WHT"Ã×¾Æ"NOR, ({ "wine" }), HIW"ÌÂ´É±­"NOR );
                create_wine(GRN"ÖñÒ¶Çà"NOR, ({ "wine" }), GRN"ôä´ä±­"NOR );
                create_wine(YEL"ÉÜĞË»Æ¾Æ"NOR, ({ "wine" }), HIY"ÏóÑÀ±­"NOR );
                create_wine(HIR"Å®¶ùºì"NOR, ({ "wine" }), MAG"×ÏÌ´±­"NOR );
                create_wine(WHT"Ã©Ì¨¾Æ"NOR, ({ "wine" }), YEL"öÌ½ğ±­"NOR );
                create_wine(RED"¹ğ»¨¾Æ"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR );
                create_food(YEL"ÏãËÖ»¨Éú"NOR,({"peanut"}) );
                create_food(HIR"¾ÆÔãºìÔæ"NOR,({"jujube"}) );
                create_food(RED"Ï²ÌÇ"NOR,({"sugar"}) );
                create_food(HIW"ÄÌÓÍ¹Ï×Ó"NOR,({"melon seeds","seeds"}) );
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
                create_food(HIW"ÂéÀ±ÊÖËº¼¦"NOR, ({"chicken"}) );
                create_food(HIR"¸ÉìÔÓÈÓã"NOR, ({"fish"}) );
                create_food(HIY"¶«±±Ë®½È"NOR, ({ "dumpling" }) );
                create_food(RED"ÂéÀ±»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
                create_food(HIR"ÓÍ¼åó¦Ğ·"NOR, ({ "crab" }) );
                create_food(HIY"·ÛÕôÈâ"NOR, ({ "meat" }) );
                create_food(YEL"¼Ò³£¶¹¸¯"NOR, ({ "bean curd" }) );
                create_water(GRN"ÔÆÎí²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
                create_water(HIG"¾ıÉ½ÒøÕë"NOR, ({ "tea" }), RED"ºìÄàÕµ"NOR );
                create_water(HIW"ÏÊÄÌ"NOR, ({ "milk" }), WHT"²£Á§±­"NOR );
                create_wine(RED"³ÂÄê»¨µñ"NOR, ({ "wine" }), HIW"ËÎ´É±­"NOR  );
                create_wine(WHT"ÎåÁ¸Òº"NOR, ({ "wine" }), WHT"²£Á§±­"NOR );
                create_wine(WHT"Ã×¾Æ"NOR, ({ "wine" }), HIW"ÌÂ´É±­"NOR );
                create_wine(HIR"¶Å¿µ¾Æ"NOR, ({ "wine" }), HIG"ÇàÍ­¾ô"NOR  );
                create_wine(HIW"Í¸Æ¿Ïã"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR  );
                create_food(HIY"µÂÖİ°Ç¼¦"NOR, ({ "chicken" }) );
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
                create_food(YEL"¿§à¬·¹"NOR, ({"rice"}) );
                create_food(RED"òºÓÍÈâÆ¬"NOR, ({"fish meat","meat"}) );
                create_food(RED"ÑòÈâ´®"NOR, ({ "mutton" }) );
                create_food(HIR"ÖØÇì»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
                create_food(HIY"±±¾©¿¾Ñ¼"NOR, ({ "duck" }) );
                create_food(YEL"·ÛÕôÈâ"NOR, ({ "meat" }) );
                create_food(HIW"ËÄÏ²¶¹¸¯"NOR, ({ "bean curd" }) );
        } else if (arg == "player") {
                mesg = me->name() + "ÏÖÔÚÔÚ×íÏÉÂ¥Ãµ¹åÌüÑçÇë¸÷Â·Ó¢ĞÛºÀ½Ü  !!!\n";
                if (can_afford(me,5000) == 0)
                        return 0;
                pay_money(me,5000);
                create_food(YEL"½Ğ»¨¼¦"NOR, ({ "chicken" }) );
                create_food(HIW"ËÄÏ²¶¹¸¯"NOR, ({ "bean curd" }) );
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring","roll" }) );
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
                create_food(RED"ÑòÈâ´®"NOR, ({ "mutton" }) );
                create_food(HIY"»¨Ö¦·¹¾í"NOR, ({"rice"}) );
                create_food(HIR"ÓãÏãÈâË¿"NOR, ({"fish meat","meat"}) );
                create_food(HIY"µÂÖİ°Ç¼¦"NOR, ({ "chicken" }) );
                create_food(RED"ÂéÀ±»ğ¹ø"NOR, ({ "chrafing dish","dish" }) );
                create_food(HIY"±±¾©¿¾Ñ¼"NOR, ({ "duck" }) );
                create_food(HIW"°×Õ¶¼¦"NOR, ({ "chicken" }) );
                create_food(YEL"·ÛÕôÈâ"NOR, ({ "meat" }) );
                create_food(HIR"ÖØÇì»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
                create_food(HIR"ÂéÆÅ¶¹¸¯"NOR, ({ "bean curd" }) );
                create_food(RED"òºÓÍÈâÆ¬"NOR, ({"fish meat","meat"}) );
                create_food(YEL"¿§à¬·¹"NOR, ({"rice"}) );
                create_food(HIW"ÂéÀ±ÊÖËº¼¦"NOR, ({"chicken"}) );
                create_food(HIR"¸ÉìÔÓÈÓã"NOR, ({"fish"}) );
                create_food(HIY"¶«±±Ë®½È"NOR, ({ "dumpling" }) );
                create_water(HIW"ÑòÄÌ"NOR, ({ "milk" }), CYN"Çà»¨Íë"NOR );
                create_water(GRN"ÔÆÎí²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
                create_water(GRN"±ÌÂİ´º"NOR, ({ "tea" }), MAG"×ÏÉ°Õµ"NOR );
                create_water(HIG"¾ıÉ½ÒøÕë"NOR, ({ "tea" }), RED"ºìÄàÕµ"NOR );
                create_water(HIR"ºìÃ«¼â"NOR, ({ "tea" }), CYN"ÇàÄàÕµ"NOR );
                create_wine(HIW"·Ú¾Æ"NOR, ({ "wine" }), WHT"ÑòÖ¬°×Óñ±­"NOR );
                create_wine(WHT"¹ØÍâ°×¾Æ"NOR, ({ "wine" }), YEL"Ï¬½Ç±­"NOR );
                create_wine(RED"ÆÏÌÑ¾Æ"NOR, ({ "wine" }), HIW"Ò¹¹â±­"NOR );
                create_wine(WHT"¸ßÁ»¾Æ"NOR, ({ "wine" }), CYN"ÇàÍ­¾ô"NOR );
                create_wine(HIG"°Ù²İ¾Æ"NOR, ({ "wine" }), RED"¹ÅÌÙ±­"NOR );
                create_wine(HIR"×´Ôªºì"NOR, ({ "wine" }), WHT"¹Å´É±­"NOR );
                create_wine(GRN"Àæ»¨¾Æ"NOR, ({ "wine" }), HIG"ôä´ä±­"NOR );
                create_wine(HIW"ÓñÂ¶¾Æ"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR );
                create_water(HIG"Áú¾®²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
                create_water(RED"ÆÕ¶ı²è"NOR, ({ "tea" }), WHT"Ë®¾§Õµ"NOR );
                create_wine(WHT"Ã×¾Æ"NOR, ({ "wine" }), HIW"ÌÂ´É±­"NOR );
                create_wine(GRN"ÖñÒ¶Çà"NOR, ({ "wine" }), GRN"ôä´ä±­"NOR );
                create_wine(YEL"ÉÜĞË»Æ¾Æ"NOR, ({ "wine" }), HIY"ÏóÑÀ±­"NOR );
                create_wine(HIR"Å®¶ùºì"NOR, ({ "wine" }), MAG"×ÏÌ´±­"NOR );
                create_wine(WHT"Ã©Ì¨¾Æ"NOR, ({ "wine" }), YEL"öÌ½ğ±­"NOR );
                create_wine(RED"¹ğ»¨¾Æ"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR );
                create_food(YEL"ÏãËÖ»¨Éú"NOR,({"peanut"}) );
                create_food(HIR"¾ÆÔãºìÔæ"NOR,({"jujube"}) );
                create_food(RED"Ï²ÌÇ"NOR,({"sugar"}) );
                create_food(HIW"ÄÌÓÍ¹Ï×Ó"NOR,({"melon seeds","seeds"}) );
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
                create_food(HIW"ÂéÀ±ÊÖËº¼¦"NOR, ({"chicken"}) );
                create_food(HIR"¸ÉìÔÓÈÓã"NOR, ({"fish"}) );
                create_food(HIY"¶«±±Ë®½È"NOR, ({ "dumpling" }) );
                create_food(RED"ÂéÀ±»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
                create_food(HIR"ÓÍ¼åó¦Ğ·"NOR, ({ "crab" }) );
                create_food(HIY"·ÛÕôÈâ"NOR, ({ "meat" }) );
                create_food(YEL"¼Ò³£¶¹¸¯"NOR, ({ "bean curd" }) );
                create_water(GRN"ÔÆÎí²è"NOR, ({ "tea" }), MAG"×ÏÉ°²èÖÑ"NOR );
                create_water(HIG"¾ıÉ½ÒøÕë"NOR, ({ "tea" }), RED"ºìÄàÕµ"NOR );
                create_water(HIW"ÏÊÄÌ"NOR, ({ "milk" }), WHT"²£Á§±­"NOR );
                create_wine(RED"³ÂÄê»¨µñ"NOR, ({ "wine" }), HIW"ËÎ´É±­"NOR  );
                create_wine(WHT"ÎåÁ¸Òº"NOR, ({ "wine" }), WHT"²£Á§±­"NOR );
                create_wine(WHT"Ã×¾Æ"NOR, ({ "wine" }), HIW"ÌÂ´É±­"NOR );
                create_wine(HIR"¶Å¿µ¾Æ"NOR, ({ "wine" }), HIG"ÇàÍ­¾ô"NOR  );
                create_wine(HIW"Í¸Æ¿Ïã"NOR, ({ "wine" }), WHT"ÁğÁ§±­"NOR  );
                create_food(HIY"µÂÖİ°Ç¼¦"NOR, ({ "chicken" }) );
                create_food(HIG"±ÌÂİ´º¾í"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"ÏãÆ¬ÕôÓã"NOR, ({"fish"}) );
                create_food(YEL"¿§à¬·¹"NOR, ({"rice"}) );
                create_food(RED"òºÓÍÈâÆ¬"NOR, ({"fish meat","meat"}) );
                create_food(RED"ÑòÈâ´®"NOR, ({ "mutton" }) );
                create_food(HIR"ÖØÇì»ğ¹ø"NOR, ({ "chafing dish","dish" }) );
                create_food(HIY"±±¾©¿¾Ñ¼"NOR, ({ "duck" }) );
                create_food(YEL"·ÛÕôÈâ"NOR, ({ "meat" }) );
                create_food(HIW"ËÄÏ²¶¹¸¯"NOR, ({ "bean curd" }) );
        }
         else {
                return notify_fail("ÄãÒª¶¨Ê²Ã´¾ÆÏ¯?\n");
        }
        message("channel:chat", HIR+"¡¾Í¨¸æ¡¿"+mesg+NOR, users() );
        set("order_owner", me->query("id"));
        set("order_type", arg);
        return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query("id") != query("order_owner"))
                return 1;
        return notify_fail(RED + "ÏÈÓÃ order end ½áÊøÑç»áºó²ÅÄÜÀë¿ª¡£\n" + NOR);
}

