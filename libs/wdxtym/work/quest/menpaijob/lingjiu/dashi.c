//snowman 28/02/98
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
int ask_rob();
void create()
{
        set_name(HIG"小女孩"NOR, ({ "nuhai"}));
       set("long",
                "一个长的非常短小的小女孩，长相到是十分秀丽.\n"
                "但眼神里却露出怪异的神色。\n");
        set("attitude", "friendly");
        set("gender", "女性");
        set("age", 12);
	set("no_get", 1);
        set("per", 35);
        set("str", 40);
        set("int", 47);
        set("con", 46);
        set("dex", 88);
        set("qi", 9500);
        set("max_qi", 9500);
        set("jing", 9600);
        set("max_jing", 9600);
        set("neili", 18000);
        set("max_neili", 18000);
set_skill("dodge",400);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
        set_skill("sword",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");	        
        set("inquiry", ([
        "回宫" : (:ask_huijia:) ,
        "到宫" : (:ask_daojia:) ,
         ]) );
        set("env/wimpy", 40);
        set_temp("apply/attack", 300);
        set_temp("apply/defense",300);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 100);
        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if(this_player()->query("lingjiujob") )
	this_player()->start_busy(1);
if (ob->query("lingsong") == 0 )
{
        remove_call_out("leave");
        call_out("leave",240);
}
}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "小女孩见无人来接应,自己离开了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

string ask_huijia()
{
object me=this_player();
object ob = this_object();
if(me->query("lingjiujob") == 0 )
return "我看你是乌老大派来的那奸细吧。。。\n";
me->apply_condition("lingjiu_song",30);
me->set("lingsong",1);
set_leader(me);
ob->set("lingsong",10);
return "你小子如果送老娘回宫，回宫后自有奖赏.\n";
}

string ask_daojia()
{
 object ob,me;
int exp,pot,base_exp;
ob = this_object();
me = this_player();
if(me->query("lingjiujob") == 0 )
return "我看你是乌老大派来的那奸细吧。。。\n";
if(me->query("lingsong") == 0 )
return "我看你是乌老大派来的那奸细吧。。。\n";

 if( environment(ob)->query("short")=="灵鹫百丈涧")
         {

          set_leader(0);
          write("终于到宫门了，你护送有功.\n");
pot=880+random(800);
exp=980+random(1300);
             me->add("potential",pot);
             me->add("combat_exp",exp);
             me->set("lingjiujob",0);
me->set("lingsong",0);
             me->apply_condition("lingjiu_song",0);
          write("你的修为和潜能提高了!!\n");
        call_out("leavet",1);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
           return "我回宫去了.....\n";  
      }
        else {
                return "还没到呢!你想不管了吗?\n";
        }
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用guard！\n");
        return 1;
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	