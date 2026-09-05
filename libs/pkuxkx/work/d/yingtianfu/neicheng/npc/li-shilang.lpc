//吏部侍郎

#include <ansi.h>
inherit NPC;

#include "li_shilang.h"
void create()
{
    set_name("吏部左侍郎", ({"libu shilang", "shilang"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的吏部左侍郎。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",3);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    set("mingpin",3);
    set("chat_chance", 5);
        set("chat_msg", ({
                
                (:askforhelp:),
        }) );
	set("depart","libu");
	set("inquiry", ([
	
     "兑换" : (: ask_convert :),
	 "convert" : (: ask_convert :),
     "官印": (: ask_yin :),
     "yin": (: ask_yin :),
     "调动": (: ask_change_title :),
     "diaodong": (: ask_change_title :),
     "帮助": (: ask_task :),
     "help": (: ask_task :),
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
     //"办公": (: ask_change_title2 :),
     //"office": (: ask_change_title2 :),
	]));

    setup();
    carry_object("/d/yingtianfu/neicheng/obj/guanyin2");
    setup_player_name();
}
