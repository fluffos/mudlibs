#include "path.h"

void avisar_guardias(object puto)
{
   int i, n;
   object *guardias;
   
   
   
}

string salida(string destino)
{
   int i, j, n1, n2;
   string fichero, tmp, tmp2, pos1, pos2;
   object quien;
   
   quien=previous_object();
   write(file_name(quien));
   quien=this_player();
   fichero=file_name(environment(quien));
   i=sscanf(fichero, ROOMS+"%s", tmp);
   if (i) write("\nOrigen: "+tmp+"\n");
   else
   {
      write("\nOrigen fuera de Anduar.\n");
      return 0;
   }
   tmp2=destino;
   i=sscanf(tmp2, ROOMS+"%s", destino);
   if (i) write("\nDestino: "+destino+"\n");
   else
   {
      write("\nDestino fuera de Anduar.\n");
      return 0;
   }
   if (sscanf(tmp, "%s%d", pos1, n1)!=2) return 0;  /* return 0; */
   if (sscanf(destino, "%s%d", pos2, n2)!=2) return 0;
   
   if (pos1=="oeste")
   {
      if (pos2=="oeste")
         if (n1<n2) return "norte";
         else if (n1>n2)
            return "sur";
      if (pos2=="norte")
         if (n1==9) return "este";
         else return "norte";
      if (pos2=="sur")
         return "sur";
      if (pos2=="cent")
         if ((n1-n2)<0) return "sur";
         else if (n1==9) return "este";
         else return "norte";
      if (pos2=="este")
         if ((n1-n2)<0) return "sur";
         else if (n1==9) return "este";
         else return "norte";
   }
   if (pos1=="norte")
   {
      if (pos2=="norte")
         if (n1>n2) return "este";
         else if (n1<n2) return "oeste";
      if (pos2=="oeste") return "oeste";
      if (pos2=="este")
         if (n1==1) return "sur";
         else return "este";
      if (pos2=="sur")
         if ((n1-n2)<0)
            if (n1==1) return "sur";
            else return "este";
         else return "oeste";
      if (pos2=="cent")
         if (n1<6) return "oeste";
         else if (n1>6) return "este";
         else return "sur";
   }
   if (pos1=="este")
   {
      if (pos2=="este")
         if (n1<n2) return "sur";
         else if (n1>n2) return "norte";
      if (pos2=="norte") return "norte";
      if (pos2=="sur")
         if (n1==9) return "oeste";
         else return "sur";
      if (pos2=="oeste" || pos2=="cent")
         if ((n1-n2)<0) return "norte";
         else if (n1==9) return "oeste";
         else return "sur";      
   }
   if (pos1=="sur")
   {
      if (pos2=="sur")
         if (n1<n2) return "este";
         else if (n1>n2) return "oeste";
      if (pos2=="este") return "este";
      if (pos2=="oeste")
         if (n1==1) return "norte";
         else return "oeste";
      if (pos2=="norte")
         if ((n1-n2)<0)
            if (n1==1) return "norte";
            else return "oeste";
         else return "este";
      if (pos2=="cent")
         if (n1>5) return "oeste";
         else if (n1<5) return "este";
         else return "norte";
   }
   return 0;
}