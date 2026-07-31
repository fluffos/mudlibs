
inherit F_BOAT;

void create()
{
        set_name("海船", ({ "boat" }));
        set("short", "海船");
        set_weight(1500000);
        set_max_encumbrance(900000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一条海船，行驶速度颇快。从海船的窗口向外张望(lookout)，可以观
赏到海面上的风景。船舱中有本航海须知(sign)。\n");
                set("outdoors", "大海");
                set("location", 1);
                set("item_desc", ([
                     "sign" : "\n上船离岸(start)以后，操纵(turn)海船航行，并且可以不时停下来(stop)，
千万别忘记携带罗盘，不然你会迷失在茫茫大海之中。\n\n",
                   ]));
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
