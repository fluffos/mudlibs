// booksell

inherit NPC;
inherit F_DEALER;
int set_vendor();
void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title","书店伙计");
	set("gender", "男性" );
	set("age", 20+random(10));
	set("long",
		"这位伙计板着张脸，仿佛谁欠他钱一样。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("random_npc",1);
	set("rank_info/respect", "伙计大侠");
	setup();
    set_vendor();
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
    
}

int set_vendor()
{
	int *pool=({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}),a,b,c,d,e,f,g;
	string book_name;
	a=pool[random(sizeof(pool))];
	pool-=({a});
	b=pool[random(sizeof(pool))];
	pool-=({b});
	c=pool[random(sizeof(pool))];
	pool-=({c});
	d=pool[random(sizeof(pool))];
	pool-=({d});
	e=pool[random(sizeof(pool))];
	pool-=({e});
	f=pool[random(sizeof(pool))];
	pool-=({f});
	g=pool[random(sizeof(pool))];
	if (random(100)>79&&load_object("/d/hangzhou/obj/books/book_strategy_2"))
	book_name="/d/hangzhou/obj/books/book_strategy_2";
	else
	book_name="/d/yingtianfu/neicheng/obj/history-"+g;
	set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-"+a,
        "/d/yingtianfu/neicheng/obj/history-"+b,
        "/d/yingtianfu/neicheng/obj/history-"+c,
        "/d/yingtianfu/neicheng/obj/history-"+d,
        "/d/yingtianfu/neicheng/obj/history-"+e,
        "/d/yingtianfu/neicheng/obj/history-"+f,
        book_name,
	}));
    return 1;
}