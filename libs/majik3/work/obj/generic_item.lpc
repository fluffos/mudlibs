inherit WEAPON;

string type;

generate (string str)
{
  string s1, s2, mat, wea;
  string *k;

  sscanf (str, "%s_%s", s1, s2);

  if (s1 == "random")
    {
      k = MATERIAL_D->query_all_materials();

      while (1)
       {
         mat = k[random(sizeof(k))];
         if (random(9)+1 < MATERIAL_D->query_wrar(mat))
           break;
       }

    }
  else
    mat = s1;

  if (s2 == "random")
    {
      k = keys("obj/generic"->query_weapons());
      wea = k[random(sizeof(k))];
    }
  else
    {
      k = keys("obj/generic"->query_weapons());
      if (member_array(s2, k) == -1)
        wea = k[random(sizeof(k))];
      else
        wea = s2;
    }

  type = mat+"_"+wea;
}

create_item ()
{
  string mat, wea, *w, *list, *l;
	int i;
	
  if (!type)
    return;

  sscanf (type, "%s_%s", mat, wea);
	
	l = explode(wea, " ");
	list = ({ });
	for (i = 0; i < sizeof(l); i++)
		list += ({ implode(l[i..<1], " ") });

  w = "obj/generic"->query_weapons()[wea];

  set_name (({ mat+" "+wea }) + list);
  set_short (article(mat + " " + wea));
  set_long ("This is a typical "+wea+" made of "+mat+".\n");
  set_material(mat);
  set_dimensions (w[0], w[1], w[2]);
  set_handling_type (w[4]);
}
