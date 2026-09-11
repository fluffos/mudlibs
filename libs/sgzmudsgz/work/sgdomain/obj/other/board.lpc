inherit OBJ;
inherit M_READABLE;
private string board_name;
string do_desc();

nomask void create(string name) {
    ::create();
    if (!clonep(this_object()))
        return;
	board_name = name;
    set_id("board", "留言板");
    add_id("news board");
    set_in_room_desc( (: do_desc :) );
}

private nomask string do_desc() {
	return board_name;
}