// hufa5.c
// by dou 98-09-20

#include <ansi.h>
#include "hufa.h"

inherit NPC;

void create()
{
    set_name(YEL"上官轻虹"NOR, ({ "shangguan qinghong","shang guan"}));
    set("title",YEL"一品堂总堂护法"NOR);
    set("age", 40+random(10));
    set("per",30);
    set("gender", "女性");
    set_wugong("chusuifeng",130,130,1);
    set_wugong("yubi-jian",130,130,1);
    set_wugong("damo-jian",140,140,1);
    set_wugong("shenxing",130,130,1);
    set_wugong("zuiliu-dao",150,150,1);
    set_wugong("cibei-dao",130,130,1);
    set_xiuwei_by_type("blade",1200);
    set_xiuwei_by_type("dodge",1000);
    set_xiuwei_by_type("sword",1200);
    set("combat_exp", 450000);
        JoinZuzhi("yipin","指挥使","玄阳堂");    
        set("force",2000);
        set("max_force",2000);
        set("force_factor",50);
    setup(); 
    carry_object(__DIR__"obj/cloth1")->wear();
    carry_object(__DIR__"obj/blade2") ->wield();
}   

