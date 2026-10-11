// workroom.c 逍遥的房间
// Design By BMW add from 1999.11.6

#include <ansi.h>

inherit CHAT_ROOM;

void create()
{
        set("short",HIR"★寻欢居★"NOR);
        set("long",@LONG
$HIY$
*/.    .   .    *      .
  .\*    . $NOR$   []  $NOR$  $HIY$       *  __
  */ .   .$HIM$/\~~~~~~~~~~~~'\. |$HIC$◆ $NOR$ 
$HIY$   \*   ,$NOR$$HIM$/,..,\,...........,\.$HIC$◆ $NOR$ 
$HIY$   ||  .$NOR$$HIM$.▎#  ▎田  田 ▎ | ▎$HIC$◆$NOR$
$HIY$   ||  &&$NOR$$HIM$▎   ▎       ▎'|'▎ o   
$HIY$   || ##$NOR$$HIM$■■■■■■■■■■〓     $NOR$

LONG
);
        set("outdoors","center");
        set("chat_room", 1);
        set("sleep_room",1);
        set("no_kill",1);
        set("no_steal",1);
        set("no_magic",1);
        set("item_desc",([
                "sign": HIM"
                
                寻

                欢

                居
                
\n"NOR,

                
"shuiguo":"一些极为新鲜而罕见的水果，喊不出什么名字。\n",
                
"flowers":"一束带着露珠的玫瑰花，正静静的躺在桌面上。\n",
]));

        set("exits",([
                "north"  :"/d/wizard/wizard_room",
                "gc"     :"/d/center/guangchang",
                "enter"  :__DIR__"shuifang",
                "zoys"   :"/u/zoys/workroom",
                "robert" :"/u/robert/workroom",
                "down"   :"/d/wizard/towiz_room",
         ]));
        set("objects",([
                    "/u/bmw/obj/tianlong": 2,
                    "/clone/food/jitui": 3,
                    "/clone/food/jiudai": 1,
        ]));
        set("valid_startroom","1");
        call_other("/clone/board/bmw_b","???");
        setup();
}

void init()
{
        object me;
        me = this_player();
        if(!wizardp(me)
        && me->query("id") != "bmw"
        && me->query("id") != "love"
        && me->query("id") != "connie"
        && me->query("id") != "liuxiang") {
tell_object(me,"管家说道：逍遥不在家，你进来干吗？想做贼啊？！\n");
        me->move("/d/qianjinlou/up-01e");
       }
        add_action("do_save","save");
}
int do_save(string arg)
{
        object ob;
        ob = this_player();
        
        if(wizardp(ob)
        || ob->query("id") == "connie"
        || ob->query("id") == "love"
        || ob->query("id") == "liuxiang"
        || ob->query("id") == "txy") {
                ob->set("startroom","/u/bmw/workroom");
                ob->save();
                return 0;
        }
        else {
        
        
tell_object(ob,"存盘失败，原因：逍遥不喜欢你在他家赖着不走。\n");
        ob->move("/d/center/guangchang");
        tell_object(ob,"请到这里存盘。\n");
        return 1;
        }
}