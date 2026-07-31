// This program is a part of NITAN MudLIB 
// redl 2013/11
#include <ansi.h>
#include <skill.h>

inherit ITEM;
inherit F_CLEAN_UP;
#define SKILLS_D	"/adm/daemons/skillsd"
mapping *booklists = ({
                (["id":"guangming-jing",
                        "tname":"大云光明经",
                        "rate":1000,
                       // "fam":"明教"
                        ]),
                (["id":"cibei-dao",
                        "tname":"慈悲刀",
                        "rate":1000
                        ]),
                (["id":"cuixin-zhang",
                        "tname":"摧心掌",
                        "rate":1000
                        ]),
                (["id":"literate",
                        "tname":"读书写字",
                        "rate":1000
                        ]),
                (["id":"luohan-quan",
                        "tname":"罗汉拳",
                        "rate":1000
                        ]),	
				(["id":"shenxing-baibian",
                        "tname":"神行百变",
                        "rate":1000
                        ]),
				(["id":"force",
                        "tname":"内功",
                        "rate":1000
                        ]),
						
        });


void create()
{
        set_name(NOR BRED YEL "『" NOR BRED HIW "万象天书" NOR BRED YEL "』" NOR, ({"wanxiang book", "book"}));
        set_weight(5);
                set("unit", "本");
                set("value", 1000);
                set("weight", 5);
				set("yuanbao", 5);
                set("material", "paper");
                set("longx", "这是本玄奥无比的书籍，化身千万，可以打开(open book)试试。\n");
                set("set_data", 1); 
                set("auto_load", 1); 
                set("no_sell", 1);
               // set("no_pawn", 1);        
                setup();
        if (query("opened")) {
                set_name(query("opened/name"), ({ query("opened/skill") + " book", "wanxiang book", "book"}));
                switch(query("opened/type")) {
                        case 1:
                                set("longx", "这是一本武学补遗，你(read)后可以学会「"+query("opened/can_perform")+"」的使用诀窍。\n");
                                break;
                        case 2:
                                set("longx", "这是一本武学秘笈，你(read)后可以提高『"+query("opened/tname")+"』的修为。\n");
                                break;
                        case 3:
                                set("longx", "这是一本技能秘籍，你(read)后可以提高『"+query("opened/tname")+"』的知识。\n");
                                break;
                }
        }
}        

string long()
{
        return query("longx");
}

int do_open(string arg)
{
        int i, k, rate, *rates = ({}), totalrate = 0, rndrate;
        string oldname, pfmpath, *pfmfs = ({}), rndpfm, *tname = ({}), *skid = ({});
        mixed *pfmfiles;
        mapping b;
        object me = this_player();
        
        if (!arg || (arg!=query("id") && arg!="book")) return 0;
        
        if (!query("no_open_msg") && me && playerp(me) && wiz_level(me) < 5) {
                me->start_busy(1);
        }

        if (query("opened")) return notify_fail(NOR "这本书已经打开了啊，好好研究(look)它吧。\n" NOR);

        oldname = query("name");
        
        for(i=0; i<sizeof(booklists); i++) {
                rate = booklists[i]["rate"];
                totalrate += rate;
                rates += ({rate});
                tname += ({booklists[i]["tname"]});
                skid += ({booklists[i]["id"]});
        }
        
        rndrate = random(totalrate);
        totalrate = 0;
        
        for(i=0; i<sizeof(rates); i++) {
                //write("totalrate:" + (string)totalrate + "\n");
                if (rndrate >= totalrate && rndrate < (totalrate + rates[i])) {
                        set("opened/skill", skid[i]);
                        set("opened/tname", tname[i]);
                        if (booklists[i]["fam"]) set("opened/fam", booklists[i]["fam"]);
                        if ( (string) SKILL_D(skid[i])->type() == "martial" ) {
                                if (!booklists[i]["no_learn_pfm"]) {
                                        pfmpath = "/kungfu/skill/" + skid[i] + "/";
                                        if (SKILL_D(skid[i])->valid_enable("force")) pfmpath += "perform/";
                                }
                                if (pfmpath && file_size(pfmpath) == -2) {
                                        pfmfiles = get_dir(pfmpath, -1);
                                        if (pfmfiles && sizeof(pfmfiles)) {
                                for (k = 0; k < sizeof(pfmfiles); k++)
                                {
                                        if (pfmfiles[k][0][strlen(pfmfiles[k][0])-2..strlen(pfmfiles[k][0])] != ".c")
                                                                                     continue;
                                        pfmfs += ({replace_string(pfmfiles[k][0], ".c", "")});
                                }
                                                if (pfmfs && sizeof(pfmfs)) rndpfm = pfmfs[random(sizeof(pfmfs))];
                                        }
                                }
                                if (random(25)==0 && rndpfm) {//极小几率，并且随机至少有一个pfm的情况下
                                        set("opened/name", NOR+YEL+"『"+YEL+tname[i]+NOR+YEL+"·"+YEL+"补遗"+NOR+YEL+"』"+NOR);
                                        set("longx", "这是一本武学补遗，你(read)后可以学会「"+rndpfm+"」的使用诀窍。\n");
                                        set("opened/type", 1);
                                        set("opened/can_perform", rndpfm);
                                } else {
                                        set("opened/name", NOR+YEL+"『"+WHT+tname[i]+NOR+YEL+"·"+WHT+"秘笈"+NOR+YEL+"』"+NOR);
                                        set("longx", "这是一本武学秘笈，你(read)后可以提高『"+tname[i]+"』的修为。\n");
                                        set("opened/type", 2);
                                }
                        } else {
                                set("opened/name", NOR+YEL+"『"+CYN+tname[i]+NOR+YEL+"·"+CYN+"秘籍"+NOR+YEL+"』"+NOR);
                                set("longx", "这是一本技能秘籍，你(read)后可以提高『"+tname[i]+"』的知识。\n");
                                set("opened/type", 3);
                        }
                        break;
                }
                totalrate += rates[i];
        }
        set_name(query("opened/name"), ({ skid[i] + " book", "wanxiang book", "book"}));
        if (!query("no_open_msg")) message_vision(NOR + CYN + "$N" + NOR + CYN + "打开"+ oldname + NOR + CYN + "获得了一本" +query("name") + NOR + CYN + "。\n" + NOR, me);
        return rates[i];
}

int do_read(string arg)
{
        object me = this_player();
        string sks, pfm;
        int flagused = 0, diff, improve = 3000000;
        int pot = 100000;
                
        if (!arg || (arg!=query("id") && arg!="book")) return 0;

        if (me && playerp(me) && wiz_level(me) < 5) {
                me->start_busy(1);
        }
        
        if (!query("opened")) return notify_fail(NOR "这可是万象天书啊，打开(open)再研读吧。\n" NOR);
        
        if ( query("opened/type") == 1 && ( (me->query("potential")-me->query("learned_points"))<100000000 ) )
                return notify_fail(NOR "从万象天书上学习绝技需要１亿点潜能。\n" NOR);
        else if ( query("opened/type") == 2 && ((me->query("potential")-me->query("learned_points"))<1000000 ) )
                return notify_fail(NOR "阅读万象天书学习武功至少需要１００万点潜能。\n" NOR);
        else if ((me->query("potential")-me->query("learned_points"))<1000 )
                return notify_fail(NOR "阅读万象天书学习知识至少需要１０００点潜能。\n" NOR);
        
        sks = query("opened/skill");
        
        improve *= (me->query("int") / 5) + 12;//已测试，先天40int的id要达到150level，没有diff的也需要吃12本
                switch(query("opened/type")) {
                        case 1:
                                pfm = query("opened/can_perform");
                                if ( me->query_skillo(sks, 1)>149 ) {
                                        me->set("can_perform/" + sks + "/" + pfm, 1);
                                        tell_object(me, NOR + "你冥思苦想，终于从万象天书上习得了「"+pfm+"」的绝技。\n" + NOR);
                                        me->addn("potential", -100000000);
                                        flagused = 1;
                                } else {
                                        tell_object(me, NOR + "你还不会「"+query("opened/tname")+"」或者低于１５０级。 \n" + NOR);
                                }
                                break;
                        case 2:
                                        diff = SKILLS_D->query_skill_difficult(sks); 
                                        if (! diff) diff = SKILL_D(sks)->difficult_level(); 
                                        improve = improve / (300 + diff); 
                                        if (improve < 500) improve = 500; 
                                        if (!me->can_improve_skill(sks)) {
                                                write(NOR + "也许是缺乏实战修为，你感到难以继续研究「" + query("opened/tname") + "」的问题了。\n" + NOR); 
                                        } else if (query("opened/fam") && query("opened/fam")!=me->query("family/family_name")) {
                                                write(NOR + "只有" + query("opened/fam") + "的弟子才能研究「" + query("opened/tname") + "」。\n" + NOR); 
                                        } else {
                                                me->improve_skill(sks, improve); 
                                                write(NOR "你研究了一会，似乎对「"+query("opened/tname")+"」有些新的领悟。\n" + NOR); 
                                        me->addn("potential", -1000000);
                                                flagused = 1;
                                        }
                                break;
                        case 3:
                                if (query("opened/fam") && query("opened/fam")!=me->query("family/family_name")) {
                                                write(NOR + "只有" + query("opened/fam") + "的弟子才能学习「" + query("opened/tname") + "」。\n" + NOR); 
                                        } else if ( me->query_skillo(sks, 1)<5000 || sks=="literate" ) {
                                                me->improve_skill(sks, improve / 800); 
                                                write(NOR "你研究了一会，似乎对「"+query("opened/tname")+"」有些新的领悟。\n" + NOR); 
                                        me->addn("potential", -1000);
                                                flagused = 1;
                                } else {
                                        tell_object(me, NOR + "你的「"+query("opened/tname")+"」超过了５０００级，已经无法再从万象天书上学习了。 \n" + NOR);
                                }
                                break;
                }
    if (flagused) {
        message_vision(NOR + CYN + "$N" + NOR + CYN + "手里的" +query("name") + NOR + CYN + "一振化为飞灰。\n" + NOR, me);             
        destruct(this_object());
    }
        return 1;
}

int do_setsk(string arg)
{
        if (!arg) return notify_fail(NOR "要测试什么skill？\n" NOR);
        set("opened/skill", arg);
        set("opened/tname", arg);
        set("opened/type", 2);
        set("longx", "这是一本测试用的武学秘笈，(read book)\n");
        set_name("测试秘笈", ({"book"}));
        write("ok\n");
        return 1;
}

void init()
{
        add_action("do_open", "open");
        add_action("do_read", "read");
        if (wiz_level(this_player()) > 5) 
                add_action("do_setsk", "setsk");
}


