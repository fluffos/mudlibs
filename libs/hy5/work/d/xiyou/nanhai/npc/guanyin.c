//Cracked by Roath
// guanyin.c 观音菩萨
// By Dream Dec. 19, 1996

inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
	set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
	set("title", "救苦救难大慈大悲");
	set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
	set("gender", "女性");
	set("age", 35);
	set("attitude", "peaceful");
	set("rank_info/self", "贫僧");
	set("rank_info/respect", "菩萨娘娘");
	set("class", "bonze");
                set("str",100);
                set("spi",80);
                set("cor",80);
                set("cps",80);
                set("con",80);
                set("per",40);
                set("int",40);
                set("kar",40);// Cigar@sjsh_SKxyj add the all attribute.
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 250);
   



	//let's use cast bighammer to protect her...weiqi:)
	create_family("南海普陀山", 1, "菩萨");

	setup();
        carry_object("/d/xiyou/nanhai/obj/jiasha")->wear();
        carry_object("/d/xiyou/nanhai/obj/nine-ring")->wield(); 
}

