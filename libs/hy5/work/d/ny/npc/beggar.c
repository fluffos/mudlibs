
// sp_beggar.c

#include <ansi.h>
inherit NPC;

int get_order(object me);
void create()
{
        set_name("乞丐", ({ "begger" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个满脸风霜之色的老乞丐。不过他的双目特别有神。\n");
        set("combat_exp", 100);
       
        set("kee", 0);
        set("max_kee", 1);
        set("str", 27);
        set("force", 0);
        set("max_force", 0);
        set("force_factor", 0);
        set("max_atman", 10000);
        set("atman", 10000);
        set("inquiry", ([
                "地图" :  (: get_order :),
                "羊皮地图" :  (: get_order :),               
  "军事地图" :(: get_order :),
                         ]));
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
             "乞丐说道：好心的大爷哪～ 赏我要饭的几根鸡骨头吧～\n",
                "乞丐懒洋洋地打了个哈欠。\n",
                
"乞丐伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬糜了。 \n",
        }) );
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"饶命！小的这就离开！\n");
        return 0;
}
int get_order(object me)
{
if (!this_object()->query("get_his_name"))
{                 command("say 请你在两分钟内，找齐20根鸡骨头给我!!");
    this_object()->set("get_his_name",this_player()->query("id"));
              this_player()->set("get_time", (int) time()+60);
          this_object()->set("get_time", (int) time()+90);
                  return 1;         }
 command("say 我现在不需要你干什么事!");
      return 1;
             }

int accept_object(object who, object ob)
{     object map;        
      if (ob->query("id")=="bone"
      && who->query("id") == this_object()->query("get_his_name"))
          { this_object()->add("i",1);
            if (this_object()->query("i") == 20) 
                  { if (who->query("get_time")>(int)time())
                   { map=new("open/tony/jjf/obj/map7.c");
                    map->move(who);
                    this_object()->set("i",0);
this_object()->delete("get_his_name");
                    command("say 拿去吧，我就剩下这啦！");
                call_out("leave", 1);
                    return 1;
                    }         
                   else
                      {command("say 唉，太晚了，地图给抢走了！");
                    this_object()->set("i",0);
                           return 1;} 
                   }           
  
               return 1;}
         else {command("say 我不要");
                return 0;} 
}
int heal_up()
{
if (!this_object()->query("get_his_name")
|| this_object()->query("get_time")>(int)time())

{return ::heal_up() + 1;
}
     else{   this_object()->set("get_time",0);
       this_object()->delete("get_his_name");
                call_out("leave", 1);
           }            
}

void leave()
{       object *room;
        int i,k;
        message("vision",
   NOR + name() + " 化做一阵清风，不见了。\n" NOR, environment(),
               this_player() );
        room = objects( (: function_exists("create_door", $1) :) );
        i = sizeof(room);
        k = random(i);
      this_object()->move(room[k]);
}
