#define Beschreibungen
string *ast_gr = ({});
string *ast_ob = ({});
int ast_da;

#define Details
AddSpecialDetail( ({ "ast" }), "ast");

#define Commands
AddCmd( ({ "greife", "greif" }), "cmd_hold");
AddCmd( ({ "ziehe", "zieh" }), "cmd_gothere");
AddCmd( ({ "lass", "lasse" }), "cmd_let");
AddCmd( ({ "huepf", "huepfe" }), "cmd_getdown");
AddCmd( ({ "breche", "brech", "brich" }), "cmd_break");
AddCmd( ({ "kletter", "klettere" }), "cmd_up");
grundzustand();

#define Resetx
reset()
{
  ::reset();
  grundzustand();
}

void grundzustand()
{
  ast_da = 1;
}

#define Funktionen
int cmd_hold(string str)
{
   notify_fail(BS("Nach was moechtest Du denn greifen?"));
   if(!(str == "nach ast"))
   {
     return 0;
   }
   if(!ast_da)
   {
   write(BS("Da ist kein Ast!"));
   return 1;
   }
   if(AST_GR(TP))
   {
   write(BS("Du haeltst den Ast schon fest!"));
   return 1;
   }
   if(AST_OB(TP))
   {
   write(BS("Du sitzt doch schon auf dem Ast!"));
   return 1;
   }
   if(sizeof(ast_gr)>=1)
   {
   write(BS("An dem Ast haelt sich schon "+CAP(ast_gr[0])+"! "
   	    "Mehr druck wuerde der nicht aushalten."));
   return 1;
   }
   if(sizeof(ast_ob)>=1)
   {
   write(BS("Auf dem Ast waere kein Platz mehr fuer Dich."));
   return 1;
   }
   write(BS("Du greifst nach dem Ast.\n"));
   tell_room(ENV(TP), TPN+" greift nach einem Ast.\n", ({TP}));
   ast_gr += ({ capitalize(getuid(TP)) });
   return 1;
}

int cmd_gothere(string str)
{
   notify_fail(BS("Wohin moechtest Du Dich denn ziehen?"));
   if(!(str == "auf ast" || str == "auf ast hinauf" || str == "hinauf"
     || str == "nach oben" || str == "auf ast rauf" || str == "rauf"
     || str == "auf baum hinauf" || str == "auf baum rauf" 
     || str == "auf baum"))
   {
     return 0;
   }
   if(!ast_da)
   {
   write(BS("Da ist kein Ast!"));
   return 1;
   }
   if(!AST_GR(TP))
   {
   write(BS("Du solltest vorher nach dem Ast greifen!"));
   return 1;
   }
   if(AST_OB(TP))
   {
   write(BS("Du sitzt doch schon auf dem Ast!"));
   return 1;
   }
   if(sizeof(ast_ob)>=1)
   {
   write(BS("Auf dem Ast ist kein Platz mehr fuer Dich."));
   return 1;
   }
   write(BS("Du kletterst auf den Ast hinauf."));
   tell_room(ENV(TP), TPN+" klettert auf den Ast.\n", ({TP}));
   ast_gr -= ({ capitalize(getuid(TP)) });
   ast_ob += ({ capitalize(getuid(TP)) });
   return 1;
}

void BecomesNetDead(object pl)
{
  if(AST_GR(pl))
  ast_gr -= ({ capitalize(getuid(pl)) });
  if(AST_OB(pl))
  ast_ob -= ({ capitalize(getuid(pl)) });
}

varargs int PreventLeave(object pl, mixed dest)
{ 
  if(AST_OB(pl))
  {  
     write(BS("Du solltest vorher wieder zurueck auf den Boden "
     	      "huepfen."));
     return 1;
  }
  if(AST_GR(pl))
  {
     write(BS("Du solltest den Ast vorher loslassen."));
     return 1;
  }
  return ::PreventLeave(pl);
}

int cmd_getdown(string str)
{
   notify_fail(BS("Wohin moechtest Du huepfen?"));
   if(!(str == "herunter" || str == "runter" || str == "von ast"
     || str == "von ast herunter" || str == "von baum" 
     || str == "von baum herunter" || str == "auf boden"))
   {
     return 0;
   }
   if(!AST_OB(TP))
   {
     write(BS("Aber Du sitzt doch garnicht auf dem Ast!"));
     return 1;
   }
   if(AST_OB(TP))
   {
     write(BS("Du huepfst vom Ast herunter."));
     tell_room(ENV(TP), TPN+" huepf vom Ast herunter.\n", ({TP}));
     ast_ob -= ({ capitalize(getuid(TP)) });
     return 1;
   }
}

int cmd_let(string str)
{
   notify_fail(BS("Was moechtest Du loslassen?"));
   if(!(str == "ast los" || str == "ast aus"))
   {
     return 0;
   }
   if(!AST_GR(TP))
   {
     write(BS("Du haeltst den Ast doch garnicht fest!"));
     return 1;
   }
   if(AST_GR(TP))
   {
     write(BS("Du laesst den Ast los."));
     tell_room(ENV(TP), TPN+" laesst den Ast los.\n", ({TP}));
     ast_gr -= ({ capitalize(getuid(TP)) });
     return 1;
   }
}

int cmd_break(string str)
{
   notify_fail(BS("Was moechtest Du denn abbrechen?"));
   if(!(str == "ast ab" || str == "ast"))
   {
     return 0;
   }
   if(!ast_da)
   {
   write(BS("Da ist kein Ast!"));
   return 1;
   }
   if(TP->QueryAttribute(A_STR)<=10)
   {
   write(BS("Du zerrst etwas an dem Ast herum, schaffst es aber nicht "
   	    "ihn abzubrechen. Tja, dafuer brauchst Du wohl etwas mehr "
   	    "Kraft!"));
   tell_room(ENV(TP), TPN+" zerrt an einem Ast herum, ist aber zu schwach "
   			  "ihn ganz abzubrechen.\n", ({TP}));
   return 1;
   }
   if(sizeof(ast_ob)>=1)
   {
   write(BS("Auf dem Ast sitzt noch "+CAP(ast_ob[0])+"!"));
   return 1;
   }
   if(AST_OB(TP))
   {
   write(BS("Aber Du sitzt doch noch auf dem Ast!"));
   return 1;
   }
   if(!AST_OB(TP) && sizeof(ast_ob)<=0)
   {
     write(BS("Du brichst den Ast ab."));
     tell_room(ENV(TP), TPN+" bricht einen Ast ab.\n", ({TP}));
     ast_da=0;
     return 1;
   }
}

string ast(string key)
{
  string ast;
  if(!ast_da)
  {
    return BS("Sowas siehst Du da nicht!");
  }
  if(AST_OB(TP))
  {
    return BS("Du sitzt auf dem kleinen Ast ca. einen halben Meter ueber "
              "dem Boden. Von hier aus koenntest Du ohne Probleme nach oben "
              "klettern. Du kannst aber auch wieder zurueck auf den Boden "
              "huepfen.");
  }
  if(AST_GR(TP))
  {
    return BS("Du haeltst Dich an dem Ast fest. Du koenntest Dich auf ihn "
              "hinaufziehen oder den Ast loslassen.");
  }
  if(sizeof(ast_ob)==1)
  {
    ast = "Es sitzt gerade " + ast_ob[0] + " auf dem Ast.";  
  }  
  else
  {
     ast =
     "Ein kleiner Ast ist es, der sich in Deiner Reichweite befindet. "
     "Man koennte nach ihm greifen und sich nach oben ziehen. ";
  if(sizeof(ast_gr)==1)
     ast += "" + ast_gr[0] + " haelt sich am Ast.";
  }
  return break_string(ast, 78);
}

int cmd_up(string str)
{
  notify_fail(BS("Wohin moechtest Du denn klettern?"));
  if(!(str == "nach oben" || str == "auf baum" || str == "rauf"
    || str == "auf baum hinauf"))
  {
    return 0;
  }
  if(!AST_OB(TP))
  {
  write(BS("Du solltest zuerst vorher auf einen Ast klettern!"));
  return 1;
  }
  write(BS("Geschickt kletterst Du auf den Baum hinauf."));
  tell_room(ENV(TP), TPN+" klettert geschickt auf den Baum hinauf.\n",
    ({TP}));
  ast_ob -= ({ capitalize(getuid(TP)) });
  TP->move(ROOM("wald01"), M_GO | M_SILENT);
  return 1;
}

int cmd_see(string str)
{
  notify_fail(BS("Was moechtest Du denn betrachten?"));
  if(!(str == "spiegelbild" || str == "spiegelbild in kristallen" ||
       str == "bild" || str == "bild in kristallen"))
  {
    return 0;
  }
  write(BS("Du betrachtest in den Kristallen Dein Spiegelbild. "
  	   "Ja! Das bist eindeutig Du!"));
  return 1;
}