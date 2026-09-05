#ifndef EXIT_CON_H
#define EXIT_CON_H

string convert_exit_name (string str) {    
   if(!str) return "";
   str = lower_case(str);    
   if (str == "u") return "up";    
   if (str == "d") return "down";    
   if (str == "n") return "north";    
   if (str == "s") return "south";    
   if (str == "w") return "west";    
   if (str == "e") return "east";    
   if (str == "nw") return "northwest";    
   if (str == "ne") return "northeast";    
   if (str == "sw") return "southwest";    
   if (str == "se") return "southeast";    
   return str;    
}  
  

string convert_to_brief(string str) {  
  if(!str) return ""; 
  str = lower_case(str); 
  if(str == "up")    return "u";  
  if(str == "down")  return "d";  
  if(str == "north") return "n";  
  if(str == "south") return "s";  
  if(str == "east")  return "e";  
  if(str == "west")  return "w";  
  if(str == "northwest") return "nw";  
  if(str == "northeast") return "ne";  
  if(str == "southwest") return "sw";  
  if(str == "southeast") return "se";  
  return str;  
}  

string reverse_exit(string str) {
  if(!str) return ""; 
  str = lower_case(str); 
  if(str == "up")    return "down";  
  if(str == "down")  return "up";  
  if(str == "north") return "south";  
  if(str == "south") return "north";  
  if(str == "east")  return "west";  
  if(str == "west")  return "east";  
  if(str == "northwest") return "southeast";  
  if(str == "northeast") return "southwest";  
  if(str == "southwest") return "northeast";  
  if(str == "southeast") return "northwest";  
  return str;  
}  
  


#endif /* EXIT_CON_H */

