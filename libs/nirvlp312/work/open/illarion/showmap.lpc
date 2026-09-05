string *map;
int num_lines;

void reset(status arg) {
  if(!map) {
	map = explode(
" oooooooooooooooooooooooooooooooooooooooooooooooooooo \n"+
"|                                            ()Lift()| X = You \n"+
"|    _||_            _||_            _||_            | P = Launchpad \n"+
"|   (WWWW)          (WWWW)          (WWWW)           | W = Oil Well \n"+
"|  (W    W)        (W    W)        (W    W)          |\n"+
"|   (WWWW)          (WWWW)          (WWWW)           |\n"+
"|                                                    |\n"+
"|                                                    |\n"+
"|                                                    |\n"+
"|                                     ___________    |\n"+
"|                                    |           |   |\n"+
"|    _||_                            | Cafeteria |   |\n"+
"|   (WWWW)               __          |___________|   |\n"+
"|  (W    W)             <  >                         |\n"+
"|   (WWWW)           __<    >__                      |\n"+
"|                   |  Control |             ()Lift()|\n"+
"|                   |  Center  |                     |\n"+
"|                   |__      __|            _________|\n"+
"|    _||_              |    |              |PPPPPPPPP|\n"+
"|   (WWWW)             |    |              |PPP   PPP|\n"+
"|  (W    W)            |    |              |PPP   PPP|\n"+
"|   (WWWW)             |    |              |PPP   PPP|\n"+
"|                      |    |              |PPPPPPPPP|\n"+
" oooooooooooooooooooooooooooooooooooooooooooooooooooo \n", "\n");
    num_lines=sizeof(map);
  }
}

string get_description(int x,int y,string description,string char_to_display) {
  string final_desc;
  string *additional_lines;
  int row;
  string line;
  int num_additional;
  additional_lines = explode(format(description,23),"\n");
  num_additional=sizeof(additional_lines);
  write("num additional:"+num_additional);
  final_desc = "";
  for(row=0;row<num_lines;row++)
  {
    line = map[row];
    if(row==y)
	{
	  line = line[0..x-1]+char_to_display+line[x+1..strlen(line)-1];
	}
	if(row > 5 && row - 6 < num_additional)
	  line += " "+additional_lines[row-6];
	  
	final_desc += line+"\n";
  }
  return final_desc;
}
