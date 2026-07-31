
inherit NPC;

void create()
{
       set_name("水房管事", ({ "chaifang guanshi", "guanshi" }) );
       set("gender", "男性" );
       set("age", 50);
       set("long",
               "他是襄阳武馆的一个小管家，专管水房里的大小杂事！\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");
              set("inquiry", ([
             "挑水" : "你就在这老老实实跳水，不挑满所有的缸，你就别想回去覆命！",
	       
       ]) );
       setup();

}
