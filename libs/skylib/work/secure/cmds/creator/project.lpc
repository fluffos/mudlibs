/*
 *
 * Project command.
 * Author: Shaydz
 * Started: 11/07/2005
 *
 */

int add_project(string project, string domain, string creator){
        
    if(!adminp(TP)){
                if(!DOMAIN_H->query_leader(domain,TP->query_name())){
                          tell_object(TP,"You are not a leader of "+domain+".\n");
              return 1;
          }
    }
                            
          if(!creatorp(creator)){
                  tell_object(TP,creator+" is not a creator.\n");
      return 1;
    }
          if(!DOMAIN_H->query_domain(domain)){
                  tell_object(TP,domain+" is not a valid domain.\n");
                  return 1;
          }
    if(PROJECT_H->query_project(creator, domain, project)){
            tell_object(TP,creator+" already has a project called \""+project+
                        "\" in "+domain+".\n");
                  return 1;
          }
          if(!PROJECT_H->add_project(creator,domain,project)){
                  tell_object(TP,"Unable to add project.\n");
                  return 1;
          }
          tell_object(TP,"Added \""+project+"\" for "+creator+" in "+domain+".\n");
          return 1;
} /* add_project() */

int remove_project(string project, string domain, string creator){

    if(!adminp(TP)){
                if(!DOMAIN_H->query_leader(domain,TP->query_name())){
                          tell_object(TP,"You are not a leader of "+domain+".\n");
              return 1;
          }
    }
                            
          if(!creatorp(creator)){
                  tell_object(TP,creator+" is not a creator.\n");
      return 1;
    }
          if(!DOMAIN_H->query_domain(domain)){
                  tell_object(TP,domain+" is not a valid domain.\n");
                  return 1;
          }
    if(!PROJECT_H->query_project(creator, domain, project)){
            tell_object(TP,creator+" doesn't have a project called \""+project+
                        "\" in "+domain+".\n");
                  return 1;
          }
          if(!PROJECT_H->remove_project(creator,domain,project)){
                  tell_object(TP,"Unable to remove project.\n");
                  return 1;
          }
          tell_object(TP,"Removed \""+project+"\" for "+creator+" in "+domain+".\n");
          return 1;
} /* remove_project() */

int clear_project(string str){
    if(!adminp(TP)){
                      tell_object(TP,"Admin only option.\n");
          return 1;
    }
    tell_object(TP,"Are you sure you want to delete all of "+CAP(str)+"'s "
              "projects? [y/n] ");

    input_to("clear_project_2",str);
    return 1;
} /* clear_project() */

int clear_project_2(string yesno, string str){
        
          if(yesno != "y"){
                    tell_object(TP,CAP(str)+"'s projects NOT cleared.\n");
                    return 1;
          }
          if(!PROJECT_H->clear_project(str)){
                  tell_object(TP,"Unable to clear projects for "+str+".\n");
                  return 1;
          }
          tell_object(TP,"Removed all projects for "+str+".\n");
          return 1;
} /* clear_project_2() */

int list_project(string str){
    string prt,tmp, name;
    int width,i;
    mapping projects;
    
    if(str=="all")
            projects = PROJECT_H->query_projects();
    else        
      projects = PROJECT_H->query_projects(str);
    if(!sizeof(keys(projects))){
              tell_object(TP,"There are no projects for "+str+".\n");
        return 1;
    }

    width = TP->query_cols();

    if(creatorp(str)){
                name = CAP(str)+"'s Projects";
                      tmp = sprintf( "  %-*s%-*s\n", 33, "%^WHITE%^Domain%^RESET%^", 45,
                  "%^WHITE%^Project%^RESET%^");
              foreach(string dom in keys(projects)){
                      for ( i = 0; i < sizeof( projects[dom] ); i++ ) {
                          tmp += sprintf( "  %-*s%-=*s\n", 15, CAP(dom), width-20,
                  projects[dom][i]);
          }
        }
    }
    if(DOMAIN_H->query_domain(str)){
          name = "Projects for "+CAP(str);
                      tmp = sprintf( "  %-*s%-*s\n", 33, "%^WHITE%^Creator%^RESET%^", 46,
                  "%^WHITE%^Project%^RESET%^");
              foreach(string cre in keys(projects)){
                      for ( i = 0; i < sizeof( projects[cre] ); i++ ) {
                          tmp += sprintf( "  %-*s%-=*s\n", 15, CAP(cre), width-20,
                  projects[cre][i]);
          }
        }
    }
    if(str=="all"){
          name = "Listing of all projects";
                      tmp = sprintf( " %-*s%-*s%-*s\n", 32, "%^WHITE%^ Creator%^RESET%^",35,
                              "%^WHITE%^  Domain%^RESET%^", 48,"%^WHITE%^Project%^RESET%^");
              foreach(string cre in keys(projects)){
                      foreach(string dom in keys(projects[cre])){                              
                         for ( i = 0; i < sizeof( projects[cre][dom] ); i++ ) {
                          tmp += sprintf( "  %-*s%-*s%-=*s\n", 15, CAP(cre), 15, CAP(dom), width-20,
                  projects[cre][dom][i]);
          }
        }
        }
    }
    prt = sprintf("%|*'-'s\n", width-1,"-");
    prt += sprintf( "%|*s\n", width-1, name );
    prt += sprintf("%|*'-'s\n", width-1,"-");
    prt += tmp;
    prt += sprintf("%|*'-'s\n", width-1,"-");
    tell_object(TP,prt);
    return 1;
} /*add_project()*/

/** @ignore yes */
mixed *query_patterns() {
    return ({
        "add <string'project name'> in <word'domain'> to <word'creator'>", 
                    (: add_project($4[0], $4[1], $4[2]) :),
        "remove <string'project name'> in <word'domain'> from <word'creator'>", 
                    (: remove_project($4[0], $4[1], $4[2]) :),
        "clear <word'creator|domain'>", (: clear_project($4[0]) :),
        "list <word'creator|domain|all'>", (: list_project($4[0]) :)
    });
} /* query_patterns() */
