// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/create_wiz.inc
// Description:
//
// $Log: create_wiz.inc,v $
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

int master_create_learner(string owner)
{
    object player, stab;
    string wizard, workroom;

    if (!stringp(owner))
	return 0;
    owner=lower_case(owner);
    if (!(player=find_player(owner)))
	return 0;

    if (object_name(previous_object()) !=  "/room/rathaus/div/leo" ||
	!learnerp(player))
    {
	tell_object(player, "Dies ist ein illegaler Versuch !\n");
	return 0;
    }

    /* Freaky: Man muss den neuen Goettern die UID umsetzen ! */
    funcall(bind_lambda(unbound_lambda(({}),({#'seteuid, 0 })),player));
    seteuid(LEARNER_UID);
    export_uid(player);
    funcall(bind_lambda(unbound_lambda(({}),({#'seteuid, LEARNER_UID })),
								player));
    stab=clone_object("/obj/zauberstab");
    seteuid(getuid());
    stab->move(player);

    wizard = "/w/" + owner;
    workroom = wizard + "/workroom";

    if (file_size(wizard) == -1)
    {
	mkdir(wizard);
	tell_object(player, "Du hast nun ein Home-Directory: " +
		    wizard + "\n");
    }

    if (file_size(workroom+".c") <= 0)
    {
	if (write_file(workroom+".c", read_file("/room/workroom.c"))) 
	    tell_object(player, "Du hast nun einen Arbeitsraum: " + workroom + ".c\n");
	else
	    tell_object(player, "Konnte den Arbeitsraum fuer dich nicht erzeugen !\n");
    }
    return 1;
}

int master_create_geselle(string owner)
{
    object player, stab;

    if (!owner)
	return 0;
    owner=lower_case(owner);
    if (!(player=find_player(owner)))
	return 0;

    if (object_name(previous_object()) !=  "/room/rathaus/div/leo" ||
	!gesellep(player))
    {
	tell_object(player, "Dies ist ein illegaler Versuch !\n");
	return 0;
    }

    /* Freaky: Man muss den neuen Goettern die UID umsetzen ! */
    funcall(bind_lambda(unbound_lambda(({}),({#'seteuid, 0 })),player));
    seteuid(owner);
    export_uid(player);
    funcall(bind_lambda(unbound_lambda(({}),({#'seteuid, owner })),player));
    seteuid(getuid());

    if ((stab=present("zauberstab",player)) &&
	object_name(stab)[0..15]=="/obj/zauberstab#")
    {
	/* Freaky: Man muss dem Zauberstab die UID umsetzen ! */
	funcall(bind_lambda(unbound_lambda(({}),({#'seteuid, 0 })),stab));
	seteuid(owner);
	export_uid(stab);
	funcall(bind_lambda(unbound_lambda(({}),({#'seteuid, owner })),stab));
	seteuid(getuid());
	stab->add_commands();
    }
    return 1;
}
