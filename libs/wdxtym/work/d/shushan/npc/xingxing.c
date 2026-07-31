//shushan2 by yushu@SHXY 2000.12
// lilong alter 2002.01.18
inherit NPC;
void create()
{
        set_name("ÐÇÐÇ", ({"xingxing", "xing"}));
        set("gender","ÄÐÐÔ");
	 set("class", "xiake");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",500000);
        set("attitude","heroism");
        set("chat_chance", 10);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("literate", 120);
 	 set("jiali", 200);
	 set("neili", 200);
        set("max_qi", 700);
        set("max_jing", 500);
        setup();
       carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 40);
}

void init()
{
::init();
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$NÏòÐÇÐÇÎÊµÀ£ºÐ¡Ê¦µÜ£¬¿ª·¹ÁËÂð£¿\n", this_player());

        if((int)this_player()->query("food") >=
             (int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("ÐÇÐÇÐ¦µÀ£º»¹Ã»×öºÃ£¡\n");

        if((present("gongbao jiding", this_player())))
        return notify_fail("ÐÇÐÇÐ¦µÀ£º²»ÒªÄÃ×ÅÊÖÀïµÄ£¬»¹¿´×Å¹øÀïµÄ!\n");
	
	 if ( present("gongbao jiding", environment()) )
         return notify_fail("ÐÇÐÇÐ¦µÀ£ºÄÇ²»ÊÇÓÐÒ»ÅÌÂï£¬³ÔÍêÔÙËµ£¡\n");

       m=new("clone/food/baozi");
       mm=new("clone/food/jiudai");


        m->move(this_player());
        mm->move(this_player());
             
        command("hoho");
        message_vision("ÐÇÐÇ¶Ô$NÐ¦µÀ£º¶öÁË°É£¬Âýµã³Ô£¡£¡\n", this_player());
        return 1;
}

 

ÿ
