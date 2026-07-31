#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Ð¡Í¯",({"xiao tong","xiao"}));
	set("area","Ò°ÑòÕ¯");
	set("long","×¨ÃÅÊÌºîÄãË¯¾õµÄÐ¡ÄÐº¢¡£\n");
	set("age",25);
        setup();
	carry_object("/clone/misc/cloth.c")->wear();
}
	
