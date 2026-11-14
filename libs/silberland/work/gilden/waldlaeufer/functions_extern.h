//** Einige Grundfunktionen die an vielen Stellen benoetigt werden *********//
//-- Circle aus der GS errechnen ---------------------------------------------
int GetCircle(int gl)
{
   gl=limit(gl,1,MAX_GUILD_LEVEL);
   return (1+((gl-1)/5));
}

//-- StringAusgabe -----------------------------------------------------------
string circle_to_string(int circle)
{
  mixed circles;
  circle=limit(circle,1,4);
  circles=({KREIS_1,KREIS_2,KREIS_3,KREIS_4});
  return circles[(circle-1)];  
}

//-- Den Grad zurueckgeben ---------------------------------------------------
int GetGrad(int gl)
{
  int c;
  
  gl=limit(gl,1,MAX_GUILD_LEVEL);
  c=GetCircle(gl);
  return gl-((c-1)*5);
}
//**************************************************************************//