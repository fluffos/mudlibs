inherit EQUIP;
void create()
{
        set_name("花满城的人皮面具", ({ "skinmask" }) );
        set_weight(600);
                set("unit", "个");
                set("value", 0);
                set("material", "cloth");
                set("armor_type", "mask");
		     set("fakegender", "男性");
                set("armor_prop/id", ({"maskman"}) );
                set("armor_prop/name", ({"花满城"}) );
                set("armor_prop/short", ({"花满城(maskman)"}) );
}
