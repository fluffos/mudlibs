
inherit F_BOAT;

void create()
{
        set_name("大海船", ({ "boat" }));
        set("short", "大海船");
        set_weight(2000000);
        set_max_encumbrance(1400000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一条大帆船，白帆挂在十余丈高的双桅上，行驶速度颇快。但帆船
虽大，在惊涛骇浪中也会成了无主游魂，只是随风飘荡，所以你必须有一身
高深的武功和高明的航海本领，才可在大海中行驶。从大海船的窗口向外张
望(lookout)，可以观赏到海面上的风景。船舱中有本航海须知(sign)。\n");
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
