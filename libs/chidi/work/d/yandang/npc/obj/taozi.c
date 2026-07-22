#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ÃÖºïÌÒ", ({ "taozi" }) );
        set("long", "Ò»ÖÖÒ°ÉúµÄË®¹û¡£\n");
        set("unit", "¿Å");
        set("weight", 100);
        set("value", 5000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
         ob=this_player();
        if( !id(arg) ) return notify_fail("ÄãÒª³ÔÊ²÷á£¿\n");
if( living(this_player()) ==0 ) return 0;
        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);

        write("[1;33mÄã³ÔÏÂÒ»¿ÅÃÖºïÌÒ£¬Ö»¾õµÃ³İ¼ÕÁô·¼,»ØÎ¶ÎŞÇî£¡\n[0;37m");

        message("vision", HIY + ob->name() + 
"Äã³ÔÏÂÒ»¿ÅÃÖºïÌÒ£¬Ö»¾õµÃ³İ¼ÕÁô·¼,»ØÎ¶ÎŞÇî£¡\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
