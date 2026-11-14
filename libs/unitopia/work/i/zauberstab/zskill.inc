// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zskill.inc
// Description: Skillhandling (Skills manipulieren)
// Author:	Freaky (23.12.93)
//
// $Log: zskill.inc,v $
// Revision 1.4  2015/08/26 21:32:21  gnomi
// Typen verfeinert.
//
// Revision 1.3  2014/05/20 21:42:59  gnomi
// Typen korrigiert.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types

private void write_skill(mixed *node,int tab) {
    int i;
    string indent,out;

    if (!node)
	return;
    indent = copies(" ",tab);
    for (i=0; i<sizeof(node); i++) {
	out = node[i][0]+" "+node[i][1]+"  ";
	W(out);
	if (sizeof(node[i]) == 3 && sizeof(node[i][2])) {
	    write_skill(node[i][2],tab+strlen(out));
	    if (i != sizeof(node)-1)
		W(indent);
	    }
	else
	    if (i == sizeof(node)-1)
		W("\n");
	    else
		W("\n"+indent);
	}
}

private string|mixed* subskill(mixed *skillst,string skillpfad) {
    int i;
    string *skill;

    if (!skillst || !skillpfad)
	return 0;
    skill=explode(skillpfad,",");
    if (!skill || sizeof(skill)<=0)
	return 0;
    for (i=0; i<sizeof(skillst); i++)
	if (skillst[i][0]==skill[0])
	    if (sizeof(skillst[i]) == 3 && sizeof(skillst[i][2]) > 0)
		if (sizeof(skill) == 1)
		    return skillst[i][2];
		else
		    return subskill(skillst[i][2],
				implode(skill[1..],",") );
	    else
		if (sizeof(skill) == 1)
		    return skillst[i][1]+" Punkte.\n";
   return 0;
}

int z_skilloeschen(string str) {
    string obst, pfad;
    object ob;

    SECURE;
    HELP("zskilloeschen");
    if (!str)
	FAIL(query_verb()+" [<Objektstring>] <Skill-Pfad>\n");
    if (sscanf(str,"%s %s",obst,pfad)!=2) {
	obst=MARK_ICON;
	pfad=str;
	}
    ob=SO(obst);
    if (!ob)
	return 0;
    if (ob->delete_skill_path(explode(pfad,",")))
	W("Ok.\n");
    else
	W("Angegebener Skill-Pfad existiert nicht.\n");
    PRINT;
    return 1;
}

int z_skillalles(string str) {
    object ob;

    SECURE;
    HELP("zskillalles");
    ob=SO(str);
    if (!ob)
	return 0;
    write_skill(ob->query_skill_structure(),0);
    PRINT;
    return 1;
}

int z_skill(string str) {
    string obst, pfad;
    string|mixed* skillstruc;
    object ob;

    SECURE;
    HELP("zskill");
    if (!str)
	FAIL(query_verb()+" [<Objektstring>] <Sub-Skill>\n");
    if (sscanf(str,"%s %s",obst,pfad)!=2) {
	obst=MARK_ICON;
	pfad=str;
	}
    ob=SO(obst);
    if (!ob)
	return 0;
    skillstruc=subskill(ob->query_skill_structure(),pfad);
    if (!skillstruc) {
	W(Name(ob)+" hat keinen Skill-Pfad '"+pfad+"'.\n");
	PRINT;
	return 1;
	}
    if (!pointerp(skillstruc)) {
	W(Name(ob)+" hat im Skill-Pfad '"+pfad+"' "+skillstruc);
	PRINT;
	return 1;
	}
    write_skill(skillstruc,0);
    PRINT;
    return 1;
}

int z_skilladdieren(string str) {
    string obst, pfad, *skill;
    int summ;
    object ob;

    SECURE;
    HELP("zskilladdieren");
    if (!str)
	FAIL(query_verb()+" [<Objektstring>] <Skill-Pfad> <Summand>\n");
    if (sscanf(str,"%s %s %d",obst,pfad,summ)!=3) {
	obst=MARK_ICON;
	if (sscanf(str,"%s %d",pfad,summ)!=2)
	    FAIL(query_verb()+" [<Objektstring>] <Skill-Pfad> <Summand>\n");
	}
    ob=SO(obst);
    if (!ob)
	return 0;
    skill = explode(pfad,",");
    if (!skill)
	FAIL("Fehler im Skill-Pfad.\n");
    ob->add_skill_points(skill,summ);
    summ=ob->get_one_skill(skill);
    W(Name(ob)+" hat nun im Skill-Pfad '"+pfad+"' "+summ+" Punkte.\n");
    PRINT;
    return 1;
}

int z_skillsumme(string str) {
    string obst, pfad, *skill;
    int summ;
    object ob;

    SECURE;
    HELP("zskillsumme");
    if (!str)
	FAIL(query_verb()+" [<Objektstring>] <Skill-Pfad>\n");
    if (sscanf(str,"%s %s",obst,pfad)!=2) {
	obst=MARK_ICON;
	pfad=str;
	}
    ob=SO(obst);
    if (!ob)
	return 0;
    skill = explode(pfad,",");
    if (!skill)
	FAIL("Fehler im Skill-Pfad.\n");
    summ=ob->compute_one_skill(skill);
    W(Name(ob)+" hat als Summe des Skill-Pfades '"+
	  pfad+"' "+summ+" Punkte.\n");
    PRINT;
    return 1;
}
