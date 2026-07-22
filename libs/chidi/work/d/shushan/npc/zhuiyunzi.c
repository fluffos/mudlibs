//zhui yunzi-yushu 2001.2.
// lilong alter 2002.01.19
#include <ansi.h>
inherit BHNPC;
void create()
{
       set_name("×·ÔÆ×Ó", ({"zhui yunzi", "yunzi", "zi"}));
       set("title", "ÊñÉ½ÅÉµÚÈı´úµÜ×Ó");   
       set("gender", "ÄĞĞÔ");
       set("age", 32);
       set("attitude", "friendly");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 30);
       set("con", 30);
       set("combat_exp", 4000000);
       set("max_qi", 10000);
       set("max_qi", 10000);
       set("neili",30000);
       set("max_neili",30000);
        set("max_jingli", 800);
        set("jingli", 8000);
 
	set_skill("shushan-force", 400);
	set_skill("yujianshu",400);
       set_skill("dodge",400);
       set_skill("literate", 400);
       set_skill("sword",400);
       set_skill("force", 400);
       set_skill("parry",400);
       set_skill("zuixian-steps", 400);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "shushan-force");
       create_family("ÊñÉ½ÅÉ", 3, "µÜ×Ó");
       setup();
      carry_object("/clone/cloth/cloth")->wear();
       carry_object("/clone/weapon/changjian")->wield();
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
			command("say ÊÇÄã×Ô¼ºÒª°İµÄ£¬¿É±ğ¹ÖÎÒ°¡!¡£\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say ºÃ£¬ÎÒÊñÉ½ÅÉÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "ÊñÉ½ÅÉµÚËÄ´úµÜ×Ó");
                            }
              return 0;
}

ÿ
