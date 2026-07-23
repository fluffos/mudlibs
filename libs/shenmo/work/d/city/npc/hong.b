// wujiang.c 武将

#include <ansi.h>
inherit NPC;

#include <greeting.h>
int ask_xlzhang();
int ask_dgbang();

void create()
{
        set_name("洪七公", ({ "hong qigong", "hong", "qigong" }));
        set("gender", "男性");
set("inquiry",([
"降龙十八掌"     : (: ask_xlzhang :),
"打狗棒法"     : (: ask_dgbang :),
]));
        set("age", random(10) + 30);
        set("str", 25);
        set("long", "他就是现任丐帮帮主，当今世界打狗棒和降龙十八掌的CEO。\n");
        set("combat_exp", 2000000);
 
set("attitude", "peaceful");


        set_skill("unarmed", 250);

        set_skill("force", 250);
 
       set_skill("stick", 250);
   
     set_skill("dodge", 250);
   
     set_skill("parry", 250);

set_skill("xianglong-zhang",250);
set_skill("dagou-bang",250);
map_skill("unarmed","xianglong-zhang");
map_skill("stick","dagou-bang"); 
set("max_kee", 400);
	set("max_sen", 4000);
        set("force", 4000); 
        set("max_force", 4000);
       set("force_factor", 150);
	set("max_mana", 4000);
	set("mana", 4000);
	set("mana_factor", 150);
        setup();
        carry_object("/u/yhq/npc/stick")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
//                remove_call_out("kill_ob");
//                call_out("kill_ob", 1, ob);
        }
        greeting2(this_player());
}
int accept_fight(object me)
{
        message_vision("洪七公对$N把眼一瞪，喝道：去死！\n\n", me);
        return 0;
}

int ask_xlzhang()
{
object me;
object item;
me=this_player();
if(me->query("level")<600)
{
command("hehe");
command("say 你现在的等级太低了，恐怕难以领悟降龙十八掌的精深奥妙！"); 
return 1; 
}
if(me->query("xlzhang_ask")==1)
{
command("kick");
command("say 你怎么又问这个啊，好话不说二遍！");
return 1;
}
if (me->query("xlzhang_agree")!=1)
{
if ( random(100) > 30 )
{
command("sigh");
command("say 你的资质不适合练习降龙十八掌，千万不要难过哈。");
me->set("xlzhang_ask",1); 
}
else
{
command("wow");
command("say 你的资质太好了，正是练降龙十八掌的料啊！\n");
command("say 碰上我算是你走了狗屎运了，我就教你两下子吧！\n");
me->set("xlzhang_ask",1);
me->set("xlzhang_agree",1);
item=new("/d/obj/weapon/sword/qinghong");
item->move(me);
command("chat 老叫花子的降龙十八掌后继有人了！\n");
message("channel:rumor",YEL+"\n【"+HIM" 顺风耳 "NOR+YEL"】某人："+me->query("name")+"从洪七公那里学到了"+HIR"降龙十八掌"NOR+YEL"！\n\n"+NOR,users() );
}
return 1;
}
return 0;
}
int ask_dgbang()
{
object me;
object item;
me=this_player();
if(me->query("level")<600)
{
command("hehe");
command("say 你现在的等级太低了，恐怕难以领悟打狗棒法的精深奥妙！"); 
return 1; 
}
if(me->query("dgbang_ask")==1)
{
command("kick");
command("say 你怎么又问这个啊，好话不说二遍！");
return 1;
}
if (me->query("dgbang_agree")!=1)
{
if( random(100) > 30 )
{
command("sigh");
command("say 你的资质不适合练习打狗棒法，千万不要难过哈。");
me->set("dgbang_ask",1);
}
else
{
command("wow");
command("say 你的资质太好了，正是练打狗棒的料啊！\n");
command("say 碰上我算是你走了狗屎运了，我就教你两下子吧！\n");
me->set("dgbang_ask",1);
me->set("dgbang_agree",1);
item=new("/u/yhq/npc/stick");
item->move(me);
command("chat 老叫花子的打狗棒法后继有人了！\n");
message("channel:rumor",YEL+"\n【"+HIM" 顺风耳 "NOR+YEL"】某人："+me->query("name")+"从洪七公那里学到了"+HIG"打狗棒法"NOR+YEL"！\n\n"+NOR,users() );
}
return 1;
}
return 0;
}
int recognize_apprentice(object ob) 
{
        return 1; 
}

