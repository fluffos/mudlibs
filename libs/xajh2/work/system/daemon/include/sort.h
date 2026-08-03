#ifndef __SORT_H
#define __SORT_H

private string * Families = ({
    "少林派",  "姑苏慕容",  "丐帮",   "镇南王府", 
     "崆峒派",  "无量剑派东宗",   "无量剑派西宗",  "蓬莱派", 
     "伏牛派",  });


int ComparePlayer( object, object );
int CompareFamily( string, string );
int CompareZuzhi( mixed, mixed );
int CompareWizardLevel( int, int );
int CompareAge( int, int );
int CompareId( string, string );
 
#endif /* __SORT_H */
