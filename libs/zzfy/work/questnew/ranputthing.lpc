void reset()
{
        object con, item, cave;
        object *inv;
        ::reset();
        cave = present("cave", this_object());
        inv = all_inventory(cave);
        if( !sizeof(inv) && !random(4)) {
        con = new(__DIR__"obj/cave1");
        item = new(__DIR__"obj/thing2");
        item->move(con);
        item = new(__DIR__"obj/medicine");
        item->move(con);
        con->move(cave);
        }
        
}