//qing yunzi-yushu 2001.2.
#include <ansi.h>
inherit BHNPC;
void create()
{
       set_name("ÇáÔÆ×Ó", ({"qing yunzi", "yunzi", "zi"}));
       set("title", "ÊñÉ½ÅÉµÚÈı´úµÜ×Ó");   
       set("gender", "Å®ĞÔ");
       set("age", 32);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 40);
       set("con", 30);
       set("combat_exp", 5000000);
       set("max_qi", 10000);
       set("max_jing", 10000);
       set("neili", 10000);
       set("max_neili", 18000);
        set("max_jingli", 500);
        set("jingli", 500);
        set("jiali", 5000);
	set_skill("shushan-force", 500);
	set_skill("yujianshu", 500);
       set_skill("dodge", 500);
       set_skill("literate", 500);
       set_skill("sword", 500);
       set_skill("force", 500);
       set_skill("parry", 500);
       set_skill("zuixian-steps", 500);
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
