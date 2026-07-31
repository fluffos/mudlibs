// feizei.c
//星星(lywin)2000/5/30为一个任务系统写此npc

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小毛贼",({ "mao zei","zei" }) );
	set("title",HIY"飞天遁地"NOR);
        set("gender", "男性" );
        set("long", 
"这是无恶不做的小毛贼，背上有一个小小包裹，看样子是才偷了不少银子。\n");

	set("int", 20);
	set("str", 20);
	set("con", 20);
	set("dex", 60);
        set("attitude", "aggressive");
        set("shen_type", -1);

  set("combat_exp", 1000+random(300000));
  set("age", 10+random(30));
  set("per", 14+random(20));
  set("max_qi",100+random(400));
  set("max_jing",100+random(400));
  set("max_sen",300+random(300));
  set("max_neili",300+random(300));
  set("max_mana",300+random(300));

  set_skill("unarmed", 10+random(190));
  set_skill("dodge", 50+random(200));
  set_skill("parry", 10+random(190));
  set_skill("sword", 10+random(190));
	
        setup();
        carry_object( __DIR__ "changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
  add_money("silver", random(20));
}
void init()
{
	add_action("do_guard", "halt");
        remove_call_out("hunting");
	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
		if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB+name()+"急急忙忙地走开了。\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用halt！\n");
        return 1;
}