//Cracked by Roath
// happ@YSZZ
 
// gao.c
#include <ansi.h>

inherit NPC;
string ask_girl();

void create()
{
       set_name("¸ßÔ±Íâ", ({"gao yuanwai", "gao"}));

set("long","¸ß¼Ò×¯µÄÖ÷ÈË£¬³ÔµÄÅÖºõºõµÄ£®\n°´Ëµ´ó²ÆÖ÷Ó¦¸ÃÀÖºÇºÇµØ£¬ËûÈ´³îÃ¼¿àÁ³£¬ÏóÊÇÓöµ½ÁËÊ²Ã´ÄÑÊÂ£®\n");
       set("gender", "ÄĞĞÔ");
       set("age", 46);
       set("title", "×¯Ö÷");
       set("attitude", "peaceful");
       set("shen_type", 1);
   set("combat_exp", 5000);
        set_skill("unarmed", 15);
   set_skill("dodge", 30);
   set_skill("parry", 15);
set("inquiry", ([
"name": "ÀÏ·òĞÕ¸ß£¬ÄËÊÇ¼ÒÖĞµÄÖ÷ÈË£®\n",
"here": "¸ßÀÏ×¯ÊÇÒ²£®\n",
"¸ßĞ¡½ã": (: ask_girl :),
"´äÀ¼" : (: ask_girl :),
]) );

   setup();
       add_money("silver", 3+random(5));
   carry_object("/clone/misc/cloth")->wear();
}


void init()
{
        remove_call_out("check");
        call_out("check",1);
}

void check()
{
          object room = environment();
          object lady = present("cui lan",room);        
          object ob;
          if (!lady) return ;
          if( lady->query_leader() == 0 )
                return ;
          ob = present(lady->query_leader(),room);
          if( ob == 0 )
                return ;
          remove_call_out("check2");
          call_out("check2",1,ob);
}
void check2(object ob)
{
          int i;

//          if(! ob->query("obstacle/hf") )
//                return;
          if (ob->query("obstacle/yz") == "done")
                return;
          if( !ob->query_temp("pig_killed") )
                return;

        i = random(800);
        ob->add("obstacle/number",1);
        ob->set("obstacle/yz","done");
        ob->add("combat_exp",i+10000);
        ob->add("potential",i*8);
        ob->add("mpgx",10);ob->add("expmax",2);
        command("chat ¸ĞĞ»"+ob->query("name")+"¾È³öÎÒµÄĞ¡Å®´äÀ¼£¡");
        message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+ob->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚÎå¹Ø£¡\n"NOR,users());
        tell_object (ob,"ÄãÓ®µÃÁË"+chinese_number(i+10000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+
               "Ê®µãÃÅÅÉ¹±Ï× ¶şµã³É³¤ÉÏÏŞ£¡\n");
        ob->delete_temp("pig_killed");
        ob->save();
        return;
}


string ask_girl()
{
        object ob = this_player();
        object cloth = new("/d/qujing/gao/obj/cloth");

        if( ob->query("obstacle/yz") == "done" 
        || !ob->query("obstacle/hf") 
        || ob->query_temp("girl_asked") )
                {
                command("?");
                return("ÄãÎÊÕâ¸ÉÊ²Ã´£¿");
                }

        command("disapp1 gao");
        command("cry1");
        cloth->move(ob);
        ob->set_temp("girl_asked",1);
        command("say ÎÒÄÇÅ®¶ù£¬±»¸£ÁêÉ½Ò»¸öÒ°Öí¹Ö°ÔÕ¼ÁË£¬²»ÖªÄúÓĞÃ»ÓĞÊÖ¶Î£¬°ïÎÒ¾È»ØÅ®¶ù£¿ ");
        return("ÕâÊÇËıÒÔÇ°´©µÄÒÂ·ş¡£");       
}        
