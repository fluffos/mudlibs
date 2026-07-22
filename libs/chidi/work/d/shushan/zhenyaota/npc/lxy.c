//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
//lilong¸ÄÓÚ 2002.01.12
inherit BHNPC;
#include <ansi.h>
int do_report();
void create()
{
        set_name("ÀîåĞÒ£", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","ÊñÉ½½£ÅÉÈëÃÅµÜ×Ó");
        set("long", 
"ÀîåĞÒ£Éí²Ä½ÏÊİ£¬³¤µÄÅ¨Ã¼À«ÑÛ£¬ÆøÓîêÑ°º¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 18);
	 set("class", "xiake");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("qi", 28000);
        set("max_qi", 28000);
        set("jing", 16000);
        set("max_jing", 16000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("combat_exp", 80000000);
        set("max_jingli", 10000);
        set("jingli", 100000);
         set("jiali",1000);
        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("unarmed", 1500);
         set_skill("fumozhang", 1500);
        set_skill("parry", 1500);
        set_skill("sword", 1500);
        set_skill("canxin-jian", 1500);
        set_skill("shushan-force", 1500);
        set_skill("zuixian-steps",1500);
        set_skill("literate",1500);
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
        set("inquiry", ([
                "¾È³öÀ´ÁË"    : (: do_report :),
        ]));
        setup();
        create_family("ÊñÉ½ÅÉ", 3, "µÜ×Ó");
         carry_object("/clone/cloth/dao-cloth")->wear();
         carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="ÊñÉ½ÅÉ" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄĞĞÔ" ) command("say Ê¦Êå¼ûĞ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûĞ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "ÄĞĞÔ" ) command("say Ê¦ĞÖÌ«¿ÍÆøÁË¡£\n");
			else command("say Ê¦ÃÃÌ«¿ÍÆøÁË¡£\n");
		}
		else 
		{
			command("consider");
			command("say ¿´ÔÚÄã³ÏĞÄ³ÏÒâµÄ·İÉÏ,ÎÒÊÕÄãÎªÍ½!\n");
			command("recruit " + ob->query("id") );
                     ob->set("shushan/xiangsi_perform",1);

		}
	}
            else
	{
		command("say ¿´ÔÚÄã³ÏĞÄ³ÏÒâµÄ·İÉÏ,ÎÒÊÕÄãÎªÍ½!\n");
		command("recruit " + ob->query("id") );
              ob->set("shushan/xiangsi_perform",1);

	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "ÊñÉ½ÅÉÀîåĞÒ£µÜ×Ó");
              }
              return 0;
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "ÀîåĞÒ£ËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob) +
"£¬ÄÜ²»ÄÜ°ïÎÒ¾È³öÁé¶ù£¡Ëı±»¹Ø½øÕòÑıËşÀïÁË£¡\n");
}

int do_report()
{
 int i=random(500)+1;
 object me = this_player();
 if(me->query("shushan/zhanyi")) { 
 me->set("zhanyi/zhenyaota",1);
 me->delete("shushan/zhanyi");
 me->add("combat_exp",50000+i);
 me->add("neili",1000);
 message("system",HIC"¡¼"HIW"ÕòÑıËş´«Ñ¶"HIC"¡½"HIY+me->query("name")+HIG"¾È³ö[1;37mÕòÑıËş[1;32mÀïµÄÕÔÁé¶ù£¬ÊÜµ½½±Àø£¡[2;37;0m\n"NOR,users());    
 tell_object(me,"ÄãÓ®µÃÁË50000µãµÄ¾­ÑéºÍ1000µãµÄÄÚÁ¦\n");
 me->save();
 } 
 else 
 {
 command("say Ğ»Ğ»Äã£¡²»ÄÜÔÙÂé·³ÄãÀ²£¡");
 }
 return 1;
}



