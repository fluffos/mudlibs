
inherit F_BOAT;

void create()
{
        set_name("小帆船", ({ "boat" }));
        set("short", "小帆船");
        set_weight(1000000);
        set_max_encumbrance(700000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一条简陋的自制帆船，船身上下全是用树木做成。航行时可以看见(lookout)
一排排的风浪从大海打来，使之不住地颠簸。\n");
                set("value", 50);
                set("location", 1);
                set("outdoors", "大海");
        }
        setup();
}

int is_container() { return 1; }

void init()
{
   add_action("do_turn","turn");
   add_action("do_out","out");
   add_action("do_start","start");
   add_action("lookout","lookout");
   add_action("do_stop","stop");
}
