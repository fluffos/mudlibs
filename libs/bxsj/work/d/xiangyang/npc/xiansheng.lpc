// xiansheng.c 私塾先生

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("私塾先生", ({ "sishu xiansheng", "xiansheng"}));
	set("long", "这位先生手里捧着一本书，正在摇头晃脑读。\n");
	set("gender", "男性");
	set("age", 22);
	set("shen_type", 1);

	set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);

        set("combat_exp", 100000+random(1000));
	set_skill("literate", 50);
        setup();
        carry_object(ARMOR_D("changshan2"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

int recognize_apprentice(object ob)
{
        int money = 50, level = ob->query_skill("literate", 1);

        if (level > ob->query("int")*10){
                message_vision(CYN"\n$N对着$n端详了一番道：“你因先天所制，已无法再进修更高深的学问了。”\n"NOR, this_object(), ob);
                return 0;
        }

        if (level > 10) money = 100;
        if (level > 29) money = 500;
        if (level > 39) money = 1000;

        ob->delete_temp("mark/literate");
        switch (MONEY_D->player_pay(ob, money)) {
                case 0:
                case 2: return 0;
        }
        ob->set_temp("mark/literate", 1);
        return 1;
}
