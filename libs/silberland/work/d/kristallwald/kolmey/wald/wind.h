#define TEST								    \
AddCmd( ({ "wind" }), "c_test");					    \

#define DETAILS							            \
AddSpecialDetail( ({ "wind", "brise" }), "wind");			    \
AddSpecialDetail( ({ "glanz" }), "glanz");			            \

#define DESC							            \
string wind()                                                               \
{ 									    \
  string wind;								    \
  if(!wind_da)		   						    \
  {									    \
     wind =								    \
     "Sowas siehst Du da nicht!";					    \
  }									    \
  else									    \
  {									    \
     wind =								    \
     "Eine leichte Brise weht von "+richtung+" herein und bringt "+         \
     "silbernen zarten Glanz mit sich.";		                    \
  }									    \
  return break_string(wind, 78);					    \
}									    \
									    \
string glanz()								    \
{									    \
  string glanz;								    \
  if(!wind_da)								    \
  {									    \
     glanz =								    \
     "Sowas siehst Du da nicht!";					    \
  }									    \
  else									    \
  {									    \
     glanz =								    \
     "Ein strahlender silberner Glanz aus dem "+richtung+" erfuellt "+      \
     "den Raum und vermischt sich mit dem Funkeln und Glitzern der "+       \
     "Kristalls. Ein wahrlich wunderschoener Anblick!";		            \
  }									    \
  return break_string(glanz, 78);					    \
}									    \

#define SEQ1								    \
void wind_da()								    \
{									    \
  write("Eine leichte Brise zieht von "+richtung+" herein.\n"		    \
  	"Ploetzlich wird die Umgebung in silbernen Glanz getaucht.\n");     \
}									    \

#define SEQ2								    \
void wind_weg()								    \
{									    \
  write("Die leichte Brise aus dem "+richtung+" laesst nach.\n"		    \
  	"Der silberene Glanz verblasst.\n");     			    \
}									    \

#define TEST_FUNC						            \
int c_test(string str)							    \
{  									    \
   notify_fail(BS("Wind?"));						    \
   if(!(str == ""))							    \
   {									    \
     return 0;								    \
   }									    \
   if(!wind_da)								    \
   {									    \
     write(BS("Wind ein!"));						    \
     call_out("wind_da", 0);						    \
     return 1;								    \
   }									    \
   else									    \
   {									    \
     write(BS("Wind aus!"));						    \
     call_out("wind_weg", 0);						    \
     return 1;								    \
  }									    \
}									    \