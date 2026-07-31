inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("Ğ¦²¨¶ùÌì", ({"xiaoboer tian", "tian"}));
        set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄĞ¡Ñı¡£\n");
        set("age", 30);
	set("title", "Çà÷­¹Ö");
        set("attitude", "friendly");
        set("gender", "ÄĞĞÔ");
	set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",1000);
        set("max_jing", 1000);
        set("combat_exp", 350000);
  set("combat_exp", 450000);

 
set("inquiry", ([
"ºó»¨Ô°": "ÌıËµÕâºó»¨Ô°ÊÇ¸ö°ËØÔÕó£¬²»ÖªµÀ·½Î»µÄ£¬ºÙºÙ£®£®£®\n",
]) );

        setup();
        initlvl((500+random(500)),54);
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
	if( random(5) > 3  ) {
        if (objectp(present("xiao", environment(this_object())))) {
                switch( random(6) ){
                        case 0:
                                command("say Ìì²¨¶ùĞ¦£¬±ğÓÖË¯×ÅÁË£¡");
                                command("wake xiao");
                        break;
                        case 1:
                                command("say Ìì²¨¶ùĞ¦£¬ÌıËµÁúÍõÓÖÉÍÄãÁË¡£");
                                command("consider xiao");
                        break;
                        case 2:
                                command("say Ìì²¨¶ùĞ¦£¬ÏëÂïÄØ£¿");
                                command("poke xiao");
                        break;
                        case 3:
                                command("say Ìì²¨¶ùĞ¦£¬ÉÏÔÂÀ´µÄÄÇ¸öĞ¡¹¬¶ğ»¹ÕæÆ¯ÁÁ£¡");
                                command("grin xiao");
                        break;
                        case 4:
                                command("say Ìì²¨¶ùĞ¦£¬¿´ºÃÁËÃÅ£¬±ğÈÃÈËÁï½øÈ¥£¡");
                                command("kick xiao");
                        break; 
			case 5:
				command("say Ìì²¨¶ùĞ¦£¬¿ìÈ¥Ïò¹«Ö÷ÇëÊ¾·½Î»£¡");
				command("lazy xiao");
			break;
                	}
        	}
        }
	}
        return ::heal_up() + 1;
}

ÿ