int
main (string str)
{
    object ob;
    string meep;
    string targ, arg, *k, m;
    int i;
    
    if (!str) {
	write ("Usage: stat <object | material:name> [skills/truenames]\n");
	return 1;
    }
    
    if (sscanf(str, "material:%s", arg) == 1)
    {
	if (!MATERIAL_D->query_material(arg))
	{
	    write ("No such material exists.\n");
	    return 1;
	}
	
	k = MATERIAL_D->query_resists(arg);
	
	write ("MATERIAL: "+arg+"\n");
	write (repeat_string("-", 78)+"\n");
	write ("         value: ^c1"+MATERIAL_D->query_value(arg)+"^c0 cp/kg\n");
	write ("        weight: ^c1"+MATERIAL_D->query_weight(arg)+"^c0 kg/dm^3\n");
	write (" weapon rarity: ^c1"+MATERIAL_D->query_wrar(arg)+"^c0\n");
	write (" armour rarity: ^c1"+MATERIAL_D->query_arar(arg)+"^c0\n");
	write ("          type: ^c1"+MATERIAL_D->query_type(arg)+"^c0\n");
	write ("\n");
	write ("                PHY FIR COL ELE ACI DIS MAG POI\n");
	write ("   resistances: "+
	       sprintf ("^c1%3d^c0 ^c1%3d^c0 ^c1%3d^c0 ^c1%3d^c0 ^c1%3d^c0 ^c1%3d^c0 ^c1%3d^c0 ^c1%3d^c0\n",
			k[0], k[1], k[2], k[3], k[4], k[5], k[6], k[7]));
	write (repeat_string("-", 78)+"\n");
	return 1;
    }
    
    if (sscanf(str, "%s %s", targ, arg) != 2)
	targ = str;
    
    if (targ == "here")
	ob = environment(THIS);
    else if (targ == "me")
	ob = THIS;
    else
	ob = (find_living (targ) || find_object (targ) || present (targ));
    
    if (!ob)
    {
	notify_fail("No such object: " + targ + "\n");
	return 0;
    }
    
    switch(arg)
    {
      case "skills" :
	meep = ob->list_skills();
	break;
      case "truenames" : 
	k = ob->query_known_true_names();
	meep = sprintf("^bb^cW%-78s^c0\n", "True names known by " + ob->query_cap_name());
	for (i = 0; i < sizeof(k); i++)
	{
	    m = ob->query_magical_true_meaning(k[i]);
	    meep += sprintf("%-13s %-12s: %d\n", m, "(" + k[i] + ")", ob->query_skill_chance("name_of_" + m));
	}
	break;	
      default:
	meep = ob->stat_me();
    }
    
    if (!meep)
	write ("It does not contain any statistics.\n");
    else
	write (meep);
    
    return 1;
}
