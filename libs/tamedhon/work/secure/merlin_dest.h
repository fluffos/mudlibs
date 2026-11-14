// 2024/05/23 wo befindet sich merlin ausgelagert - Aloy

string merlin_dest(string *path)
{
  string ans;
    
  switch(path[0])
  {
      case "d":
          if(path[1] == "gidhrog")
	  {
	      if(path[3] == "park")
	      { ans="Ich spaziere im Stadtgarten von Gidhrog."; }
	      else if(path[3] == "kanalisation")
	      { ans="Ich bin in der Kanalisation von Gidhrog."; }
	      else
	      { ans="Ich bin irgendwo in Gidhrog."; }
	  }
	  else if((path[1] == "tal") && (path[3] == "brownies"))
	  { ans="Ich schaue gerade bei den Brownies vorbei!"; }

	  else
	  { ans="Ich bin in der Region "+capitalize(path[1])+"!"; }
          break;
      case "players":
          ans="Bin bei "+capitalize(path[1])+" auf Besuch!";
          break;
      case "gilden":
          if(path[1][0..5] == "files.") { path[1]=path[1][6..]; }
	  ans="Ich befinde mich in der "+capitalize(path[1])+"-Gilde.";
          break;
      default:
          break;
  }
  
  return ans;
}
