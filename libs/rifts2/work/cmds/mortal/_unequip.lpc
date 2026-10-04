/*  /cmds/mortal/_unequip.c
 *  Made for DarkeMUD
 *  Created by Geldron 031096
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */


inherit DAEMON;

int cmd_unequip(string arg) {
    object *tmp;
    int i;

    if(arg) {
	write(syntax("unequip"));
	return 1;
    }
    write("You begin power unequipping.  Please wait...");
    tmp = all_inventory(TP);
    for(i = 0; i < sizeof(tmp); i++) {
	if((int)tmp[i]->is_armour() && (object)tmp[i]->query_worn())
	   call_out("forces", 0, "remove " + ((string *)tmp[i]->query_id())[0], TP);
      
        if((int)tmp[i]->is_armour() && (object)tmp[i]->query_worn()){
	  if((string)tmp[i]->query_type() == "bracer" || "gauntlet") {
      call_out("forces", 0, "remove " + ((string *)tmp[i]->query_id())[0]+" 2", TP);
	  }
	}
	if((int)tmp[i]->is_weapon() && (object)tmp[i]->query_wielded())
	  call_out("forces", 0, "unwield " + ((string *)tmp[i]->query_id())[0], TP);
     }
    call_out("relay_message", 0, TP);
    return 1;
}

protected void forces(string str, object ob) {
    if(ob)
	ob->force_me(str);
}

protected void relay_message(object ob) {
    if(ob)
	message("unequip", "Done Unequiping.", ob);
}

void help() {
    message("unequip_help", syntax("unequip") + "\n\n"
      "Unequips all your armour and weapons in order.", TP);
}
