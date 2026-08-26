/*
 * New Project handler
 * Author:  Shaydz
 * Started: 07/07/2005
 */
 

#define SAVE_FILE SECURE_DIR SAVE_DIR HANDLER_DIR "/project"

void load_me();
void save_me();

mapping projects;
nosave string tmp;

private void create() {
    seteuid(master()->creator_file(file_name(TO)));
    projects = ([]);
    load_me();

} /* setup() */

void load_me() {
    unguarded((: restore_object , SAVE_FILE :));
} /* load_me() */

void save_me() {
    unguarded((: save_object ,SAVE_FILE :));
} /* save_me() */

void dest_me(){
    destruct(TO);
} /* dest_me() */

int query_project(string creator, string dom, string proj){

   if(!creator || !dom || !proj)
            return 0;
   if(projects[creator]){
                if(projects[creator][dom]){
                              tmp = proj;
                if(sizeof(filter(projects[creator][dom],(: lower_case($1) == lower_case(tmp) :)))){
                        return 1;
                }
         }
          }
          return 0;
} /* query_project() */
        
int add_project(string creator, string dom, string proj){

   
   if (file_name(PO) != "/secure/cmds/creator/project")
     return 0;
   
   if(!creator || !dom || !proj)
            return 0;
   if(projects[creator]){
                if(projects[creator][dom]){
                if(query_project(creator,dom,proj)){
                        return 0;
                }                     
            projects[creator][dom] += ({proj});
         }else{
            projects[creator][dom] = ({proj});
         }
     save_me();
            return 1;
          }

          projects[creator] = ([dom:({proj})]);
   save_me();
   return 1;
   
} /* add_project */

int remove_project(string creator, string dom, string proj){

   if (file_name(PO) != "/secure/cmds/creator/project")
     return 0;

   if(!creator || !dom || !proj)
            return 0;

   if(projects[creator]){
                if(projects[creator][dom]){
                           if(sizeof(projects[creator][dom])>1){
                if(!query_project(creator,dom,proj)){
                        return 0;
                }                     
                    projects[creator][dom] -= ({proj});
               }else{
                           map_delete(projects[creator],dom);
               }
                if(!sizeof(projects[creator][dom])){
                           map_delete(projects[creator],dom);
         }
         if(!sizeof(projects[creator])){
                           map_delete(projects,creator);
         }
         save_me();
                return 1;
                }
          }
                    
         return 0;
} /* remove_project() */

int clear_project(string str){

    if(creatorp(str)){
        map_delete(projects,str);
         if(!sizeof(projects[str])){
                           map_delete(projects,str);
         }
        save_me();
        return 1;
    }
    if(DOMAIN_H->query_domain(str)){
              foreach(string cre in keys(projects)){
                      map_delete(projects[cre],str);
                if(!sizeof(projects[cre][str])){
                           map_delete(projects[cre],str);
         }
         if(!sizeof(projects[cre])){
                           map_delete(projects,cre);
         }
              }

              save_me();
        return 1;
    }
    return 0;
} /* clear_project() */

mixed query_projects(string str){
     mapping projs = ([]);

     if(!sizeof(keys(projects)))
                return ([]);
     
     if(!str)
                return projects;
                            
     if(creatorp(str)){
                   if(!projects[str]){
                             return ([]);
                   }else{
                       return projects[str];
            }
     }
     if(DOMAIN_H->query_domain(str)){
         foreach(string cre in keys(projects)){
              if(sizeof(projects[cre][str]))
                     projs += ([cre:projects[cre][str]]);
         }
         return projs;
     }
     return ([]);              
} /* query_projects() */