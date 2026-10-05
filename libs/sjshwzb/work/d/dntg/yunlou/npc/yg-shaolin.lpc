// yg-shaolin   by piao

#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        set("title",HIY"少林弃徒"NOR);
	set("gender", "男性");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("stick", j);
        me->set_skill("zui-gun", j);
        me->set_skill("sword",j);
        me->set_skill("shaolin-sword",j);
        me->set_skill("shaolin-shenfa", j);
        me->set_skill("chanzong", j);
        me->set_skill("banruo-zhang", j);
        me->set_skill("yijinjing", j);

        me->map_skill("force", "yijinjing");
        me->map_skill("sword", "shaolin-sword");
        me->map_skill("stick",  "zui-gun");
        me->map_skill("parry", "zui-gun");
        me->map_skill("spells", "chanzong");
        me->map_skill("dodge", "shaolin-shenfa");
        me->map_skill("unarmed", "banruo-zhang");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"stick", "yading" :),
        (: cast_spell, "raor" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/stick/xiangmo");
        else
           weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
