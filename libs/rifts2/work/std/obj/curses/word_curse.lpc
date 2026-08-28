/*  /std/obj/curses/word_curse.c

 *  Made for DarkeMUD

 *  Created by Geldron 031096

 *  Copyright (c) 1996, DarkeMUd

 *  Do not remove this header

 */



inherit "/std/spells/shadows/shadow";



private object me;



void sh_init(object ob) {

    if(query_shadowing(ob)) {

	call_out("remove", 1);

	return;

    } 

    begin_shadow(ob);

    me = ob;

    call_out("remove_me", random(60) + 85);

}



void receive_message(string msg_class, string msg) {

    string *tmp;

    int i;



    tmp = explode(msg, "");

    for(i = 0; i < sizeof(tmp); i++)

	if(random(2) && member_array(tmp[i], ({ "a", "b", "c", "d",

	    "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",

	    "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "A", "B",

	    "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",

	    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" })) != -1)

	    tmp[i] = CAP(tmp[i]);

    return me->receive_message(msg_class, implode(tmp, ""));

}



void remove_me() {

    stop_shadow();

    remove();

}

