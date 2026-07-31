//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
//yushuĞŞ¸Ä 2001.2
inherit NPC;

#define YAO       "/d/shushan/obj/lingyao"

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
        set("qi", 2800);
        set("max_qi", 2800);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4800);
        set("max_neili", 2400);
        set("jiali", 60);
        set("combat_exp", 38000000);
        set("max_jingli", 1000);
          set("max_neili", 10000);
        set("jingli", 100000);
        set("neili",10000000);
         set("jiali",1000);
        set_skill("force", 250);
        set_skill("dodge", 240);
        set_skill("unarmed", 230);
         set_skill("fumozhang", 230);
        set_skill("parry", 250);
        set_skill("sword", 250);
        set_skill("canxin-jian", 270);
        set_skill("shushan-force", 240);
        set_skill("zuixian-steps",240);
        set_skill("literate",120);
        map_skill("unarmed", "fumozhang");
        map_skill("force", "shushan-force");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "canxin-jian");
        map_skill("sword", "canxin-jian");
	set("chat_chance",20);
       
    set("chat_msg",({
        "ÀîåĞÒ£Äîß¶×Å£º°¥! ²»ÖªµÀÏÉÅ®½ã½ã»á²»»á¸øÎÒÁéÒ©¡«\n",
        "ÀîåĞÒ£ÉîÉîµØÌ¾ÁË¿ÚÆø¡£\n",
        "ÀîåĞÒ£¶À×ÔËµµÀ£ºË­ÄÜ¾È¾ÈÎÒÉôÉô¡«\n"
       }) );
        set("inquiry", ([
                "¾È³öÀ´ÁË"    : (: do_report :),
        ]));
	 setup();
        create_family("ÊñÉ½½£ÅÉ", 3, "µÜ×Ó");
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
//        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
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
		}
	}
            else
	{
		command("say ¿´ÔÚÄã³ÏĞÄ³ÏÒâµÄ·İÉÏ,ÎÒÊÕÄãÎªÍ½!\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "ÊñÉ½ÅÉÀîåĞÒ£µÜ×Ó");
		  ob->set("shushan/xiangsi_perform", 1);
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
"£¬ÄÜ²»ÄÜ°ïÎÒ¾È³öÁé¶ù£¡Ëı±»¹Ø½ø·âÄ§ËşÀïÁË£¡\n");
}


int do_report()
{
 int i=random(50000)+1;
 object me = this_player();
 if(me->query("shushan/zhanyi")) { 
 me->set("zhanyi/zhenyaota",1);
 me->delete("shushan/zhanyi");
 me->add("combat_exp",300000+i);
 me->add("potential",100000);
 me->add("max_neili",me->query("max_neili")/10);
 message("system",HIC"¡¼"HIW"·âÄ§Ëş´«Ñ¶"HIC"¡½"HIY+me->query("name")+HIG"¾È³ö[1;37m·âÄ§Ëş[1;32mÀïµÄÕÔÁé¶ù£¬ÊÜµ½½±Àø£¡[2;37;0m\n"NOR,users());    
 tell_object(me,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+chinese_number(i/4)+"Ìì"+chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞºÍ"+
 chinese_number(100000)+"µãÇ±ÄÜ,ºÍÔö¼ÓÁË10%µÄÄÚÁ¦\n");
 me->save();
 } 
 else 
 {
 command("say Ğ»Ğ»Äã£¡²»ÄÜÔÙÂé·³ÄãÀ²£¡");
 }
 return 1;
}


int accept_object(object me, object obj)
{
object tuzhu;
if(base_name(obj)!=YAO)
{
                command("say Õâ¶«Î÷ÄÜÖÎºÃÎÒÉôÉôµÄ²¡Âğ£¿Äã²»ÒªÆ­ÎÒÁË!\n");
                return 0;
}
	tuzhu=new("/data/hell/fengmota/obj/tuzhu");
	tuzhu->move(me);
	command("say ÕâÏÂÎÒÉôÉôÓĞ¾ÈÁË!! Õâ¿ÅÍÁÁéÖê¾Í¸øÄã°É¡£\n");
return 1;

}

