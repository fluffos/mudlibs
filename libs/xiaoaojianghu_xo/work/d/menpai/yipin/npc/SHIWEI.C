// shiwei.c
// by dou 98-09-20

#include <ansi.h>
#include "weishi.h"

inherit NPC;

void create()
{
    set_name(GRN"侍卫"NOR, ({ "shi wei","shi"}));
    set("title",GRN"一品堂总堂"NOR);
    set("age", 30+random(10));
    set("gender", "男性");
    set_wugong("chusuifeng",90,90,1);
    set_wugong("yubi-jian",80,80,1);
    set_wugong("damo-jian",90,90,1);
    set_wugong("shenxing",90,90,1);
    set_wugong("zuiliu-dao",90,90,1);
    set_wugong("cibei-dao",90,90,1);
    set_xiuwei_by_type("blade",700);
    set_xiuwei_by_type("dodge",700);
    set_xiuwei_by_type("sword",700);
    set("combat_exp", 100000);
        JoinZuzhi("yipin","指挥使","玄阳堂");    
        set("force",1000);
        set("max_force",1000);
        set("force_factor",20);
    setup(); 
    carry_object(__DIR__"obj/cloth1")->wear();
    carry_object(__DIR__"obj/jian1") ->wield();
}   

