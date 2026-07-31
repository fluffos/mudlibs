// bbsboard.c
// updated by Lonely
/* ÔöÇ¿¹¦ÄÜÁôÑÔ°æ£ºBBS_BOARD £¬Ôö¼Ó£º»Ø¸´¹¦ÄÜ¡¢°ßÖñ¹¦ÄÜ¡¢ÕûÀí¹¦ÄÜ
 * ·ÀÖ¹ FLOOD ¹¦ÄÜ£¬²Î¿¼ÓÚ jjgod µÄÁôÑÔ°æ */

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

#define BBS             "\n\nBbs - http://bbs.mudbuilder.com/"

// ×î¶àÈİÄÉ 100 ¸öÌù×Ó
#define MAX_PLAN                1000

// ¼ÙÈçÌù×Ó³¬¹ıÁË MAX_PLAN£¬É¾µôÇ° 25 ¸ö
#define DEL_TO          MAX_PLAN/4

// ÊÇ·ñ±£´æËùÓĞÔ­À´µÄÌù×Ó£¬ÊÇÔòÉèÎª0£¬·ñÔòÉèÎª 1
#define SAVE_ALL_OLD_PLAN 0

// Èç¹ûĞèÒªÏÔÊ¾ÕûÀíÇé¿ö£¨ºÜ³¤ºÜ³¤£©£¬Çë£º
#define DEBUG           1

// ×î´óµÄ±êÌâ³¤¶È
#define MAX_TITLE_LEN   29

// ·¢±íÎÄÕÂĞèÒªµÄÄÜÁ¦
#define NEED_EXP                10000
#define NEED_AGE                16

void setup()
{
        string loc;
        string my_long, my_id;

        if (stringp(loc = query("location")))
                move(loc);

        my_long = query("long");
        my_id = query("board_id");

        restore();

        set("no_get", 1);
        set("long", my_long);
        set("id", "board");
        set("location", loc);
}

void init()
{
        add_action("do_post", "post");
        add_action("do_re", "re");
        add_action("do_followup", "followup");
        add_action("do_read", "read");
        add_action("delete_post", "delete");
        add_action("delete_post", "discard");
        add_action("do_from", "from");
        add_action("do_banzhu", "banzhu");
        add_action("do_search", "search");
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

string short()
{
        mapping *notes;
        string banzhu;
        int i, unread, last_read_time;

        if (! query("banzhu"))
                banzhu = "[°ßÖñÕ÷ÇóÖĞ]";
        else
                banzhu = "[°ßÖñ:" + this_object()->query("banzhu") + "]";

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                return ::short() + " [ Ã»ÓĞÈÎºÎÌù×Ó ]";

        if (this_player())
        {
                last_read_time = (int)this_player()->query("board_last_read/" +
                                 (string)query("board_id"));
                for (unread = 0, i = sizeof(notes) - 1; i >= 0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if (unread)
                return sprintf(HIC "%s" NOR " [ " HIW "%d" NOR " ¸öÌù×Ó£¬" HIR "%d" NOR " ÆªÎ´¶Á ]" +
                               banzhu, ::short(), sizeof(notes), unread);
        else
                return sprintf("%s [ " HIW "%d" NOR " ¸öÌù×Ó ]" + banzhu, ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, j, last_time_read;
        string msg, myid;

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                return query("long");

        msg = query("long") + (query("banzhu") ? ("Õâ¸ö°æµÄµÄ°æÖ÷ÊÇ " WHT + query("banzhu") + NOR "¡£\n") : "") +
              HIW "±àºÅ©¤©¤±êÌâ©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤×÷Õß©¤»Ø¸´©¤©¤©¤Ê±¼ä©¤©¤©¤©¤©¤\n" NOR;

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

        for (i = 0; i < sizeof(notes); i++)
        {
                msg += sprintf("%s[" WHT "%3d" NOR "]" NOR "  %-29s %12s " WHT "%+3d" NOR "   [%s]\n",
                        (notes[i]["time"] > last_time_read ? HIY: ""),
                        i + 1, notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]),
                        ctime(notes[i]["time"])[0..15] );
        }

        msg += HIW "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n" NOR;
        return msg;
}


int do_from(string arg)
{
        mapping *notes;
        int i,j,last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        msg = msg + "ÁôÑÔ°æµÄÊ¹ÓÃ·½·¨Çë¼û help board¡£\n";
        if (! pointerp(notes) || ! sizeof(notes)) return notify_fail(query("long"));

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

        if (!arg)
                i = 0;
        else
                i = atoi(arg) - 1;

        if (i < 0) i = 0;

        j = 0;
        for (; i < sizeof(notes); i++)
        {
                msg += sprintf("%s[%3d]" NOR "  %-40s %12s (%s)\n",
                        (notes[i]["time"] > last_time_read ? HIY: ""),
                        i + 1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15]);
                j ++;
                if (j>1000) break;
        }

        this_player()->start_more(msg);
        return 1;
}

void done_post(object me, mapping note, int n, string text)
{
        int i, j;
        int t;
        int pl;
        string sign;
        string pure;
        mapping *notes;
        string *lines;
        string msg = "";

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "ÄãµÄÁôÑÔÌ«³¤ÁË£¬ÇëÂÔÈ¥Ò»Ğ©²»±ØÒªµÄ¡£\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "ÄãµÄÁôÑÔÌ«³¤ÁË£¬ÇëÂÔÈ¥Ò»Ğ©²»±ØÒªµÄ¡£\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "ÄãµÄÁôÑÔÖĞ¶Ì¾äÌ«¶àÁË£¬Çëµ÷ÕûÒ»ÏÂÒÔ±ãËûÈËÔÄ¶Á¡£\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "ÄãÁôÑÔÖĞÓĞĞ©ĞĞÌ«³¤ÁË£¬Çë·ÖĞĞÒÔ±ãËûÈËÔÄ¶Á¡£\n");
                        return;
                }
        }

        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;
        } // else text += HIM "\n" + BBS + "\n" NOR;

        text = color_filter(text) + NOR;
        note["msg"] = text;
        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                notes = ({ note });
        else
        {
                i = sizeof(notes) - 1;
                if (note["time"] <= notes[i]["time"])
                        note["time"] = notes[i]["time"] + 1;
                notes += ({ note });
        }

        set("notes", notes);
        tell_object(me, HIW "ĞÂÌù×ÓÍê³É¡£\n" NOR);
        save();

        if (sizeof(query("notes")) > MAX_PLAN)
        {
                tell_object(me, HIR "Ìù×ÓÊıÄ¿³¬Á¿£¬ÕıÔÚÕûÀí¡­¡­\n" NOR);
                for (i = 0; i < DEL_TO; i++)
                {
                        // Ô­ÎÄÄÚÈİ
                        msg += sprintf("[" WHT "%3d" NOR "] %-31s %14s [" WHT "%10s" NOR "]\n"
                                       "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n%s\n",
                        i + 1,
                        notes[i]["title"],
                        notes[i]["author"] + "-" + notes[i]["owner"],
                        ctime(notes[i]["time"])[0..9],
                        notes[i]["msg"],);
                        // »Ø¸´ÄÚÈİ
                        if (sizeof(notes[i]["re"]))
                        {
                                for (j = 0; j < sizeof(notes[i]["re"]); j++)
                                {
                                        msg += sprintf("\n[ " WHT "»Ø¸´£º" NOR "%3d] %-26s %12s [" WHT "%10s" NOR "]\n"
                                                       "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n""%s\n",
                                        j + 1,
                                        notes[i]["re"][j]["title"],
                                        notes[i]["re"][j]["author"] + "-" +
                                        notes[i]["re"][j]["owner"],
                                        ctime(notes[i]["re"][j]["time"])[0..9],
                                        notes[i]["re"][j]["msg"],);
                                }
                        }
                }
#ifdef DEBUG
                me->start_more(msg);
#endif
                // 25 ÒÔÇ°µÄÌù×Ó½«±£´æµ½ /data/board/ÕâÀïµÄboard_id ÎÄ¼şÖĞ
                write_file(DATA_DIR + "board/" + query("board_id") + ".old", msg, SAVE_ALL_OLD_PLAN);
                // É¾³ıÄ¿Ç° board ÀïµÄ 25 ÒÔÇ°µÄÌù×Ó
                notes = notes[DEL_TO..sizeof(notes)-1];
                set("notes", notes);
                save();
                tell_object(me, HIR "¡­¡­ÕûÀíÍê±Ï£¬É¾³ı " HIW + (DEL_TO + 1) + HIR " ºÅÒÔÇ°µÄÌù×Ó¡£\n" NOR);
        }
        return;
}

void done_re(object me, mapping report, int project, int n, string text)
{
        int i;
        int t;
        int pl;
        string sign;
        string pure;
        mapping *notes, *reports;
        string *lines;
        mapping note;

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "ÄãµÄÁôÑÔÌ«³¤ÁË£¬ÇëÂÔÈ¥Ò»Ğ©²»±ØÒªµÄ¡£\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "ÄãµÄÁôÑÔÌ«³¤ÁË£¬ÇëÂÔÈ¥Ò»Ğ©²»±ØÒªµÄ¡£\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "ÄãµÄÁôÑÔÖĞ¶Ì¾äÌ«¶àÁË£¬Çëµ÷ÕûÒ»ÏÂÒÔ±ãËûÈËÔÄ¶Á¡£\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "ÄãÁôÑÔÖĞÓĞĞ©ĞĞÌ«³¤ÁË£¬Çë·ÖĞĞÒÔ±ãËûÈËÔÄ¶Á¡£\n");
                        return;
                }
        }

        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;
        } // else text += HIM "\n" + BBS + "\n" NOR;

        text = color_filter(text) + NOR;
        report["msg"] = text;

        notes = query("notes");
        reports = notes[project]["re"];

        if (! arrayp(reports))
                reports = ({ report });
        else
                reports += ({ report });

        notes[project]["re"] = reports;
        notes[project]["time"] = time();

        set("notes", notes);
        tell_object(me, HIW "»Ø¸´Íê±Ï¡£\n" NOR);

        save();
        return;
}

int do_post(string arg, int n)
{
        mapping note, fam;
        int noname_board;
        string poster_lvl, family;
        object me = this_player();

        poster_lvl = query("poster_level");

        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)
                return notify_fail("±¾°å²»½ÓÊÜÄãµÄÍ¶¸å¡£\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("·Ç±¾ÅÉµÜ×Ó²»µÃÏò±¾°åÂÒÍ¿ÂÒĞ´¡£\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("ÄãÔİÊ±»¹Ã»ÓĞÈ¨Á¦ÔÚÕâÀï·¢±íÎÄÕÂ£¬ĞèÒª " WHT +
                                   NEED_EXP + NOR " µãĞŞÎªÖµ»òÕß " WHT + NEED_AGE + NOR " ËêµÄÄêÁä¡£\n");

        if (! arg) return notify_fail("ĞÂÌù×ÓÇëÖ¸¶¨Ò»¸ö±êÌâ¡£\n");

        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "ÎŞ±êÌâ";
        /*
        else
                arg = color_filter(arg) + NOR;
        */
        if (strlen(arg) > MAX_TITLE_LEN)
                return notify_fail("Õâ¸ö±êÌâÌ«³¤ÁË£¬Çë»»Ò»¸ö¼ò½àÒ»µãµÄ¡£\n");

        note = allocate_mapping(5);
        note["title"] = arg;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "ÄäÃû";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_post, me, note, n :));
        return 1;
}

int do_re(string arg, int n)
{
        int num, noname_board;
        string title;
        mapping note, *notes, fam;
        string poster_lvl, family;
        object me = this_player();

        poster_lvl = query("poster_level");

        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)

                return notify_fail("±¾°å²»½ÓÊÜÄãµÄÍ¶¸å¡£\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("·Ç±¾ÅÉµÜ×Ó²»µÃÏò±¾°åÂÒÍ¿ÂÒĞ´¡£\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("ÄãÔİÊ±»¹Ã»ÓĞÈ¨Á¦ÔÚÕâÀï·¢±íÎÄÕÂ£¬ĞèÒª " WHT +
                                   NEED_EXP + NOR " µãĞŞÎªÖµ»òÕß " WHT + NEED_AGE + NOR " ËêµÄÄêÁä¡£\n");

        if (! arg) return notify_fail("Ö¸Áî¸ñÊ½£ºre <Ìù×Ó±àºÅ>.<»Ø¸´±êÌâ> with <Ç©Ãûµµ>\n");

        if (sscanf(arg, "%d.%s", num, title) < 1)
                return notify_fail("Ö¸Áî¸ñÊ½£ºre <Ìù×Ó±àºÅ>.<»Ø¸´±êÌâ> with <Ç©Ãûµµ>\n");

        if (sscanf(arg, "%d.%s with %d", num, title, n) != 3
                && sscanf(arg, "%d with %d", num, n) != 2)
                n = 0;

        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                return notify_fail("Ã»ÓĞÕâ¸öÌù×Ó¡£\n");

        if (strlen(title)>MAX_TITLE_LEN)
                return notify_fail("Õâ¸ö±êÌâÌ«³¤ÁË£¬Çë»»Ò»¸ö¼ò½àÒ»µãµÄ¡£\n");

        if (! title) title = "Re: " + notes[num - 1]["title"];
        /*
        else
                title = color_filter(title) + NOR;
        */

        note = allocate_mapping(5);
        note["title"] = title;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "ÄäÃû";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_re, me, note, num - 1, n :));
        return 1;
}

int do_followup(string arg)
{
        int n, num, noname_board;
        string title, file, msg = "";
        mapping note, *notes, fam;
        string poster_lvl, family;
        object me = this_player();

        poster_lvl = query("poster_level");

        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)

                return notify_fail("±¾°å²»½ÓÊÜÄãµÄÍ¶¸å¡£\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("·Ç±¾ÅÉµÜ×Ó²»µÃÏò±¾°åÂÒÍ¿ÂÒĞ´¡£\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("ÄãÔİÊ±»¹Ã»ÓĞÈ¨Á¦ÔÚÕâÀï·¢±íÎÄÕÂ£¬ĞèÒª " WHT +
                                   NEED_EXP + NOR " µãĞŞÎªÖµ»òÕß " WHT + NEED_AGE + NOR " ËêµÄÄêÁä¡£\n");

	if( !arg )
		return notify_fail("ÇëÊäÈëÓû»Ø¸²µÄÎÄÕÂ±àºÅ»ò last »Ø¸²×îºóÒ»ÆªÎÄÕÂ¡£\n");

        notes = query("notes");

	if( arg == "last" ) num = sizeof(notes);
	else
        if (sscanf(arg, "%d %s", num, title) < 1)
                return notify_fail("ÇëÊäÈëÓû»Ø¸²µÄÎÄÕÂ±àºÅ¡£\n");

        if (sscanf(arg, "%d %s with %d", num, title, n) != 3
                && sscanf(arg, "%d with %d", num, n) != 2)
                n = 0;

        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                return notify_fail("Ã»ÓĞÕâÕÅÁôÑÔ¡£\n");

        if (title && strlen(title) > MAX_TITLE_LEN)
                return notify_fail("Õâ¸ö±êÌâÌ«³¤ÁË£¬Çë»»Ò»¸ö¼ò½àÒ»µãµÄ¡£\n");

	num--;
	file = notes[num]["msg"];

	foreach( string word in explode( file, "\n" ) )
	{
		if( word == "" || word[0..7]=="[1;30m>" ) continue;
		else if( word[0..5] == "[33m>" ) msg += "[1;30m> "+word[5..]+"\n";
		else if( word[0..5] == "[36m>" ) msg += "[33m> "+word[5..]+"\n";
		else msg += "[36m> "+word+"\n";
	}

	if( msg[0..5] == "[36m>" )
		msg = "[36m> ¡ò" + notes[num]["author"] + " ÔÚ " + ctime(notes[num]["time"]) + " ÁôÏÂÕâÆªÁôÑÔ£º\n" + msg;

	msg += "\n¡ò" + me->query_idname() + " ÔÚ " + ctime(time()) + " ÁôÏÂÕâÆªÁôÑÔ£º\n";

	note = allocate_mapping(5);
	if (! title)
		title = (notes[num]["title"][0..5] != "»Ø¸²£º" ? "»Ø¸²£º" : "") + notes[num]["title"];

        note["title"] = title;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "ÄäÃû";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_post, me, note, n :), msg);
        return 1;
}

int do_read(string arg)
{
        int num, rep, last_read_time, i, last, arc, private_board;
        mapping *notes, fam;
        string myid, msg, file;
        string family;
        object me = this_player();

        last_read_time = me->query("board_last_read/" + query("board_id"));
        myid    = query("board_id");
        notes   = query("notes");
        arc = query("wizard_only");
        private_board = query("private_board");

        if (arc && ! wizardp(me))
                return notify_fail("Î×Ê¦ÄÚ²¿½»Á÷²»µÃ¿úÊÓ¡£\n");

        family = query("poster_family");
        fam = me->query("family");

        //write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && ! wizardp(me)
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("·Ç±¾ÅÉµÜ×Ó²»µÃ¿úÊÓ±¾ÅÉÄÚ²¿½»Á÷¡£\n");

        if (! pointerp(notes) || ! sizeof(notes))
                return notify_fail("°å×ÓÉÏÄ¿Ç°Ã»ÓĞÈÎºÎÌù×Ó¡£\n");

        if (! arg) return notify_fail("Ö¸Áî¸ñÊ½£ºread <Ìù×Ó±àºÅ>[.<»Ø¸´±àºÅ>]|new|next|old\n");

        // ÏÔÊ¾ÒÔÇ°±¸·İµÄ¾ÉÌù×Ó
        if (arg == "old")
        {
                file = DATA_DIR + "board/" + query("board_id") + ".old";
                if (file_size(file) <= 0)
                        return notify_fail("¶Ô²»Æğ£¬Ä¿Ç°±¾°æÃ»ÓĞ±£´æµÄ¾ÉÌù¡£\n");
                else
                {
                        if (private_board && ! wizardp(me))
                                return notify_fail("¶Ô²»Æğ£¬ÓÉÓÚ¾ÉÌùÉæ¼°µ½Ò»Ğ©¸öÈËÒşË½£¬¹Ê²»¿ª·ÅÔÄ¶Á¡£\n");

                        msg = read_file(file);
                        me->start_more(msg);
                        return 1;
                }
        }
        // ÏÔÊ¾Î´¶ÁµÄÌù×Ó
        if (arg == "new" || arg == "next")
        {
                if (! intp(last_read_time) || undefinedp(last_read_time))
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
                                if (notes[num-1]["time"] > last_read_time)
                                {
                                        if (private_board)
                                        {
                                                if (wizardp(me)) break;
                                                else
                                                if (! strcmp(me->query("id"), notes[num - 1]["owner"]))
                                                        break;
                                        } else
                                                break;
                                }

        } else
        if (sscanf(arg, "%d.%d", num, rep) == 2)
        {
                if (num < 1 || num > sizeof(notes))
                        return notify_fail("Ã»ÓĞÕâ¸öÌù×Ó¡£\n");
                else num--;

                if (! wizardp(me) && private_board && strcmp(me->query("id"), notes[num]["owner"]))
                        return notify_fail("Õâ¸öÌû×Ó²»ÊÇÄãÁôµÄ£¬ËùÒÔÄã²»ÄÜÔÄ¶Á¡£\n");

                if (rep < 1 || rep > sizeof(notes[num]["re"]))
                        return notify_fail("Ã»ÓĞÕâ¸ö»Ø¸´¡£\n");
                else rep --;

                me->start_more(sprintf("[ " HIW "±àºÅ£º" NOR "%3d | " HIW "»Ø¸´±àºÅ£º" NOR "%3d] [ " HIW "Ô­Ìâ£º" NOR "%-27s ] \n"
                               "[ " HIW "»Ø¸´±êÌâ£º" NOR "%-51s ]\n©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"
                               "%s\n©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n[ " HIW "Ê±¼ä£º" NOR "%s ] [ "
                               HIW "×÷Õß£º" NOR " %19s]\n",
                               num + 1, rep + 1,
                               notes[num]["title"],
                               notes[num]["re"][rep]["title"],
                               notes[num]["re"][rep]["msg"] + HIM "\n" + BBS + "\n" NOR,
                               ctime(notes[num]["re"][rep]["time"]),
                               notes[num]["re"][rep]["author"] + "(" +
                               notes[num]["re"][rep]["owner"] + ")"));

                if (notes[num]["time"] > last_read_time)
                        me->set("board_last_read/" + query("board_id"),
                               notes[num]["time"]);

                return 1;
        } else
        if (! sscanf(arg, "%d", num))
                return notify_fail("ÄãÒª¶ÁµÚ¼¸¸öÌù×ÓµÄ»Ø¸´£¿\n");

        if (num < 1 || num > sizeof(notes))
                return notify_fail("Ã»ÓĞÕâ¸öÌù×Ó¡£\n");
        num--;

        if (! wizardp(me) && private_board && strcmp(me->query("id"), notes[num]["owner"]))
                return notify_fail("Õâ¸öÌû×Ó²»ÊÇÄãÁôµÄ£¬ËùÒÔÄã²»ÄÜÔÄ¶Á¡£\n");

        msg = sprintf("[ " HIW "±àºÅ£º" NOR "%3d ] [ " HIW "×÷Õß£º" NOR "%20s ] [ " HIW "Ê±¼ä£º" NOR "%-9s ]\n[ "
                      HIW "±êÌâ£º" NOR "%-55s ]\n©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤" WHT "[Content-]" NOR "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n%s\n"
                      "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤" WHT "[-End]" NOR "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n",
                      num + 1,
                      notes[num]["author"] + "(" + notes[num]["owner"] + ")",
                      ctime(notes[num]["time"])[0..9],
                      notes[num]["title"],
                      notes[num]["msg"] + HIM "\n" + BBS + "\n" NOR);
        // ÏÔÊ¾»Ø¸´µÄÊıÄ¿
        if (sizeof(notes[num]["re"]) && me->query("env/show_reply") != "all")
                msg += sprintf(HIW "»Ø¸´£º" NOR "%d ·İ¡£\n", sizeof(notes[num]["re"]));

        // ÏÔÊ¾×îºóµÄÒ»¸ö»Ø¸´
        if (me->query("env/show_reply") == "last")
        {
                last = sizeof(notes[num]["re"]) - 1;
                msg += sprintf(
                               "\n[ " HIW "»Ø¸´±àºÅ£º" NOR "%3d] [ " HIW "»Ø¸´±êÌâ£º" NOR "%-34s ] \n"
                               "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"
                               "%s\n©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n[ " HIW "Ê±¼ä£º" NOR "%s ] [ "
                               HIW "×÷Õß£º" NOR " %19s]\n",
                               last + 1,
                               notes[num]["re"][last]["title"],
                               notes[num]["re"][last]["msg"] + HIM "\n" + BBS + "\n" NOR,
                               ctime(notes[num]["re"][last]["time"]),
                               notes[num]["re"][last]["author"] + "(" +
                               notes[num]["re"][last]["owner"] + ")");
        }
        // ÏÔÊ¾ËùÓĞµÄ»Ø¸´
        if (me->query("env/show_reply") == "all")
        {
                for (i = 0; i < sizeof(notes[num]["re"]); i++)
                {
                        msg += sprintf(
                                       "\n[ " HIW "»Ø¸´±àºÅ£º" NOR "%3d] [ " HIW "»Ø¸´±êÌâ£º" NOR "%-34s ] \n"
                                       "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"
                                       "%s\n©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n[ " HIW "Ê±¼ä£º" NOR "%s ] [ "
                                       HIW "×÷Õß£º" NOR " %19s]\n",
                                       i+1,
                                       notes[num]["re"][i]["title"],
                                       notes[num]["re"][i]["msg"] + HIM "\n" + BBS + "\n" NOR,
                                       ctime(notes[num]["re"][i]["time"]),
                                       notes[num]["re"][i]["author"] + "(" +
                                       notes[num]["re"][i]["owner"] + ")");
                }
        }
        me->start_more(msg);

        if (notes[num]["time"] > last_read_time)
                me->set("board_last_read/" + query("board_id"),
                        notes[num]["time"]);

        return 1;
}


int do_banzhu(string arg)
{
        if (! arg) return notify_fail("Ö¸Áî¸ñÊ½£º banzhu <°æÖ÷id>\n");

        if (! stringp(arg) || strlen(arg) < 3)
                return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");

        if (query("banzhu") == arg)
                return notify_fail("Ä¿Ç°µÄ°æÖ÷¾ÍÊÇ " + arg + "£¬²»ĞèÒªÉèÖÃ¡£\n");

        if (SECURITY_D->get_status(this_player(1)) != "(admin)" &&
            query("owner_id") != this_player()->query("id"))
                return notify_fail("Äã²»ÊÇÌìÉñ£¬²»¿ÉÒÔÉèÖÃ°æÖ÷¡£\n");

        set("banzhu", arg);
        write("ÉèÖÃ " HIW + arg + NOR " Îª" + name() + "°æÖ÷³É¹¦¡£\n");
        save();
        return 1;
}

int delete_post(string arg)
{
        mapping *notes;
        int num, re_num;

        if (! arg ||sscanf(arg, "%d.%d", num, re_num) < 1)
                return notify_fail("Ö¸Áî¸ñÊ½£ºdelete <Ìù×Ó±àºÅ>[.<»Ø¸´±àºÅ>]\n");

        notes = query("notes");
        if (! arrayp(notes)|| num < 1 || num > sizeof(notes))
                return notify_fail("Ã»ÓĞÕâÕÅÌù×Ó¡£\n");

        else
        if (re_num)
        {
                if (re_num < 1 || ! arrayp(notes[num - 1]["re"])
                        || re_num > sizeof(notes[num - 1]["re"]))
                        return notify_fail("Ã»ÓĞÕâÕÅ»Ø¸´¡£\n");
                else
                {
                        num--;
                        re_num--;

                        if (notes[num]["re"][re_num]["owner"] != (string)this_player(1)->query("id")
                                && query("banzhu") != this_player(1)->query("id")
                                && (string)SECURITY_D->get_status(this_player(1)) != "(admin)")
                                return notify_fail("Õâ¸ö»Ø¸´²»ÊÇÄãĞ´µÄ£¬ÄãÓÖ²»ÊÇ°æÖ÷¡£\n");

                        else
                        {
                                notes[num]["re"] = notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
                                set("notes", notes);
                                write("É¾³ıµÚ " + (num+1) + " ºÅÌù×ÓµÄµÚ "+ (re_num + 1) + " ºÅ»Ø¸´....Ok¡£\n");
                                save();
                                return 1;
                        }
                }
        } else
        {
                num--;
                if (notes[num]["owner"] != (string)this_player(1)->query("id")
                        && query("banzhu") != this_player(1)->query("id")
                        && (string)SECURITY_D->get_status(this_player(1)) != "(admin)")
                        return notify_fail("Õâ¸öÌù×Ó²»ÊÇÄãĞ´µÄ£¬ÄãÓÖ²»ÊÇ°æÖ÷¡£\n");

                notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
                set("notes", notes);
                write("É¾³ıµÚ " + (num + 1) + " ºÅÌù×Ó....Ok¡£\n");
                save();
                return 1;
        }
}


int do_search(string arg)
{
        mapping *notes;
        int i, last_time_read, j = 0;
        string msg, topic, note;
        object me = this_player();

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "Ä¿Ç°Ã»ÓĞÈÎºÎÌû×Ó¡£\n");
                return 1;
        }

        if (! arg)
        {
                tell_object(me, "ÄãÏëËÑË÷ÄÇÒ»ÌõÌû×Ó£¿\n");
                return 1;
        }

        if (sscanf(arg, "%s %s", topic, arg) != 2)
        {
                tell_object(me, "ÄãÖ»ÄÜËÑË÷±êÌâ(title)¡¢×÷Õß(author)¡¢ÄÚÈİ(document)¡£\n");
                return 1;
        } else
        {
                if (topic == "title") note = "±êÌâ";
                else
                if (topic == "author") note = "×÷Õß";
                else
                if (topic == "document") note = "ÄÚÈİ";
                else
                {
                        tell_object(me, "ÄãÖ»ÄÜËÑË÷±êÌâ(title)¡¢×÷Õß(author)¡¢ÄÚÈİ(document)¡£\n");
                        return 1;
                }
        }

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        i = sizeof(notes);

        msg = sprintf("¸ù¾İ " HIY "%s" NOR " ËÑË÷ " HIY "%s" NOR " µÃµ½ÈçÏÂ·ûºÏÌõ¼şÌû×Ó£º\n"
                      HIW "±àºÅ©¤©¤±êÌâ©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤×÷Õß©¤»Ø¸´©¤©¤©¤Ê±¼ä©¤©¤©¤©¤©¤\n" NOR,
                      arg, note);

        while (i--)
        {
                if (topic == "document")
                {
                        if (strsrch(notes[i]["msg"], arg) == -1)
                                continue;
                } else
                {
                        if (strsrch(notes[i][topic], arg) == -1)
                                continue;
                }

                msg += sprintf("%s[" WHT "%3d" NOR "]" NOR "  %-29s %12s " WHT "%+3d" NOR "   [%s]\n",
                               (notes[i]["time"] > last_time_read ? HIY: ""),
                               i + 1, notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]),
                               ctime(notes[i]["time"])[0..15] );

                j++;
                if (j > 19)
                {
                        msg += "ÓÉÓÚËÑË÷µ½µÄ½á¹ûÌ«¶à£¬Òò´ËÖ»ÏÔÊ¾¶şÊ®ÌõÁôÑÔ£¬ÇëÊ¹ÓÃ¸üÃ÷È·µÄ¹Ø¼ü×Ö|´Ê¡£\n";
                        break;
                }
        }

        if (j == 0)
        {
                tell_object(me, "¸ù¾İ " HIY + arg + NOR " ËÑË÷ " HIY + note + NOR " Ã»ÓĞÕÒµ½·ûºÏÌõ¼şµÄÌû×Ó¡£\n");
                return 1;
        }

        msg += HIW "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n" NOR;
        me->start_more(msg);
        return 1;
}

