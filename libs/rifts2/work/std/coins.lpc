//	/obj/coins.c

//	from the Nightmare mudlib

//	object for freely occurring money

//	created by Descartes of Borg september 1992



inherit "/std/Object";

inherit "/std/money";



int query_coins() { return 1; }



int move(object tmp) {

    string *currs;

    int tmp_size, i;



    if(!tmp) return ::move(tmp);

    if(!living(tmp)) return ::move(tmp);

    for(i=0, tmp_size = sizeof(currs=query_currencies()); i<tmp_size; i++) {

        tmp->add_money(currs[i], query_money(currs[i]));

        set_money(currs[i], 0);

    }

    call_out("remove", 2);

}



void create() {

    set("id", ({"pile", "pile of coins", "coins", "money" }) );

    set_name("money");

    set_short("A pile of coins");

}



string query_long(string str) {

    string *currs;

    int i, tmp;

    string desc;



    if(!query_currencies() || !sizeof(query_currencies()))

      return "This is a pile of worthless coins.";

    desc = "This is a pile of:\n";

    for(i=0, tmp=sizeof(currs=query_currencies()); i<tmp; i++) {

        if(query_money(currs[i])) desc += query_money(currs[i])+

          " "+currs[i]+"\n";

    }

    return desc;

}



