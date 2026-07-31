// regiser: entry.c
// by Doing
// Update by Lonely

#include <ansi.h>
#include <login.h>
#include <command.h>

inherit ROOM;

int is_chat_room() { return 1; }

int do_wash(string arg);
int do_born(string arg);

mapping born = ([
        "¹ØÍâÈËÊÏ" : "/d/guanwai/kedian",
        "ÑàÕÔÈËÊÏ" : "/d/beijing/kedian",
        "ÆëÂ³ÈËÊÏ" : "/d/taishan/kedian",
        "ÇØ½úÈËÊÏ" : "/d/changan/kezhan",
        "ÃÉ¹ÅÈËÊÏ" : 0,
        "ÖĞÔ­ÈËÊÏ" : "/d/shaolin/kedian1",
        "Î÷ÓòÈËÊÏ" : "/d/xingxiu/kedian",
        "¾£ÖİÈËÊÏ" : "/d/jingzhou/kedian",
        "ÑïÖİÈËÊÏ" : "/d/city/kedian",
        "ËÕÖİÈËÊÏ" : "/d/suzhou/kedian",
        "º¼ÖİÈËÊÏ" : "/d/hangzhou/kedian",
        "¸£½¨ÈËÊÏ" : "/d/fuzhou/kedian",
        "°ÍÊñÈËÊÏ" : "/d/city3/kedian",
        "ÔÆÄÏÈËÊÏ" : "/d/dali/kedian",
        "Ç­ÖĞÈËÊÏ" : 0,
        "Á½¹ãÈËÊÏ" : "/d/foshan/beidimiao",
        "Å·ÑôÊÀ¼Ò" : ([ "born"      : "Î÷ÓòÈËÊÏ",
                        "surname"   : "Å·Ñô",
                        "startroom" : "/d/baituo/dating",
                     ]),
        "¹ØÍâºú¼Ò" : ([ "born"      : "¹ØÍâÈËÊÏ",
                        "surname"   : "ºú",
                        "startroom" : "/d/guanwai/xiaowu",
                     ]),
        "¶ÎÊÏ»Ê×å" : ([ "born"      : "´óÀíÈËÊÏ",
                        "surname"   : "¶Î",
                        "startroom" : "/d/dali/wangfugate",
                     ]),
        "Ä½ÈİÊÀ¼Ò" : ([ "born"      : "½­ÄÏÈËÊÏ",
                        "surname"   : "Ä½Èİ",
                        "startroom" : "/d/yanziwu/cuixia",
                     ]),
        "ÌÆÃÅÊÀ¼Ò" : ([ "born"      : "°ÍÊñÈËÊÏ",
                        "surname"   : "ÌÆ",
                        "startroom" : "/d/tangmen/kedian",
                     ]),
]);

void create()
{
        int i, k;
        string desc;
        string *position;

        set("short", HIR "ÉúÃüÖ®¹È" NOR);
        set("long",
"»ìãç³õ·ÖÅÌ¹Å¿ªÌìµØ£¬ÃÔÎí¡¢Î¢·ç£¬ÌìµØ³õ¿ª£¬ËÄÖÜ»ìãç£¬ÎíÃ£Ã£Ò»\n"
"Æ¬£¬ÕâÀï¾ÍÊÇ×ÓÌì³óµØÈËÒú³öµÄÉúÃüÖ®¹È£¬Ö»¼ûÅÌ¹ÅÕıÔÚ±ÕÄ¿³ÁË¼£¬Ô­Ê¼\n"
"Ìì×ğºÍÁé±¦Ìì×ğ¹ªÁ¢ÉíÅÔ¡£\n"
"¡¡¡¡¹ÈÖĞÓĞÒ»¸öÊ¯Í·Æö³ÉµÄ³Ø×Ó£¬ÆäÖĞË®Çå³ºÈ´²»¼ûµ×£¬²»ÖªµÀËü¾¿¾¹ÓĞ\n"
"¶àÉî£¬³Ø×ÓÕıÉÏ·½Ğü¹Ò×ÅÌ«¼«Á½ÒÇËÄÏó£¬²»ÖªÓĞºÎ°ÂÃî£¿£¡\n"
"¡¡¡¡ÅÔ±ßÓĞÒ»¸öÅÆ×Ó(paizi)¡£(ÊäÈë£º[1;32mlook paizi[2;37;0m ¿É¿´µ½ÅÆ×ÓÉÏµÄÄÚÈİ)\n"
);
        set("no_fight", 1);
        set("item_desc", ([
                "paizi" : "Í¶Ì¥ÄËÈËÉú´óÊÂ£¬ÇĞ¼Ç²»¿É²İÂÊ£¡Ñ¡ºÃ·½Ïò£¬¾ÍÊäÈëborn <µØÃû>¡£\n"
        ]));

        set("objects", ([
                __DIR__"npc/pangu" : 1,
        ]));

        // set("no_say", "ÅÌ¹ÅÕıÔÚ±ÕÄ¿³ÁË¼£¬ÄãÄÄÀï¸ÒÂÒËµ»°£¿\n");

        desc = query("item_desc/paizi");
        position = keys(born);

        for (i = 0, k = 1; i < sizeof(position); i++)
        {
                if (! stringp(born[position[i]]))
                        continue;

                desc += sprintf("%2d. " HIW "%s" NOR "\n", k++, position[i]);
        }

        for (i = 0; i < sizeof(position); i++)
        {
                if (! mapp(born[position[i]]))
                        continue;

                desc += sprintf("%2d. " HIC "%s" NOR "\n", k++, position[i]);
        }
        set("item_desc/paizi", desc);

        setup();
}

void init()
{
        add_action("do_wash", "wash");
        add_action("do_born", "born");
}

int do_wash(string arg)
{
        int i;
        int points;
        int tmpstr, tmpint, tmpcon, tmpdex;
        object me;
        mapping my;

        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;

        write(HIC "ÄãÌøÈëÉúÃü³Ø£¬¶ÙÊ±±»Ò»¹É¼¤Á÷¾íÁË½øÈ¥¡£\n" NOR, me);

        tmpstr = tmpint = tmpcon = tmpdex = 13;

        switch (me->query("type"))
        {
        case "ÃÍÊ¿ĞÍ":
                tmpstr = 20;
                break;

        case "ÖÇ»ÛĞÍ":
                tmpint = 20;
                break;

        case "ÄÍÁ¦ĞÍ":
                tmpcon = 20;
                break;

        case "Ãô½İĞÍ":
                tmpdex = 20;
                break;

        default:
                break;
        }

        points = 80 - (tmpstr + tmpint + tmpcon + tmpdex);
        for (i = 0; i < points; i++) {
                switch (random(4)) {
                case 0: if (tmpstr < 30) tmpstr++; else i--; break;
                case 1: if (tmpint < 30) tmpint++; else i--; break;
                case 2: if (tmpcon < 30) tmpcon++; else i--; break;
                case 3: if (tmpdex < 30) tmpdex++; else i--; break;
                }
        }

        my = me->query_entire_dbase();

        my["str"] = tmpstr;
        my["int"] = tmpint;
        my["con"] = tmpcon;
        my["dex"] = tmpdex;
        my["kar"] = 10 + random(21);
        my["per"] = 10 + random(21);

        write(HIC "¡°Å¾¡±µÄÒ»Éù£¬Äã±»ÊªäõäõµÄÅ×ÁË³öÀ´¡£\n" NOR, me);
        write(sprintf(HIY "\nÄãÕâ´Î»ñµÃµÄËÄÏîÏÈÌìÌì¸³·Ö±ğÊÇ£º\n"
                          "ëöÁ¦£º¡¾ " HIG "%d" HIY " ¡¿ "
                          "ÎòĞÔ£º¡¾ " HIG "%d" HIY " ¡¿ "
                          "¸ù¹Ç£º¡¾ " HIG "%d" HIY " ¡¿ "
                          "Éí·¨£º¡¾ " HIG "%d" HIY " ¡¿\n"
			  "Èç¹ûÄãÂúÒâ£¬¾ÍÈ¥Í¶Ì¥(born)°É£¡\n\n" NOR,
                      tmpstr, tmpint, tmpcon, tmpdex));
        me->set_temp("washed", 1);

        return 1;
}

int do_born(string arg)
{
        object me;
        object obj;
	object item;
        mixed dest;
        string new_name;
        string msg;

        if (! objectp(me = this_player()) ||
            ! userp(me))
                return 1;

        if (! me->query_temp("washed"))
                return notify_fail("ÄãÏÖÔÚÉúÃü³ØÖĞÏ´Ò»ÏÂ(wash)£¬Ñ¡ÔñºÃÌì¸³ÄãÔÚÍ¶Ì¥Ò²²»³Ù°¡£¡\n");

        if (arg && arg[0] < 160)
                return notify_fail("Äã±ØĞëÊäÈëÖĞÎÄµØÃû£¬±ÈÈçborn ÑïÖİÈËÊÏ£¬»òÕßÊÇborn Å·ÑôÊÀ¼ÒÒÔ±ÜÃâÍ¶´íÌ¥¡£\n");

        new_name = 0;
        if (arg) sscanf(arg, "%s %s", arg, new_name);

        if (! arg || (! stringp(dest = born[arg]) && ! mapp(dest)))
        {
                message_vision("Ô­Ê¼Ìì×ğ¶ñºİºİµÄ¶Ô$NËµ£ºÄãÒª¸ÉÊ²Ã´£¡Í¶Ì¥È¥ÄÄÀï£¿\n", me);
                return 1;
        }

        if (mapp(dest) && stringp(dest["notice"]))
                return notify_fail(dest["notice"]);

        if (stringp(dest))
        {
                if (! objectp(obj = find_object(dest)))
                        obj = load_object(dest);
                me->set("startroom", dest);
                me->set("born", arg);
                me->set("born_family", "Ã»ÓĞ");
        } else
        {
                if (! objectp(obj = find_object(dest["startroom"])))
                        obj = load_object(dest["startroom"]);

                if (new_name)
                {
                        if (! sscanf(new_name, dest["surname"] + "%*s"))
                                new_name = dest["surname"] + new_name;

                        if (strlen(new_name) > 8)
                                return notify_fail("ÄãµÄÃû×ÖÌ«³¤ÁË¡£\n");

                        if (strlen(new_name) < 4)
                                return notify_fail("ÄãµÄÃû×ÖÌ«¶ÌÁË¡£\n");

                        if (! is_chinese(new_name))
                                return notify_fail("ÇëÄãÓÃÖĞÎÄÆğÃû×Ö¡£\n");
                }

                if (me->query("surname") != dest["surname"])
                {
                        // Ãû×ÖĞèÒª±ä»¯
                        NAME_D->remove_name(me->name(1), me->query("id"));
                        if (! new_name) new_name = dest["surname"] + me->query("purename");
                        if (stringp(msg = NAME_D->invalid_new_name(new_name)))
                        {
                                write(msg);
                                write("Äã¿ÉÒÔ¿¼ÂÇÔÚÍ¶ÈëÊÀ¼ÒµÄÊ±ºòÖØĞÂÑ¡ÔñÃû×Ö£ºborn <ÊÀ¼Ò> <Ãû×Ö>\n");
                                return 1;
                        }
                        me->set("surname", dest["surname"]);
                        me->set("purename", new_name[strlen(dest["surname"])..<1]);
                        me->set_name();
                        NAME_D->map_name(me->name(1), me->query("id"));
                }

                me->set("startroom", dest["startroom"]);
                me->set("born", dest["born"]);
                me->set("born_family", arg);

                if (mapp(dest["family"]))
                {
                        me->set("family", dest["family"]);
                        me->assign_apprentice(dest["family"]["title"], 0);
                }
        }
        if (! objectp(obj))
        {
                message_vision("Ô­Ê¼Ìì×ğÒ»´ô£¬É¦É¦Í·Ëµ£ºÔõÃ´ºÃÏñÓĞÎÊÌâ...\n", me);
                return 1;
        }

        message_vision("Ô­Ê¼Ìì×ğ·ÉÆğÒ»½Å£¬½«$NÌßÁË³öÈ¥¡£\n", me);
	
	foreach (item in all_inventory(me))
		if (! item->query("armor_type"))
		{
			message_vision("$N¶ªÏÂÁË$n¡£\n", me, item);
                        if (item->is_character() || item->query("value"))
			        item->move(environment(me));
                        else
                                destruct(item);
		}

        // Ñ¡ÔñÌØÊâ¼¼ÄÜ
        UPDATE_D->born_player(me);

        me->move(obj);
        me->set("mud_age", 0);
        me->set("age", 14);
        me->save();
	HELP_CMD->main(me, "rules");
        message_vision("$NÈàÈàÑÛ¾¦£¬ÃÔã¯µÄÍû×ÅÕâ¸öÄ°ÉúµÄÊÀ½ç¡£\n", me);

        return 1;
}
