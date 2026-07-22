 // judge_guard.c
int back_home(string arg);

inherit BHNPC;

void create()
{
  set_name("ÖµÇÚ±ø", ({ "zhi qin bing","zhi","bing" }) );
    set("gender", "ÄÐÐÔ" );
         set("shen_type",1);
 set("age", 44);
set ("no_arrest",1);
        set("con", 18);
        set("dex", 21);
       set("str", 50);
        set("int", 25);
        set("per", 27);
        set("long", @LONG
[32mÖµÇÚ±øÍþ·çÁÝÁÝµÄÍû×ÅÄã£¬Èç¹ûÃ»ÓÐ±ø·û,ÐÝÏëÈÃËûÃÇ·ÅÄã½ø±øÓª![0m
LONG
);
 set("vendetta_mark", "authority");
         set("combat_exp", 400000);

      set("max_neili", 1000);
       set("neili", 1000);
       set("force_factor", 20);

set("inquiry", ([
                "»ØÈ¥" :  (: back_home :),
                 "¹ö" : (: back_home :),]) );


        set("attitude", "heroism");
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
              "ÖµÇÚ±øËµµÀ£ºÄãµ±ÕâÀïÊÇÊ²Ã´µØ·½£¬¸ÒÀ´ÕâÀïÉ§ÈÅ£¿\n",
               "ÖµÇÚ±øËµµÀ£ºÄãÒªÊÇÔÙÎÞÀíÈ¡ÄÖ£¬°ÑÄã×¥È¥×øÀÎ!\n",
        }) );

   set_skill("parry", 160);
             set_skill("blade", 160);
                  set_skill("dodge", 160);
        
        set_skill("chaos-steps", 160);

        map_skill("dodge", "chaos-steps");

        setup();
        
carry_object("/obj/npc/obj/blade")->wield();
   carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
object ob;
ob = this_player();
::init();
remove_call_out("greeting");
call_out("greeting", 1, ob);
      }

void greeting(object ob)
{
object *list;
int i;
list = all_inventory(ob);
i=sizeof(list);
if(environment(this_object())->query("short")!="ÁÉ¶«±øÓªÕ¯ÃÅ")
    return ;
if((string)ob->query("family/family_name") == "³¯Í¢")
{while(i--)
   {if (list[i]->query("id")=="bingfu"
        && list[i]->query("owner")== ob->query("id"))
           {command("say Çë´óÈËÈëÄÚ£¬×Ü±ø´óÈËÕýÔÚµÈÄú£¡");
                      return;
                         }
            }
   }
command("say ±øÓªÖØµØ£¬ÏÐÔÓÈËµÈÒ»ÂÉÀë¿ª£¡£¡");
   ob->move("/d/chaoting/xianya/xianya_squre");
return;
}
