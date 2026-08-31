
/* chaosblade */

#define _tp this_player()
#define _tpn _tp->query_name() 

inherit "/obj/weapon";

void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
	set_name("chaosblade");
	set_alias("chaosblade of death");
	set_alt_name("sword");
	set_short("A chaosblade of death");
	set_long(
        "This is a slim, but very heavy, sword that seems to glow with\n" +
        "soft darkness. It looks strangely unnatural, and it would\n" +
        "probably be a bad move even to try to wield this weapon.\n" +
        "Maybe someone else wants it?\n" +
        "Come to think of it, wasn't there a strange shop somewhere\n" +
        "where you could bring this sword and collect a reward?\n");
	set_class(25);
	set_weight(7);
	set_value(2000);
    }
}

/* only the chaosdemon itself can wield this weapon */

int wield(string str)
{
    if (!id(str)) return 0;
    if (lower_case(_tpn) != "chaosdemon")
    {
        write(
        "The blade twists away from your grip and hovers in the air.\n"+
        "It looks at you, laughs and disappears in a blinding flash.\n");
        call_out("dest_me",0);
        return 1;
    }
    return ::wield(str);
}

void dest_me()
{
   destruct(this_object());
}
