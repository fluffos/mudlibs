#include <ansi.h>
inherit BHNPC;

int to_quit();
string this_job();
string give_baochou();
string cizhi();

void create()
{
        set_name("’≈‘±Õ‚",({"zhang yuanwai", "zhang", "yuanwai"}));
        set("age",38);
        set("max_qi",5000);
        set("eff_qi",5000);
        set("qi",5000);
        set("max_jing",500);
        set("eff_jing",500);
        set("jing",500);
        set("combat_exp",10000);

        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("cuff",50);

        set("startroom","/d/city2/xidan");
        set("start_time",time());
