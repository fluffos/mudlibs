inherit NPC;
#include "MoveNpc.h"
string *PlaceList=({"/d/yingtiansouth/dufu/guangchang","/d/yingtiansouth/dufu/xier"," /d/yingtiansouth/dufu/donger",
"/d/yingtiansouth/dufu/huilang1","/d/yingtiansouth/dufu/qianting","/d/yingtiansouth/dufu/puren"}); //allowed to move across those rooms
void create()
{
	set_name("仆人", ({ "puren", "ren","pu" }));
	set("gender", "男性");
	set("age", random(20) + 20);
	set("str", 10);
	set("dex", 10);
	set("long", "他是一名都府里的仆人，正在打扫着。\n");
	set("combat_exp", 8000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 10);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set("is_puren",1);
	set("chat_chance", 3);
	set("chat_msg", ({
				(: random_move :),
                this_object()->name()+"低下头去，用扫把把地上的杂物扫起来。\n",
				this_object()->name()+"拿出抹布，擦拭着家具。\n",
                //(:askforhelp:),
        }) );
	set("Placelist",({"/d/yingtiansouth/dufu/guangchang","/d/yingtiansouth/dufu/xier","/d/yingtiansouth/dufu/donger",
"/d/yingtiansouth/dufu/huilang1","/d/yingtiansouth/dufu/qianting","/d/yingtiansouth/dufu/puren"}));
	setup();
	carry_object(__DIR__"obj/cloth_puren")->wear();
}

