// only for wizard room test

#include <ansi.h>
inherit ROOM;
int do_listemote();
void create()
{
    set("short", "他自己的工作室");
    set("long",@LONG

───────────────────────────────────
aqm.暗器门  bt.白驼     bj.北京     bhd.冰火岛  gb.丐帮     dl.大理
dyd.钓鱼岛  em.峨嵋     gy.归云庄   gm.古墓     hs.华山     feng.风清扬  
lj.灵鹫     lz.灵州     mj.明教     mr.慕容     px.平西     pk.杀手帮  
qz.全真     qz2.泉州    ry.日月教   sl.少林     sz.苏州     ts.泰山  
th.桃花岛   wud.武当    xkd.侠客岛  xy.襄阳     xx.星宿     mz 梅庄 
tdh 天地会  wm 无名     wyy 王语嫣  duo.多隆    mg 蒙古     yideng 一灯
duanyu段誉  ywm 岳王墓 wxb 韦小宝
───────────────────────────────────
LONG
       );
    set("exits", ([
                "aqm":"/d/anqimen/zaixiang",
                "bt":"/d/baituo/dongjie",
                "bj":"/d/beijing/changanjie",
                "bhd":"/d/bhdao/shidong",
                "gb":"/d/city/gbxiaowu",
                "dl":"/d/dali/dadian",
                "dyd":"/d/diaoyudao/zhangqian",
                "em":"/d/emei/houshan/jxan",
                "gy":"/d/guiyunzhuang/guiyunting",
                "gm":"/d/gumu/dating",
                "hs":"/d/huashan/shufang",
                "fqy":"/d/huashan/feng",
                "lj":"/d/lingjiu/xiaowu",
                "lz":"/d/lingzhou/center",
                "mj":"/d/mingjiao/dadian",
                "mr":"/d/murong/yketing",
                "px":"/d/pingxiwangfu/dadao1",
                "pk":"/d/pker/guangchang",
                "qz":"/d/quanzhen/xuanzt",
                "qz2":"/d/quanzhou/zhongxin",
                "ry":"/d/riyuejiao/dadian1",
                "sl":"/d/shaolin/fzlou",
                "sz":"/d/suzhou/nandajie1",
                "ts":"/d/taishan/fengchan",
                "th":"/d/taohuadao/dating",
                "wud":"/d/wudang/houtang",
                "xkd":"/d/xiakedao/shishi1",
                "xy":"/d/xiangyang/xycenter",
                "xx":"/d/xingxiu/xxh2",
                "mz":"/d/riyuejiao/prison",
                "tdh":"/d/beijing/qingmutang",
                "wm":"/d/shaolin/hantan4",
                "wyy":"/d/murong/mzhulin",
                "duo":"/d/beijing/shiwei_office",
                "mg":"/d/xiangyang/caoyuan4",
                "yideng":"/d/dali/yideng/shiwu",
                "duanyu":"/d/dali/fudi",
                "ywm":"/d/yuewangmu/xiaodao3", 
"wxb":"/d/beijing/dating",

                "down":"/d/wizard/wizard_room",
                "west":"/u/notme/test_room",
                "east":"/d/city/guangchang",
                ]));
                set("valid_startroom", 1);
                set("no_clean_up", 0);
                setup();
}
void init()
{
    add_action("do_listemote","listemote");
}

int do_listemote()
{
    string *list, emote_name;
    mapping emote;

    list = EMOTE_D->query_all_emote();
    foreach(emote_name in list)
    {
        emote = EMOTE_D->query_emote(emote_name);
        log_file("emote_list",
        sprintf("emote:(%s)  上次修改：%s\n", emote_name,emote["updated"]) +
        sprintf("─────────────\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
            emote["myself"], emote["others"], emote["myself_self"],
            emote["others_self"], emote["myself_target"], emote["target"],
            emote["others_target"] ) );
    }
    return 1;
}

int valid_leave(object me, string dir)
{
    if (!wizardp(me) && dir == "down")
    {
        return notify_fail("你不能从那里出去!\n");
    }
    return ::valid_leave(me, dir);
} 
