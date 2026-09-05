// 村长
// created by Zine 5 Sep 2010

inherit NPC;
#include <ansi.h>

int ask_knowledge();
void create()
{
	
	string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title", HIR"建康府知府"NOR);
	set("gender", "男性" );
	set("long", "这位大人不怒而威，实则在建康府他只是芝麻绿豆大的小官。\n");
	
    set("age", 45);
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 100);
    set("combat_exp", 1000000);
    set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	setup();
	carry_object("/d/jinyang/obj/heibuxie")->wear();
    carry_object("/d/yingtianfu/neicheng/npc/obj/cloth4")->wear();
}

#include "die.h"