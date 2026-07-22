// Npc: /d/tianshan/npc/linyang.c
// By Linux

inherit NPC;
int random_walk();
string *walkrooms = ({
        "/d/tianshan/shanjin1",
        "/d/tianshan/shanjin2",
        "/d/tianshan/shanjin3",
        "/d/tianshan/shanjin4",
        "/d/tianshan/shanjin5",
        "/d/tianshan/shanjin6",
});

void create()
{
        
	set_name("羚羊", ({ "ling yang", "yang" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "这是一头羚羊。\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("cor", 26);

        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 3000);

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);
	set("chat_chance", 3);
      	set("chat_msg", ({
              (: random_walk :),
      	}) );

        setup();
}

int random_walk()
{
        mapping exits;
        string *dirs, dir;

        if( member_array(base_name(environment()), walkrooms) == -1 ) {
                message_vision("$N一溜烟跑掉了。\n", this_object());
                destruct(this_object());
        }

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) 
                return 0;

        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if( member_array(exits[dir], walkrooms) == -1 ) return 0;

        command("go " + dir);
        return 1;
}
