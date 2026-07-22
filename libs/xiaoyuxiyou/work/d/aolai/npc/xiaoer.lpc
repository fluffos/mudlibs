inherit F_VENDOR_SALE;

void create()
{
    	reload("aolai_xiaoer");
    	set_level(1);
	set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
	set("shop_id",({"waiter","xiaoer","xiao","er"}));
	set("shop_title","店小二");
	set("gender", "男性");
	set("age", 26);
	set("per", 14);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("unarmed", 10);
 	set("vendor_goods", ([
                "jiudai": "/d/moon/obj/jiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "jitui": "/d/ourhome/obj/jitui",
                "huasheng": "/d/ourhome/obj/huasheng",
        ]) );
 	setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say(name()+ "笑咪咪地说道：这位" +RANK_D->query_respect(ob)+ "，进来歇歇脚，喝两盅吧。\n");
                        break;
        }
}

int accept_object(object me,object ob)
{
        object m;
        if (ob->query("id")=="old hen" && !userp(ob) ) 
        {
		command("hehe " + this_player()->query("id") );
		m=new("/d/obj/food/jitui");
		m->move(this_player());
		message_vision(name()+"偷偷塞给$N一根烤鸡腿。\n", this_player());
        	return 1;
        }
        else return 0;
}