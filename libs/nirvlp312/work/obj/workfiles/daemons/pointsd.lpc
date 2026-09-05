string *nms;
int    *pts;

#define SAVEPATH "obj/daemons/save/"

void reset(int arg)
{
  if(arg) return;
  
  if(!restore_object(SAVEPATH))
  {
    nms = ({ });
    pts = ({ });
  }
}

void add_pts(string nm, int pt)
{
  int i;
  
  if((i = member_array(nm, nms)) == -1)
  {
    nms += ({ nm });
    pts += ({ 0 });
    i = sizeof(nms) - 1;
  }
  
  pts[i] += pt;
  
  save_object(SAVEPATH);
}

int query_pts(string nm)
{
  int i;
  
  if((i = member_array(nm, nms)) == -1)
  {
    return 0;
  }
  
  return pts[i];
} 