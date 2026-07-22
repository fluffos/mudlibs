inherit BHNPC;
#include <ansi.h>

void create()
{
        int level,exp;

        set_name("ºÚÒÂ´Ì¿Í",({"heiyi cike", "cike"}));
        set("age",28);
        set("max_qi",1800);
        set("max_jing",1200);
        set("max_neili",2500);
        set("neili",2500);

        exp=150000*(5+random(5))/10;
        set("combat_exp",exp);
        level = ceil( pow( exp*10.0, 0.333333) );
        set("jiali",30);

        set_skill("unarmed",level);
        set_skill("dodge",level);
        set_skill("parry",level);
        set_skill("whip",level);
        set_skill("force",level);
        set_skill("hunyuan-yiqi",l