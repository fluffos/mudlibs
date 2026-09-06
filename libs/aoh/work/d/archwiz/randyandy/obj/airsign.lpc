inherit "std/thing";

void create() {
	::create();
	SetShort("A sign");
	SetLong(
"A huge sign stands here. There's something written on it.\n");
        AddId("sign");
        SetWeight(100000);
        SetValue(10);
}

init() {
	::init();
	add_action("read", "read");
}

read(str) {
	if(!str) return 0;
	if (str != "sign") return 0;
	write("    Nightfall Central Airport\n");
	return 1;
}

