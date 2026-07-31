// ma-yuanshuai.c

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("马元帅", ({"ma yuanshuai","ma","yuanshuai","hou","mahou"}));
        set("gender", "男性" );
        set("age", 50);
        set("long", "一只身强体壮的大马猴。\n");
        set("combat_exp", 90000);
  set("daoxing", 10000000);

        set("attitude", "peaceful");
        set("str",40);
        set_skill("unarmed", 80);
        set_skill("dodge", 110);
        set_skill("parry", 80);
        set_skill("force", 50);   
        set("per", 10);
        set("max_qi", 600);
        set("max_gin", 100);
        set("max_jing", 300);
        set("max_neili", 400);
        set("neili",400);
        set("max_mana",200);
        set("neili",200);
        set("force_factor", 20);
        setup();
initlvl((500+random(500)),random(63));
}

int accept_fight(object me)
{
        return 0;
}
