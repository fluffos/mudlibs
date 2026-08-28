string
tee_messu (string nimi, string color, string messu)
{
   string args;
   string *hii;
   
   args = wrap(messu, 78-11);
   
   hii = explode(args, "\n");
   
   hii[0] = sprintf("%-9s: %s", capitalize(nimi), color) + hii[0];
   
   for (int j=1;j<sizeof(hii);j++)
	 hii[j] = repeat_string(" ", (11)) + hii[j];
							
   if (color != "")
     return implode(hii, "\n") + "^c0\n";
   else
	 return implode(hii, "\n") + "\n";
}


int
main (string str)
{
   string nimi, messu, color;
   
   if (!str) {
	  notify_fail ("Usage: rpgsay jotain.\n");
	  return 0;
   }
	
   if (sscanf (str, ":%s %s", nimi, messu) != 2)
	 sscanf (str, "%s", messu);
   
   if (nimi && THIS->query_name() != "smoky")
	 nimi = 0;
   
   if (nimi && (nimi != "arien" && nimi != "darnek"))
	 nimi = 0;
   
   if (!nimi)
	 switch (THIS->query_name()) {
	  case "namhas":
		nimi = "namhas";
		break;
	  case "yorkaturr":
		nimi = "yorkaturr";
		break;
	  case "malekith":
		nimi = "petrul";
		break;
	  case "jormap":
		nimi = "raktar";
		break;
	  case "zac":
		nimi = "arien";
		break;
	  case "smoky":
		nimi = "darnek";
		break;
	  case "harum":
		nimi = "conina";
		break;
	  default:
		nimi = "luuska";
		break;
	 }
   
   if (nimi == "luuska") {
	  write ("Et oo pelis. Mee pois!\n");
	  return 1;
   }
   
   switch (nimi) {
	case "petrul":
	  color = "^cC";
	  break;
	case "yorkaturr":
	  color = "^cL";
	  break;
	case "arien":
	  color = "^cG";
	  break;
	case "darnek":
	  color = "^cR";
	  break;
	case "raktar":
	  color = "^cY";
	  break;
	case "namhas":
	  color = "^c1";
	  break;
	case "conina":
	  color = "^cP";
	  break;
	default:
	  color = "^cP";
	  break;
   }
   
   tell_room (ENV(THIS), tee_messu(nimi, color, messu));
   write_file ("/log/day5.log", tee_messu(nimi, "", messu));
   return 1;
}
