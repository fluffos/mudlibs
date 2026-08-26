inherit OBJECT;

void create() {
    set("short", "a gag");
    set("prevent_clean", 1);
    set("id", ({ "gag" }) );
}

void init() {
    add_action("block", "");
}

int block() {
    if (TPN=="Cyanide") return 0;


    else {
	write("Umm.. no.\n");
	return 1;
    }
}
