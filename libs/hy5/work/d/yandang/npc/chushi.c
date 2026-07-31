inherit NPC;
void create()
{
        set_name("吴胖子", ({ "wu pangzi", "wu"}) );
        set("title", "厨师");
        set("gender", "男性");
        set("age", 35);
        set("long",
"吴胖子敞着衣服,露出胸前的一丛黑毛,正忙得团团转\n"
               ); 

        set("attitude", "peaceful");
        set("combat_exp", 10);
        setup();
}
