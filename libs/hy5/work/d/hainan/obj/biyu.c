// music yangzhou's Ñ©Á«
#include <ansi.h>

inherit ITEM;
int count=20;
void create()
{
        set_name(HIC"ÇàÁú±ÌÑªÓñ"NOR, ({ "yu","biyu","qinglong" }) );
        set("long", "Ò»¿é±ÌÓñ,ÉÏÃæÌìÈ»ĞÎ³ÉÒ»ÌõÑ©ºìµÄ·ÉÁú¡£
Äã¿ÉÒÔÓÃ(use yu)À´»Ö¸´Äã¸÷ÏîÖµ,²»¹ıÖ»ÄÜÊ¹ÓÃ20´Î.
³¬¹ı´ËÏŞ,ºó¹û×Ô¸º.\n");
        set("unit", "¿é");
        set("weight", 100);
        set("money_id",1);
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("ÄãÒªÊ¹ÓÃÊ²÷á£¿\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        if (count==0) {
 message_vision("$NÊÖÖĞµÄ$nÍ»È»±©ÆğÒ»Éù¾ŞÏì,±¬Õ¨ÁË.\n",ob,this_object());
 ob->die();
 destruct(this_object());
 return 1;
                 }
        ob->set("qi",(int)ob->query("max_qi"));
        ob->set("jing",(int)ob->query("max_jing"));
        ob->set("neili",(int)ob->query("max_neili"));

         ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);
        ob->set_temp("windnod",1);
        write("[1;33mÄãÊÖÖĞµÄ±ÌÓñ·¢³öÑ©ºìµÄ¹âÃ££¡\n[0;37m");
        message("vision", HIY + ob->name() + 
"ÊÖÖĞµÄ±ÌÓñ·¢³öÑ©ºìµÄ¹â,Ò»ÉÁ²»¼û£¡\n"+NOR,
                environment(ob), ob);
     count--;
        return 1;
}
