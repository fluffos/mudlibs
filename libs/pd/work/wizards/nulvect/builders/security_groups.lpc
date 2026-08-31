
varargs mixed security_groups(string grouping,mixed target) {
    string pname;
    mapping groups=master()->query_groups();

    if(!grouping) return groups;
    if(!groups[grouping]) error("The security group requested doesn't exist...");

      if(target) {
         pname = (objectp(target)) ? target->query_name() : target;
         return member_array(pname,groups[grouping]) ? 1 : 0 ; }
      else {
          return groups[grouping]; }}
