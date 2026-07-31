//snowman 28/02/98
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
int ask_rob();


void create()
{
        set_name(HIG"玄难大师"NOR, ({ "dashi"}));
       set("long",
                "玄难大师及当今的少林名僧,他武功不高.\n"
                "但常四处奔走,为武林主持公道。\n");
        set("attitude", "friendly");
        set("gender", "男性");
        set("age", 68);
        set("per", 40);
        set("no_get", 1);
        set("str", 40);
        set("int", 47);
        set("con", 46);
        set("dex", 90);
        set("qi", 9500);
        set("max_qi", 9500);
        set("jing", 9600);
        set("max_jing", 9600);
        set("neili", 8000);
        set("max_neili", 8000);
set_skill("dodge",400);
set("combat_exp", 2000000);
	set("score", 100);

	set_skill("force", 350);
	set_skill("hunyuan-yiqi", 150);
	set_skill("dodge", 350);
	set_skill("shaolin-shenfa", 350);
	set_skill("strike", 350);
	set_skill("sanhua-zhang", 150);
	set_skill("parry", 350);
	set_skill("damo-jian", 150);
	set_skill("buddhism", 350);
	set_skill("literate", 350);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "sanhua-zhang");
	map_skill("parry", "sanhua-zhang");
        set("inquiry", ([
        "回寺" : (:ask_huijia:) ,
        "到寺" : (:ask_daojia:) ,
         ]) );
        set("env/wimpy", 40);
        set_temp("apply/attack", 300);
        set_temp("apply/defense",300);
        set_temp("apply/armor", 300);
        set_temp("apply/damage", 100);
        setup();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
if (this_player()->query("shaolinjob"))
	this_player()->start_busy(1);
if (ob->query("husong") == 0 )
{
        remove_call_out("leave");
        call_out("leave",240);
}
}

void leave()
{
        object ob = this_object();
        if (ob->query("husong") == 0) {
                message_vision(HIG "大师见无人来接应,自己离开了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

string ask_huijia()
{
object me=this_player();
object ob = this_object();
if(me->query("shaolinjob") == 0 )
return "阿弥陀佛！我不认识施主.\n";
me->apply_condition("shaolin_song",30);
set_leader(me);
me->set("husong",1);
ob->set("husong",10);
return "阿弥陀佛！谢谢师侄愿意送我回寺.\n";
}

string ask_daojia()
{
 object ob,me;
 int exp,pot;
 ob = this_object();
me = this_player();
if(me->query("shaolinjob") == 0 )
return "阿弥陀佛！我不认识施主.\n";
if(me->query("husong") == 0 )
return "阿弥陀佛！我不认识施主.\n";

 if( environment(ob)->query("short")=="少林广场")
         {

          set_leader(0);
          write("终于到寺里了，太谢谢你了.\n");
pot=880+random(700);
exp=1080+random(1300);
             me->add("potential",pot);
             me->add("combat_exp",exp);
             me->set("shaolinjob",0);
me->set("husong",0);
             me->apply_condition("shaolin_song",0);
          write("你的修为和潜能提高了!!\n");
        call_out("leavet",1);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
           return "我进寺里做法事去了.....\n";  
      }
        else {
                return "还没到寺里面呢!\n";
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