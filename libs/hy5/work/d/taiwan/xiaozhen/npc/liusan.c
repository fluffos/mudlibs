inherit NPC;
int go_leave();
void on_board();
void arrive();
void create()
{
        set_name("刘三爷",({"liusan","liu"}));
        set("gender","男性");
        set("combat_exp",300000);
        set("force",700);
        set("max_force",700);
        set("nickname","独眼");
        set("long","刘三靠着在这海峡两边倒运货物赚了许多,看来
这次他正好要出海,你可以问他关于出海的事情");
        set("inquiry",([
                 "独眼":"我以前不听人家的话,到庄家老屋去,丢了一只眼睛!\n",
             ]));
        set("age",43);
              set_skill("parry",120);
              set_skill("dodge",120);
              set_skill("unarmed",120);
              setup();
              carry_object("/clone/misc/cloth")->wear();
              add_money("silver",80);
 }
