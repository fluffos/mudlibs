//made by goodtaste
// Modified by iszt@pkuxkx, 2007-03-12, deleted chat()
// date: 1998.12.11
               
#include <ansi.h> 
inherit NPC; 
void re_rank(object);   
string ask_for_ershisi();
string ask_for_fanqing();
string ask_leadership();
string ask_strategy();
void consider();
void heal();
void create()
{
   object me;

	set_name("吴三桂", ({ "wu sangui" , "wu" , "sangui" }));

        set("title",HIB"平西王"NOR);
	set("long",
	"他就是当年为一女子背叛大明王朝，引得清兵入关的吴三桂\n"
         );
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", -1);
        set("shen",-1000);
        set("str",30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
        set("max_qi", 5500);
        set("jing", 1500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 300);
        set("combat_exp", 3500000+random(100000));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        set_skill("sword",380);
        set_skill("hero-jianfa",380);
        set_skill("force", 370);
        set_skill("xiantian-gong", 380);
        set_skill("dodge", 380);
        set_skill("fx-step", 380);
        set_skill("parry", 380);
	
        set_skill("literate",100);
        map_skill("sword","hero-jianfa");
	map_skill("dodge","fx-step");
	map_skill("parry","hero-jianfa");
	map_skill("force","xiantian-gong");
        set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 250);
    	set("book_count", 1);
	set("inquiry", ([
                "反清复明" :(:ask_for_fanqing:),
	"为官之道" : "哼哼，大清的江山迟早是我的。",
	//"兵法战策" : (: ask_strategy :),
	        "陈圆圆" :"哎，.......\n",
                "四十二章经":(:ask_for_ershisi:),
                "射月弓":"那是我最喜爱的一样事物，却在三年前丢了，估计是内奸所为,你若\n"+
            "能取回，本王允你入我密室一行\n"        
                          
	]) );
	setup();

	
        carry_object("/d/city/obj/cloth")->wear();
        if (random(10)>6)
 		carry_object(__DIR__"obj/herosword");
 	else
 		carry_object("/clone/weapon/changjian");

}


string ask_for_ershisi()
{
   object me ,ob;
ob=this_object();
   me = this_player();
   if(!me->query_temp("qinbing_asked") || !me->query_temp("huanong_asked"))
   {
     command("sneer");
     command("say 你是怎么混进来的?!"); 
ob->kill_ob(me);
return "见鬼去吧!!!\n";
   }
   return "四十二章经就在密室之中，你若能帮我一个忙本王允许你入我密室一行。";
      
}

string ask_for_fanqing()
{
   object me ,ob;
   me = this_player();
ob=this_object();
   command("say 大胆狂徒，你也敢揭我的短处!");
ob->kill_ob(me);
return "你认命吧!...";
   
}

int accept_object(object me, object obj)
{
if ((string)obj->query("name")=="射月弓" && obj->query("id")=="sheyue gong")
{
command("say 大侠果然出手不凡，好，请入我密室一游!\n");
command("hehe");
call_out("destroy",1,obj);
  me->set("permit", 1);  
   me->delete_temp("moved");
          me->set_temp("qingbing_asked",0);
          me->set_temp("huanong_aked",0);
        }
        else {
                 command("shake");
                 command("say 刁民竟敢欺骗本王 !");
  
        }
        return 1;
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield sword");
            command("wield changjian");
            command("perform sword.xiyang " + target->query("id"));
            command("unwield sword");
            command("unwield changjian");
             break;
            case 1:
            command("yun powerup");
             break;
             }
}
void heal()
{
        object ob=this_object();
        
        if (ob->query("bihua"))
                return;
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("exert lifeheal");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                ob->set("water",ob->max_water_capacity() );
                ob->set("food",ob->max_food_capacity() );
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

void init()
{
object me=this_player();
add_action("do_hit","hit");
add_action("do_fight","fight");
}
void destroy(object obj)
{
destruct(obj);
return;
}
int do_fight(string str)
{
 if ((str == "wu") || (str == "wu sangui")|| (str=="sangui"))
{
 command("say 我不屑与你这等无官衔的平民交手.\n");
return 1;
}
return 0;
}
int do_hit(string str)
{
 if ((str == "wu") || (str == "wu sangui")|| (str=="sangui"))
{
command("say 我不屑与你这等无官衔的平民交手.\n");
return 1;
}
return 0;
}
/*string ask_strategy()
{
        object ob;
        if (this_player()->query("class") != "officer")
                return RANK_D->query_respect(this_player()) +
                "与朝廷素无来往，不知此话从何谈起？";
        if (this_player()->query("pin") > 4)
                return "你官品太低，还看不了「吴子兵法」。";
        if (query("book_count") < 1)
                return "行军打仗要钻研古代兵书，不过「吴子兵法」已经被人拿走了。";
        add("book_count", -1);
        ob = new("/d/beijing/npc/obj/book_wuzi");
        ob->move(this_player());
        return "行军打仗要钻研古代兵书，这本「吴子兵法」你拿回去好好钻研。";
}*/
