inherit ITEM;
inherit F_SAVE;

void create(string banghui)
{
        if( banghui)    set("banghui",banghui);
        if(! restore()) {
                set_name("Œﬁ–ß¡Ó≈∆",({"lingpai"}));
                set("no_use",1);
        }
        else    {
                set_name(banghui+"¡Ó≈∆",({"lingpai"}));
                set("no_use",0);
        }
        set("unit","øÈ");
        seteuid(getuid());
}

string query_save_file() { return DATA_DIR + "guild/" + query("banghui")+".o"; }

