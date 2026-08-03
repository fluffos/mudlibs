// wushi6.c
// by dou 98-09-20

#include <ansi.h>
#include "weishi.h"

inherit NPC;

void create()
{
    set_name(CYN"杨威"NOR, ({ "yang wei","yang"}));
    set("title",CYN"一品堂总堂武士"NOR);
    set("age", 40+random(10));
    set("gender", "男性");
    set_wugong("chusuifeng",110,110,1);
    set_wugong("yubi-jian",110,110,1);
    set_wugong("damo-jian",110,110,1);
    set_wugong("shenxing",110,110,1);
    set_wugong("zuiliu-dao",110,110,1);
    set_wugong("cibei-dao",110,110,1);
    set_xiuwei_by_type("blade",1000);
    set_xiuwei_by_type("dodge",1000);
    set_xiuwei_by_type("sword",1000);
    set("combat_exp", 300000);
        JoinZuzhi("yipin","指挥使","玄阳堂");    
        set("force",1500);
        set("max_force",1500);
        set("force_factor",30);
    setup(); 
    carry_object(__DIR__"obj/cloth1")->wear();
    carry_object(__DIR__"obj/jian1") ->wield();
}   

