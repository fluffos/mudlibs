//Cracked by Roath
//ling.c happ@yszz
inherit F_VENDOR_SALE;
void create()
{
    reload("wang2");
        set_name("王小二", ({"wang", "wang xiaoer", "xiaoer"}));
        set("title", "包子店老板");
        set("gender", "男性");
        set("age", 42);
        set("long", "一个很喜欢笑的商人。\n");
   set("str", 30);
   set("con", 30);
   set("spi", 30);
        set("combat_exp", 20000);
	set("daoxing",20000);	
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
   set("force", 200);
   set("max_force", 200);
   set("force_factor", 5);
        set("vendor_goods", ([
                "gbl":"/d/jz/obj/gbl",
                "tang": "/d/jz/obj/gouroutang",
                           ]));
        setup();
   add_money("silver", 20);
}

void init()
{
        add_action("do_vendor_list", "list");

}