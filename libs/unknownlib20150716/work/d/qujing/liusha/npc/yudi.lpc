//Cracked by Roath
 
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("木叉行者", ({ "mucha xingzhe", "mucha", "xingzhe" }));
        create_family("南海普陀山", 2, "弟子");
        set_level(120);
        set("title", "观音首徒");   
        set("long", @LONG
李天王二太子木叉，南海观音大徒弟惠岸行者。
LONG);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "贫僧");
        set("class", "bonze");
    
        set("force_factor", 175);
        set("mana_factor", 255);

        set("eff_dx", 150000);
        set("nkgain", 300);

        set_skill("literate", 1200);
        set_skill("spells", 1200);
        set_skill("buddhism", 1200);
        set_skill("unarmed", 1200);
        set_skill("jienan-zhi", 1200);
        set_skill("dodge", 1200);
        set_skill("lotusmove", 1200);
        set_skill("parry", 1200);
        set_skill("force", 1200);
        set_skill("lotusforce", 1200);
        set_skill("staff", 1200);
        set_skill("lunhui-zhang", 1200);
        set_skill("blade", 1200);
        set_skill("cibeidao", 1200);
        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        map_skill("blade", "cibeidao");

	set_skill("tianlong-chanchang",1200);
	set_skill("jingang-sanmei",1200);
	set_skill("jingang-zhenshen",1200);
	set_skill("longxiang-li",1200);
	set_skill("qu-yue",1200);
	set_skill("bubu-shenglian",1200);
        set("env/test","HIB");
	set_temp("armor_level",90);
	set_temp("weapon_level",90);
        setup();
        carry_object("/d/nanhai/obj/sengpao")->wear();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"pifeng",1)->wear();
        carry_object(0,"hand",1)->wear();
        carry_object(0,"wrists",1)->wear();
        carry_object(0,"waist",1)->wear();
        carry_object(0,"staff",1)->wield();
        powerup(0,1);
}