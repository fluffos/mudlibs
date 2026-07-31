#include <ansi.h>
inherit NPC;
void say_some(string word);

void create()
{
    set_name("门徒",({"mentu"}));
    set("gender","男性");
    set("age",16+random(30));
    set("title",RED"幽冥山庄"NOR);
    set("combat_exp",1000+random(10000));
    set("kee",300);
    set("max_kee",300);
    set("force",300);
    set("max_force",300);
    set("force_factor",5);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"你现在呆的地方就是了。\n",
    "道心种魔大法":"我门中无上大法，可惜早几代就失传了.\n",
    ]));
        set("shen_type",-1);
    
    set_skill("dodge",4+random(10));
    set_skill("parry",4+random(10));
    set_skill("unarmed",4+random(10));
    set_skill("force",4+random(10));
    set_skill("literate",2);

  
    setup();
    add_money("silver",3);
 }

void say_some(string word)
{
	command("say "+word);
}
   
