// 侠客台
// for Xiake dao
// modified by aiai  98/10/27

#include <ansi.h>
//#include "/u/aiai/create_menpai/creat_menpai.h"

inherit ROOM;

string look_shibei();

void create()
{
    set("short",HIC"俠客台"NOR);
    set("long", CYN@LONG
                       ■■■■■■■■■■■■
                         ■■■■■■■■■■■■□
                       ■■■■■■■■■■■■□□         这里是武林人士
                       ■                    ■□□         心中的圣地，数		
                       ■     ┌━━━━┐   ■□□         百年来为各正邪		
                       ■     │俠 客 台│   ■□□         武林人物所膜拜。		
                       ■     ┕━━━━┙   ■□□		
                       ■                    ■□□		
                       ■                    ■□□		
                       ■    賞        開    ■□□		
                       ■    善        宗    ■□□		
                       ■    罰        立    ■□□		
                       ■    惡        派    ■□□		
                       ■    乾        俠    ■□□		
                       ■    坤        骨    ■□□		
                       ■    定        風    ■□□		
                       ■                    ■□□		
                       ■                    ■□□		
                       ■                    ■□□		
                   ◇◇■                    ■□□ ◇◇◇◇	
                ◇◇◇ ■                    ■□ ◇◇◇◇◇
              ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇	
　 　       ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇
            ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇
　　        ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇
            ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇

LONG NOR
    );

    set("exits", ([
	"down" : __DIR__"ya-up1",
    ]));
    set("objects", ([
    "/kungfu/class/xiakedao/mujianfeng":1,
    ])  );

    set("item_desc",([
        "台"        :    (: look_shibei :),
    ]));
    set("no_fight",1);
    set("no_steal",1);
    set("no_sleep",1);
    setup();
}



string look_shibei()
{
    return "天苍苍兮临下土，胡为不救万灵苦。
万灵日夜相凌迟，饮气吞声死无语。
仰天大叫天不应，一物细琐枉劳形。
安得大千复混沌，免教造物生精灵。\n";
}
