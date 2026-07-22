// zhu.c 朱熹

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("私塾先生", ({ "sishu xiansheng", "xiansheng"}));
        set("long", "这位老先生正在摇头晃脑地读书。\n");
        set("gender", "男性");
        set("age", 65);

        set_skill("literate", 140);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);

        set("combat_exp", 500000);
        set("shen_type", 1);
        setup();
        carry_object(ARMOR_D("cloth"))->wear();

}

int recognize_apprentice(object ob)
{
        int money = 50, level = ob->query_skill("literate", 1);
	    int rate;
		/*
		玩家的literate等级低于80时，学习费用（GOLD）减少为原来的50%。
		玩家的literate等级高于80时，学习费用（GOLD）恢复正常计算公式。
		玩家的literate等级高于250时，学习费用（GOLD）增加为原来的150%。
		*/
        if (level > ob->query("int")*10){
                message_vision(CYN"\n$N对着$n端详了一番道：“你因先天所制，已无法再进修更高深的学问了。”\n"NOR, this_object(), ob);
                return 0;
        }
		rate=1;
		if(level > 80) rate=2;
		if(level > 250) rate=3;
		
		if (level > 29) money = 100*rate/2;
        if (level > 59) money = 500*rate/2;
        if (level > 89) money = 1000*rate/2;
        if (level > 119) money = 2500*rate/2;

        ob->delete_temp("mark/literate");
        switch (MONEY_D->player_pay(ob, money)) {
                case 0:
                case 2: return 0;
        }
        ob->set_temp("mark/literate", 1);
        return 1;
}
