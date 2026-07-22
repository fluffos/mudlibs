// newsd.c
// Last Modified By Pkyou@xyj 2002-06-12 19:00
// Update by waiwai@2003/04/09
// 时间格式修改

// Update by jingxue 12.25.2004 for xycq3
// Update by amy 4.12.2005 for xycq
// Update by god 14.6.2005 for xycq3


#include <command.h>
#include <getconfig.h>
#include <mudlib.h>
/*
#pragma optimize
#pragma save_binary
*/

#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;

// 最多一千条新闻
#define MAX_NEWS_CAPACITY       1000
int     last_update_day = 0;
mapping family_priority = ([ ]);

void create()
{
        seteuid(getuid());
        restore();
      set("channel_id","游戏更新");
        set_heart_beat(300);
}
void remove()
{
        save();
}

void mud_shutdown()
{
        save();
}

// prompt user
void prompt_user(object me)
{
        int num;
        int total;
        mapping *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        if (! last_read_time)
        {//added pkyou@xyj 写描述真累！
                
                tell_object(me, HIG "\n你有新的消息没有查看，请用"WHT"news"HIG"来查看最新的天界消息。\n\n" NOR);
/*
                me->set("last_read_news", time());
                // Added by waiwai@2003/04/20

                if( me->query("new_player") ) {
                me->delete("new_player");
                }
                me->set("last_read_news", 0);
                call_out("auto_notice",10+random(10),me); 
*/
                return;
        }

        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes);
        total = 0;
        while (num--)
                if (notes[num]["time"] > last_read_time)
                        total++;
                else
                        break;

        if (! total) {
        // Added by waiwai@2003/04/09
        if(me->query("mud_age")>0)
        write(RED"  → "NOR"您已经在"+MUDLIB_NAME+"的世界里经历了" + FINGER_D->age_string( (int)me->query("mud_age")) + 
        "的岁月了。。。\n"NOR);
        }
        else
                tell_object(me, sprintf(GRN "\n你目前一共有 " YEL "%d" NOR
                                        GRN " 条来自天界的消息还没有得知。\n请您立即使用 "
                                        WHT "news" NOR GRN " 咒文查看最新的升级更新情况。\n" NOR, total));
/*
        // 开始定时通知
        if (previous_object() == find_object(LOGIN_D))
            //    call_out((: call_other, __FILE__, "auto_notice", me :), me), 10 + random(10);
        call_out("auto_notice",10+random(10),me); 
*/
}

// show all the news's title
// raw = 1: only show the non-read news
void show_news(object me, int raw)
{
        mapping *notes;
        int i, i2, last_time_read;
        string msg;

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes)) {
                tell_object(me, MUDLIB_NAME+"天神们没有发布任何消息。\n");
                return;
        }

        last_time_read = me->query("last_read_news");
        i = sizeof(notes);
        i2 = sizeof(notes)-last_time_read;

        msg = "目前"+MUDLIB_NAME+"发布的最新公告如下。\n"
              GRN "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" NOR;
        while (i--) {
                if (raw && (notes[i]["time"] <= last_time_read))
                        break;

                msg += sprintf("%s[%3d]%-39s %18s [%s]\n",
                               (notes[i]["time"] > last_time_read ? HIR"(未读)"NOR:WHT"(已读)"NOR),
                               i + 1, notes[i]["title"],
                               notes[i]["author"], 
                                BJTIME_CMD->chinese_time(8, ctime(notes[i]["time"])));
        }
        if (i == sizeof(notes) - 1) {
                tell_object(me, "目前没有任何未查看过的消息。\n");
                return;
        } 

        msg += GRN "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"HIR+MUDLIB_NAME+NOR GRN"━━━━━\n" NOR;

        me->start_more(msg);
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, int n, string text)
{
        int i;
      //  int t;
        int pl;
        string sign;
        string pure;
        mapping *notes;

/*
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
        }

        text = color_filter(text) + NOR;
*/
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

        // Truncate the notes if maximum capacity exceeded.
        if (sizeof(notes) > MAX_NEWS_CAPACITY)
                notes = notes[MAX_NEWS_CAPACITY / 4 .. MAX_NEWS_CAPACITY];

        set("notes", notes);
        tell_object(me, "新闻发布完毕。\n");
    message("shout",HIC"\n【谈天说地】系统公告："+MUDLIB_NAME+HIC"有最新新闻发布！请用 "BLINK HIR"news new "NOR HIC"了解详细情况 \n\n"NOR, users());

        save();
}

// post a news
void do_post(object me, string arg)
{
        int n,i;
        mapping note;
        string sign;

        if (! wizardp(me) || ! interactive(me))
        {
                tell_object(me, "只有巫师才能发布新闻。\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "发布新闻请指定一个标题。\n");
                return;
        }

        // Added By waiwai@2003/04/09 这里为了规范显示，限制了标题长度
        if (strlen(arg) > 100)
        {
                tell_object(me, "标题过长,请控制在20个中文字符以内。\n");
                return;
        }

        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "无标题";
/*
        else
                arg = color_filter(arg) + NOR;
*/
        note = allocate_mapping(5);
        note["title"] = arg;
        note["author"] = me->name(1) + "-" + me->query("id");
        note["time"] = time();

/*  
        if (! n) sign = me->query("qmd/wizqmd");
        if (n && ! stringp(sign = me->query(sprintf("qmd/wizqmd%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("qmd/wizqmd%d", i));
                        if (stringp(sign)) break;
                }
        }
        if (stringp(sign))
                note["qmd"] = sign+NOR;
        else
                note["qmd"] = "";
*/
        me->edit((: call_other, __FILE__, "done_post", me, note, 0 :), me);
}

// read a news
void do_read(object me, string arg)
{
        int num;
        mapping *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "目前没有任何消息。\n");
                return;
        }

        if (! arg)
        {
                tell_object(me, "你想读那一条消息？\n");
                return;
        }

        if (arg == "new" || arg == "next")
        {
                if (! last_read_time)
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
                                if (notes[num - 1]["time"] > last_read_time)
                                        break;
        } else
        if (! sscanf(arg, "%d", num))
        {
                tell_object(me, "你要读第几条消息？\n");
                return;
        }

        if (num < 1 || num > sizeof(notes))
        {
                tell_object(me, "没有这条新闻。\n");
                return;
        }
        num--;
        me->start_more(sprintf("[%d] %-41s %s [%s]\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n",
                               num + 1, notes[num]["title"], notes[num]["author"],
                               BJTIME_CMD->chinese_time(8, ctime(notes[num]["time"])))+
                               notes[num]["msg"]+
         "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"+MUDLIB_NAME+"━━━━━");

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
}

// discard a news
void do_discard(object me, string arg)
{
        mapping *notes;
        int num;
        string author, aid;

        if (! arg || sscanf(arg, "%d", num) != 1)
        {
                tell_object(me, "你想去掉哪一条新闻？\n");
                return;
        }

        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
        {
                tell_object(me, "没有这条新闻。\n");
                return;
        }

        num--;

        if ((! stringp(author = notes[num]["author"]) ||
             sscanf(author, "%*s-%s", aid) != 2 ||
             aid != me->query("id")) &&
            (string)SECURITY_D->get_status(me) != "(admin)")
        {
                tell_object(me, "只有天神才能去掉他人发布的新闻。\n");
                return;
        }

        notes = notes[0..num - 1] + notes[num + 1..sizeof(notes) - 1];
        set("notes", notes);
        save();
        tell_object(me, "删除第 " + (num + 1) + " 条新闻....Ok。\n");
}

/*
// auto notice user
void auto_notice(object me)
{
        int num;
        mapping *notes;
        string msg;
        int last_read_time;

        if (! objectp(me))
                return;

        last_read_time = me->query("last_read_news");
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes) - 1;
        if (notes[num]["time"] <= last_read_time)
                return;

        // some news need read, start next call out
       // call_out((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30);
call_out("auto_notice",10+random(10),me); 
        if (! living(me) || me->query_temp("block_msg/all"))
                return;

        while (num-- > 0)
        {
                if (notes[num]["time"] <= last_read_time)
                {
                        num++;
                        break;
                }

                // contine to find next
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = GRN "\n一阵烟雾过后，土地老儿出现在你的面前，只见"
                      "\n那土地慌慌张张的趴在你耳朵边上嘀咕了几句。\n" NOR;
                break;
        case 1:
                msg = GRN "\n地上突然开了一个裂缝，冒出一个白发大胡子的土"
                      "\n地老儿，对着你鞠了个躬，然后喋喋不休的唠叨起来。\n" NOR;
                break;
        case 2:
                msg = GRN "\n你忽然听见有人喊你“上仙留步”，你回头一看"
                      "\n原来是土地老儿满头大汗的在追着叫你。\n" NOR;
                break;
        case 3:
                msg = GRN "\n突然你眼前出现一股白色的烟雾，待烟雾散去以后"
                      "\n只见一个土地老儿跪在地上说到：“上仙驾到，有失远迎”。\n" NOR;
                break;
        default:
                msg = GRN "\n一道金光闪过，土地从一股烟雾中出现在你的面前，"
                      "\n土地对你鞠了个躬说道：“小仙在此恭候大驾多时了”。\n" NOR;
                break;
        }

        msg += HIG "土地(tu di)告诉你：请看来自"+MUDLIB_NAME+"天界最新的消息：\n" NOR;
        tell_object(me, msg);
        me->start_more(sprintf("[%d] %-" + (41 + color_len(notes[num]["title"])) +
                               "s %s [%s]\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n",
                               num + 1, notes[num]["title"], notes[num]["author"],
                               BJTIME_CMD->chinese_time(8, ctime(notes[num]["time"]))) + 
         notes[num]["msg"]+
         "\n"+sprintf("%s\n"NOR,notes[num]["qmd"])+
         "\n━━━━━━━━━━━━━━━━━━━━━━━━━"+MUDLIB_FULL_NAME+"━━━━━");

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me,  "\n土地说完后，消失在一阵烟雾之中。\n" );
}
*/
string query_save_file() { return DATA_DIR "newsd"; }


