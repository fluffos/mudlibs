// automatch.c
string point_tostring(mixed point)
{
if(!sizeof(point)) return "";
        return point[0]+"/"+point[1];
}
mixed point_toint(string point)
{
        mixed pp;
        pp=explode(point,"/");
        return({to_int(pp[0]),to_int(pp[1])});
}
mixed get_neighbor(string p_point,string p_area,string p_side)
{
   int *nb,*me,x,y;
   string m,newpoint;
   mixed ret;
   ret=([]);
   me=point_toint(p_point);x=me[0];y=me[1];
   m=MAP_D->get_map_cell(p_area,y,x-1,"m");
   if (m&&(m!="0")&&(m!="※"))
   {   newpoint=point_tostring(({x-1,y}));
       ret[newpoint]=([]);
       ret[newpoint]["step"]=MAP_D->get_consume("m",p_side);
   }
   m=MAP_D->get_map_cell(p_area,y,x+1,"m");
   if (m&&(m!="0")&&(m!="※"))
   {  newpoint=point_tostring(({x+1,y}));
      ret[newpoint]=([]);
      ret[newpoint]["step"]=MAP_D->get_consume("m",p_side);
    }
    m=MAP_D->get_map_cell(p_area,y-1,x,"m");
    if (m&&(m!="0")&&(m!="※"))
    {   newpoint=point_tostring(({x,y-1}));
        ret[newpoint]=([]);
        ret[newpoint]["step"]=MAP_D->get_consume("m",p_side);
    }
    m=MAP_D->get_map_cell(p_area,y+1,x,"m");
    if (m&&(m!="0")&&(m!="※"))
    {   newpoint=point_tostring(({x,y+1}));
        ret[newpoint]=([]);
        ret[newpoint]["step"]=MAP_D->get_consume("m",p_side);
    }
    return ret;
}
mixed expand_path(mapping p_path,string p_target,string p_area,
    string p_side)
{
   string *p_leaves;
   string *p_tmp,*p_tmp2;
   mapping neighbors;
   p_leaves=keys(p_path);
   if(member_array(p_target,p_leaves)!=-1)
   {
       string *ret;
       ret=({p_target});
       while(p_path[p_target]["pre"]!="")
       {   p_target=p_path[p_target]["pre"];
           ret=({p_target})+ret;
       }
       ret-=({p_target});
       return ret;
    }
    p_leaves=filter_array(p_leaves,(: $(p_path)[($1)]["leave"]==1 :));
    if(!sizeof(p_leaves))
    return 0; // means can not find a path
              // a troop should not been put in this point
    foreach(string p_leave in p_leaves)
    {
        neighbors=get_neighbor(p_leave,p_area,p_side);
        p_tmp=keys(p_path);
        p_tmp2=keys(neighbors);
        foreach(string p_neighbor in p_tmp2)
        {
            if(member_array(p_neighbor,p_tmp)==-1) // a new point
            {       p_path[p_neighbor]=([]);
                    p_path[p_neighbor]["step"]=
                             p_path[p_leave]["step"]+
                             neighbors[p_neighbor]["step"];
                             p_path[p_neighbor]["pre"]=p_leave;
                             p_path[p_neighbor]["leave"]=1;
            }
            else
            {
                if(p_path[p_neighbor]["step"]>
                      (p_path[p_leave]["step"]+
                      neighbors[p_neighbor]["step"]))
                {
                      p_path[p_neighbor]["step"]=
                           p_path[p_leave]["step"]+
                           neighbors[p_neighbor]["step"];
                      p_path[p_neighbor]["pre"]=p_leave;
                 }
             }
            }
            p_path[p_leave]["leave"]=0;
         }
        return expand_path(p_path,p_target,p_area,p_side);
}
// search a little random 
// so not necessary the shortest path to the target
mixed expand_path_r(mapping p_path,string p_target,string p_area,
string p_side)
{
   string *p_leaves;
   string *p_tmp,*p_tmp2;
   mapping neighbors;
   p_leaves=keys(p_path);
   if(member_array(p_target,p_leaves)!=-1)
   {
       string *ret;
       ret=({p_target});
       while(p_path[p_target]["pre"]!="")
       {       p_target=p_path[p_target]["pre"];
               ret=({p_target})+ret;
       }
       ret-=({p_target});
       return ret;
    }
    p_leaves=filter_array(p_leaves,(: $(p_path)[($1)]["leave"]==1 :));
    if(!sizeof(p_leaves))
      return 0; // means can not find a path
                // a troop should not been put in this point
    foreach(string p_leave in p_leaves)
    {
        neighbors=get_neighbor(p_leave,p_area,p_side);
        p_tmp=keys(p_path);
        p_tmp2=keys(neighbors);
        foreach(string p_neighbor in p_tmp2)
        {
           if(member_array(p_neighbor,p_tmp)==-1) // a new point
           {   p_path[p_neighbor]=([]);
               p_path[p_neighbor]["step"]=p_path[p_leave]["step"]+
                                neighbors[p_neighbor]["step"];
                                p_path[p_neighbor]["pre"]=p_leave;
                                p_path[p_neighbor]["leave"]=1;
           }
           else
           {
               if(random(2))
               {
                 if(p_path[p_neighbor]["step"]>
                    (p_path[p_leave]["step"]+neighbors[p_neighbor]["step"]))
                 {
                     p_path[p_neighbor]["step"]=
                           p_path[p_leave]["step"]+
                           neighbors[p_neighbor]["step"];
                     p_path[p_neighbor]["pre"]=p_leave;
                  }
              }
           }
       }
       p_path[p_leave]["leave"]=0;
    }
    return expand_path_r(p_path,p_target,p_area,p_side);
}
mixed auto_match(int t_id)
{
   string p_curpoint,p_tarpoint;
   string p_area;
   string p_side;
   mixed p_path=([]);
   p_area=TROOP_D->get_troops(t_id,"area");
   p_curpoint=point_tostring(TROOP_D->get_troops(t_id,"position"));
   p_tarpoint=point_tostring(MAP_D->get_city(p_area,"center"));
   p_side=TROOP_D->get_troops(t_id,"side");
   p_path[p_curpoint]=([]);
   p_path[p_curpoint]["step"]=0; // zero fron the source
   p_path[p_curpoint]["leave"]=1; // this is the leave
   p_path[p_curpoint]["pre"]="";
   p_path=expand_path_r(p_path,p_tarpoint,p_area,p_side);
   return p_path;
}
